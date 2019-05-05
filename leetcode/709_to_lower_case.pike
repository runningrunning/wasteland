char* toLowerCase(char* str) {
    char* s = strdup(str);
    int i = 0;
    int c = s[i ++];

    while (c)
    {
        if (c >= 'A' && c <= 'Z')
            s[i - 1] = c - 'A' + 'a';
        c = s[i ++];
    }
    return s;
}
