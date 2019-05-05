void ps(struct TreeNode* r, int* a, int n, int sum, int* num)
{
    a[n] = r->val;

    int all = 0;
    for (int i = n; i >= 0; i --)
    {
        all += a[i];

        if (all == sum)
            (*num) ++;
    }

    if (r->right)
        ps(r->right, a, n + 1, sum, num);

    if (r->left)
        ps(r->left, a, n + 1, sum, num);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pathSum(struct TreeNode* root, int sum)
{
    if (!root)
        return 0;

    int num = 0;
    int a[1024] = {0};
    ps(root, a, 0, sum, &num);
    return num;
}
