#include "../common.h"
// Using other language
// FIND THE BETTER SOLUTION !
// PRACTISE MORE

// DAY 20 DO IT AGAIN !!!
// DAY 23 DO IT AGAIN !!! 3D
// Just be careful !!!!!!
// TRY TO REMEMBER qsort the 3rd one is the sizeof

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
        sum += x;
        a[i] = x;
    }

    printf("dp is %d.\n", dp);

    sum = 0;
    bool got = false;

    long has = 0;

    while(!got)
    {
        int i = 0;
        do {
            long k = abs(sum) % dp;
            long s = (sum >= 0) ? sum + 1 : sum;

            if (has >= dp)
            {
                printf("got has %ld, but not found.\n", has);
                break;
            }

            while (hash[k] && hash[k] != s)
            {
                // printf("try k %d.\n", k);
                k = (k + 1) % dp;
            }

            if (hash[k] == s)
            {
                got = true;
                printf("break here.\n");
                break;
            }
            has ++;
            hash[k] = s;
            // printf("i is %d sum is %ld.\n", i, sum);
            sum += a[i ++];
        } while (i < ai);
    }

    printf("sum is %ld ai is %d.\n", sum, ai);
}

void test()
{
    FILE* fin;
    fin = fopen("input_2", "rb");

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int t3 = 0;
    int t2 = 0;

    int ai = 0;
    char* a[256] = {0};

    // here len is the reading len !!!
    while (read = getline(&line, &len, fin) != -1)
    {
        a[ai ++] = strdup(line);
        int t[26] = {0};
        for (int i = 0; i < len; i ++)
            t[line[i] - 'a'] ++;

        bool has_2 = 0;
        bool has_3 = 0;

        for (int i = 0; i < 26; i ++)
        {
            has_2 = has_2 || t[i] == 2;
            has_3 = has_3 || t[i] == 3;
        }

        if (has_2)
            t2 ++;
        if (has_3)
            t3 ++;
    }

    free(line);
    fclose(fin);

    len = strlen(a[0]);

    bool got = false;
    for (int i = 0; i < ai; i ++)
    {
        for (int j = i + 1; j < ai; j ++)
        {
            int d = 0;
            // printf("%s %s %d len %d.\n", a[i], a[j], d, len);

            for (int k = 0; k < len; k ++)
            {
                // printf("d %d %c %c.\n", d, a[i][k], a[j][k]);
                d += (a[i][k] != a[j][k]) ? 1 : 0;
            }

            // printf("%s\n%s", a[i], a[j]);
            if (d == 1)
            {
                printf("%s and  %s.\n", a[i], a[j]);
                got = true;
                break;
            }
        }
        if (got)
            break;
    }

    printf("check sum %d.\n", t2 * t3);
}

void test()
{
    FILE* fin;
    fin = fopen("input_3", "rb");

    int ai = 0;
    int* a = malloc(sizeof(int) * 4 * 1536);

    int t, x, y, r, c;

    char* bits = calloc(sizeof(char), 1024 * 1024);

    int num = 0;

    // why, need \n this time
    while (fscanf(fin, "#%d @ %d,%d: %dx%d\n", &t, &x, &y, &r, &c) == 5)
    {
        a[ai ++] = x;
        a[ai ++] = y;
        a[ai ++] = r;
        a[ai ++] = c;
        for (int i = x; i < x + r; i ++)
            for (int j = y; j < y + c; j ++)
            {
                if (!bits[i * 1024 + j])
                    bits[i * 1024 + j] = 1;
                else if (bits[i * 1024 + j] == 1)
                {
                    num ++;
                    bits[i * 1024 + j] = -1;
                }
            }
    }

    char* ts = calloc(sizeof(char), 1024);

    for (int i = 0; i < ai; i += 4)
    {
        if (ts[i / 4])
            continue;

        int xi = a[i];
        int yi = a[i + 1];
        int xi_e = xi + a[i + 2] - 1;
        int yi_e = yi + a[i + 3] - 1;

        // from the beginning
        for (int j = 0; j < ai; j += 4)
        {
            if (j == i)
                continue;

            int xj = a[j];
            int yj = a[j + 1];
            int xj_e = xj + a[j + 2] - 1;
            int yj_e = yj + a[j + 3] - 1;

            if (!(xj > xi_e || xi > xj_e || yj > yi_e || yi > yj_e))
            {
                ts[i/4] = ts[j/4] = 1;
                break;
            }
        }

        if (!ts[i / 4])
            printf("i is %d.\n", i / 4 + 1); // add 1 as extra
    }
}

int test_4_cmp(const void* e1, const void* e2)
{
    return strcmp(*((const char**)e1), *((const char**)e2));
}

void test()
{
    int ai = 0;
    char** as = read_input("input_4", &ai);
    qsort(as, ai, sizeof(char**), test_4_cmp);

    int all = 0;
    int* ids = malloc(sizeof(int) * ai);
    int* nums = malloc(sizeof(int) * ai);

    for (int i = 0; i < ai;)
    {
        int id = 0;

        while(as[i][19] != 'G')
        {
            i ++;
            printf("error here.\n");
        }

        sscanf(as[i ++], "%*s %*s Guard #%d %*s", &id);

        int in = 0;
        for (; in < all; in ++)
            if (ids[in] == id)
                break;

        if (in == all)
        {
            ids[in] = id;
            nums[in] = 0;
            all ++;
        }

        int total = 0;
        int fall_sleep = 0;
        int last_wake = true;

        while (i < ai && as[i][19] != 'G')
        {
            int c = as[i][19];
            int t = (as[i][15] - '0') * 10 + as[i][16] - '0';
            if (as[i][19] == 'f')
                fall_sleep = t;
            else if (!last_wake)
                total +=  t - fall_sleep;
            last_wake = c == 'w';
            i ++;
        }

        if (!last_wake)
            total += 60 - fall_sleep;

        nums[in] += total;
    }

    int max_i = 0;
    int max_num = INT_MIN;

    for (int i = 0; i < all; i ++)
        if (max_num < nums[i])
        {
            max_i = i;
            max_num = nums[i];
        }

    int most_i = 0;
    int most_t = INT_MIN;
    int most_n = INT_MIN;

    // printf("max_id is %d max_t is %d, result is %d \n", ids[max_i], max_t, max_t * ids[max_i]);
    for (int j = 0; j < all; j ++)
    {
        int times[60] = {0};
        for (int i = 0; i < ai;)
        {
            int id = 0;
            sscanf(as[i ++], "%*s %*s Guard #%d %*s", &id);

            if (id != ids[j])
                continue;

            int fall_sleep = 0;
            int last_wake = true;

            while (i < ai && as[i][19] != 'G')
            {
                int c = as[i][19];
                int t = (as[i][15] - '0') * 10 + as[i][16] - '0';
                if (as[i][19] == 'f')
                    fall_sleep = t;
                else if (!last_wake)
                    for (int k = fall_sleep; k < t; k ++)
                    {
                        times[k] ++;
                        if (times[k] > most_n)
                        {
                            most_n = times[k];
                            most_i = ids[j];
                            most_t = k;
                        }
                    }
                last_wake = c == 'w';
                i ++;
            }
        }
    }
    printf("%d %d %d %d.\n", most_i, most_t, most_n, most_i * most_t);
}

void test()
{
    int l = 50000;
    int ai = 0;
    char** as = read_input("input_5",&ai);
    char* t = as[0];

    char* s = NULL;

    int less = l;
    int less_c = 0;

    for (int x = 0; x < 26; x ++)
    {
        s = strdup(t);

        for (int j = 0; j < l; j ++)
            if (s[j] == 'a' + x || s[j] == 'A' + x)
                s[j] = 0;

        bool found = true;
        while (found)
        {
            found = false;
            for (int i = 0; i < l; i ++)
            {
                if (!s[i])
                    continue;

                char c = s[i];

                int j = i + 1;

                for (; j < l; j ++)
                    if (s[j])
                        break;

                if (j == l)
                    break;

                if (s[j] - s[i] == 32 || s[i] - s[j] == 32)
                {
                    s[i] = 0;
                    s[j] = 0;
                    found = true;
                    break;
                }
            }
        }

        int c = 0;
        for (int i = 0; i < l; i ++)
            if (s[i])
                c ++;

        if (c < less)
        {
            less_c = 'a' + x;
            less = c;
        }

        free(s);
    }

    printf("c is %c %d.\n", less_c, less);
}

int comp_6(const void* e1, const void* e2)
{
    return *((int*) e1) - *((int*) e2);
}

void test()
{
    int ai = 0;
    char** as = read_input("input_6", &ai);

    int pi = 0;
    int* ps = malloc(sizeof(int) * ai * 2);

    int max_x = INT_MIN;
    int max_y = INT_MIN;

    for (int i = 0; i < ai; i ++)
    {
        sscanf(as[i], "%d, %d", &ps[pi], &ps[pi + 1]);

        if (ps[pi] > max_x)
            max_x = ps[pi];

        if (ps[pi + 1] > max_y)
            max_y = ps[pi + 1];

        pi += 2;
    }

    int r = 600;
    int c = 600;

    int** t = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i ++)
        t[i] = calloc(sizeof(int), c);

    for (int i = 0; i < ai; i ++)
    {
        int x = ps[i * 2] + 100;
        int y = ps[i * 2 + 1] + 100;

        for (int j = 0; j < r; j ++)
            for (int k = 0; k < c; k ++)
            {
                int d = abs(j - x) + abs(k - y);
                t[j][k] += abs(j - x) + abs(k - y);
            }
    }

    int n = 0;
    for (int j = 0; j < r; j ++)
        for (int k = 0; k < c; k ++)
        {
            if (t[j][k] < 10000)
                n ++;
        }

    printf("n is %d.\n", n);
    int r = 360;
    int c = 360;

    int** t = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i ++)
        t[i] = calloc(sizeof(int), c);

    for (int i = 0; i < ai; i ++)
    {
        int x = ps[i * 2];
        int y = ps[i * 2 + 1];

        for (int j = 0; j < r; j ++)
            for (int k = 0; k < c; k ++)
            {
                int d = abs(j - x) + abs(k - y);
                if (!t[j][k])
                    t[j][k] = (i << 16) | d + 1;
                else
                {
                    int ot = abs(t[j][k]);
                    int od = (ot & 0xFFFF) - 1;

                    if (od > d)
                        t[j][k] = (i << 16) | d + 1;
                    else if (od == d)
                        t[j][k] = - t[j][k];
                }
            }
    }

    int* all = calloc(sizeof(int), ai);

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (t[i][j] > 0)
                all[t[i][j] >> 16] ++;
        }

    for (int i = 0; i < ai; i ++)
        all[i] = all[i] << 16 | i;

    qsort(all, ai, sizeof(int), comp_6);

    for (int i = ai - 1; i >= 0; i --)
    {
        int id = all[i] & 0xFFFF;
        bool found = false;

        for (int j = 0; j < r; j ++)
        {
            if ((t[0][j] >> 16 == id)
                || (t[r - 1][j] >> 16 == id)
                || (t[j][0] >> 16 == id)
                || (t[j][c - 1] >> 16 == id))
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            printf("num is %d.\n", all[i] >> 16);
            break;
        }
    }
}

