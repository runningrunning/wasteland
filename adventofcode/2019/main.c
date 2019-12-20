#include "../common.h"
// TODO Day 13 again !, it's simple AI can do what ever we want to !
// Day 14, find better ways, think toooo complicated, find better way and also the binary search algorithm
// Using other language
// FIND THE BETTER SOLUTION !
// PRACTISE MORE
// Day 16 is fun and tricky !
// Day 17 find better way !

// be careful here, it MUST be with &0xFFFFFFFF
// (x & 0xFFFFFFFF) << 32 | (y&0xFFFFFFFF); != x << 32 | y

#define LENGTH(o) sizeof(o)/sizeof(o[0])
#define INTCODE_MEMORY 20480

long gcd(long x, long y)
{
    if (!x || !y)
        return x + y;
    return x > y ? gcd(y, x % y) : gcd(x, y % x);
}

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

void paint_area(int** a, int r, int c)
{
    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
            printf("%c", a[i][j]);
        printf("\n");
    }
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

typedef long (*inputCB)();
typedef void (*outputCB)(long);

void output_print(long in)
{
    printf("%ld, ", in);
}

long input()
{
    printf("need input.\n");
    return 0;
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
            {
                int _in = input_cb();
                // printf("input is %d.\n", _in);
                assign(p1, a[s + 1], base, memory, _in);
            }
            s += 2;
            break;
        case 4:
            if (output_cb)
            {
                int _out = value(p1, a[s + 1], base, memory);
                // printf("ouput is %d.\n", _out);
                output_cb(_out);
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

#if 0
typedef struct {
    int goal_type;
    int goal_num;
    int recipe_num;
    int* item_type;
    int* item_num;
} Recipe;

int get_type(char* s, int n)
{
    int x = 0;
    for (int i = n - 1; i >= 0; i --)
        x = x * 27 + s[i] - 'A' + 1;
    return x;
}

void get_name(char* s, int t)
{
    int i = 0;
    do {
        s[i ++] = 'A' + (t % 27) - 1;
        t /= 27;
    } while(t);
    s[i] = 0;
}

void read_one_recipe(Recipe* r, char* s)
{
    int i = 0;

    bool item = true;

    while (s[i] && s[i] != '\n')
    {
        if (s[i] == '=')
        {
            i ++;
            i ++;
            i ++;
            item = false;
            continue;
        }

        int n = 0;

        while (s[i] >= '0' && s[i] <= '9')
            n = n * 10 + s[i ++] - '0';

        // skip ' '
        s[i ++];

        int ss = i;
        while (s[i] >= 'A' && s[i] <= 'Z')
            i ++;

        int t = get_type(s + ss, i - ss);

        if (s[i] == ',')
            s[i ++];

        if (s[i] == ' ')
            s[i ++];

        if (item)
        {
            r->item_type = realloc(r->item_type, sizeof(int) * (r->recipe_num + 1));
            r->item_num = realloc(r->item_num, sizeof(int) * (r->recipe_num + 1));
            r->item_type[r->recipe_num] = t;
            r->item_num[r->recipe_num] = n;
            r->recipe_num ++;
        }
        else
        {
            r->goal_type = t;
            r->goal_num = n;
        }
    }
}

void print_recipe(Recipe* r)
{
    char c[128];

    get_name(c, r->goal_type);
    printf("%d %s => ", r->goal_num, c);

    for (int i = 0; i < r->recipe_num; i ++)
    {
        get_name(c, r->item_type[i]);
        printf("%d %s, ", r->item_num[i], c);
    }
    printf("\n");
}

void print_recipe2(long* r, int n)
{
    char c[128];

    for (int i = 0; i < n; i ++)
    {
        get_name(c, r[i] & 0xFFFFFFFF);
        printf("%d %s, ", r[i] >> 32, c);
    }
    printf("\n");
}

void print_recipe3(long* r, int* t, int n)
{
    char c[128];

    for (int i = 0; i < n; i ++)
    {
        get_name(c, t[i]);
        printf("%d %s, ", r[i], c);
    }
    printf("\n");
}

int need_ore(int n, int t, Recipe** rs, int* rn, Recipe** ors, int on)
{
    int ore_type = get_type("ORE", 3);
    char name[64];
    get_name(name, t);

    if (t == ore_type)
        return n;

    int num = 0;

    for (int i = 0; i < *rn; i ++)
    {
        if (rs[i]->goal_type == t)
        {
            num = ((n + rs[i]->goal_num - 1) / rs[i]->goal_num) * rs[i]->recipe_num;
            printf("%d for %d %s.\n", num, n, name);
            return num;
        }
    }

    for (int i = 0; i < on; i ++)
    {
        if (ors[i]->goal_type == t)
        {
            for (int j = 0; j < ors[i]->recipe_num; j ++)
                num += need_ore(ors[i]->item_num[j], ors[i]->item_type[j], rs, rn, ors, on);

            rs[*rn] = malloc(sizeof(Recipe));
            rs[*rn]->goal_type = t;
            rs[*rn]->goal_num = ors[i]->goal_num;
            rs[*rn]->recipe_num = num;
            (*rn) ++;
            num = ((n + ors[i]->goal_num - 1) / ors[i]->goal_num) * num;
            printf("%d for %d %s.\n", num, n, name);
            return num;
        }
    }
    printf("error here %d %s.\n", n, name);
    return 0;
}

bool is_part_of(int ct, int pt, Recipe**rs, int rn)
{
    if (ct == pt)
        return true;

    for (int i = 0; i < rn; i ++)
    {
        if (rs[i]->goal_type == pt)
        {
            for (int j = 0; j < rs[i]->recipe_num; j ++)
                if (is_part_of(ct, rs[i]->item_type[j], rs, rn))
                    return true;
        }
    }

    return false;
}

int recipe_of(int n, int t, long* temp, Recipe** rs, int rn, bool extra)
{
    for (int i = 0; i < rn; i ++)
    {
        if (rs[i]->goal_type == t)
        {
            if (extra || !(n % rs[i]->goal_num))
            {
                int mul = ((n + rs[i]->goal_num - 1) / rs[i]->goal_num);
                for (int j = 0; j < rs[i]->recipe_num; j ++)
                    temp[j] = ((long)rs[i]->item_num[j] * mul) << 32 | rs[i]->item_type[j];
                return rs[i]->recipe_num;
            }
        }
    }
    return 0;
}

int recipe_of_2(long n, int t, long* temp, int* types, Recipe** rs, int rn, bool extra)
{
    for (int i = 0; i < rn; i ++)
    {
        if (rs[i]->goal_type == t)
        {
            if (extra || !(n % rs[i]->goal_num))
            {
                long mul = ((n + rs[i]->goal_num - 1) / rs[i]->goal_num);
                for (int j = 0; j < rs[i]->recipe_num; j ++)
                {
                    temp[j] = ((long)rs[i]->item_num[j] * mul);
                    types[j] = rs[i]->item_type[j];
                }
                return rs[i]->recipe_num;
            }
        }
    }
    return 0;
}

long num_of_ore(long need, Recipe** rs, int rn)
{
    Recipe* fule;
    int fule_type = get_type("FUEL", 4);

    for (int i = 0; i < rn; i ++)
    {
        if (rs[i]->goal_type == fule_type)
        {
            fule = rs[i];
            break;
        }
    }

    int si = fule->recipe_num;
    int ni = 0;

    long* sa = malloc(sizeof(long) * 1024);
    long* sb = malloc(sizeof(long) * 1024);

    int* ta = malloc(sizeof(int) * 1024);
    int* tb = malloc(sizeof(int) * 1024);

    for (int i = 0; i < si; i ++)
    {
        sa[i] = fule->item_num[i] * need;
        ta[i] = fule->item_type[i];
    }

    long* st = sa;
    int* stt = ta;
    long* nx = sb;
    int* nxt = tb;

    bool found = true;

    long* temp = malloc(sizeof(long) * 1024);
    int* temp_type = malloc(sizeof(int) * 1024);

    char name[1024];
    // print_recipe3(st, stt, si);

    while (found)
    {
        found = false;
        for (int i = 0; i < si; i ++)
        {
            long n = st[i];
            int t = stt[i];

            bool is_part = false;
            for (int j = 0; j < ni; j ++)
            {
                if (is_part_of(t, nxt[j], rs, rn))
                {
                    is_part = true;
                    break;
                }
            }

            if (!is_part)
            {
                for (int j = i + 1; j < si; j ++)
                {
                    if (is_part_of(t, stt[j], rs, rn))
                    {
                        is_part = true;
                        break;
                    }
                }
            }

            int f = recipe_of_2(n, t, temp, temp_type, rs, rn, !is_part);
            if (f)
                found = true;
            else
            {
                temp[f] = st[i];
                temp_type[f ++] = stt[i];
            }
            get_name(name, t);

            // printf("n %d t %d %s f %d.\n", n, t, name, f);
            for (int j = 0; j < f; j ++)
            {
                bool new = true;
                for (int k = 0; k < ni; k ++)
                {
                    if (nxt[k] == temp_type[j])
                    {
                        nx[k] += temp[j];
                        new = false;
                    }
                }

                if (new)
                {
                    nx[ni] = temp[j];
                    nxt[ni ++] = temp_type[j];
                }
            }

        }
        st = st == sa ? sb : sa;
        stt = stt == ta ? tb : ta;
        nx = nx == sa ? sb : sa;
        nxt = nxt == ta ? tb : ta;
        si = ni;
        ni = 0;

        // print_recipe3(st, stt, si);
        // getchar();
    }

    printf("%ld.\n", st[0]);
    return st[0];
}

void optimize_fuel_recipe(Recipe** rs, int rn)
{
    Recipe* fule;
    int fule_type = get_type("FUEL", 4);

    for (int i = 0; i < rn; i ++)
    {
        if (rs[i]->goal_type == fule_type)
        {
            fule = rs[i];
            break;
        }
    }

    int si = fule->recipe_num;
    int ni = 0;

    long* sa = malloc(sizeof(long) * 1024);
    long* sb = malloc(sizeof(long) * 1024);

    for (int i = 0; i < si; i ++)
        sa[i] = ((long) fule->item_num[i]) << 32 | fule->item_type[i];

    long* st = sa;
    long* nx = sb;

    bool found = true;

    long* temp = malloc(sizeof(long) * 1024);
    char name[64];

    while(found)
    {
        found = false;

        for (int i = 0; i < si; i ++)
        {
            long n = (st[i] >> 32) & 0xFFFFFFFF;
            long t = st[i] & 0xFFFFFFFF;

            bool is_part = false;
            for (int j = 0; j < ni; j ++)
                if (is_part_of(t, nx[j] & 0xFFFFFFFF, rs, rn))
                {
                    is_part = true;
                    break;
                }

            if (!is_part)
            {
                for (int j = i + 1; j < si; j ++)
                {
                    if (is_part_of(t, st[j] & 0xFFFFFFFF, rs, rn))
                    {
                        is_part = true;
                        break;
                    }
                }
            }

            int f = recipe_of(n, t, temp, rs, rn, !is_part);

            if (f)
                found = true;
            else
                temp[f ++] = st[i];
            get_name(name, t);

            printf("n %d t %d %s f %d.\n", n, t, name, f);
            // merge

            for (int j = 0; j < f; j ++)
            {
                bool new = true;
                for (int k = 0; k < ni; k ++)
                {
                    if ((nx[k] & 0xFFFFFFFF) == (temp[j] & 0xFFFFFFFF))
                    {
                        nx[k] += (temp[j] & 0xFFFFFFFF00000000);
                        new = false;
                    }
                }

                if (new)
                    nx[ni ++] = temp[j];
            }
        }
        st = st == sa ? sb : sa;
        nx = nx == sa ? sb : sa;
        si = ni;
        ni = 0;

        print_recipe2(st, si);
        getchar();
    }

    /*
    while(found)
    {
        found = false;
        for (int i = 0; i < si; i ++)
        {
            long n = (st[i] >> 32) & 0xFFFFFFFF;
            long t = st[i] & 0xFFFFFFFF;
            int f = recipe_of(n, t, temp, rs, rn, false);

            if (f)
                found = true;
            else
                temp[f ++] = st[i];
            get_name(name, t);

            printf("n %d t %d %s f %d.\n", n, t, name, f);
            // merge

            for (int j = 0; j < f; j ++)
            {
                bool new = true;
                for (int k = 0; k < ni; k ++)
                {
                    if ((nx[k] & 0xFFFFFFFF) == (temp[j] & 0xFFFFFFFF))
                    {
                        nx[k] += (temp[j] & 0xFFFFFFFF00000000);
                        new = false;
                    }
                }

                if (new)
                    nx[ni ++] = temp[j];
            }
        }
        st = st == sa ? sb : sa;
        nx = nx == sa ? sb : sa;
        si = ni;
        ni = 0;

        print_recipe2(st, si);
        getchar();
     }

    found = true;

    while(found)
    {
        for (int i = 0; i < si; i ++)
        {
            long n = st[i] >> 32;
            long t = st[i] & 0xFFFFFFFF;
            int f = recipe_of(n, t, temp, rs, rn, true);

            if (f)
                found = true;
            else
                temp[f ++] = st[i];

            printf("n %d t %d f %d.\n", n, t, f);
            // merge

            for (int j = 0; j < f; j ++)
            {
                bool new = true;
                for (int k = 0; k < ni; k ++)
                {
                    if ((nx[k] & 0xFFFFFFFF) == (temp[j] & 0xFFFFFFFF))
                    {
                        nx[k] += (temp[j] & 0xFFFFFFFF00000000);
                        new = false;
                    }
                }

                if (new)
                    nx[ni ++] = temp[j];
            }
        }
        st = st == sa ? sb : sa;
        nx = nx == sa ? sb : sa;
        si = ni;
        ni = 0;
        print_recipe2(nx, ni);
        getchar();
     }
    */
}

void test()
{
    int ai = 0;
    char** as = read_input("input_14", &ai);

    Recipe** rs = malloc(sizeof(Recipe*) * ai);
    for (int i = 0; i < ai; i ++)
    {
        Recipe* r = malloc(sizeof(Recipe));
        rs[i] = r;
        r->goal_type = 0;
        r->goal_num = 0;
        r->recipe_num = 0;
        r->item_type = NULL;
        r->item_num = NULL;
        read_one_recipe(r, as[i]);
        // printf("%s", as[i]);
        // print_recipe(r);
    }

    int rs_ore_num = 0;
    Recipe** rs_ore = malloc(sizeof(Recipe*) * ai);

    int type = get_type("FUEL", 4);
    // optimize_fuel_recipe(rs, ai);
    num_of_ore(1, rs, ai);
    // int fuel = need_ore(1, type, rs_ore, &rs_ore_num, rs, ai);
    // printf("it's %d.\n", fuel);

    long x = 1000000000000;
    int s = 500;
    int e = 92892753;

    while (s < e)
    {
        long m = e - (e - s) / 2;
        long need = num_of_ore(m, rs, ai);

        if (need > x)
            e = m - 1;
        else
            s = m;
    }
    printf("%d.\n", s);
}

#define AREA_C 512
#define AREA_R 512

int r;
int c;
int** area;

bool has_result;
int min;

int x;
int y;

int px;
int py;

int ox;
int oy;

int si;
int* stack;

int min_x;
int max_x;
int min_y;
int max_y;

//
//
//       N
//     W   E
//       S
//
//    Bottom left is, 0, 0, Right +x, Up +y

void output_my(long in)
{
    if (x < min_x)
        min_x = x;
    if (x > max_x)
        max_x = x;
    if (y < min_y)
        min_y = y;
    if (y > max_y)
        max_y = y;

    // printf("x %d y %d output is in %d.\n", x, y, in);
    if (in == 0)
    {
        area[x][y] = 1;
        x = px;
        y = py;
        si --;
    }
    else
    {

        if (!area[x][y] || (area[x][y] >> 16) > si)
            area[x][y] = (si << 16) | in + 1;

        if (in == 2)
        {
            if (si < min)
                min = si;
            ox = x;
            oy = y;

            for (int i = 0; i < AREA_R; i ++)
                memset(area[i], 0, sizeof(int) * AREA_C);
            area[x][y] = 1;
            si = 0;
            px = x;
            py = y;
            has_result = true;
        }
    }
}

bool will(int x, int y, int dx, int dy, int step)
{
    /* if (has_result && (step > min)) */
    /*     return false; */

    int next = area[x + dx][y + dy];

    if (!next)
        return true;

    if (next == 1)
        return false;

    if ((next >> 16) <= step)
        return false;

    return true;
}

long input_my()
{
    printf("x %d y %d input.\n", x, y);
    if (x == 0 || x == AREA_C - 1 || y == 0 || y == AREA_R - 1)
        printf("Error, Edge here si %d.\n", si);

    px = x;
    py = y;

    if (will(x, y, 0, 1, si + 1))
    {
        stack[si ++] = 1;
        y += 1;
        return 1;
    }
    else if (will(x, y, 0, -1, si + 1))
    {
        stack[si ++] = 2;
        y += -1;
        return 2;
    }
    else if (will(x, y, 1, 0, si + 1))
    {
        stack[si ++] = 3;
        x += 1;
        return 3;
    }
    else if (will(x, y, -1, 0, si + 1))
    {
        stack[si ++] = 4;
        x += -1;
        return 4;
    }
    else
    {
        int d = stack[-- si];
        if (si == 0)
        {
            printf("result is %d min_x %d min_y %d, max_x %d max_y %d\n", min, min_x, min_y, max_x, max_y);
            int max = INT_MIN;
            for (int i = 0; i < AREA_R; i ++)
                for (int j = 0; j < AREA_C; j ++)
                {
                    if (area[i][j] > 1)
                        if (max < (area[i][j] >> 16))
                            max = area[i][j] >> 16;
                }

            printf("step is %d.\n", max);
            exit(0);
        }
        switch(d)
        {
        case 1:
            y += -1;
            return 2;
        case 2:
            y += 1;
            return 1;
        case 3:
            x += -1;
            return 4;
        case 4:
            x += 1;
            return 3;
        }

    }
    printf("error input. si %d \n", si);
    return 0;
}

void test()
{
#include "input_15"

    r = AREA_R;
    c = AREA_C;
    area = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i ++)
        area[i] = calloc(sizeof(int), c);

    has_result = false;
    min = 65535;

    x = AREA_C / 2;
    y = AREA_R / 2;

    px = x;
    py = y;

    si = 0;
    stack = malloc(sizeof(int) * 20480);
    int l = LENGTH(m);

    area[x][y] = INT_MAX;
    min_x = min_y = INT_MAX;
    max_x = max_y = INT_MIN;
    intcode(m, l, INTCODE_MEMORY, input_my, output_my);

}

void test()
{
    int time = 10000;

    int ai = 0;
    char** as = read_input("input_16", &ai);
    char* s = as[0];
    int n = 0;

    while(s[n] >= '0' && s[n] <= '9')
        n ++;

    int* in = malloc(sizeof(int) * n);

    n = 0;

    while(s[n] >= '0' && s[n] <= '9')
    {
        in[n] = s[n] - '0';
        n ++;
    }

    int offset = 0;

    for (int i = 0; i < 7; i ++)
        offset = offset * 10 + in[i];

    int left = n * time - offset;

    int* last = malloc(sizeof(int) * left);

    int st = offset % n;

    for (int i = 0; i < left; i ++)
        last[i] = in[(st ++) % n];

    int* tmp = malloc(sizeof(int) * left);

    int* cur = last;
    int* nxt = tmp;

    int t = 0;

    while (t < 100)
    {
        memset(nxt, 0, sizeof(int) * left);

        int x = 0;
        for (int i = left - 1; i >= 0; i --)
        {
            x += cur[i];
            nxt[i] = x % 10;
        }

        cur = cur == last ? tmp : last;
        nxt = nxt == last ? tmp : last;

        t ++;
    }

    out(cur, left);

    // for (int i = 1; i < time; i ++)
    // {
    //     for (int j = 0; j < n; j ++)
    //         in[i * n + j] = in[j];
    // }

    // int* ou = malloc(sizeof(int) * n * time);

    // int p[] = {0, 1, 0, -1};

    // int t = 0;
    // int o = 1;
    // int pn = 1;
    // int pi = 0;

    // int* cur = in;
    // int* nxt = ou;

    // // out(cur, n * time);

    // while (t < 100)
    // {
    //     int st = 0;

    //     for (int i = 0; i < n * time; i ++)
    //     {
    //         int x = 0;
    //         int y = 0;
    //         int d = (n * time - st) / o;
    //         int z = st;
    //         int pi = 0;

    //         for (int j = 0; j < d; j ++)
    //         {
    //             y = (++ pi) % 4;

    //             int r = o;

    //             // printf("z %d, o %d y %d.\n", z, o, y);

    //             if (y == 0 || y == 2)
    //             {
    //                 z += o;
    //                 continue;
    //             }

    //             if (y == 1)
    //                 while(r --)
    //                     x += cur[z ++];
    //             else
    //                 while (r --)
    //                     x -= cur[z ++];
    //         }

    //         y = (++ pi) % 4;
    //         // printf("z is %d %d %d\n", z, y, x);
    //         if (y == 1)
    //             while (z < n * time)
    //                 x += cur[z ++];
    //         else if (y == 3)
    //             while(z < n * time)
    //                 x -= cur[z ++];

    //         // for (int j = st; j < n * time; j ++)
    //         // {
    //         //     x += p[pi % 4] * cur[j];
    //         //     if (!((pn ++) % o))
    //         //         pi ++;
    //         // }

    //         nxt[i] = abs(x) % 10;

    //         st ++;
    //         o ++;
    //     }

    //     // out(nxt, n * time);
    //     // getchar();

    //     cur = cur == in ? ou : in;
    //     nxt = nxt == in ? ou : in;

    //     t ++;
    //     o = 1;
    //     printf("t %d.\n", t);
    // }
    // out(cur, n * time);
}

// top left is 0, 0, right is +x, down is +y
int r = 0;
int c = 0;
int x = 0;
int y = 0;
int f = 0;

int cx = 0;
int cy = 0;
int** area;
int nums = 0;

// R,4,R,10,R,8,R,4
// R,10,R,6,R,4
// R,4,R,10,R,8,R,4
// R,10,R,6,R,4
// R,4,L,12,R,6,L,12
// R,10,R,6,R,4
// R,4,L,12,R,6,L,12
// R,4,R,10,R,8,R,4
// R,10,R,6,R,4
// R,4,L,12,R,6,L,12

int in = 5;
int in_i = 0;
int in_o = 0;

char* inputs[] =
{
 "A,B,A,B,C,B,C,A,B,C\n",
 "R,4,R,10,R,8,R,4\n",
 "R,10,R,6,R,4\n",
 "R,4,L,12,R,6,L,12\n",
 "n\n",
};

long input_my()
{
    if (in_i >= in)
        printf("error here.\n");
    if (inputs[in_i][in_o])
        return inputs[in_i][in_o ++];
    in_i ++;
    in_o = 0;
    return input_my();
}

void output_my(long out)
{
    if (out == '\n')
    {
        if (c < cx)
            c = cx;
        cy += 1;
        cx = 0;
    }
    else
    {
        if (out != '.' && out != '#')
        {
            x = cx;
            y = cy;
            f = out;
        }

        if (out == '#')
            nums ++;

        area[cy][cx ++] = (int) out;
    }
    r = cy;

    if (out > 256)
        printf("%d.\n", out);
}

int can(int x, int y, int f, int* v)
{
    int dx = 0;
    int dy = 0;

    if (f == '^')
        dy = -1;
    else if (f == '>')
        dx = 1;
    else if (f == 'v')
        dy = 1;
    else if (f == '<')
        dx = -1;

    int n = 0;

    x += dx;
    y += dy;

    int new = 0;

    // the first one can not be visited
    if (x >= 0 && x < c && y >= 0 && y < r && area[y][x] == '-')
        return 0;

    while (x >= 0 && x < c && y >= 0 && y < r && (area[y][x] == '#' || area[y][x] == '-'))
    {
        if (area[y][x] == '#')
            new ++;
        x += dx;
        y += dy;
        n ++;
    }

    *v = new;
    return n;
}

void do_visit(int x, int y, int f, int num)
{
    int dx = 0;
    int dy = 0;

    if (f == '^')
        dy = -1;
    else if (f == '>')
        dx = 1;
    else if (f == 'v')
        dy = 1;
    else if (f == '<')
        dx = -1;

    area[y][x] = '-';

    for (int i = 0; i < num; i ++)
    {
        x += dx;
        y += dy;
        area[y][x] = '-';
    }

    area[y][x] = f;
}

void paint_area()
{
    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
            printf("%c", area[i][j]);
        printf("\n");
    }
}

