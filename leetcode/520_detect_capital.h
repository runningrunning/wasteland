bool detectCapitalUse(char* word)
{
    if (!word || !word[0])
        return false;

    int i = 1;
    char c = word[0];

    if (c >= 'a' && c <= 'z')
    {
        while(c = word[i++])
            if (c < 'a' || c > 'z')
                return false;
    }
    else
    {
        if (c = word[i++])
        {
            if (c >= 'a' && c <= 'z')
            {
                while(c = word[i++])
                    if (c < 'a' || c > 'z')
                        return false;
            }
            else
            {
                while(c = word[i++])
                    if (c < 'A' || c > 'Z')
                        return false;
            }
        }
    }
    return true;
}
