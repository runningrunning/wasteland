bool is_ok(int m, int n, int* c)
{
    for (int i = 0; i < m; i ++)
        if (c[i] == n || abs(m - i) == abs(n - c[i]))
            return false;
    return true;
}

void tnq(int* r, int s, int n, int* c)
{
    if (s == n)
        (*r) ++;
    else
    {
        for (int i = 0; i < n; i ++)
            if (is_ok(s, i, c))
            {
                c[s] = i;
                tnq(r, s + 1, n, c);
            }
    }
}

int totalNQueens(int n) {
    int r = 0;
    int* c = malloc(sizeof(int) * n);
    tnq(&r, 0, n, c);
    return r;
}
