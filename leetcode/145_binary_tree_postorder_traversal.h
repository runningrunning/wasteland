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
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int ret_c = 0;
    int ret_n = 256;
    int* ret = malloc(sizeof(int) * ret_n);
    int stack_c = 0;
    int stack_n = 256;
    struct TreeNode* t = NULL;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * stack_n);
    *returnSize = 0;
    if (!root)
        return NULL;

    stack[stack_c ++] = root;
    do {
        if (ret_c >= ret_n)
        {
            ret_n += 256;
            ret = realloc(ret, sizeof(int) * ret_n);
        }

        t = stack[stack_c - 1];
        if (!t->left && !t->right)
        {
            stack_c --;
            ret[ret_c ++] = t->val;
        }
        else
        {
            if (stack_c + 2 >= stack_n)
            {
                stack_n += 256;
                stack = realloc(stack, sizeof(struct TreeNode*) * stack_n);
            }
            if (t->right)
                stack[stack_c ++] = t->right;
            if (t->left)
                stack[stack_c ++] = t->left;
            t->right = NULL;
            t->left = NULL;
        }
    }while(stack_c);

    *returnSize = ret_c;
    return ret;
}
