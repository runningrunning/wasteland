#include "../common.h"
// Using other language
// FIND THE BETTER SOLUTION !
// PRACTISE MORE

void out_input(char** as, int ai)
{
    for (int i = 0; i < ai; i ++)
        printf("%s", as[i]);
}

char** read_input(char* file, int* s)
{
    FILE* fin;
    fin = fopen(file, "rb");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int ai = 0;
    int as = 1024;
    char** a = malloc(sizeof(char*) * as);

    while (read = getline(&line, &len, fin) != -1)
    {
        if (ai == as)
        {
            as += 1024;
            a = realloc(a, sizeof(char*) * as);
        }
        a[ai ++] = strdup(line);
    }

    free(line);
    fclose(fin);

    *s = ai;
    return a;
}

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
#endif

int main(int argn, char** argv)
{
    srand(time(NULL));
    test();
}
