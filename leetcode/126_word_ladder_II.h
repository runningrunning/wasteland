// BFS ? yes, don't insert any item if it's has been inserted before, but not in this turn to optimie the code !!!
// DO IT AGAIN !! similar with WordLadder II.
// optimize the memory usage !!!!! // Reduce the memory usage !!!!
// Optimize the algorithm !!
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool can(char* a, char* b)
{
    int i = 0;
    bool diff = false;

    while (a[i])
    {
        if (a[i] != b[i])
        {
            if (diff)
                return false;
            diff = true;
        }

        i ++;
    }
    return diff;
}

char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int** columnSizes, int* returnSize)
{
    *columnSizes = NULL;
    *returnSize = 0;

    if (!wordListSize)
        return NULL;

    char* bs = calloc(sizeof(char), wordListSize);
    int** same = calloc(sizeof(int*), wordListSize);
    int** a = calloc(sizeof(int*), wordListSize);
    int** b = calloc(sizeof(int*), wordListSize);

    int cs = wordListSize;
    int ns = wordListSize;

    int ci = 0;
    int ni = 0;
    int** cur = a;
    int** nxt = b;

    int found = -1;
    bool has = false;

    for (int i = 0; i < wordListSize; i ++)
    {
        if (!strcmp(wordList[i], endWord))
            found = i;

        if (can(beginWord, wordList[i]))
        {
            cur[ci] = malloc(sizeof(int) * 1);
            cur[ci][0] = i;

            bs[i] = 1;

            if (found == i)
                has = true;

            ci ++;
        }
        for (int j = i + 1; j < wordListSize; j ++)
            if (can(wordList[i], wordList[j]))
            {
                int size = same[i] ? same[i][0] : 0;
                size ++;

                same[i] = realloc(same[i], sizeof(int) * (size + 1));
                same[i][0] = size;
                same[i][size] = j;

                size = same[j] ? same[j][0] : 0;
                size ++;
                same[j] = realloc(same[j], sizeof(int) * (size + 1));
                same[j][0] = size;
                same[j][size] = i;
            }
    }

    if (found == -1)
        return NULL;

    int step = 1;

    char* st = calloc(sizeof(char), wordListSize);

    while (!has)
    {
        for (int i = 0; i < ci; i ++)
        {
            int top = cur[i][step - 1];
            if (same[top])
            {
                for (int j = 0; j < same[top][0]; j ++)
                {
                    int try = same[top][j + 1];
                    if (!bs[try])
                    {
                        st[try] = 1;

                        if (ni == ns)
                        {
                            ns *= 2;
                            nxt = realloc(nxt, sizeof(int*) * ns);
                            memset(nxt + ni, 0, sizeof(int*) * ni);
                        }

                        if (nxt[ni])
                            free(nxt[ni]);

                        nxt[ni] = malloc(sizeof(int) * (step + 1));
                        memcpy(nxt[ni],  cur[i], sizeof(int) * step);
                        nxt[ni][step] = try;

                        if (try == found)
                            has = true;

                        ni ++;
                    }
                }
            }
        }

        // printf("step is %d.\n", step);
        int** t = cur;

        cur = nxt;
        nxt = t;
        ci = ni;
        ni = ns;
        ns = cs;
        cs = ni;
        ni = 0;

        for (int k = 0; k < wordListSize; k ++)
            if (st[k])
                bs[k] = 1;

        step ++;

        if (step >= wordListSize)
            break;
    }

    if (!has)
        return NULL;

    int ri = 0;
    char*** r = NULL;
    for (int i = 0; i < ci; i ++)
    {
        if (cur[i][step - 1] == found)
        {
            r = realloc(r, sizeof(char**) * (ri + 1));
            r[ri] = malloc(sizeof(char*) * (step + 1));
            r[ri][0] = strdup(beginWord);
            for (int j = 0; j < step; j ++)
                r[ri][j + 1] = strdup(wordList[cur[i][j]]);
            ri ++;
        }
    }

    int* cols = malloc(sizeof(int) * ri);
    for (int i = 0; i < ri; i ++)
        cols[i] = step + 1;

    free(bs);
    for (int i = 0; i < wordListSize; i ++)
        free(same[i]);
    free(same);
    for (int i = 0; i < cs; i ++)
        free(cur[i]);
    for (int i = 0; i < ns; i ++)
        free(nxt[i]);
    free(cur);
    free(nxt);
    free(st);

    *columnSizes = cols;
    *returnSize = ri;

    return r;
}
