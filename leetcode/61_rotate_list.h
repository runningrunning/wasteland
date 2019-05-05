/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int l = 0;
    struct ListNode* h = head;
    struct ListNode** tail = NULL;

    while(h)
    {
        tail = &h->next;
        h = h->next;
        l ++;
    }

    k %= l;

    if (k == 0)
        return head;

    h = head;
    int t = l - k - 1;

    while(t)
    {
        t --;
        h = h->next;
    }

    struct ListNode* temp = h->next;

    h->next = NULL;
    *tail = head;

    return temp;
}
