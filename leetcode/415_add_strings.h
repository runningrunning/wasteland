char* addStrings(char* num1, char* num2)
{
    if (!num1 || !num2)
        return num1 ? num1 : num2;

    int l1 = strlen(num1);
    int l2 = strlen(num2);

    int l;
    char* t = num1;
    // make l1 >= l2
    if (l2 > l1)
    {
        t = num1;
        num1 = num2;
        num2 = t;
        l = l1;
        l1 = l2;
        l2 = l;
    }

    l = l2;

    for (int i = 1; i <= l2; i ++)
        num1[l1 -i] += num2[l2 - i] - '0';

    int c = 0;
    for (int i = 1; i <= l1; i ++)
    {
        int x = num1[l1 - i] + c - '0';
        c = x / 10;
        num1[l1 - i] = '0' + (x % 10);
    }

    if (!c)
        return num1;

    char* r = malloc(l1 + 2);
    r[0] = '1';
    r[l1 + 1] = 0;
    memcpy(r + 1, num1, l1);
    return r;
}

/*
char* addStrings(char* num1, char* num2)
{
    if (!num1 || !num2)
        return num1 ? num1 : num2;

    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int l;

    char* t = num1;
    // make l1 >= l2
    if (l2 > l1)
    {
        t = num1;
        num1 = num2;
        num2 = t;
        l = l1;
        l1 = l2;
        l2 = l;
    }

    l = l2;

    char x;
    int c = 0;
    for (int i = 1; i <= l2; i ++)
    {
        x = num1[l1 - i] + num2[l2 - i] - '0' + c;
        if (x <= '9')
            c = 0;
        else
        {
            c = 1;
            x -= 10;
        }
        num1[l1 - i] = x;
    }

    if (c)
    {
        l2 = l1 - l2;
        for (int i = 1; i <= l2; i ++)
        {
            if (!c)
                break;
            x = num1[l2 - i] + c;
            if (x <= '9')
                c = 0;
            else
            {
                c = 1;
                x -= 10;
            }
            num1[l2 - i] = x;
        }
    }

    char* r = malloc(l1 + 1 + (c ? 1 : 0));
    if (c)
    {
        r[0] = '1';
        memcpy(r + 1, num1, l1);
        r[l1 + 1] = 0;
    }
    else
    {
        memcpy(r, num1, l1);
        r[l1] = 0;
    }
    return r;
}
*/
