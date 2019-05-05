// stupid my sort, i <= e !!!!!!!!!!!!!
// be careful and just write code
// write different code to handle this
// take idea from basic calculator III
// try another ways !!
// be patient
// design a structure, DESIGN
// how to represent this
// use c++ or java
// just like lisp calculation, just write code
// complicate code

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 1 (
// 2 +
// 3 -
// 4 *

struct Var
{
    int n;
    int a;
    int* v;
};

struct Exp
{
    int n;
    struct Var** v;
};

char* _conv(struct Var* v, char** vars)
{
    int ti = 0;
    char t[256] = {0};
    ti += sprintf(t + ti, "%d", v->a);

    for (int i = 0; i < v->n; i ++)
        ti += sprintf(t + ti, "*%s", vars[v->v[i]]);
    t[ti] = 0;
    return strdup(t);
}

int comp_v(struct Var* v1, struct Var* v2, int* seq)
{
    if (v1->n != v2->n)
        return v2->n - v1->n;

    for (int i = 0; i < v1->n; i ++)
        if (v1->v[i] != v2->v[i])
            return seq[v1->v[i]] - seq[v2->v[i]];
    return 0;
}

void _my_sort_3(struct Var** v, int s, int e, int* seq)
{
    if (s >= e)
        return;

    struct Var* t;

    if (comp_v(v[s], v[e], seq) > 0)
    {
        t = v[s];
        v[s] = v[e];
        v[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (comp_v(v[i], v[s], seq) < 0)
            i ++;
        while (comp_v(v[e], v[s], seq) > 0)
            e --;

        if (i >= e)
        {
            t = v[s];
            v[s] = v[e];
            v[e] = t;
        }
        else
        {
            t = v[i];
            v[i] = v[e];
            v[e] = t;
        }
    }
    _my_sort_3(v, cs, e - 1, seq);
    _my_sort_3(v, e + 1, ce, seq);

}

void _my_sort_2(int* v, int s, int e, int* seq)
{
    if (s >= e)
        return;

    int t;

    if (seq[v[s]] > seq[v[e]])
    {
        t = v[s];
        v[s] = v[e];
        v[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (seq[v[i]] < seq[v[s]])
            i ++;
        while (seq[v[e]] > seq[v[s]])
            e --;

        if (i >= e)
        {
            t = v[s];
            v[s] = v[e];
            v[e] = t;
        }
        else
        {
            t = v[i];
            v[i] = v[e];
            v[e] = t;
        }
    }

    _my_sort_2(v, cs, e - 1, seq);
    _my_sort_2(v, e + 1, ce, seq);
}

void _my_sort(int* id, int s, int e, char** vs)
{
    if (s >= e)
        return;

    int t;
    if (strcmp(vs[id[s]], vs[id[e]]) > 0)
    {
        t = id[s];
        id[s] = id[e];
        id[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (strcmp(vs[id[i]], vs[id[s]]) < 0)
            i ++;
        while (strcmp(vs[id[e]], vs[id[s]]) > 0)
            e --;

        if (i >= e)
        {
            t = id[s];
            id[s] = id[e];
            id[e] = t;
        }
        else
        {
            t = id[i];
            id[i] = id[e];
            id[e] = t;
        }
    }

    _my_sort(id, cs, e - 1, vs);
    _my_sort(id, e + 1, ce, vs);
}

void _outv(struct Var* v, char** vs)
{
    printf("%d ", v->a);
    for (int i = 0; i < v->n; i ++)
    {
        if (v->v[i])
            printf("* %s", vs[v->v[i]]);
    }

    printf(" + ");
}

void _mul(struct Exp* r1, struct Exp* r2)
{
    int on = r1->n;
    struct Var** ov = r1->v;

    r1->n = 0;
    r1->v = NULL;

    int in = 0;
    for (int i = 0; i < on; i ++)
    {
        struct Var* v1 = ov[i];

        in = r1->n;
        r1->n += r2->n;
        r1->v = realloc(r1->v, sizeof(struct Var*) * r1->n);

        for (int j = 0; j < r2->n; j ++)
        {
            struct Var* v2 = r2->v[j];
            struct Var* tv = malloc(sizeof(struct Var));
            tv->n = v1->n + v2->n;
            tv->a = v1->a * v2->a;
            tv->v = malloc(sizeof(int) * (v1->n + v2->n));

            int ti = 0;
            for (int k = 0; k < v1->n; k ++)
                tv->v[ti ++] = v1->v[k];
            for (int k = 0; k < v2->n; k ++)
                tv->v[ti ++] = v2->v[k];
            r1->v[in ++] = tv;
        }
    }
}

void _add(struct Exp* r1, struct Exp* r2)
{
    int in = r1->n;
    r1->n += r2->n;
    r1->v = realloc(r1->v, sizeof(struct Var*) * r1->n);

    for (int i = 0; i < r2->n; i ++)
        r1->v[in ++] = r2->v[i];
}

void _minus(struct Exp* r1, struct Exp* r2)
{
    int in = r1->n;
    r1->n += r2->n;
    r1->v = realloc(r1->v, sizeof(struct Var*) * r1->n);

    for (int i = 0; i < r2->n; i ++)
    {
        r2->v[i]->a = - r2->v[i]->a;
        r1->v[in ++] = r2->v[i];
    }
}

char** basicCalculatorIV(char* expression, char** evalvars, int evalvarsSize, int* evalints, int evalintsSize, int* returnSize)
{
    *returnSize = 0;
    if (!expression || !expression[0])
        return NULL;

    int vi = 1;
    int dp = 257;
    int* ehash = calloc(sizeof(int), dp);
    int* vhash = calloc(sizeof(int), dp);
    char** vars = malloc(sizeof(char*) * dp);

    for (int i = 0; i < evalvarsSize; i ++)
    {
        int x = 0;
        int ei = 0;

        char* e = evalvars[i];
        while(e[ei])
            x = (x * 256 + e[ei ++]) % dp;

        while (ehash[x])
            x = (x + 1) % dp;
        ehash[x] = i + 1;
    }

    int i = 0;
    int l = strlen(expression);

    int si = 0;
    struct Exp** st = calloc(sizeof(struct Exp*), 256);
    char t[256];

    while (expression[i])
    {
        // '*' only happen in between ") * ("
        if (expression[i] == '(' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == ' ')
        {
            if (expression[i] != ' ')
                st[si ++] = expression[i];

            i ++;
            continue;
        }

        if (expression[i] == ')')
        {
            int end = -- si;
            while (st[si] != '(')
                si --;

            struct Exp* r = st[si + 1];

            for (int j = si + 2; j <= end; j += 2)
            {
                bool rev = st[j] == '-';
                if (st[j] == '-')
                    _minus(r, st[j + 1]);
                else
                    _add(r, st[j + 1]);
            }

            st[si ++] = r;
            i ++;
        }
        else
        {
            int a = 1;
            struct Var* v = malloc(sizeof(struct Var));
            v->n = 0;
            v->a = 0;
            v->v = NULL;

            while (expression[i])
            {
                int c = expression[i];
                if (c == ' ' || c == '*')
                {
                    i ++;
                    continue;
                }

                if (c == '(' || c == '+' || c == '-' || c == ')')
                {
                    if (c == '(')
                    {
                        while (expression[i] != '*')
                            i --;
                    }
                    break;
                }

                int ta = 0;

                if (c >= '0' && c <= '9')
                {
                    while (c >= '0' && c <= '9')
                    {
                        ta = ta * 10 + c - '0';
                        c = expression[++ i];
                    }

                    a *= ta;
                }
                else
                {
                    int ti = 0;
                    int tx = 0;
                    while (c >= 'a' && c <= 'z')
                    {
                        tx = (tx * 256 + c) % dp;
                        t[ti ++] = c;
                        c = expression[++ i];
                    }

                    t[ti] = 0;

                    int otx = tx;

                    while (ehash[tx] && strncmp(t, evalvars[ehash[tx] - 1], ti))
                        tx = (tx + 1) % dp;

                    if (ehash[tx])
                    {
                        // printf("a %d v %d.\n", a,                        a * evalints[ehash[tx] - 1]);
                        a *= evalints[ehash[tx] - 1];
                    }
                    else
                    {
                        tx = otx;
                        while (vhash[tx] && strncmp(t, vars[vhash[tx]], ti))
                            tx = (tx + 1) % dp;

                        int tvi = vi;

                        if (vhash[tx])
                            tvi = vhash[tx];
                        else
                        {
                            vhash[tx] = vi;
                            vars[vi ++] = strdup(t);
                            // printf("== vi is %d %s.\n", vi - 1, vars[vi - 1]);
                        }
                        v->v = realloc(v->v, sizeof(int) * (v->n + 1));
                        v->v[v->n] = tvi;
                        v->n ++;
                    }
                }
            }

            struct Exp* r = malloc(sizeof(struct Exp));
            r->n = 1;
            r->v = malloc(sizeof(struct Var*));
            v->a = a;
            r->v[0] = v;
            st[si ++] = r;
            // printf("%d %p %c\n", si - 1, r, expression[i]);
        }

        while (si > 2 && st[si - 2] == '*')
        {
            _mul(st[si - 3], st[si - 1]);
            si -= 2;
        }
    }

    int* vars_id = malloc(sizeof(int) * vi);
    for (int i = 0; i < vi; i ++)
        vars_id[i] = i;

    _my_sort(vars_id, 1, vi - 1, vars);

    int* id_seq = malloc(sizeof(int) * vi);
    for (int i = 0; i < vi; i ++)
        id_seq[vars_id[i]] = i;

    for (int i = 1; i < si; i += 2)
    {
        if (st[i] == '-')
            _minus(st[0], st[i + 1]);
        else
            _add(st[0], st[i + 1]);
    }

    struct Exp* e = st[0];

    for (int i = 0; i < e->n; i ++)
    {
        struct Var* v = e->v[i];
        _my_sort_2(v->v, 0, v->n - 1, id_seq);
    }

    struct Var** vs = e->v;
    _my_sort_3(vs, 0, e->n - 1, id_seq);

    int pi = 0;
    for (int i = 1; i < e->n; i ++)
    {
        if (!comp_v(vs[pi], vs[i], id_seq))
            vs[pi]->a += vs[i]->a;
        else
        {
            pi ++;
            vs[pi] = vs[i];
        }
    }

    e->n = pi + 1;

    int ri = 0;
    char** r = NULL;

    // check 0
    for (int i = 0; i < e->n; i ++)
    {
        if (vs[i]->a)
        {
            r = realloc(r, sizeof(char*) * (ri + 1));
            r[ri ++] = _conv(vs[i], vars);
        }
    }

    *returnSize = ri;
    return r;
}
