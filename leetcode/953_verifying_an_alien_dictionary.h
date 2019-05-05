// stupid corner case
bool _is_small(char* a, char* b, int* o)
{
    int al = strlen(a);
    int bl = strlen(b);

    int ml = al > bl ? bl : al;

    for (int i = 0; i < ml; i ++)
        if (o[a[i] - 'a'] > o[b[i] - 'a'])
            return false;
        else if (o[a[i] - 'a'] < o[b[i] - 'a'])
            return true;
    return bl >= al;
}

bool isAlienSorted(char** words, int wordsSize, char* order)
{
    int o[26] = {0};
    for (int i = 0; i < 26; i ++)
        o[order[i] - 'a'] = i;

    for (int i = 1; i < wordsSize; i ++)
        if (!_is_small(words[i - 1], words[i], o))
            return false;
    return true;
}
