// HOW TO PROVE GREEDY IS CORRECT ?
// HEAP + GREEDY !!!! TYPO ERROR !!!!
// !! similar AS 767. Reorganize String !!!! IT CAN WRAP AROUND !!!!!!!!!!
// and 621 task_scheduler.h
// TO MANY FAILED, how to prove it works !!!!!!!!!!!!!!!!!!!!!!!!  JUST NOT TRUE LIKE 767, how to prove it !!
void rs_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] < n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i++)
    {
        while (n[i] > n[s]) i ++;
        while (n[e] < n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    rs_sort(n, cs, e - 1);
    rs_sort(n, e + 1, ce);
}

void aHeap(int* heap, int hi, int v)
{
    heap[hi ++] = v;

    int x = hi - 1;

    while (x)
    {
        int p = (x - 1) / 2;
        if (heap[p] >= heap[x])
            break;
        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

int rHeap(int* heap, int hi)
{
    int t = heap[0];
    hi --;

    heap[0] = heap[hi];

    int x = 0;
    int v = heap[0];

    while (x * 2 + 1 < hi)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l >= r)
        {
            if (v >= l)
                break;

            heap[x * 2 + 1] = v;
            heap[x] = l;
            x = x * 2 + 1;
        }
        else
        {
            if (v >= r)
                break;
            heap[x * 2 + 2] = v;
            heap[x] = r;
            x = x * 2 + 2;
        }
    }

    return t;
}

char* rearrangeString(char* s, int k)
{
    if (k <= 1)
        return strdup(s);

    int l = 0;
    int a[26] = {0};

    int max = 0;
    char c = s[l ++];

    while (c)
    {
        a[c - 'a'] ++;

        if (a[c - 'a'] > max)
            max = a[c - 'a'];
        c = s[l ++];
    }

    /* be careful about the l, it should be the last character */
    l -= 1;

    if (max <= 1)
        return strdup(s);

    char* t = malloc(l);
    t[l] = 0;

    // try to use heap + GREEDY
    int hi = 0;
    int* heap = malloc(sizeof(int) * 26);

    int index[26] = {0};
    for (int i = 0; i < 26; i ++)
    {
        if (a[i])
            aHeap(heap, hi ++, a[i] << 8 | i);
        index[i] = -1;
    }

    int ti = 0;
    int temp[26] = {0};

    for (int i = 0; i < l; i ++)
    {
        ti = 0;
        int x = -1;
        int xi = -1;

        while (true && hi)
        {
            x = rHeap(heap, hi --);
            xi = x & 0xFF;
            temp[ti ++] = x;

            if (index[xi] == -1 || i - index[xi] >= k)
            {
                temp[ti - 1] -= 1 << 8;
                break;
            }
        }
        if (index[xi] != -1 && i - index[xi] < k)
            return "";

        index[xi] = i;
        t[i] = xi + 'a';

        for (int j = 0; j < ti; j ++)
        {
            if (temp[j] & 0xFFFFFF00)
                aHeap(heap, hi ++, temp[j]);
        }
    }

    return t;


    /* for (int i = 0; i < 26; i ++) */
    /*     if (a[i]) */
    /*         a[i] = (a[i] << 8) | i; */

    /* rs_sort(a, 0, 25); */

    /* if (max > l / k) */
    /* { */
    /*     int cn = 0; */
    /*     for (int i = 0; i < 26; i ++) */
    /*         if (a[i] >= max << 8) */
    /*             cn ++; */
    /*         else */
    /*             break; */

    /*     if ((max - 1) * k + cn > l) */
    /*         return ""; */
    /* } */

    /* char* t = malloc(l + 1); */
    /* t[l] = 0; */

    /* int in = 0; */
    /* int p = 0; */

    /* for (int i = 0; i < 26; i ++) */
    /* { */
    /*     if (!a[i]) */
    /*         break; */

    /*     int n = a[i] >> 8; */
    /*     int s = a[i] & 0xFF; */

    /*     for (int j = 0; j < n; j ++) */
    /*     { */
    /*         t[in] = s + 'a'; */
    /*         in += k; */
    /*         if (in >= l) */
    /*             in = ++ p; */
    /*     } */
    /* } */

    // wrong code 1
    /* int* slot = malloc(sizeof(int) * k); */
    /* for (int i = 0; i < k; i ++) */
    /*     slot[i] = i; */

    /* int sl = 0; */
    /* for (int i = 0; i < 26; i ++) */
    /* { */
    /*     if (!a[i]) */
    /*         break; */
    /*     int n = a[i] >> 8; */
    /*     int s = a[i] & 0xFF; */

    /*     while (n) */
    /*     { */
    /*         int st = slot[sl % k]; */
    /*         if (st < l) */
    /*         { */
    /*             while (n) */
    /*             { */
    /*                 n --; */
    /*                 t[st] = s + 'a'; */
    /*                 st += k; */
    /*                 if (st >= l) */
    /*                     break; */
    /*             } */
    /*             slot[sl % k] = st; */
    /*         } */
    /*         sl ++; */
    /*     } */
    /* } */


    // wrong code 2
    /* int in = 0; */
    /* int p = 0; */

    /* for (int i = 0; i < 26; i ++) */
    /* { */
    /*     if (!a[i]) */
    /*         break; */

    /*     int n = a[i] >> 8; */
    /*     int s = a[i] & 0xFF; */

    /*     for (int j = 0; j < n; j ++) */
    /*     { */
    /*         t[in] = s + 'a'; */

    /*         in += k; */
    /*         if (in >= l) */
    /*             in = ++ p; */
    /*     } */
    /* } */

    return t;
}
