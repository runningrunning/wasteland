/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// linear probing * 4
// try to study hash code library, to get generic hash code
// corner case for compare the left part of the code
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
{
    *returnSize = 0;

    if (!words || !wordsSize || !k)
        return NULL;

    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};

    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 8; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 4 > wordsSize)
            break;
    }

    int* hs = malloc(sizeof(int) * dp);
    memset(hs, 0, sizeof(int) * dp);

    int hi = 0;
    int* hn = malloc(sizeof(int) * wordsSize);
    char** hw = malloc(sizeof(char*) * wordsSize);

    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];
        int j = 0;
        int c = w[j ++];

        int t = 0;
        while (c)
        {
            t = (26 * t + c - 'a') % dp;
            c = w[j ++];
        }

        while (hs[t] && strcmp(hw[hs[t] - 1], w))
        {
            t ++;
            t = t % dp;
        }

        if (hs[t])
        {
            hn[hs[t] - 1] ++;
        }
        else
        {
            hn[hi] = 1;
            hw[hi] = w;
            hi ++;
            hs[t] = hi;
        }
    }

    int* heap = malloc(sizeof(int) * hi);

    for (int i = 0; i < hi; i ++)
    {
        heap[i] = i;

        int p = i;

        while (p) // up
        {
            int n = (p - 1) / 2;
            int _hn = heap[n];
            int _hp = heap[p];

            if (hn[_hn] < hn[_hp] || (hn[_hn] == hn[_hp] && (strcmp(hw[_hn], hw[_hp]) > 0)))
            {
                heap[p] = _hn;
                heap[n] = _hp;
            }
            p = n;
        }
    }

    char** r = malloc(sizeof(char*) * k);
    for (int i = 0; i < k; i ++)
    {
        int c = heap[0];
        r[i] = hw[c];
        c = heap[0] = heap[-- hi];

        int x = 0;

        // down
        while (x * 2 + 1 < hi)
        {
            int lc = heap[x * 2 + 1];
            int rc = lc;

            if (x * 2 + 2 < hi)
                rc = heap[x * 2 + 2];

            // must use lc == rc to force compare left part
            if ((lc == rc) || hn[lc] > hn[rc] || (hn[lc] == hn[rc] && (strcmp(hw[lc], hw[rc]) < 0)))
            {
                if (hn[c] > hn[lc] || (hn[c] == hn[lc] && strcmp(hw[c], hw[lc]) < 0))
                    break;

                heap[x] = lc;
                heap[x * 2 + 1] = c;
                x = x * 2 + 1;
            }
            else
            {
                if (hn[c] > hn[rc] || (hn[c] == hn[rc] && strcmp(hw[c], hw[rc]) < 0))
                    break;
                heap[x] = rc;
                heap[x * 2 + 2] = c;
                x = x * 2 + 2;
            }
        }
    }

    *returnSize = k;
    return r;
}
