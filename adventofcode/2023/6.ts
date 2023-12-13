import { readFileSync } from 'fs';

function question(file: string) {
    const inputs = readFileSync(file, 'utf-8').split('\n');

    const times = inputs[0]
        .split(':')[1]
        .split(' ')
        .filter((x) => x.length)
        .map(Number);
    const distances = inputs[1]
        .split(':')[1]
        .split(' ')
        .filter((x) => x.length)
        .map(Number);

    let multiple = 1;

    for (let i = 0; i < times.length; i++) {
        const t = times[i];
        const d = distances[i];

        let c = 0;
        for (let j = 1; j < t; j++) {
            if (j * (t - j) > d) {
                c = j;
                break;
            }
        }
        console.log(t, c, t - 2 * c + 1);
        multiple *= t - 2 * c + 1;
    }
    console.log(multiple);
}

function question2(file: string) {
    const inputs = readFileSync(file, 'utf-8').split('\n');

    const time = inputs[0]
        .split(':')[1]
        .split(' ')
        .filter((x) => x.length)
        .join('');
    const distance = inputs[1]
        .split(':')[1]
        .split(' ')
        .filter((x) => x.length)
        .join('');
    console.log(time, distance);

    const t = Number(time);
    const d = Number(distance);

    let c = 0;
    for (let j = 1; j < t; j++) {
        if (j * (t - j) > d) {
            c = j;
            break;
        }
    }
    console.log(t, c, t - 2 * c + 1);
}

question('6.input');
question2('6.input');
