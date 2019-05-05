int nthUglyNumber(int n)
{
    int pre[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
    if (n <= 10)
        return pre[n - 1];

    int next = 10;
    int* c = malloc(sizeof(int) * n);
    memcpy(c, pre, sizeof(int) * 10);

    int p;
    int p2 = 6;
    int p3 = 4;
    int p5 = 2;

    int v2, v3, v5;

    while(next < n)
    {
        v2 = c[p2] * 2;
        v3 = c[p3] * 3;
        v5 = c[p5] * 5;

        if (v2 <= v3 && v2 <= v5)
        {
            c[next ++] = v2;
            p2 ++;
            if (v2 == v3)
                p3 ++;
            if (v2 == v5)
                p5 ++;
        }
        else if (v3 < v2 && v3 <= v5)
        {
            c[next ++] = v3;
            p3 ++;
            if (v3 == v5)
                p5 ++;
        }
        else
        {
            c[next ++] = v5;
            p5 ++;
        }
    }
    return c[next - 1];
}
