int try(char* s)
{
    if (s[0] == '0')
        return 0;

    if (!s[1])
        return 1;

    if (s[0] > '2')
        return try(s + 1);

    if (!s[2])
    {
        if (s[1] == '0')
            return 1;

        if (s[0] == '1')
            return 2;

        return s[1] > '6' ? 1 : 2;
    }
    else
    {
        if (s[1] == '0')
            return try(s + 2);

        if (s[1] > '2')
        {
            if (s[0] == '1')
                return 2 * try(s + 2);

            return s[1] > '6' ? try(s + 2) : 2 * try(s + 2);
        }

        return try(s + 1) + try(s + 2);
    }
}

int numDecodings(char* s)
{
    if (!strlen(s))
        return 0;
    return try(s);
}
