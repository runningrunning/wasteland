// not always positive number, can not use binary search here.
bool canThreePartsEqualSum(int* A, int ASize)
{
    int all = 0;
    for (int i = 0; i < ASize; i ++)
        all += A[i];
    if (all % 3)
        return false;

    int x = all / 3;
    all = 0;
    int found1 = -1;
    for (int i = 0; i < ASize; i ++)
    {
        all += A[i];
        if (x == all)
        {
            found1 = i;
            break;
        }
    }

    if (found1 == -1 || found1 >= ASize - 2)
        return false;

    all = 0;
    int found2 = -1;
    for (int i = ASize - 1; i > found1; i --)
    {
        all += A[i];
        if (x == all)
        {
            found2 = i;
            break;
        }
    }
    return found2 != -1 && found1 < found2;
}

/* bool canThreePartsEqualSum(int* A, int ASize) */
/* { */
/*     for (int i = 1; i < ASize; i ++) */
/*         A[i] += A[i - 1]; */
/*     if (A[ASize - 1] % 3) */
/*         return false; */

/*     int x = A[ASize - 1] / 3; */
/*     int s = 0; */
/*     int e = ASize - 1; */
/*     while (s < e) */
/*     { */
/*         int m = (s + e) / 2; */
/*         if (A[m] < x) */
/*             s = m + 1; */
/*         else */
/*             e = m; */
/*     } */

/*     if (A[s] != x) */
/*         return false; */

/*     s = s + 1; */
/*     e = ASize - 1; */
/*     x = x * 2; */
/*     while (s < e) */
/*     { */
/*         int m = (s + e) / 2; */
/*         if (A[m] < x) */
/*             s = m + 1; */
/*         else */
/*             e = m; */
/*     } */
/*     if (A[s] != x) */
/*         return false; */

/*     return true; */
/* } */
