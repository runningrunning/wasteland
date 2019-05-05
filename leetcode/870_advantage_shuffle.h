// real qsort code !
// how to use qsort to sort id ? sort map by its key ?
void _ac_sort(int* n, int s, int e, int* i)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        if (i)
        {
            t = i[s];
            i[s] = i[e];
            i[e] = t;
        }
    }

    int cs = s;
    int ce = e;

    for (int j = s + 1; j <= e; j ++)
    {
        while (n[j] < n[s]) j ++;
        while (n[e] > n[s]) e --;

        if (j >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            if (i)
            {
                t = i[s];
                i[s] = i[e];
                i[e] = t;
            }
        }
        else
        {
            t = n[j];
            n[j] = n[e];
            n[e] = t;

            if (i)
            {
                t = i[j];
                i[j] = i[e];
                i[e] = t;
            }
        }
    }

    _ac_sort(n, cs, e - 1, i);
    _ac_sort(n, e + 1, ce, i);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    *returnSize = 0;
    if (!A || !ASize || !B || !BSize)
        return NULL;


    *returnSize = ASize;
    int* id = malloc(sizeof(int) * BSize);
    int* ret = malloc(sizeof(int) * BSize);

    for (int i = 0; i < BSize; i ++)
        id[i] = i;

    _ac_sort(A, 0, ASize - 1, NULL);
    _ac_sort(B, 0, BSize - 1, id);

    int ai = 0;
    int bi = 0;
    int be = BSize - 1;

    while (ai < ASize)
    {
        if (A[ai] > B[bi])
        {
            ret[id[bi]] = A[ai];
            bi ++;
        }
        else
        {
            ret[id[be]] = A[ai];
            be --;
        }

        ai ++;
    }

    return ret;
}
