/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize)
{
    char** ret = malloc(sizeof(char*) * n);
    for (int j = 1; j <= n; j ++)
    {
        int i = j - 1;
        if (!(j % 15))
            ret[i] = strdup("FizzBuzz");
        else if (!(j % 3))
            ret[i] = strdup("Fizz");
        else if (!(j % 5))
            ret[i] = strdup("Buzz");
        else
        {
            ret[i] = malloc(16);
            sprintf(ret[i], "%d", j);
        }
    }

    *returnSize = n;
    return ret;
}
