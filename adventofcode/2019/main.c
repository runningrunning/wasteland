#include "../common.h"
// TODO Day 13 again !, it's simple AI can do what ever we want to !
// Day 14, find better ways, think toooo complicated, find better way and also the binary search algorithm
// Using other language
// FIND THE BETTER SOLUTION !
// PRACTISE MORE

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

int main(int argn, char** argv)
{
    srand(time(NULL));
    test();
}
