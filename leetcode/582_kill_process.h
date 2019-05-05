/* find sort function which do better when input is almost has sequence */
/* quick sort do worse when input has sequence */
/* FIND BETTER SORT FUNCTION WHEN INPUT IS SORTED!!! */
/* Use Insert Sort or Bubble in already sorted list */

/* QUICK SORT is the WORST when already sorted list */
/* Only a few items => INSERTION SORT */

/* Items are mostly sorted already => INSERTION SORT */

/* Concerned about worst-case scenarios => HEAP SORT */

/* Interested in a good average-case result => QUICKSORT */

/* Items are drawn from a dense universe => BUCKET SORT */

/* Desire to write as little code as possible => INSERTION SORT */

void kp_sort(int* n, int s, int e, int* id)
{
    if (s > e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = id[e];
        id[e] = id[s];
        id[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = id[e];
            id[e] = id[s];
            id[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = id[e];
            id[e] = id[i];
            id[i] = t;
        }
    }

    kp_sort(n, cs, e - 1, id);
    kp_sort(n, e + 1, ce, id);
}

/* Input:  */
/* pid =  [1, 3, 10, 5] */
/* ppid = [3, 0, 5, 3] */
/* kill = 5 */

// same with 760_find_anagram_mappings.h ?

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize)
{
    *returnSize = 0;
    if (!pid || !pidSize || !ppid || !ppidSize || pidSize != ppidSize)
        return NULL;

    bool has_sequence = true;

    /* Cheating here, find better sort method which do better when input is sorted !!!! */
    for (int i = 1; i < pidSize; i ++)
    {
        if (ppid[i] < ppid[i - 1])
        {
            has_sequence = false;
            break;
        }
    }

    if (!has_sequence)
        kp_sort(ppid, 0, ppidSize - 1, pid);
    int* ret = malloc(sizeof(int) * pidSize);

    int en = 0;
    ret[en ++] = kill;

    for (int i = 0; i < en; i ++)
    {
        int kp = ret[i];

        // search in ppid
        int s = 0;
        int e = ppidSize - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (ppid[m] < kp)
                s = m + 1;
            else
                e = m;
        }

        for (int j = s; j < ppidSize; j ++)
        {
            if (ppid[j] != kp)
                break;
            ret[en ++] = pid[j];
        }
    }

    *returnSize = en;
    return ret;
}
