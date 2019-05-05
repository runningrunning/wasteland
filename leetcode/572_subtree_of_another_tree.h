bool is_same(struct TreeNode* s, struct TreeNode* t)
{
    if (!s || !t)
        return !s ? !t : !s;
    return s->val == t->val && is_same(s->left, t->left) && is_same(s->right, t->right);
}

bool iss(struct TreeNode* s, int h, struct TreeNode* t)
{
    if (!s || !h)
        return false;
    if (s->val == t->val && is_same(s->left, t->left) && is_same(s->right, t->right))
        return true;
    return iss(s->left, h - 1, t) || iss(s->right, h - 1, t);
}

void tl(struct TreeNode* r, int h, int* l)
{
    if (!r)
        return;

    if (h > *l)
        *l = h;

    tl(r->left, h + 1, l);
    tl(r->right, h + 1, l);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if (!s || !t)
        return false;

    int ls = 0;
    tl(s, 1, &ls);
    int lt = 0;
    tl(t, 1, &lt);
    return iss(s, ls - lt + 1, t);
}
