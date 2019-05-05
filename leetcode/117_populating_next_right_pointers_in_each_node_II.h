struct TreeLinkNode** _nth(struct TreeLinkNode *r, int l, int n)
{
    if (r)
    {
        if (l == n)
            return &r->next;

        struct TreeLinkNode** ret = _nth(r->right, l + 1, n);
        if (ret)
            return ret;

        return _nth(r->left, l + 1, n);
    }
    return NULL;
}

void con(struct TreeLinkNode* h, struct TreeLinkNode *r, int n, int* max_n)
{
    if (r)
    {
        if (n > *max_n)
            *max_n = n;

        struct TreeLinkNode** i = _nth(h, 1, n);
        if (i)
        {
            if (*i)
                (*i)->next = r;
            *i = r;
        }

        con(h, r->left, n + 1, max_n);
        con(h, r->right, n + 1, max_n);
    }
}

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root)
{
    int max_n = 1;
    con(root, root, 1, &max_n);

    for(int i = 1; i <= max_n; i ++)
    {
        struct TreeLinkNode ** _n = _nth(root, 1, i);
        *_n = NULL;
    }
}
