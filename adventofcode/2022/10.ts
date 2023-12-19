import { readFileSync } from 'fs';

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.split(' ').filter((x) => x.length));
    let cycle = 0;
    let count = 0;
    let threshold = 20;
    let x = 1;
    let crt: Array<string> = [];

    for (const input of inputs) {
        let dx = 0;
        if (input[0] === 'addx') {
            crt.push(cycle % 40 >= x - 1 && cycle % 40 <= x + 1 ? '#' : '.');
            cycle += 1;
            crt.push(cycle % 40 >= x - 1 && cycle % 40 <= x + 1 ? '#' : '.');
            cycle += 1;
            dx = Number(input[1]);
        } else {
            crt.push(cycle % 40 >= x - 1 && cycle % 40 <= x + 1 ? '#' : '.');
            cycle += 1;
        }
        // the new x will be effective in the next cycle
        if (cycle >= threshold) {
            count += x * threshold;
            threshold += 40;
        }
        x += dx;
    }
    console.log(count);
    for (let i = 0; i < 6; i++) {
        console.log(crt.slice(0, 40).join(''));
        crt = crt.slice(40);
    }
}

question('temp');
question('10.input');
