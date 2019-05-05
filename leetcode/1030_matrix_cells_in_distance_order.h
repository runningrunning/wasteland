/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int R, int C, int r0, int c0, int** columnSizes, int* returnSize) {
    if (!R || !C)
        return 0;

    int n = R * C;
    int* cs = malloc(sizeof(int) * n);
    *columnSizes = cs;
    *returnSize = n;

    char* bs = calloc(sizeof(char), (n + 1));

    int ri = 0;
    int rs = 1;
    int** ret = malloc(sizeof(int*) * n);

    ret[0] = malloc(sizeof(int) * 2);
    ret[0][0] = r0;
    ret[0][1] = c0;
    bs[r0 * C + c0] = 1;

    while (ri < rs)
    {
        int* cur = ret[ri ++];
        int d = abs(cur[0] - r0) + abs(cur[1] - c0);

        if (cur[0] + 1 < R)
        {
            int d1 = abs(cur[0] + 1 - r0) + abs(cur[1] - c0);
            if (d + 1 == d1 && !bs[(cur[0] + 1) * C + cur[1]])
            {
                ret[rs] = malloc(sizeof(int) * 2);
                ret[rs][0] = cur[0] + 1;
                ret[rs][1] = cur[1];
                bs[(cur[0] + 1) * C + cur[1]] = 1;
                rs ++;
            }
        }

        if (cur[0])
        {
            int d2 = abs(cur[0] - 1 - r0) + abs(cur[1] - c0);
            if (d + 1 == d2 && !bs[(cur[0] - 1) * C + cur[1]])
            {
                ret[rs] = malloc(sizeof(int) * 2);
                ret[rs][0] = cur[0] - 1;
                ret[rs][1] = cur[1];
                bs[(cur[0] - 1) * C + cur[1]] = 1;
                rs ++;
            }
        }

        if (cur[1] + 1 < C)
        {
            int d3 = abs(cur[0] - r0) + abs(cur[1] + 1 - c0);
            if (d + 1 == d3 && !bs[(cur[0]) * C + cur[1] + 1])
            {
                ret[rs] = malloc(sizeof(int) * 2);
                ret[rs][0] = cur[0];
                ret[rs][1] = cur[1] + 1;
                bs[(cur[0]) * C + cur[1] + 1] = 1;
                rs ++;
            }
        }

        if (cur[1])
        {
            int d4 = abs(cur[0] - r0) + abs(cur[1] - 1 - c0);
            if (d + 1 == d4 && !bs[(cur[0]) * C + cur[1] - 1])
            {
                ret[rs] = malloc(sizeof(int) * 2);
                ret[rs][0] = cur[0];
                ret[rs][1] = cur[1] - 1;
                bs[(cur[0]) * C + cur[1] - 1] = 1;
                rs ++;
            }
        }
        if (rs == n)
            break;
    }

    for (int i = 0; i < n; i ++)
        cs[i] = 2;
    return ret;
}
