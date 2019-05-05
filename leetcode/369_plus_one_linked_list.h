/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* plusOne(struct ListNode* head)
{
    if (!head)
        return head;

    struct ListNode* r = NULL;
    struct ListNode* t = NULL;

    /* reverse linked list */
    while(head)
    {
        t = head->next;
        head->next = r;
        r = head;
        head = t;
    }

    int c = 1;

    head = r;
    r = t = NULL;

    while (head)
    {
        t = head->next;
        head->next = r;
        r = head;
        head = t;

        c += r->val;
        r->val = c % 10;
        c /= 10;
    }

    if (c)
    {
        t = malloc(sizeof(struct ListNode));
        t->val = 1;
        t->next = r;
        r = t;
    }

    return r;
}
