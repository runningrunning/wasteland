/* int num(int n) */
/* { */
/*     if (n == 0) */
/*         return 1; */
/*     if (n == 1) */
/*         return 1; */
/*     if (n == 2) */
/*         return 2; */

/*     int m = num(n - 1); */
/*     for(int i = 0; i < n - 1; i ++) */
/*     { */
/*         m += num(i) * num(n - 1 - i); */
/*     } */
/*     return m; */
/* } */
/*
void _gp(char* c, int s, int e, int k, int left)
{
    left --;

    if (k == 1)
    {
        c[s] = '(';
        c[e] = ')';
        if (!left)
            printf("%s.\n", c);
    }
    else
    {
        c[s] = '(';
        c[e] = ')';
        _gp(c, s + 1, e - 1, k - 1, left);

        for(int i  = 0; i < n; i ++)
        {
            if (i)
                _gp(c, 0, 2 * i - 1, i, n);

            _gp(c, 2 * i, e - 1, n - i, n - i);
        }
    }

    else if (k == 2)
    {
        left --;
        c[s] = '(';
        c[s + 1] = ')';
        c[s + 2] = '(';
        c[s + 3] = ')';
        if (!left)
            printf("%s.\n", c);

        c[s] = '(';
        c[s + 1] = '(';
        c[s + 2] = ')';
        c[s + 3] = ')';
        if (!left)
            printf("%s.\n", c);
    }
    else
    {
        c[s] = '(';
        c[e] = ')';
        _gp(c, s + 1, e - 1, k - 1, left);

        c[s] = '(';
        c[s + 1] = ')';
        c[s + 2] = '(';
        c[e] = ')';
        _gp(c, s + 3, e - 1, k - 2, left - 1);

        c[e - 2] = ')';
        c[e - 1] = '(';
        c[e] = ')';
        c[s] = '(';
        _gp(c, s + 1, e - 3, k - 2, left - 1);
    }

}

char** generateParenthesis(int n, int* returnSize)
{
    char c[256] = {0};
    int s = 0;
    int e = n * 2;
    c[e] = 0;

    _gp(c, 0, e - 1, n, n);
    for(int i  = 0; i < n; i ++)
    {
        if (i)
            _gp(c, 0, 2 * i - 1, i, n);

        _gp(c, 2 * i, e - 1, n - i, n - i);
    }
}
*/

void _gp(char* c, int s, int e, int n, int l, int r, char*** ret, int* num)
{
    if (l == n)
    {
        for(int i = s; i <= e; i ++)
            c[i] = ')';

        int cur = *num;
        if (!((cur + 1) % 256))
            *ret = realloc(*ret, sizeof(char*) * (cur + 257));

        char* rp = malloc(2 * n + 1);
        rp[2*n] = 0;
        strncpy(rp, c, 2 * n);
        (*ret)[cur] = rp;
        (*num) ++;
    }
    else if (l > r)
    {
        c[s] = ')';
        _gp(c, s + 1, e, n, l, r + 1, ret, num);

        c[s] = '(';
        _gp(c, s + 1, e, n, l + 1, r, ret, num);
    }
    else // l == r
    {
        c[s] = '(';
        _gp(c, s + 1, e, n, l + 1, r, ret, num);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    if (!n)
        return NULL;

    char c[512] = {0};
    int r = 0;
    char** ret = malloc(sizeof(char*) * 256);
    _gp(c, 0, (n << 1) - 1, n, 0, 0, &ret, &r);
    *returnSize = r;
    return ret;
}

