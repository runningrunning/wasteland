import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

function getNumber(input: string): number | undefined {
    const numbers = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
    for (let i = 0; i < numbers.length; i++) {
        if (input.startsWith(numbers[i])) {
            return i + 1;
        }
    }
    return undefined;
}

async function processLineByLine(file: string, stringNumber = false) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;

        rl.on('line', (line) => {
            let first = -1;
            let last = -1;
            for (let i = 0; i < line.length; i++) {
                const x = line[i];
                const xs = line.slice(i);
                const number = stringNumber ? getNumber(xs) : undefined;

                if ((x >= '0' && x <= '9') || number !== undefined) {
                    if (first === -1) {
                        first = number ?? Number(x);
                    }
                    last = number ?? Number(x);
                }
            }
            total += first * 10 + last;
        });
        await once(rl, 'close');
        console.log('File Processed ', total);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('1.input');
processLineByLine('1.input', true);