void test()
{
    // stupid wrong algorithm !!
    // MORE CAREFUL and how to simulate this problem
    int ai = 0;
    int left = 0;
    char** as = read_input("input_7", &ai);
    int bits[26] = {0};
    int need[26] = {0};

    for (int i = 0; i < ai; i ++)
    {
        char x, y;
        sscanf(as[i], "Step %c must be finished before step %c can begin.", &x, &y);
        bits[y - 'A'] |= 1 << (x - 'A');
        need[x - 'A'] = 1;
        need[y - 'A'] = 1;
    }

    for (int i = 0; i < 26; i ++)
        if (need[i])
            left ++;

    int ri = 0;
    char* r = malloc(27);
    r[26] = 0;


    while(true)
    {
        int i = 0;
        for (i = 0; i < 26; i ++)
            if (!bits[i] && need[i])
            {
                bits[i] = -1;
                r[ri ++] = i + 'A';
                break;
            }

        if (i == 26)
            break;

        int m = ~ (1 << i);

        i = 0;

        for (i = 0; i < 26; i ++)
            bits[i] &= m;
    }

    r[ri] = 0;
    printf("ri %d %s\n", ri, r);
    return;

#define TN 5

    int t[TN] = {0}; // (ID + 1) | END_TIME
    int cur = 0;
    // stupid wrong code ~!!!!!!!!!
    while (true)
    {
        for (int i = 0; i < TN; i ++)
        {
            int m = ~0;

            // has ID and it's finished
            if ((t[i] & 0xFFFF0000) && (t[i] & 0xFFFF) <= cur)
            {
                m = ~ (1 << ((t[i] >> 16) - 1));
                t[i] &= 0xFFFF;

                for (int j = 0; j < 26; j ++)
                    if (bits[j] > 0)
                        bits[j] &= m;
            }

            if ((t[i] & 0xFFFF) <= cur)
            {
                for (int j = 0; j < 26; j ++)
                    if (!bits[j] && need[j])
                    {
                        left --;
                        bits[j] = -1;
                        need[j] = 0;
                        t[i] = (j + 1) << 16 | (cur + j + 1 + 60);
                        printf("i %d time %d %d %d, %c %c\n", i, cur, t[0] & 0xFFFF, t[1] & 0xFFFF, (t[0] >> 16) - 1 + 'A', (t[1] >> 16) - 1 + 'A');
                        break;
                    }

                if (!left)
                {
                    for (int x = 0; x < TN; x ++)
                        printf("%d.\n", t[x] & 0xFFFF);
                    return;
                }
            }
        }

        int min_t = INT_MAX;
        for (int i = 0; i < TN; i ++)
            if ((t[i] & 0xFFFF0000) && (t[i] & 0xFFFF) < min_t && (t[i] & 0xFFFF) > cur)
                min_t = t[i] & 0xFFFF;
        cur = min_t;
    }
}

// no recursion
// write better code for this !
// second part should be recursion ways
void test()
{
    int ai = 0;
    char** as = read_input("input_8", &ai);

    int all = 0;
    int temp = 0;
    bool got = true;
    bool end = false;

    int si = 0;
    char* s = as[0];
    // char* s = "2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2";
    int l = strlen(s);

    int num = 0;
    int* meta = malloc(sizeof(int) * 15360);
    int* child = malloc(sizeof(int) * 15360);
    int* read = malloc(sizeof(int) * 15360);
    int** values = malloc(sizeof(int*) * 15360);

    // read single int from the input
#define READ_ONE() do {                                         \
        got = false;                                            \
        int t = 0;                                              \
        while (s[si] && (s[si] < '0' || s[si] > '9')) si ++;    \
        if (si == l) break;                                     \
        while (s[si] && (s[si] >= '0' && s[si] <= '9'))         \
            t = t * 10 + s[si ++] - '0';                        \
        temp = t;                                               \
        got = true;                                             \
    } while(0)

    READ_ONE();
    child[0] = temp;
    values[0] = calloc(sizeof(int), temp);
    read[0] = 0;
    READ_ONE();
    meta[0] = temp;
    num ++;

#if 0 // first part
    while (num)
    {
        if (read[num - 1] < child[num - 1])
        {
            read[num - 1] ++;
            READ_ONE();
            child[num] = temp;
            read[num] = 0;
            READ_ONE();
            meta[num] = temp;
            num ++;
        }
        else
        {
            for (int i = 0; i < meta[num - 1]; i ++)
            {
                READ_ONE();
                all += temp;
            }
            num --;
        }
    }
#else
    while (num)
    {
        if (read[num - 1] < child[num - 1])
        {
            read[num - 1] ++;
            READ_ONE();
            child[num] = temp;
            values[num] = calloc(sizeof(int), temp);
            read[num] = 0;
            READ_ONE();
            meta[num] = temp;
            num ++;
        }
        else
        {
            int v = 0;
            for (int i = 0; i < meta[num - 1]; i ++)
            {
                READ_ONE();
                if (child[num - 1])
                {
                    if (temp <= child[num - 1])
                        v += values[num - 1][temp - 1];
                }
                else
                    v += temp;
            }
            all = v;
            free(values[num - 1]);
            values[num - 1] = NULL;
            num --;
            if (num)
                values[num - 1][read[num - 1] - 1] = v;
        }
    }
#endif

    printf("all is %d.\n", all);
}

// just simulations ?
// 2 pointers list
void test()
{
    int p = 405;
    int m = 71700 * 100;

    // 32
    // int p = 9;
    // int m = 25;

    // 146373
    // int p = 13;
    // int m = 7999;

    // 8317
    // int p = 10;
    // int m = 1618;

    // 37305
    // int p = 30;
    // int m = 5807;

    // 54718
    // int p = 21;
    // int m = 6111;

    // 2764
    // int p = 17;
    // int m = 1104;


    struct DListNode* r = cDListNode(0);
    r->pre = r;
    r->nxt = r;

    unsigned long* ps = calloc(sizeof(unsigned long), p);

    struct DListNode* c = r;

    struct DListNode* p1 = NULL;
    struct DListNode* p2 = NULL;

    int np = 0;

    for (int i = 1; i <= m; i ++)
    {
        struct DListNode* t = NULL;
        if (i % 23)
        {
            p1 = c->nxt;
            p2 = c->nxt->nxt;
            t = cDListNode(i);
            p1->nxt = t;
            p2->pre = t;
            t->pre = p1;
            t->nxt = p2;
            c = t;
        }
        else
        {
            ps[np] += i;
            t = c;
            for (int j = 0; j < 7; j ++)
                t = t->pre;

            p1 = t->pre;
            p2 = t->nxt;

            p1->nxt = p2;
            p2->pre = p1;
            ps[np] += t->val;
            free(t);
            c = p2;
        }
        np = (np + 1) % p;
    }

    outl(ps, p);

    unsigned long p_max = ps[0];
    for (int i = 1; i < p; i ++)
        if (p_max < ps[i])
            p_max = ps[i];

    printf("max is %ld.\n", p_max);
}

void test()
{
    int ai = 0;
    char** as = read_input("input_10", &ai);
    int* px = malloc(sizeof(int) * ai);
    int* py = malloc(sizeof(int) * ai);
    int* vx = malloc(sizeof(int) * ai);
    int* vy = malloc(sizeof(int) * ai);

    for (int i = 0; i < ai; i ++)
    {
        int x, y, xv, yv;
        sscanf(as[i], "position=<%d,%d> velocity=<%d,%d>", &x, &y, &xv, &yv);
        px[i] = x;
        py[i] = y;
        vx[i] = xv;
        vy[i] = yv;
    }

    int mt = 0;
    int mn = 0;


#if 0 // get max time
    int time = 0;
    while(true)
    {
        int n = 0;

        for (int i = 0; i < ai; i ++)
            for (int j = i + 1; j < ai; j ++)
                if ((px[i] == px[j] && abs(py[i] - py[j]) == 1)
                    || (py[i] == py[j] && abs(px[i] - px[j]) == 1))
                    n ++;

        if (n > mn)
        {
            mn = n;
            mt = time;
            printf("mn %d mt %d.\n", mn, mt);
        }

        if (!n)
            break;

        time ++;

        for (int i = 0; i < ai; i ++)
        {
            px[i] += vx[i];
            py[i] += vy[i];
        }
    }
    printf("time is %d %d.\n", mt, mn);
#endif

    // mt is 10274
    int min_x = INT_MAX;
    int min_y = INT_MAX;
    int max_x = INT_MIN;
    int max_y = INT_MIN;

    for (int i = 0; i < ai; i ++)
    {
        px[i] += vx[i] * 10274;
        py[i] += vy[i] * 10274;

        if (px[i] < min_x)
            min_x = px[i];

        if (px[i] > max_x)
            max_x = px[i];

        if (py[i] < min_y)
            min_y = py[i];

        if (py[i] > max_y)
            max_y = py[i];
    }

    // int n = 0;
    // for (int i = 0; i < ai; i ++)
    //     for (int j = i + 1; j < ai; j ++)
    //         if ((px[i] == px[j] && abs(py[i] - py[j]) == 1)
    //             || (py[i] == py[j] && abs(px[i] - px[j]) == 1))
    //             n ++;
    // printf("%d %d %d %d %d\n", n, min_x, max_x, min_y, max_y);

    for (int j = 0; j < 30; j ++)
    {
        for (int i = 0; i < 70; i ++)
        {
            int x = i + 99;
            int y = j + 197;

            bool found = false;

            for (int k = 0; k < ai; k ++)
                if (px[k] == x && py[k] == y)
                {
                    found = true;
                    break;
                }

            printf("%c", found ? '#' : '.');
        }
        printf("\n");
    }
}

int get_p(int x, int y, int n)
{
    int rid = 10 + x;
    int t = (rid * y + n) * rid;
    return (t % 1000) / 100 - 5;
}

void test()
{
    int n = 9810;

    int** t = malloc(sizeof(int*) * 301);
    for (int i = 1; i <= 300; i ++)
    {
        t[i] = malloc(sizeof(int) * 301);
        for (int j = 1; j <= 300; j ++)
            t[i][j] = get_p(i, j, n);
    }

    int max = INT_MIN;
    int max_x, max_y, max_n;

    for (int x = 1; x <= 300; x ++)
    {
        printf("try x %d\n", x);
        for (int i = 1; i <= 301 - x; i ++)
            for (int j = 1; j <= 301 - x; j ++)
            {
                int cur = 0;

                for (int ti = i; ti < i + x; ti ++)
                    for (int tj = j; tj < j + x; tj ++)
                        cur += t[ti][tj];

                if (cur > max)
                {
                    max = cur;
                    max_x = i;
                    max_y = j;
                    max_n = x;
                }
            }
    }

    printf("x %d y %d max_n %d, max %d\n", max_x, max_y, max_n, max);
}

// read the description
// just find the pattern
void test()
{
    int ai = 0;
    char** as = read_input("input_12", &ai);

    for (int i = 0; i < ai; i++)
        printf("%s", as[i]);

    int* conv = calloc(sizeof(int), 32);

    for (int i = 0; i < 32 && i < ai - 2; i ++)
    {
        char* t = as[i + 2];
        int x = 0;
        x |= (t[0] == '#' ? 1 : 0) << 0;
        x |= (t[1] == '#' ? 1 : 0) << 1;
        x |= (t[2] == '#' ? 1 : 0) << 2;
        x |= (t[3] == '#' ? 1 : 0) << 3;
        x |= (t[4] == '#' ? 1 : 0) << 4;
        conv[x] = t[9] == '#' ? 1 : 0;
    }
    // out(conv, 32);

    char* o = "##.#...#.#.#....###.#.#....##.#...##.##.###..#.##.###..####.#..##..#.##..#.......####.#.#..#....##.#";
    // char* o = "#..#.#..##......###...###";
    int lo = strlen(o);

    printf("lo is %d.\n", lo);

    // after 72 turns, it never change
    int all = 0;
    int rd = 10000;
    int st = rd + 1;
    int ed = rd + 1;

    int* p = calloc(sizeof(int), (st + lo + ed));
    int* n = calloc(sizeof(int), (st + lo + ed));
    for (int i = 0; i < lo; i ++)
        p[st + i] = o[i] == '#' ? 1 : 0;

    lo += st + ed;

    for (int i = 0; i < rd; i ++)
    {
        for (int j = 0; j < lo; j ++)
        {
            int x = 0;
            x |= ((j >= 2) ? (p[j - 2]) : 0) << 0;
            x |= ((j >= 1) ? (p[j - 1]) : 0) << 1;
            x |= p[j] << 2;
            x |= ((j < lo - 1) ? (p[j + 1]) : 0) << 3;
            x |= ((j < lo - 2) ? (p[j + 2]) : 0) << 4;
            n[j] = conv[x];
        }
        int* t = p;
        p = n;
        n = t;
    }

    int _s = 0;
    int _e = 0;
    int _n = 0;
    for (int i = 0; i < lo; i ++)
        if (p[i])
        {
            _n ++;
            if (!_s)
                _s = i - st;
            all += i - st;
            _e = i - st;
        }

    printf("all is %d _s %d, diff %d _n %d %d.\n", all, _s, _e - _s, _n, rd - _s);
}

