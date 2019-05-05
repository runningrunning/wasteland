#define N 26

typedef struct _Trie {
    int f;
    struct _Trie* n[N];
}Trie;

Trie* cTrie()
{
    Trie* t = malloc(sizeof(Trie));
    t->f = 0;
    return t;
}

void aTrie(Trie* t, char* w)
{
    int i = 0;
    int c = w[i ++];

    while (c)
    {
        c -= 'a';
        if (!(t->f & (1 << c)))
        {
            t->f |= 1 << c;
            t->n[c] = cTrie();
        }
        t = t->n[c];
        c = w[i ++];
    }
    t->f |= 1 << 30;
}

char* replaceWords(char** dict, int dictSize, char* sentence)
{
    if (!dictSize || !dict)
        return sentence;

    Trie* o = cTrie();

    for (int i = 0; i < dictSize; i ++)
        aTrie(o, dict[i]);

    char* r = strdup(sentence);

    int i = 0;
    int c = r[i ++];
    int j = 0;

    Trie* t = o;
    bool skip = false;
    bool copy = false;

    while (c)
    {
        if (c == ' ')
        {
            r[j ++] = c;
            skip = false;
            copy = false;
            t = o;
        }
        else if (!skip)
        {
            r[j ++] = c;

            if (!copy)
            {
                c -= 'a';

                if (!(t->f & (1 << c)))
                    copy = true;
                else
                {
                    t = t->n[c];
                    if (t->f & (1 << 30))
                        skip = true;
                }
            }
        }
        c = r[i ++];
    }

    r[j] = 0;
    return r;
}
