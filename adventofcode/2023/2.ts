import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

function parse(input: string): {
    id: number;
    cubes: Record<string, number>;
} {
    const [gameID, others] = input.split(':');
    const id = Number(gameID.split('Game ')[1]);
    const cubes: Record<string, number> = { blue: 0, red: 0, green: 0 };
    for (const time of others.split(';')) {
        for (const cube of time.split(',')) {
            const [numbers, color] = cube.trim().split(' ');
            cubes[color] = Math.max(Number(numbers), Number(cubes[color]));
        }
    }
    return { id, cubes };
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        let totalPower = 0;

        rl.on('line', (line) => {
            const parsed = parse(line);
            if (parsed.cubes.red <= 12 && parsed.cubes.green <= 13 && parsed.cubes.blue <= 14) {
                total += parsed.id;
            }
            totalPower += parsed.cubes.red * parsed.cubes.blue * parsed.cubes.green;
        });
        await once(rl, 'close');
        console.log('File Processed ', total, totalPower);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('2.input');
