int _index(int* ns, int s, int e, int t)
{
    if (s >= e)
        return s;

    int m = s + (e - s) / 2;

    if (ns[m] < t)
        return _index(ns, m + 1, e, t);
    return _index(ns, s, m, t);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    if (!numbers || numbersSize < 2)
        return NULL;
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);

    int e = numbersSize - 1;
    for(int i = 0; i < numbersSize - 1; i ++)
    {
        ret[0] = i + 1;
        e = _index(numbers, i + 1, e, target - numbers[i]);
        if (numbers[i] + numbers[e] == target)
        {
            ret[1] = e + 1;
            return ret;
        }
    }
    return NULL;
}
