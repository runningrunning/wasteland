/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* find(struct TreeNode* o, int x)
{
    if (!o)
        return NULL;
    if (o->val == x)
        return o;
    struct TreeNode* t = find(o->left, x);
    if (t)
        return t;
    return find(o->right, x);
}

int count(struct TreeNode* o)
{
    if (!o)
        return 0;
    return 1 + count(o->left) + count(o->right);
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x)
{
    int all = n;
    struct TreeNode* o = find(root, x);
    int l = count(o->left);
    int r = count(o->right);
    int nx = l + r + 1;

    if (all - nx > nx)
        return true;
    if (l > all - l)
        return true;
    if (r > all - r)
        return true;
    return false;
}

