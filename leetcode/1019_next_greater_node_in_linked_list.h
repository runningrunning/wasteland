int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    if (!head)
        return NULL;

    int sn = 1024;
    int si = 0;
    long* stack = malloc(sizeof(long) * sn);
    long rn = 1024;
    long ri = 0;
    int* ret = malloc(sizeof(int) * rn);
    ret[ri ++] = 0;
    stack[si ++] = 0L << 32 | head->val;

    struct ListNode* r = head->next;
    while (r)
    {
        if (ri == rn)
        {
            rn += 1024;
            ret = realloc(ret, sizeof(int) * rn);
        }
        ret[ri] = 0;
        int val = r->val;
        while (si && (val > (stack[si - 1] & 0xFFFFFFFF)))
        {
            si --;
            ret[stack[si] >> 32] = val;
        }

        if (si == sn)
        {
            sn += 1024;
            stack = realloc(stack, sizeof(long) * sn);
        }
        stack[si ++] = ri << 32 | val;
        ri ++;
        r = r->next;
    }

    *returnSize = ri;
    return ret;
}
