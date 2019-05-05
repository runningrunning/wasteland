// optimize the reset same part
// it's my way to do the undirected graph
// use linked list or array to do the optimiaztion here !!
// learn a lot !!!!!!
// find simple solutions here !!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int _ids(int* ids, int x)
{
    int y = ids[x];
    while (y != x)
    {
        x = y;
        y = ids[y];
    }
    return y;
}

int* findRedundantConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
    *returnSize = 0;
    if (!edges || !edgesRowSize)
        return NULL;
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);

    int id = 1;
    int* ns = calloc(sizeof(int), (edgesRowSize + 1));
    int* ids = malloc(sizeof(int) * (edgesRowSize + 1));

    for (int i = 0; i < edgesRowSize; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        if (!ns[x] && !ns[y])
        {
            ns[x] = ns[y] = id;
            ids[id] = id;
            id ++;
        }
        else if (!ns[x] || !ns[y])
        {
            if (ns[x])
                ns[y] = _ids(ids, ns[x]); // ids[ns[x]];
            else
                ns[x] = _ids(ids, ns[y]); // ids[ns[y]];
        }
        else if (_ids(ids, ns[x]) == _ids(ids, ns[y]))
        {
            ret[0] = x;
            ret[1] = y;
        }
        else
        {
            ids[_ids(ids, ns[x])] = ids[ns[y]];
        }
    }
    return ret;
}


// optimize the reset same part
/*
int* findRedundantConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
    *returnSize = 0;
    if (!edges || !edgesRowSize)
        return NULL;
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);

    int id = 1;
    int* ns = calloc(sizeof(int), (edgesRowSize + 1));

    for (int i = 0; i < edgesRowSize; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        if (!ns[x] && !ns[y])
        {
            ns[x] = ns[y] = id ++;
        }
        else if (!ns[x] || !ns[y])
        {
            if (ns[x])
                ns[y] = ns[x];
            else
                ns[x] = ns[y];
        }
        else if (ns[x] == ns[y])
        {
            ret[0] = x;
            ret[1] = y;
        }
        else
        {
            int t = ns[x];
            for (int j = 1 ; j <= edgesRowSize; j ++)
                if (ns[j] == t)
                    ns[j] = ns[y];
        }
    }
    return ret;
}
*/
