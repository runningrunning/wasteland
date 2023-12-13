import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

function parse(input: string): {
    wins: Set<string>;
    score: number;
} {
    const [cardID, others] = input.split(':');
    const id = Number(cardID.split('Card ')[1]);
    const [winS, cardsS] = others.split('|');
    const wins = new Set(winS.split(' ').filter((x) => x !== ''));
    const num = cardsS
        .trim()
        .split(' ')
        .filter((x) => wins.has(x)).length;
    return { wins, score: num ? Math.pow(2, num - 1) : 0 };
}

const allCards = [0];

function addToCards(index: number, num: number) {
    if (allCards.length <= index) {
        allCards.push(num);
    } else {
        allCards[index] += num;
    }
}

function parse2(input: string): void {
    const [cardID, others] = input.split(':');
    const id = Number(cardID.split('Card ')[1]);
    addToCards(id, 1);

    const cur = allCards[id];
    const [winS, cardsS] = others.split('|');
    const wins = new Set(winS.split(' ').filter((x) => x !== ''));
    const num = cardsS
        .trim()
        .split(' ')
        .filter((x) => wins.has(x)).length;

    for (let i = 0; i < num; i++) {
        addToCards(id + 1 + i, cur);
    }
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        rl.on('line', (line) => {
            const parsed = parse(line);
            parse2(line);
            total += parsed.score;
        });
        await once(rl, 'close');
        console.log(
            'File Processed ',
            total,
            allCards.reduce((pre, cur) => pre + cur)
        );
    } catch (err) {
        console.error(err);
    }
}
processLineByLine('4.input');
