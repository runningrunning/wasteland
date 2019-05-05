/*int strStr(char* haystack, char* needle)
{
    int l = strlen(haystack);
    int size = strlen(needle);

    if (l < size)
        return -1;

    int* ofs = malloc(sizeof(int) * (size + 1));
    memset(ofs, 0, sizeof(int) * (size + 1));

    for (int i = 1; i < size; i ++)
    {
        int o = 0;
        while(needle[o] == needle[i + o])
        {
            if (!ofs[i + o] || (ofs[i + o] > i + o))
                ofs[i + o] = i + o;
            o ++;
        }
        if (!ofs[i + o] || (ofs[i + o] > i))
            ofs[i + o] = i;
    }

    int o = 0;
    for (int i = 0; i <= l - size;)
    {
        while(needle[o] && (needle[o] == haystack[i + o]))
            o ++;
        if (!needle[o])
            return i;

        if (!o)
        {
            i ++;
            continue;
        }

        i += o;
        o -= ofs[o];
        i -= o;
    }
    return -1;
}
*/

int strStr(char *haystack, char* needle)
{
    int l = strlen(haystack);
    int m = strlen(needle);
    if (l < m)
        return -1;

    for (int i = 0; i < l - m + 1; i++)
    {
        int o = 0;
        while(needle[o] && (needle[o] == haystack[i + o])) o++;
        if (!needle[o])
            return i;
    }
    return -1;
}
