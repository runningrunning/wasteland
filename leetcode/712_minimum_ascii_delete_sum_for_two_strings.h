int mmds(char* s1, char* s2, int i1, int i2, int l1, int l2, int* t)
{
    if (i1 == l1 || i2 == l2)
        return 0;

    int z = i1 * l2 + i2;
    if (t[z])
        return t[z] - 1;

    if (s1[i1] == s2[i2])
        t[z] = mmds(s1, s2, i1 + 1, i2 + 1, l1, l2, t) + (1 << 16) + s1[i1] - 97 + 1;
    else
    {
        int x1 = mmds(s1, s2, i1 + 1, i2, l1, l2, t);
        int x2 = mmds(s1, s2, i1, i2 + 1, l1, l2, t);

        if (x1 >= x2)
            t[z] = x1 + 1;
        else
            t[z] = x2 + 1;
    }
    return t[z] - 1;
}

int minimumDeleteSum(char* s1, char* s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    int z = 0;
    for (int i = 0; i < l1; i ++)
        z += s1[i];
    for (int i = 0; i < l2; i ++)
        z += s2[i];

    if (l1 == 0 || l2 == 0)
        return z;

    int* t = calloc(sizeof(int), l1 * l2);
    int x = mmds(s1, s2, 0, 0, l1, l2, t);
    return z - ((x >> 16) * 97 + (x & 0xFFFF)) * 2;
}
