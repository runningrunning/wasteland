void _tbst(struct TreeNode* root, struct TreeNode** p, int L, int R)
{
    if (root->val >= L && root->val <= R)
    {
        *p = root;
        if (root->left)
            _tbst(root->left, &root->left, L, R);

        if (root->right)
            _tbst(root->right, &root->right, L, R);
    }
    else
    {
        if ((root->val < L && !root->right) || (root->val > R && !root->left))
            *p = NULL;
        else
        {
            if (root->val < L)
                _tbst(root->right, p, L, R);
            else
                _tbst(root->left, p, L, R);
        }
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
struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
    if (!root)
        return root;

    struct TreeNode* r;
    _tbst(root, &r, L, R);
    return r;
}
