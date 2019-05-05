// DP, find better solution here.
// trick, but still DP, is there anyway to calculate it directly ?
// just need to find a way to remember all of its internal status
bool ciw(int m, int t, int f, int* fs)
{
    if (fs[f>>5] & (1 << (f & 0x1F)))
        return true;

    for (int i = m; i >= 1; i --)
    {
        int x = 1 << (i - 1);
        if (f & x)
            continue;

        if (i >= t)
            return false;

        f |= x;
        if (ciw(m, t - i, f, fs))
        {
            fs[f >> 5] |= 1 << (f & 0x1F);
            return false;
        }
        f &= ~x;
    }
    return true;
}

bool canIWin(int m, int t)
{
    int a = m * (m + 1) / 2;
    if (t > a)
        return false;

    if (t == a)
        return m & 1;

    if (t <= m)
        return true;

    // check if it's possible
    int f = 0;
    // flags size
    int fs_s[] = {1,1,1,1,1,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

    int* fs = malloc(sizeof(int) * fs_s[m]);
    memset(fs, 0, sizeof(int) * fs_s[m]);

    for (int i = m; i >= 1; i --)
    {
        f |= 1 << (i - 1);
        if (ciw(m, t - i, f, fs))
            return true;
        f = 0;
    }
    return false;
}

// DP
bool ciw_1(int m, int t, int* f)
{
    for (int i = m; i >= 1; i --)
    {
        if (f[i])
            continue;

        if (i >= t)
            return false;

        f[i] = 1;
        if (ciw_1(m, t - i, f))
        {
            f[i] = 0;
            return false;
        }
        f[i] = 0;
    }
    return true;
}

bool canIWin_1(int m, int t)
{
    int a = m * (m + 1) / 2;
    if (t > a)
        return false;

    if (t == a)
        return m & 1;

    if (t <= m)
        return true;

    // check if it's possible
    int cs[24] = {0};
    for (int i = m; i >= 1; i --)
    {
        cs[i] = 1;
        if (ciw_1(m, t - i, cs))
        {
            // printf("choose %d ", i);
            return true;
        }
        cs[i] = 0;
    }
    return false;
}
