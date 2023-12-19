import { readFileSync } from 'fs';

function question(file: string): void {
    const boxes = new Array<Array<[string, number]>>(256);
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)[0];

    const labelNumber = (input: string): number => {
        let current = 0;
        for (const c of input) {
            current += c.charCodeAt(0);
            current = (current * 17) % 256;
        }
        return current;
    };

    let total = 0;

    for (const input of inputs.split(',')) {
        total += labelNumber(input);

        if (input.includes('=')) {
            const [key, value] = input.split('=');
            const label = labelNumber(key);
            if (boxes[label] === undefined) {
                boxes[label] = [[key, Number(value)]];
            } else {
                const find = boxes[label].findIndex((x) => x[0] === key);
                if (find === -1) {
                    boxes[label].push([key, Number(value)]);
                } else {
                    boxes[label][find][1] = Number(value);
                }
            }
        } else if (input.includes('-')) {
            const [key] = input.split('-');
            const label = labelNumber(key);
            if (boxes[label] !== undefined) {
                const find = boxes[label].findIndex((x) => x[0] === key);
                if (find !== -1) {
                    boxes[label].splice(find, 1);
                }
            }
        }
    }
    const focusPower = boxes.reduce(
        (acc, cur, bi) => acc + cur.reduce((acc, cur, si) => acc + (si + 1) * cur[1], 0) * (bi + 1),
        0
    );

    console.log(total, focusPower);
}

question('temp');
question('15.input');
