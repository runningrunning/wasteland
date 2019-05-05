/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool ls(struct TreeNode* r, int* m, int* i, int mi)
{
    if (!r->left && !r->right)
    {
        if (!mi)
            m[*i] = r->val;
        else if (r->val != m[*i])
            return false;

        (*i) ++;
    }

    if (r->left && !ls(r->left, m, i, mi))
        return false;

    if (r->right && !ls(r->right, m, i, mi))
        return false;

    return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1 || !root2)
        return root1 == root2;

    int i = 0;
    int mi = 0;
    int m[256];

    ls(root1, m, &mi, mi);
    return ls(root2, m, &i, mi);
}
