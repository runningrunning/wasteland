/* careful !!!!! */
/* Stupid error */
void am_sort(int* n, int s, int e, int* id)
{
    if (s >= e)
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
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

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

    am_sort(n, cs, e - 1, id);
    am_sort(n, e + 1, ce, id);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* anagramMappings(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    *returnSize = 0;
    if (!A || !ASize || !B || !BSize || ASize != BSize)
        return NULL;

    *returnSize = ASize;
    int* ret = malloc(sizeof(int) * ASize);

    /*
    int* ai = malloc(sizeof(int) * ASize);
    int* bi = malloc(sizeof(int) * ASize);
    for (int i = 0; i < ASize; i ++)
        ai[i] = bi[i] = i;

    am_sort(A, 0, ASize - 1, ai);
    am_sort(B, 0, BSize - 1, bi);

    for (int i = 0; i < ASize; i ++)
        ret[ai[i]] = bi[i];
    */

    /* ERROR CODE */
    /*
    int* ai = malloc(sizeof(int) * ASize);
    for (int i = 0; i < ASize; i ++)
        ai[i] = i;
    am_sort(A, 0, ASize - 1, ai);

    for (int i = 0; i < ASize; i ++)
    {
        int s = 0;
        int e = ASize - 1;
        int m = 0;
        int b = B[i];
        // When we want to have m, we must set the s <= e
        // if we want to have s or e, we can set it s < e
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (A[m] == b)
                break;

            if (A[m] < b)
                s = m + 1;
            else
                e = m - 1;
        }
        ret[ai[m]] = i;
    }
    */

    int* bi = malloc(sizeof(int) * BSize);
    for (int i = 0; i < BSize; i ++)
        bi[i] = i;
    am_sort(B, 0, BSize - 1, bi);

    for (int i = 0; i < BSize; i ++)
    {
        int a = A[i];

        int s = 0;
        int e = BSize - 1;
        int m = 0;
        // When we want to have m, we must set the s <= e
        // if we want to have s or e, we can set it s < e
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (B[m] == a)
                break;

            if (B[m] < a)
                s = m + 1;
            else
                e = m - 1;
        }
        ret[i] = bi[m];
    }

    return ret;
}
