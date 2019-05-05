/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void lc(struct TreeNode* r, struct TreeNode* p, struct TreeNode* q, int l, int* la, struct TreeNode** a, bool* done)
{
    if (*done)
        return;

    if (*la)
    {
        if (l < *la)
        {
            *la = l;
            *a = r;
        }

        if (r == p || r == q)
        {
            *done = true;
            return;
        }
    }
    else
    {
        if (r == p || r == q)
        {
            *la = l;
            *a = r;
        }
    }

    if (r->left)
        lc(r->left, p, q, l + 1, la, a, done);

    if (l < *la)
    {
        if (!(*done))
        {
            *la = l;
            *a = r;
        }
    }

    if (r->right)
        lc(r->right, p, q, l + 1, la, a, done);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (!root)
        return NULL;

    if (p == q)
        return p;

    if (p == root || q == root)
        return root;

    int la = 0;
    struct TreeNode* a;
    bool done = false;
    lc(root, p, q, 1, &la, &a, &done);
    return a;
}
