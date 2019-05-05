/* rand all is too large, so rand each step if size > 13 */
/* /\* idea copy form 46 permutations, 47 permutations II *\/ */
typedef struct {
    int size;
    int all;
    int* ori;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution* s = malloc(sizeof(Solution));
    s->all = 0;
    s->size = size;
    s->ori = malloc(sizeof(int) * size);
    memcpy(s->ori, nums, sizeof(int) * size);

    if (size < 14)
    {
        int all = size;
        for (int i = size - 1; i > 0; i --)
            all *= i;
        s->all = all;
    }
    return s;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    if (!obj)
        return NULL;

    int* t = NULL;
    *returnSize = obj->size;
    if (!obj->size)
        return t;

    t = malloc(sizeof(int) * obj->size);
    memcpy(t, obj->ori, sizeof(int) * obj->size);
    return t;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    int* t = solutionReset(obj, returnSize);
    if (!t)
        return t;

    int s = obj->size;

    if (obj->all)
    {
        int a = obj->all;
        int r = rand() % a;

        int st = 0;
        int en;
        while(r)
        {
            a /= s;
            s --;
            en = r / a;
            r %= a;
            if (en)
            {
                int temp = t[st];
                t[st] = t[st + en];
                t[st + en] = temp;
            }
            st ++;
        }
    }
    else
    {
        int os = s;
        for (int i = 0; i < s - 1; i ++)
        {
            int r = rand() % os;
            if (r)
            {
                int temp = t[i];
                t[i] = t[i + r];
                t[i + r] = temp;
            }
            os --;
        }
    }
    return t;
}

void solutionFree(Solution* obj) {
    if (obj)
        free(obj->ori);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */
