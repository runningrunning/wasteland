// find the proper memory internal calculation status !!!!!
// TODO REWORK AGAIN
bool is_il(char* s1, int i1, char* s2, int i2, char* s3, int i3, char* f, int l2)
{
    int c1 = s1[i1];
    int c2 = s2[i2];
    int c3 = s3[i3];

    if (!c1 && !c2 && !c3)
        return true;

    if (!c1)
        return !strcmp(s2 + i2, s3 + i3);

    if (!c2)
        return !strcmp(s1 + i1, s3 + i3);

    int t1 = i1 * l2 + i2;
    if (f[t1])
        return false;

    if (c3 != c1 && c3 != c2)
    {
        f[t1] = true;
        return false;
    }

    if (c3 == c1)
        if (is_il(s1, i1 + 1, s2, i2, s3, i3 + 1, f, l2))
            return true;

    if (c3 == c2)
        if (is_il(s1, i1, s2, i2 + 1, s3, i3 + 1, f, l2))
            return true;

    f[t1] = true;
    return false;
}

bool isInterleave(char* s1, char* s2, char* s3)
{
    if (!s1 || !s1[0])
    {
        if (s2 == NULL || s3 == NULL)
            return s2 == s3;
        return !strcmp(s2, s3);
    }

    if (!s2 || !s2[0])
    {
        if (s1 == NULL || s3 == NULL)
            return s1 == s3;
        return !strcmp(s1, s3);
    }

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l3 = strlen(s3);

    if (l1 + l2 != l3)
        return false;

    char* f = malloc(l1 * l2);
    bzero(f, l1 * l2);
    return is_il(s1, 0, s2, 0, s3, 0, f, l2);
}
