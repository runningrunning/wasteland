int* try(struct TreeNode* r, int sum, int*** ret, int** cs, int* rs, int* size, int n)
{
    if (!r->left && !r->right)
    {
        if (sum == r->val)
        {
            if (*rs >= *size)
            {
                (*size) += 512;
                *cs = realloc(*cs, sizeof(int) * (*size));
                *ret = realloc(*ret, sizeof(int*) * (*size));
            }
            int l = *rs;

            (*cs)[l] = n;
            (*ret)[l] = malloc(sizeof(int) * n);
            (*ret)[l][n - 1] = r->val;
            (*rs) ++;

            int* ls = malloc(sizeof(int) * 2);
            ls[0] = l + 1;
            ls[1] = 0;

            return ls;
        }
    }

    int li = 0;
    int ri = 0;
    int* lis = NULL;
    int* ris = NULL;
    if (r->left)
    {
        lis = try(r->left, sum - r->val, ret, cs, rs, size, n + 1);

        if (lis)
        {
            while(lis[li])
            {
                (*ret)[lis[li] - 1][n - 1] = r->val;
                li ++;
            }
        }
    }

    if (r->right)
    {
        ris = try(r->right, sum - r->val, ret, cs, rs, size, n + 1);

        if (ris)
        {
            while(ris[ri])
            {
                (*ret)[ris[ri] - 1][n - 1] = r->val;
                ri ++;
            }
        }
    }

    if (!lis)
        return ris;

    if (!ris)
        return lis;

    int* all = malloc(sizeof(int) * (ri + li + 1));

    for(int i = 0; i < ri; i ++)
        all[i] = ris[i];

    for(int i = 0; i < li; i ++)
        all[ri + i] = lis[i];

    all[ri + li] = 0;

    free(lis);
    free(ris);

    return all;
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
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int size = 256;
    int** ret = malloc(sizeof(int *) * size);
    int* cs = malloc(sizeof(int) * size);
    int rs = 0;

    try(root, sum, &ret, &cs, &rs, &size, 1);
    *returnSize = rs;
    *columnSizes = cs;
    return ret;
}
