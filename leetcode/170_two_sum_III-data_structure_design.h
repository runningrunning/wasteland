// use lookup table per int is very fast, but not reasonable to do so.
// learn a lot here
#define NUM 5120
/* bst, hash table */
typedef struct {
    int n;
    int* is;
} TwoSum;

/** Initialize your data structure here. */
TwoSum* twoSumCreate() {
    TwoSum* t = malloc(sizeof(TwoSum));
    t->n = 0;
    t->is = malloc(sizeof(int) * NUM);
    return t;
}

/** Add the number to an internal data structure.. */
void twoSumAdd(TwoSum* obj, int number) {
    if (obj)
    {
        int* is = obj->is;
        is[obj->n ++] = number;

        if (!(obj->n % NUM))
            obj->is = realloc(obj->is, sizeof(int) * (obj->n + NUM));

        // reassign is, STUPID MISTAKE not do do so
        is = obj->is;

        int t;
        for (int i = obj->n - 1; i > 0; i --)
        {
            if (is[i] < is[i - 1])
            {
                t = is[i];
                is[i] = is[i - 1];
                is[i - 1] = t;
            }
            else
                break;
        }
    }
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
bool twoSumFind(TwoSum* obj, int v) {
    if (obj)
    {
        if (obj->n <= 1)
            return false;

        int s = 0;
        int e = obj->n - 1;

        int* is = obj->is;
        int t = is[s] + is[e];

        while (s < e)
        {
            t = is[s] + is[e];

            if (t < v)
                s = s + 1;
            else if (t > v)
                e = e - 1;
            else
                return true;
        }
    }
    return false;
}

void twoSumFree(TwoSum* obj) {
    if (obj)
    {
        free(obj->is);
        free(obj);
    }
}

/**
 * Your TwoSum struct will be instantiated and called as such:
 * struct TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 * bool param_2 = twoSumFind(obj, value);
 * twoSumFree(obj);
 */
