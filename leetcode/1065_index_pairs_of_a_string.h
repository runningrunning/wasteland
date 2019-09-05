/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Trie {
    bool end;
    struct Trie* next[26];
};

struct Trie* new()
{
    struct Trie* t = malloc(sizeof(struct Trie));
    memset(t, 0, sizeof(struct Trie));
    return t;
}

void add(struct Trie** r, char* text)
{
    if (!(*r))
        *r = new();
    char c = text[0];
    if (c)
        add(&((*r)->next[c - 'a']), text + 1);
    else
        (*r)->end = true;
}

void find(char* t, int s, int e, struct Trie* r, int*** o, int* oi)
{
    if (r->end)
    {
        int num = *oi;
        *o = realloc(*o, sizeof(int*) * (num + 1));
        (*o)[num] = malloc(sizeof(int) * 2);
        (*o)[num][0] = s;
        (*o)[num][1] = e - 1;
        *oi = num + 1;
    }

    if (!t[e])
        return;
    char c = t[e] - 'a';

    if (r->next[c])
        find(t, s, e + 1, r->next[c], o, oi);
}

// build tries tree
int** indexPairs(char * text, char ** words, int wordsSize, int* returnSize, int** returnColumnSizes)
{
    struct Trie* r = NULL;

    for (int i = 0; i < wordsSize; i ++)
        add(&r, words[i]);

    int oi = 0;
    int** o = NULL;

    int i = 0;

    while (text[i])
    {
        find(text, i, i, r, &o, &oi);
        i ++;
    }

    int* c = malloc(sizeof(int) * oi);
    for (int i = 0; i < oi; i ++)
        c[i] = 2;

    *returnSize = oi;
    *returnColumnSizes = c;
    return o;
}

