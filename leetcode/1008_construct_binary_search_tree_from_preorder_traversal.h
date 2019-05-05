/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Binary Search Tree, just simple MIN MAX !!
// Just simple Divide and Conquer !!!!
// THINK TOOOOOO MUCH
// Stupid, simple D&C
void bfp(int* p, int* n, int s, struct TreeNode* c, int max)
{
    if (*n == s)
        return;

    if (p[*n] < c->val)
    {
        c->left = malloc(sizeof(struct TreeNode));
        c->left->val = p[*n];
        c->left->left = c->left->right = NULL;
        *n = *n + 1;
        bfp(p, n, s, c->left, c->val);
    }

    if (*n == s)
        return;

    if (p[*n] < max)
    {
        c->right = malloc(sizeof(struct TreeNode));
        c->right->val = p[*n];
        c->right->left = c->right->right = NULL;
        *n = *n + 1;
        bfp(p, n, s, c->right, max);
    }
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    if (!preorder || !preorderSize)
        return NULL;
    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    r->val = preorder[0];
    r->left = r->right = NULL;
    int n = 1;
    bfp(preorder, &n, preorderSize, r, INT_MAX);
    return r;
}
