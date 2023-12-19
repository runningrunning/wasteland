import { readFileSync } from 'fs';
import { off } from 'process';

// line > 0 is row, line < 0 is column
function isReflectionWithNDiff(input: Array<string>, line: number, ignoreNumber: number): boolean {
    if (line > 0) {
        let max = Math.min(line, input.length - line);
        for (let i = 0; i < max; i++) {
            for (let j = 0; j < input[0].length; j++) {
                if (input[line - i - 1][j] !== input[line + i][j]) {
                    ignoreNumber--;
                    if (ignoreNumber < 0) {
                        return false;
                    }
                }
            }
        }
    } else {
        line = -line;
        let max = Math.min(line, input[0].length - line);
        for (let i = 0; i < max; i++) {
            for (const l of input) {
                if (l[line - i - 1] !== l[line + i]) {
                    ignoreNumber--;
                    if (ignoreNumber < 0) {
                        return false;
                    }
                }
            }
        }
    }
    return ignoreNumber === 0;
}

function reflectionNumber(input: Array<string>, offset = 0): number {
    let max = 0;
    for (let i = 0; i < input.length - 1; i++) {
        if (isReflectionWithNDiff(input, i + 1, offset)) {
            max = i + 1;
        }
    }

    if (max !== 0) {
        return max * 100;
    }

    for (let j = 0; j < input[0].length - 1; j++) {
        if (isReflectionWithNDiff(input, -j - 1, offset)) {
            max = j + 1;
        }
    }
    return max;
}

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8').split('\n\n');
    const maps = inputs.map((input) => input.split('\n').map((x) => x.trim()));
    const total = maps.reduce((acc, map) => acc + reflectionNumber(map), 0);
    const total2 = maps.reduce((acc, map) => acc + reflectionNumber(map, 1), 0);
    console.log('q1', total, 'q2', total2);
}

question('temp');
question('13.input');
