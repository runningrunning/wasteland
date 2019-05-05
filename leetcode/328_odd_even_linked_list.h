/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head)
        return head;

    struct ListNode** odd = &head->next;
    if (!*odd)
        return head;

    struct ListNode** even = &head->next->next;
    if (!*even)
        return head;

    while (*even)
    {
        struct ListNode* t = *even;
        *even = t->next;
        t->next = *odd;
        *odd = t;
        odd = &(*odd)->next;
        if (!*even)
            break;
        even = &(*even)->next;
    }
    return head;
}