// just write the method, is that possible, a cart is on the intersection place
// find simple way to program this one !
void test()
{
    int ai = 0;
    char** as = read_input("input_13", &ai);
    int* ls = malloc(sizeof(int) * ai);
    char** rs = malloc(sizeof(char*) * ai);

    // 1:>, 2:v, 3:<, 4:^
    char nxt_1[5] = {0, 2, 1, 4, 3}; // '\'
    char nxt_2[5] = {0, 4, 3, 2, 1}; // '/'

    char nxt_l[5] = {0, 4, 1, 2, 3}; // left
    char nxt_s[5] = {0, 1, 2, 3, 4}; // straight
    char nxt_r[5] = {0, 2, 3, 4, 1}; // right

    char* nxt[3] = {nxt_l, nxt_s, nxt_r};

    int num = 0;

    for (int i = 0; i < ai; i ++)
    {
        ls[i] = strlen(as[i]);
        rs[i] = strdup(as[i]);

        for (int j = 0; j < ls[i]; j ++)
            if (rs[i][j] == '>')
            {
                rs[i][j] = 1;
                num ++;
            }
            else if (rs[i][j] == 'v')
            {
                rs[i][j] = 2;
                num ++;
            }
            else if (rs[i][j] == '<')
            {
                rs[i][j] = 3;
                num ++;
            }
            else if (rs[i][j] == '^')
            {
                rs[i][j] = 4;
                num ++;
            }
            else if (rs[i][j] == '\n')
                rs[i][j] = 0;
    }

    while (true)
    {
        // for (int i = 0; i < ai; i ++)
        // {
        //     for (int j = 0; j < ls[i]; j ++)
        //     {
        //         if (rs[i][j] >= 32)
        //             printf("%c", rs[i][j]);
        //         else
        //         {
        //             switch(rs[i][j] & 7)
        //             {
        //             case 1:
        //                 printf(">");
        //                 break;
        //             case 2:
        //                 printf("v");
        //                 break;
        //             case 3:
        //                 printf("<");
        //                 break;
        //             case 4:
        //                 printf("^");
        //                 break;
        //             }
        //         }
        //     }
        //     printf("\n");
        // }
        // printf("===== out =====\n");

        if (num == 1)
        {
            for (int i = 0; i < ai; i ++)
                for (int j = 0; j < ls[i]; j ++)
                    if (rs[i][j] < 32 && rs[i][j])
                        printf("%d,%d is %d\n", j, i, rs[i][j]);
            return;
        }

        for (int i = 0; i < ai; i ++)
        {
            char* r = rs[i];
            for (int j = 0; j < ls[i]; j ++)
            {
                if (r[j] >= 31 || !r[j] || ((int) r[j]) & (1 << 7))
                    continue;

                int c = r[j];
                if (as[i][j] == '>' || as[i][j] == '<')
                    r[j] = '-';
                else if (as[i][j] == 'v' || as[i][j] == '^')
                    r[j] = '|';
                else
                    r[j] = as[i][j];

                char* n = NULL;

                switch (c & 7)
                {
                case 1:
                    if (r[j + 1] < 32)
                    {
                        // printf("%d,%d\n", j + 1, i);
                        // return;
                        printf("== 1 %d\n", num);
                        if (as[i][j + 1] == '>' || as[i][j + 1] == '<')
                            r[j + 1] = '-';
                        else if (as[i][j + 1] == 'v' || as[i][j + 1] == '^')
                            r[j + 1] = '|';
                        else
                            r[j + 1] = as[i][j + 1];
                        num -= 2;
                        printf("1 %d\n", num);
                        continue;
                    }
                    n = &r[j + 1];
                    break;
                case 2:
                    if (rs[i + 1][j] < 32)
                    {
                        // printf("%d,%d\n", j, i + 1);
                        // return;
                        printf("== 2 %d\n", num);

                        if (as[i + 1][j] == '>' || as[i + 1][j] == '<')
                            rs[i + 1][j] = '-';
                        else if (as[i + 1][j] == 'v' || as[i + 1][j] == '^')
                            rs[i + 1][j] = '|';
                        else
                            rs[i + 1][j] = as[i + 1][j];
                        num -= 2;
                        printf("2 %d\n", num);
                        continue;
                    }
                    n = &rs[i + 1][j];
                    break;
                case 3:
                    if (r[j - 1] < 32)
                    {
                        // printf("%d,%d\n", j - 1, i);
                        // return;
                        printf("== 3 %d\n", num);
                        if (as[i][j - 1] == '>' || as[i][j - 1] == '<')
                            r[j - 1] = '-';
                        else if (as[i][j - 1] == 'v' || as[i][j - 1] == '^')
                            r[j - 1] = '|';
                        else
                            r[j - 1] = as[i][j - 1];
                        num -= 2;
                        printf("3 %d\n", num);
                        continue;
                    }
                    n = &r[j - 1];
                    break;
                case 4:
                    if (rs[i - 1][j] < 32)
                    {
                        // printf("%d,%d\n", j, i - 1);
                        // return;
                        printf("== 4 %d\n", num);
                        if (as[i - 1][j] == '>' || as[i - 1][j] == '<')
                            rs[i - 1][j] = '-';
                        else if (as[i - 1][j] == 'v' || as[i - 1][j] == '^')
                            rs[i - 1][j] = '|';
                        else
                            rs[i - 1][j] = as[i - 1][j];
                        num -= 2;
                        printf("4 %d\n", num);
                        continue;
                    }
                    n = &rs[i - 1][j];
                    break;
                }

                if (!n)
                {
                    printf("num is %d.\n", num);
                    continue;
                }

                if (*n == '+')
                    *n = (nxt[c >> 3][c & 7]) | ((((c >> 3) + 1) % 3) << 3);
                else if (*n == '\\')
                    *n = (nxt_1[c & 7]) | (c & 24);
                else if (*n == '/')
                    *n = (nxt_2[c & 7]) | (c & 24);
                else
                    *n = c;
                *n |= 1 << 7;
            }
        }

        for (int i = 0; i < ai; i ++)
            for (int j = 0; j < ls[i]; j ++)
                if (rs[i][j] & (1 << 7))
                    rs[i][j] &= 127;
    }
}

void test()
{
    int si = 0;
    int need = 103637061;
    int num = need + 20;
    // int num = 30;
    int* sn = malloc(sizeof(int) * (num));

    sn[si ++] = 3;
    sn[si ++] = 7;

    int x = 0;
    int y = 1;

    while (si < num - 2)
    {
        int z = sn[x] + sn[y];
        if (z >= 10)
            sn[si ++] = z / 10;
        sn[si ++] = z % 10;

        x = (x + sn[x] + 1) % si;
        y = (y + sn[y] + 1) % si;
        // out(sn, num);
    }

    // for (int i = 0; i < 10; i ++)
    //     printf("%d", sn[need + i]);
    // printf("\n");

    for (int i = 0; i < num - 6; i ++)
    {
        if (sn[i] == 6 &&
            sn[i + 1] == 3 &&
            sn[i + 2] == 7 &&
            sn[i + 3] == 0 &&
            sn[i + 4] == 6 &&
            sn[i + 5] == 1)
        {
            printf("haha here, %d.", i);
            break;
        }
    }
}

bool step_to(int a, int b, int r, int c, int nx, int ny, int ns, int** as, int* s, int* t)
{
    int si = 0;
    int ti = 0;

    s[si ++] = a << 16 | b;

    unsigned long bits[64] = {0};

    // printf("try step from %d:%d to %d:%d with %d %d.\n", a, b, nx, ny, ns - 1, s[0]);

    for (int n = 0; n < ns; n ++)
    {
        for (int i = 0; i < si; i ++)
        {
            int x = s[i] >> 16;
            int y = s[i] & 0xFFFF;

            // printf("s[i] %d x is %d y is %d, n is %d.\n", s[i], x, y, n);

            if (x && as[x - 1][y] == '.' && !(bits[x - 1] & (1L << y)))
            {
                bits[x - 1] |= 1L << y;
                t[ti ++] = (x - 1) << 16 | y;
            }

            if (y && as[x][y - 1] == '.' && !(bits[x] & (1L << (y - 1))))
            {
                bits[x] |= 1L << (y - 1);
                t[ti ++] = x << 16 | y - 1;
            }

            if (x < r && as[x + 1][y] == '.' && !(bits[x + 1] & (1L << y)))
            {
                bits[x + 1] |= 1L << y;
                t[ti ++] = (x + 1) << 16 | y;
            }

            if (y < c && as[x][y + 1] == '.' && !(bits[x] & (1L << (y + 1))))
            {
                bits[x] |= 1L << (y + 1);
                t[ti ++] = x << 16 | y + 1;
            }
        }

        // printf("ti is %d.\n", ti);
        si = ti;
        ti = 0;
        int* _t = t;
        t = s;
        s = _t;
    }

    for (int i = 0; i < si; i ++)
    {
        int x = s[i] >> 16;
        int y = s[i] & 0xFFFF;

        if (x == nx && y == ny)
            return true;
    }

    return false;
}

int next_step(int a, int b, int e, int r, int c, int** as, int* s, int* t)
{
    int si = 0;
    int ti = 0;

    s[si ++] = a << 16 | b;

    bool found = false;

    int ns = 0;
    int nx = INT_MAX;
    int ny = INT_MAX;

    // choose the positions which is the reading order !!!
    unsigned long bits[64] = {0};

    while (si)
    {
        ns ++;
        for (int i = 0; i < si; i ++)
        {
            int x = s[i] >> 16;
            int y = s[i] & 0xFFFF;

            if (x)
            {
                if ((as[x - 1][y] & 0xFF)== e)
                {
                    found = true;
                    if (x < nx || (x == nx && y < ny))
                    {
                        nx = x;
                        ny = y;
                    }
                }
                else if (as[x - 1][y] == '.' && !(bits[x - 1] & (1L << y)))
                {
                    bits[x - 1] |= 1L << y;
                    t[ti ++] = (x - 1) << 16 | y;
                }
            }

            if (y)
            {
                if ((as[x][y - 1] & 0xFF) == e)
                {
                    found = true;
                    if (x < nx || (x == nx && y < ny))
                    {
                        nx = x;
                        ny = y;
                    }
                }
                else if (as[x][y - 1] == '.' && !(bits[x] & (1L << (y - 1))))
                {
                    bits[x] |= 1L << (y - 1);
                    t[ti ++] = x << 16 | y - 1;
                }
            }

            if (y < c)
            {
                if ((as[x][y + 1] & 0xFF) == e)
                {
                    found = true;
                    if (x < nx || (x == nx && y < ny))
                    {
                        nx = x;
                        ny = y;
                    }
                }

                else if (as[x][y + 1] == '.' && !(bits[x] & (1L << (y + 1))))
                {
                    bits[x] |= 1L << (y + 1);
                    t[ti ++] = x << 16 | y + 1;
                }
            }

            if (x < r)
            {
                if ((as[x + 1][y] & 0xFF) == e)
                {
                    found = true;
                    if (x < nx || (x == nx && y < ny))
                    {
                        nx = x;
                        ny = y;
                    }
                }
                else if (as[x + 1][y] == '.' && !(bits[x + 1] & (1L << y)))
                {
                    bits[x + 1] |= 1L << y;
                    t[ti ++] = (x + 1) << 16 | y;
                }
            }
        }

        if (found)
            break;

        si = ti;
        ti = 0;
        int* _t = t;
        t = s;
        s = _t;
    }

    if (!found)
        return 0;

    // printf("ns is %d for %d %d %d %d.\n", ns, a, b, nx, ny);

    // order is important
    if (a && as[a - 1][b] == '.' && step_to(a - 1, b, r, c, nx, ny, ns - 2, as, s, t))
        return (a) << 16 | b + 1;
    if (b && as[a][b - 1] == '.' && step_to(a, b - 1, r, c, nx, ny, ns - 2, as, s, t))
        return (a + 1) << 16 | b;
    if (b < c && as[a][b + 1] == '.' && step_to(a, b + 1, r, c, nx, ny, ns - 2, as, s, t))
        return (a + 1) << 16 | b + 2;
    if (a < r && as[a + 1][b] == '.' && step_to(a + 1, b, r, c, nx, ny, ns - 2, as, s, t))
        return (a + 2) << 16 | b + 1;

    printf("error here\n");
    return 0;
}

bool near_by(int x, int y, int r, int c, int** as, char n)
{
    return (x && (as[x - 1][y] & 0xFF) == n)
        || (y && (as[x][y - 1] & 0xFF) == n)
        || (x < r && (as[x + 1][y] & 0xFF) == n)
        || (y < c && (as[x][y + 1] & 0xFF) == n);
}

int win(int r, int c, int** as)
{
    int gi = 0;
    int ei = 0;

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if ((as[i][j] & 0xFF) == 'G')
                gi += (as[i][j] >> 8) & 0xFF;
            else if ((as[i][j] & 0xFF) == 'E')
                ei += (as[i][j] >> 8) & 0xFF;
        }

    if (!gi)
        return ei;

    if (!ei)
        return gi;

    return 0;
}

