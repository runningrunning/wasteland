int findCircleNum(int** M, int MRowSize, int MColSize)
{
    int id = 1;
    int* ns = calloc(sizeof(int), MRowSize);
    int num = 0;
    for (int i = 0; i < MRowSize; i ++)
        for (int j = 0; j < MColSize; j ++)
        {
            if (j == i || !M[i][j])
                continue;

            if (!ns[i] && !ns[j])
            {
                ns[i] = ns[j] = id ++;
                num ++;
            }
            else if (!ns[i] || !ns[j])
            {
                if (ns[i])
                    ns[j] = ns[i];
                else
                    ns[i] = ns[j];
            }
            else if (ns[i] != ns[j])
            {
                int t = ns[i];
                for (int k = 0; k < MRowSize; k ++)
                    if (ns[k] == t)
                        ns[k] = ns[j];
                num --;
            }
        }

    int is = 0;
    for (int i = 0; i < MRowSize; i ++)
        if (!ns[i])
            is ++;
    return num + is;
}
