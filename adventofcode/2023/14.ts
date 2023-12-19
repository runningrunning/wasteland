import { readFileSync } from 'fs';

function tilt(dish: Array<Array<string>>, direction: 'N' | 'S' | 'W' | 'E'): Array<Array<string>> {
    const offsets = {
        N: {
            outer: [0, dish[0].length],
            inner: [0, dish.length],
            offset: (o: number, i: number) => ({ x: o, y: i }),
        },
        S: {
            outer: [0, dish[0].length],
            inner: [0, dish.length],
            offset: (o: number, i: number) => ({ x: o, y: dish.length - 1 - i }),
        },
        W: {
            outer: [0, dish.length],
            inner: [0, dish[0].length],
            offset: (o: number, i: number) => ({ x: i, y: o }),
        },
        E: {
            outer: [0, dish.length],
            inner: [0, dish[0].length],
            offset: (o: number, i: number) => ({ x: dish[0].length - 1 - i, y: o }),
        },
    };

    const current = offsets[direction];

    for (let i = 0; i < current.outer[1]; i++) {
        const sample: Array<string> = [];
        for (let j = 0; j < current.inner[1]; j++) {
            const o = current.offset(i, j);
            sample.push(dish[o.y][o.x]);
        }
        for (let k = 1; k < sample.length; k++) {
            let c = k;
            if (sample[c] === 'O') {
                while (c > 0 && sample[c - 1] === '.') {
                    sample[c - 1] = 'O';
                    sample[c] = '.';
                    c--;
                }
            }
        }
        for (let j = 0; j < current.inner[1]; j++) {
            const o = current.offset(i, j);
            dish[o.y][o.x] = sample[j];
        }
    }
    return dish;
}

function cycle(dish: Array<Array<string>>): string {
    tilt(dish, 'N');
    tilt(dish, 'W');
    tilt(dish, 'S');
    tilt(dish, 'E');
    return encoding(dish);
}

function encoding(dish: Array<Array<string>>): string {
    return dish.map((x) => x.join('')).join('\n');
}

function score(inputs: Array<Array<string>>): number {
    let curScoreBase = inputs.length;
    let total = 0;

    for (const input of inputs) {
        let count = 0;
        for (const char of input) {
            if (char === 'O') {
                count++;
            }
        }
        total += count * curScoreBase--;
    }
    return total;
}

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    const dish: Array<Array<string>> = [];
    const dish2: Array<Array<string>> = [];
    for (const input of inputs) {
        dish.push(input.split(''));
        dish2.push(input.split(''));
    }

    tilt(dish, 'N');
    const calculated = new Map<string, number>();

    let total = 1000000000;
    for (let i = 0; i < total; i++) {
        const key = cycle(dish2);
        if (total === 1000000000) {
            if (calculated.has(key)) {
                total = i + ((1000000000 - i) % (i - (calculated.get(key) as number)));
            } else {
                calculated.set(key, i);
            }
        }
    }
    console.log(file, 'q1', score(dish));
    console.log(file, 'q2', score(dish2));
}

question('temp');
question('14.input');
