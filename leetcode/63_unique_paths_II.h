// similar with 62  Unique Paths !!
// just count numbers
int uniquePathsWithObstacles(int** og, int ors, int ocs)
{
    if (!og)
        return 0;

    if (og[0][0])
        return 0;

    int* counts = calloc(sizeof(int), ors * ocs);
    counts[0] = 1;

    for (int i = 1; i < ocs; i ++)
        counts[i] = og[0][i] ? 0 : counts[i - 1];

    for (int j = 1; j < ors; j ++)
        counts[j * ocs] = og[j][0] ? 0 : counts[(j - 1) * ocs];

    for (int i = 1; i < ors; i ++)
        for (int j = 1; j < ocs; j ++)
        {
            int in = i * ocs + j;
            if (og[i][j])
                counts[in] = 0;
            else
                counts[in] = counts[(i - 1) * ocs + j] + counts[i * ocs + j - 1];
        }
    return counts[ors * ocs - 1];
}