void out_input_15(int** as, int r, int c)
{
    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
            printf("%c", as[i][j] & 0xFF);
    }
    printf("\n");

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if ((as[i][j] & 0xFF) == 'G' || (as[i][j] & 0xFF) == 'E')
                printf("left %c is %d.\n", as[i][j] & 0xFF, (as[i][j] >> 8) & 0xFF);
        }
}

bool attack(int i, int j, int r, int c, int** as, int e, int power)
{
    if (e == 'E')
        power = 3;

    int nx = 0;
    int ny = 0;
    int nhp = INT_MAX;
    if (i && (as[i - 1][j] & 0xFF) == e && nhp > (as[i - 1][j] & 0xFF00))
    {
        nx = i - 1;
        ny = j;
        nhp = as[i - 1][j] & 0xFF00;
    }

    if (j && (as[i][j - 1] & 0xFF) == e && nhp > (as[i][j - 1] & 0xFF00))
    {
        nx = i;
        ny = j - 1;
        nhp = as[i][j - 1] & 0xFF00;
    }

    if (j < c && (as[i][j + 1] & 0xFF) == e && nhp > (as[i][j + 1] & 0xFF00))
    {
        nx = i;
        ny = j + 1;
        nhp = as[i][j + 1] & 0xFF00;
    }

    if (i < r && (as[i + 1][j] & 0xFF) == e && nhp > (as[i + 1][j] & 0xFF00))
    {
        nx = i + 1;
        ny = j;
    }

    int hp = (as[nx][ny] >> 8) & 0xFF;

    if (hp <= power)
    {
        as[nx][ny] = '.';

        if (e == 'E')
        {
            printf("died here.\n");
            return false;
        }
    }
    else
        as[nx][ny] = (as[nx][ny] & 0xFFFF00FF) | (hp - power) << 8;

    return true;
}

// 93 turns
// define of fully turns !!!!!!!!!
// too many corner cases !!!!!!!!
// find the reading order of the next move
// do it again !
// just be careful !!!
void test()
{
    int ai = 0;
    char** aas = read_input("input_15", &ai);
    int r = ai;
    int c = strlen(aas[0]);
    int* s = malloc(sizeof(int) * r * c);
    int* t = malloc(sizeof(int) * r * c);
    int** as = malloc(sizeof(int*) * r);
    for (int i = 0; i < ai; i ++)
        as[i] = malloc(sizeof(int) * c);

    for (int p = 3; p < 200; p ++)
    {
    try_again:
        printf("start as p is %d.\n", p);
        for (int i = 0; i < ai; i ++)
            for (int j = 0; j < c; j ++)
            {
                as[i][j] = aas[i][j];
                if (as[i][j] == 'G' || as[i][j] == 'E')
                    as[i][j] |= 200 << 8;
            }

        int ret = 0;
        int all = 0;
        int turns = 0;

        while (true)
        {
            // printf("\n");
            for (int i = 0; i < r; i ++)
                for (int j = 0; j < c; j ++)
                {
                    int x = as[i][j];
                    if (!x || x == ' ' || x == '\n' || x == '.' || x == '#' || (x & (1 << 30)))
                        continue;

                    ret = win(r, c, as);

                    if (ret)
                    {
                        out_input_15(as, r, c);
                        printf("p is %d result is %d turns %d outcomes %d.\n", p, ret, turns, ret * turns);
                        return;
                    }

                    int e = (x & 0xFF) == 'G' ? 'E' : 'G';

                    if (near_by(i, j, r, c, as, e))
                    {
                        if (!attack(i, j, r, c, as, e, p))
                        {
                            p ++;
                            printf("try p %d.\n", p);
                            goto try_again;
                        }
                    }
                    else
                    {
                        if (near_by(i, j, r, c, as, '.'))
                        {
                            int n = next_step(i, j, e, r, c, as, s, t);
                            if (n)
                            {
                                int nx = (n >> 16) - 1;
                                int ny = (n & 0xFFFF) - 1;

                                as[i][j] = '.';
                                as[nx][ny] = x | (1 << 30);
                                if (near_by(nx, ny, r, c, as, e))
                                {
                                    if (!attack(nx, ny, r, c, as, e, p))
                                    {
                                        p ++;
                                        printf("try p %d.\n", p);
                                        goto try_again;
                                    }
                                }
                            }
                        }
                    }
                }

            turns ++;
            printf("turn is %d.\n", turns);

            out_input_15(as, r, c);

            for (int i = 0; i < r; i ++)
                for (int j = 0; j < c; j ++)
                    as[i][j] &= 0xFFFFFFF;
        }
    }
}

void carry_on(int* rs, int op, int o2, int o3, int o4)
{
    // read register 0, immediate 1
    // ops add 1 << 0, mul 1 << 1, bitwise and 1 << 2, bitwise or 1 << 3, assignment 1 << 4, great 1 << 5, equal 1 << 6
    int opc[16] = {
                   0 << 24 | 0 << 16 | 0 << 8 | 1, // addr
                   0 << 24 | 1 << 16 | 0 << 8 | 1, // addi
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 1, // mulr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 1, // muli
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 2, // banr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 2, // bani
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 3, // borr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 3, // bori
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // setr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // seti
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 5, // gtri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtrr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 6, // eqri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqrr
    };
    op = opc[op];

    int va = o2;
    if (!(op & 0xFF000000))
        va = rs[o2];

    int vb = o3;
    if (!(op & 0x00FF0000))
        vb = rs[o3];

    switch (op & 0xFF)
    {
    case 1:
        rs[o4] = va + vb;
        break;
    case 1 << 1:
        rs[o4] = va * vb;
        break;
    case 1 << 2:
        rs[o4] = va & vb;
        break;
    case 1 << 3:
        rs[o4] = va | vb;
        break;
    case 1 << 4:
        rs[o4] = va;
        break;
    case 1 << 5:
        rs[o4] = va > vb ? 1 : 0;
        break;
    case 1 << 6:
        rs[o4] = va == vb ? 1 : 0;
        break;
    }
}

// before -> after
int count_opcodes(int b1, int b2, int b3, int b4,
                  int a1, int a2, int a3, int a4,
                  int o1, int o2, int o3, int o4,
                  int* used, int* r)
{
    // read register 0, immediate 1
    // ops add 1 << 0, mul 1 << 1, bitwise and 1 << 2, bitwise or 1 << 3, assignment 1 << 4, great 1 << 5, equal 1 << 6
    int opc[16] = {
                   0 << 24 | 0 << 16 | 0 << 8 | 1, // addr
                   0 << 24 | 1 << 16 | 0 << 8 | 1, // addi
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 1, // mulr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 1, // muli
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 2, // banr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 2, // bani
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 3, // borr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 3, // bori
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // setr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // seti
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 5, // gtri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtrr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 6, // eqri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqrr
    };

    int rs[4] = {0};

    int counts = 0;

    for (int i = 0; i < 16; i ++)
    {
        if (used[i])
            continue;

        int op = opc[i];
        int va = o2;

        rs[0] = b1;
        rs[1] = b2;
        rs[2] = b3;
        rs[3] = b4;

        if (!(op & 0xFF000000))
            va = rs[o2];

        int vb = o3;

        if (!(op & 0x00FF0000))
            vb = rs[o3];

        switch (op & 0xFF)
        {
        case 1:
            rs[o4] = va + vb;
            break;
        case 1 << 1:
            rs[o4] = va * vb;
            break;
        case 1 << 2:
            rs[o4] = va & vb;
            break;
        case 1 << 3:
            rs[o4] = va | vb;
            break;
        case 1 << 4:
            rs[o4] = va;
            break;
        case 1 << 5:
            rs[o4] = va > vb ? 1 : 0;
            break;
        case 1 << 6:
            rs[o4] = va == vb ? 1 : 0;
            break;
        }

        if (rs[0] == a1 && rs[1] == a2 && rs[2] == a3 && rs[3] == a4)
        {
            counts ++;
            *r = i;
        }
    }
    return counts;
}

// simple, even no backtrace !
void test()
{
    int ai = 0;
    char** as = read_input("input_16", &ai);

    int num = 0;
    int counts = 0;

    /* for (int i = 0; i < ai; i ++) */
    /* { */
    /*     int b1, b2, b3, b4; */
    /*     if (sscanf(as[i], "Before: [%d, %d, %d, %d]", &b1, &b2, &b3, &b4) == 4) */
    /*     { */
    /*         int o1, o2, o3, o4; */
    /*         sscanf(as[i + 1], "%d %d %d %d", &o1, &o2, &o3, &o4); */
    /*         int a1, a2, a3, a4; */
    /*         sscanf(as[i + 2], "After: [%d, %d, %d, %d]", &a1, &a2, &a3, &a4); */
    /*         num ++; */
    /*         int n = count_opcodes(b1, b2, b3, b4, a1, a2, a3, a4, o1, o2, o3, o4); */
    /*         // printf("n is %d %s %s %s.\n", n, as[i], as[i + 1], as[i + 2]); */
    /*         if (n >= 3) */
    /*             counts ++; */
    /*         i += 2; */
    /*     } */
    /* } */

    int r = 0;
    int opc[16] = {0};
    int used[16] = {0};

    int need = 16;
    while (need)
    {
        bool found = false;
        for (int i = 0; i < ai; i ++)
        {
            int b1, b2, b3, b4;

            if (sscanf(as[i], "Before: [%d, %d, %d, %d]", &b1, &b2, &b3, &b4) == 4)
            {
                int o1, o2, o3, o4;
                sscanf(as[i + 1], "%d %d %d %d", &o1, &o2, &o3, &o4);

                if (!opc[o1])
                {
                    int a1, a2, a3, a4;
                    sscanf(as[i + 2], "After: [%d, %d, %d, %d]", &a1, &a2, &a3, &a4);
                    num ++;
                    int n = count_opcodes(b1, b2, b3, b4, a1, a2, a3, a4, o1, o2, o3, o4, used, &r);

                    if (n == 1)
                    {
                        printf("o1 is %d %d.\n", o1, r);
                        found = true;
                        used[r] = 1;
                        opc[o1] = (r) + 1;
                        need --;
                    }
                }
                i += 2;
            }
        }
        if (!found)
            break;
    }

    int rs[4] = {0};
    for (int i = 3342; i < ai; i ++)
    {
        int o1, o2, o3, o4;
        sscanf(as[i], "%d %d %d %d", &o1, &o2, &o3, &o4);
        carry_on(rs, opc[o1] - 1, o2, o3, o4);
    }

    out(rs, 4);
    printf("num is %d counts %d need %d.\n", num, counts, need);
}

void output_17(int xl, int yl, char** area)
{
    for (int i = 0; i < yl; i ++)
    {
        for (int j = 0; j < xl; j ++)
            printf("%c", area[j][i]);
        printf("\n");
    }
}

bool fill(int* stacks, int start, int* si, char** area, int xl, int yl)
{
    int last = *si - 1;

    bool got = false;

    for (int i = last; i >= start; i --)
    {
        int x = (stacks[i] >> 16) & 0xFFFF;
        int y = stacks[i] & 0xFFFF;

        int r_x = x;
        bool r_o = false;

        int j = 0;

        // right
        for (j = x + 1; j < xl; j ++)
        {
            if (area[j][y] == '#')
                break;

            r_x = j;

            if (area[j][y + 1] == '.' || area[j][y + 1] == '|')
            {
                r_o = true;
                break;
            }
        }

        if (j == xl)
        {
            r_x = j;
            r_o = true;
        }

        int l_x = x;
        bool l_o = false;

        // left
        for (j = x - 1; j >= 0; j --)
        {
            if (area[j][y] == '#')
                break;

            l_x = j;

            if (area[j][y + 1] == '.' || area[j][y + 1] == '|')
            {
                l_o = true;
                break;
            }
        }

        if (j < 0)
        {
            l_x = j;
            l_o = true;
        }


        if (l_o || r_o)
        {
            int in = i;
            if (l_o && l_x >= 0)
                stacks[in ++] = l_x << 16 | y;

            if (r_o && r_x < xl)
                stacks[in ++] = r_x << 16 | y;

            for (j = l_x; j <= r_x; j ++)
                if (j >= 0 && j < xl)
                {
                    if (area[j][y] != '|')
                        got = true;
                    area[j][y] = '|';
                }
            *si = in;
            break;
        }
        else
        {
            for (j = l_x; j <= r_x; j ++)
                if (j >= 0 && j < xl)
                {
                    if (area[j][y] != '~')
                        got = true;
                    area[j][y] = '~';
                }
        }
    }

    return got;
}

