// try method just like 42 Trapping Rain Water with scan line method !
int trapRainWater(int** m, int r, int c)
{
}

// STUPID WRONG ALGORITHMS !!!!
/* void _trw_mark(int** m, int x, int y, int r, int c, short* b) */
/* { */
/*     if (b[x * c + y] == -1) */
/*         return; */

/*     b[x * c + y] = -1; */

/*     if (x && m[x][y] <= m[x - 1][y]) */
/*         _trw_mark(m, x - 1, y, r, c, b); */

/*     if (x != r - 1 && m[x][y] <= m[x + 1][y]) */
/*         _trw_mark(m, x + 1, y, r, c, b); */

/*     if (y && m[x][y] <= m[x][y - 1]) */
/*         _trw_mark(m, x, y - 1, r, c, b); */

/*     if (y != c - 1 && m[x][y] <= m[x][y + 1]) */
/*         _trw_mark(m, x, y + 1, r, c, b); */
/* } */

/* void _trw_next(int** m, int x, int y, int r, int c, short* b, short id, int* t, int px, int py) */
/* { */
/*     if (x < 0 || y < 0 || x >= r || y >= c) */
/*         return; */

/*     if (b[x * c + y] == -1) */
/*     { */
/*         if (((*t) & 0xFFFF) > m[x][y]) */
/*             *t = px << 24 | py << 16 | m[x][y]; */
/*         return; */
/*     } */

/*     if (b[x * c + y] == id) */
/*         return; */

/*     b[x * c + y] = id; */

/*     _trw_next(m, x - 1, y, r, c, b, id, t, x, y); */
/*     _trw_next(m, x + 1, y, r, c, b, id, t, x, y); */
/*     _trw_next(m, x, y - 1, r, c, b, id, t, x, y); */
/*     _trw_next(m, x, y + 1, r, c, b, id, t, x, y); */
/* } */

/* void _trw_fill(int** m, int x, int y, int r, int c, int h, short* b, int* ret) */
/* { */
/*     if (x < 0 || y < 0 || x >= r || y >= c) */
/*         return; */

/*     if (b[x * c + y] == -1) */
/*         return; */

/*     b[x * c + y] = -1; */

/*     if (m[x][y] <= h) */
/*         (*ret) += h - m[x][y]; */
/*     else */
/*         return; */

/*     _trw_fill(m, x - 1, y, r, c, h, b, ret); */
/*     _trw_fill(m, x + 1, y, r, c, h, b, ret); */
/*     _trw_fill(m, x, y - 1, r, c, h, b, ret); */
/*     _trw_fill(m, x, y + 1, r, c, h, b, ret); */
/* } */

/* /\* void out_m(int**m, int r, int c, short* b) *\/ */
/* /\* { *\/ */
/* /\*     printf("========================\n"); *\/ */
/* /\*     for (int i = 0; i < r; i ++) *\/ */
/* /\*     { *\/ */
/* /\*         for (int j = 0; j < c; j ++) *\/ */
/* /\*             printf("%10d(%-3d)", m[i][j], b[i * c + j]); *\/ */
/* /\*         printf("\n"); *\/ */
/* /\*     } *\/ */
/* /\*     printf("========================\n"); *\/ */
/* /\* } *\/ */

/* int trapRainWater(int** m, int r, int c) */
/* { */
/*     if (r <= 2 || c <= 2) */
/*         return 0; */
/*     short* b = calloc(sizeof(short), r * c); */
/*     for (int i = 0; i < r; i ++) */
/*     { */
/*         if (b[i * c] != -1) */
/*             _trw_mark(m, i, 0, r, c, b); */

/*         if (b[i * c + c - 1] != -1) */
/*             _trw_mark(m, i, c - 1, r, c, b); */
/*     } */

/*     for (int i = 0; i < c; i ++) */
/*     { */
/*         if (b[i] != -1) */
/*             _trw_mark(m, 0, i, r, c, b); */

/*         if (b[(r - 1) * c + i] != -1) */
/*             _trw_mark(m, r - 1, i, r, c, b); */
/*     } */

/*     // out_m(m, r, c, b); */
/*     // outsh(b, r * c); */
/*     short id = 1; */
/*     int ret = 0; */

