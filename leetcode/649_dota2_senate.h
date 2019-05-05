char* predictPartyVictory(char* senate)
{
    int rs = 0;
    int ds = 0;

    int i = 0;
    int c = senate[i ++];

    int lr = 0;
    int ld = 0;

    do {
        while (c)
        {
            if (c == 'R')
            {
                if (ds)
                {
                    ds --;
                    senate[i - 1] = 'Z';
                }
                else
                {
                    lr ++;
                    rs ++;
                }
            }
            else if (c == 'D')
            {
                if (rs)
                {
                    rs --;
                    senate[i - 1] = 'Z';
                }
                else
                {
                    ld ++;
                    ds ++;
                }
            }
            c = senate[i ++];
        }

        // printf("%d %d %d %d.\n", lr, ds, ld, rs);
        if (lr <= ds)
            return strdup("Dire");

        if (ld <= rs)
            return strdup("Radiant");

        lr = 0;
        ld = 0;

        i = 0;
        c = senate[i ++];
    } while (true);


    return strdup("Dire");
}
