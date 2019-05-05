struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* genList(int num)
{
    struct ListNode* ret = 0;
    struct ListNode** next = 0;
    do {
        struct ListNode *r = malloc(sizeof(struct ListNode));
        r->val = num % 10;
        r->next = 0;
        if (!ret)
            ret = r;
        else
            *next = r;
        next = &r->next;
        num /= 10;
    } while(num);
    return ret;
}

void outList(struct ListNode* l)
{
    while(l)
    {
        if (l->next)
            printf("%d -> ", l->val);
        else
            printf("%d \n", l->val);
        l = l->next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int n1 = 0;
    int n2 = 0;
    int level = 1;
    while(l1)
    {
        n1 += l1->val * level;
        level *= 10;
        l1 = l1->next;
    }
    level = 1;
    while(l2)
    {
        n2 += l2->val * level;
        level *= 10;
        l2 = l2->next;
    }
    n1 += n2;
    printf("%d %d %d.\n", n1 - n2, n2, n1);
    struct ListNode* g = genList(n1);
    outList(g);
    return genList(n1);
}

/* 25 ms */
struct ListNode* addTwoNumbers_2(struct ListNode* l1, struct ListNode* l2)
{
    int inc = 0;
    struct ListNode* ret = 0;
    struct ListNode** next = 0;
    while(l1 || l2 || inc)
    {
        struct ListNode *r = malloc(sizeof(struct ListNode));
        int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + inc;
        r->val = val % 10;
        inc = val / 10;
        r->next = 0;
        if (!ret)
            ret = r;
        else
            *next = r;
        next = &r->next;
        l1 = l1 ? l1->next : 0;
        l2 = l2 ? l2->next : 0;
    }
    return ret;
}

