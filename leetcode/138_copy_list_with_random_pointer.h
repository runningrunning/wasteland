/* TODO it's pretty slow, find better way to handle it.*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
    if (!head)
        return NULL;

    int num = 0;
    struct RandomListNode* h = head;
    struct RandomListNode** all = NULL;

    while(h)
    {
        all = realloc(all, (num + 1) * sizeof(struct RandomListNode*));
        all[num] = malloc(sizeof(struct RandomListNode));
        all[num]->label = h->label;
        all[num]->random = h->random;
        all[num]->next = h;
        h = h->next;
        num ++;
    }

    for(int i = 0; i < num; i ++)
    {
        if (all[i]->random)
        {
            int j = i;
            while(1)
            {
                if (all[j]->next == all[i]->random)
                {
                    all[i]->random = all[j];
                    break;
                }
                j = (j + 1) % num;
            }
        }
    }

    for(int i = 0; i < num - 1; i ++)
        all[i]->next = all[i + 1];

    all[num - 1]->next = NULL;
    return all[0];
}
