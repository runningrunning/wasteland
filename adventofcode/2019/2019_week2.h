#if 0

int p1(int a)
{
    int x = a / 3;
    x -= 2;
    return x <= 0 ? 0 : x;
}

void test()
{
    int x = 0;
    int ai = 0;

    char** as = read_input("input_1", &ai);
    int* a = malloc(sizeof(int) * ai);
    long sum = 0;

    int dp = 0;
    long* hash = gen_hash_l(131101, &dp);

    for (int i = 0; i < ai; i ++)
    {
        sscanf(as[i], "%d", &x);

        do {
            x = p1(x);
            sum += x;
        } while(x);
        // sum += p1(x);
        a[i] = x;
    }

    printf("dp is %d.\n", dp);
    printf("sum is %d\n", sum);
    out(a, ai);
}

long test_inner(int o, int p)
{
    int m[] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,13,19,1,9,19,23,1,6,23,27,2,27,9,31,2,6,31,35,1,5,35,39,1,10,39,43,1,43,13,47,1,47,9,51,1,51,9,55,1,55,9,59,2,9,59,63,2,9,63,67,1,5,67,71,2,13,71,75,1,6,75,79,1,10,79,83,2,6,83,87,1,87,5,91,1,91,9,95,1,95,10,99,2,9,99,103,1,5,103,107,1,5,107,111,2,111,10,115,1,6,115,119,2,10,119,123,1,6,123,127,1,127,5,131,2,9,131,135,1,5,135,139,1,139,10,143,1,143,2,147,1,147,5,0,99,2,0,14,0};

    // int m[] = {1, 0, 0, 0, 99};
    // int m[] = {2,3,0,3,99};
    // int m[] = {2,4,4,5,99,0};
    // int m[] = {1,1,1,4,99,5,6,0,99};

    int l = sizeof(m)/sizeof(m[0]);
    int ai = l;
    unsigned long* a = malloc(sizeof(unsigned long) * l);

    for (int i = 0; i < ai; i ++)
        a[i] = m[i];

    a[1] = o;
    a[2] = p;

    long s = 0;
    while(s + 4 <= l)
    {
        if (a[s] == 99)
            break;

        int op = a[s];
        int v1 = a[s + 1];
        int v2 = a[s + 2];
        int v3 = a[s + 3];

        if (v1 > l || v2 > l || v3 > l)
            break;

        if (op == 1)
            a[v3] = a[v1] + a[v2];
        else
            a[v3] = a[v1] * a[v2];
        s += 4;
    }

    /* out(m, l); */
    /* outl(a, l); */
    s = a[0];
    free(a);
    return s;
}

void test()
{
    for (int i = 0; i < 100; i ++)
        for (int j = 0; j < 100; j ++)
        {
            long x = test_inner(i, j);

            if (x == 19690720)
            {
                printf("%d\n", i * 100 + j);
                exit(0);
            }
        }
}

// bottom, left is 0, 0
void read(int* x, int* y, int* l, char* s)
{
    x[0] = 0;
    y[0] = 0;

    int pl = 1;
    int a = 0;

    int cx = 0;
    int cy = 0;

    for (; pl < 2048; pl ++)
    {
        if (!s[a] || s[a] == '\n')
            break;

        char o = s[a ++];
        int n = 0;

        while (s[a] && s[a] <= '9' && s[a] >= '0')
            n = n * 10 + s[a ++] - '0';

        if (o == 'U')
            cy += n;
        else if (o == 'D')
            cy -= n;
        else if (o == 'L')
            cx -= n;
        else if (o == 'R')
            cx += n;
        else
            printf("ERROR here %c.\n", o);

        x[pl] = cx;
        y[pl] = cy;

        if (s[a] != ',')
            break;
        else
            a ++;

        printf("%c %d %d %d\n", o, n, cx, cy);
    }
    *l = pl + 1;
    return;
}


bool pin(int x, int y, int q)
{
    return x < y ? (q >= x && q <= y) : (q >= y && q <= x);
}

int coll(int x1, int y1, int x2, int y2, int* px, int* py, int pl, int steps)
{
    int ox = 0;
    int oy = 0;
    int min = INT_MAX;
    int diff = INT_MAX;

    int cur_steps = 0;

    for (int i = 1; i < pl; i ++)
    {
        diff = INT_MAX;

        int nx = px[i];
        int ny = py[i];

        if (x1 == x2)
        {
            if (ox == nx)
            {
                if (x1 == ox)
                {
                    int dx = ox;
                    int dy;

                    if (pin(oy, ny, y1))
                    {
                        dy = y1;
                        // diff = abs(dx) + abs(y1);
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(oy, ny, y2))
                    {
                        // diff = abs(dx) + abs(y2);
                        dy = y2;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(y1, y2, oy))
                    {
                        // diff = abs(dx) + abs(oy);
                        dy = oy;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(y1, y2, ny))
                    {
                        // diff = abs(dx) + abs(ny);
                        dy = ny;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }
                }
            }
            else if (oy == ny)
            {
                int dx = x1;
                int dy = oy;

                if (pin(y1, y2, dy) && pin(ox, nx, dx)) // be careful
                {
                    // diff = abs(dx) + abs(dy);
                    diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                    if (diff < min && diff)
                        min = diff;
                }

            }
        }
        else
        {
            if (oy == ny)
            {
                if (y1 == oy)
                {
                    int dx;
                    int dy = oy;
                    if (pin(ox, nx, x1))
                    {
                        dx = x1;
                        // diff = abs(x1) + abs(dy);
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(ox, nx, x2))
                    {
                        // diff = abs(x2) + abs(dy);
                        dx = x2;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(x1, x2, ox))
                    {
                        // diff = abs(ox) + abs(dy);
                        dx = ox;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }

                    if (pin(x1, x2, nx))
                    {
                        // diff = abs(nx) + abs(dy);
                        dx = nx;
                        diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                        if (diff < min && diff)
                            min = diff;
                    }
                }
            }
            else if (ox == nx)
            {
                int dx = nx;
                int dy = y1;

                if (pin(oy, ny, dy) && pin(x1, x2, dx)) // be careful
                {
                    // diff = abs(dx) + abs(dy);
                    diff = steps + cur_steps + abs(dx - x1) + abs(dy - y1) + abs(dx - ox) + abs(dy - oy);
                    if (diff < min && diff)
                        min = diff;
                }
            }
        }

        printf("== %d %d %d %d %d.\n", ox, oy, nx, ny, diff);

        cur_steps += abs(ox - nx) + abs(oy - ny);
        ox = nx;
        oy = ny;
    }
    printf("%d %d %d %d, %d\n", x1, y1, x2, y2, min);
    return min;
}

void test()
{
    int x = 0;
    int ai = 0;
    char** as = read_input("input_3", &ai);
    int* px1 = malloc(sizeof(int) * 2048);
    int* py1 = malloc(sizeof(int) * 2048);
    int l1 = 0;
    read(px1, py1, &l1, as[0]);
    printf("l1 is %d.\n", l1);
    out(px1, l1);
    out(py1, l1);

    int* px2 = malloc(sizeof(int) * 2048);
    int* py2 = malloc(sizeof(int) * 2048);
    int l2 = 0;
    read(px2, py2, &l2, as[1]);
    printf("l2 is %d.\n", l2);
    out(px2, l2);
    out(py2, l2);
    int min = INT_MAX;
    int steps = 0;

    for (int i = 1; i < l1; i ++)
    {
        int p1x1 = px1[i - 1];
        int p1y1 = py1[i - 1];
        int p1x2 = px1[i];
        int p1y2 = py1[i];

        int diff = coll(p1x1, p1y1, p1x2, p1y2, px2, py2, l2, steps);
        steps += abs(p1x2 - p1x1) + abs(p1y2 - p1y1);

        if (diff < min && diff)
            min = diff;
    }
    printf("%d.\n", min);
}

bool qualify(int x)
{
    bool has = false;
    int p = 10;

    int s = -1;
    int n = 0;

    while (x)
    {
        int l = x % 10;
        x /= 10;
        if (p == l)
        {
            if (s == p)
                n ++;
            else
            {
                if (n == 2)
                    has = true;

                s = p;
                n = 2;
            }
        }
        else
        {
                if (n == 2)
                    has = true;
            s = -1;
            n = 0;
        }

        if (p < l)
            return false;

        p = l;
    }

    return has || n == 2;
}

int num(int a, int b)
{
    int num = 0;
    for (int i = a; i <= b; i ++)
        if (qualify(i))
            num ++;
    return num;
}

