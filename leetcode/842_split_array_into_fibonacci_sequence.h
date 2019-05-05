/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool _csif(char* s, int o, int l, char* t, int r)
{
    if (o == l)
        return true;

    if (o + r > l)
        return false;

    for (int i = 0; i < r; i ++)
        if (s[o + i] != t[i])
            return false;
    return true;
}
int _sif(char* s, int l, int o, int si, int* st)
{
    long x = 0;
    long y = 0;
    long z = 0;
    char t[24] = {0};

    int imax = s[0] == '0' ? 1 : l - 2;

    for (int i = 0; i < imax; i ++)
    {
        x = x * 10 + s[i] - '0';
        if (x > INT_MAX)
            break;

        if (i && s[0] == '0')
            return 0;

        st[0] = x;

        y = 0;

        int jmax = s[i + 1] == '0' ? i + 2 : l - 1;

        for (int j = i + 1; j < jmax; j ++)
        {
            si = 1;
            y = y * 10 + s[j] - '0';
            if (x + y > INT_MAX)
                break;

            st[si ++] = y;

            z = x + y;
            o = j + 1;

            int r = sprintf(t, "%d", z);

            t[r] = 0;

            int nx = x;
            int ny = y;
            int nz = z;

            while (o < l && _csif(s, o, l, t, r))
            {
                nx = ny;
                ny = nz;
                nz = nx + ny;

                if (nz > INT_MAX)
                    break;

                st[si ++] = ny;
                o += r;
                r = sprintf(t, "%d", nz);
            }
            if (o == l)
                return si;
        }
    }
    return 0;
}

int* splitIntoFibonacci(char* S, int* returnSize)
{
    int si = 0;
    int* st = malloc(sizeof(int) * 256);

    int l = strlen(S);
    if (l < 3)
    {
        *returnSize = 0;
        return NULL;
    }

    si = _sif(S, l, 0, si, st);
    *returnSize = si;
    return si ? st : NULL;
}
