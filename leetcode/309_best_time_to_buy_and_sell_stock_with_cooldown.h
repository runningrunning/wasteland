/* DO more practice for DP DP TO KNOW DP RULES!!! */
// FUCKING SIMPLE SOLUTIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/* THINK TOO MUCH */
// OUT OF MIND !!!!!!!!!!!!!!!!!!!
// USE DP METHOD
// SHAME ON ME
// PEEK THE SOLUTION!!!
// brilliant !!!!
#define max(a, b) ((a) > (b) ? (a) : (b))


int maxProfit(int* prices, int pricesSize)
{
    int pb = - prices[0];
    int pc = 0;
    int ps = 0;

    for (int i = 1; i < pricesSize; i ++)
    {
        int cb = max(pb, pc - prices[i]);
        int cc = max(pc, ps);
        int cs = max(ps, pb + prices[i]);

        pb = cb;
        pc = cc;
        ps = cs;
    }

    if (pb >= pc)
        return max(pb, ps);
    return max(pc, ps);
}

/*
int maxProfit(int* prices, int pricesSize)
{
    int pc = 0;
    int ps = 0;
    for (int i = 1; i < pricesSize; i ++)
    {
        int tc = max(ps, pc);
        int ts = max(pc, ps + prices[i] - prices[i - 1]);
        pc = tc;
        ps = ts;
    }
    return pc > ps ? pc : ps;
}
*/






/* DO more practice for DP DP TO KNOW DP RULES!!! */
// FUCKING SIMPLE SOLUTIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/* THINK TOO MUCH */
// OUT OF MIND !!!!!!!!!!!!!!!!!!!
// USE DP METHOD
// SHAME ON ME
// PEEK THE SOLUTION!!!
/* int _max(int a, int b) */
/* { */
/*     return a > b ? a : b; */
/* } */

/* int maxProfit(int* prices, int pricesSize) */
/* { */
/*     if (!prices || pricesSize < 2) */
/*         return 0; */

/*     int* p = prices; */
/*     int ps = pricesSize; */

/*     int* b = malloc(sizeof(int) * ps); */
/*     int* s = malloc(sizeof(int) * ps); */
/*     int* n = malloc(sizeof(int) * ps); */

/*     b[0] = - p[0]; s[0] = 0; n[0] = 0; */

/*     for (int i = 1; i < ps; i ++) */
/*     { */
/*         b[i] = _max(b[i - 1], n[i - 1] - p[i]); */
/*         s[i] = _max(b[i - 1] + p[i], s[i - 1]); */
/*         n[i] = _max(n[i - 1], s[i - 1]); */
/*     } */

/*     printf("n %d b %d s %d\n", n[ps -1], b[ps -1], s[ps -1]); */

/*     /\* int* t = malloc(sizeof(int) * ps); *\/ */
/*     /\* memset(t, 0, sizeof(int) * ps); *\/ */

/*     /\* t[0] = 0; *\/ */

/*     /\* int t = 0; *\/ */
/*     /\* int bs = 0; // last has deal *\/ */
/*     /\* int bn = 0; // last has not deal *\/ */

/*     /\* for (int i = 1; i < ps; i ++) *\/ */
/*     /\* { *\/ */
/*     /\*     t = bs; *\/ */
/*     /\*     /\\* if (p[i] - p[i - 1] >= 0) *\\/ *\/ */
/*     /\*     /\\*     bs = bs + p[i] - p[i - 1]; *\\/ *\/ */
/*     /\*     /\\* bs = bs > bn ? bs : bn; *\\/ *\/ */
/*     /\*     bs = (bs + p[i] - p[i - 1]) > bn ? bs + p[i] - p[i - 1] : bn; *\/ */
/*     /\*     bn = t > bn ? t : bn; *\/ */
/*     /\*     printf("bn %d. bs %d.\n", bn, bs); *\/ */
/*     /\* } *\/ */
/*     /\* // printf("bn %d. bs %d.\n", bn, bs); *\/ */
/* } */

