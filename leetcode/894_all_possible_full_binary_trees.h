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

struct TreeNode* dupTree(struct TreeNode* o)
{
    struct TreeNode* n = NULL;

    if (o)
    {
        n = malloc(sizeof(struct TreeNode));
        n->val = 0;
        n->left = dupTree(o->left);
        n->right = dupTree(o->right);
    }

    return n;
}

void deleteTree(struct TreeNode* t)
{
    if (t->left)
        deleteTree(t->left);
    if (t->right)
        deleteTree(t->right);
    free(t);
}

void removeTree(struct TreeNode** t, int ts)
{
    for (int i = 0; i < ts; i ++)
        deleteTree(t[i]);
    free(t);
}

struct TreeNode** allPossibleFBT(int N, int* returnSize)
{
    *returnSize = 0;
    if (!(N & 1))
        return NULL;

    int rs = 0;
    struct TreeNode** r = NULL;
    if (N == 1)
    {
        rs = 1;
        r = malloc(sizeof(struct TreeNode*));
        r[0] = malloc(sizeof(struct TreeNode));
        r[0]->val = 0;
        r[0]->left = r[0]->right = NULL;
    }
    else
    {
        for (int i = 1; i < N - 1; i += 2)
        {
            int left_size = 0;
            struct TreeNode** left = allPossibleFBT(i, &left_size);
            int right_size = 0;
            struct TreeNode** right = allPossibleFBT(N - 1 - i, &right_size);
            r = realloc(r, sizeof(struct TreeNode*) * (rs + left_size * right_size));

            for (int m = 0; m < left_size; m ++)
                for (int n = 0; n < right_size; n ++)
                {
                    r[rs] = malloc(sizeof(struct TreeNode));
                    r[rs]->val = 0;
                    r[rs]->left = dupTree(left[m]);
                    r[rs]->right = dupTree(right[n]);
                    rs ++;
                }

            removeTree(left, left_size);
            removeTree(right, right_size);
        }
    }

    *returnSize = rs;
    return r;
}
