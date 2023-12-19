import { readFileSync } from 'fs';

function question(file: string, length: number = 2): number {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split(' '));

    const offset: Record<string, [number, number]> = {
        R: [1, 0],
        L: [-1, 0],
        U: [0, -1],
        D: [0, 1],
    };
    const positions = new Set<string>();
    const ropes: Array<[number, number]> = [];
    for (let i = 0; i < length; i++) {
        ropes.push([0, 0]);
    }

    // add the tail
    positions.add(ropes.slice(-1).join(','));

    // 0.5 => 1, -0.5 => -1
    // 1 => 1, -1 => -1
    const roundAwayZero = (n: number): number => {
        return n > 0 ? Math.ceil(n) : Math.floor(n);
    };

    const forward = (src: number, dst: number): number => {
        return src + roundAwayZero((dst - src) / 2);
    };

    for (const [x, y] of inputs) {
        let n = Number(y);
        const [ox, oy] = offset[x];
        while (n--) {
            // update the header
            ropes[0][0] += ox;
            ropes[0][1] += oy;

            /*
            // when it's moved as the body, it may need go to diagonal as both x, y are diff in 2.
            // but never be the head, since it can only R/L/U/D
            for (let i = 1; i < ropes.length; i++) {
                // always go diagonally
                if (Math.abs(ropes[i][0] - ropes[i - 1][0]) === 2) {
                    ropes[i][0] += (ropes[i - 1][0] - ropes[i][0]) / 2;
                    if (Math.abs(ropes[i][1] - ropes[i - 1][1]) === 2) {
                        ropes[i][1] += (ropes[i - 1][1] - ropes[i][1]) / 2;
                    } else {
                        ropes[i][1] = ropes[i - 1][1];
                    }
                } else if (Math.abs(ropes[i][1] - ropes[i - 1][1]) === 2) {
                    ropes[i][1] += (ropes[i - 1][1] - ropes[i][1]) / 2;
                    ropes[i][0] = ropes[i - 1][0];
                } else {
                    break;
                }
            }
            */

            // when it's moved as the body, it may need go to diagonal as both x, y are diff in 2.
            // but never be the head, since it can only R/L/U/D
            for (let i = 1; i < ropes.length; i++) {
                // always go diagonally
                if (Math.abs(ropes[i][0] - ropes[i - 1][0]) === 2 || Math.abs(ropes[i][1] - ropes[i - 1][1]) === 2) {
                    ropes[i][0] += roundAwayZero((ropes[i - 1][0] - ropes[i][0]) / 2);
                    ropes[i][1] += roundAwayZero((ropes[i - 1][1] - ropes[i][1]) / 2);
                } else {
                    break;
                }
            }

            positions.add(ropes.slice(-1).join(','));
        }
    }
    return positions.size;
}

console.log(question('temp'), question('temp', 10));
console.log(question('9.input'), question('9.input', 10));
