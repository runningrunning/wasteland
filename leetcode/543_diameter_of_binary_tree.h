int dobt(struct TreeNode* n, int* max)
{
    int l = 0;
    if (n->left)
        l = 1 + dobt(n->left, max);
    int r = 0;
    if (n->right)
        r = 1 + dobt(n->right, max);

    if (l + r > *max)
        *max = l + r;

    return l > r ? l : r;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root)
{
    int max = INT_MIN;
    dobt(root, &max);
    return max;
}
