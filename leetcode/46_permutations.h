// Cheating
void swap(int* a1, int *a2)
{
    if (a1 == a2)
        return;
    *a1 ^= *a2;
    *a2 ^= *a1;
    *a1 ^= *a2;
}

void find(int* nums, int numsSize, int start, int end, int** ret, int* returnSize)
{
    if (start == end)
    {
        memcpy(ret[*returnSize], nums, sizeof(int) * numsSize);
        (*returnSize) ++;
    }
    else
    {
        for(int i = start; i <= end; i ++)
        {
            swap(nums + start, nums + i);
            find(nums, numsSize, start + 1, end, ret, returnSize);
            swap(nums + start, nums + i);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    if (!numsSize)
    {
        *returnSize = 0;
        return NULL;
    }

    int all = 1;
    for(int i = 1; i <= numsSize; i++)
        all *= i;

    int** ret = malloc(sizeof(int*) * all);
    for(int i = 0; i < all; i ++)
        ret[i] = malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    find(nums, numsSize, 0, numsSize - 1, ret, returnSize);
    return ret;
}
