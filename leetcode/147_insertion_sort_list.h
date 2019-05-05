/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (!head)
        return head;

    struct ListNode* a = NULL;
    struct ListNode* r = head;

    while(r)
    {
        if (!r->next)
            return head;

        if (r->next->val >= r->val)
            r = r->next;
        else
        {
            a = r->next;
            r->next = NULL;
            break;
        }
    }

    struct ListNode* root = head;
    struct ListNode* t = head;
    struct ListNode** in = &head;
    struct ListNode* temp = NULL;

    while(a)
    {
        t = root;
        in = &root;
        temp = a->next;
        a->next = NULL;

        while(1)
        {
            if (!t)
            {
                *in = a;
                break;
            }
            else
            {
                if (t->val > a->val)
                {
                    *in = a;
                    a->next = t;
                    break;
                }
                in = &t->next;
                t = t->next;
            }
        }
        a = temp;
    }

    return root;
}