void test()
{
    #include "input_17"
    int l = LENGTH(m);
    int ml = INTCODE_MEMORY;

    area = malloc(sizeof(int*) * 256);
    for (int i = 0; i < 256; i ++)
        area[i] = malloc(sizeof(int) * 64);

    intcode(m, l, ml, input_my, output_my);

    // paint_area();

    // int si = 3;
    // int steps[512];
    // steps[0] = steps[1] = steps[2] = 0;

    // int visits = 0;
    // while (visits < nums)
    // {
    //     int v = 0;
    //     int n = 0;

    //     for (int i = 0; i < 4; i ++)
    //     {
    //         if (n = can(x, y, f, &v))
    //         {
    //             if (steps[si - 1] == (0 - 'R') && steps[si - 2] == (0 - 'R') && steps[si - 3] == (0 - 'R'))
    //             {
    //                 si -= 3;
    //                 steps[si ++] = 0 - 'L';
    //             }

    //             int tx = x;
    //             int ty = y;

    //             printf("f %c x %d y %d n %d\n", f, x, y, n);

    //             do_visit(tx, ty, f, n);

    //             steps[si ++] = n;

    //             if (f == '^')
    //                 y -= n;
    //             else if (f == '>')
    //                 x += n;
    //             else if (f == 'v')
    //                 y += n;
    //             else if (f == '<')
    //                 x -= n;
    //             else
    //                 printf("f is error %c.\n", f);
    //             visits += v;
    //             break;
    //         }
    //         else
    //         {
    //             steps[si ++] = 0 - 'R';
    //             if (f == '^')
    //                 f = '>';
    //             else if (f == '>')
    //                 f = 'v';
    //             else if (f == 'v')
    //                 f = '<';
    //             else if (f == '<')
    //                 f = '^';
    //             else
    //                 printf("f is error %c.\n", f);
    //             // printf("f is %c.\n", f);
    //         }
    //     }

    //     paint_area();
    //     // getchar();
    // }

    // for (int i = 3; i < si; i ++)
    // {
    //     if (steps[i] < 0)
    //         printf("%c,", abs(steps[i]));
    //     else
    //         printf("%d,", steps[i]);
    // }

    // printf("%d.\n", si - 3);
}

