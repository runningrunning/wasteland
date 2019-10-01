int maxNumberOfBalloons(char * text)
{
    int cs[26] = {0};
    int i = 0;
    while(text[i])
        cs[text[i ++] - 'a'] ++;

    int min = cs['a' - 'a'];

    if (min > cs['b' - 'a'])
        min = cs['b' - 'a'];

    if (min > cs['n' - 'a'])
        min = cs['n' - 'a'];

    if (min * 2 > cs['l' - 'a'])
        min = cs['l' - 'a'] / 2;

    if (min * 2 > cs['o' - 'a'])
        min = cs['o' - 'a'] / 2;
    return min;
}

