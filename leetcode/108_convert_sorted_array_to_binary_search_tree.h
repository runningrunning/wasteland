void cov(struct TreeNode** i, int* nums, int s, int e)
{
    *i = NULL;

    if(s > e)
        return;

    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    *i = r;
    int m = ((e - s) / 2 + s);
    r->val = nums[m];
    cov(&r->left, nums, s, m - 1);
    cov(&r->right, nums, m + 1, e);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (!numsSize)
        return NULL;
    struct TreeNode* r;
    cov(&r, nums, 0, numsSize - 1);
    return r;
}
