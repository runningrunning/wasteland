import { readFileSync } from 'fs';

function question(file: string, y: number): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);
    const ranges: Array<[number, number]> = [];
    const occupied = new Set<string>();

    let min = Infinity;
    let max = -Infinity;
    for (const line of inputs) {
        const input = line
            .split(':')
            .map((x) => x.split(',').map((x) => x.split('=').map(Number)))
            .flat()
            .flat()
            .filter((x) => !isNaN(x));
        occupied.add(`${input[0]},${input[1]}`);
        occupied.add(`${input[2]},${input[3]}`);
        const distance = Math.abs(input[0] - input[2]) + Math.abs(input[1] - input[3]);
        const diff = distance - Math.abs(y - input[1]);
        if (diff >= 0) {
            ranges.push([input[0] - diff, input[0] + diff]);
            min = Math.min(min, input[0] - diff);
            max = Math.max(max, input[0] + diff);
        }
    }

    let count = 0;
    for (let i = min; i <= max; i++) {
        let flag = false;
        for (const [from, to] of ranges) {
            if (i >= from && i <= to) {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (occupied.has(`${i},${y}`) === false) {
                count += 1;
            }
        }
    }
    // remove the S or B at that position
    console.log(count);
}

function question2(file: string, maxRange: number): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    const sensors = new Array<[number, number, number]>();
    for (const line of inputs) {
        const input = line
            .split(':')
            .map((x) => x.split(',').map((x) => x.split('=').map(Number)))
            .flat()
            .flat()
            .filter((x) => !isNaN(x));
        const distance = Math.abs(input[0] - input[2]) + Math.abs(input[1] - input[3]);
        sensors.push([input[0], input[1], distance]);
    }

    let y = 0;
    for (y = 0; y <= maxRange; y++) {
        const ranges: Array<[number, number]> = [];
        for (const input of sensors) {
            let distance = input[2];
            const diff = distance - Math.abs(y - input[1]);
            if (diff >= 0) {
                ranges.push([input[0] - diff, input[0] + diff]);
            }
        }

        ranges.sort((a: [number, number], b: [number, number]): number => {
            if (a[0] === b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });

        let x = 0;
        for (x = 0; x <= maxRange; x++) {
            let found = false;
            for (const [from, to] of ranges) {
                if (x >= from && x <= to) {
                    found = true;
                    x = to;
                    break;
                }
            }
            if (!found) {
                console.log(x * 4000000 + y);
                return;
            }
        }
    }
}

question('temp', 10);
question2('temp', 20);
question('15.input', 2000000);
question2('15.input', 4000000);
