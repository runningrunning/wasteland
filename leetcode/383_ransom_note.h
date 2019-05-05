/* Carefully !!!!!!!!!! */
bool canConstruct(char* ransomNote, char* magazine) {
    if (!ransomNote)
        return true;

    if (!magazine)
        return false;

    int l = strlen(ransomNote);
    int lr = strlen(magazine);

    if (l > lr)
        return false;

    int a[26] = {0};
    int fr = 0;
    int fm = 0;
    for (int i = 0; i < l; i ++)
    {
        int c = ransomNote[i] - 'a';
        a[c] --;
        fr |= 1 << c;
        c = magazine[i] - 'a';
        a[c] ++;
        fm |= 1 << c;
    }

    for (int i = l; i < lr; i ++)
    {
        int c = magazine[i] - 'a';
        fm |= 1 << c;
        a[c] ++;
    }

    if ((fr & fm) != fr)
        return false;

    for(int i = 0; i < 26; i ++)
        if (a[i] < 0)
            return false;
    return true;
}
