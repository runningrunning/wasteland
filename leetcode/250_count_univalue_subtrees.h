bool cus(struct TreeNode* n, int* num)
{
    if (!n)
        return true;

    if (!n->left && !n->right)
    {
        (*num) ++;
        return true;
    }

    int nv = n->val;
    int lv = n->left ? n->left->val : nv;
    int rv = n->right ? n->right->val : nv;
    bool l = cus(n->left, num);
    bool r = cus(n->right, num);

    if (l && r && rv == lv && lv == nv)
    {
        (*num) ++;
        return true;
    }
    return false;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countUnivalSubtrees(struct TreeNode* root)
{
    int n = 0;
    cus(root, &n);
    return n;
}
