import { readFileSync } from 'fs';

type Point = {
    x: number;
    y: number;
};

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim());
    const galaxies: Array<Point> = [];
    const spacesX = new Array<boolean>(inputs[0].length).fill(true);
    const spacesY = new Array<boolean>(inputs[0].length).fill(true);

    for (let i = 0; i < inputs.length; i++) {
        const line = inputs[i];
        if (line.includes('#')) {
            spacesY[i] = false;
            let lastPosition = 0;
            do {
                let index = line.indexOf('#', lastPosition);
                if (index === -1) {
                    break;
                }
                spacesX[index] = false;
                galaxies.push({ x: index, y: i });
                lastPosition = index + 1;
            } while (true);
        }
    }

    const countDistance = (from: number, to: number, space: Array<boolean>): number => {
        let extra = 0;
        if (from > to) {
            [from, to] = [to, from];
        }

        for (let i = from; i < to; i++) {
            if (space[i]) {
                // extra +=2 - 1;
                // extra +=10 - 1;
                // extra +=100 -1;
                extra += 1000000 - 1;
            }
        }
        return extra + to - from;
    };

    let length = 0;
    for (let i = 0; i < galaxies.length; i++) {
        for (let j = i + 1; j < galaxies.length; j++) {
            length += countDistance(galaxies[i].x, galaxies[j].x, spacesX);
            length += countDistance(galaxies[i].y, galaxies[j].y, spacesY);
        }
    }

    console.log('distance', length);
}

question('temp');
question('11.input');