void test()
{
    printf("%d.\n", qualify(111111));
    printf("%d.\n", qualify(223450));
    printf("%d.\n", qualify(123789));
    printf("%d.\n", qualify(112233));
    printf("%d.\n", qualify(123444));
    printf("%d.\n", qualify(111122));
    printf("%d.\n", num(273025, 767253));
}

void test()
{
    int m[] = {3,225,1,225,6,6,1100,1,238,225,104,0,1102,67,92,225,1101,14,84,225,1002,217,69,224,101,-5175,224,224,4,224,102,8,223,223,101,2,224,224,1,224,223,223,1,214,95,224,101,-127,224,224,4,224,102,8,223,223,101,3,224,224,1,223,224,223,1101,8,41,225,2,17,91,224,1001,224,-518,224,4,224,1002,223,8,223,101,2,224,224,1,223,224,223,1101,37,27,225,1101,61,11,225,101,44,66,224,101,-85,224,224,4,224,1002,223,8,223,101,6,224,224,1,224,223,223,1102,7,32,224,101,-224,224,224,4,224,102,8,223,223,1001,224,6,224,1,224,223,223,1001,14,82,224,101,-174,224,224,4,224,102,8,223,223,101,7,224,224,1,223,224,223,102,65,210,224,101,-5525,224,224,4,224,102,8,223,223,101,3,224,224,1,224,223,223,1101,81,9,224,101,-90,224,224,4,224,102,8,223,223,1001,224,3,224,1,224,223,223,1101,71,85,225,1102,61,66,225,1102,75,53,225,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,8,226,226,224,102,2,223,223,1005,224,329,1001,223,1,223,1108,677,677,224,1002,223,2,223,1006,224,344,101,1,223,223,1007,226,677,224,102,2,223,223,1005,224,359,101,1,223,223,1007,677,677,224,1002,223,2,223,1006,224,374,101,1,223,223,1108,677,226,224,1002,223,2,223,1005,224,389,1001,223,1,223,108,226,677,224,102,2,223,223,1006,224,404,101,1,223,223,1108,226,677,224,102,2,223,223,1005,224,419,101,1,223,223,1008,677,677,224,102,2,223,223,1005,224,434,101,1,223,223,7,677,226,224,1002,223,2,223,1005,224,449,101,1,223,223,1008,226,226,224,102,2,223,223,1005,224,464,1001,223,1,223,107,226,677,224,1002,223,2,223,1006,224,479,1001,223,1,223,107,677,677,224,102,2,223,223,1005,224,494,1001,223,1,223,1008,226,677,224,102,2,223,223,1006,224,509,1001,223,1,223,1107,677,226,224,102,2,223,223,1005,224,524,101,1,223,223,1007,226,226,224,1002,223,2,223,1006,224,539,1001,223,1,223,107,226,226,224,102,2,223,223,1006,224,554,101,1,223,223,108,677,677,224,1002,223,2,223,1006,224,569,1001,223,1,223,7,226,677,224,102,2,223,223,1006,224,584,1001,223,1,223,8,677,226,224,102,2,223,223,1005,224,599,101,1,223,223,1107,677,677,224,1002,223,2,223,1005,224,614,101,1,223,223,8,226,677,224,102,2,223,223,1005,224,629,1001,223,1,223,7,226,226,224,1002,223,2,223,1006,224,644,1001,223,1,223,108,226,226,224,1002,223,2,223,1006,224,659,101,1,223,223,1107,226,677,224,1002,223,2,223,1006,224,674,101,1,223,223,4,223,99,226};
    // int m[] = {3,9,8,9,10,9,4,9,99,-1,8};
    // int m[] = {3,9,7,9,10,9,4,9,99,-1,8};
    // int m[] = {3,12,6,12,15,1,13,14,13,4,13,99,-1,0,1,9};
    // int m[] = {3,3,1105,-1,9,1101,0,0,12,4,12,99,1};
    // int m[] = {3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99};
    int e = sizeof(m)/sizeof(m[0]);
    long* a = malloc(sizeof(long) * e);

    for (int i = 0; i < e; i ++)
        a[i] = m[i];

    int s = 0;
    int out = 0;
    bool end = false;

    while (s < e && !end)
    {
        long c = a[s];
        int o = c % 100;
        c /= 100;

        int p1 = c % 10;
        c /= 10;
        int p2 = c % 10;
        c /= 10;
        int p3 = c % 10;
        c /= 10;

        long v1;
        long v2;

        switch(o)
        {
        case 1:
        case 2:
            v1 = p1 ? a[s + 1] : a[a[s + 1]];
            v2 = p2 ? a[s + 2] : a[a[s + 2]];
            a[a[s + 3]] = o == 1 ? (v1 + v2) : (v1 * v2);
            s += 4;
            break;
        case 3:
            a[a[s + 1]] = 5;
            s += 2;
            break;
        case 4:
            out = p1 ? a[s + 1] : a[a[s + 1]];
            s += 2;
            break;
        case 5:
            if (p1 ? a[s + 1] : a[a[s + 1]])
                s = p2 ? a[s + 2] : a[a[s + 2]];
            else
                s += 3;
            break;
        case 6:
            if (p1 ? a[s + 1] : a[a[s + 1]])
                s += 3;
            else
                s = p2 ? a[s + 2] : a[a[s + 2]];
            break;
        case 7:
        case 8:
            v1 = p1 ? a[s + 1] : a[a[s + 1]];
            v2 = p2 ? a[s + 2] : a[a[s + 2]];
            if (o == 7 ? (v1 < v2) : (v1 == v2))
                a[a[s + 3]] = 1;
            else
                a[a[s + 3]] = 0;
            s += 4;
            break;
        case 99:
            s += 1;
            end = true;
            break;
        default:
            printf("error here %d.\n", o);
            exit(0);
            break;
        }

    }

    printf("%d %d %d.\n", s, e, out);
}

int num(char* s, int n)
{
    int x = 0;
    for (int i = n - 1; i >= 0; i --)
    {
        if (s[i] >= '0' && s[i] <= '9')
            x = x * 40 + s[i] - '0' + 26;
        else
            x = x * 40 + s[i] - 'A';
    }
    return x;
}

void get(char* a, int* s, int* e)
{
    int i = 0;
    while (a[i] != ')')
        i ++;
    *s = num(a, i);
    i ++;
    a += i;
    i = 0;
    while (a[i] && a[i] != '\n')
        i ++;
    *e = num(a, i);
}

// stupid, just do graph or map again !!!
void test()
{
    int x = 0;
    int ai = 0;

    char** as = read_input("input_6", &ai);
    int* a = malloc(sizeof(int) * ai);
    long sum = 0;
    int dp = 40 * 40 * 40;

    int* hash = calloc(sizeof(int), dp);
    int* stacks = malloc(sizeof(int) * ai);

    for (int i = 0; i < ai; i ++)
    {
        int s = 0;
        int e = 0;
        get(as[i], &s, &e);
        // printf("%s %d %d.\n", as[i], s, e);
        stacks[i] = s << 16 | e;
    }

    int all = 0;
    int new = true;

    /* q 1
    hash[num("COM", 3)] = 1;
    while (new)
    {
        new = false;
        for (int i = 0; i < ai; i ++)
        {
            int s = (stacks[i] >> 16) & 0xFFFF;
            int e = stacks[i] & 0xFFFF;

            if (hash[s] && !hash[e])
            {
                new = true;
                hash[e] = hash[s] + 1;
                all += hash[s];
            }
        }
    }
    */

    // broad depth searching
    // q 2
    hash[num("YOU", 3)] = 1;
    int ti = 0;
    int ni = 0;
    int* ta = malloc(sizeof(int) * ai);
    int* tb = malloc(sizeof(int) * ai);

    int* tmp = ta;
    int* next = tb;
    tmp[ti ++] = num("YOU", 3);

    int need = num("SAN", 3);

    while (true)
    {
        // getchar();
        for (int t = 0; t < ti; t ++)
        {
            int x = tmp[t];

            for (int i = 0; i < ai; i ++)
            {
                int s = (stacks[i] >> 16) & 0xFFFF;
                int e = stacks[i] & 0xFFFF;

                if ((s == x) && !hash[e])
                {
                    hash[e] = hash[s] + 1;
                    next[ni ++] = e;
                }

                if ((e == x) && !hash[s])
                {
                    hash[s] = hash[e] + 1;
                    next[ni ++] = s;
                }

                if (hash[need])
                {
                    printf("need is %d.\n", hash[need] - 3);
                    exit(0);
                }
            }
        }

        tmp = tmp == ta ? tb : ta;
        next = next == ta ? tb : ta;
        ti = ni;
        ni = 0;

        printf("ti is %d.\n", ti);
    }
    printf("all is %d, need %d.\n", all, hash[num("SAN", 3)] - 3);
}

