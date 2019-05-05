void _me(int* nums, int numsSize, int l, int mask, int* rs, int* ri)
{
    if (l == 4)
    {
        *(rs + (*ri)) = mask;
        (*ri) ++;
        return;
    }

    int shift = 24;
    int min = numsSize / 3;
    shift -= 8 * l;
    int slot[256] = {0};
    int smask[4] = {0, 0xFF000000, 0xFFFF0000, 0xFFFFFF00};

    int t1 = -1;
    int t2 = -1;

    for (int i = 0; i < numsSize; i ++)
    {
        if ((nums[i] & smask[l]) != mask)
            continue;

        int x = (nums[i] >> shift) & 0xFF;
        slot[x] ++;

        if (slot[x] > min)
        {
            if (t1 == -1)
                t1 = x;
            else
            {
                t2 = x;
                break;
            }

            slot[x] -= numsSize;
        }
    }

    if (t1 != -1)
        _me(nums, numsSize, l + 1, mask | (t1 << shift), rs, ri);

    if (t2 != -1 && *ri < 2)
        _me(nums, numsSize, l + 1, mask | (t2 << shift), rs, ri);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int ri = 0;
    int* r = malloc(sizeof(int) * 2);
    _me(nums, numsSize, 0, 0, r, &ri);
    *returnSize = ri;
    return r;
}
