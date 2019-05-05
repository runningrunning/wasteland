// better solution ?
// find better solution
// just brute force, it's simple, but need more careful
// segment tree ?
// ideas ?
// just one way, is there any other possible ways ?
// DP ? any ideas ?
// rewrite the function to make it clear

int minKBitFlips(int* A, int ASize, int K)
{
    int ns = 0;
    int num = 0;
    int i = 0;
    for (i = 0; i < ASize; i ++)
    {
        if (A[i] < 0)
        {
            A[i] += 2;
            ns = !ns;
        }
        if (A[i] == ns)
        {
            num ++;
            if (i + K > ASize)
                return -1;
            if (i + K < ASize)
                A[i + K] -= 2;
            ns = !ns;
        }
    }
    return num;

    /* for (; i < ASize; i ++) */
    /* { */
    /*     if (A[i] < 0) */
    /*     { */
    /*         A[i] += 2; */
    /*         ns = !ns; */
    /*     } */
    /*     if (A[i] == ns) */
    /*         return -1; */
    /* } */
    /* while (sa < ASize - K) */
    /* { */
    /*     do */
    /*     { */
    /*         si ++; */
    /*         sa ++; */
    /*         if (s[si % K]) */
    /*         { */
    /*             s[si % K] = 0; */
    /*             ns = !ns; */
    /*         } */
    /*     } while (sa < ASize - K && (A[sa] ^ ns)); */

    /*     if (!(A[sa] ^ ns)) */
    /*     { */
    /*         // printf("sa %d ns %d A[sa] %d.\n", sa, ns, A[sa]); */
    /*         num ++; */
    /*         s[si % K] = 1; */
    /*         ns = !ns; */
    /*     } */
    /* } */

    /* sa ++; */
    /* si ++; */

    /* // printf("sa is %d %d %d\n", sa, ns, num); */
    /* for (; sa < ASize; sa ++) */
    /* { */
    /*     if (s[si % K]) */
    /*     { */
    /*         s[si % K] = 0; */
    /*         ns = !ns; */
    /*     } */

    /*     if (!(A[sa] ^ ns)) */
    /*     { */
    /*         // printf("sa %d v %d ns %d.\n", sa, A[sa], ns); */
    /*         return -1; */
    /*     } */
    /*     si ++; */
    /* } */
    return num;
}
