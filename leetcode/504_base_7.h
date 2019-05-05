char* convertToBase7(int num)
{
    if (!num)
    {
        char* r = malloc(2);
        r[0] = '0';
        r[1] = 0;
        return r;
    }

    char a[256] = {0};

    int j = 0;
    if (num < 0)
    {
        j = 1;
        num = - num;
    }
    int i = 0;

    while(num)
    {
        a[i++] = num % 7;
        num /= 7;
    }

    char* r = malloc(i + 1 + j);
    r[i + j] = 0;

    if (j)
        r[0] = '-';

    for (int x = 0; x < i; x ++)
        r[j + x] = a[i - 1 - x] + '0';

    return r;
}
