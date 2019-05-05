// find better code
char* pushDominoes(char* dominoes)
{
    int ps = 0;
    int l = strlen(dominoes);

    for (int i = 0; i < l; i ++)
    {
        if (dominoes[i] != '.')
            continue;

        int pre = i - 1;
        while (i < l && dominoes[i] == '.')
            i ++;

        if (i == l)
        {
            if (pre != -1 && dominoes[pre] == 'R')
                for (; pre < l; pre ++)
                    dominoes[pre] = 'R';
            return dominoes;
        }

        if (dominoes[i] == 'R' && (pre == -1 || dominoes[pre] == 'L'))
            continue;

        int s = pre + 1;
        int e = i - 1;

        if (dominoes[i] == 'L')
        {
            if (pre != -1 && dominoes[pre] == 'R')
            {
                while (s < e)
                {
                    dominoes[s ++] = 'R';
                    dominoes[e --] = 'L';
                }
            }
            else
            {
                while (s <= e)
                    dominoes[s ++] = 'L';
            }
        }
        else if (pre != -1 && dominoes[pre] == 'R')
        {
            while (s <= e)
                dominoes[s ++] = 'R';
        }
    }
    return dominoes;
}

/* char* pushDominoes(char* dominoes) */
/* { */
/*     int ps = 0; */
/*     int pre = -1; */

/*     int first = -1; */
/*     int last = -1; */

/*     int l = strlen(dominoes); */
/*     for (int i = 0; i < l; i ++) */
/*     { */
/*         if (dominoes[i] == '.') */
/*             ps ++; */
/*         else */
/*         { */
/*             if (first == -1) */
/*                 first = i; */

/*             last = i; */

/*             if (pre != -1 && pre != i - 1) */
/*             { */
/*                 int s = pre + 1; */
/*                 int e = i - 1; */

/*                 if (dominoes[pre] == 'R') */
/*                 { */
/*                     if (dominoes[i] == 'L') */
/*                     { */
/*                         while (s < e) */
/*                         { */
/*                             dominoes[s ++] = 'R'; */
/*                             dominoes[e --] = 'L'; */
/*                         } */
/*                     } */
/*                     else */
/*                     { */
/*                         while (s <= e) */
/*                             dominoes[s ++] = 'R'; */
/*                     } */
/*                 } */
/*                 else if (dominoes[i] == 'L') */
/*                 { */
/*                     while (s <= e) */
/*                         dominoes[s ++] = 'L'; */
/*                 } */
/*             } */
/*             pre = i; */
/*             ps = 0; */
/*         } */
/*     } */

/*     if (dominoes[first] == 'L') */
/*         for (int i = 0; i < first; i ++) */
/*             dominoes[i] = 'L'; */

/*     if (dominoes[last] == 'R') */
/*         for (int i = last + 1; i < l; i ++) */
/*             dominoes[i] = 'R'; */

/*     return dominoes; */
/* } */
