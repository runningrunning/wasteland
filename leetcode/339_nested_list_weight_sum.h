int ds(struct NestedInteger** nl, int ns, int l)
{
    if (!nl || !ns)
        return 0;

    int all = 0;
    for (int i = 0; i < ns; i ++)
    {
        struct NestedInteger* t = nl[i];
        if (NestedIntegerIsInteger(t))
            all += l * NestedIntegerGetInteger(t);
        else
            all += ds(NestedIntegerGetList(t), NestedIntegerGetListSize(t), l + 1);
    }
    return all;
}

int depthSum(struct NestedInteger** nestedList, int nestedListSize)
{
    return ds(nestedList, nestedListSize, 1);
}
