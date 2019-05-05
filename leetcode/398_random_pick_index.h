// just use hash and index table should be enough
typedef struct
{
    int primer;
    int ns;
    int* hash;
    int* nums;
    int* nids;
} Solution;

Solution* solutionCreate(int* nums, int numsSize)
{
    Solution* s = malloc(sizeof(Solution));
    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};

    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 8; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 4 > numsSize)
            break;
    }

    s->primer = dp;
    int* hash = malloc(sizeof(int) * dp);
    memset(hash, 0, sizeof(int) * dp);

    int* ids = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        ids[i] = 0;

        // force negative to positive
        long n = nums[i] & 0xFFFFFFFF;
        int x = n % dp;
        while (hash[x] && nums[hash[x] - 1] != nums[i])
            x = (x + 1) % dp;

        if (hash[x])
        {
            ids[i] = ids[hash[x] - 1];
            ids[hash[x] - 1] = i;
        }
        else
            ids[i] = i;
        hash[x] = i + 1;
    }
    s->nids = ids;
    s->hash = hash;
    s->ns = numsSize;
    s->nums = nums;
    return s;
}

int solutionPick(Solution* obj, int target)
{
    if (obj)
    {
        int dp = obj->primer;
        long n = target & 0xFFFFFFFF;
        int x = n % dp;

        int* hash = obj->hash;
        int* ids = obj->nids;
        int* nums = obj->nums;

        while (hash[x] && nums[hash[x] - 1] != target)
            x = (x + 1) % dp;

        int i = hash[x] - 1;

        if (ids[i] == i)
            return i;

        x = i;

        int r = rand();
        int o = r;

        while (r && ids[x] != i)
        {
            r --;
            x = ids[x];
        }

        int s = o - r + 1;
        r = o % s;
        x = i;

        while (r --)
            x = ids[x];
        return x;
    }
    return 0;
}

void solutionFree(Solution* obj)
{
    if (obj)
    {
        free(obj->hash);
        free(obj->nids);
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 * solutionFree(obj);
 */
