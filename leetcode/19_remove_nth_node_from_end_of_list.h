struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode** removed = malloc(sizeof(struct ListNode*) * (n + 1));
    memset(removed, 0, sizeof(struct ListNode*) * (n+1));
    int i = 0;
    struct ListNode* t = head;
    while(t)
    {
        removed[i % (n + 1)] = t;
        t = t->next;
        i ++;
    }
    int p = i % (n + 1);
    if (!removed[p])
        return head->next;
    int p1 = (i + 1) % (n + 1);
    removed[p]->next = removed[p1]->next;
    return head;
}
