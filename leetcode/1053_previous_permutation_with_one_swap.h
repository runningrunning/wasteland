// use hash ?? to find the next biggest ???
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prevPermOpt1(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;
    int min = 10001;
    int s[10001] = {0};
    for (int i = ASize - 1; i >= 0; i --)
    {
        int c = A[i];

        if (c > min)
        {
            for (int j = c - 1; j >= 0; j --)
                if (s[j])
                {
                    A[s[j] - 1] = c;
                    A[i] = j;
                    break;
                }
            break;
        }

        s[c] = i + 1;
        min = min < c ? min : c;
    }
    return A;
}

