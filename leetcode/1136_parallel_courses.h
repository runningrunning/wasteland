// find better code structure
// union find ? BFS ?
// better code ?
int minimumSemesters(int N, int** relations, int relationsSize, int* relationsColSize)
{
    int* all = calloc(sizeof(int), N + 1);

    int** sta = malloc(sizeof(int*) * relationsSize);
    int** stb = malloc(sizeof(int*) * relationsSize);

    for (int i = 0; i < relationsSize; i ++)
    {
        sta[i] = relations[i];
        all[relations[i][1]] ++;
    }

    int si = 0;
    int id = 1;

    int** st = sta;
    int** nst = stb;
    int ss = relationsSize;

    while (ss)
    {
        int* t = NULL;
        int cs = ss;

        for (int i = 0; i < ss; i ++)
        {
            t = st[i];

            if (all[t[0]] <= 0 && (all[t[0]] != -id))
            {
                all[t[1]] --;

                if (!all[t[1]])
                    all[t[1]] = -id;
            }
            else
            {
                nst[si ++] = t;
            }
        }

        if (si == cs)
            return -1;

        id ++;

        st = st == sta ? stb : sta;
        nst = nst == sta ? stb : sta;

        ss = si;
        si = 0;
    }
    return id;
}
