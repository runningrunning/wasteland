/* // be more careful, have done this before !!!!! */
/* // and y is also important !!!!! */
/* /\** */
/*  * Definition for a binary tree node. */
/*  * struct TreeNode { */
/*  *     int val; */
/*  *     struct TreeNode *left; */
/*  *     struct TreeNode *right; */
/*  * }; */
/*  *\/ */
/* /\** */
/*  * Return an array of arrays of size *returnSize. */
/*  * The sizes of the arrays are returned as *columnSizes array. */
/*  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free(). */
/*  *\/ */
/* // STUPID AGAIN, the node could have the same position, so just recorder the node and sort it !! */
/* // use stack or sort */
/* /\* void vt(struct TreeNode* root, int* rs, int*** rv, int ** rn, int* ls, int***lv, int** ln, int x) *\/ */
/* /\* { *\/ */
/* /\*     if (!root) *\/ */
/* /\*         return; *\/ */
/* /\*     int ox = x; *\/ */
/* /\*     if (x >= 0) *\/ */
/* /\*     { *\/ */
/* /\*         int s = *rs; *\/ */
/* /\*         if (s < x + 1) *\/ */
/* /\*         { *\/ */
/* /\*             *rs = x + 1; *\/ */
/* /\*             *rv = realloc(*rv, sizeof(int*) * (x + 1)); *\/ */
/* /\*             *rn = realloc(*rn, sizeof(int) * (x + 1)); *\/ */
/* /\*             (*rv)[x] = NULL; *\/ */
/* /\*             (*rn)[x] = 0; *\/ */
/* /\*         } *\/ */
/* /\*         (*rv)[x] = realloc((*rv)[x], sizeof(int) * ((*rn)[x] + 1)); *\/ */
/* /\*         (*rv)[x][(*rn)[x]] = root->val; *\/ */
/* /\*         (*rn)[x] = (*rn)[x] + 1; *\/ */
/* /\*     } *\/ */
/* /\*     else *\/ */
/* /\*     { *\/ */
/* /\*         x = -x - 1; *\/ */
/* /\*         int s = *ls; *\/ */
/* /\*         if (s < x + 1) *\/ */
/* /\*         { *\/ */
/* /\*             *ls = x + 1; *\/ */
/* /\*             *lv = realloc(*lv, sizeof(int*) * (x + 1)); *\/ */
/* /\*             *ln = realloc(*ln, sizeof(int) * (x + 1)); *\/ */
/* /\*             (*lv)[x] = NULL; *\/ */
/* /\*             (*ln)[x] = 0; *\/ */
/* /\*         } *\/ */

/* /\*         (*lv)[x] = realloc((*lv)[x], sizeof(int) * ((*ln)[x] + 1)); *\/ */
/* /\*         (*lv)[x][(*ln)[x]] = root->val; *\/ */
/* /\*         (*ln)[x] = (*ln)[x] + 1; *\/ */
/* /\*     } *\/ */
/* /\*     vt(root->left, rs, rv, rn, ls, lv, ln, ox - 1); *\/ */
/* /\*     vt(root->right, rs, rv, rn, ls, lv, ln, ox + 1); *\/ */
/* /\* } *\/ */

/* int comp(const void* e1, const void* e2) */
/* { */
/*     return *((int*)e1) - *((int*)e2); */
/* } */

/* int** verticalTraversal(struct TreeNode* root, int** columnSizes, int* returnSize) { */
/*     int rs = 0; */
/*     int** rv = NULL; */
/*     int* rn = NULL; */
/*     int ls = 0; */
/*     int** lv = NULL; */
/*     int* ln = NULL; */

/*     int ai = 0; */
/*     struct TreeNode** as = malloc(sizeof(struct TreeNode*) * 1024); */
/*     int bi = 0; */
/*     struct TreeNode** bs = malloc(sizeof(struct TreeNode*) * 1024); */

/*     as[ai ++] = root; */
/*     root->val = 1024 << 16 | root->val; */
/*     int l = 0; */
/*     while (ai) */
/*     { */
/*         for (int i = 0; i < ai; i ++) */
/*         { */
/*             int v = as[i]->val; */
/*             int x = (v >> 16) - 1024; */
/*             int val = l << 16 | (v & 0xFFFF); */

/*             int ox = v >> 16; */
/*             // printf("x %d v %d.\n", x, val); */
/*             if (x >= 0) */
/*             { */
/*                 int s = rs; */
/*                 if (s < x + 1) */
/*                 { */
/*                     rs = x + 1; */
/*                     rv = realloc(rv, sizeof(int*) * (x + 1)); */
/*                     rn = realloc(rn, sizeof(int) * (x + 1)); */
/*                     rv[x] = NULL; */
/*                     rn[x] = 0; */
/*                 } */
/*                 (rv)[x] = realloc((rv)[x], sizeof(int) * ((rn)[x] + 1)); */
/*                 (rv)[x][(rn)[x]] = val; */
/*                 (rn)[x] = (rn)[x] + 1; */
/*             } */
/*             else */
/*             { */
/*                 x = -x - 1; */
/*                 int s = ls; */
/*                 if (s < x + 1) */
/*                 { */
/*                     ls = x + 1; */
/*                     lv = realloc(lv, sizeof(int*) * (x + 1)); */
/*                     ln = realloc(ln, sizeof(int) * (x + 1)); */
/*                     (lv)[x] = NULL; */
/*                     (ln)[x] = 0; */
/*                 } */