// how to code this
// x values is always valid !!!!!!!!!, must count the outside for dropping water ~~~~~!!!!!!!!
// be careful
void test()
{
    int ai = 0;
    char** as = read_input("input_17", &ai);

    int minx = INT_MAX;
    int miny = INT_MAX;
    int maxx = INT_MIN;
    int maxy = INT_MIN;

    long* all = malloc(sizeof(long) * ai);

    for (int i = 0; i < ai; i ++)
    {
        long x1 = 0, x2 = 0;
        long y1 = 0, y2 = 0;

        if (as[i][0] == 'x')
        {
            sscanf(as[i], "x=%ld, y=%ld..%ld", &x1, &y1, &y2);
            x2 = x1;
        }
        else
        {
            sscanf(as[i], "y=%ld, x=%ld..%ld", &y1, &x1, &x2);
            y2 = y1;
        }

        if (x1 < minx)
            minx = x1;
        if (x2 > maxx)
            maxx = x2;
        if (y1 < miny)
            miny = y1;
        if (y2 > maxy)
            maxy = y2;

        all[i] = x1 << 48 | x2 << 32 | y1 << 16 | y2;
    }

    // any x is valid, so leave the space for outside dropping !!
    minx -= 2;

    int xl = maxx - minx + 2;
    int yl = maxy + 1;
    char** area = malloc(sizeof(char*) * xl);
    for (int i = 0; i < xl; i ++)
    {
        area[i] = malloc(sizeof(char) * yl);
        memset(area[i], '.', sizeof(char) * yl);
    }

    for (int i = 0; i < ai; i ++)
    {
        int x1 = (all[i] >> 48) & 0xFFFF;
        int x2 = (all[i] >> 32) & 0xFFFF;
        int y1 = (all[i] >> 16) & 0xFFFF;
        int y2 = all[i] & 0xFFFF;

        for (int j = x1; j <= x2; j ++)
            for (int k = y1; k <= y2; k ++)
                area[j - minx][k] = '#';
    }

    area[500 - minx][0] = '+';
    // output_17(xl, yl, area);

    int si = 0;
    int* stacks = malloc(sizeof(int) * xl * yl);
    stacks[si ++] = (500 - minx) << 16 | 0;

    int tsi = 0;
    int* t_stacks = malloc(sizeof(int) * xl * yl);

    bool got_fill = true;

    int showy = 0;

    while (got_fill && si)
    {
        got_fill = false;

        for (int i = si - 1; i >= 0; i --)
        {
            int x = (stacks[i] >> 16) & 0xFFFF;
            int y = stacks[i] & 0xFFFF;
            int oti = tsi;

            t_stacks[tsi ++] = stacks[i];

            while (y < maxy && area[x][y + 1] == '.')
            {
                area[x][++ y] = '|';
                t_stacks[tsi ++] = x << 16 | y;
            }

            if (y + 1 > showy)
                showy = y + 1;

            if (y < maxy && (area[x][y + 1] == '#' || area[x][y + 1] == '~'))
            {
                got_fill = got_fill || fill(t_stacks, oti, &tsi, area, xl, yl);
            }
        }

        // output_17(xl, showy + 1, area);
        // printf("\n============================================= showy is %d\n", showy);
        // getchar();

        si = 0;
        for (int i = tsi - 1; i >= 0; i --)
        {
            stacks[si ++] = t_stacks[i];
            // printf("%d %d.\n", t_stacks[i] >> 16, t_stacks[i] & 0xFFFF);
        }
        tsi = 0;
    }
    // count the number
    output_17(xl, showy + 1, area);

    int counts = 0;
    int counts_left = 0;
    for (int i = 0; i < xl; i ++)
        for (int j = 1; j < yl; j ++)
            if (j >= miny && j <= maxy)
            {
                if (area[i][j] == '|' || area[i][j] == '~')
                    counts ++;
                if (area[i][j] == '~')
                    counts_left ++;
            }

    printf("n is %d %d.\n", counts, counts_left);
}

char conv(char** as, int x, int y, int r, int c)
{
    int nums[256] = {0};

    if (x - 1 >= 0)
    {
        if (y - 1 >= 0)
            nums[as[x - 1][y - 1]] ++;

        nums[as[x - 1][y]] ++;

        if (y + 1 < c)
            nums[as[x - 1][y + 1]] ++;
    }

    if (x + 1 < r)
    {
        if (y - 1 >= 0)
            nums[as[x + 1][y - 1]] ++;

        nums[as[x + 1][y]] ++;

        if (y + 1 < c)
            nums[as[x + 1][y + 1]] ++;
    }

    if (y - 1 >= 0)
        nums[as[x][y - 1]] ++;

    if (y + 1 < c)
        nums[as[x][y + 1]] ++;

    char ret = 0;

    switch(as[x][y])
    {
    case '.':
        ret = nums['|'] >= 3 ? '|' : '.';
        break;
    case '|':
        ret = nums['#'] >= 3 ? '#' : '|';
        break;
    case '#':
        ret = (nums['#'] >= 1 && nums['|'] >= 1) ? '#' : '.';
        break;
    }

    // printf("ret for x %d y %d %c is %c.\n", x, y, as[x][y], ret);
    return ret;
}
void test()
{
    int ai = 0;
    char** as = read_input("input_18", &ai);
    char** t = malloc(sizeof(char*) * ai);

    for (int i = 0; i < ai; i ++)
        t[i] = strdup(as[i]);

    int r = ai;
    int c = strlen(as[0]) - 1;fefe

    int pi = 0;
    char** previous = malloc(sizeof(char**) * 10000000);

    bool got_diff = false;

    for (int time = 0; time < 1000000000; time ++)
    {
        for (int p = 0; p < pi; p += r)
        {
            bool diff = false;

            for (int i = 0; i < r; i ++)
                if (strcmp(previous[p + i], as[i]))
                {
                    diff = true;
                    break;
                }

            if (!diff)
            {
                int otime = time;
                int x = time - (p / r);
                time += ((1000000000 - time) / x) * x;
                printf("%d is same with %d, so %d can be %d now.\n", otime, p / r, otime, time);
                break;
            }
        }

        for (int i = 0; i < r; i ++)
            previous[pi ++] = strdup(as[i]);

        // out_input(as, ai);
        for (int i = 0; i < r; i ++)
            for (int j = 0; j < c; j ++)
                t[i][j] = conv(as, i, j, r, c);

        char** _t = t;
        t = as;
        as = _t;

    }

    int rt = 0;
    int rl = 0;
    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
            if (as[i][j] == '|')
                rt ++;
            else if (as[i][j] == '#')
                rl ++;

    printf("\n %dx%d= %d.\n", rt, rl, rt * rl);
}


void output_20(char** base, int size)
{
    int minx = INT_MAX;
    int maxx = INT_MIN;
    int miny = INT_MAX;
    int maxy = INT_MIN;

    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j ++)
        {
            if (base[i][j])
            {
                if (i < minx)
                    minx = i;
                if (i > maxx)
                    maxx = i;

                if (j < miny)
                    miny = j;
                if (j > maxy)
                    maxy = j;
            }
        }

    for (int j = miny; j <= maxy; j ++)
    {
        for (int i = minx; i <= maxx; i ++)
        {
            int c = base[i][j];
            if (c & (1 << 0))
                printf("#-#");
            else
                printf("###");
        }
        printf("\n");
        for (int i = minx; i <= maxx; i ++)
        {
            int c = base[i][j];
            if (c & (1 << 1) && c & (1 << 3))
                printf("|.|");
            else if (c & (1 << 1))
                printf("|.#");
            else if (c & (1 << 3))
                printf("#.|");
            else
                printf("#.#");
        }
        printf("\n");
        for (int i = minx; i <= maxx; i ++)
        {
            int c = base[i][j];
            if (c & (1 << 2))
                printf("#-#");
            else
                printf("###");
        }
        printf("\n");
    }
}

int distance(char** base, int size)
{
    int minx = INT_MAX;
    int maxx = INT_MIN;
    int miny = INT_MAX;
    int maxy = INT_MIN;

    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j ++)
        {
            if (base[i][j])
            {
                if (i < minx)
                    minx = i;
                if (i > maxx)
                    maxx = i;

                if (j < miny)
                    miny = j;
                if (j > maxy)
                    maxy = j;
            }
        }

    int x = size / 2 - minx;
    int y = size / 2 - miny;

    int lx = maxx - minx + 1;
    int ly = maxy - miny + 1;

    int* s = malloc(sizeof(int) * lx * ly);
    int* t = malloc(sizeof(int) * lx * ly);
    int** b = malloc(sizeof(int*) * lx);
    for (int i = 0; i < lx; i ++)
        b[i] = calloc(sizeof(int), ly);

    int si = 0;
    int ti = 0;
    s[si ++] = x << 16 | y;
    b[x][y] = 1;

    int max = 0;

    while (si)
    {
        max ++;
        for (int i = 0; i < si; i ++)
        {
            x = s[i] >> 16;
            y = s[i] & 0xFFFF;
            char r = base[x + minx][y + miny];

            if (r & (1 << 0) && !b[x][y - 1])
            {
                b[x][y - 1] = b[x][y] + 1;
                t[ti ++] = x << 16 | y - 1;
            }

            if (r & (1 << 1) && !b[x - 1][y])
            {
                b[x - 1][y] = b[x][y] + 1;
                t[ti ++] = (x - 1) << 16 | y;
            }

            if (r & (1 << 2) && !b[x][y + 1])
            {
                b[x][y + 1] = b[x][y] + 1;
                t[ti ++] = x << 16 | y + 1;
            }

            if (r & (1 << 3) && !b[x + 1][y])
            {
                b[x + 1][y] = b[x][y] + 1;
                t[ti ++] = (x + 1) << 16 | y;
            }
        }

        si = ti;
        ti = 0;
        int* _t = t;
        t = s;
        s = _t;
    }

    int temp = 0;
    for (int i = 0; i < lx; i ++)
        for (int j = 0; j < ly; j ++)
        {
            if (b[i][j] >= 1001)
                temp ++;
        }

    printf("temp is %d. max %d \n", temp, max);
    return max - 1;
}

// find better way to represent this ?!!!!!!!!!
int* walk(char** base, int* _in, int _in_num, int r, int c, char* p, int* _pi, int* out_num)
{
    printf("pi is %d in_num %d %c.\n", *_pi, _in_num, p[*_pi]);
    int rn = 0;
    int* ret = NULL;
    int pi = *_pi;

    if (p[pi] == '^' || p[pi] == '(')
        pi ++;

    int in_num = _in_num;
    int* in = malloc(sizeof(int) * in_num);
    memcpy(in, _in, sizeof(int) * in_num);

    while (p[pi] != '$' && p[pi] != ')')
    {
        int opi = pi;

        if (p[pi] != '(' && p[pi] != '|' && p[pi] != ')' && p[pi] != '$')
        {
            for (int i = 0; i < in_num; i ++)
            {
                pi = opi;

                int x = (in[i] >> 16) & 0xFFFF;
                int y = in[i] & 0xFFFF;

                while (p[pi] != '(' && p[pi] != '|' && p[pi] != ')' && p[pi] != '$') // can only be '('
                {
                    char c = p[pi];
                    switch (c)
                    {
                    case 'N':
                        base[x][y] |= 1 << 0;
                        base[x][y - 1] |= 1 << 2;
                        y -= 1;
                        break;
                    case 'W':
                        base[x][y] |= 1 << 1;
                        base[x - 1][y] |= 1 << 3;
                        x -= 1;
                        break;
                    case 'S':
                        base[x][y] |= 1 << 2;
                        base[x][y + 1] |= 1 << 0;
                        y += 1;
                        break;
                    case 'E':
                        base[x][y] |= 1 << 3;
                        base[x + 1][y] |= 1 << 1;
                        x += 1;
                        break;
                    }
                    pi ++;
                }
                in[i] = x << 16 | y;
            }
        }

        if (p[pi] == '(')
            in = walk(base, in, in_num, r, c, p, &pi, &in_num);

        if (p[pi] == '|')
        {
            ret = realloc(ret, sizeof(int) * (rn + in_num));
            memcpy(&ret[rn], in, sizeof(int) * in_num);
            rn += in_num;

            free(in);
            in_num = _in_num;
            in = malloc(sizeof(int) * in_num);
            memcpy(in, _in, sizeof(int) * in_num);
            pi ++;
        }
    }

    ret = realloc(ret, sizeof(int) * (rn + in_num));
    memcpy(&ret[rn], in, sizeof(int) * in_num);
    rn += in_num;
    q_sort(ret, 0, rn - 1);

    int ri = 1;
    for (int i = 1; i < rn; i ++)
        if (ret[i] != ret[i - 1])
            ret[ri ++] = ret[i];
    rn = ri;
    *_pi = pi + 1;
    *out_num = rn;

    // for (int i = 0; i < rn; i ++)
    //     printf("%d %d.\n", ret[i] >> 16, ret[i] & 0xFFFF);
    return ret;
}

