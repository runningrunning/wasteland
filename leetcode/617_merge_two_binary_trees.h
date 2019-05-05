void mt(struct TreeNode* t1, sturct TreeNode* t2)
{
    t1->val += t2->val;

    if (t1->left && t2->left)
        mt(t1->left, t2->left);
    else
    {
        if (!t1->left)
            t1->left = t2->left;
    }

    if (t1->right && t2->right)
        mt(t1->right, t2->right);
    else
    {
        if (!t1->right)
            t1->right = t2->right;
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
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    if (!t1 || !t2)
        return t1 ? t1 : t2;

    mt(t1, t2);
    return t1;
}
