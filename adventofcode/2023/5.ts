import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

type NumberMap = {
    name: string;
    to: string;
    map: Array<[start: number, to: number, length: number]>; // should be sorted afterwards
};
type Maps = Record<string, NumberMap>;

const seeds = new Array<number>();
const allMaps: Maps = {};
let currentMap: NumberMap | undefined = undefined;

function parse(input: string): void {
    if (currentMap) {
        if (input.trim().length === 0) {
            currentMap.map.sort((a, b) => a[0] - b[0]);
            allMaps[currentMap.name] = currentMap;
            currentMap = undefined;
            return;
        }

        const numbers = input
            .split(' ')
            .filter((x) => x.length)
            .map((x) => Number(x));
        currentMap.map.push([numbers[1], numbers[0], numbers[2]]);
    } else if (input.includes('map:')) {
        const names = input.split(' ')[0].split('-');
        currentMap = { name: names[0], to: names[2], map: [] };
    } else if (input.startsWith('seeds:')) {
        seeds.push(
            ...input
                .split(':')[1]
                .split(' ')
                .filter((x) => x.length)
                .map((x) => Number(x))
        );
    }
}

function toMap(start: string, from: Array<number>): { end: string; to: Array<number> } {
    const next = allMaps[start];
    if (next === undefined) {
        return { end: start, to: from };
    }
    const to: Array<number> = [];

    for (const n of from) {
        for (let i = 0; i < next.map.length; i++) {
            if (n < next.map[i][0]) {
                to.push(n);
                break;
            } else if (n < next.map[i][0] + next.map[i][2]) {
                to.push(next.map[i][1] - next.map[i][0] + n);
                break;
            } else if (i === next.map.length - 1) {
                // the last one
                to.push(n);
                break;
            }
        }
    }
    return { end: next.to, to: to.sort((a, b) => a - b) };
}

type IntersectResult = {
    less?: [number, number];
    in?: [number, number];
    more?: [number, number];
};

function intersect(start: number, length: number, check: number, checkLength: number): IntersectResult {
    if (start + length <= check) {
        return { less: [start, length] };
    } else if (start >= check + checkLength) {
        return { more: [start, length] };
    }

    const result: IntersectResult & { in: [number, number] } = {
        in: [Math.max(start, check), Math.min(start + length, check + checkLength) - Math.max(start, check)],
    };

    if (start < result.in[0]) {
        result['less'] = [start, result.in[0] - start];
    }

    if (start + length > result.in[0] + result.in[1]) {
        result['more'] = [result.in[0] + result.in[1], start + length - result.in[0] - result.in[1]];
    }
    return result as IntersectResult;
}

function toMap2(start: string, from: Array<[number, number]>): { end: string; to: Array<[number, number]> } {
    const next = allMaps[start];
    if (next === undefined) {
        return { end: start, to: from };
    }

    const to: Array<[number, number]> = [];

    for (let [start, length] of from) {
        for (let i = 0; i < next.map.length; i++) {
            const result = intersect(start, length, next.map[i][0], next.map[i][2]);
            if (result.less) {
                to.push(result.less);
            }
            if (result.in) {
                to.push([next.map[i][1] + result.in[0] - next.map[i][0], result.in[1]]);
            }

            if (result.more) {
                if (i === next.map.length - 1) {
                    to.push(result.more);
                }
                start = result.more[0];
                length = result.more[1];
                continue;
            }
            break;
        }
    }
    return { end: next.to, to: to.sort((a, b) => a[0] - b[0]) };
}

function toSeeds2(): Array<[number, number]> {
    const seeds2 = new Array<[number, number]>();
    for (let i = 0; i < seeds.length; i += 2) {
        seeds2.push([seeds[i], seeds[i + 1]]);
    }
    return seeds2;
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        rl.on('line', (line) => {
            parse(line);
        });
        await once(rl, 'close');

        if (currentMap) {
            currentMap.map.sort((a, b) => a[0] - b[0]);
            allMaps[currentMap.name] = currentMap;
        }

        let to = { end: 'seed', to: [...seeds].sort((a, b) => a - b) };
        let pre = to;
        do {
            pre = to;
            to = toMap(to.end, to.to);
        } while (pre.end !== to.end);

        let to2 = { end: 'seed', to: toSeeds2() };
        let pre2 = to2;

        do {
            pre2 = to2;
            to2 = toMap2(to2.end, to2.to);
        } while (pre2.end !== to2.end);

        console.log('less is', to.to[0]);
        console.log('less is', to2.to[0][0]);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('5.input');
