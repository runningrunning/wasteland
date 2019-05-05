/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* t = node;
    struct ListNode* n = node->next;

    while(1)
    {
        t->val = n->val;

        if (!n->next)
            break;
        t = n;
        n = n->next;
    }
    t->next = NULL;
    free(n);
}
