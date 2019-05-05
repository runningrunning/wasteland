char* intToRoman(int num)
{
    /* /\* 1, 5, 10, 50, 100, 500, 1000 *\/ */
    /* char* so = {"I", "V", "X", "L", "C", "D", "M"}; */

    int ns[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2, 1};
    char* so1[]    = {NULL, "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    char* so10[]   = {NULL, "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
    char* so100[]  = {NULL, "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
    char* so1000[] = {NULL, "M", "MM", "MMM"};

    char* r = malloc(20);
    r[19] = 0;

    int o = 0;
    int i = 0;

    o = num / 1000;
    if (o)
    {
        strncpy(r, so1000[o], ns[o]);
        i += ns[o];
        num %= 1000;
    }

    o = num / 100;
    if (o)
    {
        strncpy(r + i, so100[o], ns[o]);
        i += ns[o];
        num %= 100;
    }

    o = num / 10;
    if (o)
    {
        strncpy(r + i, so10[o], ns[o]);
        i += ns[o];
        num %= 10;
    }

    if (num)
    {
        strncpy(r + i, so1[num], ns[num]);
        i += ns[num];
    }
    r[i] = 0;

    return r;
}
