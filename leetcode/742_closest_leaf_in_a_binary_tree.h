/* Be careful about the initialize value */
/* the complicated part is that initializing values */
/* Do it again, Favorite !!! */
/* more clear code ? */
#define MAX_NODES 1024
int fcl(struct TreeNode* r, int k, int* n, bool* found, int* cv, int* cn, int* cd)
{
    if (*found && !(*cn))
        return 0;

    if (!r->left && !r->right)
    {
        if (r->val == k)
        {
            *cv = k;
            *cn = 0;
            *cd = 1;
            *found = true;
            return 0;
        }
        *n = r->val;
        return 1;
    }

    int l_n;
    int l_cd;
    int l_min = MAX_NODES;
    bool l_find = false;
    if (r->left)
        l_min = fcl(r->left, k, &l_n, &l_find, cv, cn, &l_cd);

    int r_n;
    int r_cd;
    int r_min = MAX_NODES;
    bool r_find = false;
    if (r->right)
        r_min = fcl(r->right, k, &r_n, &r_find, cv, cn, &r_cd);

    *found = l_find || r_find;

    if (l_find)
    {
        *cd = l_cd + 1;
        if (r_min + l_cd < *cn)
        {
            *cn = r_min + l_cd;
            *cv = r_n;
        }
    }

    if (r_find)
    {
        *cd = r_cd + 1;
        if (l_min + r_cd < *cn)
        {
            *cn = l_min + r_cd;
            *cv = l_n;
        }
    }

    int min;
    if (l_min <= r_min)
    {
        *n = l_n;
        min = l_min + 1;
    }
    else
    {
        *n = r_n;
        min = r_min + 1;
    }

    if (r->val == k)
    {
        *found = true;
        *cd = 1;
        *cv = *n;
        *cn = min;
    }
    return min;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findClosestLeaf(struct TreeNode* root, int k)
{
    if (!root)
        return 0;

    bool found = false;
    int cv = 0;
    int cn = 0;
    int cd = 0;
    int n = 0;
    fcl(root, k, &n, &found, &cv, &cn, &cd);
    return found ? cv : 0;
}
