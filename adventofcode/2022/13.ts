import { readFileSync } from 'fs';

type Input = Array<Input> | number;

// Parse ourself
function parse(line: string): Input {
    let result: Array<Input> = [];
    let pre: undefined | number;
    let stack: Array<Array<Input>> = [result];
    for (const c of line) {
        const current = stack[stack.length - 1];
        if (c >= '0' && c <= '9') {
            pre = (pre ?? 0) * 10 + Number(c);
        } else {
            if (pre !== undefined) {
                current.push(pre);
                pre = undefined;
            }

            if (c !== ',') {
                if (c === '[') {
                    const next: Array<Input> = [];
                    current.push(next);
                    stack.push(next);
                } else if (c === ']') {
                    stack.pop();
                }
            }
        }
    }

    if (pre !== undefined) {
        stack[stack.length - 1].push(pre);
        pre = undefined;
    }
    return result[0];
}

// Much easier way
function parseJS(input: string): Input {
    return eval(input) as Input;
}

// 1 for left is bigger, -1 for right is bigger, 0 for equal
function compare(left: Input, right: Input): number {
    if (typeof left === 'number' && typeof right === 'number') {
        const diff = Number(left) - Number(right);
        return diff > 0 ? 1 : diff < 0 ? -1 : 0;
    }

    if (typeof left === 'number') {
        return compare([left], right);
    }

    if (typeof right === 'number') {
        return compare(left, [right]);
    }

    const minLen = Math.min(left.length, right.length);

    for (let i = 0; i < minLen; i++) {
        const diff = compare(left[i], right[i]);
        if (diff !== 0) {
            return diff;
        }
    }

    if (left.length === right.length) {
        return 0;
    }
    return left.length > right.length ? 1 : -1;
}

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    const start: Input = [[2]];
    const end: Input = [[6]];

    let lessThanStart = 0;
    let lessThanEnd = 0;
    let total = 0;
    for (let i = 0; i < inputs.length; i++) {
        const pairs = inputs[i].split('\n');
        const left = parseJS(pairs[0].trim());
        const right = parseJS(pairs[1].trim());
        if (compare(left, right) <= 0) {
            total += i + 1;
        }

        if (compare(left, start) <= 0) {
            lessThanStart += 1;
            lessThanEnd += 1;
        } else if (compare(left, end) <= 0) {
            lessThanEnd += 1;
        }

        if (compare(right, start) <= 0) {
            lessThanStart += 1;
            lessThanEnd += 1;
        } else if (compare(right, end) <= 0) {
            lessThanEnd += 1;
        }
    }
    console.log(total, (lessThanStart + 1) * (lessThanEnd + 1 + 1));
}

question('temp');
question('13.input');
