// how to detect it ??
// another kind of DP
// just simple recursive, not DP at all
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define C_MAX 1024
// num in r
// 0 is the node with cam, 1 is node without but monitor, 2 is node without and not monitor
void _mcc(struct TreeNode* root, int* n)
{
    if (!root)
    {
        n[0] = n[1] = n[2] = 0;
        return;
    }

    if (root->left && root->right)
    {
        int l[3] = {0};
        _mcc(root->left, l);
        int r[3] = {0};
        _mcc(root->right, r);

        int x0 = 1 + l[2] + r[2];
        int x1 = l[0] + r[1];
        int x2 = l[1] + r[1];

        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++)
            {
                int z = l[i] + r[j];
                if (z + 1 < x0)
                    x0 = z + 1;

                if (i == 2 || j == 2)
                    continue;

                if (i == 0 || j == 0)
                {
                    if (z < x1)
                        x1 = z;
                }
            }

        n[0] = x0;
        n[1] = x1;
        n[2] = x2;
    }
    else if (root->left || root->right)
    {
        int l[3] = {0};
        _mcc(root->left ? root->left : root->right, l);

        n[1] = l[0];
        n[2] = l[1];

        int x = l[0];

        if (l[1] < x)
            x = l[1];

        if (l[2] < x)
            x = l[2];

        n[0] = x + 1;

    }
    else
    {
        n[0] = 1;
        n[1] = C_MAX;
        n[2] = 0;
    }
}

int minCameraCover(struct TreeNode* root)
{
    int n[3] = {0};

    _mcc(root, n);
    n[2] += 1;
    int x = n[0] < n[1] ? n[0] : n[1];
    x = x < n[2] ? x : n[2];
    return x;
}

