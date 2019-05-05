/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */


// TODO how to use segment tree !!!!
// binary search works

/*
class Solution {

    int _random(long x)
    {
        return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
    }

    int N;
    int size;
    long* nums;
    int p;

 public:
    Solution(int num, vector<int> blacklist) {
        size = 0;
        nums = NULL;
        N = num;

        p = _random((long) 38888);

        if (blacklist.size())
        {
            sort(blacklist.begin(), blacklist.end());
            int blacklistSize = blacklist.size();

            size = 0;
            nums = (long*) malloc(sizeof(long) * blacklistSize + 1);

            long l = 0;
            if (blacklist[0] != 0)
            {
                l = blacklist[0];
                nums[size ++] = l << 32 | (blacklist[0] - 1);
            }

            for (int i = 1; i < blacklistSize; i ++)
            {
                if (blacklist[i] == blacklist[i - 1] + 1)
                    continue;
                l += blacklist[i] - blacklist[i - 1] - 1;
                nums[size ++] = l << 32 | (blacklist[i] - 1);
            }

            if (blacklist[blacklistSize - 1] != N - 1)
            {
                l += num - 1 - blacklist[blacklistSize - 1];
                nums[size ++] = l << 32 | (N - 1);
            }
        }
        N -= blacklist.size();
    }
    int pick() {
        p = _random(p);

        long x = p % N;
        if (!nums)
            return x;

        x ++;
        x <<= 32;

        int s = 0;
        int e = size - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] < x)
                s = m + 1;
            else
                e = m;
        }

        int st = nums[s] & 0xFFFFFFFF;
        int sl = nums[s] >> 32;

        x >>= 32;
        return st - (sl - x);
    }
};
*/

int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct {
    int p;
    int N;
    int size;
    long* nums;
} Solution;

Solution* solutionCreate(int N, int* blacklist, int blacklistSize) {
    Solution* s = malloc(sizeof(Solution));
    s->size = 0;
    s->nums = NULL;
    s->N = N - blacklistSize;
    s->p = _random((long) s);

    if (blacklist && blacklistSize)
    {
        qsort(blacklist, blacklistSize, sizeof(int), comp);
        int size = 0;
        long* nums = malloc(sizeof(long) * blacklistSize + 1);

        long l = 0;
        if (blacklist[0] != 0)
        {
            l = blacklist[0];
            nums[size ++] = l << 32 | (blacklist[0] - 1);
        }

        for (int i = 1; i < blacklistSize; i ++)
        {
            if (blacklist[i] == blacklist[i - 1] + 1)
                continue;
            l += blacklist[i] - blacklist[i - 1] - 1;
            nums[size ++] = l << 32 | (blacklist[i] - 1);
        }

        if (blacklist[blacklistSize - 1] != N - 1)
        {
            l += N - 1 - blacklist[blacklistSize - 1];
            nums[size ++] = l << 32 | (N - 1);
        }
        s->nums = nums;
        s->size = size;
    }
    return s;
}

int solutionPick(Solution* obj) {
    if (!obj)
        return 0;

    obj->p = _random(obj->p);

    long x = obj->p % obj->N;
    if (!obj->nums)
        return x;

    x ++;
    x <<= 32;

    int s = 0;
    int e = obj->size - 1;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        if (obj->nums[m] < x)
            s = m + 1;
        else
            e = m;
    }

    int st = obj->nums[s] & 0xFFFFFFFF;
    int sl = obj->nums[s] >> 32;
    x >>= 32;
    return st - (sl - x);
}

void solutionFree(Solution* obj) {
    if (obj)
    {
        free(obj->nums);
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(N, blacklist, blacklistSize);
 * int param_1 = solutionPick(obj);
 * solutionFree(obj);
 */
