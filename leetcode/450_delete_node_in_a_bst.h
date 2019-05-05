/* Becareful about Tree Accessing */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    struct TreeNode** r = &root;

    while (*r)
    {
        int v = (*r)->val;

        if (v == key)
            break;

        if (v > key)
            r = &(*r)->left;
        else
            r = &(*r)->right;
    }

    if (!*r)
        return root;

    struct TreeNode* d = *r;

    if (!d->left || !d->right)
    {
        *r = d->left ? d->left : d->right;
        return root;
    }

    if (!d->left->right || !d->right->left)
    {
        if (!d->left->right)
        {
            *r = d->left;
            d->left->right = d->right;
        }
        else
        {
            *r = d->right;
            d->right->left = d->left;
        }
        return root;
    }

    struct TreeNode** l = &d->left;
    while ((*l)->right)
        l = &(*l)->right;

    struct TreeNode* t = *l;
    *l = t->left;
    *r = t;
    t->left = d->left;
    t->right = d->right;

    return root;
}
