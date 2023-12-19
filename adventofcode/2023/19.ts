import { readFileSync } from 'fs';

type WorkFlow = {
    name: string;
    method: (input: string) => string;
    branches: Array<[string, string, number]>;
};

function parse(line: string): WorkFlow {
    const [name, condition] = line.slice(0, -1).split('{');
    const cs = condition
        .split(',')
        .map((x) => x.trim())
        .filter((x) => x.length);
    let check = '';
    const branches: Array<[string, string, number]> = [];
    for (const c of cs) {
        if (c.includes(':')) {
            const s = c.split(':').map((x) => x.trim());
            branches.push([s[0][0], s[0][1], Number(s[0].slice(2))]);
            check += `if(${s[0]}) return "${s[1]}";`;
        } else {
            check += `return "${c}";`;
        }
    }
    const method = (init: string): string => {
        return eval(`((${init}) => {
            ${check}
            return "A";
        })()`) as string;
    };
    return { name, method, branches };
}

function question(file: string): void {
    const [workflow, inits] = readFileSync(file, 'utf-8').split('\n\n');
    const all: Record<string, WorkFlow> = {};
    workflow
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .forEach((line) => {
            const parsed = parse(line);
            all[parsed.name] = parsed;
        });

    const result: Array<string> = [];
    inits
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .forEach((line) => {
            const input = line.slice(1, -1);
            let check = 'in';
            while (check !== 'A' && check !== 'R') {
                check = all[check].method(input);
            }

            if (check === 'A') {
                result.push(input);
            }
        });

    console.log(
        result
            .join(',')
            .split(',')
            .map((x) => x.split('=')[1])
            .map(Number)
            .reduce((a, b) => a + b)
    );
}

function clone(a: Record<string, [number, number]>): Record<string, [number, number]> {
    return JSON.parse(JSON.stringify(a));
}

function question2(file: string): void {
    const [workflow] = readFileSync(file, 'utf-8').split('\n\n');
    const all: Record<string, WorkFlow> = {};
    workflow
        .split('\n')
        .map((x) => x.trim())
        .filter((x) => x.length)
        .forEach((line) => {
            const parsed = parse(line);
            all[parsed.name] = parsed;
        });

    const result: Array<Record<string, [number, number]>> = [];

    const check = (init: Record<string, [number, number]>, workflow: string): void => {
        if (workflow === 'A' || workflow === 'R') {
            if (workflow === 'A') {
                result.push(init);
            }
            return;
        }

        let inputs: Array<Record<string, [number, number]>> = [init];
        const next = all[workflow];

        for (const [key, condition, value] of next.branches) {
            let nextInputs: Array<Record<string, [number, number]>> = [];
            for (const input of inputs) {
                if (condition === '>') {
                    if (input[key][0] <= value && input[key][1] > value) {
                        const c1 = clone(input);
                        c1[key][1] = value;
                        const c2 = clone(input);
                        c2[key][0] = value + 1;
                        nextInputs.push(c1, c2);
                    } else {
                        nextInputs.push(input);
                    }
                } else {
                    if (input[key][0] < value && input[key][1] >= value) {
                        const c1 = clone(input);
                        c1[key][1] = value - 1;
                        const c2 = clone(input);
                        c2[key][0] = value;
                        nextInputs.push(c1, c2);
                    } else {
                        nextInputs.push(input);
                    }
                }
            }
            inputs = nextInputs;
        }

        for (const input of inputs) {
            check(
                input,
                next.method(
                    Object.entries(input)
                        .map(([name, value]) => `${name}=${value[0]}`)
                        .join(',')
                )
            );
        }
    };

    check(
        {
            x: [1, 4000],
            m: [1, 4000],
            a: [1, 4000],
            s: [1, 4000],
        },
        'in'
    );

    console.log(result.reduce((p, c) => p + Object.values(c).reduce((p, c) => p * (c[1] - c[0] + 1), 1), 0));
}

question('temp');
question('19.input');
question2('temp');
question2('19.input');
