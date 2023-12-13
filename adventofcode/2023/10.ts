import { readFileSync } from 'fs';

type Point = {
    x: number;
    y: number;
};

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim());
    const p1: Point = { x: 0, y: 0 };
    const p2: Point = { x: 0, y: 0 };
    const X = inputs[0].length;
    const Y = inputs.length;

    let lineNumber = 0;
    // find the start S
    for (const line of inputs) {
        if (line.indexOf('S') !== -1) {
            p1.x = p2.x = line.indexOf('S');
            p1.y = p2.y = lineNumber;
            break;
        }
        lineNumber++;
    }

    // passed[y][x];
    const passed = new Array<Array<boolean>>(Y);
    inputs.forEach((_, i) => (passed[i] = new Array(X).fill(false)));

    const connected: {
        up?: boolean;
        down?: boolean;
        left?: boolean;
        right?: boolean;
    } = {};

    if (p1.x > 0) {
        const left = inputs[p1.y][p1.x - 1];
        if (left === '-' || left === 'F' || left === 'L') {
            connected.left = true;
        }
    }

    if (p1.x < X - 1) {
        const right = inputs[p1.y][p1.x + 1];
        if (right === '-' || right === '7' || right === 'J') {
            connected.right = true;
        }
    }

    if (p1.y > 0) {
        const up = inputs[p1.y - 1][p1.x];
        if (up === '|' || up === 'F' || up === '7') {
            connected.up = true;
        }
    }

    if (p1.y < Y - 1) {
        const down = inputs[p1.y + 1][p1.x];
        if (down === '|' || down === 'J' || down === 'L') {
            connected.down = true;
        }
    }

    const stepsMap: Record<string, [Point, Point]> = {
        '|': [
            { x: 0, y: 1 },
            { x: 0, y: -1 },
        ],
        '-': [
            { x: -1, y: 0 },
            { x: 1, y: 0 },
        ],
        L: [
            { x: 1, y: 0 },
            { x: 0, y: -1 },
        ],
        '7': [
            { x: -1, y: 0 },
            { x: 0, y: 1 },
        ],
        J: [
            { x: -1, y: 0 },
            { x: 0, y: -1 },
        ],
        F: [
            { x: 1, y: 0 },
            { x: 0, y: 1 },
        ],
    };

    const toNewPosition = (current: string, point: Point): [Point, Point] => {
        const step = stepsMap[current];
        return [
            { x: point.x + step[0].x, y: point.y + step[0].y },
            { x: point.x + step[1].x, y: point.y + step[1].y },
        ];
    };

    let current = '';
    if (connected.left && connected.right) {
        current = '-';
    } else if (connected.left && connected.up) {
        current = 'J';
    } else if (connected.left && connected.down) {
        current = '7';
    } else if (connected.right && connected.up) {
        current = 'L';
    } else if (connected.right && connected.down) {
        current = 'F';
    } else if (connected.down && connected.up) {
        current = '|';
    } else {
        console.log('Error', connected);
    }
    let [lastP1, lastP2] = toNewPosition(current, p1);

    let currentP1 = p1;
    let currentP2 = p2;
    passed[p1.y][p1.x] = true;

    const startS = current;

    const nextPosition = (current: Point, last: Point): Point => {
        let pipe = inputs[current.y][current.x];
        if (pipe === 'S') {
            pipe = startS;
        }
        const [nextP1, nextP2] = toNewPosition(pipe, current);
        return last.x !== nextP1.x || last.y !== nextP1.y ? nextP1 : nextP2;
    };

    let step = 0;
    do {
        let nextP1 = nextPosition(currentP1, lastP1);
        let nextP2 = nextPosition(currentP2, lastP2);

        if (
            nextP1.x === currentP2.x &&
            nextP1.y === currentP2.y &&
            nextP2.x === currentP1.x &&
            nextP2.y === currentP1.y
        ) {
            console.log('break here');
            break;
        }

        lastP1 = currentP1;
        currentP1 = nextP1;
        lastP2 = currentP2;
        currentP2 = nextP2;

        passed[currentP1.y][currentP1.x] = true;
        passed[currentP2.y][currentP2.x] = true;

        step++;
    } while (currentP1.x !== currentP2.x || currentP1.y !== currentP2.y);

    console.log('step', step);

    // any direction if it's odd number of line blocks, it's inside
    // only take account one direction, so '-', '7' and 'J'
    // or '-', 'F' and 'L'
    const inside = (x: number, y: number) => {
        // just one direction should be enough, down is ok
        let ups = 0;

        while (y > 0) {
            let pipe = inputs[y - 1][x];
            if (pipe === 'S') {
                pipe = startS;
            }

            if (passed[y - 1][x]) {
                if (pipe === '7' || pipe === '-' || pipe === 'J') {
                    ups++;
                }
            }
            y--;
        }
        return ups % 2;
    };

    // question2
    let withIn = 0;
    for (let i = 0; i < Y; i++) {
        for (let j = 0; j < X; j++) {
            if (inputs[i][j] === '.' || passed[i][j] === false) {
                withIn += inside(j, i);
            }
        }
    }
    console.log('within', withIn);
}

question('10.input');
