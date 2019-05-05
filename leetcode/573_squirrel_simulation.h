// STUPID WRONG ALGORITHM
// find the better position which squirrel can save the most steps
int minDistance(int height, int width, int* tree, int treeSize, int* squirrel, int squirrelSize, int** nuts, int nutsRowSize, int nutsColSize)
{
    int sx = squirrel[0];
    int sy = squirrel[1];
    int tx = tree[0];
    int ty = tree[1];

    int s_max = INT_MIN;
    int all = 0;
    for (int i = 0; i < nutsRowSize; i ++)
    {
        int x = nuts[i][0];
        int y = nuts[i][1];
        int dt = abs(x - tx) + abs(y - ty);
        all += dt << 1;

        if (dt - abs(sx - x) - abs(sy - y) > s_max)
            s_max = dt - abs(sx - x) - abs(sy - y);
    }
    return all - s_max;
}
