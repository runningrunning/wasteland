// two points
// s >= e
// i >= e
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void _sort(int* n, int s, int e)
{
    if (s >= e) // HINT
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s])
            i ++;
        while (n[e] > n[s])
            e --;

        if (i >= e) // HINT
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    _sort(n, os, e - 1);
    _sort(n, e + 1, oe);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    if (!nums || numsSize < 2)
        return nums;

    int i = 1;
    for (; i < numsSize; i ++)
        if (nums[i] < nums[i - 1])
            break;

    if (i == numsSize)
        return nums;

    _sort(nums, 0, numsSize - 1);
    // int* ret = malloc(sizeof(int) * numsSize);
    // memcpy(ret, nums, sizeof(int) * numsSize);
    // *returnSize = numsSize;
    return nums;
}
