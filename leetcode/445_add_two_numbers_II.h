/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (!l1 || !l2)
        return l1 ? l1 : l2;

    int la1[5120] = {0};
    int la2[5120] = {0};

    int len1 = 0;
    int len2 = 0;

    struct ListNode* li1 = l1;
    struct ListNode* li2 = l2;

    while(li1)
    {
        la1[len1 ++] = li1->val;
        li1 = li1->next;
    }

    while(li2)
    {
        la2[len2 ++] = li2->val;
        li2 = li2->next;
    }

    int len = len1 < len2 ? len1 : len2;

    struct ListNode* node = NULL;

    int inc = 0;
    int t2 = len2 - 1;
    int t1 = len1 - 1;
    for (int i = 0; i < len; i ++)
    {
        struct ListNode* r = malloc(sizeof(struct ListNode));
        r->next = node;
        node = r;
        int a = la2[t2 --] + la1[t1 --] + inc;
        r->val = a % 10;
        inc = a /10;
    }

    if (len2 - len)
    {
        if (!inc)
        {
            int t = len2 - len;
            struct ListNode** r = &l2;

            while(t--)
                r = &(*r)->next;
            *r = node;
            return l2;
        }


        t2 = len2 - len - 1;
        for (int i = 0; i < len2 - len; i ++)
        {
            struct ListNode* r = malloc(sizeof(struct ListNode));
            r->next = node;
            node = r;
            int a = la2[t2 --] + inc;
            r->val = a % 10;
            inc = a /10;
        }
    }
    else if (len1 - len)
    {
        if (!inc)
        {
            int t = len1 - len;
            struct ListNode** r = &l1;

            while(t --)
                r = &(*r)->next;
            *r = node;
            return l1;
        }

        t1 = len1 - len - 1;
        for (int i = 0; i < len1 -len; i ++)
        {
            struct ListNode* r = malloc(sizeof(struct ListNode));
            r->next = node;
            node = r;
            int a = la1[t1 --] + inc;
            r->val = a % 10;
            inc = a /10;
        }
    }

    if (inc)
    {
        struct ListNode* r = malloc(sizeof(struct ListNode));
        r->next = node;
        r->val = inc;
        node = r;
    }

    return node;
}
