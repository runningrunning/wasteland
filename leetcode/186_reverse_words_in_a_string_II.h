void rw(char* a, int s, int e)
{
    if (s == e)
        return;

    int t = 0;

    while (s < e)
    {
        t = a[s];
        a[s] = a[e];
        a[e] = t;

        s ++;
        e --;
    }
}

void reverseWords(char* str, int strSize)
{
    if (!str || !strSize)
        return;

    rw(str, 0, strSize - 1);

    int pre = 0;
    for (int i = 0; i < strSize; i ++)
    {
        if (str[i] == ' ')
        {
            rw(str, pre, i - 1);
            pre = i + 1;
        }
    }
    rw(str, pre, strSize - 1);
    return;
}
