/* Alphanumeric */ is ALPHA + NUMERIC
char Alpha(char a)
{
    if (a <= 'z' && a >= 'a')
        return a;
    if (a <= 'Z' && a >= 'A')
        return a - 'A' + 'a';

    if (a <= '9' && a >= '0')
        return a;
    return 0;
}

bool isPalindrome(char* s)
{
    int l = strlen(s);
    if (l <= 1)
        return true;

    for(int i = 0, j = l - 1; i < j; i ++, j --)
    {
        while(i < j && !Alpha(s[i]))
            i ++;
        char ia = Alpha(s[i]);

        while(j > i && !Alpha(s[j]))
            j --;
        char ja = Alpha(s[j]);

        if (i == j)
            return true;

        if (ia != ja)
            return false;
    }
    return true;
}
