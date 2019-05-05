/* can not do by just removing smallest one, it could be used */
/* DO IT TWICE !!!!!! */
/* once per start but size - 1, the other is start + 1, and size - 1 */
/* this is better solution and also O(1) space solution. */
/* Just need i - 1 and i - 2, so there is no need to use memory */
int rob(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize == 1 ? nums[0] : 0;

    if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];

    int* tmp = malloc(sizeof(int) * numsSize);

    int tpp = nums[1];
    int tp = nums[2] > nums[1] ? nums[2] : nums[1];

    int spp = nums[0];
    int sp = nums[1] > nums[0] ? nums[1] : nums[0];

    int ns = 0;
    int ts = 0;

    for (int i = 2; i < numsSize - 1; i++)
    {
        ns = nums[i] + spp;
        spp = sp;
        sp = ns > sp ? ns : sp;

        ts = nums[i + 1] + tpp;
        tpp = tp;
        tp = ts > tp ? ts : tp;
    }
    return sp > tp ? sp : tp;
}
/*

    int* tmp = malloc(sizeof(int) * numsSize);

    tmp[0] = nums[1];
    tmp[1] = nums[2] > nums[1] ? nums[2] : nums[1];
    nums[1] = nums[1] > nums[0] ? nums[1] : nums[0];


    int ns;
    int ts;
    int pre_t = tmp[1];
    int pre_n = nums[1];

    for (int i = 2; i < numsSize - 1; i++)
    {
        ns = nums[i] + nums[i - 2];
        pre_n = nums[i] = ns > pre_n ? ns : pre_n;
        ts = nums[i + 1] + tmp[i - 2];
        pre_t = tmp[i] = ts > pre_t ? ts : pre_t;
    }

    return tmp[numsSize - 2] > nums[numsSize - 2] ? tmp[numsSize - 2] : nums[numsSize -2];


    int* tmp = malloc(sizeof(int) * numsSize - 1);
    memcpy(tmp, nums, sizeof(int) * numsSize);

    int r = rb(tmp, numsSize);

    if (tmp[numsSize - 1] == tmp[numsSize - 2])
        return r;

    int min_i = 0;
    int min = INT_MAX;

    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
            min_i = i;
        }
    }

    int ti = 0;
    for (int i = min_i + 1; i < numsSize; i ++)
        tmp[ti ++] = nums[i];

    for (int i = 0; i < min_i; i ++)
        tmp[ti ++] = nums[i];

    return rb(tmp, ti);
}

int rb(int* nums, int numsSize)
{
    nums[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    int s;
    int pre = nums[1];
    for (int i = 2; i < numsSize; i++)
    {
        s = nums[i] + nums[i - 2];
        pre = nums[i] = s > pre ? s : pre;
    }

    return nums[numsSize - 1];
}

int rob(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize == 1 ? nums[0] : 0;

    if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];

    int* tmp = malloc(sizeof(int) * numsSize - 1);
    memcpy(tmp, nums, sizeof(int) * numsSize);

    int a = rb(tmp + 1, numsSize - 1);
    int b = rb(nums, numsSize - 1);

    return a > b ? a : b;

}

*/
