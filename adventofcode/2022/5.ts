import { readFileSync } from 'fs';

function question(file: string, multiple = false): string {
    const [cargos, steps] = readFileSync(file, 'utf-8')
        .split('\n\n')
        .map((x) => x.split('\n').filter((x) => x.length));

    // it's good since it's less than 10 lines
    const current: Array<string> = [];
    const last = cargos[cargos.length - 1];
    for (let i = 0; i < last.length; i++) {
        if (last[i] !== ' ') {
            const line: Array<string> = [];
            let c = cargos.length - 1;
            while (c > 0 && cargos[c - 1][i] !== ' ') {
                line.push(cargos[--c][i]);
            }
            current.push(line.join(''));
        }
    }

    for (const step of steps) {
        const s = step.split(' ');
        let n = Number(s[1]);
        let f = Number(s[3]) - 1;
        let t = Number(s[5]) - 1;

        const moved = current[f].slice(-n);
        current[f] = current[f].slice(0, -n);
        current[t] += multiple ? moved : moved.split('').reverse().join('');
    }
    return current.reduce((a, b) => a + b[b.length - 1], '');
}

console.log(question('temp'), question('temp', true));
console.log(question('5.input'), question('5.input', true));
