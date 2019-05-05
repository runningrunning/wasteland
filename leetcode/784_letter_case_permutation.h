/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCasePermutation(char* S, int* returnSize)
{
    int n = 1;
    int i = 0;

    char c = S[i ++];
    while (c)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            n *= 2;
        c = S[i ++];
    }

    *returnSize = n;
    char** ret = malloc(sizeof(char*) * n);

    for (int j = 0; j < n; j ++)
    {
        char* t = strdup(S);

        if (j)
        {
            int m = j;
            for (int k = 0; k < i; k ++)
            {
                if (t[k] >= 'a' && t[k] <= 'z' || t[k] >= 'A' && t[k] <= 'Z')
                {
                    if (m & 1)
                        t[k] = (t[k] >= 'a' && t[k] <= 'z') ? t[k] - ('a' - 'A') : t[k] + ('a' - 'A');
                    m >>= 1;
                    if (!m)
                        break;
                }
            }
        }
        ret[j] = t;
    }
    return ret;
}

