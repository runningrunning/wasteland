/* back tracing if different, NEED ADD MORE OPTIMIZING CODE */
/* The sequence of mt_15 is highly related with the time spend to calculate */
/* Need practice more times !! */
int countArrangement(int N)
{
    int m_1[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, INT_MAX};
    int m_2[]  = {1, 2, 4, 6, 8, 10, 12, 14, INT_MAX};
    int m_3[]  = {1, 3, 6, 9, 12, 15, INT_MAX};
    int m_4[]  = {1, 2, 4, 8, 12, INT_MAX};
    int m_5[]  = {1, 5, 10, 15, INT_MAX};
    int m_6[]  = {1, 2, 3, 6, 12, INT_MAX};
    int m_7[]  = {1, 7, 14, INT_MAX};
    int m_8[]  = {1, 2, 4, 8, INT_MAX};
    int m_9[]  = {1, 3, 9, INT_MAX};
    int m_10[] = {1, 2, 5, 10, INT_MAX};
    int m_11[] = {1, 11, INT_MAX};
    int m_12[] = {1, 2, 3, 4, 6, 12, INT_MAX};
    int m_13[] = {1, 13, INT_MAX};
    int m_14[] = {1, 2, 7, 14, INT_MAX};
    int m_15[] = {1, 3, 5, 15, INT_MAX};

    if (N == 1)
        return 1;

    int* mt_1[]  = {m_1};
    int* mt_2[]  = {m_2, m_1};
    int* mt_3[]  = {m_3, m_2, m_1};
    int* mt_4[]  = {m_4, m_3, m_2, m_1};
    int* mt_5[]  = {m_5, m_4, m_3, m_2, m_1};
    int* mt_6[]  = {m_5, m_6, m_4, m_3, m_2, m_1};
    int* mt_7[]  = {m_7, m_5, m_6, m_4, m_3, m_2, m_1};
    int* mt_8[]  = {m_7, m_8, m_4, m_6, m_5, m_3, m_2, m_1};
    int* mt_9[]  = {m_7, m_8, m_4, m_6, m_5, m_9, m_3, m_2, m_1};
    int* mt_10[] = {m_7, m_8, m_4, m_6, m_5, m_10, m_9, m_3, m_2, m_1};
    int* mt_11[] = {m_11, m_7, m_8, m_4, m_6, m_5, m_10, m_9, m_3, m_2, m_1};
    int* mt_12[] = {m_11, m_7, m_8, m_4, m_6, m_5, m_10, m_9, m_12, m_3, m_2, m_1};
    int* mt_13[] = {m_13, m_11, m_7, m_8, m_4, m_6, m_5, m_10, m_9, m_12, m_3, m_2, m_1};
    int* mt_14[] = {m_13, m_11, m_7, m_14, m_9, m_5, m_10, m_8, m_6, m_12, m_4, m_3, m_2, m_1};
    int* mt_15[] = {m_13, m_11, m_7, m_14, m_9, m_15, m_5, m_10, m_8, m_6, m_12, m_4, m_3, m_2, m_1};
    // int* mt_15[] = {m_1, m_2, m_3, m_4, m_5, m_6, m_7, m_8, m_9, m_10, m_11, m_12, m_13, m_14, m_15};
    int** m[] = { mt_1, mt_2, mt_3, mt_4, mt_5, mt_6, mt_7, mt_8, mt_9, mt_10, mt_11, mt_12, mt_13, mt_14, mt_15 };

    int count = 0;
    int f = 0;
    int flag = 0;

    int** test = m[N - 1];
    int t[20] = {0};
    int cf[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int i = 0;

    while(1)
    {
        flag &= cf[i];

        if (i >= N)
        {
            i --;
            count ++;
            continue;
        }

        int ci = test[i][t[i] ++];

        while(ci <= N)
        {
            f = 1 << ci;
            if (!(flag & f))
            {
                break;
            }

            ci = test[i][t[i] ++];
        }

        if (ci > N)
        {
            if (i == 0)
                break;

            t[i] = 0;
            cf[i] = -1;

            i --;
            continue;
        }
        flag |= f;
        cf[i] = ~f;
        i ++;
    }
    return count;
}
