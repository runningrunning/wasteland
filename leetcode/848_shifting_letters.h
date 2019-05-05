// be careful !!!
char* shiftingLetters(char* S, int* shifts, int shiftsSize)
{
    int p = 0;
    char* t = strdup(S);

    if (!shifts || !shiftsSize)
        return t;

    for (int i = shiftsSize - 1; i >= 0; i --)
    {
        int x = (shifts[i] + p) % 26;
        int y = t[i] + x; // be carefule t[i] is char, so 'u' + 17 will be -122 not 134
        if (y > 'z')
            t[i] += x - 26;
        else
            t[i] = y;
        p = x;
    }

    return t;
}
