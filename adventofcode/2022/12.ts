import { readFileSync } from 'fs';

type Trail = {
    x: number;
    y: number;
    preHeight: number;
};

function question(file: string, S: number = 'S'.charCodeAt(0), E: number = 'E'.charCodeAt(0)): number {
    const startHeight = S === 'S'.charCodeAt(0) ? 'a'.charCodeAt(0) : 'z'.charCodeAt(0);
    const endHeight = E === 'E'.charCodeAt(0) ? 'z'.charCodeAt(0) : 'a'.charCodeAt(0);
    const reverse = S === 'E'.charCodeAt(0);

    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split('').map((x) => x.charCodeAt(0)));

    const steps: Array<Array<number>> = [];
    for (let i = 0; i < inputs.length; i++) {
        steps[i] = new Array(inputs[i].length).fill(0);
    }

    const X = inputs[0].length;
    const Y = inputs.length;

    // x, y
    let stacks: Array<Trail> = [];
    for (let i = 0; i < Y; i++) {
        for (let j = 0; j < X; j++) {
            if (inputs[i][j] === S) {
                // The start point is startHeight
                stacks.push({ x: j, y: i, preHeight: startHeight });
            }
        }
    }

    const mark = (x: number, y: number, preHeight: number, next: Array<Trail>): void => {
        next.push({ x, y, preHeight });
    };

    // BFS
    let stepsCount = 0;

    while (stacks.length) {
        let nexts: Array<Trail> = [];
        for (const stack of stacks) {
            // out of bound
            if (stack.x < 0 || stack.x >= X || stack.y < 0 || stack.y >= Y) {
                continue;
            }

            // already been here
            if (steps[stack.y][stack.x] > 0) {
                continue;
            }

            // verify whether it's possible to be here
            const currentHeight =
                inputs[stack.y][stack.x] === S
                    ? startHeight
                    : inputs[stack.y][stack.x] === E
                    ? endHeight
                    : inputs[stack.y][stack.x];

            // not possible to be here
            if (reverse) {
                // Can be much higher, but at most 1 level lower
                if (stack.preHeight - currentHeight > 1) {
                    continue;
                }
            } else {
                // Can be much lower, but at most 1 level higher
                if (currentHeight - stack.preHeight > 1) {
                    continue;
                }
            }

            // matched the end point
            if (inputs[stack.y][stack.x] === E || (reverse && inputs[stack.y][stack.x] === endHeight)) {
                return stepsCount;
            }

            steps[stack.y][stack.x] = stepsCount + 1;

            // try next position
            mark(stack.x - 1, stack.y, currentHeight, nexts);
            mark(stack.x + 1, stack.y, currentHeight, nexts);
            mark(stack.x, stack.y - 1, currentHeight, nexts);
            mark(stack.x, stack.y + 1, currentHeight, nexts);
        }
        stacks = nexts;
        stepsCount += 1;
    }
    return 0;
}

function question2(file: string): number {
    return question(file, 'E'.charCodeAt(0), 'S'.charCodeAt(0));
}

console.log(question('temp'), question2('temp'));
console.log(question('12.input'), question2('12.input'));
