#define MOD 1000000007
// BFS ?
int findPaths(int m, int n, int N, int i, int j)
{
    if (!N)
        return 0;
    int* a = calloc(sizeof(int), m * n);
    int* b = calloc(sizeof(int), m * n);

    int ai = 0;
    int bi = 0;
    short* sa = malloc(sizeof(short) * m * n);
    short* sb = malloc(sizeof(short) * m * n);

    a[i * n + j] = 1;
    sa[ai ++] = i << 8 | j;

    int all = 0;
    int step = 0;

    int* cur = a;
    int* nxt = b;

    int ci = ai;
    int ni = 0;

    short* cs = sa;
    short* ns = sb;

    while (step < N && ci)
    {
        step ++;

        for (int i = 0; i < ci; i ++)
        {
            int x = cs[i] >> 8;
            int y = cs[i] & 0xFF;

            int num = cur[x * n + y];

            if (x)
            {
                if (!nxt[(x - 1) * n + y])
                    ns[ni ++] = (x - 1) << 8 | y;
                nxt[(x - 1) * n + y] += num;
                nxt[(x - 1) * n + y] %= MOD;
            }
            else
            {
                all += num;
                all %= MOD;
            }

            if (y)
            {
                if (!nxt[x * n + y - 1])
                    ns[ni ++] = x << 8 | (y - 1);
                nxt[x * n + y - 1] += num;
                nxt[x * n + y - 1] %= MOD;
            }
            else
            {
                all += num;
                all %= MOD;
            }

            if (x != m - 1)
            {
                if (!nxt[(x + 1) * n + y])
                    ns[ni ++] = (x + 1) << 8 | y;
                nxt[(x + 1) * n + y] += num;
                nxt[(x + 1) * n + y] %= MOD;
            }
            else
            {
                all += num;
                all %= MOD;
            }

            if (y != n - 1)
            {
                if (!nxt[x * n + y + 1])
                    ns[ni ++] = x << 8 | (y + 1);
                nxt[x * n + y + 1] += num;
                nxt[x * n + y + 1] %= MOD;
            }
            else
            {
                all += num;
                all %= MOD;
            }
        }

        int* t = nxt;
        nxt = cur;
        cur = t;
        memset(nxt, 0, sizeof(int) * m * n);

        short* ts = ns;
        ns = cs;
        cs = ts;
        ci = ni;
        ni = 0;
    }

    return all;
}
