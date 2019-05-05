/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (!head)
        return false;

    int n = 0;
    struct ListNode* h = head;
    while(h)
    {
        n ++;
        h = h->next;
    }
    if (n == 1)
        return true;
    h = head;
    struct ListNode* t = NULL;
    struct ListNode* r = NULL;

    for(int i = 0; i < n >> 1; i ++)
    {
        t = h->next;
        h->next = r;
        r = h;
        h = t;
    }

    if (n & 1)
        t = t->next;

    for(int i = 0; i < n >> 1; i ++)
    {
        if (t->val != r->val)
            return false;
        t = t->next;
        r = r->next;
    }
    return true;
}
