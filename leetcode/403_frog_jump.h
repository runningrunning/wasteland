// DP and memorization
#define PRIME 4099
bool _cc(int* n, int s, int e, int x, int* mins, int* maxs, short* hash, int* fs)
{
    int o = s * (e + 1) + x;

    if (fs[o / 32] & (1 << (o % 32)))
        return false;

    int z = n[s] + x;
    int h = z % PRIME;
    while (hash[h] && (n[hash[h]] != z))
        h = (h + 1) % PRIME;

    if (!hash[h])
        return false;

    s = hash[h];

    if (s == e)
        return true;

    if (x + 1 < mins[s] || x - 1 > maxs[s])
        return false;

    // - 1
    if (x != 1 && _cc(n, s, e, x - 1, mins, maxs, hash, fs))
        return true;

    // 0
    if (_cc(n, s, e, x, mins, maxs, hash, fs))
        return true;

    // + 1
    if (_cc(n, s, e, x + 1, mins, maxs, hash, fs))
        return true;

    fs[o / 32] |= (1 << (o % 32));
    return false;
}

bool canCross(int* stones, int stonesSize)
{
    int* mins = malloc(sizeof(int) * stonesSize); // <
    int* maxs = malloc(sizeof(int) * stonesSize); // >
    int* fs = calloc(sizeof(int), stonesSize * stonesSize / 32);

    short hash[PRIME] = {0};

    int pre = 0;
    for (int i = stonesSize - 1; i > 0; i --)
    {
        int x = stones[i];
        int y = stones[i - 1];

        pre --;
        if (pre < x - y)
            pre = x - y;

        mins[i - 1] = pre;
        maxs[i - 1] = stones[stonesSize - 1] - y;

        int h = x % PRIME;
        while (hash[h] && (stones[hash[h]] != x))
            h = (h + 1) % PRIME;
        hash[h] = i;
    }

    if (mins[0] > 1)
        return false;
    return _cc(stones, 0, stonesSize - 1, 1, mins, maxs, hash, fs);
}
