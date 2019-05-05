/* BE CAREFUL !!! */
int cet(struct TreeNode* root, int* ret, int* rc)
{
    if (!root)
        return INT_MIN;

    int l = cet(root->left, ret, rc);
    int r = cet(root->right, ret, rc);
    l = l == INT_MIN ? 0 : l;
    r = r == INT_MIN ? 0 : r;
    int x = l + r + root->val;

    ret[*rc] = x;
    (*rc) ++;
    return x;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkEqualTree(struct TreeNode* root)
{
    if (!root)
        return false;

    int rc = 0;
    int r[10000];
    int a = cet(root, r, &rc);

    if (a & 1)
        return false;

    a /= 2;

    for (int i = rc - 2; i >= 0; i --)
        if (r[i] == a)
            return true;
    return false;
}
