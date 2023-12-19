import { readFileSync } from 'fs';

// BFS
const LightDirection: Record<string, [number, number, number]> = {
    L: [-1, 0, 0x1],
    R: [1, 0, 0x10],
    U: [0, 1, 0x100],
    D: [0, -1, 0x1000],
};

const Direction90: Record<string, Record<string, string>> = {
    '\\': {
        L: 'D',
        R: 'U',
        U: 'R',
        D: 'L',
    },
    '/': {
        L: 'U',
        R: 'D',
        U: 'L',
        D: 'R',
    },
};

type Light = {
    x: number;
    y: number;
    d: string; // 'L' | 'R' | 'U' | 'D';
};

function maxBeams(inputs: Array<Array<string>>, x: number, y: number, d: string): number {
    const X = inputs[0].length;
    const Y = inputs.length;

    const paths = new Array<Array<number>>(Y);
    for (let i = 0; i < Y; i++) {
        paths[i] = new Array<number>(X).fill(0);
    }

    let stacks: Array<Light> = [{ x, y, d }];

    const forward = (light: Light, stacks: Array<Light>): void => {
        stacks.push({
            x: light.x + LightDirection[light.d][0],
            y: light.y + LightDirection[light.d][1],
            d: light.d,
        });
    };

    while (stacks.length) {
        let next: Array<Light> = [];
        for (const light of stacks) {
            if (light.x < 0 || light.x >= X || light.y < 0 || light.y >= Y) {
                // out of bound
                continue;
            }

            // got the same direction light before, continue
            if (paths[light.y][light.x] & LightDirection[light.d][2]) {
                continue;
            }
            // mark current position
            paths[light.y][light.x] |= LightDirection[light.d][2];

            switch (inputs[light.y][light.x]) {
                case '.':
                    forward(light, next);
                    break;
                case '|':
                    if (light.d === 'U' || light.d === 'D') {
                        forward(light, next);
                    } else {
                        // just change the direction
                        forward({ ...light, d: 'U' }, next);
                        forward({ ...light, d: 'D' }, next);
                    }
                    break;
                case '-':
                    if (light.d === 'R' || light.d === 'L') {
                        forward(light, next);
                    } else {
                        // just change the direction
                        forward({ ...light, d: 'R' }, next);
                        forward({ ...light, d: 'L' }, next);
                    }
                    break;
                default: // '\' or '/'
                    forward({ ...light, d: Direction90[inputs[light.y][light.x]][light.d] }, next);
                    break;
            }
        }
        stacks = next;
    }
    return paths.reduce((acc, cur) => acc + cur.filter((x) => x).length, 0);
}
function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split(''));
    const X = inputs[0].length;
    const Y = inputs.length;

    // question 1
    console.log(maxBeams(inputs, 0, 0, 'R'));

    let max = 0;
    for (let i = 0; i < Y; i++) {
        max = Math.max(max, maxBeams(inputs, 0, i, 'R'), maxBeams(inputs, X - 1, i, 'L'));
    }
    for (let j = 0; j < X; j++) {
        max = Math.max(max, maxBeams(inputs, j, 0, 'U'), maxBeams(inputs, j, Y - 1, 'D'));
    }

    // question 2
    console.log(max);
}

question('temp');
question('16.input');
