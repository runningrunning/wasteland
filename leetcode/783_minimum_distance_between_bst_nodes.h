// another method ?
void mdib(struct TreeNode* root, int* min, int l, int r)
{
    int k = root->val;

    if (k != l)
    {
        if (*min > k - l)
            *min = k - l;
    }

    if (k != r)
    {
        if (*min > r - k)
            *min = r - k;
    }

    if (root->right)
        mdib(root->right, min, root->val, r);

    if (root->left)
        mdib(root->left, min, l, root->val);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDiffInBST(struct TreeNode* root)
{
    if (!root)
        return 0;

    int left;
    struct TreeNode* r = root;
    while (r->left)
        r = r->left;
    left = r->val;

    int right;
    r = root;
    while (r->right)
        r = r->right;
    right = r->val;

    int min = INT_MAX;
    mdib(root, &min, left, right);
    return min;
}
