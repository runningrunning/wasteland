// forget to initialization memory again !!!
// realloc must use size is b = realloc(b, sizeof(int) * (bi + 1)) !!!!!
int next(int a, int* t)
{
    int a6 = a % 6;
    a /= 6;
    int a5 = a % 6;
    a /= 6;
    int a4 = a % 6;
    a /= 6;
    int a3 = a % 6;
    a /= 6;
    int a2 = a % 6;
    a /= 6;
    int a1 = a % 6;
    a /= 6;

    int r = 2;
    if (a2 == 0 || a5 == 0)
        r = 3;

    if (a1 == 0)
    {
        t[0] = a2 * 7776 + a1 * 1296 + a3 * 216 + a4 * 36 + a5 * 6 + a6;
        t[1] = a4 * 7776 + a2 * 1296 + a3 * 216 + a1 * 36 + a5 * 6 + a6;

    } else if (a2 == 0)
    {
        t[0] = a2 * 7776 + a1 * 1296 + a3 * 216 + a4 * 36 + a5 * 6 + a6;
        t[1] = a1 * 7776 + a3 * 1296 + a2 * 216 + a4 * 36 + a5 * 6 + a6;
        t[2] = a1 * 7776 + a5 * 1296 + a3 * 216 + a4 * 36 + a2 * 6 + a6;
    } else if (a3 == 0)
    {
        t[0] = a1 * 7776 + a3 * 1296 + a2 * 216 + a4 * 36 + a5 * 6 + a6;
        t[1] = a1 * 7776 + a2 * 1296 + a6 * 216 + a4 * 36 + a5 * 6 + a3;
    } else if (a4 == 0)
    {
        t[0] = a4 * 7776 + a2 * 1296 + a3 * 216 + a1 * 36 + a5 * 6 + a6;
        t[1] = a1 * 7776 + a2 * 1296 + a3 * 216 + a5 * 36 + a4 * 6 + a6;
    } else if (a5 == 0)
    {
        t[0] = a1 * 7776 + a2 * 1296 + a3 * 216 + a5 * 36 + a4 * 6 + a6;
        t[1] = a1 * 7776 + a2 * 1296 + a3 * 216 + a4 * 36 + a6 * 6 + a5;
        t[2] = a1 * 7776 + a5 * 1296 + a3 * 216 + a4 * 36 + a2 * 6 + a6;
    } else
    {
        t[0] = a1 * 7776 + a2 * 1296 + a6 * 216 + a4 * 36 + a5 * 6 + a3;
        t[1] = a1 * 7776 + a2 * 1296 + a3 * 216 + a4 * 36 + a6 * 6 + a5;
    }

    return r;
}

int slidingPuzzle(int** board, int boardRowSize, int *boardColSizes)
{
    int f[1536] = {0};
    int ai = 1;
    int bi = 0;
    int* a = malloc(sizeof(int));
    int* b = NULL;
    a[0] = 0;
    int e = 0;

    for (int i = 0; i < 6; i ++)
    {
        e = e * 6 + ((i + 1) % 6);
        a[0] = a[0] * 6 + board[i/3][i%3];
    }

    int x = a[0] / 32;
    int y = a[0] % 32;
    f[x] |= 1 << y;

    if (a[0] == e)
        return 0;

    int ti = 0;
    int t[4] = {0};

    int n = 1;
    while (true)
    {
        for (int i = 0; i < ai; i ++)
        {
            int ta = a[i];
            ti = next(ta, t);

            for (int j = 0; j < ti; j ++)
            {
                ta = t[j];

                if (ta == e)
                    return n;

                 x = ta / 32;
                 y = ta % 32;

                if (!(f[x] & (1 << y)))
                {
                    f[x] |= 1 << y;
                    b = realloc(b, sizeof(int) * (bi + 1));
                    b[bi ++] = ta;
                }
            }
        }

        if (!bi)
            return -1;

        free(a);

        ai = bi;
        a = b;

        b = NULL;
        bi = 0;
        n ++;
    }

    return -1;
}
