bool validWordAbbreviation(char* word, char* abbr)
{
    if (!word)
        return !abbr;

    int wi = 0;
    int ai = 0;

    char w;
    char a;
    int c = 0;

    while(word[wi])
    {
        w = word[wi];
        a = abbr[ai];

        if (c)
            c --;
        else if (a == w)
            ai ++;
        else if (a >= '0' && a <= '9')
        {
            if (a == '0')
                return false;

            c = 0;
            do
            {
                c = c * 10 + a - '0';
                a = abbr[++ ai];
            } while(a >= '0' && a <= '9');

            c --;
        }
        else
            return false;

        wi ++;
    }
    return !word[wi] && !abbr[ai] && !c;
}
