//  1->8 is PASS !!!!!!!!
int _nop(int m, int n, int i, int* t, int p)
{
    if (i > n)
        return 0;

    if (i == n)
        return 1;

    int num = 0;

    if (i == 0)
    {
        t[1] = 1;
        num = 4 * _nop(m, n, i + 1, t, 1);
        t[1] = 0;
        t[2] = 1;
        num += 4 * _nop(m, n, i + 1, t, 2);
        t[2] = 0;
        t[5] = 1;
        num += _nop(m, n, i + 1, t, 5);
    }
    else
    {
        if (i >= m)
            num = 1;

        if (i < n)
        {
            int n11[] = {2, 4, 5, 6, 8};
            int n12[] = {3, 7, 9};
            int b12[] = {2, 4, 5};
            int n13[] = {6, 8};
            int b13[] = {2, 5, 4, 5};

            int n21[] = {1, 3, 4, 5, 6, 7, 9};
            int n22[] = {8};
            int b22[] = {5};
            int n23[] = {7, 9};
            int b23[] = {4, 5, 5, 6};

            int n31[] = {2, 5, 6, 4, 8};
            int n32[] = {1, 7, 9};
            int b32[] = {2, 5, 6};
            int n33[] = {4, 8};
            int b33[] = {2, 5, 5, 6};

            int n41[] = {1, 2, 5, 7, 8, 3, 9};
            int n42[] = {6};
            int b42[] = {5};
            int n43[] = {3, 9};
            int b43[] = {2, 5, 5, 8};

            int n51[] = {1, 2, 3, 4, 6, 7, 8, 9};

            int n61[] = {2, 3, 5, 8, 9, 1, 7};
            int n62[] = {4};
            int b62[] = {5};
            int n63[] = {1, 7};
            int b63[] = {2, 5, 5, 8};

            int n71[] = {4, 5, 8, 2, 6};
            int n72[] = {1, 3, 9};
            int b72[] = {4, 5, 8};
            int n73[] = {2, 6};
            int b73[] = {4, 5, 5, 8};

            int n81[] = {4, 5, 6, 7, 9, 1, 3};
            int n82[] = {2};
            int b82[] = {5};
            int n83[] = {1, 3};
            int b83[] = {4, 5, 5, 6};

            int n91[] = {5, 6, 8, 2, 4};
            int n92[] = {1, 3, 7};
            int b92[] = {5, 6, 8};
            int n93[] = {2, 4};
            int b93[] = {5, 8, 5, 6};

            int* a[] = {
                n11, n12, b12, n13, b13,
                n21, n22, b22, n23, b23,
                n31, n32, b32, n33, b33,
                n41, n42, b42, n43, b43,
                n51, n51, n51, n51, n51,
                n61, n62, b62, n63, b63,
                n71, n72, b72, n73, b73,
                n81, n82, b82, n83, b83,
                n91, n92, b92, n93, b93,
            };

            if (p == 5)
            {
                for (int j = 1; j < 10; j ++)
                {
                    if (j == 5)
                        continue;

                    if (!t[j])
                    {
                        t[j] = 1;
                        num += _nop(m, n, i + 1, t, j);
                        t[j] = 0;
                    }
                }
            }
            else
            {

                int n1 = 5;
                int n2 = 3;
                int n3 = 2;

                if (!(p & 1))
                {
                    n1 = 7;
                    n2 = 1;
                    n3 = 2;
                }

                int si = (p - 1) * 5;
                int* ns = a[si];

                for (int j = 0; j < n1; j ++)
                {
                    int x = ns[j];
                    if (!t[x])
                    {
                        t[x] = 1;
                        num += _nop(m, n, i + 1, t, x);
                        t[x] = 0;
                    }
                }

                ns = a[si + 1];
                int* bs = a[si + 2];
                for (int j = 0; j < n2; j ++)
                {
                    int x = ns[j];
                    int y = bs[j];

                    if (!t[x] && t[y])
                    {
                        t[x] = 1;
                        num += _nop(m, n, i + 1, t, x);
                        t[x] = 0;
                    }
                }

                /* ns = a[si + 3]; */
                /* bs = a[si + 4]; */

                /* for (int j = 0; j < n3; j ++) */
                /* { */
                /*     int x = ns[j]; */
                /*     int y = bs[j * 2]; */
                /*     int z = bs[j * 2 + 1]; */

                /*     if (!t[x] && t[y] && t[z]) */
                /*     { */
                /*         t[x] = 1; */
                /*         num += _nop(m, n, i + 1, t, x); */
                /*         t[x] = 0; */
                /*     } */
                /* } */
            }
        }
    }

    return num;
}

int numberOfPatterns(int m, int n)
{
    if (!m && m == n)
        return 0;

    int t[11] = {0};
    return _nop(m, n, 0, t, 0);
}