// do it again !!!!!!!!!!!!!!!!!!!!!!!!
// find a way to represent this problems
// recursion version
// have a clear mind !!!!!!!!!!!!
void test()
{
    int ai = 0;
    char** as = read_input("input_20", &ai);
    int l = strlen(as[0]);

    // int* stacks = malloc(sizeof(int) * l);
#define SIZE 1024
    char** t = malloc(sizeof(char*) * SIZE);
    for (int i = 0; i < SIZE; i ++)
        t[i] = calloc(sizeof(char), SIZE);

    int x = SIZE / 2;
    int y = SIZE / 2;
    // go through all of the possible ways
    int pi = 0;

    int* temp = malloc(sizeof(int) * 1);
    temp[0] = x << 16 | y;

    int* ret;
    int out_num = 0;
    ret = walk(t, temp, 1, SIZE, SIZE, as[0], &pi, &out_num);

    for (int i = 0; i < out_num; i ++)
       printf("%d %d.\n", ret[i] >> 16, ret[i] & 0xFFFF);
    output_20(t, SIZE);

    printf("max lenght is %d.\n", distance(t, SIZE));
}

// just run it and skip inner loops !
// how can I solve this in minutes !!!
// find a way to skip the outer looper !!!
/*
ip=2, [14068556, 10551393, 1, 10551396, 0, 10551397]
ip=3, [14068556, 10551393, 2, 10551396, 0, 1]
ip=4, [14068556, 10551393, 3, 10551396, 10551393, 1]
ip=5, [14068556, 10551393, 4, 10551396, 0, 1]
ip=6, [14068556, 10551393, 5, 10551396, 0, 1]
ip=8, [14068556, 10551393, 7, 10551396, 0, 1]
ip=9, [14068556, 10551393, 8, 10551396, 0, 10551397]
ip=10, [14068556, 10551393, 9, 10551396, 1, 10551397]
ip=12, [14068556, 10551393, 11, 10551396, 1, 10551397]
ip=13, [14068556, 10551394, 12, 10551396, 1, 10551397]
ip=14, [14068556, 10551394, 13, 10551396, 0, 10551397]
ip=15, [14068556, 10551394, 14, 10551396, 0, 10551397]
ip=2, [14068556, 10551394, 1, 10551396, 0, 10551397]
ip=3, [14068556, 10551394, 2, 10551396, 0, 1]
ip=4, [14068556, 10551394, 3, 10551396, 10551394, 1]
ip=5, [14068556, 10551394, 4, 10551396, 0, 1]
ip=6, [14068556, 10551394, 5, 10551396, 0, 1]
ip=8, [14068556, 10551394, 7, 10551396, 0, 1]
ip=9, [14068556, 10551394, 8, 10551396, 0, 10551397]
ip=10, [14068556, 10551394, 9, 10551396, 1, 10551397]
ip=12, [14068556, 10551394, 11, 10551396, 1, 10551397]
ip=13, [14068556, 10551395, 12, 10551396, 1, 10551397]
ip=14, [14068556, 10551395, 13, 10551396, 0, 10551397]
ip=15, [14068556, 10551395, 14, 10551396, 0, 10551397]
ip=2, [14068556, 10551395, 1, 10551396, 0, 10551397]
ip=3, [14068556, 10551395, 2, 10551396, 0, 1]
ip=4, [14068556, 10551395, 3, 10551396, 10551395, 1]
ip=5, [14068556, 10551395, 4, 10551396, 0, 1]
ip=6, [14068556, 10551395, 5, 10551396, 0, 1]
ip=8, [14068556, 10551395, 7, 10551396, 0, 1]
ip=9, [14068556, 10551395, 8, 10551396, 0, 10551397]
ip=10, [14068556, 10551395, 9, 10551396, 1, 10551397]
ip=12, [14068556, 10551395, 11, 10551396, 1, 10551397]
ip=13, [14068556, 10551396, 12, 10551396, 1, 10551397]
ip=14, [14068556, 10551396, 13, 10551396, 0, 10551397]
ip=15, [14068556, 10551396, 14, 10551396, 0, 10551397]
ip=2, [14068556, 10551396, 1, 10551396, 0, 10551397]
ip=3, [14068556, 10551396, 2, 10551396, 0, 1]
ip=4, [14068556, 10551396, 3, 10551396, 10551396, 1]
ip=5, [14068556, 10551396, 4, 10551396, 1, 1]
ip=7, [14068556, 10551396, 6, 10551396, 1, 1]
ip=8, [24619952, 10551396, 7, 10551396, 1, 1]
ip=9, [24619952, 10551396, 8, 10551396, 1, 10551397]
ip=10, [24619952, 10551396, 9, 10551396, 1, 10551397]
ip=12, [24619952, 10551396, 11, 10551396, 1, 10551397]
ip=13, [24619952, 10551397, 12, 10551396, 1, 10551397]
ip=14, [24619952, 10551397, 13, 10551396, 1, 10551397]
ip=16, [24619952, 10551397, 15, 10551396, 1, 10551397]
ip=257, [24619952, 10551397, 256, 10551396, 1, 10551397]
result is
*/
void output_19(int* rs, int pc)
{
    printf("ip=%d, [%d, %d, %d, %d, %d, %d] ", pc, rs[0], rs[1], rs[2], rs[3], rs[4], rs[5]);
}
void test()
{
    int ai = 0;
    // char** as = read_input("input_19", &ai);
    char** as = read_input("input_21", &ai);
    int ipr = 0;
    sscanf(as[0], "#ip %d", &ipr);
    int rs[6] = {0};

    int* programs = malloc(sizeof(int) * (ai - 1) * 4);

    int opc[16] = {
                   0 << 24 | 0 << 16 | 0 << 8 | 1, // addr
                   0 << 24 | 1 << 16 | 0 << 8 | 1, // addi
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 1, // mulr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 1, // muli
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 2, // banr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 2, // bani
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 3, // borr
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 3, // bori
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // setr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 4, // seti
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 5, // gtri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 5, // gtrr
                   1 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqir
                   0 << 24 | 1 << 16 | 0 << 8 | 1 << 6, // eqri
                   0 << 24 | 0 << 16 | 0 << 8 | 1 << 6, // eqrr
    };

    char* ops[16] = {
                     "addr", "addi", "mulr", "muli", "banr", "bani", "borr", "bori",
                     "setr", "seti", "gtir", "gtri", "gtrr", "eqir", "eqri", "eqrr",
    };


    for (int i = 1; i < ai; i ++)
    {
        int o1, o2, o3, o4;
        sscanf(as[i], "%*s %d %d %d", &o2, &o3, &o4);
        for (int j = 0; j < 16; j ++)
            if (!strncmp(as[i], ops[j], 4))
            {
                o1 = j;
                break;
            }
        programs[(i - 1) * 4] = o1;
        programs[(i - 1) * 4 + 1] = o2;
        programs[(i - 1) * 4 + 2] = o3;
        programs[(i - 1) * 4 + 3] = o4;
    }

    int pc = 0;
    // rs[0] = 1; for question 19
    while (pc < ai - 1)
    {
        // write pc to register ipr
        rs[ipr] = pc;

        output_19(rs, pc);
        int op = opc[programs[pc * 4]];
        int o1 = programs[pc * 4 + 1];
        int o2 = programs[pc * 4 + 2];
        int o3 = programs[pc * 4 + 3];

        printf(" %s %d %d %d ", ops[programs[pc * 4]], o1, o2, o3);

        int va = o1;

        if (!(op & 0xFF000000))
            va = rs[o1];

        int vb = o2;

        if (!(op & 0x00FF0000))
            vb = rs[o2];

        bool skip = false;

        /* for question 19
        if (pc == 8)
        {
            skip = true;
            if (!(rs[3] % rs[1]) && (rs[3] / rs[1]) > rs[5])
                rs[5] = rs[3] / rs[1];
            else
                rs[5] = rs[3] + 1;
        }
        */

        // for question 21
        if (pc == 24)
        {
            skip = true;
            rs[2] = rs[1] / 256;
        }

        if (!skip)
        switch (op & 0xFF)
        {
        case 1:
            rs[o3] = va + vb;
            break;
        case 1 << 1:
            rs[o3] = va * vb;
            break;
        case 1 << 2:
            rs[o3] = va & vb;
            break;
        case 1 << 3:
            rs[o3] = va | vb;
            break;
        case 1 << 4:
            rs[o3] = va;
            break;
        case 1 << 5:
            rs[o3] = va > vb ? 1 : 0;
            break;
        case 1 << 6:
            rs[o3] = va == vb ? 1 : 0;
            break;
        }

        pc = rs[ipr];
        pc ++;
        output_19(rs, pc);
        printf("\n");
    }
    // halt
    rs[ipr] = 0;
    printf("result is \n");
    output_19(rs, pc);
}

int test_21(int in, char* all)
{
    printf("in is %d.\n", in);

    if (all[in])
    {
        printf("same here.\n");
        for (int i = 0xFFFFFF; i >= 0; i --)
            if (all[i])
            {
                printf("last is %d.\n", i);
                break;
            }
        return 0;
    }

    all[in] = 1;
    int x1 = in | 65536;
    in = 2024736;
    int x2 = x1 & 0xFF;
    in += x2;
    in &= 0xFFFFFF;

    long x = ((long) in) * 65899;
    in = x & 0xFFFFFF;
    while (x1 > 256)
    {
        x2 = x1 / 256;
        x1 = x2;
        x2 = x1 & 0xFF;
        in += x2;
        in &= 0xFFFFFF;
        x = ((long) in) * 65899;
        in = x & 0xFFFFFF;
    }
    // printf("out x1 %d, in is %d.\n", x1, in);
    test_21(in, all);
}

void test()
{
    char* all = calloc(sizeof(char),  (16777215 + 1));
    test_21(7129803, all);
}

long update_nt(int ct, int nt, long ctime, long ntime)
{
    long c_t = (ctime >> 32) & 0xFFFF;
    long c_c = (ctime >> 16) & 0xFFFF;
    long c_n = (ctime) & 0xFFFF;

    long n_t = (ntime >> 32) & 0xFFFF;
    long n_c = (ntime >> 16) & 0xFFFF;
    long n_n = (ntime) & 0xFFFF;

    if (ct == 0 && nt == 0)
    {
        if (!n_t || n_t > c_t + 1)
            n_t = c_t + 1;
        if (!n_c || n_c > c_c + 1)
            n_c = c_c + 1;
    }
    else if (ct == 0 && nt == 1)
    {
        if (!n_c || n_c > c_c + 1)
            n_c = c_c + 1;
        if (!n_n || n_n > n_c + 7)
            n_n = n_c + 7;
    }
    else if (ct == 0 && nt == 2)
    {
        if (!n_t || n_t > c_t + 1)
            n_t = c_t + 1;
        if (!n_n || n_n > n_t + 7)
            n_n = n_t + 7;
    }
    else if (ct == 1 && nt == 0)
    {
        if (!n_c || n_c > c_c + 1)
            n_c = c_c + 1;
        if (!n_t || n_t > n_c + 7)
            n_t = n_c + 7;
    }
    else if (ct == 1 && nt == 1)
    {
        if (!n_c || n_c > c_c + 1)
            n_c = c_c + 1;
        if (!n_n || n_n > c_n + 1)
            n_n = c_n + 1;
    }
    else if (ct == 1 && nt == 2)
    {
        if (!n_n || n_n > c_n + 1)
            n_n = c_n + 1;
        if (!n_t || n_t > n_n + 7)
            n_t = n_n + 7;
    }
    else if (ct == 2 && nt == 0)
    {
        if (!n_t || n_t > c_t + 1)
            n_t = c_t + 1;
        if (!n_c || n_c > n_t + 7)
            n_c = n_t + 7;
    }
    else if (ct == 2 && nt == 1)
    {
        if (!n_n || n_n > c_n + 1)
            n_n = c_n + 1;
        if (!n_c || n_c > n_n + 7)
            n_c = n_n + 7;
    }
    else if (ct == 2 && nt == 2)
    {
        if (!n_t || n_t > c_t + 1)
            n_t = c_t + 1;
        if (!n_n || n_n > c_n + 1)
            n_n = c_n + 1;
    }

    if (nt == 0)
    {
        if (abs(n_t - n_c) > 7)
            printf("error here.\n");
    }
    else if (nt == 1)
    {
        if (abs(n_c - n_n) > 7)
            printf("error here.\n");
    }
    else
    {
        if (abs(n_t - n_n) > 7)
            printf("error here.\n");
    }

    return n_t << 32 | n_c << 16 | n_n;
}

