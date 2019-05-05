/* TODO DO more time with different method, just rewrite the whole BST */
/*  */
void sbst(struct TreeNode* r, struct TreeNode* p, struct TreeNode** si, struct TreeNode** bi, int V)
{
    if (r->val > V)
    {
        if ((!p || p->val > V) && r->left)
            sbst(r->left, r, si, bi, V);
        else
        {
            if (si)
                *si = NULL;

            if (bi)
            {
                *bi = r;
                p->right = NULL;
            }

            if (r->left)
                sbst(r->left, r, &p->right, NULL, V);
        }
    }
    else // r->val <= V
    {
        if ((!p || p->val <= V) && r->right)
            sbst(r->right, r, si, bi, V);
        else
        {
            if (bi)
                *bi = NULL;

            if (si)
            {
                *si = r;
                p->left = NULL;
            }

            if (r->right)
                sbst(r->right, r, NULL, &p->left, V);
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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** splitBST(struct TreeNode* root, int V, int* returnSize)
{
    *returnSize = 2;
    struct TreeNode** r = malloc(sizeof(struct TreeNode*) * 2);
    r[0] = r[1] = NULL;

    if (!root)
        return r;

    struct TreeNode* lo = NULL;
    struct TreeNode* ho = NULL;
    if (root->val > V)
        sbst(root, NULL, &lo, NULL, V);
    else
        sbst(root, NULL, NULL, &ho, V);
    r[0] = root;
    r[1] = lo ? lo : ho;
    return r;
}
