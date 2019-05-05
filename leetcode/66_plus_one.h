/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int pos = -1;
    for(int i = 0; i < digitsSize; i ++)
    {
        if (digits[i] != 9)
            pos = i;
    }

    for (int i = pos + 1; i < digitsSize; i ++)
        digits[i] = 0;

    int* ret = malloc(sizeof(int) * (digitsSize + 1));

    if (pos == -1)
    {
        ret[0] = 1;
        *returnSize = digitsSize + 1;
        memcpy(ret + 1, digits, sizeof(int) * digitsSize);
    }
    else
    {
        memcpy(ret, digits, sizeof(int) * digitsSize);
        *returnSize = digitsSize;
        ret[pos] += 1;
    }

    return ret;
}

