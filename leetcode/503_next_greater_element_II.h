/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    int i = 0;

    *returnSize = numsSize;
    int* ret = malloc(sizeof(int) *  numsSize);

    int si = 0;
    int* stack = malloc(sizeof(int) * numsSize);

    int c = 0;
    int max = INT_MIN;

    for (i = 0; i < numsSize; i ++)
    {
        if (nums[i] > max)
            max = nums[i];

        if (!si)
        {
            c = nums[i];
            ret[i] = -1;
            stack[si ++] = i;
        }
        else
        {
            int t = nums[i];

            while (t > c)
            {
                ret[stack[si - 1]] = t;
                si --;
                if (!si)
                    break;
                c = nums[stack[si - 1]];
            }

            ret[i] = -1;
            c = t;
            stack[si ++] = i;
        }
    }

    if (si)
    {
        for (i = 0; i < numsSize; i++)
        {
            while (c == max)
            {
                ret[stack[si - 1]] = -1;
                si --;
                if (!si)
                    break;
                c = nums[stack[si - 1]];
            }

            if (!si)
                break;

            int t = nums[i];
            while (t > c)
            {
                ret[stack[si - 1]] = t;
                si --;
                if (!si)
                    break;
                c = nums[stack[si - 1]];
            }
            if (!si)
                break;
        }
    }
    return ret;
}
