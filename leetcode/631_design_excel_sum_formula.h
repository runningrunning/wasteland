// simple is easy ?
// just recalculate the whole rectange again ?
#define NUM 26
typedef struct {
    int tx;
    int ty;
    int bx;
    int by;
} ER;

typedef struct {
    int x;
    int y;
    int s;
    ER** es;
} SUM;

typedef struct {
    int x;
    int y;

    int* e; // excel
    int* f; // whether it's still sum
    int s;
    SUM** sum;

    // base on row
    int* rs[NUM];
    // base on column
    int* cs[NUM];
} Excel;

Excel* excelCreate(int H, char W) {
    Excel* e = malloc(sizeof(Excel));
    e->x = H;
    e->y = W - 'A' + 1;
    e->e = calloc(sizeof(int), NUM * NUM);
    e->f = calloc(sizeof(int), NUM * NUM);
    e->s = 0;
    e->sum = NULL;
    memset(e->rs, 0, sizeof(int*) * NUM);
    memset(e->cs, 0, sizeof(int*) * NUM);
    return e;
}

/* void _out(Excel* obj) */
/* { */
/*     for (int i = 0; i < obj->x; i ++) */
/*         out(obj->e + i * NUM, obj->y); */
/* } */

int _rect(Excel* obj, int tx, int ty, int bx, int by)
{
    int n = 0;
    for (int i = tx; i <= bx; i ++)
        for (int j = ty; j <= by; j ++)
            n += obj->e[i * NUM + j];
    return n;
}

void _update(Excel* obj, int r, int c, int d)
{
    int* rs = obj->rs[r];
    int* cs = obj->cs[c];

    if (!rs || !cs)
        return;

    int rl = rs[0];
    int cl = cs[0];

    int ti = 0;
    int* t = malloc(sizeof(int) * (rl < cl ? rl : cl));
    int i = 1;
    int j = 1;

    while (i < rl && j < cl)
    {
        if (rs[i] < cs[j])
            i ++;
        else if (cs[j] < rs[i])
            j ++;
        else
        {
            SUM* s = obj->sum[rs[i]];
            // take care of reset sum
            if (obj->f[s->x * NUM + s->y] == rs[i] + 1)
                t[ti ++] = rs[i];
            i ++;
            j ++;
        }
    }

    int* ds = malloc(sizeof(int) * ti);
    for (i = 0; i < ti; i ++)
    {
        SUM* s = obj->sum[t[i]];
        int diff = 0;
        for (int j = 0; j < s->s; j ++)
        {
            ER* e = s->es[j];
            if (r >= e->tx && r <= e->bx
                && c >= e->ty && c <= e->by)
                diff += d;
        }
        // only save diff as the v from that point could change in the next for loop
        ds[i] = diff;
    }

    for (int i = 0; i < ti; i ++)
    {
        SUM* s = obj->sum[t[i]];
        // use the current value and diff
        int v = obj->e[s->x * NUM + s->y];
        if (ds[i])
        {
            obj->e[s->x * NUM + s->y] = v + ds[i];
            _update(obj, s->x, s->y, ds[i]);
        }
    }

    free(t);
    free(ds);
}

void _add(Excel* obj, int id, int r, int c)
{
    if (r != -1)
    {
        if (!obj->rs[r])
        {
            obj->rs[r] = malloc(sizeof(int) * 2);
            obj->rs[r][0] = 2;
            obj->rs[r][1] = id;
        }
        else
        {
            // need to take care of dup !!
            int l = obj->rs[r][0];
            bool found = false;
            for (int i = 1; i < l; i ++)
                if (obj->rs[r][i] == id)
                {
                    found = true;
                    break;
                }

            if (!found)
            {
                obj->rs[r] = realloc(obj->rs[r], sizeof(int) * (l + 1));
                obj->rs[r][0] = l + 1;
                obj->rs[r][l] = id;
            }
        }
    }

    if (c != -1)
    {
        if (!obj->cs[c])
        {
            obj->cs[c] = malloc(sizeof(int) * 2);
            obj->cs[c][0] = 2;
            obj->cs[c][1] = id;
        }
        else
        {
            // need to take care of dup !!
            int l = obj->cs[c][0];
            bool found = false;
            for (int i = 1; i < l; i ++)
                if (obj->cs[c][i] == id)
                {
                    found = true;
                    break;
                }

            if (!found)
            {
                obj->cs[c] = realloc(obj->cs[c], sizeof(int) * (l + 1));
                obj->cs[c][0] = l + 1;
                obj->cs[c][l] = id;
            }
        }
    }
}


