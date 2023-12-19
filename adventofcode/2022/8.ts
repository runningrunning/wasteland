import { readFileSync } from 'fs';

function question(file: string): number {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    const X = inputs[0].length;
    const Y = inputs.length;
    const visible: Array<Array<number>> = [];
    for (let i = 0; i < Y; i++) {
        visible[i] = [];
    }

    // left and right
    for (let i = 0; i < Y; i++) {
        let curL = -1;
        let curR = -1;
        for (let j = 0; j < X; j++) {
            const left = Number(inputs[i][j]);
            const right = Number(inputs[i][X - 1 - j]);
            if (left > curL) {
                curL = left;
                visible[i][j] = 1;
            }
            if (right > curR) {
                curR = right;
                visible[i][X - 1 - j] = 1;
            }
        }
    }

    // up and down
    for (let i = 0; i < X; i++) {
        let curU = -1;
        let curD = -1;
        for (let j = 0; j < Y; j++) {
            const up = Number(inputs[j][i]);
            const down = Number(inputs[Y - 1 - j][i]);
            if (up > curU) {
                curU = up;
                visible[j][i] = 1;
            }
            if (down > curD) {
                curD = down;
                visible[Y - 1 - j][i] = 1;
            }
        }
    }
    return visible.reduce((acc, cur) => acc + cur.reduce((acc, cur) => acc + cur, 0), 0);
}

function question2(file: string): number {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split('').map(Number));

    let max = 0;
    const X = inputs[0].length;
    const Y = inputs.length;
    const score = (x: number, y: number): number => {
        const cur = inputs[y][x];
        let up = 0;
        let down = 0;
        let left = 0;
        let right = 0;

        let u = y - 1;
        while (u >= 0) {
            up++;
            if (cur <= inputs[u][x]) {
                break;
            }
            u--;
        }

        let d = y + 1;
        while (d < Y) {
            down++;
            if (cur <= inputs[d][x]) {
                break;
            }
            d++;
        }

        let l = x - 1;
        while (l >= 0) {
            left++;
            if (cur <= inputs[y][l]) {
                break;
            }
            l--;
        }

        let r = x + 1;
        while (r < X) {
            right++;
            if (cur <= inputs[y][r]) {
                break;
            }
            r++;
        }
        return up * down * left * right;
    };

    for (let i = 0; i < Y; i++) {
        for (let j = 0; j < X; j++) {
            const s = score(j, i);
            if (max < s) {
                max = s;
            }
        }
    }
    return max;
}

console.log(question('temp'), question2('temp'));
console.log(question('8.input'), question2('8.input'));
