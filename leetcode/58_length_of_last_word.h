int lengthOfLastWord(char* s)
{
    int l = strlen(s) - 1;

    int i = 0;
    while(l >= 0 && s[l] == ' ')
        l --;

    while(s[l] != ' ' && l >= 0)
    {
        i ++;
        l --;
    }

    return i;
}
