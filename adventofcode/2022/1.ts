import { readFileSync } from 'fs';

function question(file: string, topN = 1): number {
    const all = readFileSync(file, 'utf-8')
        .split('\n\n')
        .map((x) =>
            x
                .split('\n')
                .map((x) => x.trim())
                .filter((x) => x.length)
                .map(Number)
                .reduce((a, b) => a + b)
        ).sort((a, b) => a -b);
    return all.slice(all.length - topN).reduce((a, b) => a + b);
}

console.log(question('temp'), question('temp', 3));
console.log(question('1.input'), question('1.input', 3));