int excelGet(Excel* obj, int r, char c)
{
    r -= 1;
    c -= 'A';
    if (obj && r < obj->x && c < obj->y)
        return obj->e[r * NUM + c];
    return 0;
}

void excelSet(Excel* obj, int r, char c, int v)
{
    r -= 1;
    c -= 'A';
    if (obj && r < obj->x && c < obj->y && r >= 0 && c >= 0)
    {
        obj->f[r * NUM + c] = 0;
        int o = obj->e[r * NUM + c];
        if (v == o)
            return;
        obj->e[r * NUM + c] = v;
        _update(obj, r, c, v - o);
    }
}

int excelSum(Excel* obj, int r, char c, char** strs, int strsSize)
{
    r -= 1;
    c -= 'A';
    int n = 0;
    if (obj)
    {
        int id = obj->s;
        // how about remove the old sum, it's done by checking sum id
        SUM* sum = malloc(sizeof(SUM));
        sum->x = r;
        sum->y = c;
        obj->f[r * NUM + c] = obj->s + 1;
        sum->s = strsSize;
        sum->es = malloc(sizeof(ER*) * strsSize);
        for (int i = 0; i < strsSize; i ++)
        {
            char* s = strs[i];
            ER* er = malloc(sizeof(ER));
            int y = s[0] - 'A';
            int x = 0;
            int j = 1;

            while (s[j] && s[j] != ':')
            {
                x = x * 10 + s[j] - '0';
                j ++;
            }

            if (!s[j])
            {
                er->tx = er->bx = x - 1;
                er->ty = er->by = y;
                n += obj->e[er->tx * NUM + er->ty];
                _add(obj, id, er->tx, er->ty);
            }
            else
            {
                j ++;
                er->tx = x - 1;
                er->ty = y;
                x = 0;
                y = s[j ++] - 'A';
                while (s[j])
                {
                    x = x * 10 + s[j] - '0';
                    j ++;
                }
                er->bx = x - 1;
                er->by = y;
                n += _rect(obj, er->tx, er->ty, er->bx, er->by);

                for (int j = er->tx; j <= er->bx; j ++)
                    _add(obj, id, j, -1);

                for (int j = er->ty; j <= er->by; j ++)
                    _add(obj, id, -1, j);
            }
            sum->es[i] = er;
        }
        obj->sum = realloc(obj->sum, sizeof(SUM*) * (obj->s + 1));
        obj->sum[obj->s] = sum;
        obj->s += 1;

        int o = obj->e[r * NUM + c];
        if (n == o)
            return n;

        obj->e[r * NUM + c] = n;
        _update(obj, r, c, n - o);

    }
    return n;
}

void excelFree(Excel* obj) {
    if (obj)
    {
        free(obj->e);
        free(obj->f);
        for (int i = 0; i < obj->s; i ++)
        {
            free(obj->sum[i]->es);
            free(obj->sum[i]);
        }
        free(obj->sum);
        for (int i = 0; i < NUM; i ++)
        {
            if (obj->rs[i])
                free(obj->rs[i]);
            if (obj->cs[i])
                free(obj->cs[i]);
        }
        free(obj);
    }
}



/**
 * Your Excel struct will be instantiated and called as such:
 * struct Excel* obj = excelCreate(H, W);
 * excelSet(obj, r, c, v);
 * int param_2 = excelGet(obj, r, c);
 * int param_3 = excelSum(obj, r, c, strs, strsSize);
 * excelFree(obj);
 */
