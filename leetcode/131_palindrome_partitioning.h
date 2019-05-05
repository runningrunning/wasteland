void _pp(char* s, int start, int l, int* e, int i, char**** ret, int** ci, int* ri)
{
    if (start == l)
    {
        (*ri) ++;
        int n = *ri;
        *ci = realloc(*ci, sizeof(int) * n);
        *ret = realloc(*ret, sizeof(char**) * n);
        (*ci)[n - 1] = i;

        char** t = malloc(sizeof(char*) * i);
        (*ret)[n - 1] = t;

        int pre = 0;
        for (int ei = 0; ei < i; ei ++)
        {
            int tl = e[ei] - pre + 1;
            t[ei] = malloc(tl + 1);
            strncpy(t[ei], s + pre, tl);
            t[ei][tl] = 0;
            pre = e[ei] + 1;
        }
        return;
    }

    int x = 0;
    for (int si = 0; si < l - start; si ++)
    {
        x ^= s[start + si];
        int m = si >> 1;

        if ((si & 1) ? !x : (x == s[start + m]))
        {
            int ti = 0;
            for (; ti <= m; ti ++)
                if (s[start + ti] != s[start + si - ti])
                    break;

            if (ti > m)
            {
                e[i] = start + si;
                _pp(s, start + si + 1, l, e, i + 1, ret, ci, ri);
            }
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** partition(char* s, int** columnSizes, int* returnSize)
{
    int ri = 0;
    int* ci = NULL;
    char*** ret = NULL;

    int l = strlen(s);
    int* end = malloc(sizeof(int) * l);
    _pp(s, 0, l, end, 0, &ret, &ci, &ri);
    *columnSizes = ci;
    *returnSize = ri;
    return ret;
}
