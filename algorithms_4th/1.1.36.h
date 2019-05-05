/* the sum of elements in percent should be 100 */
/* the percentage of value i is in percent */
int discrete(int* percent, int size)
{
    int r = rand( ) % 100;
    r ++;

    int sum = 0;
    for (int i = 0; i < size; i ++)
    {
        sum += percent[i];
        if (sum >= r)
            return i;
    }
    return -1;
}

void shuffle(int* a, int size)
{
    for (int i = 0; i < size; i ++)
    {
        int r = rand() % (size - i);
        if (r)
        {
            int temp = a[i];
            a[i] = a[i + r];
            a[i + r] = temp;
        }
    }
}

void shuffle_1(int* a, int size)
{
    for (int i = 0; i < size; i ++)
    {
        int r = rand() % size;
        if (r != i)
        {
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
}

void test()
{
    int x = 20000000;
    int m = 30;
    int n = 1;

    int** r = malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i ++)
    {
        r[i] = malloc(sizeof(int) * m);
        memset(r[i], 0, sizeof(int) * m);
    }

    int* t = malloc(sizeof(int) * m);

    int* p = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i ++)
        p[i] = i;

    for (int i = 0; i < x; i ++)
    {
        memcpy(t, p, sizeof(int) * m);

        for (int j = 0; j < n; j ++)
        {
            // shuffle(t, m);
            shuffle_1(t, m);
        }

        for (int j = 0; j < m; j ++)
            r[j][t[j]] ++;
    }

    for (int j = 0; j < m; j ++)
        out(r[j], m);

}
