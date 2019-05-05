/* Take care of input NULL */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB)
        return NULL;
    int numA = 0;
    struct ListNode* tA = headA;
    while(tA->next)
    {
        numA ++;
        tA = tA->next;
    }
    int numB = 0;
    struct ListNode* tB = headB;
    while(tB->next)
    {
        numB ++;
        tB = tB->next;
    }
    if (tA != tB)
        return NULL;
    tA = headA;
    tB = headB;

    if (numA > numB)
    {
        int t = numA - numB;
        while(t --)
            tA = tA->next;
    }
    if (numB > numA)
    {
        int t = numB - numA;
        while(t --)
            tB = tB->next;
    }
    while(tA != tB)
    {
        tA = tA->next;
        tB = tB->next;
    }
    return tA;
}
