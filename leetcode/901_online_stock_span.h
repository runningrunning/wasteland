// stack ?? it's consecutive !
// CONSECUTIVE !!!!!!!

typedef struct {
    int ss;
    int si;
    int* st;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* s = malloc(sizeof(StockSpanner));
    s->si = 0;
    s->ss = 1024;
    s->st = malloc(sizeof(int) * s->ss);
    s->st[0] = 0;
    return s;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    if (obj)
    {
        int* st = obj->st;
        int si = obj->si;

        int n = 1;

        while (si)
        {
            if (price >= (st[si] % 100001))
                n += st[si] / 100001;
            else
                break;
            si --;
        }

        // if (!si || (price < st[si] % 100001))
            si ++;

        if (si == obj->ss)
        {
            obj->ss += 1024;
            obj->st = realloc(obj->st, sizeof(int) * obj->ss);
            st = obj->st;
        }

        st[si] = n * 100001 + price;

        obj->si = si;

        return n;
    }

    return 0;
}

void stockSpannerFree(StockSpanner* obj) {
    if (obj)
    {
        free(obj->st);
        free(obj);
    }
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * struct StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
 */


/* // !!!! STUPID read the wrong question */
/* // insert sort ? */
/* // how to optimize this ? */
/* // binary search tree */
/* // how to optimize this */
/* // my own segment trees */
/* // no need segment tree */
/* // just use bits */

/* typedef struct { */
/*     int* x; */
/* } StockSpanner; */

/* StockSpanner* stockSpannerCreate() { */
/*     StockSpanner* s = malloc(sizeof(StockSpanner)); */
/*     s->x = calloc(sizeof(int), (1 << 17) - 1); */
/*     return s; */
/* } */

/* int stockSpannerNext(StockSpanner* obj, int price) { */
/*     if (obj) */
/*     { */
/*         int u = 0; */
/*         int num = 0; */
/*         int p = price; */
/*         for (int i = 16; i >= 0; i --) */
/*         { */
/*             int m = 1 << i; */
/*             if (p & m) */
/*             { */
/*                 u |= m; */
/*                 num += obj->x[u]; */
/*             } */
/*             else */
/*             { */
/*                 obj->x[p | m] ++; */
/*             } */
/*         } */
/*         return num + 1; */
/*     } */
/*     return 0; */
/* } */

/* void stockSpannerFree(StockSpanner* obj) { */
/*     if (obj) */
/*     { */
/*         free(obj->x); */
/*         free(obj); */
/*     } */
/* } */

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * struct StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 * stockSpannerFree(obj);
 */

/* test binary search tree here !
void test()
{
    int* x = calloc(sizeof(int), 256);

    int m[] = {255, 100, 80, 60, 70, 60, 75, 85, 255};
    int l = LEN_M(m);

    for (int i = 0; i < l; i ++)
    {
        int y = m[i];
        int mask = 0;

        int u = 0;
        int num = 0;

        for (int j = 7; j >= 0; j --)
        {
            int ma = 1 << j;
            mask |= ma;

            if (y & ma)
            {
                u |= ma;
                num += x[u];
            }
            else
            {
                x[u | ma] ++;
            }
        }
        printf("%d is %d.\n", u, num + 1);
    }
}
*/

