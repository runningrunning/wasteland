char* convert(char* s, int numRows)
{
    if (numRows == 1)
        return s;

    int len = strlen(s);
    char* ss = malloc(sizeof(char) * (len + 1));
    ss[len] = 0;

    int offset[2] = {2 * (numRows - 1), 2 * (numRows - 1)};

    int i = 0;
    int rn = 0;
    for(int j = 0; j < numRows; j ++)
    {
        rn = j;
        offset[0] = 2 * (numRows - 1) - 2 * j;
        offset[1] = 2 * j;

        if (!offset[0])
            offset[0] = 2 * (numRows - 1);
        if (!offset[1])
            offset[1] = 2 * (numRows - 1);
        int o = 0;
        while(rn < len)
        {
            ss[i++] = s[rn];
            rn += offset[(o++) % 2];
        }
    }
    return ss;
}
