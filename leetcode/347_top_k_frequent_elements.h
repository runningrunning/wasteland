/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// linear probing * 4
// n could be negative number, must convert to long n = nums[i] & 0xFFFFFFFF
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = 0;

    if (!nums || !numsSize || !k)
        return NULL;

    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 8; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 4 > numsSize)
            break;
    }

    int* hs = malloc(sizeof(int) * dp);
    int hl = ((dp + 31) / 32) + 1;
    int* hf = malloc(sizeof(int) * hl);
    memset(hf, 0, sizeof(int) * hl);

    int hi = 0;
    int* hp = malloc(sizeof(int) * numsSize);
    int* hn = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        long n = nums[i] & 0xFFFFFFFF;
        int x = n % dp;
        int a = x / 32;
        int b = x % 32;

        while ((hf[a] & (1 << b)) && hp[hs[x]] != nums[i])
        {
            x ++;
            x = x % dp;

            a = x / 32;
            b = x % 32;
        }

        if (hf[a] & (1 << b))
        {
            hn[hs[x]] ++;
        }
        else
        {
            hf[a] |= 1 << b;
            hs[x] = hi;
            hn[hi] = 1;
            hp[hi ++] = nums[i];
        }
    }

    long* heap = (long*) malloc(sizeof(long) * numsSize);

    for (int i = 0; i < hi; i ++)
    {
        long c =  ((long) hn[i] << 32) | (hp[i] & 0xFFFFFFFF);
        heap[i] = c;

        int p = i;
        while (p) // up
        {
            int n = (p - 1) / 2;
            if (heap[n] < heap[p])
            {
                heap[p] = heap[n];
                heap[n] = c;
            }
            p = n;
        }
    }

    int* r = malloc(sizeof(int) * k);

    for (int i = 0; i < k; i ++)
    {
        long c = heap[0];
        r[i] = c & 0xFFFFFFFF;

        c = heap[0] = heap[-- hi];

        // down
        int x = 0;

        while (x * 2 + 1 < hi)
        {
            long lc = heap[x * 2 + 1];
            long rc = lc;

            if (x * 2 + 2 < hi)
                rc = heap[x * 2 + 2];

            if (lc >= rc)
            {
                if (c >= lc)
                    break;

                heap[x] = lc;
                heap[x * 2 + 1] = c;
                x = x * 2 + 1;
            }
            else
            {
                if (c >= rc)
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
