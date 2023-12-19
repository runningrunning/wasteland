import { readFileSync } from 'fs';

function question(file: string): [number, number] {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    let total = 0;
    let overlap = 0;
    for (const line of inputs) {
        const [pre, after] = line.split(',').map((x) => x.trim());
        const [pre1, pre2] = pre.split('-').map(Number);
        const [after1, after2] = after.split('-').map(Number);

        if ((pre1 <= after1 && pre2 >= after2) || (pre1 >= after1 && pre2 <= after2)) {
            total += 1;
        }

        if (pre1 <= after2 && pre2 >= after1) {
            overlap += 1;
        }
    }

    return [total, overlap];
}

console.log(question('temp'));
console.log(question('4.input'));
