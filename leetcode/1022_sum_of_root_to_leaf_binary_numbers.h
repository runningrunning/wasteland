/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// known can not exceed 2^31 - 1

void strl(struct TreeNode* root, int l, long cur, long* all)
{
    if (root->val)
        cur |= 1L << (63 - l);
    if (root->left || root->right)
    {
        if (root->left)
            strl(root->left, l + 1, cur, all);
        if (root->right)
            strl(root->right, l + 1, cur, all);
    }
    else
        *all += cur >> (63 - l);
}

int sumRootToLeaf(struct TreeNode* root)
{
    if (!root)
        return 0;
    long all = 0L;
    long cur = 0L;
    strl(root, 1, cur, &all);
    return (int) all;
}
