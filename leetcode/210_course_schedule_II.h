/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes, int* returnSize)
{
    *returnSize = numCourses;
    int* r = malloc(sizeof(int) * numCourses);

    if (!prerequisites || !prerequisitesRowSize)
    {
        for (int i = 0; i < numCourses; i ++)
            r[i] = i;
        return r;
    }

    int ri = 0;

    int** ns = calloc(sizeof(int*), numCourses);

    for (int i = 0; i < prerequisitesRowSize; i ++)
    {
        int y = prerequisites[i][0]; // be careful about the sequences, it's y required x !!!!
        int x = prerequisites[i][1];

        if (_prerequistes(ns, x, y))
        {
            *returnSize = 0;
            return NULL;
        }

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


    int left = 0;
    int* t = malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i ++)
    {
        if (!ns[i])
            r[ri ++] = i;
        else
            t [left ++] = i;
    }

    do
    {
        int nleft = 0;
        for (int i = 0; i < left; i ++)
        {
            bool found = false;
            int x = t[i];

            for (int j = 1; j < ns[x][0]; j ++)
                if (ns[ns[x][j]])
                {
                    found = true;
                    break;
                }

            if (!found)
            {
                free(ns[x]);
                ns[x] = 0;
                r[ri ++] = x;
            }
            else
            {
                t[nleft ++] = t[i];
            }
        }
        left = nleft;
    } while (left);

    return r;
}
