// STUPID Algorithm, use UNION FIND,try to optimize  can use list or others !!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numIslands2(int m, int n, int** positions, int positionsRowSize, int positionsColSize, int* returnSize)
{
    *returnSize = 0;
    if (!positions || !positionsRowSize)
        return NULL;

    *returnSize = positionsRowSize;

    int* is = calloc(sizeof(int), m * n);
    int* ps = malloc(sizeof(int) * positionsRowSize);
    int* rs = malloc(sizeof(int) * positionsRowSize);

    int ns = 0;
    int id = 1;

    for (int i = 0; i < positionsRowSize; i ++)
    {
        int x = positions[i][0];
        int y = positions[i][1];

        if (x < 0 || y < 0 || x >= m || y >= n || is[x * n + y])
            rs[i] = ns;
        else
        {
            int lid = (y && is[x * n + y - 1]) ? is[x * n + y - 1] : -1;
            int rid = (y != n - 1 && is[x * n + y + 1]) ? is[x * n + y + 1] : -1;
            int uid = (x && is[(x - 1) * n + y]) ? is[(x - 1) * n + y] : -1;
            int did = (x != m - 1 && is[(x + 1) * n + y]) ? is[(x + 1) * n + y] : -1;

            int mid = INT_MAX;

            if (lid != -1 && mid > ps[lid - 1])
                mid = ps[lid - 1];
            if (rid != -1 && mid > ps[rid - 1])
                mid = ps[rid - 1];
            if (uid != -1 && mid > ps[uid - 1])
                mid = ps[uid - 1];
            if (did != -1 && mid > ps[did - 1])
                mid = ps[did - 1];

            if (mid == INT_MAX)
            {
                is[x * n + y] = id;
                ps[id - 1] = id;
                id ++;
                ns ++;
            }
            else
            {
                is[x * n + y] = mid;
                if (lid != -1 && ps[lid - 1] != mid)
                {
                    int t = ps[lid - 1];
                    for (int j = 0; j < id; j ++)  // optimize here, try to find better solution, list nodes maybe ??
                        if (ps[j] == t)
                            ps[j] = mid;

                    ns --;
                    ps[lid - 1] = mid;
                }

                if (rid != -1 && ps[rid - 1] != mid)
                {
                    int t = ps[rid - 1];
                    for (int j = 0; j < id; j ++)
                        if (ps[j] == t)
                            ps[j] = mid;

                    ns --;
                    ps[rid - 1] = mid;
                }
                if (uid != -1 && ps[uid - 1] != mid)
                {
                    int t = ps[uid - 1];
                    for (int j = 0; j < id; j ++)
                        if (ps[j] == t)
                            ps[j] = mid;

                    ns --;
                    ps[uid - 1] = mid;
                }
                if (did != -1 && ps[did - 1] != mid)
                {
                    int t = ps[did - 1];
                    for (int j = 0; j < id; j ++)
                        if (ps[j] == t)
                            ps[j] = mid;

                    ns --;
                    ps[did - 1] = mid;
                }
            }
            rs[i] = ns;
        }
    }

    return rs;
}
