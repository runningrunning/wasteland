/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// try not to use recursion
int** getFactors(int n, int** cs, int* rs)
{
    *cs = NULL;
    *rs = 0;

    int si = 0;
    int s[32] = {2};
    int v[32] = {0};
    int* rcs = 0;
    int ri = 0;
    int** r = NULL;

    int t = n;
    while (true)
    {
        bool found = false;
        if (t > 3)
        {
            for (int i = s[si]; i <= sqrt(t); i ++)
                if (!(t % i))
                {
                    v[si] = i;
                    s[si ++] = i + 1;
                    s[si] = i;
                    t = t / i;
                    v[si] = t;
                    found = true;
                    break;
                }
        }

        if (!found)
        {
            si --;
            if (si < 0)
                break;
            t *= v[si];
        }
        else
        {
            // out(v, si + 1);
            if (!ri)
            {
                r = malloc(sizeof(int*));
                rcs = malloc(sizeof(int));
            }
            else
            {
                r = realloc(r, sizeof(int*) * (ri + 1));
                rcs = realloc(rcs, sizeof(int) * (ri + 1));
            }
            r[ri] = malloc(sizeof(int) * (si + 1));
            memcpy(r[ri], v, sizeof(int) * (si + 1));
            rcs[ri] = si + 1;
            ri ++;
        }
    }

    *rs = ri;
    *cs = rcs;
    return r;
}
