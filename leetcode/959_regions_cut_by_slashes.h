// field
// find a way to represent it
// how to write program here
int regionsBySlashes(char** grid, int gridSize)
{
    if (!grid || !gridSize || !grid[0])
        return 0;

    int id = 0;
    int c = strlen(grid[0]);

    int* up = calloc(sizeof(int), 31);

    int si = 0;
    int ss = 1024;
    int* stacks = malloc(sizeof(int) * ss);

    for (int i = 0; i < gridSize; i ++)
    {
        id ++;
        char* g = grid[i];
        int pp = -1;
        int pc = -1;
        int cp = -1;
        int cc = -1;

        for (int j = 0; j < c; j ++)
        {
            if (g[j] == ' ')
            {
                if (i)
                {
                    cp = up[j];
                    cc = id;
                }
                up[j] = id;
            }
            else if (g[j] == '/')
            {
                if (i)
                {
                    cp = up[j];
                    cc = id;
                }
                up[j] = ++ id;
            }
            else if (g[j] == '\\')
            {
                if (i)
                {
                    cp = up[j];
                    cc = id + 1;
                }
                up[j] = id ++;
            }

            if (cp != pp || cc != pc)
            {
                if (si == ss)
                {
                    ss += 1024;
                    stacks = realloc(stacks, sizeof(int) * ss);
                }
                stacks[si ++] = cp;
                stacks[si ++] = cc;
            }
            pp = cp;
            pc = cc;
        }
    }

    if (gridSize == 1)
        return id;

    int all = 0;
    char* bits = calloc(sizeof(char), (id + 1));
    int ti = 0;
    int* temp = malloc(sizeof(int) * si);

    all += 1;
    bits[stacks[0]] = 1;
    bits[stacks[1]] = 1;

    while (si)
    {
        for (int i = 0; i < si; i += 2)
        {
            int x = stacks[i];
            int y = stacks[i + 1];
            if (bits[x] || bits[y])
                bits[x] = bits[y] = 1;
            else
            {
                temp[ti ++] = x;
                temp[ti ++] = y;
            }
        }

        if (si == ti)
        {
            all ++;
            bits[temp[0]] = 1;
            bits[temp[1]] = 1;
        }

        si = ti;
        ti = 0;
        int* t = stacks;
        stacks = temp;
        temp = t;
    }

    for (int i = 1; i <= id; i ++)
        if (!bits[i])
            all ++;
    return all;
}

