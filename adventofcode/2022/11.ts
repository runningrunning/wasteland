import { readFileSync } from 'fs';

type Monkey = {
    id: number;
    items: number[];
    operations: (o: number) => number;
    test: (o: number) => number;
    counts: number;
};

function question(file: string, count = 20, reduce = 3): void {
    const inputs = readFileSync(file, 'utf-8').split('\n\n');
    const Monkeys: Monkey[] = [];
    let lcm = 1;
    for (const input of inputs) {
        const describes = input
            .split('\n')
            .map((x) => x.trim())
            .filter((x) => x.length);
        const divided = Number(describes[3].split(' ').slice(-1)[0]);
        lcm *= divided;
    }

    for (const input of inputs) {
        const describes = input
            .split('\n')
            .map((x) => x.trim())
            .filter((x) => x.length);
        const monkeyID = Number(describes[0].split(':')[0].split(' ')[1]);
        const items = describes[1]
            .split(':')[1]
            .split(',')
            .map((x) => Number(x.trim()));

        const operationsFunction = `(old) => Math.floor(((${
            describes[2].split(':')[1].split('=')[1]
        }) / ${reduce}) % ${lcm})`;
        const divided = Number(describes[3].split(' ').slice(-1)[0]);
        const testCondition = `(o) => (o % ${divided}) === 0`;
        const condition1 = describes[4].split(':');
        const condition2 = describes[5].split(':');
        const test1 = [condition1[0].split(' ').slice(-1)[0], condition1[1].split(' ').slice(-1)[0]];
        const test2 = [condition2[0].split(' ').slice(-1)[0], condition2[1].split(' ').slice(-1)[0]];
        const testFunction = `(o) => {const check = (${testCondition})(o);
        if (check === ${test1[0]}) return ${test1[1]};
        if (check === ${test2[0]}) return ${test2[1]};
        return ${test2[1]};}`;

        Monkeys[monkeyID] = {
            id: monkeyID,
            items,
            operations: eval(operationsFunction) as (o: number) => number,
            test: eval(testFunction) as (o: number) => number,
            counts: 0,
        };
    }

    while (count--) {
        for (const monkey of Monkeys) {
            for (let item of monkey.items) {
                item = monkey.operations(item);
                const to = monkey.test(item);
                Monkeys[to].items.push(item);
            }
            monkey.counts += monkey.items.length;
            monkey.items = [];
        }
    }
    console.log(
        Monkeys.map((x) => x.counts)
            .sort((a, b) => a - b)
            .slice(-2)
            .reduce((a, b) => a * b)
    );
}

question('temp', 20);
question('temp', 10000, 1);

question('11.input', 20);
question('11.input', 10000, 1);
