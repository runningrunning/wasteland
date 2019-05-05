// dp ! peek hint
// think too complicate
// stupid ME !!!!!!, wrong implement ! STUPID ERROR !!
// more understandable code !!!
// how to convert back length to string
// stupid DP here, be patient
// just find the dp representation !
// same as 753 cracking_the_safe, really? 753 is more about the math
// how to setup the structure of this task ?
// 568_maximum_vacation_days.h
// just 12 so do the full counted, 2^12 !!!, not true

// how to represent DP here
// end with id x and length all others or start with id x ?
char* shortestSuperstring(char** A, int ASize)
{
    int all = 0;
    char* r;
    int* len = malloc(sizeof(int) * ASize);
    int** tab = malloc(sizeof(int*) * ASize);

    for (int i = 0; i < ASize; i ++)
    {
        len[i] = strlen(A[i]);
        all += len[i];
        tab[i] = malloc(sizeof(int) * ASize);
    }

    r = malloc(all);
    r[0] = 0;

    for (int i = 0; i < ASize - 1; i ++)
        for (int j = i + 1; j < ASize; j ++)
        {
            if (i == j)
                tab[i][i] = 0;
            else
            {
                char* a = A[i];
                char* b = A[j];
                int ai = 0;
                int bi = 0;

                int s = len[i] > len[j] ? (len[i] - len[j]) : 0;
                tab[i][j] = 0;
                for (; s < len[i]; s ++)
                    if (!strncmp(a + s, b, len[i] - s))
                    {
                        tab[i][j] = len[i] - s;
                        break;
                    }

                tab[j][i] = 0;
                s = len[j] > len[i] ? (len[j] - len[i]) : 0;
                for (; s < len[j]; s ++)
                    if (!strncmp(a, b + s, len[j] - s))
                    {
                        tab[j][i] = len[j] - s;
                        break;
                    }
            }
        }

    // outaaa(tab, ASize, ASize);

    int l = ASize;
    int num = 1;
    while (l --)
        num <<= 1;

    char** dp = malloc(sizeof(char*) * num);
    for (int i = 0; i < num; i ++)
        dp[i] = calloc(sizeof(char), ASize);

    int ai = 0;
    int bi = 0;
    int* a = malloc(sizeof(int) * num);
    int* b = malloc(sizeof(int) * num);
    char* bits = calloc(sizeof(char), num);

    // only 1
    for (int i = 0; i < ASize; i ++)
    {
        bits[1 << i] = 1;
        a[ai ++] = 1 << i;
    }

    for (int i = 1; i < ASize; i ++)
    {
        for (int j = 0; j < ai; j ++)
        {
            for (int k = 0; k < ASize; k ++)
            {
                if (a[j] & (1 << k))
                    continue;

                int o = a[j];
                int c = o | (1 << k);

                if (!bits[c])
                {
                    // printf("o is %d k is %d, c is %d.\n", o, k, c);
                    b[bi ++] = c;
                    bits[c] = 1;
                }

                int max = dp[c][k];
                for (int l = 0; l < ASize; l ++)
                    if ((o & (1 << l)) && max < dp[o][l] + tab[k][l])
                        max = dp[o][l] + tab[k][l];
                dp[c][k] = max;
            }
        }

        int* t = a;
        a = b;
        b = t;
        ai = bi;
        bi = 0;
    }
    // outa(bits, num);

    /* for (int i = 0; i < num; i ++) */
    /* { */
    /*     printf("%2d: ", i); */
    /*     outa(dp[i], ASize * 2); */
    /* } */

    int* t = malloc(sizeof(int) * ASize);

    int s = 0;
    int e = ASize - 1;

    int n = 0;
    int p = 0;
    int c = num - 1;
    int m = 0;

    for (int i = 0; i < ASize; i ++)
    {
        if (!i)
        {
            p = 0;
            n = dp[c][p];
            for (int j = 1; j < ASize * 2; j ++)
                if (n < dp[c][j])
                {
                    n = dp[c][j];
                    p = j;
                }
        }
        else
        {
                for (int j = 0; j < ASize; j ++)
                    if (n == dp[c][j] + tab[p][j] && !(m & (1 << j)))
                    {
                        p = j;
                        n = dp[c][j];
                        break;
                    }
        }
        t[s ++] = p;
        m |= (1 << p);
        c &= ~(1 << p);
    }
    // out(t, ASize);

    p = 0;
    s = 0;
    for (int i = 0; i < ASize; i ++)
    {
        if (i)
            s -= tab[p][t[i]];
        strcpy(r + s, A[t[i]]);
        s += len[t[i]];
        p = t[i];
    }
    return r;
}
