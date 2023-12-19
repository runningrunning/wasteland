import { readFileSync } from 'fs';

const Score1: Record<string, number> = {
    A: 1,
    B: 2,
    C: 3,
};

const Score2: Record<string, number> = {
    X: 1,
    Y: 2,
    Z: 3,
};

function questions(file: string): [number, number] {
    let score = 0;
    let score2 = 0;
    for (const line of readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)) {
        const [a, b] = line.split(' ');
        score += Score2[b];
        if (Score1[a] === Score2[b]) {
            score += 3;
        } else if (Math.abs(Score2[b] + 3 - Score1[a]) % 3 === 1) {
            score += 6;
        }

        if (b === 'X') {
            score2 += Score1[a] !== 1 ? Score1[a] - 1 : 3;
        } else if (b === 'Y') {
            score2 += Score1[a] + 3;
        } else {
            score2 += (Score1[a] !== 3 ? Score1[a] + 1 : 1) + 6;
        }
    }
    return [score, score2];
}

console.log(questions('temp'));
console.log(questions('2.input'));