/*     for (int i = 0; i < r; i ++) */
/*         for (int j = 0; j < c; j ++) */
/*         { */
/*             while (b[i * c + j] != -1) */
/*             { */
/*                 int t = 32767; */
/*                 _trw_next(m, i, j, r, c, b, id ++, &t, 0, 0); */

/*                 int x = (t >> 24) & 0xFF; */
/*                 int y = (t >> 16) & 0xFF; */
/*                 int h = t & 0xFFFF; */
/*                 // outsh(b, r * c); */
/*                 _trw_fill(m, x, y, r, c, h, b, &ret); */
/*                 // out_m(m, r, c, b); */
/*                 // outsh(b, r * c); */
/*             } */
/*         } */

/*     return ret; */
/* } */

// TLE !!!!!!!!!!!!!!!!
/* int comp(const void* a1, const void* a2) */
/* { */
/*     return *((int*)a1) - *((int*)a2); */
/* } */
/* void _trw_mark(int** m, int x, int y, int r, int c, short* b) */
/* { */
/*     if (b[x * c + y] == -1) */
/*         return; */
/*     b[x * c + y] = -1; */

/*     if (x && m[x][y] <= m[x - 1][y]) */
/*         _trw_mark(m, x - 1, y, r, c, b); */

/*     if (x != r - 1 && m[x][y] <= m[x + 1][y]) */
/*         _trw_mark(m, x + 1, y, r, c, b); */

/*     if (y && m[x][y] <= m[x][y - 1]) */
/*         _trw_mark(m, x, y - 1, r, c, b); */

/*     if (y != c - 1 && m[x][y] <= m[x][y + 1]) */
/*         _trw_mark(m, x, y + 1, r, c, b); */
/* } */

/* void _trw(int** m, int x, int y, int r, int c, short* b, int* t, int h, int id, short* n) */
/* { */
/*     if (b[x * c + y] == -1) */
/*     { */
/*         if (m[x][y] < *t) */
/*         { */
/*             *t = m[x][y]; */
/*         } */
/*         return; */
/*     } */

/*     if (b[x * c + y] == id) */
/*         return; */

/*     if (*t < h) */
/*         return; */

/*     b[x * c + y] = id; */

/*     if (h >= m[x - 1][y]) */
/*         _trw(m, x - 1, y, r, c, b, t, h, id, n); */
/*     else */
/*         if (m[x - 1][y] < *t) */
/*             *t = m[x - 1][y]; */

/*     if (h >= m[x + 1][y]) */
/*         _trw(m, x + 1, y, r, c, b, t, h, id, n); */
/*     else */
/*         if (m[x + 1][y] < *t) */
/*             *t = m[x + 1][y]; */

/*     if (h >= m[x][y - 1]) */
/*         _trw(m, x, y - 1, r, c, b, t, h, id, n); */
/*     else */
/*         if (m[x][y - 1] < *t) */
/*             *t = m[x][y - 1]; */

/*     if (h >= m[x][y + 1]) */
/*         _trw(m, x, y + 1, r, c, b, t, h, id, n); */
/*     else */
/*         if (m[x][y + 1] < *t) */
/*             *t = m[x][y + 1]; */
/* } */

/* void _trw_update(int** m, int x, int y, int r, int c, short* b, int t, int h, int id, short* n) */
/* { */
/*     if (b[x * c + y] == id) */
/*         return; */

/*     b[x * c + y] = id; */

/*     if (t > n[x * c + y]) */
/*         n[x * c + y] = t; */

/*     if (h >= m[x - 1][y]) */
/*         _trw_update(m, x - 1, y, r, c, b, t, h, id, n); */
/*     if (h >= m[x + 1][y]) */
/*         _trw_update(m, x + 1, y, r, c, b, t, h, id, n); */
/*     if (h >= m[x][y + 1]) */
/*         _trw_update(m, x, y + 1, r, c, b, t, h, id, n); */
/*     if (h >= m[x][y - 1]) */
/*         _trw_update(m, x, y - 1, r, c, b, t, h, id, n); */
/* } */

/* int trapRainWater(int** m, int heightMapRowSize, int heightMapColSize) */
/* { */
/*     if (heightMapRowSize <= 2 || heightMapColSize <= 2) */
/*         return 0; */

