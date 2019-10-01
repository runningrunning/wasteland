int countCharacters(char ** words, int wordsSize, char * chars)
{
    int cs[26] = {0};

    int i = 0;
    while (chars[i])
        cs[chars[i ++] - 'a'] ++;

    int r = 0;

    for (i = 0; i < wordsSize; i++)
    {
        char* w = words[i];
        int j = 0;
        int ns[26] = {0};

        while (w[j])
        {
            int c = w[j] - 'a';
            if (ns[c] >= cs[c])
                break;
            ns[c] ++;
            j ++;
        }

        if (w[j])
            continue;

        r += j;
    }
    return r;
}
