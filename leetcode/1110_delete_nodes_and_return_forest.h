/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dn(struct TreeNode* r, int* s)
{
    if (!r)
        return;
    if (s[r->val])
        r->val = 0;
    dn(r->left, s);
    dn(r->right, s);
}

struct TreeNode* co(struct TreeNode* o, struct TreeNode*** r, int* rs)
{
    if (!o)
        return NULL;

    o->left = co(o->left, r, rs);
    o->right = co(o->right, r, rs);

    if (o->val)
        return o;

    if (o->left)
    {
        *r = realloc(*r, sizeof(struct TreeNode*) * ((*rs) + 1));
        (*r)[*rs] = o->left;
        (*rs) ++;
        o->left = NULL;
    }

    if (o->right)
    {
        *r = realloc(*r, sizeof(struct TreeNode*) * ((*rs) + 1));
        (*r)[*rs] = o->right;
        (*rs) ++;
        o->right = NULL;
    }

    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize)
{
    int* s = calloc(sizeof(int), 1024);
    for (int i = 0; i < to_deleteSize; i ++)
        s[to_delete[i]] = 1;

    dn(root, s);

    int rs = 0;
    struct TreeNode** r = NULL;

    struct TreeNode* t = co(root, &r, &rs);

    if (t)
    {
        r = realloc(r, sizeof(struct TreeNode*) * (rs + 1));
        r[rs ++] = t;
    }

    *returnSize = rs;
    return r;
}

