// brilliant to have my own tree
// generate my tree here
// find better way to mark the jump than now ~~~
// TREE MAP + DP ??
// WHERE'S THE DP PART?
// try to use KEY to speed up

// USE TREE to find the better one

// FIND THE BETTER SOLUTION ~~~~!!!!

// HOW STUPID ME ~~!!!!!!!!!!!!!
// O(N^2) version !!!
// how to use stack ?????
// take a look at hint !!
// clear mind here ~~~~!!!
// use binary tree to find the next one
// use graph to do the link thing ? or some thing else
// how to solve this issue correctly
// stupid ME !!!!
// DP again ????
// use heap !! not heap !!!
// find the stupidest solution
// stupid wrong algorithm !!!!!
// binary search tree ? be sure to find the next bigger or next smaller ?
// use graph to add linked nodes ?

// my tree

int _random(long x)
{
    return (((x * 48271L)) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct _Node {
    int p;
    int i;
    int v;
    struct _Node* l;
    struct _Node* r;
} Node;

Node* cNode(int i, int v, int p)
{
    Node* n = malloc(sizeof(Node));
    n->i = i;
    n->v = v;
    n->p = p;
    n->l = n->r = NULL;
    return n;
}

void aTree(Node** r, int i, int v, int p, int* min_v, int* max_v, int* min_i, int* max_i)
{
    if (*r == NULL)
    {
        *r = cNode(i, v, p);
        return;
    }

    Node* c = *r;

    if (c->v == v)
    {
        *max_i = c->i;
        *min_i = c->i;
        c->i = i;
        return;
    }

    if (v < c->v)
    {
        if (*max_v > c->v)
        {
            *max_v = c->v;
            *max_i = c->i;
        }
        aTree(&c->l, i, v, p, min_v, max_v, min_i, max_i);
        if (c->p > c->l->p)
        {
            Node* t = c->l;
            c->l = t->r;
            t->r = c;
            *r = t;
        }
    }
    else
    {
        if (*min_v < c->v)
        {
            *min_v = c->v;
            *min_i = c->i;
        }
        aTree(&c->r, i, v, p, min_v, max_v, min_i, max_i);
        if (c->p > c->r->p)
        {
            Node* t = c->r;
            c->r = t->l;
            t->l = c;
            *r = t;
        }
    }
}

int oddEvenJumps(int* A, int ASize)
{
    if (ASize == 1)
        return 1;

    int* odd = calloc(sizeof(int), ASize);
    int* eve = calloc(sizeof(int), ASize);
    int pri = ((long) A) & 0xFFFFFFFF;

    Node* t = NULL;

    int min_v;
    int max_v;
    for (int i = ASize - 1; i >= 0; i --)
    {
        max_v = INT_MAX;
        min_v = INT_MIN;
        odd[i] = 0;
        eve[i] = 0;
        aTree(&t, i, A[i], pri, &min_v, &max_v, eve + i, odd + i);
        pri = _random(pri);
    }

    /* out(odd, ASize); */
    /* out(eve, ASize); */

    odd[ASize - 1] = ASize - 1;
    eve[ASize - 1] = ASize - 1;

    // using stack here

    int se = ASize - 1;
    int ne = ASize - 1;

    int* s = malloc(sizeof(int) * ASize);
    int* n = malloc(sizeof(int) * ASize);

    for (int i = ASize - 2; i >= 0; i --)
        if (eve[i] || odd[i])
            s[se --] = i;

    while (true)
    {
        ne = ASize - 1;
        for (int i = ASize - 1; i > se; i --)
        {
            int x = s[i];
            if (!eve[x] && !odd[x])
                continue;

            if (eve[x] && !odd[eve[x]])
                eve[x] = 0;
            if (odd[x] && !eve[odd[x]])
                odd[x] = 0;
            if (eve[x] || odd[x])
                n[ne --] = x;
        }

        if (se == ne)
            break;

        int* m = s;
        se = ne;
        s = n;
        n = m;
    }

    int has_num = 0;
    for (int i = 0; i < ASize; i ++)
        if (odd[i])
            has_num ++;
    return ASize == 1 ? 1 : has_num;;
}

int comp_long(const void* e1, const void* e2)
{
    long l1 = *((long*)e1);

    long l2 = *((long*)e2);

    if (l1 == l2)
        return 0;

    return l1 > l2 ? 1 : -1;
}

void _oej(int* a, int e, int** ej, int* en, int** oj, int* on, bool odd, int* num)
{
    if (odd)
    {
        if (on[e])
        {
            for (int i = 0; i < on[e]; i ++)
            {
                int x = oj[e][i];

                if (a[x] > 0)
                {
                    a[x] = - a[x];
                    (*num) ++;
                }
                _oej(a, x, ej, en, oj, on, false, num);
            }
            on[e] = 0;
        }
    }
    else if (en[e])
    {
        for (int i = 0; i < en[e]; i ++)
            _oej(a, ej[e][i], ej, en, oj, on, true, num);
        en[e] = 0;
    }
}

bool _oej2(int* a, int s, int e, int* ej, int* oj, bool odd)
{
    if (s == e)
        return true;

    if (odd)
    {
        if (oj[s] > 0)
        {
            if (_oej2(a, oj[s], e, ej, oj, false))
                oj[s] = - oj[s];
            else
                oj[s] = 0;
        }
        return oj[s] < 0;
    }

    if (ej[s] > 0)
    {
        if (_oej2(a, ej[s], e, ej, oj, true))
            ej[s] = - ej[s];
        else
            ej[s] = 0;
    }

    return ej[s] < 0;
}

int oddEvenJumps_1(int* A, int ASize)
{
    int* odd = calloc(sizeof(int), ASize);
    int* eve = calloc(sizeof(int), ASize);
    long* t = malloc(sizeof(long) * ASize);

    for (int i = 0; i < ASize; i ++)
    {
        A[i] += 1;
        t[i] = (((long) A[i]) << 32) | i;
    }

    qsort(t, ASize, sizeof(long), comp_long);

    for (int i = ASize - 1; i >= 0; i --)
    {
        int index = t[i] & 0xFFFFFFFF;
        int value = t[i] >> 32;
        int pre = -1;

        if (i != ASize - 1)
        {
            if (((t[i + 1] >> 32) == value) && ((t[i + 1] & 0xFFFFFFFF) > index))
                eve[index] = t[i + 1] & 0xFFFFFFFF;
        }

        for (int j = i - 1; j >= 0; j --)
        {
            int _i = t[j] & 0xFFFFFFFF;
            if (_i < index)
            {
                if (_i > pre)
                {
                    pre = _i;
                    odd[_i] = index;
                }
            }
            else if (!eve[index] || A[eve[index]] == (t[j] >> 32))
                eve[index] = _i;
        }
    }

    /*
    // Try another method !!!
    int* on = calloc(sizeof(int), ASize);
    int* en = calloc(sizeof(int), ASize);
    int** oj = calloc(sizeof(int*), ASize);
    int** ej = calloc(sizeof(int*), ASize);

    for (int i = 0; i < ASize; i ++)
    {
        if (odd[i])
        {
            int jf = i;
            int jt = odd[jf];
            oj[jt] = realloc(oj[jt], sizeof(int) * (on[jt] + 1));
            oj[jt][on[jt]] = jf;
            on[jt] += 1;
        }

        if (eve[i])
        {
            int jf = i;
            int jt = eve[jf];
            ej[jt] = realloc(ej[jt], sizeof(int) * (en[jt] + 1));
            ej[jt][en[jt]] = jf;
            en[jt] += 1;
        }
    }

    int num = 1;
    _oej(A, ASize - 1, ej, en, oj, on, 0, &num);
    _oej(A, ASize - 1, ej, en, oj, on, 1, &num);
    */

    /* out(odd, ASize); */
    /* out(eve, ASize); */

    odd[ASize - 1] = ASize - 1;
    eve[ASize - 1] = ASize - 1;

    bool has = true;
    while (has)
    {
        has = false;
        for (int i = ASize - 1; i >= 0; i --)
        {
            if (eve[i])
            {
                if (!odd[eve[i]])
                {
                    has = true;
                    eve[i] = 0;
                }
            }

            if (odd[i])
            {
                if (!eve[odd[i]])
                {
                    has = true;
                    odd[i] = 0;
                }
            }
        }
    }

    /*
    int num = 0;
    for (int i = 0; i < ASize; i ++)
    {
        if (_oej2(A, i, ASize - 1, eve, odd, true))
            num ++;
        if (odd[i])
            has_num ++;
    }

    if (num != has_num)
        printf("%d %d.\n", num, has_num);
    */

    int has_num = 0;
    for (int i = 0; i < ASize; i ++)
        if (odd[i])
            has_num ++;
    return ASize == 1 ? 1 : has_num;;
}
