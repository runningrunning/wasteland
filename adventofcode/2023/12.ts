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

    // use binary to stimulate the different
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

const FOLD = 5;
let memory: Record<string, number> = {};

function countMatch(myth: string, records: Array<number>, allQuestionToDamage = false): number {
    const key = `${myth}-${records.join(',')}-${allQuestionToDamage ? 'true' : 'false'}`;
    if (memory[key] !== undefined) {
        return memory[key];
    }

    if (records.length === 0) {
        if (myth.includes('#') || (allQuestionToDamage && myth.includes('?'))) {
            memory[key] = 0;
        } else {
            memory[key] = 1;
        }
        return memory[key];
    }

    const needed = records.reduce((a, b) => a + b, 0) + records.length - 1;
    if (myth.length < needed) {
        memory[key] = 0;
        return 0;
    }

    let count = 0;
    if (records.length === 1) {
        // check the continue '#'
        for (let i = 0; i < myth.length - records[0] + 1; i++) {
            const pre = myth.slice(0, i);
            const last = myth.slice(i + records[0]);
            const middle = myth.slice(i, i + records[0]);

            if (pre.includes('#') || (allQuestionToDamage && pre.includes('?'))) {
                break;
            }

            if (last.includes('#') || (allQuestionToDamage && last.includes('?'))) {
                continue;
            }

            if (middle.includes('.') === false) {
                count++;
            }
        }
        memory[key] = count;
    } else if (allQuestionToDamage) {
        let pre = -1;
        const ones: Array<number> = [];
        for (const c of myth) {
            if (c === '.') {
                if (pre > 0) {
                    ones.push(pre);
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
            ones.push(pre);
        }

        if (ones.join(',') === records.join(',')) {
            memory[key] = count = 1;
        }
        return count;
    } else {
        // for each question mark, it could be '.' or '#'
        // when it's '.', divide the myth into 2 parts, match each parts with different records.
        // since the '?' is checked from left to right, the questions has been '.' and checked already in
        // the previous part so it can only act as damaged which is indicated by allQuestionToDamage
        for (let i = 0; i < myth.length; i++) {
            if (myth[i] === '?') {
                for (let j = 0; j <= records.length; j++) {
                    const pre = countMatch(myth.slice(0, i), records.slice(0, j), true);
                    if (pre === 1) {
                        count += countMatch(myth.slice(i + 1), records.slice(j), allQuestionToDamage);
                    }
                }
            }
        }
        // treat the whole inputs as previous part for the last '?' in the myth or no '?' in the myth
        count += countMatch(myth, records, true);
        memory[key] = count;
    }

    return memory[key];
}

function process2(input: string): number {
    input = input.trim();
    if (input.length === 0) {
        return 0;
    }

    const [myth, counts] = input.split(' ').map((x) => x.trim());
    const realMyth = new Array(FOLD).fill(myth).join('?');
    const realCountsStrings = new Array(FOLD).fill(counts).join(',');
    const records = realCountsStrings
        .split(',')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map(Number);
    // clear the memory
    memory = {};
    return countMatch(realMyth, records);
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        let total2 = 0;
        rl.on('line', (line) => {
            total += process(line);
            total2 += process2(line);
        });
        await once(rl, 'close');
        console.log('total', total);
        console.log('total2', total2);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('temp');
processLineByLine('12.input');
