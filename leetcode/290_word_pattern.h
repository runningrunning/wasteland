/* TODO wrong too much times, careful !!! */
bool wordPattern(char* pattern, char* str)
{
    int lp = strlen(pattern);
    int ls = strlen(str);

    int sa[26] = {0};
    int ea[26] = {0};
    int sv[26] = {0};
    int sx[26] = {0};
    int sp[26] = {0};

    int si = 0;
    int tv = 0;
    int tx = 0;
    int tp = 0;
    for(int i = 0; i < lp; i ++)
    {
        int ci = pattern[i] - 'a';
        if (ea[ci])
        {
            if (si + ea[ci] - sa[ci] > ls)
                return false;

            int s = sa[ci];
            while(s < ea[ci])
            {
                if (str[si] != str[s])
                    return false;
                si ++;
                s ++;
            }
        }
        else
        {
            sa[ci] = si;
            tv = 0;
            tx = 0;
            tp = 0;
            while(str[si] && str[si] != ' ')
            {
                tv += str[si];
                tp |= 1 << (str[si] - 'a');
                tx ^= str[si];
                si ++;
            }

            if (str[si] && (si - sa[ci] == 0))
                return false;
        }

        if (!ea[ci])
        {
            ea[ci] = si;
            sv[ci] = tv;
            sx[ci] = tx;
            sp[ci] = tp;

            for(int i = 0; i < 26; i ++)
            {
                if (i == ci || sv[i] != sv[ci] || sx[i] != sx[ci] || sp[i] != sp[ci])
                    continue;

                if (ea[i] - sa[i] != ea[ci] - sa[ci])
                    continue;

                return false;
            }
        }

        if (!str[si])
            return i == (lp - 1);
        else
        {
            if (str[si] != ' ')
                return false;
            si ++;
        }
    }

    while(str[si])
    {
        if (si != ' ')
            return false;
        si ++;
    }
    return true;
}
