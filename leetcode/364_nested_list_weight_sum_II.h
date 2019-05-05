void ls(struct NestedInteger** nl, int ns, int l, int* max)
{
    if (*max < l)
        *max = l;

    for (int i = 0; i < ns; i ++)
    {
        struct NestedInteger* t = nl[i];
        if (!NestedIntegerIsInteger(t))
            ls(NestedIntegerGetList(t), NestedIntegerGetListSize(t), l + 1, max);
    }
}

int ds(struct NestedInteger** nl, int ns, int l, int c)
{
    int all = 0;
    int lv = c - l;

    for (int i = 0; i < ns; i ++)
    {
        struct NestedInteger* t = nl[i];
        if (NestedIntegerIsInteger(t))
            all += lv * NestedIntegerGetInteger(t);
        else
            all += ds(NestedIntegerGetList(t), NestedIntegerGetListSize(t), l + 1, c);
    }
    return all;
}

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
int depthSumInverse(struct NestedInteger** nestedList, int nestedListSize)
{
    if (!nestedList || !nestedListSize)
        return 0;

    int l = 0;
    ls(nestedList, nestedListSize, 1, &l);
    return ds(nestedList, nestedListSize, 0, l);
}
