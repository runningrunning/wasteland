// favorite
void lbst(struct TreeNode* root, int* cur, int* max, int* vmin, int* vmax)
{
    *cur = 0;

    int lcur = 0;
    int lmin = root->val;
    bool lfalse = false;
    if (root->left)
    {
        lbst(root->left, &lcur, max, vmin, vmax);
        if (!lcur || root->val <= *vmax)
            lfalse = true;
        lmin = *vmin;
    }

    int rcur = 0;
    int rmax = root->val;
    bool rfalse = false;
    if (root->right)
    {
        lbst(root->right, &rcur, max, vmin, vmax);
        if (!rcur || root->val >= *vmin)
            rfalse = true;
        rmax = *vmax;
    }

    if (lfalse || rfalse)
        return;

    *cur = lcur + rcur + 1;
    if (*cur > *max)
        *max = *cur;

    *vmin = lmin;
    *vmax = rmax;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int largestBSTSubtree(struct TreeNode* root)
{
    if (!root)
        return 0;
    int cur = 0;
    int max = 0;
    int vmin, vmax;
    lbst(root, &cur, &max, &vmin, &vmax);
    return max;
}
