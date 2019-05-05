// learn a lot !!!
typedef struct {
    int level; // tree level
    int start;
    int* tree;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize)
{
    int l = 1;
    int lv = 0;
    while (l < numsSize)
    {
        l <<= 1;
        lv ++;
    }
    NumArray* na = malloc(sizeof(NumArray));
    int* tree = calloc(sizeof(int), l - 1 + numsSize);
    na->tree = tree;
    na->level = lv;
    na->start = l - 1;

    for (int i = 0; i < numsSize; i ++)
    {
        tree[l - 1 + i] = nums[i];
        int x = l - 1 + i;
        while (x)
        {
            x = (x - 1) / 2;
            tree[x] += nums[i];
        }
    }
    return na;
}

void numArrayUpdate(NumArray* obj, int i, int val)
{
    if (obj)
    {
        int* tree = obj->tree;
        int x = obj->start + i;
        int d = val - tree[x];
        tree[x] += d;
        while (x)
        {
            x = (x - 1) / 2;
            tree[x] += d;
        }
    }
}

void _range(int* tree, int x, int l, int i, int j, int* r)
{
    int t = x + 1;
    int s = (t << l) - 1;
    int e = s + (1 << l) - 1;

    if (i > e || j < s)
        return;

    if (i <= s && j >= e)
        (*r) += tree[x];
    else if (l)
    {
        _range(tree, x * 2 + 1, l - 1, i, j, r);
        _range(tree, x * 2 + 2, l - 1, i, j, r);
    }
}

int numArraySumRange(NumArray* obj, int i, int j)
{
    int r = 0;
    if (obj)
    {
        if (i == j)
            return obj->tree[obj->start + i];
        _range(obj->tree, 0, obj->level, i + obj->start, j + obj->start, &r);
    }
    return r;
}

void numArrayFree(NumArray* obj) {
    if (obj)
    {
        free(obj->tree);
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, i, val);
 * int param_2 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
