import { readFileSync } from 'fs';

type File = {
    name: string;
    size: number;
};

type Directory = {
    name: string;
    dirs?: Record<string, Directory>;
    files?: Record<string, File>;
    size?: number;
};

const TOTAL: number = 70000000;
const NEED: number = 30000000;

function question(file: string, max: number): void {
    const root: Directory = { name: '/' };
    const stack: Directory[] = [root];

    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    let currentStackIndex = 0;
    for (const line of inputs) {
        if (line.startsWith('$')) {
            const [command, name] = line
                .slice(1)
                .split(' ')
                .map((x) => x.trim())
                .filter((x) => x.length);

            if (command === 'cd') {
                if (name === '/') {
                    currentStackIndex = 0;
                } else if (name === '..') {
                    if (currentStackIndex > 0) {
                        currentStackIndex -= 1;
                    }
                } else {
                    // must a known directory
                    const dir = stack[currentStackIndex].dirs![name];
                    stack[++currentStackIndex] = dir;
                }
            } else if (command === 'ls') {
                // do nothing here
            }
        } else {
            const [dirOrSize, name] = line
                .split(' ')
                .map((x) => x.trim())
                .filter((x) => x.length);
            if (dirOrSize === 'dir') {
                if (stack[currentStackIndex].dirs === undefined) {
                    stack[currentStackIndex].dirs = {};
                }
                if (stack[currentStackIndex].dirs![name] === undefined) {
                    stack[currentStackIndex].dirs![name] = { name };
                }
            } else {
                const size = Number(dirOrSize);
                if (stack[currentStackIndex].files === undefined) {
                    stack[currentStackIndex].files = {};
                }
                // always update the file size
                stack[currentStackIndex].files![name] = { name, size };
            }
        }
    }

    // update the directory size
    const updateDirectorySize = (dir: Directory): number => {
        if (dir.size !== undefined) {
            return dir.size;
        }
        dir.size =
            Object.values(dir.files ?? {}).reduce((a, b) => a + b.size, 0) +
            Object.values(dir.dirs ?? {}).reduce((a, b) => a + updateDirectorySize(b), 0);
        return dir.size;
    };

    const myth = (dir: Directory, max?: number, total?: [number], atLeast?: number, current?: [number]): void => {
        if (dir.size == undefined) {
            updateDirectorySize(dir);
        }

        Object.values(dir.dirs ?? {}).map((x) => myth(x, max, total, atLeast, current));
        if (max !== undefined && total !== undefined) {
            if (dir.size! <= max) {
                total[0] += dir.size!;
            }
        }

        if (atLeast !== undefined && current !== undefined) {
            if (dir.size! >= atLeast && dir.size! <= current[0]) {
                current[0] = dir.size!;
            }
        }
    };
    updateDirectorySize(root);

    const total: [number] = [0];
    const current: [number] = [root.size!];
    myth(root, max, total, NEED + root.size! - TOTAL, current);
    console.log(total[0], current[0]);
}

question('temp', 100000);
question('7.input', 100000);
