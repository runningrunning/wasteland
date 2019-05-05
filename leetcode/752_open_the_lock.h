// just bfs, but how to ?
// find better solution ?
// no dp ?
// learn a lot !!

void _opl(int* a, int ai, int* b, char* f, int l, int* n)
{
    if (ai == 0)
    {
        *n = -1;
        return;
    }

    int bi = 0;
    for (int i = 0; i < ai; i ++)
    {
        if (a[i] == 0)
        {
            *n = l;
            return;
        }

        int t = a[i];

        int ts[4];
        ts[0] = t / 1000;
        ts[1] = (t / 100) % 10;
        ts[2] = (t / 10) % 10;
        ts[3] = t % 10;

        for (int j = 0; j < 4; j ++)
        {
            int o = ts[j];
            ts[j] = o == 0 ? 9 : (o - 1);
            int nt = ts[0] * 1000 + ts[1] * 100 + ts[2] * 10 + ts[3];

            if (!f[nt])
            {
                f[nt] = 1;
                b[bi ++] = nt;
            }

            ts[j] = o == 9 ? 0 : (o + 1);
            nt = ts[0] * 1000 + ts[1] * 100 + ts[2] * 10 + ts[3];

            if (!f[nt])
            {
                f[nt] = 1;
                b[bi ++] = nt;
            }
            ts[j] = o;
        }
    }
    _opl(b, bi, a, f, l + 1, n);
}

int openLock(char** deadends, int deadendsSize, char* target)
{
    int as[10000] = {0};
    int bs[10000] = {0};
    char fs[10000] = {0};

    for (int i = 0; i < deadendsSize; i ++)
    {
        int x;
        sscanf(deadends[i], "%d", &x);
        fs[x] = 1;
    }

    int t;
    sscanf(target, "%d", &t);

    if (fs[t] || fs[0])
        return -1;

    fs[t] = 1;
    as[0] = t;

    int num = 0;
    _opl(as, 1, bs, fs, 0, &num);
    return num;
}
