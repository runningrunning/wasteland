/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* s1 = head;
    struct ListNode* s2 = head;

    while (s2 && s2->next) // should check s2 also.
    {
        s2 = s2->next;
        if (s2)
            s2 = s2->next;
        s1 = s1->next;
    }

    return s1;
}
