// qsort_r

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
int comp(const void* a, const void* b, void* s)
{
    int* seq = s;
    int ia = *((int*)a);
    int ib = *((int*)b);
    if (seq[ia] || seq[ib])
    {
        if (seq[ia] && seq[ib])
            return seq[ia] - seq[ib];
        return seq[ia] ? -1 : 1;
    }
    return ia - ib;
}
*/

int comp(int* n, int a, int b, int* seq)
{
    int ia = n[a];
    int ib = n[b];

    if (seq[ia] || seq[ib])
    {
        if (seq[ia] && seq[ib])
            return seq[ia] - seq[ib];
        return seq[ia] ? -1 : 1;
    }
    return ia - ib;
}
void my_qsort(int* n, int s, int e, int* seqs)
{
    if (s >= e)
        return;

    if (comp(n, s, e, seqs) > 0)
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];
    }

    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (comp(n, i, s, seqs) < 0) i ++;
        while (comp(n, e, s, seqs) > 0) e --;

        if (i >= e)
        {
            if (n[s] != n[e])
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];
            }
        }
        else
        {
            if (n[i] != n[e])
            {
                n[i] ^= n[e];
                n[e] ^= n[i];
                n[i] ^= n[e];
            }
        }
    }

    my_qsort(n, os, e - 1, seqs);
    my_qsort(n, e + 1, oe, seqs);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int seqs[1024] = {0};

    for (int i = 0; i < arr2Size; i ++)
        seqs[arr2[i]] = i + 1;

    // qsort_r(arr1, arr1Size, sizeof(int), comp, seqs);
    my_qsort(arr1, 0, arr1Size - 1, seqs);
    *returnSize = arr1Size;
    return arr1;
}
