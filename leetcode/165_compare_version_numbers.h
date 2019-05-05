int v_comp(char* v1, char* v2)
{
    if (!v1[0] && !v2[0])
        return 0;

    if (!v1[0] || !v2[0])
    {
        int i = 0;
        int ret = v1[0] ? 1 : -1;
        char* v = v1[0] ? v1 : v2;

        while(v[i])
        {
            if (v[i] == '.')
            {
                i ++;
                break;
            }

            if (v[i] != '0')
                return ret;
            i ++;
        }

        return v == v1 ? v_comp(v1 + i, v2)
            : v_comp(v1, v2 + i);
    }

    int i = 0;
    int j = 0;

    while(v1[i] == '0')
        i ++;
    while(v2[j] == '0')
        j ++;

    if (!v1[i] && !v2[j])
        return 0;

    if (!v1[i])
    {
        if (v2[j] != '.')
            return -1;
        return v_comp(v1 + i, v2 + j + 1);
    }

    if (!v2[j])
    {
        if (v1[i] != '.')
            return 1;
        return v_comp(v1 + i + 1, v2 + j);
    }

    v1 += i;
    v2 += j;

    int i2 = 0;
    int j2 = 0;

    while(v1[i2] && v1[i2] != '.')
        i2 ++;
    while(v2[j2] && v2[j2] != '.')
        j2 ++;

    if (i2 != j2)
        return i2 > j2  ? 1 : -1;

    for(i = 0; i < i2; i ++)
    {
        if (v1[i] != v2[i])
            return v1[i] > v2[i] ? 1 : -1;
    }

    return v_comp(v1[i2] ? v1 + i2 + 1 : v1 + i2,
                  v2[j2] ? v2 + j2 + 1 : v2 + j2);
}

int compareVersion(char* version1, char* version2)
{
    return v_comp(version1, version2);
}
