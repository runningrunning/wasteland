/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize)
{
    int i = 0;
    int c = S[i ++];

    int l = 0;
    int n = 0;
    while (c)
    {
        c -= 'a';
        n += widths[c];

        if (n > 100)
        {
            l ++;
            n = widths[c];
        }
        c = S[i ++];
    }

    *returnSize = 2;

    int* r = malloc(sizeof(int) * 2);
    r[0] = i == 1 ? 0 : (l + 1);
    r[1] = n;
    return r;
}
