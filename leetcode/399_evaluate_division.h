// use graph to do
// find better structure
// find simple solutions !!!!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define PRIMER 32771
#define V_MASK 0x7FFF
#define F_MASK 0x8000

int _id(int* i, int x)
{
    while (x != i[x])
        x = i[x];
    return x;
}

int _hash(char* x)
{
    int i = 0;
    int c = x[i ++];

    int t = 0;
    while (c)
    {
        t = ((t << 8) + c) % PRIMER;
        c = x[i ++];
    }
    return t;
}

// is it possible to infinite, yes, it is?
bool dfs(int** g, int x, int y, double* vs, double* r, char* f)
{
    if (x == y)
    {
        *r = 1.0;
        return true;
    }

    if (g[x])
    {
        int l = g[x][0];
        for (int i = 1; i < l; i += 2)
        {
            if (g[x][i] == y)
            {
                *r = g[x][i + 1] > 0 ? vs[g[x][i + 1] - 1]
                    : 1.0 / vs[- g[x][i + 1] - 1];
                return true;
            }
        }
    }

    double d;

    if (g[x])
    {
        int l = g[x][0];
        for (int i = 1; i < l; i += 2)
        {
            int v = g[x][i + 1] > 0 ? g[x][i + 1] - 1
                : - g[x][i + 1] - 1;

            if (f[v])
                continue;

            f[v] = 1;
            if (dfs(g, g[x][i], y, vs, &d, f))
            {
                *r = (g[x][i + 1] > 0 ? vs[v]
                      : 1.0 / vs[v]) * d;
                f[v] = 0;
                return true;
            }
            f[v] = 0;
        }
    }
    return false;
}

double* calcEquation(char*** equations, int equationsRowSize, int equationsColSize, double* values, int valuesSize, char*** queries, int queriesRowSize, int queriesColSize, int* returnSize)
{
    *returnSize = 0;
    if (!queries || !queriesRowSize || !queriesColSize)
        return NULL;
    *returnSize = queriesRowSize;

    int id = 0;
    short* hash = calloc(sizeof(short), PRIMER);
    char** strs = malloc(sizeof(char*) * 2 * equationsRowSize);

    // used to encode graph
    int** g = malloc(sizeof(int*) * 2 * equationsRowSize);

    // use to tell whether it's same group
    int sid = 1;
    int* is = calloc(sizeof(int), 2 * equationsRowSize);
    int* ns = calloc(sizeof(int), 2 * equationsRowSize);

    for (int i = 0; i < equationsRowSize; i ++)
    {
        char* x = equations[i][0];
        char* y = equations[i][1];
        int i_x = _hash(x);
        int i_y = _hash(y);
        int x_id, y_id;

        while (hash[i_x] && strcmp(strs[hash[i_x] & V_MASK], x))
            i_x = (i_x + 1) % PRIMER;

        if (!hash[i_x])
        {
            hash[i_x] = F_MASK | id;
            strs[id] = x;
            is[id] = 0;
            ns[id] = 0;
            g[id] = NULL;
            id ++;
        }

        while (hash[i_y] && strcmp(strs[hash[i_y] & V_MASK], y))
            i_y = (i_y + 1) % PRIMER;

        if (!hash[i_y])
        {
            hash[i_y] = F_MASK | id;
            strs[id] = y;
            is[id] = 0;
            ns[id] = 0;
            g[id] = NULL;
            id ++;
        }

        x_id = hash[i_x] & V_MASK;
        y_id = hash[i_y] & V_MASK;

        // merge
        if (!ns[x_id] && !ns[y_id])
        {
            ns[x_id] = ns[y_id] = sid;
            is[sid] = sid;
            sid ++;
        }
        else if (!ns[x_id] || !ns[y_id])
        {
            if (!ns[x_id])
                ns[x_id] = _id(is, ns[y_id]);
            else
                ns[y_id] = _id(is, ns[x_id]);
        }
        else if (_id(is, ns[x_id]) != _id(is, ns[y_id]))
        {
            is[x_id] = _id(is, ns[y_id]);
        }

        if (!g[x_id])
        {
            g[x_id] = malloc(sizeof(int) * 3);
            g[x_id][0] = 3;
            g[x_id][1] = y_id;
            g[x_id][2] = i + 1;
        }
        else
        {
            // should not have duplication, don't check dup
            int l = g[x_id][0];
            g[x_id] = realloc(g[x_id], sizeof(int) * (l + 2));
            g[x_id][0] = l + 2;
            g[x_id][l] = y_id;
            g[x_id][l + 1] = i + 1;
        }

        if (!g[y_id])
        {
            g[y_id] = malloc(sizeof(int) * 3);
            g[y_id][0] = 3;
            g[y_id][1] = x_id;
            g[y_id][2] = - (i + 1);
        }
        else
        {
            // should not have duplication, don't check dup
            int l = g[y_id][0];
            g[y_id] = realloc(g[y_id], sizeof(int) * (l + 2));
            g[y_id][0] = l + 2;
            g[y_id][l] = x_id;
            g[y_id][l + 1] = - (i + 1);
        }
    }


    char* fs = calloc(sizeof(char), equationsRowSize);

    double* ret = malloc(sizeof(double) * queriesRowSize);
    for (int i = 0; i < queriesRowSize; i ++)
    {
        char* x = queries[i][0];
        char* y = queries[i][1];

        int i_x = _hash(x);
        int i_y = _hash(y);

        while (hash[i_x] && strcmp(strs[hash[i_x] & V_MASK], x))
            i_x = (i_x + 1) % PRIMER;

        while (hash[i_y] && strcmp(strs[hash[i_y] & V_MASK], y))
            i_y = (i_y + 1) % PRIMER;

        if (!hash[i_x] || !hash[i_y])
        {
            ret[i] = - 1.0;
            continue;
        }

        if (i_x == i_y)
        {
            ret[i] = 1.0;
            continue;
        }

        int x_id = hash[i_x] & V_MASK;
        int y_id = hash[i_y] & V_MASK;

        if (_id(is, ns[x_id]) != _id(is, ns[y_id]))
        {
            ret[i] = - 1.0;
            continue;
        }

        if (!dfs(g, x_id, y_id, values, &ret[i], fs))
            ret[i] = - 1.0;
    }
    return ret;
}
