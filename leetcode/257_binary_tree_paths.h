void _btp(struct TreeNode* r, int h, int* l, char*** ret, int* rc)
{
    l[h - 1] = r->val;

    if (r->left || r->right)
    {
        if (r->left)
            _btp(r->left, h + 1, l, ret, rc);

        if (r->right)
            _btp(r->right, h + 1, l, ret, rc);
    }
    else
    {
        int c = (*rc) + 1;
        if (!(c % 256))
            *ret = realloc(*ret, sizeof(char*) * (c + 256));
        char* str = malloc((h * 13) + 1);
        int x = sprintf(str, "%d", l[0]);

        for (int i = 1; i < h; i ++)
            x += sprintf(str + x, "->%d", l[i]);
        str[x] = 0;

        (*rc) ++;
        (*ret)[c - 1] = str;
    }
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    if (!root)
        return NULL;

    int l[2048] ={0};

    int rc = 0;
    char** ret = malloc(sizeof(char*) * 256);
    _btp(root, 1, l, &ret, &rc);
    *returnSize = rc;
    return ret;
}
