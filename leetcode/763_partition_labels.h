void pl_sort(int* n, int s, int e, int* id)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = id[e];
        id[e] = id[s];
        id[s] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = id[e];
            id[e] = id[s];
            id[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = id[e];
            id[e] = id[i];
            id[i] = t;
        }
    }

    pl_sort(n, cs, e - 1, id);
    pl_sort(n, e + 1, ce, id);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* find union method */
/* greedy method ? */
int* partitionLabels(char* S, int* returnSize)
{
    int st[26] = {0};
    int id[26] = {0};
    int en[26] = {0};

    for (int i = 0; i < 26; i ++)
    {
        id[i] = i;
        st[i] = en[i] = INT_MAX;
    }

    int i = 0;
    char c = S[i ++];

    if (!c)
        return NULL;

    while (c)
    {
        c -= 'a';

        if (st[c] < i)
            en[c] = i;
        else
        {
            st[c] = i;
            en[c] = i;
        }
        c = S[i ++];
    }

    int size = i;

    /* merge st and en */
    pl_sort(st, 0, 25, id);

    int si = 0;
    int sti = 0;
    int* stack = malloc(sizeof(int) * 32);
    stack[sti ++] = 0;

    while (true)
    {
        int next;
        int end = en[id[si]];

        for (next = si + 1; next < 26; next ++)
        {
            if (st[next] == INT_MAX || st[next] > end)
            {
                si = next;
                break;
            }

            if (en[id[next]] > end)
                end = en[id[next]];
        }
        if (next == 26 || st[si] == INT_MAX)
            break;
        stack[sti ++] = end;
    }
    stack[sti ++] = size - 1;

    for (int i = 0; i < sti - 1; i ++)
        stack[i] = stack[i + 1] - stack[i];
    stack[sti - 1] = 0;

    *returnSize = sti - 1;
    return stack;
}