/*                 (lv)[x] = realloc((lv)[x], sizeof(int) * ((ln)[x] + 1)); */
/*                 (lv)[x][(ln)[x]] = val; */
/*                 (ln)[x] = (ln)[x] + 1; */
/*             } */

/*             if (as[i]->left) */
/*             { */
/*                 bs[bi] = as[i]->left; */
/*                 bs[bi]->val = (ox - 1) << 16 | bs[bi]->val; */
/*                 bi ++; */
/*             } */
/*             if (as[i]->right) */
/*             { */
/*                 bs[bi] = as[i]->right; */
/*                 bs[bi]->val = (ox + 1) << 16 | bs[bi]->val; */
/*                 bi ++; */
/*             } */
/*         } */
/*         l ++; */
/*         struct TreeNode** t = as; */
/*         as = bs; */
/*         bs = t; */
/*         ai = bi; */
/*         bi = 0; */
/*     } */

/*     int** ret = malloc(sizeof(int*) * (ls + rs)); */
/*     int* cs = malloc(sizeof(int) * (ls + rs)); */
/*     *returnSize = ls + rs; */
/*     for (int i = ls - 1; i >= 0; i --) */
/*     { */
/*         qsort(lv[i], ln[i], sizeof(int), comp); */
/*         for (int j = 0; j < ln[i]; j ++) */
/*             lv[i][j] &= 0xFFFF; */
/*         ret[ls - 1 - i] = lv[i]; */
/*         cs[ls - 1 - i] = ln[i]; */
/*     } */

/*     for (int i = 0; i < rs; i ++) */
/*     { */
/*         qsort(rv[i], rn[i], sizeof(int), comp); */
/*         for (int j = 0; j < rn[i]; j ++) */
/*             rv[i][j] &= 0xFFFF; */
/*         ret[ls + i] = rv[i]; */
/*         cs[ls + i] = rn[i]; */
/*     } */
/*     *columnSizes = cs; */
/*     return ret; */
/* } */


/* /\** */
/*  * Definition for a binary tree node. */
/*  * struct TreeNode { */
/*  *     int val; */
/*  *     struct TreeNode *left; */
/*  *     struct TreeNode *right; */
/*  * }; */
/*  *\/ */
/* /\** */
/*  * Return an array of arrays of size *returnSize. */
/*  * The sizes of the arrays are returned as *columnSizes array. */
/*  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free(). */
/*  *\/ */

int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

void vt(struct TreeNode* root, int* rs, int*** rv, int ** rn, int* ls, int***lv, int** ln, int x, int y)
{
    if (!root)
        return;
    int ox = x;
    if (x >= 0)
    {
        int s = *rs;
        if (s < x + 1)
        {
            *rs = x + 1;
            *rv = realloc(*rv, sizeof(int*) * (x + 1));
            *rn = realloc(*rn, sizeof(int) * (x + 1));
            (*rv)[x] = NULL;
            (*rn)[x] = 0;
        }
        (*rv)[x] = realloc((*rv)[x], sizeof(int) * ((*rn)[x] + 1));
        (*rv)[x][(*rn)[x]] = y << 16 | root->val;
        (*rn)[x] = (*rn)[x] + 1;
    }
    else
    {
        x = -x - 1;
        int s = *ls;
        if (s < x + 1)
        {
            *ls = x + 1;
            *lv = realloc(*lv, sizeof(int*) * (x + 1));
            *ln = realloc(*ln, sizeof(int) * (x + 1));
            (*lv)[x] = NULL;
            (*ln)[x] = 0;
        }
        (*lv)[x] = realloc((*lv)[x], sizeof(int) * ((*ln)[x] + 1));
        (*lv)[x][(*ln)[x]] = y << 16 | root->val;
        (*ln)[x] = (*ln)[x] + 1;
    }
    vt(root->left, rs, rv, rn, ls, lv, ln, ox - 1, y + 1);
    vt(root->right, rs, rv, rn, ls, lv, ln, ox + 1, y + 1);
}

int** verticalTraversal(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int rs = 0;
    int** rv = NULL;
    int* rn = NULL;
    int ls = 0;
    int** lv = NULL;
    int* ln = NULL;
    vt(root, &rs, &rv, &rn, &ls, &lv, &ln, 0);
    int** ret = malloc(sizeof(int*) * (ls + rs));
    int* cs = malloc(sizeof(int) * (ls + rs));
    *returnSize = ls + rs;
    for (int i = ls - 1; i >= 0; i --)
    {
        qsort(lv[i], ln[i], sizeof(int), comp);
        for (int j = 0; j < ln[i]; j ++)
            lv[i][j] &= 0xFFFF;
        ret[ls - 1 - i] = lv[i];
        cs[ls - 1 - i] = ln[i];
    }

    for (int i = 0; i < rs; i ++)
    {
        qsort(rv[i], rn[i], sizeof(int), comp);
        for (int j = 0; j < rn[i]; j ++)
            rv[i][j] &= 0xFFFF;
        ret[ls + i] = rv[i];
        cs[ls + i] = rn[i];
    }
    *columnSizes = cs;
    return ret;
}
