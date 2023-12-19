// Tags: Dijkstra, difficult
import { readFileSync } from 'fs';

// It's not suitable as DFS/BFS or recursive DP with caches, because the size of the steps is way too large
// So we start from the bottom, Dijkstra is the best choice
function question(file: string, maxSteps: number = 3, minSteps: number = 1): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split('').map(Number));

    // LR is 0, UD is 1
    const mins = new Array<Array<[number, number]>>(inputs.length);
    const X = inputs[0].length;
    const Y = inputs.length;

    for (let i = 0; i < Y; i++) {
        mins[i] = new Array(X);
        for (let j = 0; j < X; j++) {
            mins[i][j] = [Infinity, Infinity];
        }
    }

    mins[Y - 1][X - 1] = [0, 0];
    let stacks: Array<[number, number, number]> = [
        [X - 1, Y - 1, 0],
        [X - 1, Y - 1, 1],
    ];

    const cost = (x: number, y: number, nx: number, ny: number): number => {
        let cur = 0;
        let minX = Math.min(x, nx);
        let maxX = Math.max(x, nx);
        let minY = Math.min(y, ny);
        let maxY = Math.max(y, ny);
        for (let i = minX; i <= maxX; i++) {
            for (let j = minY; j <= maxY; j++) {
                if (i !== x || j !== y) {
                    cur += inputs[j][i];
                }
            }
        }
        return cur;
    };

    // Update the minimum steps to reach the end point
    while (stacks.length) {
        let next: Array<[number, number, number]> = [];
        for (const [x, y, n] of stacks) {
            const currentMin = mins[y][x];
            const maxX = Math.min(x + maxSteps, X - 1);
            const maxY = Math.min(y + maxSteps, Y - 1);
            const minX = Math.max(x - maxSteps, 0);
            const minY = Math.max(y - maxSteps, 0);

            // UD
            if (n === 1) {
                // Previous is LR
                for (let i = minX; i <= maxX; i++) {
                    if (Math.abs(i - x) < minSteps) continue;
                    const c = cost(i, y, x, y);
                    if (currentMin[1] + c < mins[y][i][0]) {
                        mins[y][i][0] = currentMin[1] + c;
                        next.push([i, y, 0]);
                    }
                }
            } else {
                // LR
                for (let i = minY; i <= maxY; i++) {
                    if (Math.abs(i - y) < minSteps) continue;
                    const c = cost(x, i, x, y);
                    if (currentMin[0] + c < mins[i][x][1]) {
                        mins[i][x][1] = currentMin[0] + c;
                        next.push([x, i, 1]);
                    }
                }
            }
        }
        stacks = next;
    }
    console.log(Math.min(...mins[0][0]));
}

question('temp');
question('17.input');
question('temp', 10, 4);
question('17.input', 10, 4);
