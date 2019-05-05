int singleNumber(int* nums, int numsSize)
{
    int and = 0;
    int xor = 0;

    for(int i = 0; i < numsSize; i ++)
    {
        int a = xor & nums[i];
        xor ^= nums[i];
        int t = ~(and & xor);
        and &= t;
        xor &= t;
        and |= a;
    }
    return xor;
}
