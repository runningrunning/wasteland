void cov(struct TreeNode** i, int* nums, int s, int e)
{
    *i = NULL;

    if(s > e)
        return;

    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    *i = r;
    int m = ((e - s) / 2 + s);
    r->val = nums[m];
    cov(&r->left, nums, s, m - 1);
    cov(&r->right, nums, m + 1, e);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if (!head)
        return NULL;
    int size = 1024;
    int* is = malloc(sizeof(int) * size);
    int cur = 0;

    while(head)
    {
        if (cur >= size)
        {
            size += 512;
            is = realloc(is, sizeof(int) * size);
        }

        is[cur++] = head->val;
        head = head->next;
    }

    struct TreeNode* r;
    cov(&r, is, 0, cur - 1);
    return r;
}
