// BFS
// HOW to OPTIMIZE this code ?
int findCheapestPrice(int n, int** flights, int flightsRowSize, int *flightsColSizes, int src, int dst, int K)
{
    int ni[101] = {0};
    int* ns = malloc(sizeof(int)* n * n);
    int* np = calloc(sizeof(int), n * n);

    for (int i = 0; i < flightsRowSize; i ++)
    {
        int s = flights[i][0];
        int d = flights[i][1];
        ns[s * n + ni[s]] = i;
        ni[s] ++;
        np[s * n + d] = flights[i][2];
    }

    int start = src * n;

    // use stack
    int* st = malloc(sizeof(int) * n);

    for (int i = 0; i < K; i ++)
    {
        bool update = false;
        memset(st, 0, sizeof(int) * n);
        for (int j = start; j < start + n; j ++)
        {
            if (np[j])
            {
                int startj = (j - start) * n;
                int endj = startj + ni[j - start];
                for (int k = startj; k < endj; k ++)
                {
                    int d = flights[ns[k]][1];
                    int p = flights[ns[k]][2];

                    if (!np[start + d] || np[start + d] > np[j] + p)
                    {
                        // don't update flight this time, wait for next
                        update = true;
                        if (!st[d] || st[d] > np[j] + p)
                            st[d] = np[j] + p;
                    }
                }
            }
        }

        if (!update)
            break;

        for (int j = 0; j < n; j ++)
            if (st[j])
                np[start + j] = st[j];
    }

    return np[src * n + dst] > 0 ? np[src * n + dst] : -1;
}
