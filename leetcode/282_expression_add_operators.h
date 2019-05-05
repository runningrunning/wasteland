// DFS ? could overflow ?
void ao(char* n, int s, int e, int* vs, int* os, int si, int t, long v, int* ri, char*** r, long m, bool multi)
{
    if (!n[s] && (v == t || (multi && (v + m == t))))
    {
        int _ri = *ri;
        (*r) = realloc(*r, sizeof(char*) * (_ri + 1));
        char* t = malloc((e + 1) * 2);
        int i = 0;
        for (int j = 0; j < si; j ++)
            if (j != si - 1)
                i += sprintf(t + i, "%d%c", vs[j], os[j]);
            else
                i += sprintf(t + i, "%d", vs[j]);
        t[i] = 0;
        (*r)[_ri] = t;
        (*ri) ++;
        return;
    }

    long tmp = 0;
    if (n[s] == '0')
    {
        vs[si] = tmp;
        os[si] = '+';
        long nv = v;
        if (multi)
        {
            nv += m * tmp;
        }
        else
        {
            if (si == 0 || os[si - 1] == '+')
                nv += tmp;
            else
                nv -= tmp;
        }
        ao(n, s + 1, e, vs, os, si + 1, t, nv, ri, r, 0, false);

        if (!n[s + 1])
            return;

        os[si] = '-';
        ao(n, s + 1, e, vs, os, si + 1, t, nv, ri, r, 0, false);

        os[si] = '*';

        if (multi)
            ao(n, s + 1, e, vs, os, si + 1, t, v, ri, r, 0, true);
        else
            ao(n, s + 1, e, vs, os, si + 1, t, v, ri, r, 0, true);
    }
    else
    {
        int i = 0;
        while (tmp < INT_MAX && (s + i <= e))
        {
            tmp = tmp * 10 + n[s + i ++] - '0';
            if (tmp > INT_MAX)
                break;

            vs[si] = tmp;
            os[si] = '+';
            long nv = v;
            if (multi)
            {
                nv += m * tmp;
            }
            else
            {
                if (si == 0 || os[si - 1] == '+')
                    nv += tmp;
                else
                    nv -= tmp;
            }
            ao(n, s + i, e, vs, os, si + 1, t, nv, ri, r, 0, false);

            if (!n[s + i])
                return;

            os[si] = '-';
            ao(n, s + i, e, vs, os, si + 1, t, nv, ri, r, 0, false);


            os[si] = '*';

            if (multi)
            {
                ao(n, s + i, e, vs, os, si + 1, t, v, ri, r, m * tmp, true);
            }
            else
            {
                if (si == 0 || os[si - 1] == '+')
                    m = tmp;
                else
                    m = -tmp;
                ao(n, s + i, e, vs, os, si + 1, t, v, ri, r, m, true);
            }
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** addOperators(char* num, int target, int* returnSize)
{
    int l = strlen(num);
    if (!l)
    {
        *returnSize = 0;
        return NULL;
    }
    int* os = malloc(sizeof(int) * l);
    int* vs = malloc(sizeof(int) * l);
    int ri = 0;
    char** r = NULL;
    ao(num, 0, l - 1, vs, os, 0, target, 0, &ri, &r, 0, false);
    *returnSize = ri;
    return r;
}
