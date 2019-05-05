/* how to write permutation code ? */
/* change recursion to inline functions */
/* write function to generate full permutations */
/* CPP STL do have next_permutation function !!!!! */
/* cheating !!! */

/* same with 47 permutation II !!! */
void gp(char* t, int l, int m, char*** ret, int* rt, int s, int e)
{
    if (s >= e)
    {
        (*rt) ++;
        int size = *rt;
        *ret = realloc(*ret, sizeof(char*) * size);
        char* tmp = malloc(l + 1);
        tmp[l] = 0;
        for (int i = 0; i < m; i ++)
        {
            tmp[i] = t[i];
            tmp[l - i - 1] = t[i];
        }
        if (l & 1)
            tmp[m] = t[m];
        (*ret)[size - 1] = tmp;
    }
    else
    {
        char c = t[s];

        for (int i = s; i <= e; i ++)
        {
            bool done = false;
            char tmp = t[i];
            for (int j = s; j < i; j ++)
                if (t[j] == tmp)
                {
                    done = true;
                    break;
                }
            if (done)
                continue;

            t[i] = c;
            t[s] = tmp;
            gp(t, l, m, ret, rt, s + 1, e);
            t[i] = tmp;
            t[s] = c;
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generatePalindromes(char* s, int* returnSize)
{
    *returnSize = 0;
    char** ret = NULL;

    if (!s || !(*s))
        return ret;

    int c1 = 0;
    int c[256] = {0};

    int all = 0;
    int l = 0;
    int x = 0;

    while(s[l])
    {
        char t = s[l ++];

        x ^= t;

        if (c[t] & 1)
            all --;
        else
            all ++;

        c[t] ++;
    }

    if (x ? (all != 1 || !c[x]) : all)
        return ret;

    int m = l / 2;
    int rt = 0;
    char* t = malloc(l + 1);
    t[l] = 0;
    int ti = 0;

    for (int i = 0; i < 256; i ++)
    {
        int num = c[i];
        if (num)
        {
            if (num & 1)
            {
                t[m] = i;
                num --;
            }

            num >>= 1;
            while (num --)
                t[ti ++] = i;
        }
    }

    gp(t, l, m, &ret, &rt, 0, m - 1);
    *returnSize = rt;
    return ret;
}
