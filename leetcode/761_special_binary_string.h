// TRY RECURSION METHOD !!
// simple brute force !!! and do recursion. there is no shortest way to do this !!!!!
// there is no need to use heap !!
// just find the largest one, find the largest one doesn't works either !!????
// stupid WRONG ALGORITHMS !!!
// similar with 555. Split Concatenated Strings ??
// just simple recursion !
// write the simple code to do this !!!!!!!
// 1 1010 1100 010

int comp(char* s, int x1, int y1, int x2, int y2)
{
    while (x1 <= y1 && x2 <= y2 && s[x1] == s[x2])
    {
        x1 ++;
        x2 ++;
    }

    if (x1 == y1 && x2 == y2)
        return 0;

    return s[x1] > s[x2] ? 1 : -1;
}

int mks(char* S, char* d)
{
    int min_s = INT_MAX;
    int max_s = 0;
    int max_e = 0;

    int i = 0;
    int p = -1;
    int c = S[i ++];

    // printf("== %s.\n", S);
    while (c)
    {
        c -= '0';
        if (c == 1 && !p)
        {
            int s = i - 1;
            int e = s + 1;

            int n0 = 0;
            int n1 = 1;

            while (S[e] && n0 != n1)
            {
                if (S[e ++] - '0')
                    n1 ++;
                else
                    n0 ++;
            }
            e -= 1;

            int as = s;
            int ae = e;

            e = i - 2;
            s = e - 1;

            n0 = 1;
            n1 = 0;

            int bs = s;

            // printf("bs try %d %d %d %d %d.\n", bs, s, e, as, ae);
            while (s >= 0)
            {
                if (S[s --] - '0')
                    n1 ++;
                else
                    n0 ++;

                if (n0 == n1)
                {
                    bs = s + 1;
                    if (s >= 0 && S[s] == '1')
                        break;
                }
            }

            while (bs <= min_s && bs <= as)
            {
                // printf("bs %d as %d ae %d.\n", bs, as, ae);
                if (comp(S, as, ae, bs, as - 1) > 0)
                {
                    if (bs < min_s)
                    {
                        min_s = bs;
                        max_s = as;
                        max_e = ae;
                    }
                    else
                    {
                        if (comp(S, as, ae, max_s, max_e) > 0)
                        {
                            max_s = as;
                            max_e = ae;
                        }
                    }
                }

                s = bs + 1;
                n1 = 1;
                n0 = 0;

                while (n1 != n0)
                {
                    if (S[s ++] - '0')
                        n1 ++;
                    else
                        n0 ++;
                }
                bs = s;
            }
        }

        p = c;
        c = S[i ++];
    }

    if (min_s == INT_MAX)
        return -1;

    /* printf("%s.\n", S); */
    /* printf("min_s %d max_s %d max_e %d.\n", min_s, max_s, max_e); */

    i = 0;
    int si = 0;

    while (d[i])
    {
        if (i == min_s)
            si = max_s;
        else if (si == max_s)
            si = i; // i can be max_e + 1

        //  printf("%d %c %d %c.\n", i, d[i], si, S[si]);

        d[i ++] = S[si ++];

        // must add this line at the end !!!!
        // put it before d = S will cause error !!!!
        if (si == max_e + 1)
            si = min_s;
    }

    return min_s + max_e - max_s + 1;
}

char* makeLargestSpecial(char* S)
{
    char* s = strdup(S);
    char* d = strdup(S);

    while (true)
    {
        int x = mks(s, d);
        if (x == -1)
            return s;
        char* t = s;
        s = d;
        d = t;
        strcpy(d, s);
    }
    return s;
}

/*
void aHeap(char* s, int* heap, int hi, int v)
{
    heap[hi ++] = v;

    int x1 = v >> 8;
    int y1 = v & 0xFF;

    int x = hi - 1;
    while (x)
    {
        int p = (x - 1) / 2;
        int x2 = heap[p] >> 8;
        int y2 = heap[p] & 0xFF;

        if (comp(s, x1, y1, x2, y2) < 0)
            break;

        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

char* makeLargestSpecial(char* S)
{
    int hi = 0;
    int heap[64]= {0};

    int i = 0;
    int p = -1;
    int c = S[i ++];

    int min_s = INT_MAX;
    int last_i = -1;

    while (c)
    {
        c -= '0';
        if (c == 1 && !p)
        {
            last_i = i - 1;
            int e = i - 2;

            int s = e - 1;
            int n0 = 1;
            int n1 = 0;
            while (n0 != n1)
            {
                if (S[s --] - '0')
                    n1 ++;
                else
                    n0 ++;
            }
            s += 1;

            if (s < min_s)
                min_s = s;

            aHeap(S, heap, hi ++, s << 8 | e);
        }
        p = c;
        c = S[i ++];
    }

    if (last_i != -1)
    {
        int n1 = 1;
        int n0 = 0;
        int s = last_i;
        int e = s + 1;

        while (n0 != n1)
        {
            if (S[e ++] - '0')
                n1 ++;
            else
                n0 ++;
        }
        e -= 1;
        aHeap(S, heap, hi ++, s << 8 | e);
    }

    char* n = strdup(S);

    if (!hi)
        return n;

    int st = min_s;

    printf("min_s is %d.\n", min_s);

    while (hi)
    {
        int v = heap[0];
        heap[0] = heap[-- hi];

        int x = 0;
        int nv = heap[0];
        while (x * 2 + 1 < hi)
        {
            int l = heap[x * 2 + 1];
            int r = l;

            if (x * 2 + 2 < hi)
                r = heap[x * 2 + 2];

            if (comp(S, l >> 8, l & 0xFF, r >> 8, r & 0xFF) >= 0)
            {
                if (comp(S, l >> 8, l & 0xFF, nv >> 8, nv & 0xFF) < 0)
                    break;
                heap[x] = l;
                heap[x * 2 + 1] = nv;
                x = x * 2 + 1;
            }
            else
            {
                if (comp(S, r >> 8, r & 0xFF, nv >> 8, nv & 0xFF) < 0)
                    break;
                heap[x] = r;
                heap[x * 2 + 2] = nv;
                x = x * 2 + 2;
            }
        }

        x = v >> 8;
        int y = v & 0xFF;

        printf("get %d %d.\n", x, y);
        for (; x <= y; x ++)
            n[st ++] = S[x];
    }

    while (n[st])
        n[st ++] = '0';
    return n;
}
*/
w
