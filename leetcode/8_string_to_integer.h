char to_low(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

int myAtoi(char* str)
{
    if (!strlen(str))
        return 0;

    long val = 0;

    int i = 0;
    char c = 0;
    bool has_value = false;
    bool hex = false;
    bool minus = false;

    while (c = to_low(str[i]))
    {
        if (has_value)
        {
            if (c < '0' || c > '9' && (!hex || (c < 'a' || c > 'f')))
                break;

            if (hex)
                val = val * 16 + ((c >= '0' && c <= '9') ? (c - '0') : ((c - 'a')  + 10));
            else
                val = val * 10 + c - '0';

            long temp = minus ? -val : val;

            /* if (temp < INT_MIN || temp > INT_MAX) */
            /*     return 0; */

            if (temp < INT_MIN)
                return INT_MIN;
            if (temp > INT_MAX)
                return INT_MAX;
        }
        else
        {
            if (c == '-' || c == '+')
            {
                char n = to_low(str[i + 1]);
                if (n < '0' || n > '9')
                    break;
                else
                    minus = c == '-';
                i ++;
                continue;
            }
            else if (c < '0' || c > '9')
            {
                if (c == ' ' || c == '\t')
                {
                    i++;
                    continue;
                }
                return 0;
            }
            else if (c == '0')
            {
                if (to_low(str[i + 1]) == 'x')
                {
                    hex = true;
                    i += 2;
                    has_value = true;
                    continue;
                }
                break;
            }
            else
            {
                has_value = true;
                val = c - '0';
            }
        }

        i ++;
    }
    return minus ? -val : val;
}
