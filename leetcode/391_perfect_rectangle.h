// FAILED TOO MUCH, JUST WRITE THE CODE !!!!!!
// LOTS OF TYPO !!!!
// STUPID WRONG ALGORITHM !!
// just checking the points !
// TLE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// can just finish check points
// stupid me
// 2D tree or 2d segments ? (try this ways !!!!)
// peek hints !
// actually, it's hash problems, that's embarrassing :(

// just write the code ???
// how about performance ????
// not rectangle intersect with others ?
// stupid algorithm :(, stupid me
// or 2d segment tree ?

#define _DP(a, b) do {                              \
        a = a & 0xFFFFFFFF; b = b & 0xFFFFFFFF;     \
        x = a << 32 | b; k = x % dp;                \
        if (k < 0) k += dp;                         \
        while (hash[k] && store[hash[k] >> 1] != x) \
            k = (k + 1) % dp;                       \
        if (!hash[k]) {                             \
            hash[k] = si << 1;                      \
            store[si ++] = x;                       \
        }                                           \
        hash[k] ^= 1;                               \
        if (hash[k] & 1)                            \
        {   printf("n ++ for x %ld k %ld %ld %ld.\n", 0L, 0L, a, b);   \
            n ++;                                   }                \
        else                                        \
        {   printf("n -- for x %ld k %ld %ld %ld.\n", 0L, 0L, a, b);   \
            n --;                                   }   \
    } while (0)

#define _CK(a, b) do {                              \
        a = a & 0xFFFFFFFF; b = b & 0xFFFFFFFF;     \
        x = a << 32 | b; k = x % dp;                \
        if (k < 0) k += dp;                         \
        while (hash[k] && store[hash[k] >> 1] != x) \
            k = (k + 1) % dp;                       \
        if (!(hash[k] & 1)) return false;           \
    } while (0)

bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize)
{
    if (!rectangles || rectanglesRowSize < 2)
        return true;

    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 8 >= (rectanglesRowSize * 4))
            break;
    }

    int n = 0;
    long area = 0;
    int* hash = calloc(sizeof(int), dp);
    int si = 0;
    long* store = malloc(sizeof(long) * rectanglesRowSize * 4);

    long bx = INT_MAX;
    long by = INT_MAX;
    long tx = INT_MIN;
    long ty = INT_MIN;

    long x, k;

    for (int i = 0; i < rectanglesRowSize; i ++)
    {
        long b_x = rectangles[i][0];
        long b_y = rectangles[i][1];
        long t_x = rectangles[i][2];
        long t_y = rectangles[i][3];

        if (b_x < bx)
            bx = b_x;
        if (b_y < by)
            by = b_y;
        if (t_x > tx)
            tx = t_x;
        if (t_y > ty)
            ty = t_y;

        area += (t_x - b_x) * (t_y - b_y);

        _DP(b_x, b_y);
        _DP(b_x, t_y);
        _DP(t_x, b_y);
        _DP(t_x, t_y);
   }

    if (n != 4 || area != (tx - bx) * (ty - by))
        return false;
    printf("haha %ld %ld %ld %ld\n", bx, by, tx, ty);

    _CK(bx, by);
    _CK(bx, ty);
    _CK(tx, by);
    _CK(tx, ty);
    return true;
}

/* bool check_border(int** r, int i, int n, int a, int b, int c, int j) */
/* { */
/*     if (a == b) */
/*         return true; */

/*     while (i < n && r[i][j] != c) */
/*         i ++; */

/*     if (i == n) */
/*         return false; */

/*     int x, y; */

/*     if (j & 1) */
/*     { */
/*         x = r[i][0]; */
/*         y = r[i][2]; */
/*     } */
/*     else */
/*     { */
/*         x = r[i][1]; */
/*         y = r[i][3]; */
/*     } */

/*     if (y <= a || x >= b) */
/*         return check_border(r, i + 1, n, a, b, c, j); */

/*     if (a > x || b < y) */
/*         return false; */

/*     return check_border(r, i + 1, n, a, x, c, j) */
/*         && check_border(r, i + 1, n, y, b, c, j); */
/* } */

/* int comp_start(const void* e1, const void* e2) */
/* { */
/*     int* r1 = *((int**)e1); */
/*     int* r2 = *((int**)e2); */
/*     return r1[0] == r2[0] ? (r1[1] - r2[1]) : (r1[0] - r2[0]); */
/* } */

/* int comp_end(const void* e1, const void* e2) */
/* { */
/*     int* r1 = *((int**)e1); */
/*     int* r2 = *((int**)e2); */
/*     return r1[2] == r2[2] ? (r1[3] - r2[3]) : (r1[2] - r2[2]); */
/* } */

/* bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize) */
/* { */
/*     if (!rectangles || rectanglesRowSize < 2) */
/*         return true; */

/*     long bx = INT_MAX; */
/*     long by = INT_MAX; */
/*     long tx = INT_MIN; */
/*     long ty = INT_MIN; */
/*     long area = 0; */

/*     for (int i = 0; i < rectanglesRowSize; i ++) */
/*     { */
/*         long b_x = rectangles[i][0]; */
/*         long b_y = rectangles[i][1]; */
/*         long t_x = rectangles[i][2]; */
/*         long t_y = rectangles[i][3]; */

/*         if (b_x < bx || b_y < by) */
/*         { */
/*             bx = b_x; */
/*             by = b_y; */
/*         } */

/*         if (t_x > tx || t_y > ty) */
/*         { */
/*             tx = t_x; */
/*             ty = t_y; */
/*         } */

/*         area += (t_x - b_x) * (t_y - b_y); */
/*     } */

/*     if ((tx - bx) * (ty - by) != area) */
/*         return false; */

/*     if (!check_border(rectangles, 0, rectanglesRowSize, by, ty, bx, 0) */
/*         || !check_border(rectangles, 0, rectanglesRowSize, bx, tx, by, 1) */
/*         || !check_border(rectangles, 0, rectanglesRowSize, by, ty, tx, 2) */
/*         || !check_border(rectangles, 0, rectanglesRowSize, bx, tx, ty, 3)) */
/*         return false; */

/*     int** ends = malloc(sizeof(int*) * rectanglesRowSize); */
/*     memcpy(ends, rectangles, sizeof(int*) * rectanglesRowSize); */
/*     qsort(rectangles, rectanglesRowSize, sizeof(int*), comp_start); */
/*     qsort(ends, rectanglesRowSize, sizeof(int*), comp_end); */

/*     int j = 0; */

/*     for (int i = 0; i < rectanglesRowSize; i ++) */
/*     { */
/*         long b_x = rectangles[i][0]; */
/*         long b_y = rectangles[i][1]; */
/*         long t_x = rectangles[i][2]; */
/*         long t_y = rectangles[i][3]; */

/*         while (j < rectanglesRowSize && b_x >= ends[j][2] && b_y >= ends[j][3]) */
/*             j ++; */

/*         for (int k = j; k < rectanglesRowSize; k ++) */
/*         { */
/*             if (ends[k] == rectangles[i]) */
/*                 continue; */

/*             long b_xt = ends[k][0]; */
/*             long b_yt = ends[k][1]; */
/*             long t_xt = ends[k][2]; */
/*             long t_yt = ends[k][3]; */

/*             if (b_xt >= t_x && b_yt >= t_y) */
/*                 break; */

/*             if (b_x < t_xt && t_x > b_xt && b_y < t_yt && t_y > b_yt) */
/*                 return false; */
/*         } */
/*     } */
/*     return true; */
/* } */
