/* Use Stack to asscess binay tree from top to bottom, or from left to right, otherwise it will do deep search ! */
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
int** verticalOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int rlc = -1;
    int rl[1024] = {0};
    int* rls[1024];

    int rrc = -1;
    int rr[1024] = {0};
    int* rrs[1024];

    int st = 0;
    int si = 0;

    struct TreeNode* stack[1024];
    int h_stack[1024];

    h_stack[si] = 0;
    stack[si ++] = root;

    while(st < si)
    {
        int hi = h_stack[st];
        struct TreeNode* r = stack[st];

        if (r->left)
        {
            h_stack[si] = hi - 1;
            stack[si ++] = r->left;
        }

        if (r->right)
        {
            h_stack[si] = hi + 1;
            stack[si ++] = r->right;
        }

        int* t;

        if (hi >= 0)
        {
            int h = hi;
            if (h > rrc)
                rrc = h;

            int i = rr[h];
            if (!i)
                rrs[h] = malloc(sizeof(int) * 64);

            rrs[h][i] = r->val;
            rr[h] ++;
        }
        else
        {
            int h = -hi;
            h -= 1;

            if (h > rlc)
                rlc = h;

            int i = rl[h];
            if (!i)
                rls[h] = malloc(sizeof(int) * 64);
            rls[h][i] = r->val;
            rl[h] ++;
        }
        st ++;
    }

    rlc ++;
    rrc ++;
    int* cs = malloc(sizeof(int) * (rrc + rlc));
    int** ret = malloc(sizeof(int*) * (rrc + rlc));

    // be careful
    for (int i = 0; i < rlc; i ++)
    {
        cs[i] = rl[rlc - i - 1];
        ret[i] = rls[rlc - i - 1];
    }

    for (int i = 0; i < rrc; i ++)
    {
        cs[rlc + i] = rr[i];
        ret[rlc + i] = rrs[i];
    }

    *columnSizes = cs;
    *returnSize = rlc + rrc;

    return ret;
}

/*
void ol(struct TreeNode* r, int hi, int*** rls, int** rl, int* rlc, int* lc, int*** rrs, int** rr, int* rrc, int* rc)
{
    if (!r)
        return;

    int* t;

    if (hi >= 0)
    {
        int h = hi;
        if (h > *rrc)
            *rrc = h;

        if (h >= *rc)
        {
            *rc += 1024;
            *rrs = realloc(*rrs, sizeof(int*) * (*rc));
            *rr = realloc(*rr, sizeof(int) * (*rc));
            memset(*rr + *rc - 1024, 0, sizeof(int) * 1024);
        }

        int i = 0;
        if (!(*rr)[h])
        {
            t = malloc(sizeof(int) * 256);
            memset(t, 0, sizeof(int) * 256);
            (*rrs)[h] = t;
        }
        else
        {
            i = (*rr)[h];
            t = (*rrs)[h];
            if (!(i % 256))
            {
                t = realloc((*rrs)[h], sizeof(int) * (i + 256));
                memset(t - 256, 0, sizeof(int) * 256);
                (*rrs)[h] = t;
            }
        }
        t[i] = r->val;
        (*rr)[h] ++;
    }
    else
    {
        int h = -hi;
        h -= 1;

        if (h > *rlc)
            *rlc = h;

        if (h >= *lc)
        {
            *lc += 1024;
            *rls = realloc(*rls, sizeof(int*) * (*lc));
            *rl = realloc(*rl, sizeof(int) * (*lc));
            memset(*rl + *lc - 1024, 0, sizeof(int) * 1024);
        }

        int i = 0;
        if (!(*rl)[h])
        {
            t = malloc(sizeof(int) * 256);
            memset(t, 0, sizeof(int) * 256);
            (*rls)[h] = t;
        }
        else
        {
            i = (*rl)[h];
            t = (*rls)[h];
            if (!(i % 256))
            {
                t = realloc((*rls)[h], sizeof(int) * (i + 256));
                memset(t - 256, 0, sizeof(int) * 256);
                (*rls)[h] = t;
            }
        }
        t[i] = r->val;
        (*rl)[h] ++;
    }
}

int** verticalOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int lc = 1024;
    int rlc = -1;
    int *rl = malloc(sizeof(int) * 1024);
    memset(rl, 0, sizeof(int) * 1024);
    int** rls = malloc(sizeof(int*) * 1024);

    int rc = 1024;
    int rrc = -1;
    int* rr = malloc(sizeof(int) * 1024);
    memset(rr, 0, sizeof(int) * 1024);
    int** rrs = malloc(sizeof(int*) * 1024);

    int st = 0;
    int si = 0;
    int st_size = 1024;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * st_size);
    int* h_stack = malloc(sizeof(int) * st_size);

    h_stack[si] = 0;
    stack[si ++] = root;

    while(st < si)
    {
        int h = h_stack[st];
        struct TreeNode* r = stack[st];

        if (st + 2 > st_size)
        {
            st_size += 1024;
            h_stack = realloc(stack, sizeof(int) * st_size);
            stack = realloc(stack, sizeof(struct TreeNode*) * st_size);
        }

        if (r->left)
        {
            h_stack[si] = h - 1;
            stack[si ++] = r->left;
        }

        if (r->right)
        {
            h_stack[si] = h + 1;
            stack[si ++] = r->right;
        }

        ol(stack[st], h_stack[st], &rls, &rl, &rlc, &lc, &rrs, &rr, &rrc, &rc);
        st ++;
    }

    rlc ++;
    rrc ++;
    int* cs = malloc(sizeof(int) * (rrc + rlc));
    int** ret = malloc(sizeof(int*) * (rrc + rlc));

    // be careful
    for (int i = 0; i < rlc; i ++)
    {
        cs[i] = rl[rlc - i - 1];
        ret[i] = rls[rlc - i - 1];
    }

    for (int i = 0; i < rrc; i ++)
    {
        cs[rlc + i] = rr[i];
        ret[rlc + i] = rrs[i];
    }

    *columnSizes = cs;
    *returnSize = rlc + rrc;

    return ret;
}
*/
