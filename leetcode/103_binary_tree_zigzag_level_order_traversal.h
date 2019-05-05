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
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root)
        return NULL;

    int st_size = 512;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * st_size);
    int top = 0;
    stack[top ++] = NULL;
    int cur = top;
    stack[top ++] = root;
    int o_top = top;

    bool reverse = false;

    int reti = 0;
    int size = 512;
    int* rs = malloc(sizeof(int) * size);
    int** ret = malloc(sizeof(int*) * size);

    int ri = 0;
    int risize = 256;

    ret[0] = malloc(sizeof(int) * 1);

    while(1)
    {
        if (!stack[cur])
        {
            rs[reti] = ri;

            if (o_top == top)
                break;
            cur = top;
            stack[top++] = NULL;
            o_top = top;

            risize = 256;
            reverse = !reverse;

            if (reti + 1 > size)
            {
                size += 512;
                ret = realloc(ret, size);
            }
            ri = 0;
            reti ++;
            ret[reti] = malloc(sizeof(int) * risize);
        }
        else
        {
            if (top + 2 > st_size)
            {
                st_size += 512;
                stack = realloc(stack, sizeof(struct TreeNode*) * st_size);
            }

            if (reverse)
            {
                if (stack[cur]->right)
                    stack[top ++] = stack[cur]->right;
                if (stack[cur]->left)
                    stack[top ++] = stack[cur]->left;
            }
            else
            {
                if (stack[cur]->left)
                    stack[top ++] = stack[cur]->left;
                if (stack[cur]->right)
                    stack[top ++] = stack[cur]->right;
            }

            if (ri + 1 > risize)
            {
                risize += 256;
                ret[reti] = realloc(ret[reti], risize);
            }
            ret[reti][ri ++] = stack[cur]->val;
        }
        cur --;
    }

    *columnSizes = rs;
    *returnSize = reti + 1;
    return ret;
}
