/* The key method of DP is cut the path or cache the result into somewhere  */
/* STUPID WRONG ALGORITHM !!!, it's not that simple for just one level */
/* E.g. Tree, 2, 1, 3, 4 */
/* can not use array, as it's recursive */
/* how to optimize it ? */
/* Just cache the half result into the array itself as - or allocate new cache */

int rob_tree_2(struct TreeNode* root, bool used_parent, int* dv, int* id)
{
    if (!root)
        return 0;

    int ilf = (*id) ++;
    int ilt = (*id) ++;
    int irf = (*id) ++;
    int irt = (*id) ++;

    int r = 0;

    if (used_parent)
    {
        if (!dv[ilf])
            dv[ilf] = rob_tree_2(root->left, false, dv, id);
        r += dv[ilf];

        if (!dv[irf])
            dv[irf] = rob_tree_2(root->right, false, dv, id);
        r += dv[irf];

        return r;
    }

    int wp = root->val;
    if (!dv[ilt])
        dv[ilt] = rob_tree_2(root->left, true, dv, id);
    wp += dv[ilt];

    if (!dv[irt])
        dv[irt] = rob_tree_2(root->right, true, dv, id);
    wp += dv[irt];

    int np = 0;
    if (!dv[ilf])
        dv[ilf] = rob_tree_2(root->left, false, dv, id);
    np += dv[ilf];
    if (!dv[irf])
        dv[irf] = rob_tree_2(root->right, false, dv, id);
    np += dv[irf];

    return wp > np ? wp : np;
}

int rob_tree_1(struct TreeNode* root, bool used_parent)
{
    if (!root)
        return 0;

    if (used_parent)
        return rob_tree_1(root->left, false) + rob_tree_1(root->right, false);
    int wp = root->val + rob_tree_1(root->left, true) + rob_tree_1(root->right, true);
    int np = rob_tree_1(root->left, false) + rob_tree_1(root->right, false);;
    return wp > np ? wp : np;
}

int rob_tree(struct TreeNode* root, bool used_parent)
{
    if (!root)
        return 0;

    if (used_parent)
        return rob_tree(root->left, false) + rob_tree(root->right, false);

    /* cache when this node is used or not */
    if (root->val > 0)
    {
        int wp = root->val + rob_tree(root->left, true) + rob_tree(root->right, true);
        int np = rob_tree(root->left, false) + rob_tree(root->right, false);
        root->val = - (wp > np ? wp : np);
    }

    return - root->val;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode* root)
{
    return rob_tree(root, false);
    /* int id = 0; */
    /* int idv[8192] = {0}; */
    /* return rob_tree_2(root, false, idv, &id); */
}

/*
void rob_tree(struct TreeNode* r, int l, int* lv, int* ln)
{
    if (!r)
        return;

    if ((l + 1) > *ln)
        *ln = l + 1;
    lv[l] += r->val;

    rob_tree(r->left, l + 1, lv, ln);
    rob_tree(r->right, l + 1, lv, ln);
}

int rob(struct TreeNode* root) {
    int ln = 1;
    int lv[8192] = {0};
    rob_tree(root, 0, lv, &ln);

    if (ln == 1)
        return lv[0];

    if (ln == 2)
        return lv[0] > lv[1] ? lv[0] : lv[1];

    lv[1] = lv[1] > lv[0] ? lv[1] : lv[0];

    int s;
    int pre = lv[1];
    for (int i = 2; i < ln; i ++)
    {
        s = lv[i] + lv[i - 2];
        pre = lv[i] = s > pre ? s : pre;
    }
    return lv[ln - 1];
}

*/
