/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void _cc(char* a, int* t)
{
    int i = 0;
    while (a[i])
        t[a[i ++] - 'a'] ++;
}

char** commonChars(char** A, int ASize, int* returnSize)
{
    if (!A || !ASize)
        return 0;

    int nums[26] = {0};
    _cc(A[0], nums);

    for (int i = 1; i < ASize; i ++)
    {
        int c[26] = {0};
        _cc(A[i], c);

        for (int j = 0; j < 26; j ++)
            nums[j] = nums[j] < c[j] ? nums[j] : c[j];
    }

    int all = 0;
    for (int i = 0; i < 26; i ++)
        all += nums[i];

    *returnSize = all;
    char** ret = malloc(sizeof(char*) * all);

    int in = 0;
    for (int i = 0; i < 26; i ++)
    {
        while (nums[i])
        {
            ret[in] = malloc(sizeof(char) * 2);
            ret[in][0] = 'a' + i;
            ret[in][1] = 0;
            in ++;
            nums[i] --;
        }
    }
    return ret;
}
