// be careful about corner cases
// 2001:0db8:85a3:033:0:8A2E:0370:7334 is OK
char* validIPAddress(char* IP) {
    int l = strlen(IP);

    if (l < 7)
        return "Neither";

    bool is6 = false;
    bool is4 = false;

    for (int i = 0; i < 5; i ++)
        if (IP[i] == ':')
            is6 = true;
        else if (IP[i] == '.')
            is4 = true;

    bool error = !is4 && !is6;

    int i = 0;
    int s = 0;
    int e = s;

    if (is4 != is6)
    {
        if (is4)
        {
            is4 = false;

            for (; i < 4; i ++)
            {
                int n = 0;

                if (!IP[e])
                {
                    error = true;
                    break;
                }

                while (IP[e] && IP[e] != '.')
                {
                    char c = IP[e];

                    if (c < '0' || c > '9')
                    {
                        error = true;
                        break;
                    }

                    n = n * 10 + c - '0';
                    e ++;
                }

                if (e == s)
                    error = true;

                if (!error)
                {
                    if (n > 255)
                        error = true;
                    else if (n && IP[s] == '0')
                        error = true;
                    else if (!n && e - s != 1)
                        error = true;
                }

                if (error)
                    break;

                if (i != 3 && IP[e])
                {
                    s = e + 1;
                    e = s;
                }
            }

            if (!IP[e])
                is4 = true;
            else
                error = true;
        }
        else
        {
            is6 = false;
            if (l >= 15)
            {
                for (; i < 8; i ++)
                {
                    if (!IP[e])
                    {
                        error = true;
                        break;
                    }

                    while (IP[e] && IP[e] != ':')
                    {
                        char c = IP[e];

                        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                        {
                            error = true;
                            break;
                        }
                        e ++;
                    }

                    if (e == s)
                        error = true;

                    if (!error)
                    {
                        int fl = e - s;
                        if (fl > 4)
                            error = true;
                        /* else if (fl < 4) */
                        /*     if (IP[s] == '0' && fl != 1) */
                        /*         error = true; */
                    }

                    if (error)
                        break;

                    if (i != 7 && IP[e])
                    {
                        s = e + 1;
                        e = s;
                    }
                }

                if (!IP[e])
                    is6 = true;
                else
                    error = true;
            }
            else
                error = true;
        }
    }

    if (error)
        return "Neither";

    return is4 ? "IPv4" : "IPv6";
}
