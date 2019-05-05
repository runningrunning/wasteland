struct ListNode* reverseKGroup(struct ListNode* header, int k) {
    if (k <= 1)
        return header;

    struct ListNode* h = header;
    struct ListNode** rh = &h;

    int m = 0;
    while(header)
    {
        m ++;
        header = header->next;
        if (!(m % k))
        {
            struct ListNode *e = header;
            // reverse rh to e
            struct ListNode *s = *rh;
            struct ListNode ** oh = rh;
            rh = &s->next;
            struct ListNode *n = e;
            while(s != e)
            {
                struct ListNode *t = s->next;
                s->next = n;
                n = s;
                *oh = s;
                s = t;
            }
        }
    }
    return h;
}
/*
struct ListNode* swapPairs(struct ListNode* header)
{
    if (!header || !header->next)
        return header;

    struct ListNode* h;
    struct ListNode** rh = &h;
    struct ListNode* t = NULL;

    while(header && header->next)
    {
        *rh = header->next;
        t = header->next->next;
        header->next->next = header;
        header->next = t;
        rh = &header->next;
        header = t;
    }
    return h;
}

struct ListNode* reverseKGroup(struct ListNode* header, int k) {
    if (k <= 1)
        return header;

    if (k == 2)
        return swapPairs(header);

    int length = 0;
    struct ListNode* h = header;
    while(header)
    {
        length ++;
        header = header->next;
    }

    if (length < k)
        return h;

    struct ListNode** base = &h;

    for(int i = 0; i < length / k; i ++)
    {
        // reverse k
        for (int j = 0; j < k; j ++)
        {
            struct ListNode** a = base;
            struct ListNode** b = base;
            struct ListNode* temp = NULL;
            int m = j;
            int n = k - j - 1;

            if (m >= n)
                break;

            while(m --)
                a = &((*a)->next);
            while(n --)
                b = &((*b)->next);

            if ((*a)->next == *b)
            {
                struct ListNode* temp = *b;
                *b = (*b)->next;
                temp->next = *a;
                *a = temp;
            }
            else
            {
                struct ListNode* temp = (*a)->next;
                (*a)->next = (*b)->next;
                (*b)->next = temp;

                temp = *a;
                *a = *b;
                *b = temp;
            }
        }
        int o = k;
        while(o--)
            base = &((*base)->next);
    }

    return h;
}
*/