/*
// stupid wrong algorithm
int maxProfit(int* prices, int pricesSize)
{
    if (!prices || pricesSize < 2)
        return 0;

    int* p = prices;
    int ps = pricesSize;

    int* t = malloc(sizeof(int) * ps);
    memset(t, 0, sizeof(int) * ps);

    t[0] = 0;

    int pre_buy = -1;
    int pre_sell = -1;

    int last_buy = -1;
    int last_sell = -1;

    if (p[1] > p[0])
    {
        last_buy = 0;
        last_sell = 1;
        t[1] = p[1] - p[0];
    }

    int pre = p[1];

    for (int i = 2; i < ps; i ++)
    {
        if (pre > p[i])
            t[i] = t[i - 1];
        else
        {
            if (last_sell == i - 1)
            {
                last_sell = i;
                t[i] = t[i - 1] + (p[i] - pre);
            }
            else
            {
                if (last_sell >= 0 && last_sell == i - 2)
                {
                    int tmp = 0;
                    if (last_buy == last_sell - 1)
                    {
                        if (pre_sell >= 0 && pre_sell == last_buy - 2 && p[pre_sell + 1] >= p[pre_sell])
                            tmp = p[pre_sell + 1] - p[pre_sell];
                    }

                    if (p[i - 2] - p[i - 3] < p[i] - p[i - 1] + tmp)
                    {
                        pre_buy = last_buy;
                        pre_sell = last_sell - 1;
                        last_buy = i - 1;
                        last_sell = i;

                        t[i] = t[i - 1] + p[last_sell] - p[last_buy] + tmp;
                        t[i] -= p[i - 2] - p[i - 3];
                    }
                    else
                        t[i] = t[i - 1];
                }
                else
                {
                    pre_buy = last_buy;
                    pre_sell = last_sell;
                    last_buy = i - 1;
                    last_sell = i;
                    t[i] = t[i - 1] + p[last_sell] - p[last_buy];
                }
            }
        }
        pre = p[i];
    }
    return t[ps - 1];
}

// DP stupid wrong algorithm ??
int mp(int* p, int s, int e, int a, int* tmp)
{
    if (s == e)
        return 0;

    if (s + 1 == e)
    {
        int r = p[e] - p[s];
        return r > 0 ? r : 0;
    }

    if (tmp[s * a + e] >= 0)
        return tmp[s * a + e];

    int max = INT_MIN;
    int buy = p[s];

    bool skip = true;

    for (int i = s + 1; i <= e; i ++)
    {
        if (p[i] <= p[i - 1])
            skip = false;
        if (p[i] <= buy)
            buy = p[i];
        else if (max < p[i] - buy)
            max = p[i] - buy;
    }

    if (skip)
    {
        tmp[s * a + e] = max;
        return max;
    }

    int t = mp(p, s + 1, e, a, tmp);
    if (max < t)
        max = t;

    t = mp(p, s, e - 1, a, tmp);
    if (max < t)
        max = t;

    for (int i = s + 1; i <= e - 1; i ++)
    {
        int l = mp(p, s, i - 1, a, tmp);
        int r = mp(p, i + 1, e, a, tmp);
        if (max < l + r)
            max = l + r;
    }

    tmp[s * a + e] = max;
    return max;
}

int maxProfit_1(int* prices, int pricesSize)
{
    if (!prices || pricesSize < 2)
        return 0;

    if(pricesSize == 2)
        return (prices[1] - prices[0]) > 0 ? (prices[1] - prices[0]) : 0;

    int* temp = malloc(sizeof(int) * pricesSize * pricesSize);
    for (int i = 0; i < pricesSize * pricesSize; i ++)
        temp[i] = - 1;

    int c = 0;
    int i = 1;
    for (; i < pricesSize; i++)
    {
        if (prices[i] <= prices[i - 1])
        {
            // c - i - 1
            if (i - 1 - c)
            {
                for (int j = c; j <= i - 1; j ++)
                    for (int x = j; x <= i - 1; x ++)
                        temp[j * pricesSize + x] = prices[x] - prices[j];
            }
            c = i;
        }
    }

    i --;

    if (i - 1 - c)
    {
        for (int j = c; j <= i - 1; j ++)
            for (int x = j; x <= i - 1; x ++)
                temp[j * pricesSize + x] = prices[x] - prices[j];
    }


    c = 0;
    i = 1;
    for (; i < pricesSize; i++)
    {
        if (prices[i] >= prices[i - 1])
        {
            // c - i - 1
            if (i - 1 - c)
            {
                for (int j = c; j <= i - 1; j ++)
                    for (int x = j; x <= i - 1; x ++)
                        temp[j * pricesSize + x] = 0;
            }
            c = i;
        }
    }

    i --;

    if (i - 1 - c)
    {
        for (int j = c; j <= i - 1; j ++)
            for (int x = j; x <= i - 1; x ++)
                temp[j * pricesSize + x] = 0;
    }

    int max = INT_MIN;
    return mp(prices, 0, pricesSize - 1, pricesSize, temp);
}

// wrong algorithm
// DP
/*
int mp(int* price, int pricesSize, int* l, int* r, int* m, int s, int e)
{
    int pre = 0;
    if (c - 1 >= 0)
    {
        pre = l[c - 1];
        if (pre == -1)
            mp(price, pricesSize, l, r, m, c);
    }
}

int maxProfit(int* prices, int pricesSize)
{
    int* left = malloc(sizeof(int) * pricesSize);
    int* right = malloc(sizeof(int) * pricesSize);
    for (int i = 0; i < pricesSize; i ++)
        left[i] = right[i] = -1;
    int max = INT_MIN;

    mp(prices, pricesSize, left, right, &max, -1);
    return max;
}
*/


