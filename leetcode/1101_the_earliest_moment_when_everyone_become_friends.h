// careful
int comp(const void* a, const void* b)
{
    int* pa = *((int**)a);
    int* pb = *((int**)b);
    return pa[0] - pb[0];
}

int earliestAcq(int** logs, int logsSize, int* logsColSize, int N)
{
    qsort(logs, logsSize, sizeof(int*), comp);

    int meet = 0;
    int groups = 0;
    int group_id = 1;
    int all[128] = {0};

    for(int i = 0; i < logsSize; i ++)
    {
        int a = logs[i][1];
        int b = logs[i][2];

        if (all[a] && all[b])
        {
            // not equal
            if (all[a] != all[b])
            {
                // store the a here in case it's changed in all[j] = all[b]
                a = all[a];
                groups --;
                for (int j = 0; j <= N; j ++)
                    if (all[j] == a)
                        all[j] = all[b];
            }
        }
        else if (all[a] || all[b])
        {
            meet += 1;
            all[a] = all[b] = all[a] + all[b];
        }
        else
        {
            meet += 2;
            all[a] = all[b] = group_id ++;
            groups ++;
        }

        if (groups <= 1 && meet == N)
            return logs[i][0];
    }
    return -1;
}
