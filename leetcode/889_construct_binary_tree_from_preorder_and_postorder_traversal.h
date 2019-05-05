// have done this one before ?
// don't need to worry about same elements
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize)
{
    if (!preSize)
        return NULL;

    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    r->val = pre[0];
    r->left = r->right = NULL;

    if (preSize == 1)
        return r;

    int n = pre[1];

    // only one child, always left
    if (pre[1] == post[postSize - 2])
    {
        r->left = constructFromPrePost(pre + 1, preSize - 1, post, postSize - 1);
    }
    else
    {
        int i = 0;
        for (; i < preSize; i ++)
            if (post[i] == n)
                break;
        i ++;

        r->left = constructFromPrePost(pre + 1, i, post, i);
        r->right = constructFromPrePost(pre + 1 + i, preSize - 1 - i, post + i, preSize - 1 - i);
    }
    return r;
}
