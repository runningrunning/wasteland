void is_inorder(struct TreeNode* r, struct TreeNode* p, struct TreeNode** pre, struct TreeNode** t)
{
    if (*t || !r)
        return;

    is_inorder(r->left, p, pre, t);

    if (*pre == p)
    {
        *t = r;
        return;
    }

    *pre = r;
    /* if (r == p) */
    /*     *need = true; */

    is_inorder(r->right, p, pre, t);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p)
{
    if (!root || !p)
        return NULL;

    struct TreeNode* t;
    if (p->right)
    {
        t = p->right;
        while(t->left)
            t = t->left;
    }
    else
    {
        t = root;
        while(t->right)
            t = t->right;

        if (t == p)
            return NULL;
        struct TreeNode* pre;

        t = NULL;
        is_inorder(root, p, &pre, &t);
    }

    return t;
}
