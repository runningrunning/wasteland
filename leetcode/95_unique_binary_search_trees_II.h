struct TreeNode** gt(int s, int e)
{
    int l = e - s + 1;
    /* from 96_unique_binary_search_trees */
    int all[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862,
                 16796, 58786, 208012, 742900, 2674440,
                 9694845, 35357670, 129644790, 477638700, 1767263190 };

    struct TreeNode* t = NULL;
    struct TreeNode** ret = malloc(sizeof(struct TreeNode*) * all[l]);
    if (l == 1)
    {
        t = malloc(sizeof(struct TreeNode));
        t->val = s;
        t->left = t->right = NULL;
        ret[0] = t;
    }
    /* else if (l == 2) */
    /* { */
    /*     // s R -> e; */
    /*     t = malloc(sizeof(struct TreeNode)); */
    /*     t->val = s; */
    /*     t->left = t->right = NULL; */
    /*     ret[0] = t; */
    /*     t = malloc(sizeof(struct TreeNode)); */
    /*     t->val = e; */
    /*     t->left = t->right = NULL; */
    /*     ret[0]->right = t; */

    /*     // e L -> s; */
    /*     t = malloc(sizeof(struct TreeNode)); */
    /*     t->val = e; */
    /*     t->left = t->right = NULL; */
    /*     ret[1] = t; */
    /*     t = malloc(sizeof(struct TreeNode)); */
    /*     t->val = s; */
    /*     t->left = t->right = NULL; */
    /*     ret[1]->left = t; */
    /* } */
    else
    {
        int in = 0;
        struct TreeNode** left = NULL;
        struct TreeNode** right = NULL;

        for (int i = 0; i < l; i ++)
        {
            int lt = all[i];
            int rt = all[l - 1 - i];
            left = right = NULL;

            if (lt)
                left = gt(s, s + i - 1);

            if (rt)
                right = gt(s + i + 1, e);

            lt = lt ? lt : 1;
            rt = rt ? rt : 1;

            /* if (!left) */
            /* { */
            /*     for (int ri = 0; ri < rt; ri ++) */
            /*     { */
            /*         t = malloc(sizeof(struct TreeNode)); */
            /*         t->val = s; */
            /*         t->left = t->right = NULL; */
            /*         ret[in ++] = t; */
            /*         t->right = right[ri]; */
            /*     } */
            /* } */
            /* else if (!right) */
            /* { */
            /*     for (int li = 0; li < lt; li ++) */
            /*     { */
            /*         t = malloc(sizeof(struct TreeNode)); */
            /*         t->val = e; */
            /*         t->left = t->right = NULL; */
            /*         ret[in ++] = t; */
            /*         t->left = left[li]; */
            /*     } */
            /* } */
            /* else */
            /* { */
            for (int li = 0; li < lt; li ++)
            {
                for (int ri = 0; ri < rt; ri ++)
                {
                    t = malloc(sizeof(struct TreeNode));
                    t->val = s + i;
                    t->left = t->right = NULL;
                    ret[in ++] = t;
                    t->left = left ? left[li] : NULL;
                    t->right = right ? right[ri] : NULL;
                }
            }
            /* } */
        }
    }
    return ret;
}

/* find better iterator to return the overall trees */
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
struct TreeNode** generateTrees(int n, int* returnSize)
{
    if (!n)
        return NULL;

    /* from 96_unique_binary_search_trees */
    int all[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862,
                 16796, 58786, 208012, 742900, 2674440,
                 9694845, 35357670, 129644790, 477638700, 1767263190};

    *returnSize = all[n];
    return gt(1, n);
}
