/*
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

int shortestWordDistance(char** words, int wordsSize, char* word1, char* word2)
{
    if (strcmp(word1, word2))
        return shortestDistance(words, wordsSize, word1, word2);

    int i1 = -1;
    int min = wordsSize;

    for (int i = 0; i < wordsSize; i ++)
    {
        if (0 == strcmp(words[i], word1))
        {
            if (i1 != -1)
            {
                if (min > i - i1)
                    min = i - i1;
            }
            i1 = i;
        }
    }

    return min;
}
*/

/*
int shortestWordDistance(char** words, int wordsSize, char* word1, char* word2)
{
    int min = wordsSize;
    int id = 0;
    int is[2] = {-1, -1};
    char* ws[2] = {word1, word2};

    for (int i = 0; i < wordsSize; i ++)
    {
        if (0 == strcmp(words[i], ws[id % 2]))
            is[(id ++) % 2] = i;
        else if (0 == strcmp(words[i], ws[(id + 1) % 2]))
            is[((id ++) + 1) % 2] = i;

        if (is[0] != -1 && is[1] != -1)
        {
            int diff = abs(is[0] - is[1]);
            if (min > diff)
                min = diff;
        }
    }

    return min;
}
*/
