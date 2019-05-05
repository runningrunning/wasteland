void bobt(struct TreeNode* r, int** a, int* ai)
{
    if (!r)
        return;

    bobt(r->left, a, ai);
    if (!r->left && !r->right)
    {
        int c = *ai + 1;
        if (!(c % 2048))
            *a = realloc(*a, sizeof(int) * (c + 2048));

        (*a)[*ai] = r->val;
        (*ai) ++;
    }
    bobt(r->right, a, ai);
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
int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;

    int li = 0;
    int ri = 2047;
    int a[2048] = {0};

    struct TreeNode* t;
    struct TreeNode* last;

    if (root->left)
    {
        t = root;

        while(1)
        {
            last = t;
            t = t->left ? t->left : t->right;
            if (t)
                a[li ++] = last->val;
            else
                break;
        }
    }

    if (root->right)
    {
        t = root;

        while(1)
        {
            last = t;
            t = t->right ? t->right : t->left;
            if (t)
                a[ri --] = last->val;
            else
                break;
        }
    }

    if (!root->left && !root->right)
    {
        *returnSize = 1;
        int* ret = malloc(sizeof(int));
        ret[0] = root->val;
        return ret;
    }

    int rleaf = 0;
    int* r = malloc(sizeof(int) * 2048);
    bobt(root, &r, &rleaf);

    int size = li + (2047 - ri) + rleaf;

    if (li && (2047 - ri))
        size -= 1;

    *returnSize = size;
    int* ret = malloc(sizeof(int) * size);

    int off = 0;

    if (li)
    {
        off = li;
        memcpy(ret, a, sizeof(int) * li);
    }
    else
    {
        off = 1;
        ret[0] = root->val;
    }

    if (rleaf)
        memcpy(ret + off, r, sizeof(int) * rleaf);
    off += rleaf;

    if (2047 - ri)
        memcpy(ret + off, a + ri + 1, sizeof(int) * (2046 - ri));
    return ret;
}
