#define N 26
typedef struct _Trie {
    int f; // 1 << 26 for characters, 1 << 30 for end with words;
    struct _Trie* next[N];
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie* t = malloc(sizeof(Trie));
    t->f = 0;
    return t;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    if (obj)
    {
        Trie* s = obj;
        int i = 0;
        int c = word[i ++];
        while(c)
        {
            c -= 'a';
            if (!(s->f & (1 << c)))
            {
                s->f |= 1 << c;
                s->next[c] = trieCreate();
            }
            s = s->next[c];
            c = word[i ++];
        }
        s->f |= 1 << 30;
    }
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    if (obj)
    {
        Trie* s = obj;
        int i = 0;
        int c = word[i ++];

        while (c)
        {
            c -= 'a';
            if (!(s->f & (1 << c)))
                return false;
            s = s->next[c];
            c = word[i ++];
        }
        return !!(s->f & (1 << 30));
    }
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    if (obj)
    {
        Trie* s = obj;
        int i = 0;
        int c = prefix[i ++];

        while (c)
        {
            c -= 'a';
            if (!(s->f & (1 << c)))
                return false;
            s = s->next[c];
            c = prefix[i ++];
        }
        return true;
    }
    return false;
}

void trieFree(Trie* obj) {
    if (obj)
    {
        for (int i = 0; i < N; i ++)
            if (obj->f & (1 << i))
                trieFree(obj->next[i]);
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */
