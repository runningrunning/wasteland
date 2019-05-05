/* WHY ALWAYS MEMORY CORRUPTION !!! */
/* realloc should allocate sizeof(int) * size */
void ffts_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;
    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] < n[s]) i++;
        while(n[e] > n[s]) e--;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    ffts_sort(n, cs, e - 1);
    ffts_sort(n, e + 1, ce);
}

/* TODO understand the priority of operator */
int ffts(struct TreeNode* n, int** a, int* num)
{
    int l = 0;
    if (n->left)
        l = ffts(n->left, a, num);
    int r = 0;
    if (n->right)
        r = ffts(n->right, a, num);

    int all = n->val + l + r;

    (*a)[*num] = all;
    (*num) ++;

    if (!((*num) % 10240))
        *a = realloc(*a, *num + 10240);

    return all;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize)
{
    if (!root)
        return NULL;

    int n = 0;
    int* a = malloc(sizeof(int) * 10240);
    ffts(root, &a, &n);
    *returnSize = n;

    ffts_sort(a, 0, n - 1);

    int x = 0;
    int c = 0;
    int c_max = 0;

    for (int i = 0; i < n; i ++)
    {
        if (!c)
            c = 1;
        else
        {
            if (a[i] != a[i - 1])
            {
                c = 1;
            }
            else
                c ++;
        }

        if (c >= c_max)
        {
            if (c > c_max)
                x = 0;
            c_max = c;
            a[x ++] = a[i];
        }
    }
    *returnSize = x;
    return a;
}
