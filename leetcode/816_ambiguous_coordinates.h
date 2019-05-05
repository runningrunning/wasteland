/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool _can(char* d, int s, int e)
{
    if (s == e)
        return true;
    return d[s] != '0' || d[e] != '0';
}

void _double_num(char* d, int s, int e, char** t, int* n)
{
    *n = 1;
    if (s == e)
    {
        t[0][0] = d[s];
        t[0][1] = 0;
    }
    else if (d[s] == '0')
    {
        t[0][0]= '0';
        t[0][1] = '.';
        int in = 2;
        for (int i = s + 1; i <= e; i ++)
            t[0][in ++] = d[i];
        t[0][in ++] = 0;
    }
    else if (d[e] == '0')
    {
        strncpy(t[0], d + s, e - s + 1);
        t[0][e - s + 1] = 0;
    }
    else
    {
        for (int i = s; i <= e; i ++)
        {
            int in = 0;
            for (int j = s; j <= e; j ++)
            {
                t[i - s][in ++] = d[j];
                if (j == i && i != e)
                    t[i - s][in ++] = '.';
            }
            t[i - s][in] = 0;
        }
        *n = e - s + 1;
    }
}

char** ambiguousCoordinates(char* S, int* returnSize)
{
    int ri = 0;
    char** r = NULL;

    int l = strlen(S);

    char* t1[10];
    char* t2[10];

    char* tmp1 = malloc(160);
    char* tmp2 = malloc(160);

    for (int i = 0; i < 10; i ++)
    {
        t1[i] = tmp1 + i * 16;
        t2[i] = tmp2 + i * 16;
    }

    for (int i = 1; i < l - 2; i ++)
    {
        if (_can(S, 1, i) && _can(S, i + 1, l - 2))
        {
            int x = 0;
            _double_num(S, 1, i, t1, &x);
            int y = 0;
            _double_num(S, i + 1, l - 2, t2, &y);

            for (int m = 0; m < x; m ++)
                for (int n = 0; n < y; n ++)
                {
                    char* tmp = malloc(16);
                    sprintf(tmp, "(%s, %s)", t1[m], t2[n]);
                    ri ++;
                    r = realloc(r, sizeof(char*) * ri);
                    r[ri - 1] = tmp;
                }
        }
    }
    *returnSize = ri;
    return r;
}
