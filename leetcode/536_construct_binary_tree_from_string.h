/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* 4(2(3)(1))(6(5)) */
/* Don't need to handle () */
struct TreeNode* str2tree(char* s)
{
    if (!s)
        return NULL;

    int l = strlen(s);

    if (!l)
        return NULL;

    int sti = 0;
    struct TreeNode** st = malloc(sizeof(struct TreeNode*) * (l + 1) / 2);

    int v = 0;
    bool minus = false;
    bool has_value = false;

    int si = 0;
    struct TreeNode* n = NULL;

    while(s[si])
    {
        char c = s[si];

        if (c == '(' || c == ')')
        {
            n = NULL;

            if (has_value)
            {
                n = malloc(sizeof(struct TreeNode));
                n->val = minus ? -v : v;
                n->left = NULL;
                n->right = NULL;

                v = 0;
                minus = false;
                has_value = false;

                if (c == '(')
                    st[sti ++] = n;
            }

            if (c == ')')
            {
                struct TreeNode* x = st[sti - 1];
                if (!n)
                {
                    sti --;
                    n = x;
                    x = st[sti - 1];
                }

                if (!x->left)
                    x->left = n;
                else if (!x->right)
                    x->right = n;
            }
        }
        else
        {
            if (c == '-')
                minus = true;
            else
            {
                has_value = true;
                v = (c - '0')  + v * 10;
            }
        }
        si ++;
    }

    if (has_value)
    {
        n = malloc(sizeof(struct TreeNode));
        n->val = minus ? -v : v;
        n->left = NULL;
        n->right = NULL;
        st[0] = n;
    }

    return st[0];
}
