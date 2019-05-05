// ERROR: return bool can NOT be treated as int
// be careful
// in leetcode bool is bool
// how to implement this in c, code structure
// complicate, do more !
// just write the code
// find better way to construct this application

int read_cdata(char* c, int s, int e)
{
    if (e - s < 12)
        return false;

    if (strncmp(c + s, "<![CDATA[", 9))
        return false;

    int os = s;

    s += 9;

    while (s < e - 2)
    {
        if (c[s] == ']')
        {
            if (c[s + 1] == ']' && c[s + 2] == '>')
                return s + 2 - os + 1;
        }
        s ++;
    }
    return false;
}

int read_tag(char* c, int s, int e)
{
    int os = s;
    bool reverse = false;
    if (c[s + 1] == '/')
    {
        s ++;
        reverse = true;
    }

    while (s < e && c[s] != '>')
        s ++;

    if (s == e)
        return 0;

    return reverse ?  - (s - os + 1)
        : (s - os + 1);
}

bool verify_tag(char* c, int s, int e)
{
    if (e < 3 || e > 11)
        return false;

    for (int i = s + 1; i < s + e  - 1; i ++)
    {
        if (c[i] < 'A' || c[i] > 'Z')
            return false;
    }
    return true;
}

bool verify_tags(char* c, int s1, int e1, int s2, int e2)
{
    if (e2 != e1 + 1)
        return false;
    return !strncmp(c + s1 + 1, c + s2 + 2, e1 - 2);
}

bool isValid(char* code)
{
    if (!code)
        return false;

    int l = strlen(code);
    if (l < 7)
        return false;

    if (code[0] != '<' || code[l - 1] != '>')
        return false;

    int ti = 0;
    int ts = 1024;
    long* tags = malloc(sizeof(long) * ts);

    long ci = 0;
    while (code[ci])
    {
        int n = 1;

        if (code[ci] == '<')
        {
            if (code[ci + 1] == '!')
            {
                if (!ti)
                    return false;

                n = read_cdata(code, ci, l);

                if (!n)
                    return false;
            }
            else
            {
                n = read_tag(code, ci, l);

                if (!n)
                    return false;

                if (n < 0)
                {
                    n = - n;

                    if (!verify_tags(code, tags[ti - 1] >> 32, tags[ti - 1] & 0xFFFFFFFF, ci, n))
                        return false;

                    ti --;
                    // should be end
                    if (!ti && code[ci + n])
                        return false;
                }
                else
                {
                    if (!verify_tag(code, ci, n))
                        return false;

                    if (ti + 1 == ts)
                    {
                        ts += 1024;
                        tags = realloc(tags, sizeof(long) * ts);
                    }
                    tags[ti ++] = ci << 32 | n;
                }
            }
        }
        ci += n;
    }
    return !ti;
}