// heap maybe easy !
// no need to use heap ????????
// use heap maybe easy here !!!!!!!!
// or just stacks, check all of status
// generate the map a little bit larger for take the short turns
void test()
{

    /* int depth = 510; */
    /* int tx = 10; */
    /* int ty = 10; */

    int depth = 8103;
    int tx = 9;
    int ty = 758;

    // may out of the border !!
    int mx = tx * 7;
    int my = ty * 7;

    int** c = malloc(sizeof(int*) * mx);

    for (int i = 0; i < mx; i ++)
    {
        c[i] = malloc(sizeof(int) * my);
        for (int j = 0; j < my; j ++)
        {
            if ((i == 0 && j == 0) || (i == tx && j == ty))
                c[i][j] = 0;
            else if (i == 0)
                c[i][j] = j * 48271;
            else if (j == 0)
                c[i][j] = i * 16807;
            else
                c[i][j] = ((c[i - 1][j] + depth) % 20183) * ((c[i][j - 1] + depth) % 20183);
        }
    }

    int risk = 0;

    for (int j = 0; j < my; j ++)
    {
        for (int i = 0; i < mx; i ++)
        {
            c[i][j] = ((c[i][j] + depth) % 20183) % 3;

            if (i <= tx && j <= ty)
                risk += c[i][j];
            /* if (t == 0) */
            /*     printf("."); */
            /* else if (t == 1) */
            /*     printf("="); */
            /* else */
            /*     printf("|"); */
        }
        // printf("\n");
    }

    printf("risk is %d.\n", risk);

    // torch << 32 | climbing << 16 | neither time
    long** time = malloc(sizeof(long*) * mx);
    for (int i = 0; i < mx; i ++)
        time[i] = calloc(sizeof(long), my);

    int si = 0;
    int ti = 0;
    int* s = malloc(sizeof(int) * mx * my);
    int* t = malloc(sizeof(int) * mx * my);

    if (c[0][0] == 0)
        time[0][0] = 1L << 32 | 8L << 16;
    else if (c[0][0] == 1)
        time[0][0] = 8L << 16 | 8L; // can not happen, must with torch
    else
        time[0][0] = 1L << 32 | 8L;

    s[si ++] = 0 << 16 | 0;

    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int x = (s[i] >> 16) & 0xFFFF;
            int y = s[i] & 0xFFFF;
            int ctype = c[x][y];
            long ctime = time[x][y];

            long ntime;

            if (x)
            {
                ntime = update_nt(ctype, c[x - 1][y], ctime, time[x - 1][y]);
                if (!time[x - 1][y] || ntime < time[x - 1][y])
                {
                    t[ti ++] = (x - 1) << 16 | y;
                    time[x - 1][y] = ntime;
                }
            }

            if (y)
            {
                ntime = update_nt(ctype, c[x][y - 1], ctime, time[x][y - 1]);
                if (!time[x][y - 1] || ntime < time[x][y - 1])
                {
                    t[ti ++] = x << 16 | y - 1;
                    time[x][y - 1] = ntime;
                }
            }

            if (x + 1 < mx)
            {
                ntime = update_nt(ctype, c[x + 1][y], ctime, time[x + 1][y]);
                if (!time[x + 1][y] || ntime < time[x + 1][y])
                {
                    t[ti ++] = (x + 1) << 16 | y;
                    time[x + 1][y] = ntime;
                }
            }

            if (y + 1 < my)
            {
                ntime = update_nt(ctype, c[x][y + 1], ctime, time[x][y + 1]);
                if (!time[x][y + 1] || ntime < time[x][y + 1])
                {
                    t[ti ++] = x << 16 | y + 1;
                    time[x][y + 1] = ntime;
                }
            }
        }

        si = ti;
        ti = 0;
        int* _t = t;
        t = s;
        s = _t;
    }

    long ret = time[tx][ty];
    printf("time %ld %d %d %d.\n", ret, ((ret >> 32) & 0xFFFF) - 1, ((ret >> 16) & 0xFFFF) - 1, (ret & 0xFFFF) - 1);
}

// find better solution here ???????? how to
// correct here, find the better solution for this one !!!
void test()
{
    int ai = 0;
    char** as = read_input("input_23", &ai);
    int* ps = malloc(sizeof(int) * ai * 4);
    int* sigs = malloc(sizeof(int) * ai);

    long maxx = INT_MIN;
    long maxy = INT_MIN;
    long maxz = INT_MIN;

    long minx = INT_MAX;
    long miny = INT_MAX;
    long minz = INT_MAX;

    for (int i = 0; i < ai; i ++)
    {
        int x, y, z, r;
        sscanf(as[i], "pos=<%d,%d,%d>, r=%d", &x, &y, &z, &r);

        if (x > maxx)
            maxx = x;
        if (x < minx)
            minx = x;

        if (y > maxy)
            maxy = y;
        if (y < miny)
            miny = y;

        if (z > maxz)
            maxz = z;
        if (z < minz)
            minz = z;

        ps[i * 4] = x;
        ps[i * 4 + 1] = y;
        ps[i * 4 + 2] = z;
        ps[i * 4 + 3] = r;
        sigs[i] = r;
    }

    int** dis = malloc(sizeof(int*) * ai);
    for (int i = 0; i < ai; i ++)
        dis[i] = calloc(sizeof(int), ai);
    int* nums = calloc(sizeof(int), ai);

    q_sort(sigs, 0, ai - 1);
    out(sigs, ai);

    int max = 0;

    for (int i = 0; i < ai; i ++)
        for (int j = i + 1; j < ai; j ++)
        {
            dis[j][i] = dis[i][j] = abs(ps[i * 4] - ps[j * 4]) + abs(ps[i * 4 + 1] - ps[j * 4 + 1]) + abs(ps[i * 4 + 2] - ps[j * 4 + 2]);

            if (dis[i][j] <= ps[i * 4 + 3])
                nums[i] ++;
            if (dis[j][i] <= ps[j * 4 + 3])
                nums[j] ++;

            if (nums[i] > max)
                max = nums[i];
            if (nums[j] > max)
                max = nums[j];
        }

    // out(nums, ai);
    printf("max is %d.\n", max + 1);

    for (int i = 0; i < ai; i ++)
        if (ps[i * 4 + 3] == sigs[ai - 1])
        {
            printf("%d. max %d\n", sigs[ai - 1], nums[i] + 1);
            break;
        }

    // printf("x %d %d y %d %d z %d %d.\n", minx, maxx, miny, maxy, minz, maxz);

    /* // test result */
    /* // 35365645 23312260 47645184 */
    /* int tx = 35365646; */
    /* int ty = 23312260; */
    /* int tz = 47645184; */
    /* int dt = 128f; */
    /* long dd = 0; */
    /* int dmax = INT_MIN; */
    /* int dx, dy, dz; */

    /* for (int x = tx - dt; x <= tx + dt; x ++) */
    /*     for (int y = ty - dt; y <= ty + dt; y ++) */
    /*         for (int z = tz - dt; z <= tz + dt; z ++) */
    /*         { */
    /*             int num = 0; */
    /*             for (int n = 0; n < ai; n ++) */
    /*             { */
    /*                 int d = abs(ps[n * 4] - x) + abs(ps[n * 4 + 1] - y) + abs(ps[n * 4 + 2] - z); */
    /*                 if (d <= ps[n * 4 + 3]) */
    /*                     num ++; */
    /*             } */

    /*             if (num > dmax || (num == dmax && dd > x + y + z)) */
    /*             { */
    /*                 dmax = num; */
    /*                 dd = x + y + z; */
    /*                 dx = x; */
    /*                 dy = y; */
    /*                 dz = z; */
    /*             } */
    /*         } */

    /* printf("dmax %d dd %d, x %d y %d z %d.\n", dmax, dd, dx, dy, dz); */
    /* return; */

    int si = 0;
    int ti = 0;

    int* s = malloc(sizeof(int) * 102400000 * 6);
    int* t = malloc(sizeof(int) * 102400000 * 6);

    long gx = (maxx - minx) / 32;
    long gy = (maxy - miny) / 32;
    long gz = (maxz - minz) / 32;

    s[si ++] = minx;
    s[si ++] = maxx;
    s[si ++] = miny;
    s[si ++] = maxy;
    s[si ++] = minz;
    s[si ++] = maxz;

    int temp_i = 0;
    int* tnum = malloc(sizeof(int) * 102400000);
    int* temp = malloc(sizeof(int) * 102400000 * 3);

    int num_max = INT_MIN;

    while (si)
    {
        printf("si is %d %d %d %d %d.\n", si, num_max, gx, gy, gz);
        num_max = INT_MIN;

        for (int i = 0; i < si; i += 6)
        {
            int lx = s[i];
            int rx = s[i + 1];
            int ly = s[i + 2];
            int ry = s[i + 3];
            int lz = s[i + 4];
            int rz = s[i + 5];
            temp_i = 0;

            for (int _x = lx; _x < rx; _x += gx)
                for (int _y = ly; _y < ry; _y += gy)
                    for (int _z = lz; _z < rz; _z += gz)
                    {
                        int num = 0;
                        for (int n = 0; n < ai; n ++)
                        {
                            int d = abs(ps[n * 4] - _x) + abs(ps[n * 4 + 1] - _y) + abs(ps[n * 4 + 2] - _z);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x) + abs(ps[n * 4 + 1] - _y) + abs(ps[n * 4 + 2] - _z - gz);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x) + abs(ps[n * 4 + 1] - _y - gy) + abs(ps[n * 4 + 2] - _z);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x) + abs(ps[n * 4 + 1] - _y - gy) + abs(ps[n * 4 + 2] - _z - gz);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x - gx) + abs(ps[n * 4 + 1] - _y) + abs(ps[n * 4 + 2] - _z);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x - gx) + abs(ps[n * 4 + 1] - _y) + abs(ps[n * 4 + 2] - _z - gz);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x - gx) + abs(ps[n * 4 + 1] - _y - gy) + abs(ps[n * 4 + 2] - _z);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                            d = abs(ps[n * 4] - _x - gx) + abs(ps[n * 4 + 1] - _y - gy) + abs(ps[n * 4 + 2] - _z - gz);
                            if (d <= ps[n * 4 + 3])
                            {
                                num ++;
                                continue;
                            }

                        }
                        temp[temp_i * 3] = _x;
                        temp[temp_i * 3 + 1] = _y;
                        temp[temp_i * 3 + 2] = _z;
                        tnum[temp_i ++] = num;
                    }

            int temp_max = INT_MIN;
            for (int i = 0; i < temp_i; i ++)
                if (temp_max < tnum[i])
                    temp_max = tnum[i];

            if (num_max < temp_max)
            {
                num_max = temp_max;

                for (int i = 0; i < temp_i; i ++)
                    if (tnum[i] == temp_max)
                    {
                        t[ti] = temp[i * 3];
                        t[ti + 1] = temp[i * 3] + gx;
                        t[ti + 2] = temp[i * 3 + 1];
                        t[ti + 3] = temp[i * 3 + 1] + gy;
                        t[ti + 4] = temp[i * 3 + 2];
                        t[ti + 5] = temp[i * 3 + 2] + gz;
                        ti += 6;
                    }
            }

            /* q_sort(tnum, 0, temp_i - 1); */
            /* out(tnum, temp_i); */
            /* getchar(); */
        }

        if (gx == 1 && gy == 1 && gz == 1)
        {
            printf("result is here.\n====\n");
            out(temp, temp_i * 3);
            break;
        }

        gx /= 2;
        gy /= 2;
        gz /= 2;

        if (!gx)
            gx = 1;
        if (!gy)
            gy = 1;
        if (!gz)
            gz = 1;

        si = ti;
        ti = 0;
        int* _t = t;
        t = s;
        s = _t;
    }
}

#define WEAK_OFFSET 5
#define IMMUNE_OFFSET 10

