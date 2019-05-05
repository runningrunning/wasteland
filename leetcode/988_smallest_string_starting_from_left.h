/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// think too much !!!!
// INT_MAX / 8500 / 8500 = 29
// just scan, no need to do dynamic comparing
char* smallestFromLeaf(struct TreeNode* root)
{
    int sn = 1024;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * sn);
    int* istack = malloc(sizeof(int) * sn);
    int si = 0;
    istack[si] = 0;
    stack[si ++] = root;

    int lv = 0;
    int sc = 0;
    int slv = INT_MAX;

    while(sc < si)
    {
        struct TreeNode* s = stack[sc];
        int _lv = istack[sc] >> 16;
        if (_lv > slv)
        {
            sc --;
            break;
        }

        if (s->left)
        {
            if (si >= sn)
            {
                sn += 1024;
                stack = realloc(stack, sizeof(struct TreeNode*) * sn);
                istack = realloc(istack, sizeof(int) * sn);
            }
            stack[si] = s->left;
            istack[si] = (_lv + 1) << 16 | sc;

            si ++;
        }

        if (s->right)
        {
            if (si >= sn)
            {
                sn += 1024;
                stack = realloc(stack, sizeof(struct TreeNode*) * sn);
                istack = realloc(istack, sizeof(int) * sn);
            }
            stack[si] = s->right;
            istack[si] = (_lv + 1) << 16 | sc;
            si ++;
        }

        if (!s->right && !s->left && slv == INT_MAX)
            slv = _lv;
        sc ++;
    }

    if (sc == si)
        sc --;

    int cs = -1;

    while(sc >= 0)
    {
        struct TreeNode* s = stack[sc];
        int _lv = istack[sc] >> 16;
        if (_lv < slv)
            break;

        if (stack[sc]->left || stack[sc]->right)
            continue;

        if (cs == -1)
            cs = sc;
        else
        {
            int _a = cs;
            int _b = sc;

            if (stack[cs]->val < stack[sc]->val)
                continue;

            for (int i = _lv; i > 0; i --)
            {
                _a = istack[_a] & 0xFFFF;
                _b = istack[_b] & 0xFFFF;
                if (stack[_a]->val < stack[_b]->val)
                    break;
                if (stack[_a]->val > stack[_b]->val)
                {
                    cs = sc;
                    break;
                }
            }
        }
        sc --;
    }

    char* t = malloc(sizeof(char) * (_lv + 2));
    t[_lv + 1] = 0;

    for (int i = _lv; i >= 0; i --)
    {
        t[i] = stack[cs]->val + 'a';
        cs = istack[cs] & 0xFFFF;
    }

    return t;
}
