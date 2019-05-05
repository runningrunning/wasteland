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

bool _flv(struct TreeNode* r, int* v, int s, int e, int* f, int* fi)
{
    if (!r)
        return s < e;

    if (s > e)
        return false;

    if (!r->left && !r->right)
        return s == e;

    if (r->val != v[s])
        return false;

    if (!r->left || !r->right)
        return _flv(r->left ? r->left : r->right, v, s + 1, e, f, fi);

    if (s + 2 > e)
        return false;

    int le = r->left->val;
    int ri = r->right->val;

    if (v[s + 1] != le)
    {
        if (v[s + 1] != ri)
            return false;

        f[*fi] = r->val;
        *fi = *fi + 1;

        ri = le;
    }

    int i = 0;

    for (i = s + 1; i <= e; i ++)
        if (v[i] == ri)
            break;

    if (i > e)
        return false;

    if (v[s + 1] == r->left->val)
        return _flv(r->left, v, s + 1, i - 1, f, fi) &&
            _flv(r->right, v, i, e, f, fi);

    return _flv(r->right, v, s + 1, i - 1, f, fi) &&
        _flv(r->left, v, i, e, f, fi);

}

int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize)
{
    int ri = 0;
    int* r = malloc(sizeof(int) * voyageSize);

    if (!_flv(root, voyage, 0, voyageSize - 1, r, &ri))
    {
        ri = 1;
        r[0] = -1;
    }

    *returnSize = ri;
    return r;
}
