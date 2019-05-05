/* TLE AGAIN */
// 2s still not enough :(
int add(int* hash, int dp, int x)
{
    int k = x % dp;

    while (hash[k] && hash[k] != x)
        k = (k + 1) % dp;
    // printf("try %d.\n", x);
    if (!hash[k])
    {
        hash[k] = x;
        // printf("%d.\n", x);
        return 1;
    }

    return 0;
}

int subarrayBitwiseORs(int* A, int ASize)
{
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp > 3 * ASize)
            break;
    }

    if (!A || !ASize)
        return 0;

    int* hash = calloc(sizeof(int), dp);

    int BSize = 0;
    int* B = malloc(sizeof(int) * ASize);

    int nums = 0;
    int* _a = A;
    int _ai = ASize;
    int* _b = B;
    int _bi = BSize;
    int _bs = 0;

    for (int i = 0; i < _ai; i ++)
    {
        int na = _a[i];

        nums += add(hash, dp, na);
        _b[_bi ++] = na;

        if (i && (_a[i] | _a[i - 1]) == _a[i - 1])
            continue;
        int ma = 0;
        int nbs = _bi - 1;

        for (int j = _bi - 1; j >= _bs; j --)
        {
            int o = _b[j];
            na |= _b[j];
            if (na != ma)
            {
                if (ma)
                    nums += add(hash, dp, na);
                _b[nbs --] = na;
                // printf("bs is %d %d.\n", _bs, na);
            }
            else
            {
                if ((na | o) == o)
                    break;
            }
            ma = na;
        }
        _bs = nbs;
    }

    return nums;
}

/* still TLE here*/
/*
int subarrayBitwiseORs(int* A, int ASize)
{
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp > 3 * ASize)
            break;
    }

    int* hash = calloc(sizeof(int), dp);

    int BSize = 0;
    int* B = malloc(sizeof(int) * ASize);

    int nums = 0;
    int* _a = A;
    int _ai = ASize;
    int* _b = B;
    int _bi = BSize;

    for (int i = 0; i < _ai; i ++)
    {
        int x = _a[i];
        nums += add(hash, dp, x);

        if (i)
        {
            int na = _a[i - 1] | _a[i];
            if (na != _a[i])
            {
                while (_bi - 1)
                {
                    if ((_b[_bi - 2] | _b[_bi - 1]) != _b[_bi - 1])
                        break;

                    printf("merge here.\n");

                    _b[_bi - 2] = _b[_bi - 1];
                    _bi --;
                }
                _b[_bi ++] = _a[i - 1];

                // printf("bi is %d\n", _bi);

                while (_bi - 1)
                {
                    if ((_b[_bi - 2] | _b[_bi - 1]) != _b[_bi - 1])
                        break;

                    printf("merge here.\n");

                    _b[_bi - 2] = _b[_bi - 1];
                    _bi --;
                }
            }

            int p = 0;
            for (int j = _bi - 1; j >= 0; j --)
            {
                x |= _b[j];
                if (x != p)
                    nums += add(hash, dp, x);
                p = x;
            }
        }
    }
    return nums;
}
*/

/* stupid wrong algorithm, TLE */
/*
int subarrayBitwiseORs(int* A, int ASize)
{
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp > 3 * ASize)
            break;
    }

    int* hash = calloc(sizeof(int), dp);

    int BSize = 0;
    int* B = malloc(sizeof(int) * ASize);

    int nums = 0;

    int* _a = A;
    int _ai = ASize;
    int* _b = B;
    int _bi = BSize;

    while(_ai)
    {
        for (int i = 0; i < _ai; i ++)
        {
            int x = _a[i];
            int k = x % dp;
            while (hash[k] && hash[k] != x)
                k = (k + 1) % dp;

            // printf("try %d.\n", x);
            if (!hash[k])
            {
                nums ++;
                hash[k] = _a[i];
                // printf("%d.\n", _a[i]);
            }

            if (i)
            {
                int na = _a[i] | _a[i - 1];
                // if (na != _a[i]) // && na != _a[i - 1])
                {
                    _b[_bi ++] = na;
                    // printf("new %d %d.\n", na, _bi);
                }
            }
        }

        _a = _a == A ? B : A;
        _b = _b == A ? B : A;
        _ai = _bi;
        _bi = 0;
    }
    return nums;
}
*/
