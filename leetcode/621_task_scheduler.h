// STUPID WRONG ALGORITHM !!! SAME AS 767. Reorganize String !!!! IT CAN WRAP AROUND !!!!!!!!!! STILL WRONG
// heap ? priority queue ? divide them into equal number ?? find better solution for it.
// use GREEDY method !!
// how to write depth search
void li_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
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
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

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

    li_sort(n, cs, e - 1);
    li_sort(n, e + 1, ce);
}

int leastInterval(char* tasks, int tasksSize, int n)
{
    if (!tasks || !tasksSize)
        return 0;

    if (!n)
        return tasksSize;

    int a[26] = {0};

    for (int i = 0; i < tasksSize; i ++)
        a[tasks[i] - 'A'] ++;

    int all = 0;
    int ai = 0;
    for (int i = 0; i < 26; i ++)
    {
        if (a[i])
        {
            a[ai ++] = a[i];
            all += a[i];
        }
    }

    if (!n)
        return all;

    li_sort(a, 0, ai - 1);

    n ++;

    if (a[ai - 1] > all / n)
    {
        int cn = 0;
        for (int i = ai - 1; i >= 0; i --)
            if (a[i] == a[ai - 1])
                cn ++;
            else
                break;
        return (a[ai - 1] - 1) * n + cn;
    }

    return all;


    /* n ++; */

    /* // heap ? */
    /* int slot[128] = {0}; */
    /* int max = INT_MIN; */

    /* for (int i = 0; i < ai; i ++) */
    /* { */
    /*     slot[0] += a[ai - 1 - i]; */

    /*     int h = 0; */
    /*     int x = slot[0]; */

    /*     if (max < x) */
    /*         max = x; */

    /*     printf("add x %d %d.\n", x, a[ai - 1 - i]); */
    /*     out(slot, 2); */
    /*     while (h < (n / 2)) */
    /*     { */
    /*         int l = slot[2 * h + 1]; */
    /*         int r = (2 * h + 2) < n ? slot[2 * h + 2] : INT_MAX; */

    /*         if (l <= r) */
    /*         { */
    /*             if (l >= x) */
    /*                 break; */

    /*             slot[2 * h + 1] = x; */
    /*             slot[h] = l; */
    /*             h = 2 * h + 1; */
    /*         } */
    /*         else */
    /*         { */
    /*             if (r >= x) */
    /*                 break; */
    /*             slot[2 * h + 2] = x; */
    /*             slot[h] = r; */
    /*             h = 2 * h + 2; */
    /*         } */
    /*     } */
    /* } */

    /* out(slot, 2); */
    /* int cn = 0; */
    /* for (int i = 0; i < n; i ++) */
    /*     if (slot[i] == max) */
    /*         cn ++; */
    /* return (max - 1) * n + cn; */
}
