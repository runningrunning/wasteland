void test()
{
    int SIDES = 6;
    double* dist = malloc(sizeof(double) * (2 * SIDES + 1));
    for (int i = 1; i <= SIDES; i ++)
        for (int j = 1; j <= SIDES; j ++)
            dist[i + j] += 1.0;

    for (int k = 2; k <= 2 * SIDES; k ++)
    {
        dist[k] /= 36.0;
        printf("Sum is %d, percent is %f.\n", k, dist[k]);
    }

}