int _type(char* in)
{
    // bludgeoning 1 << 0
    // cold 1 << 1
    // fire 1 << 2
    // radiation 1 << 3
    // slashing 1 << 4

    char* all[] = {
                    "bludgeoning",
                    "cold",
                    "fire",
                    "radiation",
                    "slashing",
    };

    for (int i = 0; i < sizeof(all)/sizeof(all[0]); i ++)
        if (!strncmp(in, all[i], strlen(all[i])))
            return 1 << i;
}


void output_unit(long u)
{
    int initiative = (u >> 56) & 0xFF;
    int utype = (u >> 40) & 0xFFFF;
    int attack = (u >> 32) & 0xFF;
    int num = (u >> 16) & 0xFFFF;
    int hp = u & 0xFFFF;


    printf("initiative %d num %d hp %d attack %d ", initiative, num, hp, attack);

    char* all[] = {
                    "bludgeoning",
                    "cold",
                    "fire",
                    "radiation",
                    "slashing",
    };

    char* type[] = {
                    "attack",
                    "weak",
                    "immune",
    };

    for (int i = 0; i < 15; i += 5)
    {
        printf("%s :", type[i / 5]);

        for (int j = 0; j < sizeof(all)/sizeof(all[0]); j ++)
            if (utype & (1 << (i + j)))
                printf("%s ", all[j]);
        printf(". ");
    }

    printf("\n");
}

void target(long* attack, int ai, long* defend, int di, int* t, int aboost, int dboost)
{
    int ti = 0;
    long* temp = calloc(sizeof(long), 256);

    long power = 0;
    long init = 0;

    int* used = calloc(sizeof(int), di);

    for (int i = 0; i < ai; i ++)
    {
        t[i] = -1;
        long a = attack[i];
        if ((a >> 16) & 0xFFFF)
        {
            power = ((a >> 16) & 0xFFFF) * (((a >> 32) & 0xFF) + aboost);
            init = (a >> 56) & 0xFF;
            temp[ti ++] = power << 32 | init << 16 | i;
        }
    }

    qsort(temp, ti, sizeof(long), comp_long);

    for (int i = ti - 1; i >= 0; i --)
    {
        int id = temp[i] & 0xFFFF;

        int power = (temp[i] >> 32) & 0xFFFFFFFF;
        int a_type = (attack[id] >> 40) & 0x1F;

        int max_damage = INT_MIN;
        int max_d = -1;
        int max_init;
        int max_power;

        for (int j = 0; j < di; j ++)
        {
            if (used[j])
                continue;

            long d = defend[j];
            if ((d >> 16) & 0xFFFF)
            {
                int d_power = ((d >> 16) & 0xFFFF) * (((d >> 32) & 0xFF) + dboost);
                int d_weak = (d >> 40 >> WEAK_OFFSET) & 0x1F;
                int d_immune = (d >> 40 >> IMMUNE_OFFSET) & 0x1F;
                int d_init = (d >> 56) & 0xFF;

                if (a_type & d_immune)
                    continue;

                int damage = power;

                if (a_type & d_weak)
                    damage *= 2;

                if (damage > max_damage || (damage == max_damage && d_power > max_power)
                    || (damage == max_damage && d_power == max_power && d_init > max_init))
                {
                    // printf("attack %d do defend %d %d %d\n", damage, max_damage, d_power, max_power);
                    max_d = j;
                    max_damage = damage;
                    max_init = d_init;
                    max_power = d_power;
                }
            }
        }

        if (max_d != -1)
            used[max_d] = 1;
        t[id] = max_d;
    }
}

long attack(long attack, long defend, int boost)
{
    long damage = ((attack >> 16) & 0xFFFF) * (((attack >> 32) & 0xFF) + boost);

    if (damage == 0)
    {
        // printf("ERROR here. %d.\n", ((attack >> 16)) & 0xFFFF);
        return defend;
    }

    long type = (attack >> 40) & 0x1F;

    long num = (defend >> 16) & 0xFFFF;
    long immune = (defend >> 40 >> IMMUNE_OFFSET) & 0x1F;
    long weak = (defend >> 40 >> WEAK_OFFSET) & 0x1F;
    long hp = (defend) & 0xFFFF;

    if (type & weak)
        damage *= 2;

    long kill = damage / hp;

    if (kill >= num)
        defend &= 0xFFFFFFFF0000FFFFL;
    else
        defend -= kill << 16;

    return defend;
}

// manually create group
// write code the parse the input
// just write the code and be careful !!!!
// remember qsort sequences !!
// just be more careful !!!!
// change to structure !!!
// just coding !!!!
// boost immune
// simple binary search
void test()
{

    int ai = 0;
    char** as = read_input("input_24", &ai);

    int im_i = 0;
    long* o_immunes = calloc(sizeof(long), ai);
    int in_i = 0;
    long* o_infects = calloc(sizeof(long), ai);

    int* in;
    long* t;

    for (int i = 0; i < ai; i ++)
    {
        if (!strncmp(as[i], "Infection:", strlen("Infection:")))
        {
            in_i = 0;
            t = o_infects;
             in = &in_i;
            continue;
        }
        else if (!strncmp(as[i], "Immune System:", strlen("Immune System:")))
        {
            im_i = 0;
            t = o_immunes;
            in = &im_i;
            continue;
        }
        else if (strlen(as[i]) > 30)
        {
            char* weak_or_immune = strchr(as[i], '(');
            int initiative = 0;
            int num = 0;
            int hp = 0;
            int attack = 0;
            char* type = malloc(256);

            if (weak_or_immune)
            {
                weak_or_immune = malloc(256);
                sscanf(as[i], "%d units each with %d hit points (%[^)]) with an attack that does %d %s damage at initiative %d",
                       &num, &hp, weak_or_immune, &attack, type, &initiative);
            }
            else
            {
                weak_or_immune = NULL;
                sscanf(as[i], "%d units each with %d hit points with an attack that does %d %s damage at initiative %d",
                       &num, &hp, &attack, type, &initiative);
            }
            // printf("%s %d %d %d %d %s %s.\n", as[i], initiative, num, hp, attack, type, weak_or_immune ? weak_or_immune : "NONE");

            int w_or_i = 0;
            int attack_type = _type(type);

            free(type);
            type = NULL;

            if (weak_or_immune)
                type = strchr(weak_or_immune, ';');

            if (!type)
                type = weak_or_immune;
            if (type)
            {
                int offset;

                if (strstr(type, "weak"))
                    offset = WEAK_OFFSET;
                else
                    offset = IMMUNE_OFFSET;

                char* all[] = {
                               "bludgeoning",
                               "cold",
                               "fire",
                               "radiation",
                               "slashing",
                };

                for (int i = 0; i < sizeof(all)/sizeof(all[0]); i ++)
                    if (strstr(type, all[i]))
                        w_or_i |= _type(all[i]) << offset;

                if (weak_or_immune && type != weak_or_immune)
                {
                    type = weak_or_immune;

                    offset = offset == WEAK_OFFSET ? IMMUNE_OFFSET : WEAK_OFFSET;
                    for (int i = 0; i < sizeof(all)/sizeof(all[0]); i ++)
                        if (strstr(type, all[i]))
                        {
                            int t = _type(all[i]);
                            if (!(w_or_i & (t << WEAK_OFFSET)) && !(w_or_i & (t << IMMUNE_OFFSET)))
                                w_or_i |= t << offset;
                        }
                }
            }

            long u = ((long) initiative) << 56 | ((long) (attack_type | w_or_i)) << 40 | ((long) attack) << 32 | ((long) num) << 16 | (long) hp;

            t[*in] = u;
            *in = *in + 1;
        }
    }

    /*
    for (int i = 0; i < in_i; i ++)
        output_unit(infects[i]);
    printf("======= \n");
    for (int i = 0; i < im_i; i ++)
        output_unit(immunes[i]);
    */

    int* turns = malloc(sizeof(int) * (in_i + im_i));
    // in is 0, im i 1
    for (int i = 0; i < in_i + im_i; i ++)
    {
        if (i < in_i)
            turns[i] = (((o_infects[i] >> 56) & 0xFF) << 16) | i << 8 | 0;
        else
            turns[i] = (((o_immunes[i - in_i] >> 56) & 0xFF) << 16) | (i - in_i) << 8 | 1;
    }

    q_sort(turns, 0, in_i + im_i - 1);

    int* in_t = calloc(sizeof(int), in_i);
    int* im_t = calloc(sizeof(int), im_i);

    // simple binary search here

    int boost_s = 0;
    int boost_e = 10240;

    long* immunes = calloc(sizeof(long), ai);
    long* infects = calloc(sizeof(long), ai);


    while (boost_s < boost_e)
    {
        int left = 0;
        int boost_m = 57;//(boost_s + boost_e) / 2;

        memcpy(immunes, o_immunes, sizeof(long) * im_i);
        memcpy(infects, o_infects, sizeof(long) * in_i);

        int pre_in_num = INT_MIN;
        int pre_im_num = INT_MIN;

        while(true)
        {
            target(infects, in_i, immunes, im_i, in_t, 0, boost_m);
            target(immunes, im_i, infects, in_i, im_t, boost_m, 0);

            /* out(in_t, in_i); */
            /* out(im_t, im_i); */

            // attack
            for (int i = in_i + im_i - 1; i >= 0; i --)
            {
                int a = turns[i];
                int id = (a >> 8) & 0xFF;

                // immunes
                if (a & 1)
                {
                    if (im_t[id] != -1)
                    {
                        // printf("Immune %d attack Infects %d.\n", id + 1, im_t[id] + 1);
                        infects[im_t[id]] = attack(immunes[id], infects[im_t[id]], boost_m);
                    }
                }
                else
                {
                    if (in_t[id] != -1)
                    {
                        // printf("Infects %d attack Immune %d.\n", id + 1, in_t[id] + 1);
                        immunes[in_t[id]] = attack(infects[id], immunes[in_t[id]], 0);
                    }
                }

            }

            int in_num = 0;
            for (int i = 0; i < in_i; i ++)
                if ((infects[i] >> 16) & 0xFFFF)
                    in_num += (infects[i] >> 16) & 0xFFFF;

            int im_num = 0;
            for (int i = 0; i < im_i; i ++)
                if ((immunes[i] >> 16) & 0xFFFF)
                    im_num += (immunes[i] >> 16) & 0xFFFF;

            printf("in_num %d, im_num %d %d %d %d\n", in_num, im_num, boost_m, boost_s, boost_m);

            if (!in_num || !im_num)
            {
                if (in_num)
                    left = - in_num;
                else
                    left = im_num;
                // printf("at last is %d.\n", in_num + im_num);
                break;
            }
            else if (in_num == pre_in_num && im_num == pre_im_num)
            {
                left = -1;
                break;
            }

            pre_in_num = in_num;
            pre_im_num = im_num;
            // getchar();
        }

        printf("%d %d %d %d.\n", boost_s, boost_m, boost_e, left);
        if (left >= 0)
            boost_e = boost_m;
        else
            boost_s = boost_m + 1;

        break;
    }

    printf("boost is %d %d.\n", boost_s, boost_e);
}
#endif

// just simple merge like leetcode ?
void test()
{
    int ai = 0;
    char** as = read_input("input_25", &ai);

    int* all = malloc(sizeof(int) * ai * 4);

    for (int i = 0; i < ai; i ++)
        sscanf(as[i], "%d,%d,%d,%d", &all[i * 4], &all[i * 4  +1], &all[i * 4 + 2], &all[i * 4 + 3]);

    int id = 0;
    int* ids = malloc(sizeof(int) * ai);

    int* t = malloc(sizeof(int) * ai);

    for (int i = 0; i < ai; i ++)
    {
        int ti = 0;
        for (int j = 0; j < i; j ++)
        {
            int d = abs(all[i * 4] - all[j * 4]) +
                abs(all[i * 4 + 1] - all[j * 4 + 1]) +
                abs(all[i * 4 + 2] - all[j * 4 + 2]) +
                abs(all[i * 4 + 3] - all[j * 4 + 3]);

            if (d <= 3)
                t[ti ++] = ids[j];
        }

        if (!ti)
            ids[i] = id ++;
        else
        {
            ids[i] = t[0];
            if (ti > 1)
            {
                for (int j = 0; j < i; j ++)
                    for (int k = 1; k < ti; k ++)
                        if (ids[j] == t[k])
                            ids[j] = t[0];
            }
        }
    }

    int* bits = calloc(sizeof(int), ai);

    int num = 0;
    for (int i = 0; i < ai; i ++)
        if (!bits[ids[i]])
        {
            bits[ids[i]] = 1;
            num ++;
        }
    printf("num is %d.\n", num);
}


int main(int argn, char** argv)
{
    srand(time(NULL));
    test();
}
