int titleToNumber(char* s) {
    if (!s)
        return 0;
    int l = strlen(s);
    if (!l)
        return 0;

    int le = 1;
    int n = 0;
    for(int i = l -1; i >= 0; i --)
    {
        n += (s[i] - 'A' + 1) * le;
        le *= 26;
    }
    return n;
}
