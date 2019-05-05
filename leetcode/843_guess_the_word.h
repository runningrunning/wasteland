// it's not really pass, it will failed in the long times !!!
/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */

int _sc(char* a, char* b)
{
    int t = !!(a[0] == b[0]);
    t += !!(a[1] == b[1]);
    t += !!(a[2] == b[2]);
    t += !!(a[3] == b[3]);
    t += !!(a[4] == b[4]);
    t += !!(a[5] == b[5]);
    return t;
}

bool _is_x(char* a, char* b, int x)
{
    return _sc(a, b) == x;
}

int _find_better(char** wordlist, int wordlistSize)
{
    int score = 6 * wordlistSize / 2;

    int i = 0;
    int x = 0;
    int ms = 0;
    int mi;
    do {
        x = 0;
        for (int j = 0; j < wordlistSize; j ++)
        {
            x += _sc(wordlist[i], wordlist[j]);
            if (x > score)
                return i;
        }

        if (x > ms)
        {
            ms = x;
            mi = i;
        }

        i ++;
    } while (i < wordlistSize);
    return i >= wordlistSize ? mi : i;
}

int _find_better_2(char** wordlist, int* a, int as)
{
    if (as == 1)
        return a[0];

    int score = 6 * as / 2;

    int i = 0;
    int x = 0;
    int ms = 0;
    int mi;
    do {
        x = 0;
        for (int j = 0; j < as; j ++)
        {
            x += _sc(wordlist[a[i]], wordlist[a[j]]);
            if (x > score)
                return a[i];
        }

        if (x > ms)
        {
            ms = x;
            mi = i;
        }
        i ++;
    } while (i < as);

    return i >= as ? a[mi] : a[i];
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master)
{
    int t = _find_better(wordlist, wordlistSize);

    char* y = wordlist[0];
    int x = guess(master, y);
    int ai = 0;
    int a[101] = {};

    if (x == 6)
    {
        for (int i = 0; i < 9; i ++)
            guess(master, y);
    }
    else
    {
        for (int i = 0; i < wordlistSize; i ++)
            if (_is_x(wordlist[i], y, x))
                a[ai ++] = i;

        for (int i = 0; i < 9; i ++)
        {
            t = _find_better_2(wordlist, a, ai);
            y = wordlist[t];
            x = guess(master, y);

            if (x == 6)
            {
                a[0] = t;
                ai = 1;
            }
            else
            {
                int nai = 0;
                for (int j = 0; j < ai; j ++)
                    if (_is_x(wordlist[a[j]], y, x))
                        a[nai ++] = a[j];
                ai = nai;
            }
        }
    }

    if (x != 6)
        printf("guess failed.\n");
}
