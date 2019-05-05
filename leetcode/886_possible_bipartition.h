// better solution ?
// STUPID buffer overflow again !!!!!!!!!
void pb_sort(int** dislike, int s, int e)
{
    if (s >= e)
        return;

    int* t;

    if (dislike[s][0] > dislike[e][0])
    {
        t = dislike[s];
        dislike[s] = dislike[e];
        dislike[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (dislike[i][0] < dislike[s][0]) i ++;
        while (dislike[e][0] > dislike[s][0]) e --;

        if (i >= e)
        {
            t = dislike[s];
            dislike[s] = dislike[e];
            dislike[e] = t;
        }
        else
        {
            t = dislike[i];
            dislike[i] = dislike[e];
            dislike[e] = t;
        }
    }

    pb_sort(dislike, cs, e - 1);
    pb_sort(dislike, e + 1, ce);
}

bool possibleBipartition(int N, int** dislikes, int dislikesRowSize, int *dislikesColSizes)
{
    if (N <= 2 || !dislikes || !dislikesRowSize)
        return true;

    char* a = calloc(sizeof(char), N + 1);
    char* b = calloc(sizeof(char), N + 1);

    int** cur = malloc(sizeof(int*) * dislikesRowSize);
    memcpy(cur, dislikes, sizeof(int*) * dislikesRowSize);

    // pb_sort(cur, 0, dislikesRowSize - 1);

    int cs = dislikesRowSize;
    int** nxt = malloc(sizeof(int*) * dislikesRowSize);
    int ns = 0;

    int x, y;

    while (cs)
    {
        for (int i = 0; i < cs; i ++)
        {
            x = cur[i][0];
            y = cur[i][1];

            if ((a[x] && a[y]) || (b[x] && b[y]))
                return false;

            if (a[x] || b[y])
            {
                a[x] = 1;
                b[y] = 1;
            }
            else if (a[y] || b[x])
            {
                a[y] = 1;
                b[x] = 1;
            }
            else
            {
                nxt[ns ++] = cur[i];
            }
        }

        // non of them conflict
        if (ns == cs)
        {
            ns = 0;
            x = cur[0][0];
            y = cur[0][1];

            a[x] = 1;
            b[y] = 1;
        }
        else
        {
            int** t = cur;
            cur = nxt;
            cs = ns;
            nxt = t;
            ns = 0;
        }
    }

    return true;
}
