// find better solutions !!! union find or graph
// union find ? set ?
int _hash(char* s, int primer)
{
    int i = 0;
    int c = s[i ++];
    int t = 0;
    while (c)
    {
        t = ((t << 8) + c) % primer;
        c = s[i ++];
    }
    return t;
}

bool areSentencesSimilarTwo(char** words1, int words1Size, char** words2, int words2Size, char*** pairs, int pairsRowSize, int pairsColSize)
{
    if (words1Size != words2Size)
        return false;

    if (!pairs || !pairsRowSize)
    {
        for (int i = 0; i < words1Size; i ++)
            if (!strcmp(words1[i], words2[i]))
                return false;
        return true;
    }

    int primer = 0;
    int w_max = 2 * pairsRowSize + 2;

    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pri_l = sizeof(pri)/sizeof(pri[0]);
    for (int i = 0; i < pri_l; i ++)
    {
        primer = pri[i];
        if (primer / (2 * pairsRowSize) > 4)
            break;
    }

    short* hash = calloc(sizeof(short), primer);

    int str_id = 1;
    char** strs = calloc(sizeof(char*), w_max);

    int sames_id = 1;
    int* sames = calloc(sizeof(int), w_max);

    for (int i = 0; i < pairsRowSize; i ++)
    {
        int ix = 0;
        int iy = 0;

        char* x = pairs[i][0];
        int h = _hash(x, primer);
        while (hash[h] && strcmp(x, strs[hash[h]]))
            h = (h + 1) % primer;

        if (!hash[h])
        {
            strs[str_id] = x;
            hash[h] = str_id ++;
        }

        ix = hash[h];
        char* y = pairs[i][1];
        h = _hash(y, primer);
        while (hash[h] && strcmp(y, strs[hash[h]]))
            h = (h + 1) % primer;

        if (!hash[h])
        {
            strs[str_id] = y;
            hash[h] = str_id ++;
        }
        iy = hash[h];

        if (!sames[ix] && !sames[iy])
        {
            sames[ix] = sames[iy] = sames_id ++;
        }
        else if (!sames[ix] || !sames[iy])
        {
            if (sames[ix])
                sames[iy] = sames[ix];
            else
                sames[ix] = sames[iy];
        }
        else if (sames[ix] != sames[iy])
        {
            int t = sames[ix];
            for (int i = 0;i < w_max; i ++)
                if (sames[i] == t)
                    sames[i] = sames[iy];
        }
    }

    for (int i = 0; i < words1Size; i ++)
    {
        char* x = words1[i];
        char* y = words2[i];

        if (!strcmp(x, y))
            continue;

        int ix = 0;
        int iy = 0;

        int h = _hash(x, primer);
        while (hash[h] && strcmp(x, strs[hash[h]]))
            h = (h + 1) % primer;

        if (!hash[h])
            return false;

        ix = hash[h];

        h = _hash(y, primer);
        while (hash[h] && strcmp(y, strs[hash[h]]))
            h = (h + 1) % primer;

        if (!hash[h])
            return false;

        iy = hash[h];

        if (sames[ix] != sames[iy])
            return false;
    }

    return true;
}
