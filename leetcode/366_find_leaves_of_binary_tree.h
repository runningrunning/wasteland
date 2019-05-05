int fl(struct TreeNode* n, int*** ret, int** len, int* rl, int* ml)
{
    int l = 0;
    if (n->left)
        l = fl(n->left, ret, len, rl, ml);

    int r = 0;
    if (n->right)
        r = fl(n->right, ret, len, rl, ml);

    l = l > r ? l : r;

    if (l >= *rl)
    {
        *rl += 2048;
        (*ret) = realloc(*ret, sizeof(int*) * (*rl));
        (*len) = realloc(*len, sizeof(int) * (*rl));
        memset((*len) + (*rl) - 2048, 0, sizeof(int) * 2048);
    }

    if (l > *ml)
        *ml = l;

    if (!(*len)[l])
        (*ret)[l] = malloc(sizeof(int) * 2048);

    (*ret)[l][(*len)[l]] = n->val;
    (*len)[l] ++;
    return l + 1;
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
int** findLeaves(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int rl = 2048;
    int* len = malloc(sizeof(int) * rl);
    int** ret = malloc(sizeof(int*) * rl);
    memset(len, 0, sizeof(int) * rl);

    int ml = 0;

    fl(root, &ret, &len, &rl, &ml);
    *columnSizes = len;
    *returnSize = ml + 1;
    return ret;
}
