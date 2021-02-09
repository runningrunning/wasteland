// TODO try to learn how to do the modulo inverse
array(int) parser(string s, int l, int st, int step)
{
    foreach (s / "\n", string line) {
        if (line == "deal into new stack") {
            step = -step;
            st += step;
        }
        else if (has_prefix(line, "cut")) {
            int number = 0;
            sscanf(line, "cut %d", number);
            st += number * step;
        } else if (has_prefix(line, "deal with increment")) {
            int number = 0;
            sscanf(line, "deal with increment %d", number);
            step *= offset(number, l);
        }

        st %= l;
        step %= l;
    }

    return ({st, step});
}

array(int) q1(string s, int l)
{
    int st = 0;
    int step = 1;

    array(int) r = ({0}) * l;
    for (int i = 0; i < l; i ++) {
        int x = i;
        foreach (s / "\n", string line) {
            if (line == "deal into new stack") {
                x = l - 1 - x;
            }
            else if (has_prefix(line, "cut")) {
                int number = 0;
                sscanf(line, "cut %d", number);
                if (number < 0)
                    number += l;

                if (x < number) {
                    x += l - number;
                } else {
                    x -= number;
                }
            } else if (has_prefix(line, "deal with increment")) {
                int number = 0;
                sscanf(line, "deal with increment %d", number);
                x = (x * number) % l;
            }
        }
        r[x] = i;
    }
    return r;
}

array(int) t2(string s, int l)
{
    int st = 0;
    int step = 1;

    array(int) p = parser(s, l, st, step);
    st = p[0];
    step = p[1];

    array(int) r = ({0}) * l;
    for (int i = 0; i < l; i ++) {
        r[i] = (st + l) % l;
        st = (st + step) % l;
    }
    return r;
}

array(array(int)) level(int st, int step, int l, int lv)
{
    array(array(int)) cache = ({});
    int c = 1;
    while (c < lv) {
        cache += ({({st, step})});
        st = (st + (st * step)) % l;
        step = (step * step) % l;
        c *= 2;
    }
    return cache;
}

array(int) apply(array(array(int)) level, int l, int need) {

    int st = 0;
    int step = 1;
    int i = 0;

    while (need) {
        if (need & 1) {
            st = (st + level[i][0] * step) % l;
            step = (step * level[i][1]) % l;
        }
        need >>= 1;
        i ++;
    }
    return ({st, step});
}

int q2(string s, int l)
{
    int st = 0;
    int step = 1;

    array(int) p = parser(s, l, st, step);
    st = p[0];
    step = p[1];

    array(array(int)) le = level(st, step, l, 101741582076661);

    array(int) t = apply(le, l, 101741582076661);

    werror("%O.\n", t);

    st = t[0];
    step = t[1];

    for (int i = 0; i <= 2020; i ++)
    {
        if (i == 2020)
            werror("%d\n", st);
        st = (st + step) % l;
    }

    /* int ost = st; */
    /* int ostep = step; */

    /* for (int i = 0; i < 2047; i ++) { */
    /*     st = (st + ost * step) % l; */
    /*     step = (step * ostep) % l; */
    /*     array(int) t = apply(le, l, i + 2); */

    /*     if (st != t[0] || step != t[1]) */
    /*         werror("Faild here, should be %d %d but %O.\n", st, step, t); */
    /*     /\* else *\/ */
    /*     /\*      werror("%d: %d %d same", i, st, step); *\/ */
    /* } */

}



int offset(int align, int l) {
    int x = l;
    while ((x + 1)%align)
        x += l;
    return (x + 1) / align;
}

int test(string s) {
    foreach (({10007, 41077, 80701, 79907}), int len) {
        array(int) x = q1(s, len);
        array(int) y = t2(s, len);

        if (!equal(x, y)) {
            werror("x and y is not same. %O %O\n", x, y);
        } else {
            werror("they are same.\n");
        }
    }
}


int main(int argc, array(string) args)
{
    string shuffing = Stdio.read_file(args[1]);
    /* array(int) t = q1(shuffing, 10007); */
    /* for (int i = 0; i < 2500; i ++ ){ */
    /*     werror("%d:%d ", i, t[i]); */
    /* } */
    // q2(shuffing, 119315717514047);
    // test(shuffing);
    // q2(shuffing, 10007);
    q2(shuffing, 119315717514047);
}
