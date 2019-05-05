int longestValidParentheses(char* s) {
    int l = strlen(s);
    if (l < 2)
        return 0;

    int* ss = malloc(sizeof(int) * (l + 2));
    ss[0] = 0;

    int max = 0;
    int i = 0;
    int j = 0;
    int c = 2 << 8;
    while(s[i])
    {
        if (s[i] != ')')
        {
            ss[++j] = ')';
        }
        else
        {
            if (!j)
                ss[0] = 0;
            else
            {
                j --;
                ss[j] += c + (ss[j + 1] & 0xFFFFFF00);
                if (max < ss[j])
                    max = ss[j];
            }
        }
        i ++;
    }
    return max >> 8;
}
