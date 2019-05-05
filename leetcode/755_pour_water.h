int* pourWater(int* heights, int heightsSize, int V, int K, int* returnSize)
{
    while (V)
    {
        int lbi = K;
        int rbi = K;
        int c = heights[K];

        for (int i = K - 1; i >= 0; i --)
            if (heights[i] <= heights[i + 1])
            {
                if (heights[i] < heights[i + 1])
                    lbi = i;
            }
            else
                break;

        for (int i = K + 1; i < heightsSize; i ++)
        {
            if (heights[i] <= heights[i - 1])
            {
                if (heights[i] < heights[i - 1])
                    rbi = i;
            }
            else
                break;
        }
        if (heights[lbi] < c)
            heights[lbi] ++;
        else
            heights[rbi] ++;

        V --;
    }
    *returnSize = heightsSize;
    return heights;
}

/* // stupid wrong algorithm !!!!! */
/* /\** */
/*  * Return an array of size *returnSize. */
/*  * Note: The returned array must be malloced, assume caller calls free(). */
/*  *\/ */
/* int* pourWater(int* heights, int heightsSize, int V, int K, int* returnSize) */
/* { */
/*     int s = K; */
/*     int e = K; */

/*     while (V) */
/*     { */
/*         int l = 0; */
/*         int c = heights[K]; */

/*         int os = s; */
/*         int oe = e; */
/*         while (s && heights[s - 1] <= c) */
/*         { */
/*             s --; */
/*             l += c - heights[s]; */
/*         } */

/*         int r = 0; */
/*         while (e != heightsSize -1 && heights[e + 1] <= c) */
/*         { */
/*             e ++; */
/*             r += c - heights[e]; */
/*         } */

/*         if (V == l + r) */
/*         { */
/*             V = 0; */
/*             for (int i = s; i <= e; i ++) */
/*                 heights[i] = c; */
/*         } */
/*         else if (V < l + r) */
/*         { */
/*             while (V) */
/*             { */
/*                 int lbi = K; */
/*                 int rbi = K; */

/*                 for (int i = os - 1; i >= 0; i --) */
/*                     if (heights[i] <= heights[i + 1]) */
/*                     { */
/*                         if (heights[i] < heights[i + 1]) */
/*                             lbi = i; */
/*                     } */
/*                     else */
/*                         break; */

/*                 for (int i = oe + 1; i < heightsSize; i ++) */
/*                 { */
/*                     if (heights[i] <= heights[i - 1]) */
/*                     { */
/*                         if (heights[i] < heights[i - 1]) */
/*                             rbi = i; */
/*                     } */
/*                     else */
/*                         break; */
/*                 } */

/*                 out(heights, heightsSize); */

/*                 if (heights[lbi] < c) */
/*                     heights[lbi] ++; */
/*                 else */
/*                     heights[rbi] ++; */

/*                 V --; */
/*             } */
/*         } */
/*         else */
/*         { */
/*             int lh = s ? heights[s - 1] : INT_MAX; */
/*             int rh = e != heightsSize - 1 ? heights[e + 1] : INT_MAX; */
/*             int xh = lh < rh ? lh : rh; */

/*             if (xh == INT_MAX || V <= l + r + (xh - c - 1) * (e - s + 1)) */
/*             { */
/*                 V -= l + r; */
/*                 int x = V / (e - s + 1); */
/*                 int y = V % (e - s + 1); */

/*                 for (int i = s; i <= e; i ++) */
/*                     heights[i] = c + x; */

/*                 int i = K; */

/*                 while (y && i >= s) */
/*                 { */
/*                     heights[i --] ++; */
/*                     y --; */
/*                 } */

/*                 i = K + 1; */
/*                 while (y && i <= e) */
/*                 { */
/*                     heights[i ++] ++; */
/*                     y --; */
/*                 } */

/*                 V = 0; */
/*             } */
/*             else */
/*             { */
/*                 V -= l + r + (xh - c - 1) * (e - s + 1); */
/*                 for (int i = s; i <= e; i ++) */
/*                     heights[i] = xh - 1; */

/*                 int i = K; */

/*                 printf("V is %d.\n", V); */

/*                 while (V && i >= s) */
/*                 { */
/*                     heights[i --] ++; */
/*                     V --; */
/*                 } */
/*                 e = K; */
/*             } */
/*         } */
/*     } */
/*     *returnSize = heightsSize; */
/*     return heights; */
/* } */
