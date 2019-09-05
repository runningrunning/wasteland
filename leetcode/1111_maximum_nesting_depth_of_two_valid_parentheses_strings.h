/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize)
{
    int max = 0;
    int s = 0;
    int i = 0;

    while (seq[i])
    {
        int a = seq[i ++];

        if (a == '(')
        {
            s ++;
            if (s > max)
                max = s;
        }
        else
            s --;
    }
    max = (max + 1) / 2;

    int* r = malloc(sizeof(int) * i);
    *returnSize = i;
    i = 0;

    while (seq[i])
    {
        int a = seq[i];

        if (a == '(')
        {
            s ++;
            r[i ++] = s > max ? 1 : 0;
        }
        else
        {
            r[i ++] = s > max ? 1 : 0;
            s --;
        }
    }
    return r;
}