// void cal(char** a, int** f, int r, int c, char n, long** ds, int* st, int* nx)
// {
//     int di = n == '@' ? 0 : (n - 'a' + 1);
//     int need = n == '@' ? 'a' : (n + 1);

//     int x = 0;
//     int y = 0;

//     // clear visited path
//     for (int i = 0; i < r; i ++)
//     {
//         for (int j = 0; j < c; j ++)
//         {
//             if (a[i][j] == n)
//             {
//                 x = i;
//                 y = j;
//             }
//         }
//         memset(f[i], 0, sizeof(int) * c);
//     }

//     int si = 0;
//     int ni = 0;
//     int step = 1;
//     f[x][y] = step;

//     st[si ++] = x << 16 | y;

//     while (si)
//     {
//         for (int i = 0; i < si; i ++)
//         {
//             int x = st[i] >> 16;
//             int y = st[i] & 0xFFFF;

//             if (can(a, f, r, c, x - 1, y, step))
//                 nx[ni ++] = (x - 1) << 16 | y;

//             if (can(a, f, r, c, x + 1, y, step))
//                 nx[ni ++] = (x + 1) << 16 | y;

//             if (can(a, f, r, c, x, y - 1, step))
//                 nx[ni ++] = x << 16 | y - 1;

//             if (can(a, f, r, c, x, y + 1, step))
//                 nx[ni ++] = x << 16 | y + 1;
//         }
//     }
// }