/*     short* b = calloc(sizeof(short), heightMapRowSize * heightMapColSize); */
/*     for (int i = 0; i < heightMapRowSize; i ++) */
/*     { */
/*         if (b[i * heightMapColSize] != -1) */
/*             _trw_mark(m, i, 0, heightMapRowSize, heightMapColSize, b); */

/*         if (b[i * heightMapColSize + heightMapColSize - 1] != -1) */
/*             _trw_mark(m, i, heightMapColSize - 1, heightMapRowSize, heightMapColSize, b); */
/*     } */

/*     for (int i = 0; i < heightMapColSize; i ++) */
/*     { */
/*         if (b[i] != -1) */
/*             _trw_mark(m, 0, i, heightMapRowSize, heightMapColSize, b); */

/*         if (b[(heightMapRowSize - 1) * heightMapColSize + i] != -1) */
/*             _trw_mark(m, heightMapRowSize - 1, i, heightMapRowSize, heightMapColSize, b); */
/*     } */
/*     // outsh(b, heightMapRowSize * heightMapColSize); */

/*     int ai = 0; */
/*     int* a = malloc(sizeof(int) * heightMapRowSize * heightMapColSize); */

/*     for (int i = 0; i < heightMapRowSize * heightMapColSize; i ++) */
/*     { */
/*         if (b[i] != -1) */
/*         { */
/*             int x = i / heightMapColSize; */
/*             int y = i % heightMapColSize; */
/*             a[ai ++] = m[x][y] << 16 | x << 8 | y; */
/*         } */
/*     } */

/*     qsort (a, ai, sizeof(int), comp); */

/*     int r = 0; */
/*     int id = 1; */
/*     short* n = calloc(sizeof(short), heightMapRowSize * heightMapColSize); */

/*     for (int i = ai - 1; i >= 0; i --) */
/*     { */
/*         int x = (a[i] >> 8) & 0xFF; */
/*         int y = (a[i]) & 0xFF; */
/*         int t = 32767; */

/*         if (!n[x * heightMapColSize + y]) */
/*         { */
/*             _trw(m, x, y, heightMapRowSize, heightMapColSize, b, &t, m[x][y], id ++, n); */
/*             n[x * heightMapColSize + y] = t; */
/*             if (m[x][y] < t) */
/*                 _trw_update(m, x, y, heightMapRowSize, heightMapColSize, b, t, m[x][y], id ++, n); */
/*         } */
/*     } */


/*     /\* for (int i = 1; i < heightMapRowSize  - 1; i ++) *\/ */
/*     /\*     for (int j = 1; j < heightMapColSize - 1; j ++) *\/ */
/*     /\*     { *\/ */
/*     /\*         int t = 32767; *\/ */
/*     /\*         if (b[i * heightMapColSize + j] != -1) *\/ */
/*     /\*         { *\/ */
/*     /\*             if (!n[i * heightMapColSize + j]) *\/ */
/*     /\*             { *\/ */
/*     /\*                 _trw(m, i, j, heightMapRowSize, heightMapColSize, b, &t, m[i][j], id ++, n); *\/ */
/*     /\*                 n[i * heightMapColSize + j] = t; *\/ */
/*     /\*                 if (m[i][j] < t) *\/ */
/*     /\*                     _trw_update(m, i, j, heightMapRowSize, heightMapColSize, b, t, m[i][j], id ++, n); *\/ */
/*     /\*             } *\/ */
/*     /\*         } *\/ */
/*     /\*     } *\/ */
/*     // outsh(b, heightMapRowSize * heightMapColSize); */
/*     outsh(n, heightMapRowSize * heightMapColSize); */

/*     for (int i = 1; i < heightMapRowSize - 1; i ++) */
/*         for (int j = 1; j < heightMapColSize - 1; j ++) */
/*         { */
/*             if (b[i * heightMapColSize + j] > 0) */
/*             { */
/*                 if (m[i][j] < n[i * heightMapColSize + j]) */
/*                 { */
/*                     r += n[i * heightMapColSize + j] - m[i][j]; */
/*                     // printf("m[i][j] %d. n[i * heightMapColSiz + j] %d.\n", m[i][j], n[i * heightMapColSize + j]); */
/*                 } */
/*             } */
/*         } */

/*     return r; */
/* } */
