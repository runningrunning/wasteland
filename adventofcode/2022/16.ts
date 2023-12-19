import { readFileSync } from 'fs';

type Valve = {
    name: string;
    tunnels: Array<string>;
    rate: number;
};

// find the shorted path from one gate to another gate
function question2(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);
    const valves: Record<string, Valve> = {};

    const withRate = new Set<string>();
    const parse = (line: string): Valve => {
        const divided = line.split(' ');
        const name = divided[1];
        const tunnels = divided.slice(9).map((x) => x.split(',')[0]);
        const rate = Number(divided[4].split('=')[1].split(';')[0]);
        return { name, tunnels, rate };
    };

    let totalRate = 0;

    for (const input of inputs) {
        const parsed = parse(input);
        valves[parsed.name] = parsed;
        if (parsed.rate !== 0) {
            withRate.add(parsed.name);
        }
        totalRate += parsed.rate;
    }

    const paths = new Map<string, number>();
    const allRates = Array.from(withRate);
    // start point
    if (allRates.includes('AA') === false) {
        allRates.push('AA');
    }

    for (let i = 0; i < allRates.length; i++) {
        const str = allRates[i];
        let passed = new Set<string>([str]);
        let start: Array<string> = [str];
        let steps = 0;
        while (start.length) {
            let next: Array<string> = [];
            steps += 1;
            for (const s of start) {
                for (const tunnel of valves[s].tunnels) {
                    if (passed.has(tunnel) === false) {
                        paths.set([str, tunnel].sort().join('|'), steps);
                        next.push(tunnel);
                        passed.add(tunnel);
                    }
                }
            }
            start = next;
        }
    }

    const newValves: Record<string, Valve> = {
        AA: {
            name: 'AA',
            tunnels: Array.from(withRate).filter((x) => x !== 'AA'),
            rate: valves['AA'].rate,
        },
    };

    for (const valve of Array.from(withRate)) {
        newValves[valve] = {
            ...valves[valve],
            tunnels: Array.from(withRate).filter((x) => x !== valve),
        };
    }
    const opened = new Set<string>();
    const currentMax = new Map<string, number>();

    const dp = (
        current: [[string, number], [string, number]],
        opened: Set<string>,
        rate: number,
        left: number
    ): number => {
        const key = `${current.map((x) => x.join('-')).join('|')},${Array.from(opened).sort().join(',')},${left}`;
        if (currentMax.has(key)) {
            return currentMax.get(key)!;
        }
        if (left === 0) {
            return 0;
        }
        if (rate === totalRate) {
            return rate * left;
        }

        let max = 0;
        for (const tunnel1 of newValves[current[0][0]].tunnels) {
            if (current[1][0] !== 0) {
                const time = paths.get([current[0][0], tunnel1].sort().join('|'))! + 1;

                


            }
            else {

                for (const tunnel2 of newValves[current[1][0]].tunnels) {
                    max = Math.max(max, rate + dp([[tunnel1, 0], [tunnel2, 0]], opened, rate, left - 1));
                }

            }
        }



    };

    // console.log(JSON.stringify(Array.from(paths.entries())));

    /* 
    let totalRate = 0;
    for (const input of inputs) {
        const parsed = parse(input);
        valves[parsed.name] = parsed;
        totalRate += parsed.rate;
    }


    // used to reduce the time complexity
    const alreadyMax = [0];
    const currentMax = new Map<string, number>();
    // why the counted doesn't help
    const dp = (
        current: [string, string],
        opened: Set<string>,
        rate: number,
        left: number,
        counted: number
    ): number => {
        const key = `${current.sort().join('|')},${Array.from(opened).sort().join(',')},${left}`;
        if (currentMax.has(key)) {
            return currentMax.get(key)!;
        }

        if (left === 0) {
            return 0;
        }

        if (rate === totalRate) {
            return rate * left;
        }

        let max = 0;

        for (const tunnel1 of valves[current[0]].tunnels) {
            for (const tunnel2 of valves[current[1]].tunnels) {
                max = Math.max(max, rate + dp([tunnel1, tunnel2], opened, rate, left - 1, rate + counted));
            }

            if (opened.has(current[1]) === false) {
                opened.add(current[1]);
                max = Math.max(
                    max,
                    rate + dp([tunnel1, current[1]], opened, rate + valves[current[1]].rate, left - 1, rate + counted)
                );
                opened.delete(current[1]);
            }
        }

        if (current[0] !== current[1]) {
            if (opened.has(current[0]) === false) {
                opened.add(current[0]);
                for (const tunnel2 of valves[current[1]].tunnels) {
                    max = Math.max(
                        max,
                        rate +
                            dp([current[0], tunnel2], opened, rate + valves[current[0]].rate, left - 1, rate + counted)
                    );
                }

                if (opened.has(current[1]) === false) {
                    opened.add(current[1]);
                    max = Math.max(
                        max,
                        rate +
                            dp(
                                current,
                                opened,
                                rate + valves[current[0]].rate + valves[current[1]].rate,
                                left - 1,
                                rate + counted
                            )
                    );
                    opened.delete(current[1]);
                }

                opened.delete(current[0]);
            }
        }
        currentMax.set(key, max);
        if (max > alreadyMax[0]) {
            alreadyMax[0] = max;
        }
        return max;
    };

    const key = `AA|AA,${Array.from(opened).sort().join(',')},26`;
    dp(['AA', 'AA'], opened, 0, 26, 0);
    console.log(currentMax.get(key));
 */
}

function question(file: string): void {
    const inputs = readFileSync(file, 'utf-8')
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length);
    const valves: Record<string, Valve> = {};

    const parse = (line: string): Valve => {
        const divided = line.split(' ');
        const name = divided[1];
        const tunnels = divided.slice(9).map((x) => x.split(',')[0]);
        const rate = Number(divided[4].split('=')[1].split(';')[0]);
        return { name, tunnels, rate };
    };

    let totalRate = 0;

    const opened = new Set<string>();
    for (const input of inputs) {
        const parsed = parse(input);
        valves[parsed.name] = parsed;
        totalRate += parsed.rate;
        if (parsed.rate === 0) {
            opened.add(parsed.name);
        }
    }

    // used to reduce the time complexity
    const alreadyMax = [0];
    const currentMax = new Map<string, number>();
    // why the counted doesn't help
    const dp = (current: string, opened: Set<string>, rate: number, left: number, counted: number): number => {
        const key = `${current},${Array.from(opened).sort().join(',')},${left}`;
        if (currentMax.has(key)) {
            return currentMax.get(key)!;
        }

        if (left === 0) {
            return 0;
        }

        if (rate === totalRate) {
            return rate * left;
        }

        let max = 0;
        for (const tunnel of valves[current].tunnels) {
            max = Math.max(max, rate + dp(tunnel, opened, rate, left - 1, rate + counted));
        }

        if (opened.has(current) === false) {
            opened.add(current);
            max = Math.max(max, rate + dp(current, opened, rate + valves[current].rate, left - 1, rate + counted));
            opened.delete(current);
        }
        currentMax.set(key, max);
        if (max > alreadyMax[0]) {
            alreadyMax[0] = max;
        }
        return max;
    };

    const key = `AA,${Array.from(opened).sort().join(',')},30`;
    dp('AA', opened, 0, 30, 0);
    console.log(currentMax.get(key));
}

question2('temp');
// question2('16.input');
