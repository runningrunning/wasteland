// BFS + Graphic not true, need to go back
// Memory Limit Exceeded !!!
// how to optimize the memory usage ????
// why heap ????
// read book about how to optimize the memory usage !!
// check redundant, status can be remembered? at every point has the same key in the next step is redundant !!!!

int shortestPathAllKeys(char** grid, int gridSize)
{
    int r = gridSize;
    int col = strlen(grid[0]);

    long* bits = calloc(sizeof(long), r * 32);

    int* a = malloc(sizeof(int) * 256);
    int* b = malloc(sizeof(int) * 256);

    int ns = 256;
    int cs = 256;

    int ci = 0;
    int ni = 0;
    int* c = a;
    int* n = b;

#define MARK(x, y, k) do {bits[(x) * 32 + y] |= 1L << (k);} while (0)
#define IS_MARK(x, y, k) (bits[(x) * 32 + y] & (1L << (k)))

    int l = 0;
    int k = 0;

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < col; j ++)
        {
            int x = grid[i][j];
            if (x == '@')
            {
                MARK(i, j, 0);
                c[ci ++] = i << 8 | j;
            }

            if (x >= 'a' && x <= 'z')
                k |= 1 << (x - 'a');

            if (x >= 'A' && x <= 'Z')
                l |= 1 << (x - 'A');
        }

    if (l != k)
        return -1;

    int step = 0;

    while (true)
    {
        step ++;

        if (ci == 0)
            return -1;

        // printf("step %d ci is %d.\n", step, ci);

        for (int i = 0; i < ci ; i ++)
        {
            int o = c[i];
            int x = (o >> 8) & 0xFF;
            int y = o & 0xFF;
            int k = o >> 16;

            // printf("x, %d y %d k %d.\n", x, y, k);

#define STEP(x, y, k) do {                                              \
                int t = grid[x][y];                                     \
                if (t == '#') break;                                    \
                if (t >= 'A' && t <= 'Z' && !(k & (1 << (t - 'A')))) break; \
                int nk = k;                                             \
                if (t >= 'a' && t <= 'z') {nk |= (1 << (t - 'a')); if (nk == l) return step; } \
                if (bits[(x) * 32 + (y)] & (1L << nk)) break;            \
                bits[(x) * 32 + y] |= (1L << nk);                        \
                if (ni == ns) {ns *= 2; n = realloc(n, sizeof(int) * ns); } \
                n[ni ++] = (nk) << 16 | (x) << 8 | (y);                 \
            } while (0)

            if (x)
                STEP(x - 1, y, k);
            if (y)
                STEP(x, y - 1, k);
            if (x != r - 1)
                STEP(x + 1, y, k);
            if (y != col - 1)
                STEP(x, y + 1, k);
        }

        ci = ni;
        ni = ns;
        ns = cs;
        cs = ni;
        ni = 0;

        int* t = n;
        n = c;
        c = t;
    }

    return step;
}

// typedef struct
// {
//     int l;
//     int x, y;
//     int k;
//     int* ns;
// } Node;

// Node* cNode(int x, int y, int g)
// {
//     Node* n = malloc(sizeof(Node));
//     n->ns = calloc(sizeof(int), g);
//     n->ns[x] |= 1 << y;
//     n->x = x;
//     n->y = y;
//     n->k = 0;
//     n->l = 0;
//     return n;
// }

// Node* nNode(int x, int y, int l, int k, int g, Node* o, bool new)
// {
//     Node* n = malloc(sizeof(Node));
//     n->ns = malloc(sizeof(int) * g);
//     if (new)
//         n->ns = memset(n->ns, 0, sizeof(int) * g);
//     else
//         memcpy(n->ns, o->ns, sizeof(int) * g);

//     n->ns[x] |= 1 << y;
//     n->x = x;
//     n->y = y;
//     n->l = l;
//     n->k = k;
//     return n;
// }

// bool next(char** g, int gr, int gc, Node* n, Node** s, int* si, int l, bool* key)
// {
//     int x = n->x;
//     int y = n->y;
//     int* f = n->ns;
//     int mk = n->k;

