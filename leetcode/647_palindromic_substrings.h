int countSubstrings(char* s)
{
    int l = strlen(s);
    int all = 0;


    for (int i = 0; i < l; i ++)
    {
        all ++;
        /* try in the middle XA X */
        int a = i - 1;
        int b = i + 1;
        while (a >= 0 && b < l)
        {
            if (s[a] == s[b])
                all ++;
            else
                break;
            a --;
            b ++;
        }
        /* try in the first part XA AX */
        if (i + 1 < l && s[i] == s[i + 1])
        {
            all ++;
            a = i - 1;
            b = i + 2;

            while (a >= 0 && b < l)
            {
                if (s[a] == s[b])
                    all ++;
                else
                    break;
                a --;
                b ++;
            }
        }
    }
    return all;
}
