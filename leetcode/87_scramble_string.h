bool _isScramble(char* s1, char* s2, int n)
{
    int a1 = 0;
    int x1 = 0;
    int a2 = 0;
    int x2 = 0;
    int f1 = 0;
    int f2 = 0;

    for(int i = 0; i < n; i ++)
    {
        a1 += s1[i];
        a2 += s2[i];
        f1 |= (1 << (s1[i] - 'a'));
        f2 |= (1 << (s2[i] - 'a'));
        x1 ^= s1[i];
        x2 ^= s2[i];
    }

    if (!(a1 == a1 && x1 == x2 && f1 == f2))
        return false;

    if (n <= 3)
        return true;

    for(int i = 1; i < n; i ++)
    {
        if (_isScramble(s1, s2, i) && _isScramble(s1 + i, s2 + i, n - i))
            return true;

        if (_isScramble(s1, s2 + n - i, i) && _isScramble(s1 + i, s2, n - i))
            return true;
    }
    return false;
}

bool isScramble(char* s1, char* s2)
{
    int l = strlen(s1);
    return _isScramble(s1, s2, l);
}
