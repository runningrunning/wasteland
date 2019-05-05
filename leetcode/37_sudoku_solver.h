int comp (const void * elem1, const void * elem2)
{
    return  *((int*)elem1) - *((int*)elem2);
}
int count(int n)
{
    int c = 0;
    while(n)
    {
        c ++;
        n &= (n - 1);
    }
    return c;
}

void outa(int* a, int num)
{
    for(int i = 0; i < 9; i ++)
    {
        for(int n = 0; n < 9; n++)
        {
            if (a[i*9+n] > 0x10000)
            {
                int s = 0;
                int l = 1;
                int t = a[i * 9 + n] & 0x1ff;
                char temp[] = {0};
                printf("***%3d ", a[i * 9 + n]&0x1ff);
            }
            else
                printf("%6d ", a[i * 9 + n]);
        }

        printf("\n");
    }
}

void solveSudoku(char** board, int boardRowSize, int boardColisize)
{
    int s = 0;
    int result[81] = {0};
    int solved[81] = {0};
    int nf = 0x1FF;
    int df = 0x10000 | nf;
    int of[11] = {0, ~1, ~2, ~4, ~8, ~16, ~32, ~64, ~128, ~256};
    int tf[512] = {0};
    tf[1] = 1;
    tf[2] = 2;
    tf[4] = 3;
    tf[8] = 4;
    tf[16] = 5;
    tf[32] = 6;
    tf[64] = 7;
    tf[128] = 8;
    tf[256] = 9;

    int n_num = 0;
    int nums[81] = {0};

    for(int i = 0; i < 81; i ++)
    {
        char c = board[i/9][i%9];
        if (c == '.')
            result[i] = df;
        else
        {
            result[i] = c - '0';
            nums[n_num ++] = i;
        }
    }

    for (int n = 0; n < n_num; n ++)
    {
        int i = nums[n];
        int a = i / 9;
        int b = i % 9;
        int f = of[result[i]];
        int qa = (a / 3) * 3;
        int qb = (b / 3) * 3;

        for (int n = 0; n < 9; n ++)
        {
            int ll = a * 9 + n;
            if (result[ll] & 0x10000)
            {
                result[ll] &= f;
                if (tf[result[ll] & nf])
                {
                    result[ll] -= 0x10000;
                    solved[s ++] = ll;
                }
            }

            ll = n * 9 + b;
            if (result[ll] & 0x10000)
            {
                result[ll] &= f;
                if (tf[result[ll] & nf])
                {
                    result[ll] -= 0x10000;
                    solved[s ++] = ll;
                }
            }

            ll = (qa + (n % 3)) * 9 + (n / 3) + qb;
            if (result[ll] & 0x10000)
            {
                result[ll] &= f;
                if (tf[result[ll] & nf])
                {
                    result[ll] -= 0x10000;
                    solved[s ++] = ll;
                }
            }
        }
    }

    do {
        while(s --)
        {
            int i = solved[s];
            solved[s] = 0;
            result[i] = tf[result[i]];

            int a = i / 9;
            int b = i % 9;
            int f = of[result[i]];
            int qa = (a / 3) * 3;
            int qb = (b / 3) * 3;
            for (int n = 0; n < 9; n ++)
            {
                int ll = a * 9 + n;
                if (result[ll] & 0x10000)
                {
                    result[ll] &= f;
                    if (tf[result[ll] & nf])
                    {
                        result[ll] -= 0x10000;
                        solved[s ++] = ll;
                    }
                }

                ll = n * 9 + b;
                if (result[ll] & 0x10000)
                {
                    result[ll] &= f;
                    if (tf[result[ll] & nf])
                    {
                        result[ll] -= 0x10000;
                        solved[s ++] = ll;
                    }
                }

                ll = (qa + (n % 3)) * 9 + (n / 3) + qb;
                if (result[ll] & 0x10000)
                {
                    result[ll] &= f;
                    if (tf[result[ll] & nf])
                    {
                        result[ll] -= 0x10000;
                        solved[s ++] = ll;
                    }
                }
            }
        }

        s = 0;
        for(int i = 0; i < 81; i ++)
        {

            if (result[i] & 0x10000)
            {
                int a = i / 9;
                int b = i % 9;
                int qa = (a / 3) * 3;
                int qb = (b / 3) * 3;

                int lr = result[i];
                int lc = result[i];
                int lq = result[i];
                for (int n = 0; n < 9; n ++)
                {
                    int ll = a * 9 + n;
                    if (ll != i && lr && (result[ll] & 0x10000))
                        lr &= ~ result[ll];

                    ll = n * 9 + b;
                    if (ll != i && lc && (result[ll] & 0x10000))
                        lc &= ~ result[ll];

                    ll = (qa + (n % 3)) * 9 + (n / 3) + qb;
                    if (ll != i && lq && (result[ll] & 0x10000))
                        lq &= ~ result[ll];

                    if (!lr && !lc && !lq)
                        break;
                }

                if (lr && tf[lr])
                {
                    result[i] = 0x10000 | lr;
                    solved[s ++] = i;
                }
                else if (lc && tf[lc])
                {
                    result[i] = 0x10000 | lc;
                    solved[s ++] = i;
                }
                else if (lq && tf[lq])
                {
                    result[i] = 0x10000 | lq;
                    solved[s ++] = i;
                }
            }
        }

        for(int i = 0; i < s; i ++)
        {
            result[solved[i]] -= 0x10000;
        }
    } while(s);

    int g = 0;
    int guess[81] = {0};
    int g_result[81] = {0};
    for(int i = 0; i < 81; i ++)
    {

        if (result[i] & 0x10000)
        {
            guess[g ++] = (count(result[i] - 0x10000) << 16) | i;
            g_result[i] = result[i];
        }
    }

    s = 0;
    // guess part
    if (g)
    {
        int* stack_result[81] = {0};
        int si = 0;
        int stack[81] = {0};

        qsort (guess, g, sizeof(int), comp);
        stack_result[si] = malloc(sizeof(int) * 81);
        memcpy(stack_result[si], g_result, sizeof(int) * 81);

        //outa(g_result, 81);

        int left = g;
        int start_gi = 0;
        int start_l = 0;
        int t_result[81] = {0};

        bool failed = false;

        for (int gi = start_gi;  gi < g - 1; gi ++)
        {
            int l = 0;
            int n = 0;
            if (failed)
            {
                do
                {
                    int stack_s = stack[si];
                    gi = stack_s & 0xFF;
                    l = stack_s >> 16;
                    left = (stack_s >> 8) & 0xFF;
                    n = guess[gi] & 0xFFFF;
                    int ts = stack_result[si][n];
                    if ((ts - 0x10000) >= (1 << l))
                    {
                        failed = false;
                        memcpy(t_result, stack_result[si], sizeof(int) * 81);
                        while(!(t_result[n] & (1 << l)))
                            l ++;
                        stack[si] = (left << 8) |((l + 1) << 16) | gi;
                        //outa(t_result, 81);
                        //printf("failed try si %d.\n", si);
                        break;
                    }
                    //printf("do failed.\n");
                } while(si --);
            }
            else
            {
                n = guess[gi] & 0xFFFF;

                if (gi == start_gi)
                {
                    memcpy(t_result, stack_result[si], sizeof(int) * 81);
                    l = start_l;
                    while(!(t_result[n] & (1 << l)))
                        l ++;
                    stack[si] = ((left) << 8) | ((l + 1) << 16) | gi;
                    //outa(t_result, 81);
                    //printf("start try si %d.\n", si);
                }
                else
                {
                    if (!(t_result[n] & 0x10000))
                        continue;

                    l = 0;
                    while(!(t_result[n] & (1 << l)))
                        l ++;
                    stack[++ si] = (left << 8) | ((l + 1) << 16) | gi;
                    stack_result[si] = malloc(sizeof(int) * 81);
                    memcpy(stack_result[si], t_result, sizeof(int) * 81);
                    //outa(t_result, 81);
                    //printf("guess try si %d.\n", si);
                }
            }

            s = 0;
            t_result[n] = l + 1;
            //printf("guess %d is %d.\n.\n", n, l + 1);
            solved[s ++] = n;

            while (s --)
            {
                int i = solved[s];
                int a = i / 9;
                int b = i % 9;
                int f = of[t_result[i]];
                int qa = (a / 3) * 3;
                int qb = (b / 3) * 3;
                left --;
                for (int vi = gi + 1; vi < g; vi ++)
                {
                    int ti = guess[vi] & 0xFFFF;

                    int ta = ti / 9;
                    int tb = ti % 9;
                    if (ti / 9 == a)
                    {
                        if ((t_result[ti] & 0x10000))
                        {
                            t_result[ti] &= f;
                            if (tf[t_result[ti] & nf])
                            {
                                solved[s++] = ti;
                                t_result[ti] = tf[t_result[ti] & nf];
                            }
                        }
                        else if (ti != i)
                        {
                            if (t_result[ti] == t_result[i])
                            {
                                //printf("ERROR %d %d is same %d.\n", ti, i, t_result[i]);
                                failed = true;
                            }
                        }
                    }
                    else if ((ti % 9) == b)
                    {
                        if ((t_result[ti] & 0x10000))
                        {
                            t_result[ti] &= f;
                            if (tf[t_result[ti] & nf])
                            {
                                solved[s++] = ti;
                                t_result[ti] = tf[t_result[ti] & nf];
                            }
                        }
                        else if (ti != i)
                        {
                            if (t_result[ti] == t_result[i])
                            {
                                //printf("ERROR %d %d is same %d.\n", ti, i, t_result[i]);
                                failed = true;
                            }
                        }
                    }
                    else if (ta > qa && ta < qa + 3 && tb > qb && tb < qb + 3)
                    {
                        if ((t_result[ti] & 0x10000))
                        {
                            t_result[ti] &= f;
                            if (tf[t_result[ti] & nf])
                            {
                                solved[s++] = ti;
                                t_result[ti] = tf[t_result[ti] & nf];
                            }
                        }
                        else if (ti != i)
                        {
                            if (t_result[ti] == t_result[i])
                            {
                                //printf("ERROR %d %d is same %d.\n", ti, i, t_result[i]);
                                failed = true;
                            }

                        }
                    }
                    if (failed)
                        break;
                }
                if (failed)
                    break;
            }

            s = 0;
            /* printf("======== %d ==========\n", left); */
            /* outa(t_result, 81); */
            /* printf("================ %d\n\n", getchar()); */

            if (!failed && !left)
            {
                for (int i = 0; i < 81; i ++)
                {
                    if (t_result[i])
                        result[i] = t_result[i];
                }
                break;
            }
        }
    }
    for(int i = 0; i < 81; i ++)
        board[i/9][i%9] = (char)('0' + result[i]);
}
