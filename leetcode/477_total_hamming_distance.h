int totalHammingDistance(int* nums, int numsSize)
{
    int all = 0;
    int bits = 1;
    int count = 0;

    int total = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        int n = nums[i];
        all |= n;
        count += (n & bits) ? 1 : 0;
    }

    all &= ~bits;
    total += count * (numsSize - count);

    while (all)
    {
        bits <<= 1;
        count = 0;
        for (int i = 0; i < numsSize; i ++)
            count += (nums[i] & bits) ? 1 : 0;
        total += count * (numsSize - count);
        all &= ~bits;
    }
    return total;
}