bool key(char** a, int x, int y, int k)
{
    int n = a[x][y];
    if (n >= 'a' && n <= 'z')
    {
        int d = 1 << (n - 'a');
        return !(k & d);
    }
    return false;
}

bool can(char** a, int** f, int r, int c, int x, int y, int k)
{
    if (x < 0 || x >= r || y < 0 || y >= c || f[x][y])
        return false;

    int n = a[x][y];

    if (n == '#')
        return false;

    if (n >= 'A' && n <= 'Z')
    {
        int d = 1 << (n - 'A');
        return k & d;
    }
    return true;
}

int* caches;

void fun(char** a, int** f, int r, int c, int k, int x, int y, int n, int s, int* m, int* st, int* nx, int nk)
{
    if (s > *m)
        return;

    if (a[x][y] != '@')
        k |= 1 << (a[x][y] - 'a');

    int _ci = (a[x][y] == '@' ? 0 : (a[x][y]- 'a' + 1)) * 67108864 + k;

    if (caches[_ci] && s > (caches[_ci] - 1))
    {
        // printf("nk is %d.\n", nk);
        return;
    }

    caches[_ci] = s + 1;

    if (k == n)
    {
        if (s < *m)
        {
            printf("k %c s %d m %d cache %d.\n", a[x][y], s, *m, caches[_ci]);
            *m = s;
        }
        return;
    }

    // clear flag
    for (int i = 0; i < r; i ++)
        memset(f[i], 0, sizeof(int) * c);

    int ki = 0;
    long ks[26] = {0};

    // find how many keys we can get with steps

    int si = 0;
    int ni = 0;
    int step = 1;
    f[x][y] = INT_MAX;

    int* stack = st;
    int* next = nx;

    stack[si ++] = x << 16 | y;

    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int x = stack[i] >> 16;
            int y = stack[i] & 0xFFFF;

            if (key(a, x, y, k))
                ks[ki ++] = ((long) f[x][y]) << 32 | stack[i];

            if (can(a, f, r, c, x - 1, y, k))
            {
                f[x - 1][y] = step;
                next[ni ++] = (x - 1) << 16 | y;
            }

            if (can(a, f, r, c, x + 1, y, k))
            {
                f[x + 1][y] = step;
                next[ni ++] = (x + 1) << 16 | y;
            }

            if (can(a, f, r, c, x, y - 1, k))
            {
                f[x][y - 1] = step;
                next[ni ++] = x << 16 | y - 1;
            }

            if (can(a, f, r, c, x, y + 1, k))
            {
                f[x][y + 1] = step;
                next[ni ++] = x << 16 | y + 1;
            }
        }

        step ++;
        si = ni;
        ni = 0;

        stack = stack == st ? nx : st;
        next = next == st ? nx : st;
    }

    for (int i = 0; i < ki; i ++)
    {
        long will = ks[i];
        int _s = will >> 32;
        int _x = (will >> 16) & 0xFFFF;
        int _y = will & 0xFFFF;
        // printf("Got key %d k %d Found key %c .\n", nk, k, a[_x][_y]);
    }

    // apply each key
    for (int i = 0; i < ki; i ++)
    {
        long will = ks[i];
        int _s = will >> 32;
        int _x = (will >> 16) & 0xFFFF;
        int _y = will & 0xFFFF;
        fun(a, f, r, c, k, _x, _y, n, s + _s, m, st, nx, nk + 1);
    }
}

