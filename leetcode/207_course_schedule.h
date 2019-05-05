// find better solutions to optimize it !!!
// it's my way to do the graph !
// no better solutions!!!! just I confused about the sequences !!!!
bool _prerequistes(int** ns, int x, int y)
{
    if (!ns[x])
        return false;

    for (int i = 1; i < ns[x][0]; i ++)
        if (ns[x][i] == y)
            return true;

    for (int i = 1; i < ns[x][0]; i ++)
        if (_prerequistes(ns, ns[x][i], y))
            return true;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes)
{
    int** ns = calloc(sizeof(int*), numCourses);

    for (int i = 0; i < prerequisitesRowSize; i ++)
    {
        int y = prerequisites[i][0];  // it's y <= x y require x !!!!!, be careful about the sequences !!!!
        int x = prerequisites[i][1];

        if (_prerequistes(ns, x, y))
            return false;

        int in;
        if (!ns[y])
        {
            ns[y] = malloc(sizeof(int) * 2);
            ns[y][0] = 2;
            in = 1;
        }
        else
        {
            in = ns[y][0];
            ns[y] = realloc(ns[y], sizeof(int) * (in + 1));
            ns[y][0] = in + 1;
        }
        ns[y][in] = x;
    }
    return true;
}
