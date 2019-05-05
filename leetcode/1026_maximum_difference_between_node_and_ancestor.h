// STUPID !!!, NOT BINARY SEARCH TREE, but BINARY TREE !!!!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* NOT binary SEARCH TREE
int maxAncestorDiff(struct TreeNode* root)
{
    if (!root)
        return 0;
    struct TreeNode* left = root->left;
    if (left)
        while (left->left)
            left = left->left;
    struct TreeNode* right = root->right;
    if (right)
        while (right->right)
            right = right->right;

    if (!left && !right)
        return 0;

    if (!left)
        return abs(root->val - right->val);
    if (!right)
        return abs(root->val - left->val);

    return abs(root->val - left->val) > abs(root->val - right->val) ?
        abs(root->val - left->val) : abs(root->val - right->val);
}
*/

void mad(struct TreeNode* r, int min, int max, int* ret)
{
    if (!r)
        return;

    int v = r->val;
    if (min != INT_MAX)
        if (*ret < abs(v - min))
            *ret = abs(v - min);

    if (max != INT_MIN)
        if (*ret < abs(v - max))
            *ret = abs(v - max);

    mad(r->left, min > v ? v : min, max < v ? v : max, ret);
    mad(r->right, min > v ? v : min, max < v ? v : max, ret);
}

int maxAncestorDiff(struct TreeNode* root)
{
    if (!root)
        return 0;

    int max = INT_MIN;
    int min = INT_MAX;
    int r = 0;

    mad(root, min, max, &r);
    return r;
}
