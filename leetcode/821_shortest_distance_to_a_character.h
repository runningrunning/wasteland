/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize)
{
    int l = strlen(S);
    int* r = malloc(sizeof(int) * l);
    int pre = -l;

    for (int i = 0; i < l; i ++)
    {
        r[i] = i - pre;
        if (S[i] != C)
            continue;
        pre = i;

        r[i] = 0;
        int j = i - 1;
        while (j >= 0 && r[j] > i - j)
        {
            r[j] = i - j;
            j --;
        }
    }

    *returnSize = l;
    return r;
}
