void tl(struct TreeNode* r, int h, int* l)
{
    if (!r)
        return;

    if (*l < h)
        *l = h;

    tl(r->left, h + 1, l);
    tl(r->right, h + 1, l);
}

void fill(struct TreeNode* n, char*** r, int h, int i, int s, int l)
{
    if (!n)
        return;

    if (!r[h - 1])
    {
        r[h - 1] = malloc(sizeof(char*) * s);
        memset(r[h - 1], 0, sizeof(char*) * s);
    }

    char* t = malloc(20);
    int x = sprintf(t, "%d", n->val);
    t[x] = 0;
    r[h - 1][i] = t;

    fill(n->left, r, h + 1, i - l, s, l / 2);
    fill(n->right, r, h + 1, i + l, s, l / 2);
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
char*** printTree(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int l = 0;
    tl(root, 1, &l);

    if (!l)
        return NULL;
    *returnSize = l;

    int t = l;
    int s = 1;
    while(t --)
        s *= 2;

    s -= 1;

    char*** ret = malloc(sizeof(char**) * l);
    memset(ret, 0, sizeof(char**) * l);
    fill(root, ret, 1, s/2, s, (s + 1) / 4);

    int* cs = malloc(sizeof(int) * l);
    for (int i = 0; i < l; i ++)
    {
        cs[i] = s;
        for (int j = 0; j < s; j++)
        {
            if (!ret[i][j])
            {
                ret[i][j] = malloc(1);
                ret[i][j][0] = 0;
            }
        }
    }
    *columnSizes = cs;
    return ret;
}
