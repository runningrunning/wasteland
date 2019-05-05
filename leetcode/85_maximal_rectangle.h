// find better structure to handle this ?
// why the commented one is failed
// it's too slow !
int maximalRectangle(char** m, int r, int c)
{
    int l = c * c;
    int* s = malloc(sizeof(int) * l);
    memset(s, 0, sizeof(int) * l);

    int x = 0;

    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c;)
        {
            int o = j * c;

            if (m[i][j] == '0')
            {
                for (int z = 0; z < c - j; z ++)
                {
                    s[o + z] = 0;
                }

                for (int y = 0; y < j; y ++)
                    for (int z = j; z < c; z ++)
                        s[y * c + z - y] = 0;
                j ++;
            }
            else
            {
                int e = j;
                for (; e < c; e ++)
                {
                    if (m[i][e] == '0')
                        break;

                    int o = e - j;
                    for (int z = 0; z <= e - j; z ++)
                    {
                        int y = (j + z) * c + o;

                        if (s[y] == 0)
                            s[y] = o + 1;
                        else
                            s[y] += o + 1;

                        if (s[y] > x)
                            x = s[y];

                        o --;
                    }
                }
                j = e;
            }
        }
    }
    return x;
}


/* // find better structure to handle this ? */
/* int maximalRectangle(char** m, int r, int c) */
/* { */
/*     int l = c * (c + 1) / 2; */
/*     int* s = malloc(sizeof(int) * l); */
/*     memset(s, 0, sizeof(int) * l); */

/*     int* st = malloc(sizeof(int) * c); */

/*     int x = 0; */
/*     for (int i = 0; i < c; i ++) */
/*     { */
/*         st[i] = x; */
/*         x += c - i; */
/*     } */

/*     x = 0; */

/*     for (int i = 0; i < r; i ++) */
/*     { */
/*         for (int j = 0; j < c;) */
/*         { */
/*             int o = st[j]; */
/*             printf("o %2d i %d j %d ", o, i, j); */
/*             if (m[i][j] == '0') */
/*             { */
/*                 for (int z = 0; z < c - j; z ++) */
/*                 { */
/*                     s[o + z] = 0; */
/*                 } */

/*                 for (int y = 0; y < j; y ++) */
/*                     for (int z = j; z < c; z ++) */
/*                         s[st[y] + z - y] = 0; */
/*                 j ++; */
/*             } */
/*             else */
/*             { */
/*                 int e = j; */
/*                 for (; e < c; e ++) */
/*                 { */
/*                     if (m[i][e] == '0') */
/*                         break; */

/*                     int o = e - j; */
/*                     for (int z = 0; z <= e - j; z ++) */
/*                     { */
/*                         int y = st[j + z] + o; */

/*                         if (s[y] == 0) */
/*                             s[y] = o + 1; */
/*                         else */
/*                             s[y] += o + 1; */

/*                         if (s[y] > x) */
/*                             x = s[y]; */

/*                         o --; */
/*                     } */
/*                 } */
/*                 j = e; */
/*             } */

/*             out(s, l); */
/*         } */
/*     } */
/*     return x; */
/* } */
