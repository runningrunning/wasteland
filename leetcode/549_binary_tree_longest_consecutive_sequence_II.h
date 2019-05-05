int lc(struct TreeNode* n, int* max, int p)
{
    if (!n)
        return 0;
    int v = n->val;
    int t;
    int l = lc(n->left, max, v);
    int r = lc(n->right, max, v);

    if (r > l)
    {
        t = l;
        l = r;
        r = t;
    }

    int x = 1;
    int y = 0;

    /*
      if (!l && !r)
      {
      if (p == v + 1)
      y = 1;
      else if (p == v - 1)
      y = -1;
      }
      else
      {
    */
    if (r > 0)
        r = 0;
    if (l < 0)
        l = 0;

    if (p == v - 1)
        y = r - 1;
    else if (p == v + 1)
        y = l + 1;
    x += l - r;
    /*
      }
      if (r > 0)
      {
      x += l;

      if (p == v - 1)
      y = -1;
      else if (p == v + 1)
      y = l + 1;
      }
      else if (l < 0)
      {
      x += - r;
      if (p == v - 1)
      y = r - 1;
      else if (p == v + 1)
      y = 1;
      }
      else
      {
      if (p == v - 1)
      y = r - 1;
      else if (p == v + 1)
      y = l + 1;
      x += l - r;
      }
    */
    if (*max < x)
        *max = x;
    return y;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestConsecutive(struct TreeNode* n)
{
    if (!n)
        return 0;
    int max = 0;
    lc(n, &max, n->val - 2);
    return max;
}

