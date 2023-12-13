import { readFileSync } from 'fs';

const orderType: Record<string, number> = {
    '2': 1,
    '3': 2,
    '4': 3,
    '5': 4,
    '6': 5,
    '7': 6,
    '8': 7,
    '9': 8,
    T: 9,
    J: 10,
    Q: 11,
    K: 12,
    A: 13,
};

const orderTypeJoker: Record<string, number> = {
    '2': 1,
    '3': 2,
    '4': 3,
    '5': 4,
    '6': 5,
    '7': 6,
    '8': 7,
    '9': 8,
    T: 9,
    J: 0,
    Q: 11,
    K: 12,
    A: 13,
};

const typeScores: Record<string, number> = {
    '11111': 0,
    '2111': 1,
    '221': 2,
    '311': 3,
    '32': 4,
    '41': 5,
    '5': 6,
};

function typeScore(input: string, joker: boolean) {
    const orders = joker ? orderTypeJoker : orderType;
    const x = new Array<number>(orders['A'] + 1).fill(0);
    for (const s of input) {
        x[orders[s]]++;
    }

    const jokerNumber = x[orders['J']];
    if (jokerNumber === input.length) {
        return typeScores['5'];
    }

    if (joker) {
        x[orders['J']] = 0;
    }

    let numbers = x
        .sort()
        .reverse()
        .filter((x) => x);

    if (joker) {
        numbers[0] += jokerNumber;
    }
    return typeScores[numbers.join('')];
}

type Parsed = { ori: string; score: number; bid: number };

function question(file: string, joker = false) {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .filter((x) => x.trim().length);
    const parsed: Array<Parsed> = inputs.map((s) => {
        const [cards, bid] = s.split(' ').map((s) => s.trim());
        return { ori: cards, score: typeScore(cards, joker), bid: Number(bid) };
    });

    const orders = joker ? orderTypeJoker : orderType;

    parsed.sort((a, b) => {
        if (a === b) return 0;
        if (a.score !== b.score) {
            return a.score - b.score;
        }
        for (let i = 0; i < a.ori.length; i++) {
            if (a.ori[i] !== b.ori[i]) {
                return orders[a.ori[i]] - orders[b.ori[i]];
            }
        }
        return 0;
    });

    console.log(
        'sum',
        parsed.reduce((p, c, i) => {
            return p + c.bid * (i + 1);
        }, 0)
    );
}

question('7.input', false);
question('7.input', true);