// 7.2
bool run(int* p, int pl, int input_1, int input_2, int input_num, int* output, long** op, int* line)
{
    long* a;
    int s = *line;
    if (*op)
        a = *op;
    else
    {
        a = malloc(sizeof(long) * pl);
        for (int i = 0; i < pl; i ++)
            a[i] = p[i];
        *op = a;
    }
    int input_used = 0;
    int has_output = false;
    while (s < pl)
    {
        long x = a[s];
        int op = x % 100;
        x /= 100;
        int m1 = x % 10;
        x /= 10;
        int m2 = x % 10;
        x /= 10;
        int m3 = x % 10;
        x /= 10;
        int v1, v2, v3;
        switch(op)
        {
        case 1:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            a[a[s + 3]] = v1 + v2;
            s += 4;
            break;
        case 2:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            a[a[s + 3]] = v1 * v2;
            s += 4;
            break;
        case 3:
            if (input_used >= input_num)
            {
                if (has_output)
                {
                    *line = s;
                    return false;
                }
                printf("ERROR.\n");
            }
            else if (input_used == 0)
                a[a[s + 1]] = input_1;
            else
                a[a[s + 1]] = input_2;
            input_used ++;
            s += 2;
            break;
        case 4:
            *output = m1 ? a[s + 1] : a[a[s + 1]];
            s += 2;
            *line = s;
            has_output = true;
            break;
        case 5:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            if (v1)
                s = v2;
            else
                s += 3;
            break;
        case 6:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            if (v1)
                s += 3;
            else
                s = v2;
            break;
        case 7:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            a[a[s + 3]] = (v1 < v2) ? 1 : 0;
            s += 4;
            break;
        case 8:
            v1 = m1 ? a[s + 1] : a[a[s + 1]];
            v2 = m2 ? a[s + 2] : a[a[s + 2]];
            a[a[s + 3]] = (v1 == v2) ? 1 : 0;
            s += 4;
            break;
        case 99:
            return has_output;
            break;
        }
    }
    return false;
}

int run_once(int* p, int pl, int* s, int n)
{
    int* stacks = calloc(sizeof(int), n);
    long** ps = calloc(sizeof(long*), n);
    bool start = true;
    int output = 0;
    while(true)
    {
        if (start)
        {
            for (int i = 0; i < n; i ++)
            {
                int new_output = 0;
                bool end = run(p, pl, s[i], output, 2, &new_output, &ps[i], &stacks[i]);
                // printf("%d: %d %d %d.\n", i, s[i], output, new_output);
                output = new_output;
                if (end && (i == n - 1))
                {
                    // printf("output ? %d.\n", output);
                    return output;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i ++)
            {
                int new_output = 0;
                bool end = run(p, pl, output, 0, 1, &new_output, &ps[i], &stacks[i]);
                // printf("%d: %d %d.\n", i, output, new_output);
                output = new_output;
                if (end && (i == n - 1))
                {
                    // printf("output is %d.\n");
                    return output;
                }
            }
        }
        // getchar();
        start = false;
    }
    printf("error end.\n");
    return -1;
}

void try(int* s, int x, int y, int* p, int pl, int* max)
{
    if (x == y)
    {
        x = run_once(p, pl, s, y + 1);
        if (x > *max)
            *max = x;
    }
    else
    {
        int t = s[x];
        for (int i = x; i <= y; i ++)
        {
            s[x] = s[i];
            s[i] = t;
            try(s, x + 1, y, p, pl, max);
            s[i] = s[x];
            s[x] = t;
        }
    }
}

void test()
{
    // int m[] = {3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0};
    // int m[] = {3,23,3,24,1002,24,10,24,1002,23,-1,23,101,5,23,23,1,24,23,23,4,23,99,0,0};
    // int m[] = {3,31,3,32,1002,32,10,32,1001,31,-2,31,1007,31,0,33,1002,33,7,33,1,33,31,31,1,32,31,31,4,31,99,0,0,0};
    int m[] = {3,8,1001,8,10,8,105,1,0,0,21,46,55,68,89,110,191,272,353,434,99999,3,9,1002,9,3,9,1001,9,3,9,102,4,9,9,101,4,9,9,1002,9,5,9,4,9,99,3,9,102,3,9,9,4,9,99,3,9,1001,9,5,9,102,4,9,9,4,9,99,3,9,1001,9,5,9,1002,9,2,9,1001,9,5,9,1002,9,3,9,4,9,99,3,9,101,3,9,9,102,3,9,9,101,3,9,9,1002,9,4,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,99,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,99};
    // int m[] = {3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5};
    // int m[] = {3,52,1001,52,-5,52,3,53,1,52,56,54,1007,54,5,55,1005,55,26,1001,54,-5,54,1105,1,12,1,53,54,53,1008,54,0,55,1001,55,1,55,2,53,55,53,4,53,1001,56,-1,56,1005,56,6,99,0,0,0,0,10};

    int l = sizeof(m)/sizeof(m[0]);
    // int s[] = {0, 1, 2, 3, 4};
    int s[] = {5, 6, 7, 8, 9};
    int max = 0;
    try(s, 0, 4, m, l, &max);
    printf("%d.\n", max);
}

void test()
{
#include "input_8.h"
    int l = strlen(m);

    int w = 25;
    int h = 6;

    int s = 0;

    int num0 = 0;
    int num1 = 0;
    int num2 = 0;
    int min0 = INT_MAX;
    int output = 0;

    int xi = 0;
    int* x = calloc(sizeof(int), w * h);

    while (s < l)
    {
        xi = 0;
        for (int i = 0; i < h; i ++)
            for (int j = 0; j < w; j ++)
            {
                switch(m[s ++])
                {
                case '0':
                    if (!x[xi] || x[xi] == '2')
                        x[xi] = '.';
                    num0 ++;
                    break;
                case '1':
                    if (!x[xi] || x[xi] == '2')
                        x[xi] = '*';
                    num1 ++;
                    break;
                case '2':
                    if (!x[xi] || x[xi] == '2')
                        x[xi] = '2';
                    num2 ++;
                    break;
                default:
                    printf("error here.\n");
                    break;
                }

                xi ++;
            }

        if (num0 < min0)
        {
            min0 = num0;
            output = num1 * num2;
        }
        num0 = num1 = num2 = 0;
    }

    xi = 0;
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
            printf("%c", x[xi ++]);
        printf("\n");
    }
    printf("result %d.\n", output);
}

long value(int mode, long value, long base, long* memory)
{
    if (mode == 0)
    {
        if (value > 2048000)
        {
            printf("error\n");
            exit(1);
        }
        // printf("get value from %ld is %ld.\n", value, memory[value]);
        return memory[value];
    }
    if (mode == 1)
        return value;
    if (mode == 2)
    {
        if (value + base > 2048000)
        {
            printf("error\n");
            exit(2);
        }
        // printf("get value + base from %ld is %ld.\n", value + base, memory[value + base]);
        return memory[value + base];
    }
    printf("error here.\n");
}

void assign(int mode, long value, long base, long* memory, long new)
{
    if (mode == 0)
    {
        if (value > 2048000)
        {
            printf("error\n");
            exit(1);
        }
        // printf("set value %ld as %ld.\n", value, new);
        memory[value] = new;
    }
    else if (mode == 2)
    {
        if (value + base > 2048000)
        {
            printf("error\n");
            exit(2);
        }
        // printf("set value + base %ld as %ld.\n", value + base, new);
        memory[value + base] = new;
    }
    else
        printf("ERROR here.\n");
}

