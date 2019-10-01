
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int foo(char* s)
{
    int cs[26] = {0};
    int i = 0;
    int n = 0;
    int m = 26;

    while (s[i])
    {
        int c = s[i] - 'a';

        if (c < m)
        {
            n = 0;
            m = c;
        }

        if (m == c)
            n ++;

        i ++;
    }

    return n;
}

int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize)
{
    int* ws = malloc(sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i ++)
        ws[i] = foo(words[i]);

    qsort(ws, wordsSize, sizeof(int), comp);

    int* rs = malloc(sizeof(int) * queriesSize);
    int min = ws[0];
    int max = ws[wordsSize - 1];

    for (int i = 0; i < queriesSize; i ++)
    {
        char* q = queries[i];
        int n = foo(q);

        if (n < min)
            rs[i] = wordsSize;
        else if (n >= max)
            rs[i] = 0;
        else
        {
            int s = 0;
            int e = wordsSize - 1;

            while (s < e)
            {
                int m = (s + e) / 2;
                if (ws[m] <= n)
                    s = m + 1;
                else
                    e = m;
            }
            rs[i] = wordsSize - s;
        }
    }

    *returnSize = queriesSize;
    return rs;
}

