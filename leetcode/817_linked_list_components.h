/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* G, int GSize)
{
    int gf[320] = {0};

    for (int i = 0; i < GSize; i ++)
    {
        int x = G[i] / 32;
        int y = G[i] % 32;
        gf[x] |= 1 << y;
    }

    int n = 0;
    int pre = false;
    struct ListNode* h = head;
    while (h)
    {
        int x = h->val / 32;
        int y = h->val % 32;
        bool in = !!(gf[x] & (1 << y));

        if (!pre && in)
            n ++;
        pre = in;
        h = h->next;
    }
    return n;
}
