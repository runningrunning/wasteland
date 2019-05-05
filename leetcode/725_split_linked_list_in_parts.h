/* k1  + ((i < k2) ? 1 : 0); is NOT SAME WITH k1 + (i < k2) ? 1 : 0 */
/* the priority of + is higher than ? */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    *returnSize = k;
    if (k < 1)
        return NULL;

    struct ListNode** ret = malloc(sizeof(struct ListNode*) * k);
    memset(ret, 0, sizeof(struct ListNode*) * k);

    if (k < 2)
    {
        ret[0] = root;
        return ret;
    }

    int l = 0;
    struct ListNode* r = root;

    while(r)
    {
        l ++;
        r = r->next;
    }

    int x = 0;
    int k1 = l / k;
    int k2 = l % k;
    struct ListNode* t;
    r = root;

    for (int i = 0; i < k; i ++)
    {
        ret[i] = r;
        x = k1  + ((i < k2) ? 1 : 0);
        x -= 1;
        if (x < 0)
            break;

        while(x --)
            r = r->next;
        t = r;
        r = r->next;
        t->next = NULL;
    }
    return ret;
}
