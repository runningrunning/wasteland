void build1(struct TreeNode** i, int** p, int* ps, int* in, int s, int e)
{
    if (!*ps)
        return;

    int pre = (*p)[0];
    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    r->val = pre;
    r->left = NULL;
    r->right = NULL;
    *i = r;

    (*p) ++;
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

    if (j > s)
        build1(&r->left, p, ps, in, s, j - 1);

    if (j < e)
        build1(&r->right, p, ps, in, j + 1, e);
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
struct TreeNode* buildTree1(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* r = NULL;
    int* p = preorder;
    int ps = preorderSize;
    build1(&r, &p, &ps, inorder, 0, inorderSize - 1);
    return r;
}
