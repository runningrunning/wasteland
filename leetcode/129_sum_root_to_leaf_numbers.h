void sum(struct TreeNode* r, int* num, int n)
{
    if (r)
    {
        int next = (n * 10) + r->val;
        if (!r->right && !r->left)
            *num += next;

        if (r->right)
            sum(r->right, num, next);

        if (r->left)
            sum(r->left, num, next);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root)
{
    int all = 0;
    sum(root, &all, 0);
    return all;
}
