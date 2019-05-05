// stupid typo !
// write simple code
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isc(struct TreeNode* root, int i, int l, bool* right, bool* result)
{
    if (*result)
        return false;

    if (!root)
    {
        if (i < (l - 1) || i > l || (*right && (i > l - 1)))
        {
            printf("i %d, l %d, *right %d.\n", i, l, *right);
            *result = true;
            return false;
        }

        if (i == l - 1)
            *right = true;
        return true;
    }

    if (!_isc(root->left, i + 1, l, right, result))
        return false;
    return _isc(root->right, i + 1, l, right, result);
}

bool isCompleteTree(struct TreeNode* root)
{
    int ll = 0;
    struct TreeNode* t = root;

    while (t->left)
    {
        ll ++;
        t = t->left;
    }

    int lr = 0;
    t = root;

    while (t->right)
    {
        lr ++;
        t = t->right;
    }

    if (lr > ll || ll - lr > 1)
        return false;

    bool get = false;
    bool right = false;
    return _isc(root, 0, ll + 1, &right, &get);
}
