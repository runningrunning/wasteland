import { readFileSync } from 'fs';

function question(file: string, n: number): number {
    const input = readFileSync(file, 'utf-8').trim();
    for (let i = n; i <= input.length; i++) {
        if (new Set(input.slice(i - n, i)).size === n) {
            return i;
        }
    }
    return 0;
}

console.log(question('temp', 4), question('temp', 14));
console.log(question('6.input', 4), question('6.input', 14));
