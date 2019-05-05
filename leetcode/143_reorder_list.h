void re(struct ListNode* h, struct ListNode* n, struct ListNode** t, struct ListNode*** r, bool* done)
{
    if (n->next)
    {
        if (!(*t))
            re(h, n->next, t, r, done);

        if (*done)
            return;

        struct ListNode* temp = *t;
        **r = temp;
        *t = temp->next;

        if (temp != n)
        {
            temp->next = n;
            *r = &n->next;

            if (*t == n)
            {
                (*t)->next = NULL;
                *done = true;
            }
        }
        else
        {
            temp->next = NULL;
            *done = true;
        }
    }
    else
    {
        **r = h;
        if (h->next)
        {
            *t = h->next;
            h->next = n;
            *r = &n->next;
            if (*t == n)
                *done = true;
        }
        else
            *done = true;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head)
{
    if (!head)
        return head;

    bool done = false;
    struct ListNode* t = NULL;
    struct ListNode* r = NULL;
    struct ListNode** ret = &r;
    re(head, head, &t, &ret, &done);
}
