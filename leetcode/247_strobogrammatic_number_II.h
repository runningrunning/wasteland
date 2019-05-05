/* use recursive to do full arrange as it's storing everything */
void fsg(char* sample, int i, int m, int n, char** ret, int* si)
{
    if (i == m)
        ret[(*si) ++] = strdup(sample);
    else
    {
        if (i == n - 1 - i)
        {
            sample[i] = '0';
            fsg(sample, i + 1, m, n, ret, si);
            sample[i] = '1';
            fsg(sample, i + 1, m, n, ret, si);
            sample[i] = '8';
            fsg(sample, i + 1, m, n, ret, si);
        }
        else
        {
            if (i)
            {
                sample[i] = '0';
                sample[n - 1 - i] = '0';
                fsg(sample, i + 1, m, n, ret, si);
            }

            sample[i] = '1';
            sample[n - 1 - i] = '1';
            fsg(sample, i + 1, m, n, ret, si);
            sample[i] = '6';
            sample[n - 1 - i] = '9';
            fsg(sample, i + 1, m, n, ret, si);
            sample[i] = '8';
            sample[n - 1 - i] = '8';
            fsg(sample, i + 1, m, n, ret, si);
            sample[i] = '9';
            sample[n - 1 - i] = '6';
            fsg(sample, i + 1, m, n, ret, si);
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 0, 1, 6, 8, 9 */
/* full arrange */
char** findStrobogrammatic(int n, int* returnSize)
{
    *returnSize = 0;
    if (!n)
        return NULL;

    int num = 1;
    int m = (n + 1) / 2;

    for (int i = 0; i < m; i ++)
    {
        if (i == n - 1 - i)
            num *= 3;
        else
            num *= i ? 5 : 4;
    }

    *returnSize = num;

    int si = 0;
    char** ret = malloc(sizeof(char*) * num);
    char* sample = malloc(n + 1);
    memset(sample, 0, n + 1);

    fsg(sample, 0, m, n, ret, &si);

    return ret;
}
