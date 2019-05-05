// "1e10"
// "0xabc"
// "1.23e10"
// "1e10"
// "1e-10"
// "1e+10"
// "-1.23e-10"
// "-0x10"
// "+0x10" is wrong
// "1.e10"
// "1.e-10"
// ".e10"
// "-.e10"
// "-0.e10"
// "4e+" false // + at the last are wrong !
// "+.8" true ??? // + at the first is correct !
// "1/3" ???

bool isNumber(char* s)
{
    if (!s)
        return false;

    int i = 0;
    int l = strlen(s);

    char c = s[i ++];
    // remove ' ' at the front
    while (c == ' ')
        c = s[i ++];

    if (!c)
        return 0;

    int _s = i - 1;

    int _e = l - 1;
    c = s[_e --];
    // remove ' ' at the end
    while (c == ' ')
        c = s[_e --];
    _e ++;

    if (s[_s] == '-' || s[_s] == '+')
        _s ++;

    if (_s == _e)
        return s[_s] >= '0' && s[_s] <= '9';

    // 0xABCDEF
    if (s[_s] == '0' && (s[_s + 1] == 'x'
                         || s[_s + 1] == 'X'))
    {
        if (_s + 1 == _e)
            return false;

        for (int i = _s + 2; i <= _e; i ++)
        {
            c = s[i];
            if (!((c >= '0' && c <= '9') ||
                  (c >= 'a' && c <= 'f') ||
                  (c >= 'A' && c <= 'F')))
                return false;
        }
        return true;
    }

    int num_of_dot = 0;
    int num_of_number = 0;

    if (s[_s] == '.')
    {
        num_of_dot ++;
        _s ++;
    }

    for (i = _s; i <= _e; i ++)
    {
        c = s[i];
        if (c >= '0' && c <= '9')
            num_of_number ++;
        else if (c == '.')
        {
            if (num_of_dot)
                return false;
            num_of_dot ++;
        }
        else if (c == 'e' || c == 'E')
        {
            if (!num_of_number)
                return false;
            break;
        }
        else
            return false;
    }

    if (i > _e)
        return true;

    if (s[i] == 'e' || s[i] == 'E')
    {
        if (i == _e)
            return false;

        i ++;

        if (s[i] == '+' || s[i] == '-')
            i ++;

        if (i > _e)
            return false;

        for (; i <= _e; i ++)
        {
            c = s[i];
            if (!(c >= '0' && c <= '9'))
                return false;
        }
    }

    return i > _e;
}
