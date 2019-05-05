/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head)
{
    int level = 1;
    struct ListNode** h = &head;
    struct ListNode* ea = NULL;
    struct ListNode* eb = NULL;
    struct ListNode* a = *h;

    if (!head)
        return head;

    while(1)
    {
        h = &head;
        a = head;

        while(1)
        {
            if (a)
            {
                struct ListNode* b = a;
                int l = level;
                while(l -- && b)
                    b = b->next;

                if (b)
                {
                    ea = eb = b;
                    l = level;
                    while(l -- && eb)
                        eb = eb->next;

                    while(a != ea || b != eb)
                    {
                        if (a == ea)
                        {
                            *h = b;
                            while(b != eb)
                            {
                                h = &b->next;
                                b = b->next;
                            }
                        }
                        else if (b == eb)
                        {
                            *h = a;
                            while(a != ea)
                            {
                                h = &a->next;
                                a = a->next;
                            }
                        }
                        else if (a->val < b->val)
                        {
                            *h = a;
                            h = &a->next;
                            a = a->next;
                        }
                        else
                        {
                            *h = b;
                            h = &b->next;
                            b = b->next;
                        }
                    }
                    a = eb;
                    *h = eb;
                }
                else
                {
                    *h = a;
                    if (a == head)
                        return head;
                    break;
                }
            }
            else
                break;
        }
        level *= 2;
    }
    return head;
}