//     int tsi = *si;
//     // printf("next %d %d %d %d.\n", x, y, gr, gc);
// #define STEP(x, y) do {                                                 \
//         if (f[(x)] & (1 << (y))) break;                                 \
//         int c = g[x][y];                                                \
//         if (c == '#') break;                                            \
//         if (c >= 'A' && c <= 'Z' && !(n->l & (1 << (c - 'A')))) break;  \
//         int nl = n->l;                                                  \
//         int nk = n->k;                                                  \
//         if (c >= 'a' && c <= 'z' && !(nl & (1 << (c - 'a')))) {          \
//             nl |= 1 << (c - 'a'); nk = n->k + 1; mk = nk; *key = true; if (nl == l) return true; \
//         }                                                               \
//         s[(*si) ++] = nNode(x, y, nl, nk, gr, n, nl != n->l);           \
//     } while (0)

//     if (x)
//         STEP(x - 1, y);
//     if (y)
//         STEP(x, y - 1);
//     if (x != gr - 1)
//         STEP(x + 1, y);
//     if (y != gc - 1)
//         STEP(x, y + 1);

//     printf("======== x %d y %d\n", x, y);
//     if (tsi == *si)
//     {
//         for (int i = 0; i < gr; i ++)
//         {
//             int x = f[i];
//             for (int j = 0; j < gc; j ++)
//                 printf("%d ", x & (1 << j) ? 1 : 0);
//             printf("\n");
//         }
//     }

//     return false;
// }

// void fNode(Node* n)
// {
//     free(n->ns);
//     free(n);
// }

// void fNodeL(Node** n, int ni)
// {
//     for (int i = 0; i < ni; i ++)
//         if (n[i])
//             fNode(n[i]);
//     free(n);
// }

// int shortestPathAllKeys(char** grid, int gridSize)
// {
//     int r = gridSize;
//     int l = strlen(grid[0]);

//     Node** a = malloc(sizeof(Node*) * r * l * 4);
//     Node** b = malloc(sizeof(Node*) * r * l * 4);


//     int ci = 0;
//     int ni = 0;
//     int cs = r * l * 4;
//     int ns = r * l * 4;

//     Node** c = a;
//     Node** n = b;

//     int lo = 0;
//     int k = 0;
//     for (int i = 0; i < r; i ++)
//         for (int j = 0; j < l; j ++)
//         {
//             int x = grid[i][j];

//             if (x == '@')
//                 c[ci ++] = cNode(i, j, r);

//             if (x >= 'a' && x <= 'z')
//                 k |= 1 << (x - 'a');

//             if (x >= 'A' && x <= 'Z')
//                 lo |= 1 << (x - 'A');
//         }

//     if (lo != k)
//         return -1;
//     int step = 0;

//     int key = 0;

//     while (true)
//     {
//         step ++;

//         int max_key = key;

//         if (ci == 0)
//             break;

//         for (int i = 0; i < ci; i ++)
//         {

//             if (key && c[i]->k < key)
//             {
//                 // printf("c[i] k %d key %d.\n", c[i]->k, key);
//                 fNode(c[i]);
//                 c[i] = NULL;
//                 continue;
//             }

//             if (ni + 4 >= ns)
//             {
//                 ns *= 2;
//                 printf("ns %d %d.\n", ns, ni);
//                 n = realloc(n, sizeof(Node*) * ns);
//             }

//             bool new_key = false;
//             if (next(grid, r, l, c[i], n, &ni, lo, &new_key))
//             {
//                 fNodeL(c, ci);
//                 fNodeL(n, ni);
//                 return step;
//             }

//             if (new_key && c[i]->k + 1 > max_key)
//                 max_key = c[i]->k + 1;

//             fNode(c[i]);
//             c[i] = NULL;
//         }

//         // printf("ni %d ci %d.\n", ni ,ci);
//         int ts = ns;
//         Node** t = n;
//         n = c;
//         ns = cs;
//         c = t;
//         cs = ts;
//         ci = ni;
//         ni = 0;
//         key = max_key;
//     }

//     fNodeL(c, ci);
//     fNodeL(n, ni);
//     return -1;
// }
