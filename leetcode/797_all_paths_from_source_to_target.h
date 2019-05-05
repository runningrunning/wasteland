/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// try do not user recursive
// try to practice a lot
// just write code !
void apst(int** g, int r, int* c, int* ri, int** cs, int *** rs, int* s, int sf, int l, int i)
{
    if (i == r - 1)
    {
        int _ri = *ri;
        if (!_ri)
        {
            *cs = malloc(sizeof(int));
            *rs = malloc(sizeof(int*));
        }
        else
        {
            *cs = realloc(*cs, sizeof(int) * (_ri + 1));
            *rs = realloc(*rs, sizeof(int*) * (_ri + 1));
        }
        (*cs)[_ri] = l + 1;
        int* t = malloc(sizeof(int) * (l + 1));
        memcpy(t + 1, s, sizeof(int) * l);
        t[0] = 0;
        (*rs)[_ri] = t;
        (*ri) ++;
    }
    else
    {
        for (int x = 0; x < c[i]; x ++)
        {
            int y = g[i][x];
            if (sf & (1 << y))
                continue;
            s[l] = y;
            apst(g, r, c, ri, cs, rs, s, sf | (1 << y), l + 1, y);
        }
    }
}

int** allPathsSourceTarget(int** g, int r, int *c, int** cs, int* ri)
{
    *ri = 0;
    int** rs = NULL;
    int sf = 1;
    int si = 0;
    int s[16] = {0};

    /* apst(g, r, c, ri, cs, &rs, s, sf, si, 0); */
    /* return rs; */

    sf = 1;
    si = 1;
    int i = 0;
    int is[16] = {0};

    while (true)
    {
        if (i == r - 1)
        {
            int _ri = *ri;
            if (!_ri)
            {
                *cs = malloc(sizeof(int));
                rs = malloc(sizeof(int*));
            }
            else
            {
                *cs = realloc(*cs, sizeof(int) * (_ri + 1));
                rs = realloc(rs, sizeof(int*) * (_ri + 1));
            }
            (*cs)[_ri] = si;
            int* t = malloc(sizeof(int) * si);
            memcpy(t, s, sizeof(int) * si);
            rs[_ri] = t;
            (*ri) ++;

            si --;
            i = s[si - 1];
            sf &= ~(1 << (r - 1));
            sf |= 1;
        }
        else
        {
            if (is[i])
            {
                sf &= ~(1 << g[i][is[i] - 1]);
                sf |= 1;
            }

            if (is[i] == c[i])
            {
                if (i == 0)
                    break;
                is[i] = 0;
                si --;
                i = s[si - 1];
            }
            else
            {
                int y = g[i][is[i]];
                if ((sf & (1 << y)))
                {
                    is[i] ++;
                    continue;
                }

                s[si ++] = y;
                sf |= (1 << y);
                is[i] ++;
                i = y;
            }
        }
    }

    return rs;
}
