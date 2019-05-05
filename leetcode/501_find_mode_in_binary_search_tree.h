int fm_count(struct TreeNode* root, int t, bool left, int no)
{
    int c = 0;
    if (root->val == t)
    {
        root->val = no;
        if (root->left)
            c = fm_count(root->left, t, true, no);

        if (root->right)
            c += fm_count(root->right, t, false, no);

        return c + 1;
    }
    else
    {
        if (left && root->right)
            return fm_count(root->right, t, left, no);

        if (!left && root->left)
            return fm_count(root->left, t, left, no);
    }
    return c;
}

int* fm(struct TreeNode* root, int** ret, int* cur, int* max, int no)
{
    if (root->val != no)
    {
        int t = root->val;
        int x = fm_count(root, root->val, false, no);
        if (x > *max)
        {
            *max = x;
            (*ret)[0] = t;
            *cur = 1;
        }
        else if (x == *max)
        {
            (*ret)[*cur] = t;
            (*cur) ++;
        }
    }

    if (root->left)
        fm(root->left, ret, cur, max, no);
    if (root->right)
        fm(root->right, ret, cur, max, no);
}

/*
int* fm_max(struct TreeNode* root, int* rs)
{
    int r = root;
    while(r->left)
        r = r->left;
}
*/

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
int* findMode(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int max = INT_MIN;
    int cur = 0;
    int* ret = malloc(sizeof(int) * 1024);

    int over = root->val;
    int x = fm_count(root, root->val, false, over);

    if (x > max)
    {
        max = x;
        ret[0] = over;
        cur = 1;
    }

    fm(root, &ret, &cur, &max, over);
    *returnSize = cur;
    return ret;
}
