bool canPermutePalindrome(char* s)
{
    int a[256] = {0};
    int all = 0;

    int x = 0;
    int c;
    int i = 0;

    while(c = s[i])
    {
        x ^= c;
        if (a[c])
        {
            a[c] = 0;
            all --;
        }
        else
        {
            a[c] = 1;
            all ++;
        }
        i ++;
    }

    return x ? (a[x] && all == 1) : !all;
}
