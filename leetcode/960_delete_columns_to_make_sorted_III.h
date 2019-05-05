// simple DP, just need to find way to code it 
// not simple dp ????
// how to solve ? dp ?
// how to solve this as dp
// it's easy to get one dp, but how for all of them ?
// 100 dp here ?
// n * n DP ?
// n index can be in the used nth index

int minDeletionSize(char** A, int ASize)
{
    if (!A || !ASize || !A[0])
        return 0;

    int n = 0;
    int l = strlen(A[0]);
    int* of = calloc(sizeof(int), 128);
    of[0] = 1;
    n = 1;

    for (int i = 1; i < l; i ++)
    {
        of[i] = 1;
        for (int j = i - 1; j >= 0; j --)
        {
            bool add = true;
            for (int k = 0; k < ASize; k ++)
                if (A[k][i] < A[k][j])
                {
                    add = false;
                    break;
                }

            if (add)
            {
                if (of[i] < of[j] + 1)
                    of[i] = of[j] + 1;
                if (of[i] > n)
                    n = of[i];
            }
        }
    }
    return l - n;
}

/* int minDeletionSize(char** A, int ASize) */
/* { */
/*     if (!A || !ASize || !A[0]) */
/*         return 0; */

/*     int n = 0; */
/*     int l = strlen(A[0]); */
/*     int* of = calloc(sizeof(int), 128 * 128); */

/*     for (int j = 0; j < ASize; j ++) */
/*         of[(j << 7) + 0] = A[j][0]; */
/*     n = 1; */

/*     for (int i = 1; i < l; i ++) */
/*     { */
/*         // add to the last ? */
/*         int on = n; */
/*         bool update = true; */
/*         for (int j = 0; j < ASize; j ++) */
/*             if (A[j][i] < of[(j << 7) + n - 1]) */
/*             { */
/*                 update = false; */
/*                 break; */
/*             } */

/*         if (update) */
/*         { */
/*             for (int j = 0; j < ASize; j ++) */
/*                 of[(j << 7) + n] = A[j][i]; */
/*             n ++; */
/*         } */

/*         for (int k = on - 1; k >= 0; k --) */
/*         { */
/*             update = true; */
/*             for (int j = 0; j < ASize; j ++) */
/*                 if (A[j][i] > of[(j << 7) + k]) */
/*                 { */
/*                     update = false; */
/*                     break; */
/*                 } */

/*             if (update) */
/*             { */
/*                 // printf("%c %c %c.\n", A[0][i], of[k + 1], of[k]); */
/*                 for (int j = 0; j < ASize; j ++) */
/*                     of[(j << 7) + k] = A[j][i]; */
/*             } */
/*         } */
/*         // printf("== %c %c %c %c.\n", of[0], of[1], of[2], of[3]); */
/*     } */

/*     // printf("n is %d\n", n); */
/*     return l - n; */
/* } */
