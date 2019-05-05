/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
{
    *returnSize = 0;
    if (!words || !wordsSize)
        return NULL;

    int ri = 0;
    char** r = NULL;
    if (wordsSize == 1 && !strlen(words[0]))
    {
        *returnSize = 1;
        r = realloc(r, sizeof(char*));
        r[0] = malloc(maxWidth + 1);
        for (int i = 0; i < maxWidth; i ++)
            r[0][i] = ' ';
        r[0][maxWidth] = 0;
        return r;
    }

    int i = 0;
    for (; i < wordsSize; )
    {
        int o = i;
        int l = strlen(words[i ++]);

        while (i < wordsSize && l <= maxWidth)
            l += strlen(words[i ++]) + 1;

        char* a = malloc(maxWidth + 1);

        if (l <= maxWidth)
        {
            int in = 0;
            for (int s = o; s < wordsSize; s ++)
            {
                int k = 0;

                if (in)
                    a[in ++] = ' ';

                while (words[s][k])
                    a[in ++] = words[s][k ++];
            }

            while (in < maxWidth)
                a[in ++] = ' ';
        }
        else
        {
            i --;
            l -= strlen(words[i]) + 1;

            int in = 0;
            int n = i - o - 1;
            int e = maxWidth - l + n;

            if (!n)
            {
                int k = 0;
                while (words[o][k])
                    a[in ++] = words[o][k ++];
                while (in < maxWidth)
                    a[in ++] = ' ';
            }
            else
            {
                int y = e / n;
                int z = (e % n) + 1;
                for (int s = o; s < i; s ++)
                {
                    int k = 0;

                    if (in)
                    {
                        int x = y + ((s - o) < z ? 1 : 0);

                        while (x --)
                            a[in ++] = ' ';
                    }

                    while (words[s][k])
                        a[in ++] = words[s][k ++];
                }
            }
        }

        a[maxWidth] = 0;
        ri ++;
        r = realloc(r, sizeof(char*) * ri);
        r[ri - 1] = a;
    }

    *returnSize = ri;
    return r;
}
