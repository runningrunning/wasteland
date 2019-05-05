// clear mind !!!!!!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _cdc(struct TreeNode* root, int* n, int* num, long* a)
{
    if (!root)
        return;
    int in = *n;
    (*n) ++;
    (*num) += root->val;
    long x = 0;
    int cn = *n;
    int cnum = *num;
    _cdc(root->left, n, num, a);
    x = (((long)(root->val)) << 56) | (((long) (*n - cn)) << 48)| (((long) (*num - cnum)) << 32);
    cn = *n;
    cnum = *num;
    _cdc(root->right, n, num, a);
    x |= (((long) (*n - cn)) << 24) | ((long) (*num - cnum));
    // typo here
    a[in] = x;
}

int distributeCoins(struct TreeNode* root)
{
    int n = 0;
    int num = 0;
    long all[101] = {0L};
    _cdc(root, &n, &num, all);

    int avg = num / n;
    int turns = 0;
    for (int i = 0; i < n; i ++)
    {
        long x = all[i];
        int v = x >> 56;
        int nl = (x >> 48) & 0xFF;
        int nlv = (x >> 32) & 0xFFFF;
        int nr = (x >> 24) & 0xFF;
        int nrv = (x) & 0xFFFF;

        // printf("i%d %d %d %d %d %d.\n", i, v, nl, nlv, nr, nrv);
        turns += abs(avg * nl - nlv);
        turns += abs(avg * nr - nrv);
        // printf("turns %d.\n", turns);
    }
    return turns;
}
