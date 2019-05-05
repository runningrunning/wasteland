/* consecutive sequence means +1 !!!!! */
void lc(struct TreeNode* root, int pre, int cur, int* max)
{
    if (!root)
        return;
    if (root->val - pre == 1)
    {
        cur ++;
        if (cur > *max)
            *max = cur;
    }
    else
        cur = 1;

    lc(root->left, root->val, cur, max);
    lc(root->right, root->val, cur, max);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestConsecutive(struct TreeNode* root)
{
    if (!root)
        return 0;
    int max = 1;
    lc(root, root->val - 2, 1, &max);
    return max;
}

/*
void lc(struct TreeNode* root, int pre, int cur, int* max, int delta)
{
    if (!delta)
    {
        if (root->left)
            lc(root->left, root->val, 1, max, root->left->val - root->val);

        if (root->right)
            lc(root->right, root->val, 1, max, root->right->val - root->val);
    }
    else
    {
        int d = delta > 0 ? 1 : -1;

        if (root->val - pre == d)
            cur ++;
        else
            cur = 1;

        if (cur > *max)
            *max = cur;

        if (root->left)
        {
            int dl = root->left->val - root->val;
            if (dl)
            {
                int td = dl > 0 ? 1 : -1;
                if (td == d)
                    lc(root->left, root->val, cur, max, delta);
            }
        }

        if (root->right)
        {
            int dl = root->right->val - root->val;
            if (dl)
            {
                int td = dl > 0 ? 1 : -1;
                if (td == d)
                    lc(root->right, root->val, cur, max, delta);
            }
        }
    }
}

int longestConsecutive(struct TreeNode* root)
{
    if (!root)
        return 0;

    int max = 1;

    if (root->left)
        lc(root->left, root->val, 1, &max, root->left->val - root->val);

    if (root->right)
        lc(root->right, root->val, 1, &max, root->right->val - root->val);
    return max;
}
*/
