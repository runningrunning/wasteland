// same as 684 redundant connecton
// divide to different groups
int _ids(int* is, int x)
{
    while (is[x] != x)
        x = is[x];
    return x;
}

bool validTree(int n, int** edges, int edgesRowSize, int edgesColSize)
{
    if (!n)
        return false;

    if (n <= 2)
        return edgesRowSize == n - 1;

    if (edgesRowSize != n - 1)
        return false;

    int id = 1;
    int* ns = calloc(sizeof(int), n + 1);
    int* is = malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0] + 1;
        int y = edges[i][1] + 1;

        if (!ns[x] && !ns[y])
        {
            ns[x] = ns[y] = id;
            is[id] = id;
            id ++;
        }
        else if (!ns[x] || !ns[y])
        {
            if (ns[x])
                ns[y] = _ids(is, ns[x]);
            else
                ns[x] = _ids(is, ns[y]);
        }
        else if (_ids(is, ns[x]) != _ids(is, ns[y]))
            ns[x] = _ids(is, ns[x]);
        else
            return false;
    }
    return true;
}
