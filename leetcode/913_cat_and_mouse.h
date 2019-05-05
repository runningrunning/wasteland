// DFS is wrong, toplogic is right
// DP not DFS or BFS
// DFS STUPID WRONG ALGORITHM
// DFS can not solve the recursion

// 1 mouse, 2 cat, 3 draw
// [m][c]
// how to simulate steps ?
int catMouseGame(int** graph, int graphRowSize, int *graphColSizes)
{
    int g = graphRowSize;
    int* gc = graphColSizes;
    // mouse first
    char* mbs = calloc(sizeof(int), graphRowSize * graphRowSize);
    // cat first
    char* cbs = calloc(sizeof(int), graphRowSize * graphRowSize);

    int si = 0;
    int* stacks = malloc(sizeof(int) * graphRowSize * graphRowSize * 2);
    int bsi = 0;
    int* bstacks = malloc(sizeof(int) * graphRowSize * graphRowSize * 2);

    for (int i = 0; i < graphRowSize; i ++)
    {
        // (m is 0, c)
        mbs[0 * g + i] = 1;
        cbs[0 * g + i] = 1;

        // cat move
        stacks[si ++] = 0 << 16 | i << 8;
        stacks[si ++] = 0 << 16 | i << 8 | 1;

        if (i)
        {
            mbs[i * g + i] = 2;
            cbs[i * g + i] = 2;
            // mouse movie
            stacks[si ++] = i << 16 | i << 8;
            stacks[si ++] = i << 16 | i << 8 | 1;
        }
    }

    int* st = stacks;
    int* bst = bstacks;

    while (true)
    {
        /* out(mbs, g * g); */
        /* out(cbs, g * g); */

        while (si)
        {
            int x = st[-- si];
            int xm = x >> 16;
            int xc = (x >> 8) & 0xFF;

            // printf("== %d %d %d.\n", xm, xc, x & 1);

            if (x & 1)
            {
                int n = cbs[xm * g + xc];
                // cat move, check previous mouse
                if (n == 1)
                {
                    for (int i = 0; i < gc[xm]; i ++)
                    {
                        int m = graph[xm][i];
                        if (!mbs[m * g + xc])
                        {
                            mbs[m * g + xc] = 1;
                            bst[bsi ++] = m << 16 | xc << 8;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < gc[xm]; i ++)
                    {
                        bool cat = true;
                        int m = graph[xm][i];

                        if (mbs[m * g + xc])
                            continue;

                        for (int j = 0; j < gc[m]; j ++)
                        {
                            int p = graph[m][j];
                            if (cbs[p * g + xc] != 2)
                            {
                                cat = false;
                                break;
                            }
                        }

                        if (cat)
                        {
                            mbs[m * g + xc] = 2;
                            bst[bsi ++] = m << 16 | xc << 8;
                        }
                    }
                }
            }
            else
            {
                int n = mbs[xm * g + xc];
                // mouse move, check previous cat
                if (n == 2)
                {
                    for (int i = 0; i < gc[xc]; i ++)
                    {
                        int c = graph[xc][i];
                        if (c && !cbs[xm * g + c])
                        {
                            cbs[xm * g + c] = 2;
                            bst[bsi ++] = xm << 16 | c << 8 | 1;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < gc[xc]; i ++)
                    {
                        bool mouse = true;
                        int c = graph[xc][i];

                        if (!c || cbs[xm * g + c])
                            continue;

                        for (int j = 0; j < gc[c]; j ++)
                        {
                            int p = graph[c][j];
                            if (p && mbs[xm * g + p] != 1)
                            {
                                mouse = false;
                                break;
                            }
                        }

                        if (mouse)
                        {
                            cbs[xm * g + c] = 1;
                            bst[bsi ++] = xm << 16 | c << 8 | 1;
                        }
                    }
                }
            }
        }
        if (!bsi)
            break;

        si = bsi;
        bsi = 0;
        st = st == stacks ? bstacks : stacks;
        bst = bst == stacks ? bstacks : stacks;
    }

    /* out(mbs, g * g); */
    /* out(cbs, g * g); */

    return mbs[g + 2];
}



// bottom up ? or top down ?
// not way to top down, but only bottom up ?
// the node number is too much and any steps would explore the whole stacks
// DFS is not the correct answer here

// TOTALLY STUPID WRONG ALGORITHMS !!!
// NOT CORRECT !
// HOW TO DEFINE PROBLEM ?
// Bug IN CORNER CASE ?
// just one case missing !
// DFS ? BFS ? not really !!
// how to define a DRAW ?
// current node is not DRAW ?
// COULD BE FUN !!!!!!!!!!!!!
// LEARN A LOT !

// DFS with prefer not visited nodes?, not worked

/* int catMouseGame(int** graph, int graphRowSize, int *graphColSizes) */
/* { */
/*     char* bs = calloc(sizeof(char), (64 + 64) * 64); */
/*     return cmg(graph, graphColSizes, 1, 2, bs, true, graphRowSize + 1); */
/* } */


// It's win or lose depends on when cat or mouse position is fixed, it will win or lose at any move.
// how to check back to the original position ?
// how to define this problem ?

// [[3,4,6,7,9,15,16,18],[4,5,8,19],[4,5,6,7,9,18],[0,10,11,15],[0,1,2,6,10,12,14,16],[1,2,7,9,15,17,18],[0,2,4,7,9,10,11,12,13,14,15,17,19],[0,2,5,6,9,16,17],[1,9,14,15,16,19],[0,2,5,6,7,8,10,11,13,15,16,17,18],[3,4,6,9,17,18],[3,6,9,12,19],[4,6,11,15,17,19],[6,9,15,17,18,19],[4,6,8,15,19],[0,3,5,6,8,9,12,13,14,16,19],[0,4,7,8,9,15,17,18,19],[5,6,7,9,10,12,13,16],[0,2,5,9,10,13,16],[1,6,8,11,12,13,14,15,16]]

// stupid wrong algorithm again !!
// [[3,4],[3,5],[3,6],[0,1,2],[0,5,6],[1,4],[2,4]]
// it should can go back
/* int cmg(int** g, int* rc, int m, int c, char* b, bool ms, int step) */
/* { */
/*     if (step <= 0) */
/*         return 0; */

/*     // printf("step %d.\n", step); */
/*     if (ms) */
/*     { */
/*         if (!m) */
/*             return 1; */

/*         int l = rc[m]; */

/*         for (int i = 0; i < l; i ++) */
/*         { */
/*             if (!g[m][i]) */
/*                 return 1; */
/*         } */

/*         bool catch = true; */
/*         bool miss = false; */
/*         bool has = false; */

/*         for (int i = 0; i < l; i ++) */
/*         { */
/*             if (g[m][i] == 0) */
/*                 return 1; */

/*             if (!b[m * 64 + c]) */
/*             { */
/*                 has = true; */
/*                 b[m * 64 + c] = 1; */
/*                 int x = cmg(g, rc, g[m][i], c, b, false, step); */
/*                 b[m * 64 + c] = 0; */
/*                 if (x != 2) */
/*                 { */
/*                     catch = false; */
/*                     miss = miss || (x == 1); */
/*                 } */
/*             } */
/*         } */

/*         if (!has) */
/*             return 0; */

/*         if (catch) */
/*             return 2; */

/*         if (miss) */
/*             return 1; */

/*         return 0; */
/*     } */

/*     if (c == m) */
/*         return 2; */

/*     if (b[4096 + c * 64 + m]) */
/*         return 0; */

/*     int l = rc[c]; */

/*     for (int i = 0; i < l; i ++) */
/*     { */
/*         if (g[c][i] && g[c][i] == m) */
/*             return 2; */
/*     } */

/*     bool miss = true; */
/*     bool catch = false; */

/*     for (int i = 0; i < l; i ++) */
/*     { */
/*         if (!g[c][i]) */
/*             continue; */

/*         if (g[c][i] == m) */
/*             return 2; */

/*         if (!b[4096 + c * 64 + m]) */
/*         { */
/*             b[4096 + c * 64 + m] = 1; */
/*             int x = cmg(g, rc, m, g[c][i], b, true, step - 1); */
/*             b[4096 + c * 64 + m] = 0; */
/*             if (x != 1) */
/*             { */
/*                 miss = false; */
/*                 catch = catch || (x == 2); */
/*             } */
/*         } */
/*     } */

/*     if (miss) */
/*         return 1; */

/*     if (catch) */
/*         return 2; */

/*     return 0; */
/* } */

/* int catMouseGame(int** graph, int graphRowSize, int *graphColSizes) */
/* { */
/*     char* bs = calloc(sizeof(char), (64 + 64) * 64); */
/*     return cmg(graph, graphColSizes, 1, 2, bs, true, graphRowSize + 1); */
/* } */
