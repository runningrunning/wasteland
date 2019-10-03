int extra(int y)
{
    return (y % 4) ? 0 : ((y % 100) ? 1 : ((y % 400) ? 0 : 1));
}

int dayOfYear(char * date)
{
    int ms[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int y = (date[0] - '0') * 1000;
    y += (date[1] - '0') * 100;
    y += (date[2] - '0') * 10;
    y += (date[3] - '0');

    int m = (date[5] - '0') * 10;
    m += (date[6] - '0');

    int d = (date[8] - '0') * 10;
    d += (date[9] - '0');

    int n = m > 2 ? extra(y) : 0;

    for (int i = 0; i < m - 1; i ++)
        n += ms[i];

    return n + d;
}