void test()
{
    // int m[] = {109,1,204,-1,1001,100,1,100,1008,100,16,101,1006,101,0,99};
    // long m[] = {1102,34915192,34915192,7,4,7,99,0};
    // long m[] = {104,1125899906842624,99};

    long m[] = {1102,34463338,34463338,63,1007,63,34463338,63,1005,63,53,1101,3,0,1000,109,988,209,12,9,1000,209,6,209,3,203,0,1008,1000,1,63,1005,63,65,1008,1000,2,63,1005,63,904,1008,1000,0,63,1005,63,58,4,25,104,0,99,4,0,104,0,99,4,17,104,0,99,0,0,1102,0,1,1020,1102,29,1,1001,1101,0,28,1016,1102,1,31,1011,1102,1,396,1029,1101,26,0,1007,1101,0,641,1026,1101,466,0,1023,1101,30,0,1008,1102,1,22,1003,1101,0,35,1019,1101,0,36,1018,1102,1,37,1012,1102,1,405,1028,1102,638,1,1027,1102,33,1,1000,1102,1,27,1002,1101,21,0,1017,1101,0,20,1015,1101,0,34,1005,1101,0,23,1010,1102,25,1,1013,1101,39,0,1004,1101,32,0,1009,1101,0,38,1006,1101,0,473,1022,1102,1,1,1021,1101,0,607,1024,1102,1,602,1025,1101,24,0,1014,109,22,21108,40,40,-9,1005,1013,199,4,187,1105,1,203,1001,64,1,64,1002,64,2,64,109,-17,2102,1,4,63,1008,63,32,63,1005,63,229,4,209,1001,64,1,64,1105,1,229,1002,64,2,64,109,9,21108,41,44,1,1005,1015,245,1105,1,251,4,235,1001,64,1,64,1002,64,2,64,109,4,1206,3,263,1105,1,269,4,257,1001,64,1,64,1002,64,2,64,109,-8,21102,42,1,5,1008,1015,42,63,1005,63,291,4,275,1105,1,295,1001,64,1,64,1002,64,2,64,109,-13,1208,6,22,63,1005,63,313,4,301,1105,1,317,1001,64,1,64,1002,64,2,64,109,24,21107,43,44,-4,1005,1017,339,4,323,1001,64,1,64,1105,1,339,1002,64,2,64,109,-5,2107,29,-8,63,1005,63,361,4,345,1001,64,1,64,1105,1,361,1002,64,2,64,109,-4,2101,0,-3,63,1008,63,32,63,1005,63,387,4,367,1001,64,1,64,1106,0,387,1002,64,2,64,109,13,2106,0,3,4,393,1001,64,1,64,1105,1,405,1002,64,2,64,109,-27,2102,1,2,63,1008,63,35,63,1005,63,425,1105,1,431,4,411,1001,64,1,64,1002,64,2,64,109,5,1202,2,1,63,1008,63,31,63,1005,63,455,1001,64,1,64,1106,0,457,4,437,1002,64,2,64,109,19,2105,1,1,1001,64,1,64,1105,1,475,4,463,1002,64,2,64,109,-6,21102,44,1,1,1008,1017,45,63,1005,63,499,1001,64,1,64,1105,1,501,4,481,1002,64,2,64,109,6,1205,-2,513,1106,0,519,4,507,1001,64,1,64,1002,64,2,64,109,-17,1207,-1,40,63,1005,63,537,4,525,1106,0,541,1001,64,1,64,1002,64,2,64,109,-8,1201,9,0,63,1008,63,38,63,1005,63,567,4,547,1001,64,1,64,1106,0,567,1002,64,2,64,109,-3,2101,0,6,63,1008,63,32,63,1005,63,591,1001,64,1,64,1105,1,593,4,573,1002,64,2,64,109,22,2105,1,8,4,599,1106,0,611,1001,64,1,64,1002,64,2,64,109,8,1206,-4,625,4,617,1105,1,629,1001,64,1,64,1002,64,2,64,109,3,2106,0,0,1106,0,647,4,635,1001,64,1,64,1002,64,2,64,109,-29,2107,27,9,63,1005,63,667,1001,64,1,64,1106,0,669,4,653,1002,64,2,64,109,7,1207,-4,28,63,1005,63,689,1001,64,1,64,1105,1,691,4,675,1002,64,2,64,109,-7,2108,30,3,63,1005,63,711,1001,64,1,64,1105,1,713,4,697,1002,64,2,64,109,17,21101,45,0,-5,1008,1010,45,63,1005,63,735,4,719,1106,0,739,1001,64,1,64,1002,64,2,64,109,-9,1202,-2,1,63,1008,63,39,63,1005,63,765,4,745,1001,64,1,64,1106,0,765,1002,64,2,64,109,10,21101,46,0,-5,1008,1011,48,63,1005,63,785,1106,0,791,4,771,1001,64,1,64,1002,64,2,64,109,-10,1208,0,36,63,1005,63,811,1001,64,1,64,1105,1,813,4,797,1002,64,2,64,109,7,1205,8,827,4,819,1105,1,831,1001,64,1,64,1002,64,2,64,109,-15,2108,27,4,63,1005,63,853,4,837,1001,64,1,64,1106,0,853,1002,64,2,64,109,14,1201,-3,0,63,1008,63,30,63,1005,63,877,1001,64,1,64,1106,0,879,4,859,1002,64,2,64,109,11,21107,47,46,-5,1005,1018,899,1001,64,1,64,1105,1,901,4,885,4,64,99,21101,0,27,1,21101,0,915,0,1105,1,922,21201,1,31783,1,204,1,99,109,3,1207,-2,3,63,1005,63,964,21201,-2,-1,1,21101,0,942,0,1106,0,922,21201,1,0,-1,21201,-2,-3,1,21101,0,957,0,1105,1,922,22201,1,-1,-2,1106,0,968,22102,1,-2,-2,109,-3,2105,1,0};

    int e = sizeof(m)/sizeof(m[0]);
    long* a =  malloc(sizeof(long) * 2048000);
    for (int i = 0; i < e; i ++)
        a[i] = m[i];
    for (int i = e; i < 2048000; i ++)
        a[i] = 0;
    long* memory = a;

    int s = 0;
    long output = 0;
    bool end = false;

    long base = 0;
    long input = 2;

    while (s < e && !end)
    {
        long oc = a[s];
        long c = a[s];
        int o = c % 100;
        c /= 100;

        int p1 = c % 10;
        c /= 10;
        int p2 = c % 10;
        c /= 10;
        int p3 = c % 10;
        c /= 10;

        long v1 = 0;
        long v2 = 0;

        // printf("==== oc %d p1 %d, p2 %d, p3 %d, o %d, base %d\n", oc, p1, p2, p3, o, base);

        switch(o)
        {
        case 1:
        case 2:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, a[s + 3] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], a[s + 3], o, v1, v2);
            assign(p3, a[s + 3], base, memory, o == 1 ? (v1 + v2) : (v1 * v2));
            s += 4;
            break;
        case 3:
            // printf("a[s + 1] %ld, o %d, input %d ", a[s + 1], o, input);
            assign(p1, a[s + 1], base, memory, input);
            s += 2;
            break;
        case 4:
            output = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, o %d, ouput %ld ", a[s + 1], o, output);
            s += 2;
            printf("=== output %ld.\n", output);
            break;
        case 5:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("v1 %ld s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            else
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            break;
        case 6:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            else
            {
                // printf("v1 %ld %d s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            break;
        case 7:
        case 8:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            assign(p3, a[s + 3], base, memory, (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            // printf("assign %ld.\n", (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            s += 4;
            break;
        case 9:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, o %d, v1 %ld  base from %ld to %ld.\n", a[s + 1], o, v1, base, base + v1);
            base += v1;
            s += 2;
            break;
        case 99:
            s += 1;
            end = true;
            exit(0);
            break;
        default:
            printf("error here %d.\n", o);
            exit(0);
            break;
        }
        // getchar();
    }
    printf("%d %d %d.\n", s, e, out);
}

void add(long x, long y, long* temp, int* num)
{
    long ox = x;
    long oy = y;

    if (x == 0)
        y = y < 0 ? -1 : 1;
    else if (y == 0)
        x = x < 0 ? -1 : 1;
    int ax = abs(x);
    int ay = abs(y);
    long c = gcd(ax, ay);

    x /= c;
    y /= c;

    // long t = (x + 65535) << 32 | y + 65535;
    // be careful here, it MUST be with &0xFFFFFFFF
    long t = (x & 0xFFFFFFFF) << 32 | (y & 0xFFFFFFFF);

    // printf("%ld %ld => %ld.\n", x, y, t);

    for (int i = 0; i < *num; i ++)
    {
        if (temp[i] == t)
        {
            // printf("same as %ld %ld %ld.\n", i, temp[i], t);
            return;
        }
    }

    temp[*num] = t;
    (*num) ++;
    // printf("%ld, %ld num is %d\n", ox, oy, *num);
}

int area(int x, int y)
{
    if (x < 0 && y <= 0)
        return 4;
    if (x <= 0 && y > 0)
        return 3;
    if (x > 0 && y >= 0)
        return 2;
    if (x >= 0 && y < 0)
        return 1;
}
int comp(const void* e1, const void* e2)
{
    long a = *((long*) e1);
    long b = *((long*) e2);
    int x1 = (a >> 32) & 0xFFFFFFFF;
    int y1 = a & 0xFFFFFFFF;
    int x2 = (b >> 32) & 0xFFFFFFFF;
    int y2 = b & 0xFFFFFFFF;

    int a1 = area(x1, y1);
    int a2 = area(x2, y2);

    if (a1 != a2)
        return a1 - a2;

    if (a1 == 1)
    {
        return abs(x1) * abs(y2) < abs(x2) * abs(y1) ? -1 : 1;
    }
    else if (a1 == 2)
    {
        return abs(y1) * abs(x2) < abs(y2) * abs(x1) ? -1 : 1;
    }
    else if (a1 == 3)
    {
        return abs(y1) * abs(x2) < abs(y2) * abs(x1) ? 1 : -1;
    }
    else if (a1 == 4)
    {
        return abs(x1) * abs(y2) < abs(x2) * abs(y1) ? 1 : -1;
    }
}

int num(char** as, int r, int c, int y, int x, long* temp)
{
    int num = 0;
    memset(temp, 0, sizeof(long) * r * c);

    int cur = 0;

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (i == y && j == x)
                continue;

            if (as[i][j] == '#')
            {
                if (i == y)
                    add(j - x, 0, temp, &num);
                else if (j == x)
                    add(0, i - y, temp, &num);
                else
                    add(j - x, i - y, temp, &num);
            }
        }

    return num;
}

void test()
{
    int ai = 0;
    char** as = read_input("input_10", &ai);
    int* a = malloc(sizeof(int) * ai);
    long sum = 0;

    int c = strlen(as[0]);
    int r = ai;
    int max = 0;
    int px = 0;
    int py = 0;

    long* temp = malloc(sizeof(long) * c * r);

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (as[i][j] == '#')
            {
                int cur = num(as, r, c, i, j, temp);
                if (cur > max)
                {
                    max = cur;
                    px = j;
                    py = i;
                }
            }
        }

    int cur = num(as, r, c, py, px, temp);
    qsort(temp, cur, sizeof(long), comp);
    printf("max is %d %d %d %d.\n", max, px, py, cur);

    for (int i = 0; i < cur; i ++)
    {
        long t = temp[i];
        int x1 = (t >> 32) & 0xFFFFFFFF;
        int y1 = t & 0xFFFFFFFF;

        int ty = y1;
        int tx = x1;

        while (as[py + y1][px + x1] != '#')
        {
            x1 += tx;
            y1 += ty;
        }
        printf("%d: %d %d %d %d.\n", i, x1, y1, px + x1, py + y1);
    }
}

