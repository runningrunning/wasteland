// try better solution, use array to sort and get the sequence !!!
// more careful !!!
// better solution !!!
bool sequenceReconstruction(int* org, int orgSize, int** seqs, int seqsRowSize, int *seqsColSizes)
{
    if (!org || !orgSize)
        return !seqs && !seqsRowSize;

    if (!seqs || !seqsRowSize)
        return false; // orgSize < 2; // stupid corner case [1] [] will be false

    int** ns = malloc(sizeof(int*) * (orgSize + 1));
    memset(ns, 0, sizeof(int*) * (orgSize + 1));

    int fn = 0;

    char* fs = calloc(sizeof(char), (orgSize + 1));
    for (int i = 0; i < seqsRowSize; i ++)
    {
        int* s = seqs[i];
        
        if (seqsColSizes[i] == 1)
        {
            int x = s[0];
            if (x < 1 || x > orgSize)
                return false;
            if (!fs[x])
            {
                fn ++;
                fs[x] = 1;
            }
        }      
        for (int j = 0; j < seqsColSizes[i] - 1; j ++)
        {
            int x = s[j];  // x - > y
            int y = s[j + 1];

            if (x < 1 || x > orgSize)
                return false;

            if (!fs[x])
            {
                fn ++;
                fs[x] = 1;
            }

            if (y < 1 || y > orgSize)
                return false;

            if (!fs[y])
            {
                fn ++;
                fs[y] = 1;
            }

            if (!ns[y])
            {
                ns[y] = malloc(sizeof(int) * 2);
                ns[y][0] = 2;
                ns[y][1] = x;
            }
            else
            {
                bool found = false;
                int l = ns[y][0];
                for (int k = 1; k < l; k ++)
                    if (ns[y][k] == x)
                    {
                        found = true;
                        break;
                    }

                if (!found)
                {
                    ns[y] = realloc(ns[y], sizeof(int) * (l + 1));
                    ns[y][l] = x;
                    ns[y][0] = l + 1;
                }
            }
        }
    }

    if (fn < orgSize)
        return false;

    int oi = 0;

    while (oi != orgSize)
    {
        int x = org[oi ++];

        if (ns[x])
            return false;

        int del = 0;

        for (int i = oi; i < orgSize; i ++)
        {
            int x = org[i];

            if (!ns[x])
                return false;

            bool found = false;
            for (int j = 1; j < ns[x][0]; j ++)
                if (ns[ns[x][j]])
                {
                    found = true;
                    break;
                }

            if (!found)
            {
                if (del)
                    return false;
                del = x;
            }
        }

        free(ns[del]);
        ns[del] = NULL;
    }
    return true;
}
