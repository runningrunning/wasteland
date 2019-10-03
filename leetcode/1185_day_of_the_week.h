int extra(int y)
{
    return (y % 4) ? 0 : ((y % 100) ? 1 :  ((y % 400) ? 0 : 1));
}

char* dayOfTheWeek(int day, int month, int year)
{
    int e = 0;
    int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int n = 0;
    for (int i = 1971; i < year; i ++)
        n += extra(i) + 365;

    if (month > 2)
        n += extra(year);

    for (int i = 0; i < month - 1; i ++)
        n += m[i];

    n += day - 1 + 5;

    char* d[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return d[n % 7];
}
