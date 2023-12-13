import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

function process(input: string): number {
    input = input.trim();
    if (input.length === 0) {
        return 0;
    }

    if (input.includes('?') === false) {
        return 1;
    }

    let count = 0;
    let position = 0;

    do {
        position = input.indexOf('?', position);
        if (position === -1) {
            break;
        }
        count++;
        position += 1;
    } while (true);

    const [myth, counts] = input.split(' ').map((x) => x.trim());

    let matched = 0;

    // use binary to simulate the different
    for (let i = 0; i < Math.pow(2, count); i++) {
        let current = i;
        let pre = -1;
        const one: Array<number> = [];
        for (let c of myth) {
            if (c === '?') {
                c = current & 1 ? '.' : '#';
                current >>>= 1;
            }

            if (c === '.') {
                if (pre > 0) {
                    one.push(pre);
                    pre = -1;
                }
            } else {
                if (pre < 0) {
                    pre = 1;
                } else {
                    pre++;
                }
            }
        }

        if (pre > 0) {
            one.push(pre);
        }
        matched += one.join(',') === counts ? 1 : 0;
    }
    return matched;
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        rl.on('line', (line) => {
            total += process(line);
        });

        await once(rl, 'close');
        console.log('total', total);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('temp');
processLineByLine('12.input');
