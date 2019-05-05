typedef struct {
    int* left;
    int* right;
    int size;
    int all;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* n = malloc(sizeof(NumArray));
    n->size = numsSize;
    n->left = malloc(sizeof(int) * numsSize);
    n->right = malloc(sizeof(int) * numsSize);

    /* memcpy(n->left, nums, sizeof(int) * numsSize); */
    /* memcpy(n->right, nums, sizeof(int) * numsSize); */

    int l = 0;
    int r = 0;
    int s = numsSize;

    for(int i = 0; i < numsSize; i ++)
    {
        l += nums[i];
        r += nums[s - 1 - i];
        n->left[i] = l;
        n->right[s - 1 - i] = r;
    }
    n->all = l;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int t = 0;
    if (i > j)
    {
        t = j;
        j = i;
        i = t;
    }

    if (!obj || i < 0 || j >= obj->size)
        return 0;
    return (obj->left[j] + obj->right[i]) - obj->all;
}

void numArrayFree(NumArray* obj) {
    if (obj)
    {
        free(obj->left);
        free(obj->right);
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
