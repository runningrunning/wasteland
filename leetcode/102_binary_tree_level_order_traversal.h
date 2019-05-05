/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int size = 1024;
    int top = 0;
    int cur = 0;
    struct TreeNode* stopper = root;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * size);
    stack[top ++] = root;
    stack[top ++] = NULL;

    int l = 0;
    int in = 0;
    int ls = 256;
    int** ret = malloc(sizeof(int*) * ls);
    ret[0] = malloc(sizeof(int) * 1);

    int ins = 256;

    int* cs = malloc(sizeof(int) * ls);
    cs[0] = 1;

    while(cur < top)
    {
        if (top + 2 > size)
        {
            size += 1024;
            stack = realloc(stack, sizeof(struct TreeNode*) * size);
        }

        if (!stack[cur])
        {
            if (!in)
            {
                free(ret[l]);
                ret[l] = NULL;
                cs[l] = 0;
                break;
            }

            l += 1;

            if (l >= ls)
            {
                ls += 256;
                ret = realloc(ret, sizeof(int*) * ls);
                cs = realloc(cs, sizeof(int) * ls);
            }

            cs[l - 1] = in;
            ins = 256;
            ret[l] = malloc(sizeof(int) * ins);
            cs[l] = 0;
            stack[top ++] = NULL;
            in = 0;
        }
        else
        {
            if (stack[cur]->left)
                stack[top ++] = stack[cur]->left;

            if (stack[cur]->right)
                stack[top ++] = stack[cur]->right;

            if (in >= ins - 1)
            {
                ins += 256;
                ret[l] = realloc(ret[l], ins);
            }
            ret[l][in++] = stack[cur]->val;
        }
        cur ++;
    }

    *columnSizes = cs;
    *returnSize = l;
    return ret;
}
