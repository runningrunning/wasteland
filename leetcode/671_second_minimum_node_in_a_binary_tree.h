void fsmv(struct TreeNode* r, int min, int* t)
{
    if (!r->left || r->val != min)
        return;

    int max = r->left->val;
    max = max == min ? r->right->val : max;

    if (max != min)
    {
        if (max < *t || *t == -1)
            *t = max;
    }
    fsmv(r->left, min, t);
    fsmv(r->right, min, t);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root)
{
    if (!root)
        return 0;

    int n = -1;
    fsmv(root, root->val, &n);
    return n;
}
