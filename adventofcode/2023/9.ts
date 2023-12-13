import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

function process(line: string, indicateLast: boolean): number {
    if (line.trim().length === 0) {
        return 0;
    }
    const init = line
        .split(' ')
        .filter((x) => x.length)
        .map((x) => Number(x.trim()));
    const stacks: Array<Array<number>> = [];
    const allZero = (input: Array<number>) => input.filter((x) => x !== 0).length === 0;

    let start: Array<number> = init;
    while (allZero(start) === false) {
        stacks.push(start);
        start = start.map((v, i) => (i === 0 ? 0 : v - start[i - 1])).slice(1);
    }
    return indicateLast
        ? stacks.reverse().reduce((p, c) => c[c.length - 1] + p, 0)
        : stacks.reverse().reduce((p, c) => c[0] - p, 0);
}

async function processLineByLine(file: string, indicateLast = false) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });

        let total = 0;
        rl.on('line', (line) => {
            total += process(line, indicateLast);
        });

        await once(rl, 'close');
        console.log('total', total);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('9.input', true);
processLineByLine('9.input', false);