// read the question carefully !
void test()
{
    // int m[] = {109,1,204,-1,1001,100,1,100,1008,100,16,101,1006,101,0,99};
    // long m[] = {1102,34915192,34915192,7,4,7,99,0};
    // long m[] = {104,1125899906842624,99};

    // long m[] = {1102,34463338,34463338,63,1007,63,34463338,63,1005,63,53,1101,3,0,1000,109,988,209,12,9,1000,209,6,209,3,203,0,1008,1000,1,63,1005,63,65,1008,1000,2,63,1005,63,904,1008,1000,0,63,1005,63,58,4,25,104,0,99,4,0,104,0,99,4,17,104,0,99,0,0,1102,0,1,1020,1102,29,1,1001,1101,0,28,1016,1102,1,31,1011,1102,1,396,1029,1101,26,0,1007,1101,0,641,1026,1101,466,0,1023,1101,30,0,1008,1102,1,22,1003,1101,0,35,1019,1101,0,36,1018,1102,1,37,1012,1102,1,405,1028,1102,638,1,1027,1102,33,1,1000,1102,1,27,1002,1101,21,0,1017,1101,0,20,1015,1101,0,34,1005,1101,0,23,1010,1102,25,1,1013,1101,39,0,1004,1101,32,0,1009,1101,0,38,1006,1101,0,473,1022,1102,1,1,1021,1101,0,607,1024,1102,1,602,1025,1101,24,0,1014,109,22,21108,40,40,-9,1005,1013,199,4,187,1105,1,203,1001,64,1,64,1002,64,2,64,109,-17,2102,1,4,63,1008,63,32,63,1005,63,229,4,209,1001,64,1,64,1105,1,229,1002,64,2,64,109,9,21108,41,44,1,1005,1015,245,1105,1,251,4,235,1001,64,1,64,1002,64,2,64,109,4,1206,3,263,1105,1,269,4,257,1001,64,1,64,1002,64,2,64,109,-8,21102,42,1,5,1008,1015,42,63,1005,63,291,4,275,1105,1,295,1001,64,1,64,1002,64,2,64,109,-13,1208,6,22,63,1005,63,313,4,301,1105,1,317,1001,64,1,64,1002,64,2,64,109,24,21107,43,44,-4,1005,1017,339,4,323,1001,64,1,64,1105,1,339,1002,64,2,64,109,-5,2107,29,-8,63,1005,63,361,4,345,1001,64,1,64,1105,1,361,1002,64,2,64,109,-4,2101,0,-3,63,1008,63,32,63,1005,63,387,4,367,1001,64,1,64,1106,0,387,1002,64,2,64,109,13,2106,0,3,4,393,1001,64,1,64,1105,1,405,1002,64,2,64,109,-27,2102,1,2,63,1008,63,35,63,1005,63,425,1105,1,431,4,411,1001,64,1,64,1002,64,2,64,109,5,1202,2,1,63,1008,63,31,63,1005,63,455,1001,64,1,64,1106,0,457,4,437,1002,64,2,64,109,19,2105,1,1,1001,64,1,64,1105,1,475,4,463,1002,64,2,64,109,-6,21102,44,1,1,1008,1017,45,63,1005,63,499,1001,64,1,64,1105,1,501,4,481,1002,64,2,64,109,6,1205,-2,513,1106,0,519,4,507,1001,64,1,64,1002,64,2,64,109,-17,1207,-1,40,63,1005,63,537,4,525,1106,0,541,1001,64,1,64,1002,64,2,64,109,-8,1201,9,0,63,1008,63,38,63,1005,63,567,4,547,1001,64,1,64,1106,0,567,1002,64,2,64,109,-3,2101,0,6,63,1008,63,32,63,1005,63,591,1001,64,1,64,1105,1,593,4,573,1002,64,2,64,109,22,2105,1,8,4,599,1106,0,611,1001,64,1,64,1002,64,2,64,109,8,1206,-4,625,4,617,1105,1,629,1001,64,1,64,1002,64,2,64,109,3,2106,0,0,1106,0,647,4,635,1001,64,1,64,1002,64,2,64,109,-29,2107,27,9,63,1005,63,667,1001,64,1,64,1106,0,669,4,653,1002,64,2,64,109,7,1207,-4,28,63,1005,63,689,1001,64,1,64,1105,1,691,4,675,1002,64,2,64,109,-7,2108,30,3,63,1005,63,711,1001,64,1,64,1105,1,713,4,697,1002,64,2,64,109,17,21101,45,0,-5,1008,1010,45,63,1005,63,735,4,719,1106,0,739,1001,64,1,64,1002,64,2,64,109,-9,1202,-2,1,63,1008,63,39,63,1005,63,765,4,745,1001,64,1,64,1106,0,765,1002,64,2,64,109,10,21101,46,0,-5,1008,1011,48,63,1005,63,785,1106,0,791,4,771,1001,64,1,64,1002,64,2,64,109,-10,1208,0,36,63,1005,63,811,1001,64,1,64,1105,1,813,4,797,1002,64,2,64,109,7,1205,8,827,4,819,1105,1,831,1001,64,1,64,1002,64,2,64,109,-15,2108,27,4,63,1005,63,853,4,837,1001,64,1,64,1106,0,853,1002,64,2,64,109,14,1201,-3,0,63,1008,63,30,63,1005,63,877,1001,64,1,64,1106,0,879,4,859,1002,64,2,64,109,11,21107,47,46,-5,1005,1018,899,1001,64,1,64,1105,1,901,4,885,4,64,99,21101,0,27,1,21101,0,915,0,1105,1,922,21201,1,31783,1,204,1,99,109,3,1207,-2,3,63,1005,63,964,21201,-2,-1,1,21101,0,942,0,1106,0,922,21201,1,0,-1,21201,-2,-3,1,21101,0,957,0,1105,1,922,22201,1,-1,-2,1106,0,968,22102,1,-2,-2,109,-3,2105,1,0};

    long m[] = {3,8,1005,8,330,1106,0,11,0,0,0,104,1,104,0,3,8,102,-1,8,10,101,1,10,10,4,10,1008,8,0,10,4,10,102,1,8,29,2,9,4,10,1006,0,10,1,1103,17,10,3,8,102,-1,8,10,101,1,10,10,4,10,108,0,8,10,4,10,101,0,8,61,1006,0,21,1006,0,51,3,8,1002,8,-1,10,101,1,10,10,4,10,108,1,8,10,4,10,1001,8,0,89,1,102,19,10,1,1107,17,10,1006,0,18,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,1001,8,0,123,1,9,2,10,2,1105,10,10,2,103,9,10,2,1105,15,10,3,8,102,-1,8,10,1001,10,1,10,4,10,1008,8,0,10,4,10,102,1,8,161,3,8,102,-1,8,10,101,1,10,10,4,10,108,1,8,10,4,10,101,0,8,182,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,101,0,8,205,2,1102,6,10,1006,0,38,2,1007,20,10,2,1105,17,10,3,8,102,-1,8,10,1001,10,1,10,4,10,108,1,8,10,4,10,1001,8,0,241,3,8,102,-1,8,10,101,1,10,10,4,10,108,1,8,10,4,10,101,0,8,263,1006,0,93,2,5,2,10,2,6,7,10,3,8,102,-1,8,10,101,1,10,10,4,10,108,0,8,10,4,10,1001,8,0,296,1006,0,81,1006,0,68,1006,0,76,2,4,4,10,101,1,9,9,1007,9,1010,10,1005,10,15,99,109,652,104,0,104,1,21102,825594262284,1,1,21102,347,1,0,1105,1,451,21101,0,932855939852,1,21101,358,0,0,1106,0,451,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,21102,1,235152649255,1,21101,405,0,0,1105,1,451,21102,235350879235,1,1,21102,416,1,0,1106,0,451,3,10,104,0,104,0,3,10,104,0,104,0,21102,988757512972,1,1,21101,439,0,0,1106,0,451,21102,1,988669698828,1,21101,0,450,0,1106,0,451,99,109,2,22101,0,-1,1,21102,40,1,2,21102,1,482,3,21102,472,1,0,1106,0,515,109,-2,2105,1,0,0,1,0,0,1,109,2,3,10,204,-1,1001,477,478,493,4,0,1001,477,1,477,108,4,477,10,1006,10,509,1101,0,0,477,109,-2,2106,0,0,0,109,4,1202,-1,1,514,1207,-3,0,10,1006,10,532,21102,1,0,-3,21202,-3,1,1,21202,-2,1,2,21102,1,1,3,21102,1,551,0,1106,0,556,109,-4,2105,1,0,109,5,1207,-3,1,10,1006,10,579,2207,-4,-2,10,1006,10,579,22101,0,-4,-4,1105,1,647,21201,-4,0,1,21201,-3,-1,2,21202,-2,2,3,21102,598,1,0,1105,1,556,21202,1,1,-4,21101,0,1,-1,2207,-4,-2,10,1006,10,617,21102,1,0,-1,22202,-2,-1,-2,2107,0,-3,10,1006,10,639,21202,-1,1,1,21102,1,639,0,105,1,514,21202,-2,-1,-2,22201,-4,-2,-4,109,-5,2105,1,0};


    int e = sizeof(m)/sizeof(m[0]);
    long* a =  malloc(sizeof(long) * 204800);
    for (int i = 0; i < e; i ++)
        a[i] = m[i];
    for (int i = e; i < 204800; i ++)
        a[i] = 0;
    long* memory = a;

    int s = 0;
    bool end = false;

    long base = 0;
    long input = 2;

    int x = 512;
    int y = 512;
    int f = 1024;
    int ps = 0;
    int* area = calloc(sizeof(int), 1024 * 1024);

    int outputs = 0;
    int output_c;
    int output_t;

    while (s < e && !end)
    {
        long oc = a[s];
        long c = a[s];
        int o = c % 100;
        c /= 100;

        int p1 = c % 10;
        c /= 10;
        int p2 = c % 10;
        c /= 10;
        int p3 = c % 10;
        c /= 10;


        long v1 = 0;
        long v2 = 0;

        // printf("==== oc %d p1 %d, p2 %d, p3 %d, o %d, base %d\n", oc, p1, p2, p3, o, base);

        switch(o)
        {
        case 1:
        case 2:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, a[s + 3] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], a[s + 3], o, v1, v2);
            assign(p3, a[s + 3], base, memory, o == 1 ? (v1 + v2) : (v1 * v2));
            s += 4;
            break;
        case 3:
            // printf("a[s + 1] %ld, o %d, input %d ", a[s + 1], o, input);
            input = (area[y * 1024 + x] == 1) ? 0 : 1;
            assign(p1, a[s + 1], base, memory, input);
            s += 2;
            break;
        case 4:
            if (outputs % 2)
                output_t = value(p1, a[s + 1], base, memory);
            else
                output_c = value(p1, a[s + 1], base, memory);

            outputs ++;

            if (!(outputs % 2))
            {
                // do paint and move here
                if (!area[x * 1024 + y])
                    ps ++;

                area[y * 1024 + x] = output_c + 1;

                if (output_t)
                    f += 1;
                else
                    f -= 1;

                switch(f % 4)
                {
                case 0:
                    y += 1;
                    break;
                case 1:
                    x += 1;
                    break;
                case 2:
                    y -= 1;
                    break;
                case 3:
                    x -= 1;
                    break;
                }
            }

            // printf("a[s + 1] %ld, o %d, ouput %ld ", a[s + 1], o, output);
            s += 2;
            // printf("=== output %ld.\n", output);
            break;
        case 5:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("v1 %ld s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            else
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            break;
        case 6:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            else
            {
                // printf("v1 %ld %d s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            break;
        case 7:
        case 8:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            assign(p3, a[s + 3], base, memory, (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            // printf("assign %ld.\n", (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            s += 4;
            break;
        case 9:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, o %d, v1 %ld  base from %ld to %ld.\n", a[s + 1], o, v1, base, base + v1);
            base += v1;
            s += 2;
            break;
        case 99:
            s += 1;
            end = true;
            break;
        default:
            printf("error here %d.\n", o);
            end = true;
            break;
        }
        // getchar();
    }

    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;
    for (int i = 0; i < 1024; i ++)
    {
        for (int j = 0; j < 1024; j ++)
            if (area[i * 1024 + j] == 1)
            {
                if (i < min_x)
                    min_x = i;
                if (j < min_y)
                    min_y = j;
                if (i > max_x)
                    max_x = i;
                if (j > max_y)
                    max_y = j;
            }
    }

    for (int i = 560; i >= 500; i --)
    {
        for (int j = 500; j <= 560; j ++)
            if (area[i * 1024 + j] != 1)
                printf("*");
            else
                printf(".");
        printf("\n");
    }

    printf("%d -> %d, %d -> %d %d.\n", min_x, max_x, min_y, max_y, ps);
}

void out_pv(int* p, int* v)
{
    printf("x %4d, y %4d, z %4d, vx %4d, vy %4d, vz %4d.\n", p[0], p[1], p[2], v[0], v[1], v[2]);
}

int num(int p1, int p2, int p3, int p4)
{
    int o[4];
    o[0] = p1;
    o[1] = p2;
    o[2] = p3;
    o[3] = p4;

    int v[4] = {0};

    int num = 0;
    do {

        num ++;

        if (o[0] != o[1])
        {
            if (o[0] < o[1])
            {
                v[0] ++;
                v[1] --;
            }
            else
            {
                v[0] --;
                v[1] ++;
            }
        }

        if (o[0] != o[2])
        {
            if (o[0] < o[2])
            {
                v[0] ++;
                v[2] --;
            }
            else
            {
                v[0] --;
                v[2] ++;
            }
        }

        if (o[0] != o[3])
        {
            if (o[0] < o[3])
            {
                v[0] ++;
                v[3] --;
            }
            else
            {
                v[0] --;
                v[3] ++;
            }
        }

        if (o[1] != o[2])
        {
            if(o[1] < o[2])
            {
                v[1] ++;
                v[2] --;
            }
            else
            {
                v[1] --;
                v[2] ++;
            }
        }

        if (o[1] != o[3])
        {
            if (o[1] < o[3])
            {
                v[1] ++;
                v[3] --;
            }
            else
            {
                v[1] --;
                v[3] ++;
            }
        }

        if (o[2] != o[3])
        {
            if (o[2] < o[3])
            {
                v[2] ++;
                v[3] --;
            }
            else
            {
                v[2] --;
                v[3] ++;
            }
        }

        o[0] += v[0];
        o[1] += v[1];
        o[2] += v[2];
        o[3] += v[3];

    } while(o[0] != p1 || o[1] != p2 || o[2] != p3 || o[3] != p4 || v[0] != 0 || v[1] != 0 || v[2] != 0 || v[3] != 0);
    return num;
}
void test()
{

    /* int p1[] = {-1, 0, 2}; */
    /* int p2[] = {2, -10, -7}; */
    /* int p3[] = {4, -8, 8}; */
    /* int p4[] = {3, 5, -1}; */

    /* int p1[] = {-8, -10, 0}; */
    /* int p2[] = {5, 5, 10}; */
    /* int p3[] = {2, -7, 3}; */
    /* int p4[] = {9, -8, -3}; */

    int p1[] = {10, 15, 7};
    int p2[] = {15, 10, 0};
    int p3[] = {20, 12, 3};
    int p4[] = {0, -3, 13};

    int c = 3;
    int r = 4;

    long x = 1;

    for (int i = 0; i < c; i ++)
    {
        long y = num(p1[i], p2[i], p3[i], p4[i]);
        long c = gcd(x, y);
        x = x * y / c;
    }

    printf("x is %ld.\n", x);


    /* long num = 4686774924; */

    /* int v1[] = {0, 0, 0}; */
    /* int v2[] = {0, 0, 0}; */
    /* int v3[] = {0, 0, 0}; */
    /* int v4[] = {0, 0, 0}; */

    /* int* ps[] = {p1, p2, p3, p4}; */
    /* int* vs[] = {v1, v2, v3, v4}; */


    /* long step = 0; */

    /* while(step ++ < num) */
    /* { */
    /*     /\* printf("step %d.\n", step - 1); *\/ */
    /*     /\* for (int i = 0; i < r; i ++) *\/ */
    /*     /\*     out_pv(ps[i], vs[i]); *\/ */

    /*     for (int i = 0; i < r; i ++) */
    /*         for (int j = i + 1; j < r; j ++) */
    /*         { */
    /*             for (int k = 0; k < c; k ++) */
    /*             { */
    /*                 if (ps[i][k] != ps[j][k]) */
    /*                 { */
    /*                     vs[i][k] += ps[i][k] < ps[j][k] ? 1 : -1; */
    /*                     vs[j][k] += ps[i][k] < ps[j][k] ? -1 : 1; */
    /*                 } */
    /*             } */
    /*         } */

    /*     for (int i = 0; i < r; i ++) */
    /*         for (int j = 0; j < c; j ++) */
    /*             ps[i][j] += vs[i][j]; */

    /*     // getchar(); */
    /* } */

    /* int en = 0; */
    /* for (int i = 0; i < r; i ++) */
    /*     en += (abs(vs[i][0]) + abs(vs[i][1]) + abs(vs[i][2])) * (abs(ps[i][0]) + abs(ps[i][1]) + abs(ps[i][2])); */

    /* printf("en is %d.\n", en); */
}

// try another ways to do that ~~~ ! intcode with stack an store/restore
void intcode(int* code, int cl, int ml, inputCB input_cb, outputCB output_cb)
{
    long* a =  calloc(sizeof(long), ml);

    for (int i = 0; i < cl; i ++)
        a[i] = code[i];

    long* memory = a;

    int s = 0;
    int e = cl;

    bool end = false;

    long base = 0;

    while (s < e && !end)
    {
        long oc = a[s];
        long c = a[s];

        int o = c % 100;
        c /= 100;

        int p1 = c % 10;
        c /= 10;
        int p2 = c % 10;
        c /= 10;
        int p3 = c % 10;
        c /= 10;


        long v1 = 0;
        long v2 = 0;

        // printf("==== oc %d p1 %d, p2 %d, p3 %d, o %d, base %d\n", oc, p1, p2, p3, o, base);

        switch(o)
        {
        case 1:
        case 2:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, a[s + 3] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], a[s + 3], o, v1, v2);
            assign(p3, a[s + 3], base, memory, o == 1 ? (v1 + v2) : (v1 * v2));
            s += 4;
            break;
        case 3:
            // printf("a[s + 1] %ld, o %d, input %d ", a[s + 1], o, input);
            if (input_cb)
                assign(p1, a[s + 1], base, memory, input_cb());
            s += 2;
            break;
        case 4:
            if (output_cb)
                output_cb(value(p1, a[s + 1], base, memory));
            // printf("a[s + 1] %ld, o %d, ouput %ld ", a[s + 1], o, output);
            s += 2;
            // printf("=== output %ld.\n", output);
            break;
        case 5:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("v1 %ld s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            else
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            break;
        case 6:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            if (v1)
            {
                // printf("s += 3 %ld \n", s + 3);
                s += 3;
            }
            else
            {
                // printf("v1 %ld %d s %d, new_s %d.\n", v1, s, value(p2, a[s + 2], base, memory));
                s = value(p2, a[s + 2], base, memory);
            }
            break;
        case 7:
        case 8:
            v1 = value(p1, a[s + 1], base, memory); //p1 ? a[s + 1] : a[a[s + 1]];
            v2 = value(p2, a[s + 2], base, memory); // p2 ? a[s + 2] : a[a[s + 2]];
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            assign(p3, a[s + 3], base, memory, (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            // printf("a[s + 1] %ld, a[s + 2] %ld, o %d, v1 %ld, v2 %ld ", a[s + 1], a[s + 2], o, v1, v2);
            // printf("assign %ld.\n", (o == 7 ? (v1 < v2) : (v1 == v2)) ? 1 : 0);
            s += 4;
            break;
        case 9:
            v1 = value(p1, a[s + 1], base, memory);
            // printf("a[s + 1] %ld, o %d, v1 %ld  base from %ld to %ld.\n", a[s + 1], o, v1, base, base + v1);
            base += v1;
            s += 2;
            break;
        case 99:
            s += 1;
            end = true;
            break;
        default:
            printf("error here %d.\n", o);
            end = true;
            break;
        }
        // getchar();
    }
}

int num = 0;
int* area = NULL;
int blocks = 0;
int score = 0;
long p[3];

void output(long x)
{
    p[(num % 3)] = x;

    if ((num % 3) == 2)
    {
        if (x == 2)
            blocks ++;

        if (p[0] == -1 && p[1] == 0)
        {
           score = p[2];
           printf("score %d.\n", score);
        }
        if (p[2] == 3)
           printf("pad %ld %ld.\n", p[0], p[1]);
        if (p[2] == 4)
           printf("ball %ld %ld.\n", p[0], p[1]);
        area[p[1] * 100 + p[0]] = p[2];
    }

    num ++;
}

int in = 0;
int inputs[] = {1, 1, -1};
int input_l = 0;

long input()
{
    printf("need input.\n");
    if (in < input_l) return inputs[in ++];
    return 0;
}

void test()
{
    int m[] = {2,380,379,385,1008,2571,639943,381,1005,381,12,99,109,2572,1102,0,1,383,1102,1,0,382,20101,0,382,1,20102,1,383,2,21102,37,1,0,1105,1,578,4,382,4,383,204,1,1001,382,1,382,1007,382,42,381,1005,381,22,1001,383,1,383,1007,383,23,381,1005,381,18,1006,385,69,99,104,-1,104,0,4,386,3,384,1007,384,0,381,1005,381,94,107,0,384,381,1005,381,108,1105,1,161,107,1,392,381,1006,381,161,1102,-1,1,384,1106,0,119,1007,392,40,381,1006,381,161,1101,0,1,384,21002,392,1,1,21102,21,1,2,21101,0,0,3,21102,138,1,0,1105,1,549,1,392,384,392,21002,392,1,1,21102,21,1,2,21101,3,0,3,21101,161,0,0,1105,1,549,1102,1,0,384,20001,388,390,1,20102,1,389,2,21102,180,1,0,1106,0,578,1206,1,213,1208,1,2,381,1006,381,205,20001,388,390,1,21002,389,1,2,21101,205,0,0,1105,1,393,1002,390,-1,390,1102,1,1,384,20101,0,388,1,20001,389,391,2,21101,0,228,0,1105,1,578,1206,1,261,1208,1,2,381,1006,381,253,21002,388,1,1,20001,389,391,2,21101,253,0,0,1105,1,393,1002,391,-1,391,1101,0,1,384,1005,384,161,20001,388,390,1,20001,389,391,2,21101,0,279,0,1106,0,578,1206,1,316,1208,1,2,381,1006,381,304,20001,388,390,1,20001,389,391,2,21102,304,1,0,1106,0,393,1002,390,-1,390,1002,391,-1,391,1101,1,0,384,1005,384,161,20102,1,388,1,20102,1,389,2,21102,1,0,3,21101,338,0,0,1106,0,549,1,388,390,388,1,389,391,389,21002,388,1,1,21001,389,0,2,21101,0,4,3,21101,0,365,0,1105,1,549,1007,389,22,381,1005,381,75,104,-1,104,0,104,0,99,0,1,0,0,0,0,0,0,233,19,18,1,1,21,109,3,21202,-2,1,1,22102,1,-1,2,21101,0,0,3,21101,414,0,0,1106,0,549,21202,-2,1,1,21201,-1,0,2,21101,0,429,0,1106,0,601,2101,0,1,435,1,386,0,386,104,-1,104,0,4,386,1001,387,-1,387,1005,387,451,99,109,-3,2106,0,0,109,8,22202,-7,-6,-3,22201,-3,-5,-3,21202,-4,64,-2,2207,-3,-2,381,1005,381,492,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,481,21202,-4,8,-2,2207,-3,-2,381,1005,381,518,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,507,2207,-3,-4,381,1005,381,540,21202,-4,-1,-1,22201,-3,-1,-3,2207,-3,-4,381,1006,381,529,21201,-3,0,-7,109,-8,2105,1,0,109,4,1202,-2,42,566,201,-3,566,566,101,639,566,566,2101,0,-1,0,204,-3,204,-2,204,-1,109,-4,2105,1,0,109,3,1202,-1,42,593,201,-2,593,593,101,639,593,593,21001,0,0,-2,109,-3,2105,1,0,109,3,22102,23,-2,1,22201,1,-1,1,21102,487,1,2,21101,326,0,3,21102,1,966,4,21101,630,0,0,1106,0,456,21201,1,1605,-2,109,-3,2106,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,2,2,2,0,0,0,2,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,0,0,0,2,2,2,0,1,1,0,2,0,2,0,2,0,0,2,2,0,2,2,2,2,0,0,0,2,0,0,2,2,2,0,2,2,0,2,0,0,0,0,2,0,0,0,0,0,0,1,1,0,0,0,0,2,0,0,0,2,0,0,2,0,0,0,0,2,0,0,0,2,2,0,2,0,2,2,0,2,2,0,2,0,2,2,2,0,0,2,0,1,1,0,0,2,2,2,2,2,2,2,0,0,2,0,2,0,0,0,2,0,2,0,0,2,0,0,0,0,2,0,0,2,2,0,2,0,0,2,2,0,0,1,1,0,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,2,0,0,1,1,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,2,2,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,2,0,2,2,2,0,2,2,0,0,0,0,0,0,2,0,2,0,0,2,2,0,0,0,2,0,2,2,0,2,0,0,0,2,0,1,1,0,0,0,0,2,0,2,2,2,2,2,0,2,0,2,2,0,0,2,2,0,2,2,2,0,2,0,2,2,0,2,2,0,2,2,2,2,2,0,0,1,1,0,0,2,0,0,0,2,0,2,2,2,2,2,0,2,0,0,2,2,0,0,2,0,2,2,0,0,2,0,2,0,2,2,2,0,2,2,2,2,0,1,1,0,2,0,0,0,2,0,0,2,0,0,0,2,0,2,0,2,2,0,0,0,0,2,2,2,2,2,2,0,0,2,2,0,0,2,2,0,2,0,0,1,1,0,2,0,0,0,2,0,0,0,0,2,2,0,0,2,2,2,0,0,0,0,0,2,0,0,0,2,0,2,0,0,2,0,2,2,2,2,0,0,0,1,1,0,0,0,0,0,0,2,2,0,2,0,2,2,0,2,0,2,2,0,2,0,0,0,0,2,0,0,0,2,2,0,2,2,0,0,0,2,2,0,0,1,1,0,0,2,0,2,2,0,2,2,2,0,0,2,2,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,2,0,0,1,1,0,0,2,0,0,2,0,2,0,2,0,0,2,2,2,2,2,0,2,0,0,2,2,0,0,0,2,0,0,0,2,2,0,2,0,0,2,0,0,0,1,1,0,2,2,0,0,2,0,0,0,0,0,0,2,0,2,0,0,2,0,0,0,2,0,2,0,2,2,0,0,2,0,0,0,0,0,2,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,85,93,24,97,81,73,90,65,8,89,80,17,22,56,24,44,93,59,34,85,16,26,8,85,58,86,32,75,36,78,65,80,67,83,36,22,47,30,4,17,49,44,80,79,66,53,32,98,63,63,38,69,39,8,74,77,35,93,58,2,40,74,19,95,85,34,13,26,46,94,7,77,1,80,44,80,57,25,40,36,5,66,24,4,26,69,28,34,96,28,14,47,60,2,76,36,90,20,84,9,72,34,80,30,81,91,19,50,38,65,78,80,91,43,52,59,32,98,13,11,74,84,5,64,4,92,11,51,11,36,12,94,80,7,36,15,19,78,76,81,21,88,8,31,50,23,22,80,54,72,6,6,12,81,79,80,85,33,60,67,53,8,98,35,34,11,10,34,18,42,65,14,30,89,21,85,32,50,73,4,28,81,10,94,65,65,5,14,25,47,62,4,35,62,70,66,71,88,94,83,13,28,92,93,75,86,4,7,94,15,43,74,47,3,46,82,71,56,37,95,45,29,90,48,51,19,16,65,10,7,81,98,13,96,49,90,64,94,14,68,73,35,19,34,75,37,7,5,87,44,71,52,12,27,92,27,81,63,95,38,49,61,7,92,65,37,47,63,13,2,62,70,65,24,17,59,31,7,1,15,9,48,52,74,38,27,8,53,80,66,6,72,35,39,79,11,89,80,90,53,84,7,84,64,75,15,40,48,82,30,28,98,23,90,88,92,5,34,7,23,41,87,93,65,46,90,29,24,38,56,15,62,6,89,68,81,93,43,31,60,51,45,25,15,88,25,11,88,93,60,87,4,3,93,8,50,62,27,54,7,6,18,44,65,33,69,23,45,44,69,49,11,73,81,64,18,6,74,7,77,53,18,6,98,62,35,81,48,33,64,26,16,55,17,71,75,72,39,6,54,67,97,68,59,65,3,70,75,91,98,87,41,94,16,1,14,27,11,19,52,53,18,47,27,29,59,6,37,86,71,12,62,84,26,36,22,74,95,77,59,66,70,95,91,2,59,39,50,81,51,75,87,30,22,30,64,54,53,64,33,37,88,24,90,24,32,36,95,39,54,6,85,10,15,53,82,13,41,50,10,67,87,51,87,15,80,27,10,32,97,77,90,41,34,45,14,11,95,79,58,31,49,59,86,50,89,22,92,68,51,74,28,38,16,68,29,6,23,37,19,55,71,5,73,38,66,12,21,45,51,69,89,51,2,9,61,62,97,92,74,23,8,23,82,56,74,9,9,73,69,3,25,81,18,67,64,5,86,96,49,22,86,93,36,15,28,31,55,62,81,78,66,65,55,68,71,92,66,65,48,64,75,16,42,26,12,49,27,33,40,66,43,37,51,90,32,96,63,96,42,61,70,97,96,79,67,59,12,17,81,12,39,64,80,1,28,2,83,35,20,54,69,97,11,96,96,22,60,92,79,28,35,32,24,19,96,85,26,20,38,72,60,41,62,14,51,54,60,45,35,37,17,85,53,27,1,87,55,25,48,46,10,70,16,13,16,77,10,73,70,65,58,57,62,16,59,51,70,93,55,42,79,46,12,88,28,96,53,82,61,75,67,58,13,42,11,64,3,76,15,60,40,6,57,71,68,26,48,57,80,61,28,88,44,92,49,49,38,46,37,40,34,1,18,97,72,49,53,49,35,88,44,5,29,81,6,21,87,77,25,36,91,33,22,74,22,85,55,39,98,21,6,43,26,2,60,36,34,72,39,25,40,51,37,65,69,48,4,18,42,49,13,52,80,39,65,94,92,27,34,58,83,93,5,34,2,11,90,37,73,77,84,68,63,78,63,34,32,47,26,90,72,61,89,5,78,26,80,92,29,36,76,48,53,61,53,14,42,1,2,34,37,36,16,70,27,1,50,26,29,92,53,58,19,90,47,27,35,30,72,76,54,85,33,26,65,77,39,7,3,8,67,87,25,12,43,74,95,97,12,23,47,62,70,62,22,98,76,17,14,77,50,91,20,15,42,34,20,65,79,87,27,44,12,95,2,97,97,43,62,76,65,48,71,83,72,33,44,17,65,40,86,12,89,97,54,36,62,78,65,15,7,37,25,31,3,16,33,91,56,67,66,29,61,40,91,32,27,13,8,55,89,54,69,76,16,67,66,54,7,75,84,6,64,15,29,56,88,57,49,26,57,70,19,3,62,79,61,62,55,49,16,94,94,53,79,639943};

    int l = LENGTH(m);
    area = calloc(sizeof(int), 100 * 100);
    intcode(m, l, INTCODE_MEMORY, input, output);

    int bleft = 0;
    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 100; j ++)
        {
            int x = area[i * 100 + j];
            if (x)
            {
                if (x == 1) printf("|");
                if (x == 2) { printf("*"), bleft ++;}
                if (x == 3) printf("_");
                if (x == 4) printf("X");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("l %d %d left %d score %d.\n", l, blocks, bleft, score);
}
#endif
