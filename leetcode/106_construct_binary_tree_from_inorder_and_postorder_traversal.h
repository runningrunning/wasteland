void build(struct TreeNode** i, int** p, int* ps, int* in, int s, int e)
{
    if (!*ps)
        return;

    int pre = (*p)[0];
    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    r->val = pre;
    r->left = NULL;
    r->right = NULL;
    *i = r;

    (*p) --;
    (*ps) --;

    if (s == e)
        return;

    int j = s;
    while(j <= e)
    {
        if (in[j] == pre)
            break;
        j ++;
    }

    if (j < e)
        build(&r->right, p, ps, in, j + 1, e);

    if (j > s)
        build(&r->left, p, ps, in, s, j - 1);
    return;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    struct TreeNode* r = NULL;
    int* p = &postorder[postorderSize - 1];
    int ps = postorderSize;
    build(&r, &p, &ps, inorder, 0, inorderSize - 1);
    return r;
}
