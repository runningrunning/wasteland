/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void rfp(struct TreeNode** r, char* s, int* si, int sl, int l)
{
    int c = *si;
    if (c + l >= sl || s[c + l] == '-')
        return;
    for (int i = 0; i < l; i ++)
        if (s[c + i] != '-')
            return;
    c += l;
    *si = c;

    int x = 0;
    while (s[c] && s[c] != '-')
    {
        x = x * 10 + (s[c] - '0');
        c ++;
    }

    struct TreeNode* t = malloc(sizeof(struct TreeNode));
    t->val = x;
    t->left = t->right = NULL;
    *r = t;
    *si = c;

    rfp(&t->left, s, si, sl, l + 1);
    rfp(&t->right, s, si, sl, l + 1);
}

struct TreeNode* recoverFromPreorder(char* S)
{
    int si = 0;
    int sl = strlen(S);
    struct TreeNode* r = NULL;
    rfp(&r, S, &si, sl, 0);
    return r;
}
