char * longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize == 0)
        return "";

    if (strsSize == 1)
        return strs[0];
    int i = 0;
    for(i = 0; i < 0x7FFFFFFF; i ++)
    {
        bool failed = false;
        char n = *(strs[0] + i);
        for(int j = 1; j < strsSize; j++)
        {
            if (*(strs[j] + i) != n)
            {
                failed = true;
                break;
            }
        }
        if (failed)
        {
            i -= 1;
            break;
        }
    }

    char* t = "";
    if (i + 1 > 0)
    {
        t = malloc(i + 1);
        memcpy(t, strs[0], i + 1);
        t[i+1] = 0;
    }
    return t;
}
