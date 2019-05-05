/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode* f = head;
    struct ListNode* s = head;
    int num = 1;
    bool cycle = false;
    while(1)
    {
        if (!f || !s || !f->next)
            break;

        f = f->next->next;
        s = s->next;

        if (f == s)
        {
            cycle = true;
            while(s->next != f)
            {
                num ++;
                s = s->next;
            }
            break;
        }
    }

    if (!cycle)
        return NULL;

    f = head;
    s = head;

    for (int i = 0; i < num; i ++)
        s = s->next;

    while(s != f)
    {
        s = s->next;
        f = f->next;
    }

    return s;

    /*
    int count = 0;
    f = head;

    while(f != s)
    {
        count ++;
        f = f->next;
    }

    f = head;
    for(int i = 0; i < count - num; i ++)
        f = f->next;

    while(1)
    {
        s = f;
        for (int i = 0; i < num; i ++)
            s = s->next;
        if (s == f)
            return s;
        f = f->next;
    }

    return NULL;
    */
}
