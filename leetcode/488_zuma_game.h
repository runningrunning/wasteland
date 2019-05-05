// simply BFS or DFS, but how to represent them !
// just write code, code is difficult !!!
// find better solution !!!!!!!!
// DP ?
// how to represent it
// 3 bit one character
// read the questions !!!
// can choose a ball in the hand, without sequence !!!
// Wrong test cases ! But it output -1 in the case :"RRWWRRBBRR", "WB".

// just use string, could be more simple ???
// any other solution?
// how to speed up ?

int _rm(int* b, int i, int bl, int* n)
{
    int t[26];
    int ni = 0;
    bool found = false;

    do
    {
        found = false;
        int px = -1;
        int p = i;
        int ti = 0;

        while (p > 0 && (!b[p] || px == -1 || b[p] == px))
        {
            if (b[p])
            {
                if (px == -1)
                    px = b[p];
                t[ti ++] = p << 8 | b[p];
            }
            p --;
        }

        if (!ti)
            break;

        p = i + 1;

        while (p < bl && (!b[p] || b[p] == px))
        {
            if (b[p])
                t[ti ++] = p << 8 | b[p];
            p ++;
        }

        if (ti > 2)
        {
            found = true;
            for (int y = 0; y < ti; y ++)
            {
                n[ni ++] = t[y];
                b[t[y] >> 8] = 0;
            }
        }
    } while (found);
    return ni;
}

void _fm(int* b, int bl, int bn, int* h, int n, int* m)
{
    /* out(b, bl); */
    /* out(h, 26); */
    /* printf("bn is %d %d.\n", bn, n); */
    if (!bn)
    {
        if (n < *m)
            *m = n;
        return;
    }

    if (n >= *m)
        return;

    int ti = 0;
    int t[26];

    int pre = -1;
    // try to remove 2
    for (int i = 0; i < bl - 1; i ++)
    {
        if (!b[i] || b[i] == pre)
            continue;
        pre = b[i];
        for (int j = i + 1; j < bl; j ++)
        {
            if (!b[j])
                continue;
            if (b[j] != b[i] || !h[b[i]])
                break;

            ti = 0;
            t[ti ++] = i << 8 | b[i];
            t[ti ++] = j << 8 | b[j];
            int x = b[i];
            h[x] --;

            b[i] = 0;
            b[j] = 0;
            /* printf("====== \n"); */
            /* out(b, bl); */
            ti += _rm(b, i, bl, t + 2);
            /* out(b, bl); */
            /* printf("------ \n"); */
            _fm(b, bl, bn - ti, h, n + 1, m);

            for (int y = 0; y < ti; y ++)
                b[t[y] >> 8] = t[y] & 0xFF;

            h[x] ++;
        }
    }

    pre = -1;

    // try to remove 1
    for (int i = 0; i < bl; i ++)
    {
        if (!b[i] || b[i] == pre)
            continue;
        pre = b[i];
        bool found = false;

        if (h[b[i]])
        {
            ti = 0;
            int p = i - 1;
            if (b[p]) // && b[p] != b[i])
                printf("error here.\n");
            int x = b[i];

            b[p] = x;
            h[x] --;
            ti += _rm(b, i, bl, t);
            _fm(b, bl, bn + 1 - ti, h, n + 1, m);
            for (int y = 0; y < ti; y ++)
                b[t[y] >> 8] = t[y] & 0xFF;

            h[x] ++;
            b[p] = 0;
        }
    }
}

int findMinStep(char* board, char* hand)
{
    char t[26] = {0};
    int h[26] = {0};

    int i = 0;
    int bn = 0;
    int a = board[i ++];

    while (a)
    {
        bn ++;
        t[a - 'A'] ++;
        a = board[i ++];
    }

    i = 0;
    a = hand[i ++];

    while (a)
    {
        if (t[a - 'A'])
            t[a - 'A'] ++;
        h[a - 'A'] ++;
        a = hand[i ++];
    }

    if ((t['B' - 'A'] && t['B' - 'A'] < 3)
        || (t['G' - 'A'] && t['G' - 'A'] < 3)
        || (t['R' - 'A'] && t['R' - 'A'] < 3)
        || (t['W' - 'A'] && t['W' - 'A'] < 3)
        || (t['Y' - 'A'] && t['Y' - 'A'] < 3))
        return -1;

    int bi = 0;
    int bl = strlen(board);
    int* b = malloc(sizeof(int) * bl * 3);

    for (int i = 0; i < bl; i ++)
    {
        b[bi ++] = 0;
        b[bi ++] = 0;
        b[bi ++] = board[i] - 'A';
    }

    int max = INT_MAX;
    _fm(b, bl * 3, bn, h, 0, &max);
    return max == INT_MAX ? -1 : max;
}
