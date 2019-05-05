// HEAP merged
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0)
        return 0;

    if (listsSize == 1)
        return lists[0];
    struct ListNode* r = NULL;

    int hs = 0;
    struct ListNode** heap = malloc(sizeof(struct ListNode*) * listsSize);

    for (int i = 0; i < listsSize; i ++)
    {
        if (!lists[i])
            continue;
        heap[hs] = lists[i];
        hs ++;

        int x = hs - 1;
        while (x > 0)
        {
            int p = (x - 1) / 2;
            struct ListNode* px = heap[x];
            struct ListNode* pp = heap[p];
            if (pp->val <= px->val)
                break;
            heap[p] = px;
            heap[x] = pp;
            x = p;
        }
    }
    struct ListNode** n = &r;

    while (hs)
    {
        *n = heap[0];
        n = &(heap[0]->next);

        if (heap[0]->next)
            heap[0] = heap[0]->next;
        else
            heap[0] = heap[-- hs];

        if (!hs)
            break;

        int x = 0;

        while (x * 2 + 1 < hs)
        {
            int left = heap[x * 2 + 1]->val;
            int right = left;

            if (x * 2 + 2 < hs)
                right = heap[x * 2 + 2]->val;

            struct ListNode* tmp = heap[x];

            if (left <= right)
            {
                if (heap[x]->val <= left)
                    break;

                heap[x] = heap[x * 2 + 1];
                heap[x * 2 + 1] = tmp;
                x = x * 2 + 1;
            }
            else
            {
                if (heap[x]->val <= right)
                    break;

                heap[x] = heap[x * 2 + 2];
                heap[x * 2 + 2] = tmp;
                x = x * 2 + 2;
            }
        }
    }
    return r;
}
