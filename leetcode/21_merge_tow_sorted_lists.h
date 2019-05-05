struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    struct ListNode* h = NULL;
    struct ListNode* header = NULL;

    if (l1->val < l2->val)
    {
        header = l1;
        l1 = l1->next;
    }
    else
    {
        header = l2;
        l2 = l2->next;
    }
    h = header;

    while(l1 && l2)
    {
        if (l1->val < l2->val)
        {
            header->next = l1;
            l1 = l1->next;
        }
        else
        {
            header->next = l2;
            l2 = l2->next;
        }
        header = header->next;
    }
    if (l1)
        header->next = l1;
    if (l2)
        header->next = l2;

    return h;
}
