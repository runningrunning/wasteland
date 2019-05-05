// similar with 310_minimum_height_trees.h
// more understand code
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int _sodit(int** ns, int** ms, int x, int l, char* f, int* m)
{
    int num = 0;
    int len = l;

    int* a = ns[x];
    for (int i = 1; i < a[0]; i ++)
    {
        int y = a[i];
        if (f[y])
            continue;
        f[y] = 1;
        num ++;
        len += _sodit(ns, ms, y, l + 1, f, &num);
        f[y] = 0;
    }
    (*m) += num;

    ms[x] = malloc(sizeof(int) * 2);
    ms[x][0] = num;
    ms[x][1] = len - (num + 1) * l;
    return len;
}

// c is the outside length of its parent
void _sodit_2(int** ns, int** ms, int x, int n, char* f, int* l, int c)
{
    int* a = ns[x];
    l[x] = ms[x][1] + c + (n - ms[x][0] - 1); // n - ms[x][0] - 1 is num of nodes outside
    for (int i = 1; i < a[0]; i ++)
    {
        int y = a[i];
        if (f[y])
            continue;
        f[y] = 1;
        // 1 + ms[y][0] + ms[y][1] is all length in y branch from x
        _sodit_2(ns, ms, y, n, f, l, l[x] - (1 + ms[y][1] + ms[y][0]));
        f[y] = 0;
    }
}

int* sumOfDistancesInTree(int N, int** edges, int edgesRowSize, int *edgesColSizes, int* returnSize)
{
    *returnSize = 0;
    if (!N)
        return NULL;

    *returnSize = N;
    int* l = calloc(sizeof(int), N);

    if (N == 1)
    {
        l[0] = 0;
        return l;
    }

    if (N == 2)
    {
        l[0] = 1;
        l[1] = 1;
        return l;
    }

    int** ns = calloc(sizeof(int*), N);
    int** ms = calloc(sizeof(int*), N);
    char* f = calloc(sizeof(char), N);

    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        if (!ns[x])
        {
            ns[x] = malloc(sizeof(int) * 2);
            ns[x][0] = 2;
            ns[x][1] = y;
        }
        else
        {
            int l = ns[x][0];
            // don't need to check whether it's existed here
            ns[x] = realloc(ns[x], sizeof(int) * (l + 1));
            ns[x][0] = l + 1;
            ns[x][l] = y;
        }

        if (!ns[y])
        {
            ns[y] = malloc(sizeof(int) * 2);
            ns[y][0] = 2;
            ns[y][1] = x;
        }
        else
        {
            int l = ns[y][0];
            ns[y] = realloc(ns[y], sizeof(int) * (l + 1));
            ns[y][0] = l + 1;
            ns[y][l] = x;
        }
    }

    f[0] = 1;
    int m = 0;
    _sodit(ns, ms, 0, 0, f, &m);
    f[0] = 0;

    f[0] = 1;
    _sodit_2(ns, ms, 0, N, f, l, 0);
    f[0] = 0;
    return l;
}
