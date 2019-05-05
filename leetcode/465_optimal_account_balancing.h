// really? no optimization, just simple DP to solve this one ?
// figure out a better solution for this one
// graphic ?
// hash ?
// DP, how to represent DP of this money
// try with no memoryable DP

int _mt(int* n, int s1, int s2, int e1, int e2)
{
    // out(n, e2 + 1);
    while (!n[s1] && s1 < s2)
        s1 ++;

    if (s1 >= s2)
        return 0;

    int x = - n[s1];
    int m = 0;
    for (int i = s2; i <= e2; i ++)
        if (x == n[i])
        {
            m = i;
            break;
        }

    if (m)
    {
        n[s1] = 0;
        n[m] = 0;
        int r = 1 + _mt(n, s1 + 1, s2, e1, e2);
        n[s1] = -x;
        n[m] = x;
        return r;
    }

    int min = INT_MAX;

    for (int i = s2; i <= e2; i ++)
    {
        if (!n[i])
            continue;

        int num = 0;

        int o = n[i];

        if (o < x)
        {
            n[s1] += o;
            n[i] = 0;
            num = 1 + _mt(n, s1, s2, e1, e2);
            n[s1] = -x;
            n[i] = o;
        }
        else
        {
            n[s1] = 0;
            n[i] -= x;
            num = 1 + _mt(n, s1 + 1, s2, e1, e2);
            n[s1] = -x;
            n[i] = o;
        }

        if (num < min)
            min = num;
    }
    return min;
}

int minTransfers(int** transactions, int transactionsRowSize, int transactionsColSize)
{
    if (!transactions || !transactionsRowSize)
        return 0;

    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 3 > transactionsRowSize)
            break;
    }

    int hi = 0;
    int* hash = calloc(sizeof(int), dp);
    int* hash_to_id = calloc(sizeof(int), transactionsRowSize * 2);
    int* money = calloc(sizeof(int), transactionsRowSize * 2);

    for (int i = 0; i < transactionsRowSize; i ++)
    {
        int x = transactions[i][0];
        int y = transactions[i][1];
        int n = transactions[i][2];

        int id_x = x % dp;
        while (hash[id_x] && hash_to_id[hash[id_x] - 1] != x)
            id_x = (id_x + 1) % dp;

        if (!hash[id_x])
        {
            hash_to_id[hi ++] = x;
            hash[id_x] = hi;
        }
        money[hash[id_x] - 1] -= n;

        int id_y = y % dp;
        while (hash[id_y] && hash_to_id[hash[id_y] - 1] != y)
            id_y = (id_y + 1) % dp;

        if (!hash[id_y])
        {
            hash_to_id[hi ++] = y;
            hash[id_y] = hi;
        }
        money[hash[id_y] - 1] += n;
    }

    int* all = malloc(sizeof(int) * hi);

    int num = 0;
    for (int i = 0; i < hi; i ++)
    {
        if (!money[i])
            continue;

        int m = 0;
        int x = - money[i];
        for (int j = i + 1; j < hi; j ++)
            if (money[j] == x)
            {
                m = j;
                break;
            }

        if (m)
        {
            money[i] = 0;
            money[m] = 0;
            num ++;
        }
    }

    int ai = 0;
    for (int i = 0; i < hi; i ++)
        if (money[i] < 0)
            all[ai ++] = money[i];

    int ae = ai;
    for (int i = 0; i < hi; i ++)
        if (money[i] > 0)
            all[ai ++] = money[i];
    return num + _mt(all, 0, ae, ae - 1, ai - 1);
}
