/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generatePossibleNextMoves(char* s, int* returnSize)
{
    int l = strlen(s);
    *returnSize = 0;

    if (l < 2)
        return NULL;

    int c = 0;
    char** ret = malloc(sizeof(int*) * l);

    for (int i = 1; i < l; i ++)
    {
        if (s[i] == s[i - 1] && s[i] == '+')
        {
            char* t = strdup(s);
            ret[c ++] = t;
            t[i] = '-';
            t[i - 1] = '-';
        }
    }
    *returnSize = c;
    return ret;
}
