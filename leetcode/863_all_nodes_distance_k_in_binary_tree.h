/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void _add(int v, int** ret, int* rs)
{
    (*rs) ++;
    *ret = realloc(*ret, sizeof(int) * (*rs));
    (*ret)[(*rs) - 1] = v;
}

void _add_left(struct TreeNode* r, int c, int k, int** ret, int* rs)
{
    if (!r)
        return;

    if (c == k)
    {
        _add(r->val, ret, rs);
        return;
    }

    _add_left(r->right, c + 1, k, ret, rs);
    _add_left(r->left, c + 1, k, ret, rs);
}

bool _dk(struct TreeNode* r, struct TreeNode* t, int* o, int k, int** ret, int* rs)
{
    if (r == t)
    {
        *o = 0;
        _add_left(t, 0, k, ret, rs);
        return true;
    }

    if (r->left && _dk(r->left, t, o, k, ret, rs))
    {
        (*o) ++;
        if (*o <= k)
        {
            if (*o == k)
                _add(r->val, ret, rs);
            else if (r->right)
                _add_left(r->right, 1, k - (*o), ret, rs);
        }
        return true;
    }

    if (r->right && _dk(r->right, t, o, k, ret, rs))
    {
        (*o) ++;
        if (*o <= k)
        {
            if (*o == k)
                _add(r->val, ret, rs);
            else if (r->left)
                _add_left(r->left, 1, k - (*o), ret, rs);
        }
        return true;
    }
    return false;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize)
{
    int rs = 0;
    int* ret = NULL;

    if (K == 0)
    {
        *returnSize = 1;
        ret = malloc(sizeof(int));
        ret[0] = target->val;
        return ret;
    }

    int o = 0;
    _dk(root, target, &o, K, &ret, &rs);

    *returnSize = rs;
    return ret;
}
