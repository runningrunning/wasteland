import { readFileSync } from 'fs';

function question(file: string) {
    const [step, maps] = readFileSync(file, 'utf-8').split('\n\n');
    const rl = step.trim();

    const map: Record<string, [string, string]> = {};

    for (const i of maps.split('\n')) {
        if (i.length === 0) {
            continue;
        }
        // AAA = (BBB, CCC)
        map[i.slice(0, 3)] = [i.slice(7, 10), i.slice(12, 15)];
    }

    let count = 0;
    let cur = 'AAA';
    do {
        cur = map[cur][rl[count++ % rl.length] === 'L' ? 0 : 1];
    } while (cur !== 'ZZZ');
    console.log('step', count);
}

function question2(file: string) {
    const [step, maps] = readFileSync(file, 'utf-8').split('\n\n');
    const rl = step.trim();

    const map: Record<string, [string, string]> = {};

    for (const i of maps.split('\n')) {
        if (i.length === 0) {
            continue;
        }
        // AAA = (BBB, CCC)
        map[i.slice(0, 3)] = [i.slice(7, 10), i.slice(12, 15)];
    }

    let curs = Object.keys(map).filter((name) => name[2] === 'A');
    let allRepeats: Array<{ start: number; repeat: number; ends: Array<number> }> = [];

    // find each repeats
    for (let cur of curs) {
        let count = 0;
        let repeat = 0;
        const footPrints: Record<string, number> = {};
        do {
            const rli = count % rl.length;
            const rln = rl[rli] === 'L' ? 0 : 1;
            const curFootPrint = `${cur}-${rli}`;
            if (footPrints[curFootPrint] !== undefined) {
                repeat = count - footPrints[curFootPrint];
                break;
            }
            footPrints[curFootPrint] = count++;
            cur = map[cur][rln];
        } while (true);

        const start = count - repeat;
        const nextEnds: Array<number> = [];
        for (let i = 0; i < repeat; i++) {
            if (cur[2] === 'Z') {
                nextEnds.push(i);
            }
            cur = map[cur][rl[count++ % rl.length] === 'L' ? 0 : 1];
        }
        allRepeats.push({ start, repeat, ends: nextEnds });
    }

    // method 1
    const gcd = (a: number, b: number): number => (a % b === 0 ? b : gcd(b, a % b));
    // find the repeat steps;
    const commonLCM = allRepeats.reduce((pre, cur) => (pre * cur.repeat) / gcd(pre, cur.repeat), allRepeats[0].repeat);
    // The result is happened to be the commonLCM.
    console.log('commonLCM', JSON.stringify(allRepeats), commonLCM);
    // return;

    // method 2
    const checking = (cur: { start: number; repeat: number; end: number }, steps: number) => {
        if (steps < cur.start) {
            return false;
        }
        return (steps - cur.start) % cur.repeat === cur.end;
    };

    let current: { start: number; repeat: number; ends: Array<number> } | undefined;
    for (const repeat of allRepeats) {
        if (current === undefined) {
            current = repeat;
        } else {
            const curRepat = current.repeat;
            const commonLCM = (curRepat * repeat.repeat) / gcd(curRepat, repeat.repeat);
            const newEnds: Array<number> = [];
            for (let curEnd of current.ends) {
                for (const repeatEnd of repeat.ends) {
                    let steps = curEnd + current.start;
                    let found = true;
                    while (!checking({ start: repeat.start, repeat: repeat.repeat, end: repeatEnd }, steps)) {
                        steps += curRepat;
                        if (steps > curEnd + current.start + commonLCM) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        newEnds.push(steps);
                    }
                }
            }
            current = { start: 0, repeat: commonLCM, ends: newEnds };
        }
    }
    if (current !== undefined) {
        console.log('min steps', Math.min(...current?.ends.map((end) => end + (current?.start ?? 0))));
    }
}

question('8.input');
question2('temp');
question2('8.input');
