/* TODO Something wrong in memory */
void ts(struct TreeNode* t, char** s, int* n, int* max)
{
    if ((*n + 50) > (*max))
    {
        *max += 2048;
        *s = realloc(*s, *max);
    }

    int i = sprintf((*s) + *n, "%d", t->val);
    *n += i;

    if (t->left)
    {
        int ii = sprintf((*s) + *n, "(");
        *n += ii;
        ts(t->left, s, n, max);
        int iii = sprintf((*s) + *n, ")");
        *n += iii;
    }
    else if (t->right)
    {
        int ii = sprintf((*s) + *n, "()");
        *n += ii;
    }

    if (t->right)
    {
        int ii = sprintf((*s) + *n, "(");
        *n += ii;
        ts(t->right, s, n, max);
        int iii = sprintf((*s) + (*n), ")");
        *n += iii;
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* tree2str(struct TreeNode* t)
{
    char* s = (char*) malloc(20480);
    s[0] = 0;

    int n = 0;
    int m = 20480;

    if (!t)
        return s;
    ts(t, &s, &n, &m);
    return s;
}
