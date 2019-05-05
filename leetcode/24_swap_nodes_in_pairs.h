struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* header)
{
    if (!header || !header->next)
        return header;

    struct ListNode* h;
    struct ListNode** rh = &h;
    struct ListNode* t = NULL;

    while(header && header->next)
    {
        *rh = header->next;
        t = header->next->next;
        header->next->next = header;
        header->next = t;
        rh = &header->next;
        header = t;
    }
    return h;
}
