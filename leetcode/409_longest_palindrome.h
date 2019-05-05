int longestPalindrome(char* s)
{
    int l;
    int n = 0;
    int a[256] = {0};
    char x;
    int i = 0;
    while(x = s[i])
    {
        l ++;
        if (!a[x])
            a[x] = 1;
        else
        {
            n ++;
            a[x] = 0;
        }
        i ++;
    }
    n *= 2;
    return n + (n == l ? 0 : 1);
}
