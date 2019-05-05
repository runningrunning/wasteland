/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (m == n)
        return head;

    int i  = 1;

    struct ListNode** t = &head;
    struct ListNode* tt = NULL;
    struct ListNode** ppm = NULL;
    struct ListNode** pm = NULL;

    while(*t)
    {
        if (i >= m)
        {
            if (i == m)
            {
                ppm = t;
                pm = &((*t)->next);
            }
            else
            {
                if (i > n)
                    break;

                tt = *t;
                *pm = tt->next;
                tt->next = *ppm;
                *ppm = tt;
            }
            t = pm;
        }
        else
        {
            t = &((*t)->next);
        }
        i ++;
    }
    return head;
}
