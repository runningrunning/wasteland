char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize)
{
    if (!words || !wordsSize)
        return NULL;

    int ci = 0;
    int nc[7] = { 0 };

    int n = 0;
    int sn[26] = { 0 };

    int j = 0;
    char c = licensePlate[j ++];

    while (c)
    {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';

        if (c >= 'a' && c <= 'z')
        {
            c -= 'a';
            sn[c] ++;
            if (sn[c] == 1)
                nc[ci ++] = c;
            n ++;
        }
        c = licensePlate[j ++];
    }

    int min_v = INT_MAX;
    int min_i = -1;
    int wn[26] = { 0 };
    for (int i = 0; i < wordsSize; i ++)
    {
        // restore
        wn[nc[0]] = sn[nc[0]];
        wn[nc[1]] = sn[nc[1]];
        wn[nc[2]] = sn[nc[2]];
        wn[nc[3]] = sn[nc[3]];
        wn[nc[4]] = sn[nc[4]];
        wn[nc[5]] = sn[nc[5]];
        wn[nc[6]] = sn[nc[6]];

        char* t = words[i];
        j = 0;
        c = t[j ++];

        int num = n;
        while (c)
        {
            c -= 'a';
            if (wn[c])
            {
                wn[c] --;
                num --;
            }
            c = t[j ++];
        }

        if (!num)
        {
            if (j == n + 1)
                return words[i];

            if (min_v > j)
            {
                min_i = i;
                min_v = j;
            }
        }
    }
    return words[min_i];
}
