/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode* f = head;
    struct ListNode* s = head;

    while(1)
    {
        if (!f || !s)
            return false;
        f = f->next;
        if (!f)
            return false;
        f = f->next;
        s = s->next;

        if (f == s)
            return true;
    }

    return false;
}
