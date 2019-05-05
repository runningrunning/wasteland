/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    int size;
    struct ListNode* cur;
    struct ListNode* head;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
    Solution* s = malloc(sizeof(Solution));
    s->head = head;
    s->cur = head;

    int size = 1;
    struct ListNode* h = head;
    while(h->next)
    {
        size ++;
        h = h->next;
    }
    s->size = size;
    h->next = head;
    return s;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    if (!obj)
        return 0;
    int step = rand() % obj->size;
    while(step --)
        obj->cur = obj->cur->next;
    return obj->cur->val;
}

void solutionFree(Solution* obj) {
    if (obj)
    {
        struct ListNode* h = obj->head;
        do
        {
            struct ListNode* t = h->next;
            free(h);
            h = t;
        } while(h != obj->head);
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */
