/* Careful about return value */
void _soll(struct TreeNode* r, bool left, int* sum)
{
    if (!r->left && !r->right)
    {
        if (left)
            *sum += r->val;
    }
    else
    {
        if (r->left)
            _soll(r->left, true, sum);

        if (r->right)
            _soll(r->right, false, sum);
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
int sumOfLeftLeaves(struct TreeNode* root)
{
    if (!root)
        return 0;
    int s = 0;
    _soll(root, false, &s);

    return s;
}
