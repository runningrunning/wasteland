import { readFileSync } from 'fs';

const cargos = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
function question(file: string): number {
    let total = 0;
    const all = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);
    for (const line of all) {
        const half = line.length / 2;
        const seen = new Set(line.slice(0, half).split(''));

        for (let i = 0; i < half; i++) {
            if (seen.has(line[i + half])) {
                total += cargos.indexOf(line[i + half]) + 1;
                break;
            }
        }
    }
    return total;
}

function question2(file: string): number {
    let total = 0;
    const all = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);

    const intersect = (a: Set<string>, b: Set<string>): Set<string> => {
        return new Set([...a].filter((x) => b.has(x)));
    };

    for (let i = 0; i < all.length; i += 3) {
        const set1 = new Set(all[i].split(''));
        const set2 = new Set(all[i + 1].split(''));
        const set3 = new Set(all[i + 2].split(''));
        const x = Array.from(intersect(intersect(set1, set2), set3))[0];
        total += cargos.indexOf(x) + 1;
    }
    return total;
}

console.log(question('temp'), question2('temp'));
console.log(question('3.input'), question2('3.input'));
