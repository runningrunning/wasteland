// add | xor | length ARE not enough !!!!!!!!!!!!!!!!!!!!!! // e.g. 25 19 19 25.
// add bits | xor, not ADD
// be careful about how to choose signature !
int numSpecialEquivGroups(char** A, int ASize)
{
    if (!A || !ASize)
        return 0;

    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 11;

    for (int i = 0; i < pl; i ++)
        if (pri[i] > ASize * 4)
        {
            dp = pri[i];
            break;
        }

    unsigned long* hash = calloc(sizeof(unsigned long), dp);

    int n = 0;
    int l = strlen(A[0]);
    for (int i = 0; i < ASize; i ++)
    {
        char* s = A[i];

        unsigned long x0 = 0;
        unsigned long f0 = 0;
        unsigned long x1 = 0;
        unsigned long f1 = 0;

        for (int j = 0; j < l; j ++)
        {
            int c = s[j] - 'a';

            if (j % 2)
            {
                x0 ^= c;
                f0 |= 1 << c;
            }
            else
            {
                x1 ^= c;
                f1 |= 1 << c;
            }
        }

        unsigned long x = (f0 << 5 | x0) << 32 | (f1 << 5 | x1);
        int k = x % dp;

        while (hash[k] && hash[k] != x + 1)
            k = (k + 1) % dp;

        if (!hash[k])
        {
            n ++;
            hash[k] = x + 1;
        }
    }

    return n;
}
