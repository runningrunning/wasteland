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

    struct ListNode* l = 0;
    struct ListNode* ll = 0;
    struct ListNode* h = head;
    struct ListNode* t;

    bool need = true;

    while(h->next)
    {
        t = h->next;

        if (h->val != h->next->val)
        {
            if (need)
            {
                if (!l)
                {
                    l = h;
                    ll = h;
                    h->next = 0;
                }
                else
                {
                    ll->next = h;
                    h->next = 0;
                    ll = h;
                }
            }
            need = true;
        }
        else
        {
            need = false;
        }
        h = t;
    }

    if (need)
    {
        if (!l)
            l = h;
        else
            ll->next = h;
        h->next = 0;
    }

    return l;
}
