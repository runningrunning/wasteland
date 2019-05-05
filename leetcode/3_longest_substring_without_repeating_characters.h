int char_index(char*str, int s, int e, char a)
{
    for (; s <= e; s ++)
        if (str[s] == a)
            return s;
    return -1;
}

int lengthOfLongestSubstring(char* s)
{
    if (!strlen(s))
        return 0;
    int i = 1;
    int longest = 0;
    int longest_start = 0;
    int start = 0;
    int current = 1;
    while(s[i])
    {
        int f = char_index(s, start, start + current - 1, s[i]);
        if (f == -1)
            current ++;
        else
        {
            if (longest < current)
            {
                longest = current;
                longest_start = start;
            }
            start = f + 1;
            current = i - start + 1;
        }
        i ++;
    }
    return longest > current ? longest : current;
}
