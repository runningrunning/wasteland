/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head || !head->next)
        return head;

    struct ListNode* h = head->next;
    struct ListNode* l = head;
    struct ListNode* ll = head;
    head->next = 0;
    struct ListNode* t;

    while(h)
    {
        t = h->next;

        if (h->val != ll->val)
        {
            ll->next = h;
            h->next = 0;
            ll = h;
        }

        h = t;
    }
    return head;
}
