int wordsTyping(char** sentence, int sentenceSize, int rows, int cols)
{
    int* se = malloc(sizeof(int) * sentenceSize);
    se[0] = strlen(sentence[0]);

    int* st = malloc(sizeof(int) * sentenceSize);
    st[0] = 0;

    for (int i = 1; i < sentenceSize; i ++)
    {
        st[i] = se[i - 1] + 1;
        se[i] = st[i] + strlen(sentence[i]);
    }

    int end = se[sentenceSize - 1];
    int all = end + 1;

    int n = 0;
    int s = 0;
    for (int i = 0; i < rows; i ++)
    {
        int left = cols;
        if (left >= end - st[s])
        {
            n ++;
            left -= end - st[s];
            s = 0;

            if (left)
            {
                n += left / all;
                left %= all;
            }

            left --;
        }

        if (left > 0)
        {
            int f = s;
            int t = sentenceSize - 1;

            while (f < t)
            {
                int m = f + (t - f) / 2;
                if (left > (se[m] - st[s]))
                    f = m + 1;
                else
                    t = m;
            }
            s = f + ((se[f] - st[s]) == left ? 1 : 0);
        }
    }
    return n;
}
