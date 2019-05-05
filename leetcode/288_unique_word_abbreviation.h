// stupid questions, not 26, but also + 1 for string like "i"
// use hash to do it again
// no need to use hash table ?
typedef struct {
    int f[27 * 27];
    int i;
    int* s;
    char** d;
} ValidWordAbbr;

void vw_sort(int* n, int s, int e, char** d)
{
    if (s >= e)
        return;

    int t;
    char* tc;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
        tc = d[s];
        d[s] = d[e];
        d[e] = tc;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
            tc = d[s];
            d[s] = d[e];
            d[e] = tc;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
            tc = d[i];
            d[i] = d[e];
            d[e] = tc;
        }
    }

    vw_sort(n, cs, e - 1, d);
    vw_sort(n, e + 1, ce, d);
}

ValidWordAbbr* validWordAbbrCreate(char** dictionary, int dictionarySize) {
    ValidWordAbbr* w = malloc(sizeof(ValidWordAbbr));
    memset(w->f, 0, sizeof(int) * 27 * 27);

    int* ws = malloc(sizeof(int) * dictionarySize);

    for (int i = 0; i < dictionarySize; i ++)
    {
        char* s = dictionary[i];
        int l = strlen(s);

        if (!l)
            ws[i] = 0;
        else
        {
            int s1 = ((s[0] <= 'z' && s[0] >= 'a') ? (s[0] - 'a') : (s[0] - 'A')) + 1;
            int s2 = 0;

            if (l >= 2)
            {
                s2 = ((s[l - 1] <= 'z' && s[l - 1] >= 'a') ? (s[l - 1] - 'a') : (s[l - 1] - 'A')) + 1;
                l -= 2;
            }
            else
            {
                l = 0;
                s2 = 0;
            }

            s1 = s1 * 27 + s2;
            ws[i] = (s1 << 8) | l;
        }
    }

    vw_sort(ws, 0, dictionarySize - 1, dictionary);

    int uq = 0;
    int pre = -1;

    for (int i = 0; i < dictionarySize; i ++)
    {
        int x = ws[i];

        if (x == pre)
            if (!strcmp(dictionary[i], dictionary[i - 1]))
                continue;

        pre = x;

        ws[uq] = x;
        dictionary[uq] = dictionary[i];

        x = ws[uq] >> 8;
        if (!w->f[x])
            w->f[x] = uq + 1;

        uq ++;
    }
    w->s = ws;
    w->i = uq; // dictionarySize;
    w->d = dictionary;
    return w;
}

bool validWordAbbrIsUnique(ValidWordAbbr* obj, char* word)
{
    if (obj)
    {
        char* s = word;
        int l = strlen(s);
        int s1 = 0;

        if (!l)
            s1 = 0;
        else
        {
            s1 = ((s[0] <= 'z' && s[0] >= 'a') ? (s[0] - 'a') : (s[0] - 'A')) + 1;
            int s2 = 0;

            if (l >= 2)
            {
                if (s[l - 1])
                    s2 = ((s[l - 1] <= 'z' && s[l - 1] >= 'a') ? (s[l - 1] - 'a') : (s[l - 1] - 'A')) + 1;
                l -= 2;
            }
            else
            {
                l = 0;
                s2 = 0;
            }

            s1 = s1 * 27 + s2;
        }

        if (!obj->f[s1])
            return true;

        for (int i = obj->f[s1] - 1; i < obj->i; i ++)
        {
            int x = obj->s[i];

            if ((x >> 8) != s1)
                return true;

            printf("%s.\n", obj->d[i]);

            if ((x & 0xFF) == l)
            {
                if (i != obj->i - 1)
                {
                    int y = obj->s[i + 1];
                    if ((y >> 8) == s1 && (y & 0xF) == l)
                        return false;
                }
                return !strcmp(word, obj->d[i]);
            }
        }
    }
    return true;
}

void validWordAbbrFree(ValidWordAbbr* obj) {
    if (obj)
    {
        free(obj->s);
        free(obj);
    }
}

/**
 * Your ValidWordAbbr struct will be instantiated and called as such:
 * struct ValidWordAbbr* obj = validWordAbbrCreate(dictionary, dictionarySize);
 * bool param_1 = validWordAbbrIsUnique(obj, word);
 * validWordAbbrFree(obj);
 */
