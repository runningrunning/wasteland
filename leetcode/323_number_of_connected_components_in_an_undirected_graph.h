int countComponents(int n, int** edges, int edgesRowSize, int edgesColSize)
{
    if (!edges || !edgesRowSize)
        return n;

    int id = 1;
    int* ns = calloc(sizeof(int), n);

    int num = 0;
    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        if (!ns[x] && !ns[y])
        {
            ns[x] = ns[y] = id ++;
            num ++;
        }
        else if (!ns[x] || !ns[y])
        {
            if (ns[x])
                ns[y] = ns[x];
            else
                ns[x] = ns[y];
        }
        else if (ns[x] != ns[y]) // corner case, should not reset if it's same
        {
            int t = ns[x];
            for (int i = 0; i < n; i ++)
            {
                if (ns[i] == t)
                    ns[i] = ns[y];
            }
            num --;
        }
    }

    int is = 0;
    for (int i = 0; i < n; i ++)
        if (!ns[i])
            is ++;
    return num + is;
}
