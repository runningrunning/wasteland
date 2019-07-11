/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize)
{
    long long* t = calloc(sizeof(long long), N);
    int* ret = malloc(sizeof(int) * N);

    for (int i = 0; i < pathsSize; i ++)
    {
        int x = paths[i][0];
        int y = paths[i][1];
        t[x - 1] = t[x - 1] << 16 | y;
        t[y - 1] = t[y - 1] << 16 | x;
    }

    ret[0] = 1;
    for (int i = 1; i < N; i ++)
    {
        if (!t[i])
            ret[i] = 1;
        else
        {
            int f = 15;
            long long x = t[i];
            while (x)
            {
                if (x & 0xFFFF)
                {
                    if ((x & 0xFFFF) <= i)
                        f &= ~ (1 << (ret[(x & 0xFFFF) - 1] - 1));
                }
                x >>= 16;
            }
            for (int j = 0; j < 4; j ++)
                if (f & (1 << j))
                {
                    ret[i] = j + 1;
                    break;
                }
        }
    }
    *returnSize = N;
    return ret;
}
