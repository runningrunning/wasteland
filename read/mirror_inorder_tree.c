#include "../leetcode/common.h"

// Tree with Parent
typedef struct _TreeNode {
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;
    struct _TreeNode* parent;
} TreeNode;

TreeNode* cNode(int v)
{
    TreeNode* n = malloc(sizeof(TreeNode));
    n->left = n->right = n->parent = NULL;
    n->value = v;
    return n;
}

// when v[n] == 0, means empty nodes
TreeNode* cTree(int* v, int n)
{
    if (!n || !v[n])
        return NULL;

    TreeNode** ts = malloc(sizeof(TreeNode*) * n);

    TreeNode* root = cNode(v[0]);
    ts[0] = root;
    for (int i = 1; i < n; i ++)
    {
        int p = (i - 1) / 2;

        if (v[i])
        {
            if (!ts[p])
                printf("No parent %d for %d: %d.\n", p, i, v[i]);

            TreeNode* r = cNode(v[i]);
            ts[i] = r;
            r->parent = ts[p];

            // left
            if (i % 2)
                ts[p]->left = r;
            else
                ts[p]->right = r;

        }
        else
        {
            ts[i] = NULL;
        }
    }

    free(ts);
    return root;
}

// t is travel type
// 0: pre-order, 1: in-order, 2: post-order
void pTree(TreeNode* n, int t)
{
    if (!n)
        return;

    switch(t)
    {
        case 0:
            printf("%d ", n->value);
            pTree(n->left, t);
            pTree(n->right, t);
            break;
        case 1:
            pTree(n->left, t);
            printf("%d ", n->value);
            pTree(n->right, t);
            break;
        case 2:
            pTree(n->left, t);
            pTree(n->right, t);
            printf("%d ", n->value);
            break;
    }
}

int main(int argn, char** argv)
{
    int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int l = LEN_M(m);

    TreeNode* r = cTree(m, l);

    printf("Pre :");
    pTree(r, 0);
    printf("\n");

    printf("In :");
    pTree(r, 1);
    printf("\n");

    printf("Post :");
    pTree(r, 2);
    printf("\n");
}

