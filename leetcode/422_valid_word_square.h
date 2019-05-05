bool validWordSquare(char** words, int wordsSize)
{
    if (!words || !wordsSize)
        return true;

    int pre_j = wordsSize;

    for (int i = 0; i < wordsSize; i ++)
    {
        char* t = words[i];

        int j = -1;
        char c = t[++ j];
        while(c && j <= i)
            c = t[++ j];

        if (j > pre_j)
            return false;

        if (j > i)
        {
            while(true)
            {
                if (j >= wordsSize)
                {
                    if (c)
                        return false;
                    break;
                }

                if (c != words[j][i])
                    return false;

                if (!c)
                    break;

                c = t[++ j];
            }
        }
        pre_j = j;
    }
    return true;
}
