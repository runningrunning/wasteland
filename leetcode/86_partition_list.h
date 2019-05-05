/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    if (!head || !head->next)
        return head;

    struct ListNode* lo = 0;
    struct ListNode* loi = 0;
    struct ListNode* ho = 0;
    struct ListNode* hoi = 0;
    struct ListNode* h = head;
    struct ListNode* t;

    while(h)
    {
        t = h->next;

        if (h->val < x)
        {
            if (!lo)
            {
                loi = lo = h;
                h->next = 0;
            }
            else
            {
                loi->next = h;
                h->next = 0;
                loi = h;
            }
        }
        else
        {
            if (!ho)
            {
                hoi = ho = h;
                h->next = 0;
            }
            else
            {
                hoi->next = h;
                h->next = 0;
                hoi = h;
            }
        }
        h = t;
    }


    if (lo)
    {
        loi->next = ho;
        return lo;
    }
    return ho;
}
