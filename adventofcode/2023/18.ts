// Tags: difficult, geometry, new algorithm
// Try Pick's_theorem or Shoelace_formula
// https://en.m.wikipedia.org/wiki/Shoelace_formula
// Implement this https://blog.51cto.com/u_15715098/5710889
import { readFileSync } from 'fs';

type Edge = {
    id: number;
    sx: number;
    sy: number;
    dx: number;
    dy: number;
    xRange: [number, number];
    yRange: [number, number];
    direction: string;
};

type Range = {
    minX: number;
    maxX: number;
    minY: number;
    maxY: number;
};

const Direction: Record<string, [number, number]> = {
    L: [-1, 0],
    R: [1, 0],
    U: [0, 1],
    D: [0, -1],
};

const DMap: Record<string, string> = {
    '0': 'R',
    '1': 'D',
    '2': 'L',
    '3': 'U',
};

function onTheEdge(x: number, y: number, edges: Array<Edge>): Edge | undefined {
    return edges.find((edge): boolean => {
        if (x !== edge.sx && y !== edge.sy) {
            return false;
        }
        if (x === edge.sx) {
            return y >= edge.yRange[0] && y <= edge.yRange[1];
        }
        return x >= edge.xRange[0] && x <= edge.xRange[1];
    });
}

function intersectH(y: number, sx: number, dx: number, edges: Array<Edge>): Array<number> {
    const result = new Set<number>();
    edges.forEach((edge) => {
        if (edge.sy === y && edge.dy === y) {
            if (sx <= edge.xRange[1] && dx >= edge.xRange[0]) {
                result.add(edge.xRange[0]);
                result.add(edge.xRange[1]);
            }
        } else if (edge.sx === edge.dx) {
            if (y >= edge.yRange[0] && y <= edge.yRange[1]) {
                result.add(edge.sx);
            }
        }
    });
    return Array.from(result)
        .sort((a, b) => a - b)
        .filter((x) => x >= sx && x <= dx);
}

function intersectV(x: number, sy: number, dy: number, edges: Array<Edge>): Array<number> {
    const result = new Set<number>();
    edges.forEach((edge) => {
        if (edge.sx === x && edge.dx === x) {
            if (sy <= edge.yRange[1] && dy >= edge.yRange[0]) {
                result.add(edge.yRange[0]);
                result.add(edge.yRange[1]);
            }
        } else if (edge.sy === edge.dy) {
            if (x >= edge.xRange[0] && x <= edge.xRange[1]) {
                result.add(edge.sy);
            }
        }
    });
    return Array.from(result)
        .sort((a, b) => a - b)
        .filter((x) => x >= sy && x <= dy);
}

// When the point is inside, it cross the edges odd times
//
// Count as cross twice, since the two h line with this v are at the same direction
// ......v......
// ......v......
// ......####### < h
// ......#......
// ......#......
// ......####### < h
//
// Count as cross once, since the two h line with this v are not the same direction
// ......v......
// ......v......
// ......####### < h
// ......#......
// ......#......
// #######...... < h
//
function isOutSide(x: number, y: number, edges: Array<Edge>, range: Range): boolean {
    const pre = (id: number): Edge => edges[(edges.length + id - 1) % edges.length];
    const nxt = (id: number): Edge => edges[(id + 1) % edges.length];

    // Not on the edge, check how much edges crossed to know whether it's inside or outside
    if (onTheEdge(x, y, edges)) {
        return false;
    }

    // any direction in the path, check UP here
    // start from the next UP point
    const keyPoints = intersectV(x, y + 1, range.maxY, edges);
    let c = 0;
    keyPoints.forEach((u) => {
        const matchPath = onTheEdge(x, u, edges);
        if (matchPath) {
            // find the next start point of current (x, u), if exists, check whether the two H line are at the same direction
            const found = edges.find((path) => path.sx === x && path.sy === u && 'UD'.includes(path.direction));
            if (found) {
                // Same direction as cross once
                if (pre(found.id).direction === nxt(found.id).direction) {
                    c += 1;
                }
            } else if ('LR'.includes(edges[matchPath.id].direction)) {
                // If it's not at the start point of edges, just check whether it's LR and blocked the path
                c += 1;
            }
        }
    });
    // only odd time is inside
    return c % 2 === 0;
}

// Count how many points on the line are inside the polygon or on the edge
function countLine(y: number, edges: Array<Edge>, range: Range): number {
    const all = intersectH(y, range.minX, range.maxX, edges);
    let total = all[all.length - 1] - all[0] + 1;
    for (let k = 0; k < all.length - 1; k++) {
        const from = all[k];
        const to = all[k + 1];
        if (to - from > 1) {
            if (isOutSide(from + 1, y, edges, range)) {
                total -= to - from - 1;
            }
        }
    }
    return total;
}

function question(file: string, Q1 = true): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .map((x) => x.split(' '));

    const edges: Array<Edge> = [];
    let id = 0;
    let [px, py] = [0, 0];

    const range: Range = {
        minX: 0,
        maxX: 0,
        minY: 0,
        maxY: 0,
    };

    const parseQ1 = (input: string[]): [string, number] => {
        return [input[0], parseInt(input[1], 10)];
    };
    const parseQ2 = (input: string[]): [string, number] => {
        return [DMap[input[2][7]], parseInt(input[2].slice(2, 7), 16)];
    };

    for (const input of inputs) {
        const [direction, length] = Q1 ? parseQ1(input) : parseQ2(input);
        const dx = px + Direction[direction][0] * length;
        const dy = py + Direction[direction][1] * length;
        edges.push({
            id,
            sx: px,
            sy: py,
            direction,
            dx,
            dy,
            xRange: direction === 'L' ? [dx, px] : [px, dx],
            yRange: direction === 'D' ? [dy, py] : [py, dy],
        });
        px = dx;
        py = dy;
        if (px < range.minX) range.minX = px;
        if (px > range.maxX) range.maxX = px;
        if (py < range.minY) range.minY = py;
        if (py > range.maxY) range.maxY = py;
        id += 1;
    }

    let count = 0;
    const keyY = Array.from(new Set(edges.map((path) => path.sy))).sort((a, b) => a - b);
    // check between the key Y points, it means there are only | lines between them
    // so we can count the points between them as countLine() * (toY - fromY - 1)
    for (let c = 0; c < keyY.length - 1; c++) {
        const fromY = keyY[c];
        const toY = keyY[c + 1];
        if (toY - fromY > 1) {
            count += countLine(fromY + 1, edges, range) * (toY - fromY - 1);
        }
    }

    // count the points on the key Y points
    keyY.forEach((y) => {
        count += countLine(y, edges, range);
    });

    console.log(count);
}

question('temp');
question('18.input');

question('temp', false);
question('18.input', false);
