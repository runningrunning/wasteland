// math, same as 688 knight probability in chassboard, jus calculate it.
double champagneTower(int poured, int r, int g)
{
    double p1[101];
    double p2[101];
    p1[0] = poured;

    double* pk = p1;
    double* pp = p2;

    double t = 0.0;

    for (int i = 0; i < r; i ++)
    {
        pp[0] = 0.0;
        for (int j = 0; j <= i / 2; j ++)
        {
            double l = 0.0;
            if (pk[j] > 1.0)
                l = (pk[j] - 1.0) / 2.0;

            pp[j] += l;
            pp[j + 1] = l;
            // skip half of it.
            pp[i + 1 - j] = pp[j];
        }

        if (i & 1)
            pp[(i  + 1) / 2] *= 2.0;

        double* pt = pk;
        pk = pp;
        pp = pt;
    }

    t = r & 1 ? p2[g] : p1[g];
    return t > 1.0 ? 1.0 : t;
}
