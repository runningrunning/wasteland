// hash to speed up
// 26 * 26 * 26 * 26 * 2048 < pow(2, 31)

#define PRIME  4099 // should be enough for 1500

int lrs(int* hash, int l, char* s, int len)
{
    if (l > len)
        return 0;

    memset(hash, 0, sizeof(int) * PRIME);

    int max = 0;
    int mod = 1;

    for (int i = 0; i < l; i ++)
        mod *= 26;

    int x = 0;
    for (int i = 0; i < l - 1; i ++)
        x = x * 26 + s[i] - 'a';

    for (int i = l - 1; i < len; i ++)
    {
        x = x * 26 + s[i] - 'a';
        x %= mod;

        int k = x % PRIME;

        while (hash[k])
        {
            if (x == (hash[k] >> 11))
            {
                // find the match
                int ci = i;
                int pi = hash[k] & (2048 - 1);
                int pre = 0;
                int pos = 0;
                for (int t = pi; t >= 0; t --, ci --)
                    if (s[ci] != s[t])
                        break;
                    else
                        pre ++;

                ci = i + 1;
                pi ++;
                while (s[ci])
                {
                    if (s[ci ++] != s[pi ++])
                        break;
                    pos ++;
                }

                if (max < pre + pos)
                    max = pre + pos;
            }
            k = (k + 1) % PRIME;
        }
        hash[k] = x << 11 | i;
    }
    return max;
}
int longestRepeatingSubstring(char * S)
{
    int l = strlen(S);

    if (l == 1)
        return 0;

    if (l == 2)
        return S[0] == S[1] ? 1 : 0;

    int max = 0;

    int* hash = malloc(sizeof(int) * PRIME);

    int size = 4;

    while (!max && size)
        max = lrs(hash, size --, S, l);

    return max;
}
