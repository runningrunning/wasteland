void _trav(struct TreeNode* root, int l, int* h, int** r, int *c, int* max)
{
    if ((*c) + 1 > *max)
    {
        *max += 1024;
        *r = realloc(*r, sizeof(sizeof(int) * (*max)));
    }

    if (l > *h)
    {
        *h = l;
        (*r)[*c] = root->val;
        (*c) ++;
    }

    if (root->right)
        _trav(root->right, l + 1, h, r, c, max);

    if (root->left)
        _trav(root->left, l + 1, h, r, c, max);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;

    int n = 0;
    int max = 1024;
    int* ret = malloc(sizeof(int) * 1024);
    int h = 0;
    _trav(root, 1, &h, &ret, &n, &max);
    *returnSize = n;

    return ret;
}
