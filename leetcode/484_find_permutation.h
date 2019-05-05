/* TOO COMPLICATED, more practices !!! */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* findPermutation(char* s, int* returnSize)
{
    *returnSize = 0;
    int sl = strlen(s);
    if (!sl)
        return NULL;

    *returnSize = sl + 1;
    int* r = malloc(sizeof(int) * (sl + 1));

    int max = sl + 1;
    int sE = sl - 1;

    while(sE >= 0)
    {
        int sI = sE;

        if (s[sI] == 'I')
        {
            r[sI + 1] = max --;
            sE --;

            if (!sI)
                r[0] = max;
        }
        else
        {
            int end = sE;

            while(sI >= 0 && s[sI] == 'D')
                sI --;

            sE = sI - 1;

            r[sI + 1] = max --;

            for (int j = sI + 1; j <= end; j ++)
                r[j + 1] = max --;

            if (!sI && s[sI] == 'I')
                r[0] = max;
        }
    }

    return r;
}
*/

/* TOO COMPLICATED, more practices !!! */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPermutation(char* s, int* returnSize)
{
    *returnSize = 0;
    int sl = strlen(s);
    if (!sl)
        return NULL;

    *returnSize = sl + 1;
    int* r = malloc(sizeof(int) * (sl + 1));

    if (s[0] == 'I')
        r[0] = 1;

    int max = sl + 1;
    int sE = sl - 1;

    while(sE >= 0)
    {
        int sI = sE;
        while(sI >= 0 && s[sI] == 'D')
            sI --;
        for (int j = sI; j <= sE; j ++)
            r[j + 1] = max --;
        sE = sI - 1;
    }
    return r;
}
