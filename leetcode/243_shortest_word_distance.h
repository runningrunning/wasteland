/*
int shortestDistance(char** words, int wordsSize, char* word1, char* word2)
{
    if (!words || !wordsSize)
        return 0;

    int min = wordsSize;
    int i1 = - wordsSize;
    int i2 = - wordsSize;

    int wf1 = 0;
    int wf2 = 0;
    int xor1 = 0;
    int xor2 = 0;
    int all1 = 0;
    int all2 = 0;
    int wfa = 0;

    int j = 0;
    int c = word1[j ++];

    while (c)
    {
        xor1 ^= c;
        all1 += c;
        c -= 'a';
        wf1 |= 1 << c;
        wfa |= 1 << c;
        c = word1[j ++];
    }

    j = 0;
    c = word2[j ++];

    while(c)
    {
        xor2 ^= c;
        all2 += c;
        c -= 'a';
        wf2 |= 1 << c;
        wfa |= 1 << c;
        c = word2[j ++];
    }

    for (int i = 0; i < wordsSize; i ++)
    {
        char* t = words[i];
        int wf = 0;
        int xor = 0;
        int all = 0;

        j = 0;
        c = t[j ++];

        bool need = true;

        while (c)
        {
            xor ^= c;
            all += c;
            c = 1 << (c - 'a');
            if (! (c & wfa))
            {
                need = false;
                break;
            }

            wf |= c;
            c = t[j ++];
        }

        if (!need)
            continue;

        if (wf == wf1 && xor == xor1 && all == all1)
        {
            i1 = i;
            if (min > i1 - i2)
                min = i1 - i2;
        }
        else if (wf == wf2 && xor == xor2 && all == all2)
        {
            i2 = i;
            if (min > i2 - i1)
                min = i2 - i1;
        }
    }
    return min;
}
*/

int shortestDistance(char** words, int wordsSize, char* word1, char* word2)
{
    int min = wordsSize;
    int i1 = - 1;
    int i2 = - 1;

    for (int i = 0; i < wordsSize; i ++)
    {
        if (0 == strcmp(words[i], word1))
            i1 = i;
        else if (0 == strcmp(words[i], word2))
            i2 = i;
        if (i1 != -1 && i2 != -1)
        {
            int diff = abs(i1 - i2);
            if (min > diff)
                min = diff;
        }
    }

    return min;
}

/*
int shortestDistance(char** words, int wordsSize, char* word1, char* word2)
{
    if (!words || !wordsSize)
        return 0;

    int min = wordsSize;
    int i1 = - wordsSize;
    int i2 = - wordsSize;

    for (int i = 0; i < wordsSize; i ++)
    {
        if (!strcmp(words[i], word1))
        {
            i1 = i;
            if (min > i1 - i2)
                min = i1 - i2;
        }
        else if (!strcmp(words[i], word2))
        {
            i2 = i;
            if (min > i2 - i1)
                min = i2 - i1;
        }
    }
    return min;
}
*/
