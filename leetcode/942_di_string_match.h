/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 **/

int* diStringMatch(char* S, int* returnSize)
{
    int* r;

    if (!S || !S[0])
    {
        *returnSize = 1;
        r = malloc(sizeof(int));
        r[0] = 0;
        return r;
    }

    int l = strlen(S);
    r = malloc(sizeof(int) * (l + 1));
    *returnSize = l + 1;

    int e = l;
    int s = 0;

    for (int i = l - 1; i >= 0; i --)
    {
        if (S[i] == 'D')
            r[i + 1] = s ++;
        else
            r[i + 1] = e --;
    }
    r[0] = s;
    return r;
}
