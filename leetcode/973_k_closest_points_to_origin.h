// speed is too slow, try use binary search to find the proper one !!!!!
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void myqsort(long* n, int s, int e, int k)
{
    if (s >= e)
        return;

    if (n[s] > n[e])
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];
    }


    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            if (s != e)
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];
            }
        }
        else
        {
            n[i] ^= n[e];
            n[e] ^= n[i];
            n[i] ^= n[e];
        }
    }

    myqsort(n, os, e - 1, k);

    if (k > e)
        myqsort(n, e + 1, oe, k);
}

int** kClosest(int** points, int pointsRowSize, int *pointsColSizes, int K, int** columnSizes, int* returnSize)
{
    long* t = malloc(sizeof(long) * pointsRowSize);
    int min_i = 0;
    int min = INT_MAX;

    for (int i = 0; i < pointsRowSize; i ++)
    {
        long d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (d < min)
        {
            min = d;
            min_i = i;
        }

        t[i] = d << 32 | i;
    }

    // printf("%ld %ld %ld.\n", t[0], t[1], t[2]);

    if (K == 1)
        t[0] = min_i;
    else if (K < pointsRowSize)
        myqsort(t, 0, pointsRowSize - 1, K - 1);

    // printf("%ld %ld %ld.\n", t[0], t[1], t[2]);

    int* c = malloc(sizeof(int) * K);
    int** r = malloc(sizeof(int*) * K);

    for (int i = 0; i < K; i ++)
    {
        r[i] = malloc(sizeof(int) * 2);
        int x = t[i] & 0xFFFFFFFF;
        r[i][0] = points[x][0];
        r[i][1] = points[x][1];
        c[i] = 2;
    }
    *columnSizes = c;
    *returnSize = K;
    return r;
}