void test()
{
    int ai = 0;
    char** as = read_input("input_18", &ai);
    int r = ai;
    int c = strlen(as[0]);

    if (as[0][c - 1] == '\n')
        c = c - 1;

    // long** ds = malloc(sizeof(long*) * 27);
    // for (int i = 0; i < 26; i ++)
    //     ds[i] = calloc(sizeof(long), 27);

    caches = calloc(sizeof(int), 1811939328);

    int** area = malloc(sizeof(int*) * r);

    int x;
    int y;

    int need = 0;

    for (int i = 0; i < r; i ++)
    {
        area[i] = calloc(sizeof(int), c);
        for (int j = 0; j < c; j ++)
        {
            int a = as[i][j];

            if (a >= 'a' && a <= 'z')
                need |= 1 << (a - 'a');
            if (a == '@')
            {
                x = i;
                y = j;
            }
        }
    }

    int* st = malloc(sizeof(int) * r * c);
    int* nx = malloc(sizeof(int) * r * c);

    // // include @
    // for (int i = 0; i <= n; i ++)
    // {
    //     char need = i ? (i - 1 + 'a') : '@';
    // }

    int min = INT_MAX;
    int key = 0;

    fun(as, area, r, c, key, x, y, need, 0, &min, st, nx, 0);
    printf("min is %d.\n", min);
}

