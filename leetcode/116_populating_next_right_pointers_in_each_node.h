void add_next(struct TreeLinkNode* h, struct TreeLinkNode* r, int n)
{
    while (n - 1)
    {
        if (h->right)
            h = h->right;
        else
            h = h->left;
        n --;
    }

    if (h->next)
        h->next->next = r;

    h->next = r;
}

void pre(struct TreeLinkNode* h, struct TreeLinkNode* r, int n)
{
    if (r)
    {
        add_next(h, r, n);
        pre(h, r->left, n + 1);
        pre(h, r->right, n + 1);
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
void connect(struct TreeLinkNode* root)
{
    pre(root, root, 1);

    struct TreeLinkNode* r = root;
    while(r)
    {
        r->next = NULL;
        r = r->right;
    }
}
