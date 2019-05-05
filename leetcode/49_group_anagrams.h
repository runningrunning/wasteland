/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void* em1, const void* em2)
{
    long t = ((*(long*)em1) & ~0xFFFFl) - ((*(long*)em2) & ~0xFFFFl);
    if (t == 0)
        return 0;
    return t > 0l ? 1 : -1;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize)
{
    int i = 0;
    long* a = malloc(sizeof(long) * (strsSize + 1));

    int mask[26] = {0};

    for(i = 0; i < 26; i++)
        mask[i] = 1 << (i + 1);

    for(i = 0; i < strsSize; i ++)
    {
        char* t = strs[i];
        long xor = 0;
        long l = 0;
        long f = 0;
        int ac = 0;
        while(t[l])
        {
            xor ^= t[l];
            ac += t[l] - 'a';
            f |= mask[t[l] - 'a'];
            l ++;
        }

        a[i] = f << 36 | (xor & 0x7F) << 29 | (ac & 0xFF) << 21 | (l & 0xFFl) << 16 | i;
        printf("%s %lx %lx %lx %lx %d %lx\n", strs[i], f << 37, (xor & 0x7f) << 30, (ac & 0xff) << 22, (l & 0xffl) << 16, i, a[i]);
    }
    a[strsSize] = 0x7FFFFFFFl << 32 | strsSize;

    qsort(a, strsSize, sizeof(long), comp);
    outl(a, strsSize + 1);
    int limit = 255;
    char*** ret = malloc(sizeof(char**) * 255);
    int* cs = malloc(sizeof(int) * 255);

    int cur = 0;
    long pre = a[0];
    int c = 0;

    for(i = 0; i <= strsSize; i++)
    {
        if ((pre & ~0xFFFFl) != (a[i] & ~0xFFFFl))
        {
            if (c >= limit)
            {
                limit += 255;
                ret = realloc(ret, sizeof(char**) * limit);
                cs = realloc(cs, sizeof(int) * limit);
            }
            cs[c] = i - cur;
            ret[c] = malloc(sizeof(char*) * (i - cur));
            for(int n = cur; n < i; n ++)
            {
                printf("%i\n", a[i] & 0xFFFF);
                ret[c][n - cur] = strs[a[n] & 0xFFFF];
            }
            c ++;
            cur = i;
            pre = a[i];
        }
    }

    *returnSize = c;
    *columnSizes = cs;
    return ret;
}