int max_x = 300;
int max_y = 300;

int pi = 0;
int cx = 0;
int cy = 0;

int num = 0;
long last = 0;

long input_my()
{
    return ((pi ++) % 2) ? cy : cx;
}

void output_my(long out)
{
    if (out)
        num ++;
    last = out;
}
void test()
{
    #include "input_19"
    int l = LENGTH(m);
    int ml = INTCODE_MEMORY;
    int pnum = 0;

    // for (int i = 0; i < max_y; i ++)
    // {
    //     for (int j = 0; j < max_x; j ++)
    //     {
    //         cx = j;
    //         cy = i;
    //         intcode(m, l, ml, input_my, output_my);
    //         printf("%c", last ? '#' : '.');
    //     }
    //     printf("\n");
    // }

    // test

    int ty = 160;
    int dx_min = 0, dx_max = 0;
    for (int j = 0; j < max_x; j ++)
    {
        cx = j;
        cy = ty;
        intcode(m, l, ml, input_my, output_my);
        if (last)
        {
            if (!dx_min)
                dx_min = j;
            dx_max =  j;
        }
    }

    printf("%d %d %d.\n", ty, dx_min, dx_max);

    int mx;
    int my = ty;
    int my_max = INT_MIN;

    for (int i = dx_min; i <= dx_max;  i ++)
    {
        int j = ty;
        while (true)
        {
            cx = i;
            cy = j;
            intcode(m, l, ml, input_my, output_my);
            if (!last)
            {
                if (j - ty >= dx_max - i + 1)
                {
                    if (dx_max - i + 1 > my_max)
                    {
                        mx = i;
                        my_max = dx_max - i + 1;
                        my = j - 1;
                    }
                }
                break;
            }
            j ++;
        }
    }

    int nx = mx * (100.0 / my_max);
    int ny = my * (100.0 / my_max);
    // printf("mx %d my %d my_max %d %d %d.\n", mx, my, my_max, nx, ny);

    for (int i = ny - 100; i < ny + 100; i ++)
        for (int j = nx - 100; j < nx + 100; j ++)
        {
            cx = j;
            cy = i;
            intcode(m, l, ml, input_my, output_my);
            if (!last)
                continue;

            cx = j + 99;
            intcode(m, l, ml, input_my, output_my);
            if (!last)
                continue;

            cx = j + 100;
            intcode(m, l, ml, input_my, output_my);
            if (last)
                continue;

            cx = j;

            cy = i + 99;
            intcode(m, l, ml, input_my, output_my);
            if (!last)
                continue;

            cy = i + 100;
            intcode(m, l, ml, input_my, output_my);
            if (last)
                continue;

            printf("x %d y %d.\n", j, i);
            exit(0);
        }
}
#endif

void test()
{
    int ai = 0;
    char** as = read_input("input_18", &ai);
    int r = ai;
    int c = strlen(as[0]);
}

int main(int argn, char** argv)
{
    srand(time(NULL));
    test();
}
