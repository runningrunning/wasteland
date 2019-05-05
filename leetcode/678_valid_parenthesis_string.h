// how can it pass, and why does it pass ?
bool checkValidString(char* s)
{
    int l = strlen(s);

    int p_ll = 0;
    int p_ls = 0;
    int p_rr = 0;
    int p_rs = 0;

    /* int l_l[128]; */
    /* int l_s[128]; */
    /* int r_r[128]; */
    /* int r_s[128]; */

    for (int i = 0; i < l; i ++)
    {
        int x = s[i];

        /* l_l[i] = p_ll; */
        /* l_s[i] = p_ls; */

        if (x == '(')
        {
            p_ll ++;
            // l_l[i] ++;
        }
        else if (x == '*')
        {
            p_ls ++;
            // l_s[i] ++;
        }
        else
        {
            p_ll --;
            if (p_ll + p_ls < 0)
                return false;
            /* l_l[i] --; */
            /* if (l_l[i] + l_s[i] < 0) */
            /*     return false; */
        }

        x = s[l - 1 - i];
        /* r_r[i] = p_rr; */
        /* r_s[i] = p_rs; */

        if (x == ')')
        {
            p_rr ++;
            // r_r[i] ++;
        }
        else if (x == '*')
        {
            p_rs ++;
            // r_s[i] ++;
        }
        else
        {
            p_rr --;
            // r_r[i] --;
            /* if (r_r[i] + r_s[i] < 0) */
            /*     return false; */
            if (p_rr + p_rs < 0)
                return false;
        }
    }

    /* if (abs(l_l[l - 1]) > abs(l_s[l - 1])) */
    /*     return false; */

    /* for (int i = 0; i < l - 1; i ++) */
    /* { */
    /*     int ll = l_l[i]; */
    /*     int ls = l_s[i]; */
    /*     int rr = r_r[l - 2 - i]; */
    /*     int rs = r_s[l - 2 - i]; */

    /*     if (ll != rr) */
    /*     { */
    /*         if (ll > ls + rs + rr) */
    /*             return false; */

    /*         if (rr > ls + rs + ll) */
    /*             return false; */
    /*     } */
    /* } */
    return true;
}
