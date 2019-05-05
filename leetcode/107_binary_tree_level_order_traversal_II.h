void t(struct TreeNode* root, int** ret, int* cs, int le, int n)
{
    if (root)
    {
        ret[le - n][cs[le - n]] = root->val;
        cs[le - n] ++;

        if (root->left)
            t(root->left, ret, cs, le, n + 1);

        if (root->right)
            t(root->right, ret, cs, le, n + 1);
    }
}

int d(struct TreeNode* root, int** cs, int* size, int n)
{
    if (!root)
        return n - 1;

    if (n >= (*size))
    {
        *size += 256;
        *cs = realloc((*cs), sizeof(int) * (*size));
        memset(&(*cs)[n], 0, sizeof(int) * 256);
    }

    if (root->left)
        (*cs)[n] ++;

    if (root->right)
        (*cs)[n] ++;

    int l = d(root->left, cs, size, n + 1);
    int r = d(root->right, cs, size, n + 1);

    return l > r ? l : r;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int size = 512;
    int* cs = malloc(sizeof(int) * size);
    memset(cs, 0, sizeof(int) * size);
    cs[0] = 1;

    int le = d(root, &cs, &size, 1);

    int** ret = malloc(sizeof(int*) * le);
    int* rs = malloc(sizeof(int) * le);
    memset(rs, 0, sizeof(int) * le);

    for(int i = 0; i < le; i ++)
        ret[i] = malloc(sizeof(int) * cs[le - 1 - i]);

    t(root, ret, rs, le - 1, 0);
    *returnSize = le;
    *columnSizes = rs;
    return ret;
}
