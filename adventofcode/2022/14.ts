// common class and data structure
// find better representation
import { readFileSync } from 'fs';

// be careful
function question(file: string, floor = -1): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);
    const rocksX = new Map<number, Array<[number, number]>>();
    const rocksY = new Map<number, Array<[number, number]>>();
    // y, x
    const sands = new Map<number, Set<number>>();

    let minX = Infinity;
    let maxX = -Infinity;
    let minY = Infinity;
    let maxY = -Infinity;

    for (const input of inputs) {
        const ranges: Array<[number, number]> = input
            .split(' -> ')
            .map((x) => x.split(',').map((x) => Number(x.trim()))) as Array<[number, number]>;

        for (let i = 1; i < ranges.length; i++) {
            if (ranges[i][0] === ranges[i - 1][0]) {
                const [from, to] =
                    ranges[i - 1][1] < ranges[i][1]
                        ? [ranges[i - 1][1], ranges[i][1]]
                        : [ranges[i][1], ranges[i - 1][1]];

                if (minX > ranges[i][0]) minX = ranges[i][0];
                if (maxX < ranges[i][0]) maxX = ranges[i][0];

                if (minY > from) minY = from;
                if (maxY < to) maxY = to;
                if (rocksX.get(ranges[i][0]) === undefined) {
                    rocksX.set(ranges[i][0], []);
                }
                rocksX.get(ranges[i][0])?.push([from, to]);
            } else if (ranges[i][1] === ranges[i - 1][1]) {
                const [from, to] =
                    ranges[i - 1][0] < ranges[i][0]
                        ? [ranges[i - 1][0], ranges[i][0]]
                        : [ranges[i][0], ranges[i - 1][0]];

                if (minY > ranges[i][1]) minY = ranges[i][1];
                if (maxY < ranges[i][1]) maxY = ranges[i][1];
                if (minX > from) minX = from;
                if (maxX < to) maxX = to;
                if (rocksY.get(ranges[i][1]) === undefined) {
                    rocksY.set(ranges[i][1], []);
                }
                rocksY.get(ranges[i][1])?.push([from, to]);
            } else {
                console.log('error', input);
            }
        }
    }

    const occupied = (x: number, y: number): boolean => {
        if (sands.has(y) && sands.get(y)?.has(x)) {
            return true;
        }
        if (rocksX.has(x)) {
            for (const [from, to] of rocksX.get(x) as Array<[number, number]>) {
                if (from <= y && y <= to) {
                    return true;
                }
            }
        }

        if (rocksY.has(y)) {
            for (const [from, to] of rocksY.get(y) as Array<[number, number]>) {
                if (from <= x && x <= to) {
                    return true;
                }
            }
        }

        if (floor !== -1) {
            if (y >= maxY + floor) {
                return true;
            }
        }

        return false;
    };

    let caught = true;

    do {
        let x = 0;
        let y = 0;
        // new sand
        let current: [number, number] | undefined = [500, 0];
        if (sands.get(0)?.has(500)) {
            break;
        }
        while (current) {
            [x, y] = current;
            // next place
            y += 1;
            if (occupied(x, y)) {
                if (occupied(x - 1, y) === false) {
                    current = [x - 1, y];
                } else if (occupied(x + 1, y) === false) {
                    current = [x + 1, y];
                } else {
                    current = undefined;
                    if (sands.has(y - 1) === false) {
                        sands.set(y - 1, new Set());
                    }
                    sands.get(y - 1)?.add(x);
                }
            } else {
                current = [x, y];
            }

            if (floor === -1) {
                if (x < minX || x > maxX || y > maxY) {
                    caught = false;
                    break;
                }
            }
        }
    } while (caught);
    console.log(Array.from(sands.values()).reduce((acc, x) => acc + x.size, 0));
}

question('temp');
question('temp', 2);
question('14.input');
question('14.input', 2);
