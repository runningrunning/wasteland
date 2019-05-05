// can extend the length of duplicated characters
int expressiveWords(char* S, char** words, int wordsSize)
{
    char c[100] = {0};
    char n[100] = {0};

    int i = 0;
    int e = -1;

    int s = S[i ++];

    int f = 0;
    int pre = -1;

    while (s)
    {
        f |= 1 << (s - 'a');

        if (s != pre)
        {
            c[++ e] = s;
            n[e] = 1;
        }
        else
            n[e] ++;

        pre = s;

        s = S[i ++];
    }

    int a = 0;
    for (int i = 0; i < wordsSize; i ++)
    {
        int j = 0;
        char* w = words[i];

        int s = w[j ++];

        bool can = true;

        int pre = -1;
        int pre_n = 0;
        int pre_i = -1;

        while (s)
        {
            if (!(f & 1 << (s - 'a')))
            {
                can = false;
                break;
            }

            if (s != pre)
            {
                if (pre != -1)
                {
                    if (c[pre_i] != pre || (n[pre_i] == 2 ? 2 != pre_n : n[pre_i] < pre_n))
                    {
                        can = false;
                        break;
                    }
                }

                pre = s;
                pre_n = 1;
                pre_i ++;
            }
            else
                pre_n ++;

            s = w[j ++];
        }

        if (pre_i != e)
            can = false;

        if (can && pre != -1)
        {
            if (c[pre_i] != pre || (n[pre_i] == 2 ? 2 != pre_n : n[pre_i] < pre_n))
                can = false;
        }

        if (can)
            a ++;
    }

    return a;
}
