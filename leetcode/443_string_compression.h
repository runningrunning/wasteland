int compress(char* chars, int charsSize)
{
    if (!charsSize)
        return 0;

    int s = 0;
    int c = 0;
    int pre = chars[0] - 1;
    char t[20] = {0};

    for (int i = 0; i < charsSize; i ++)
    {
        if (pre != chars[i])
        {
            if (c > 1)
            {
                int x = sprintf(t, "%d", c);
                for (int j = 0; j < x; j ++)
                    chars[s ++] = t[j];
            }

            chars[s ++] = chars[i];
            pre = chars[i];
            c = 1;
        }
        else
            c ++;
    }

    if (c > 1)
    {
        int x = sprintf(t, "%d", c);
        for (int j = 0; j < x; j ++)
            chars[s ++] = t[j];
    }
    chars[s] = 0;
    return s;
}
