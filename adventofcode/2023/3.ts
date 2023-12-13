import { once } from 'node:events';
import { createReadStream } from 'node:fs';
import { createInterface } from 'node:readline';

type Symbol = number | string | undefined;
type PointNumber = {
    value: number;
    ori: number;
};

type Parsed = {
    numbers: Array<undefined | PointNumber>;
    symbols: Array<Symbol>;
    score: number;
};

let starSymbolIndex = 0;
const starSymbols = new Array<Set<PointNumber>>();

function checkSymbol(i: number, symbols?: Array<Symbol>, number?: PointNumber): boolean {
    if (symbols === undefined) {
        return false;
    }
    if (i < 0 || i >= symbols.length) {
        return false;
    }

    const symbol = symbols[i];
    if (typeof symbol === 'number' && number) {
        starSymbols[symbol].add(number);
    }

    return symbol !== undefined;
}

function checkNumbers(i: number, numbers?: Array<undefined | PointNumber>, symbol?: Symbol): number {
    if (numbers === undefined) {
        return 0;
    }

    if (i < 0 || i >= numbers.length) {
        return 0;
    }

    const num = numbers[i];

    if (num !== undefined && num.value !== 0) {
        const value = num.value;
        num.value = 0;

        if (typeof symbol === 'number') {
            starSymbols[symbol].add(num);
        }
        return value;
    }
    return 0;
}

function parse(input: string, previous?: Parsed): Parsed {
    const symbols = new Array(input.length);
    const numbers = new Array(input.length);
    let i = 0;
    let j = 0;
    let score = 0;

    for (i = 0; i < input.length; i++) {
        symbols[i] = undefined;
        numbers[i] = undefined;

        if (input[i] !== '.') {
            if (input[i] < '0' || input[i] > '9') {
                if (input[i] === '*') {
                    symbols[i] = starSymbolIndex++;
                    starSymbols.push(new Set<PointNumber>());
                } else {
                    symbols[i] = input[i];
                }
                continue;
            }

            let n = 0;
            for (j = i; j < input.length; j++) {
                if (input[j] >= '0' && input[j] <= '9') {
                    n = n * 10 + Number(input[j]);
                } else {
                    break;
                }
            }
            const value = { value: n, ori: n };
            for (let k = i; k < j; k++) {
                numbers[k] = value;
            }
            i = j - 1;
        }
    }

    for (i = 0; i < input.length; i++) {
        if (numbers[i] !== undefined && numbers[i].value !== 0) {
            if (
                checkSymbol(i - 1, previous?.symbols, numbers[i]) ||
                checkSymbol(i, previous?.symbols, numbers[i]) ||
                checkSymbol(i + 1, previous?.symbols, numbers[i]) ||
                checkSymbol(i - 1, symbols, numbers[i]) ||
                checkSymbol(i + 1, symbols, numbers[i])
            ) {
                score += numbers[i].value;
                numbers[i].value = 0;
            }
        }

        if (symbols[i] !== undefined) {
            score += checkNumbers(i - 1, previous?.numbers, symbols[i]);
            score += checkNumbers(i + 1, previous?.numbers, symbols[i]);
            score += checkNumbers(i, previous?.numbers, symbols[i]);
        }
    }

    return { symbols, numbers, score };
}

async function processLineByLine(file: string) {
    try {
        const rl = createInterface({
            input: createReadStream(file),
            crlfDelay: Infinity,
        });
        let total = 0;
        let totalGear = 0;
        let parsed: Parsed | undefined = undefined;

        rl.on('line', (line) => {
            parsed = parse(line, parsed);
            total += parsed.score;
        });
        await once(rl, 'close');

        for (const gears of starSymbols) {
            let mul = 1;
            if (gears.size === 2) {
                for (const gear of gears.values()) {
                    mul *= gear.ori;
                }

                totalGear += mul;
            }
        }
        console.log('File Processed ', total, totalGear);
    } catch (err) {
        console.error(err);
    }
}

processLineByLine('3.input');
