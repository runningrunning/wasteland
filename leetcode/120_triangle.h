// TOTAL STUPID ALGORITHMS ~~~~~
// THINK TOO MUCH ~~~!!!!
// DP ways, why is faster than others? Because we can do cut ????
// From the bottom to the top, it's pretty easy to do so.
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    int** t = triangle;
    int r = triangleRowSize;
    int* n = t[r - 1];
    for (int i = r - 2; i >= 0; i --)
    {
        int* m = t[i];
        for (int j = 0; j <= i; j ++)
            n[j] = (n[j] < n[j + 1] ? n[j] : n[j + 1]) + m[j];
    }
    return n[0];
}
// stupid wrong algorithm !
/*
// 0x011 and 0x100 is not only one position changed
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    if (!triangle || !triangleRowSize)
        return 0;

    int all = 0;

    char* ns = malloc(triangleRowSize);
    bzero(ns, triangleRowSize);

    int min = INT_MAX;

    for (int i = 0; i < triangleRowSize; i ++)
        all += triangle[i][0];

    if (min > all)
        min = all;

    char* fgs = malloc(triangleRowSize);
    bzero(fgs, triangleRowSize);

    while (true)
    {
        fgs[0] += 1;

        int i = 0;

        while (fgs[i] == 2)
        {
            fgs[i] = 0;
            fgs[i + 1] += 1;
            i ++;
        }

        if (fgs[triangleRowSize - 1])
            break;

        int pre = 0;
        int cur = 0;

        printf("%d %d %d %d.\n", i, all, triangle[triangleRowSize - 1 - i][ns[i]], triangle[triangleRowSize - 1 - i][ns[i] + 1]);

        all -= triangle[triangleRowSize - 1 - i][ns[i]] - triangle[triangleRowSize - 1 - i][ns[i] + 1];

        ns[i] ++;

        if (min > all)
            min = all;
    }
    return min;
}
*/
