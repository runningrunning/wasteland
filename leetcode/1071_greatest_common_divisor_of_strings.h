int gcd(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    return gcd(b, a % b);

}
char * gcdOfStrings(char * str1, char * str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int lc = l1 > l2 ? gcd(l1, l2) : gcd(l2, l1);
    char* r = malloc(sizeof(char) * (lc + 1));
    r[0] = r[lc] = 0;

    int i = 0;
    for (; i < l1; i += lc)
        for (int j = 0; j < lc; j ++)
            if (str1[i + j] != str1[j])
                return r;
    i = 0;
    for (; i < l2; i += lc)
        for (int j = 0; j < lc; j ++)
            if (str2[i + j] != str1[j])
                return r;

    for (int i = 0; i < lc; i ++)
        r[i] = str1[i];
    return r;
}

