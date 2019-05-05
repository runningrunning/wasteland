/* why 1 2 ? STUPID bool v !!!!!!!!!!!!!!!!!!!!!!!!!! */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct BSTIterator
{
    int si;
    struct TreeNode* stacks[256];
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root)
{
    if (!root)
        return NULL;

    struct BSTIterator* b = malloc(sizeof(struct BSTIterator));
    b->stacks[0] = NULL;

    int si = 1;
    while(root)
    {
        b->stacks[si ++] = root;
        root = root->left;
    }
    b->si = si - 1;
    return b;
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter)
{
    return iter && iter->si;
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter)
{
    int v = 0;
    if (iter && iter->si)
    {
        struct TreeNode* n = iter->stacks[iter->si];
        v = n->val;

        if (n->right)
        {
            n = n->right;
            while(n)
            {
                iter->stacks[iter->si ++] = n;
                n = n->left;
            }
        }
        iter->si --;
    }
    return v;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter)
{
        free(iter);
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
