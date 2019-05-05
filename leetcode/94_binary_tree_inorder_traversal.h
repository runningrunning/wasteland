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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;

    int size = 512;
    int* ret = NULL;
    int cur = 0;
    ret = malloc(sizeof(int) * size);
    int sp = 1;
    int st_size = 512;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * size);
    stack[sp - 1] = root;
    bool back = false;

    while(sp)
    {
        if (stack[sp - 1]->left && !back)
        {
            if (sp >= st_size)
            {
                st_size += 512;
                stack = realloc(stack, sizeof(struct TreeNode*) * st_size);
            }
            stack[sp] = stack[sp - 1]->left;
            sp ++;
            back = false;
        }
        else
        {
            if (cur >= size)
            {
                size += 512;
                ret = realloc(ret, sizeof(int) * size);
            }
            ret[cur] = stack[sp - 1]->val;
            cur ++;

            if (stack[sp - 1]->right)
            {
                stack[sp - 1] = stack[sp - 1]->right;
                back = false;
            }
            else
            {
                sp --;
                back = true;
            }
        }
    }

    *returnSize = cur;
    return ret;
}
