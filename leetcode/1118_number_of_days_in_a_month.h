int leap(int Y)
{
    if (Y % 4)
        return 0;
    if (Y % 100)
        return 1;
    return (Y % 400) ? 0 : 1;
}

int numberOfDays(int Y, int M)
{
    // leap year
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return m[M] + (M == 2 ? leap(Y) : 0);
}

