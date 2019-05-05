/* single 'a' is FALSE, as 'a' has no substring !!! */
bool repeatedSubstringPattern(char* s)
{
    if (!s)
        return false;

    int x = 0;
    int f = 0;
    int i = 0;
    int a = 0;

    while(s[i])
    {
        int v = s[i] - 'a';
        f |= 1 << v;
        a += v;
        x ^= s[i];
        i ++;
    }

    if (i < 2)
        return false;

    if (!(f & (f - 1)))
        return true;

    if (!x)
    {
        i /= 2;
        for (int j = 0; j < i; j++)
            if (s[j] != s[j + i])
                return false;
        return true;
    }

    int t = 3;
    while(t <= i / 2)
    {
        if (!(i % t))
        {
            int ct = i / t;

            int tf = 0;
            int tx = 0;
            int ta = 0;
            for (int j = 0; j < ct; j ++)
            {
                int tv = s[j] - 'a';
                tf |= 1 << tv;
                ta += tv;
                tx ^= s[j];
            }

            if (tx == x && tf == f && ta * t == a)
            {
                int ti = (i + ct) / 2;
                bool found = true;
                for (int j = 0; j < ti; j++)
                    if (s[j] != s[(j + ti) % i])
                    {
                        found = false;
                        break;
                    }

                if (found)
                    return true;
            }
        }
        t += 2;
    }

    return false;
}
