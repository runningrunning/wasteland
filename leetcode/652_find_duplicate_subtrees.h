/* Method 2: use stack to find in the part which has not been scanned */
/* TODO how to mark duplicate and remove them? */
/* hash to detect duplicate !*/
/* try HARD !!! */

bool is_dup(struct TreeNode* a, struct TreeNode* b)
{
    if (a == NULL || b == NULL)
        return a == b;
    return (a->val == b->val) && is_dup(a->left, b->left)
        && is_dup(a->right, b->right);
}

#define FMASK 0x8000
#define VMASK 0x7FFF
#define PRIMER 8209

int fds(struct TreeNode* r, struct TreeNode*** st, int* si, short* hash, int* ri, struct TreeNode*** ret, int* sf)
{
    if (!r)
        return INT_MAX % PRIMER;

    int left = fds(r->left, st, si, hash, ri, ret, sf);
    int right = fds(r->right, st, si, hash, ri, ret, sf);

    long n = (((long)left << 32) + ((long)right << 16) + r->val) % PRIMER;
    int x = n;

    bool has = false;
    while ((hash[x] & FMASK))
    {
        int t = hash[x] & VMASK;
        if ((*st)[t] && is_dup((*st)[t], r))
        {
            int m = t /32;
            int n = t % 32;
            if (!(sf[m] & (1 << n)))
            {
                sf[m] |= 1 << n;
                int ti = (*ri) + 1;
                *ret = realloc(*ret, sizeof(struct TreeNode*) * ti);
                (*ri) ++;
                (*ret)[ti - 1] = (*st)[t];
            }
            has = true;
        }
        x = (x + 1) % PRIMER;
    }

    if (!has)
    {
        int s = *si;
        if (!((s + 1) % 2048))
            *st = realloc(*st, sizeof(struct TreeNode*) * (s + 2049));
        (*si) ++;
        (*st)[s] = r;
        hash[x] = FMASK | s;
    }
    return (int) n;
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
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;

    int ri = 0;
    struct TreeNode** r = NULL;

    // hash
    short* hp = calloc(sizeof(short), PRIMER);

    int sf[2048] = {0};

    int si = 0;
    struct TreeNode** st = malloc(sizeof(struct TreeNode*) * 2048);
    fds(root, &st, &si, hp, &ri, &r, sf);
    *returnSize = ri;
    return r;
}
