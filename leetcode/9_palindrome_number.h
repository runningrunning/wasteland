bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    if (x < 10)
        return true;

    int n = 1000000000;
    while(x < n)
    {
        n /= 10;
    }

    while(n > 1)
    {
        if (((x / n) % 10) != (x % 10))
            return false;
        n /= 100;
        x /= 10;
    }
    return true;
}
