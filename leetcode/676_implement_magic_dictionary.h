// THINK TOO MUCH, just ignore several character to find another one !
#define N 26
typedef struct _Node
{
    bool e;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* n = (Node*) malloc(sizeof(Node));
    n->e = false;
    memset(n->n, 0, sizeof(Node*) * N);
    return n;
}

void aNode(Node* r, const char* s)
{
    int i = 0;
    int c = s[i ++];
    while (c)
    {
        c -= 'a';
        if (!r->n[c])
            r->n[c] = cNode();

        r = r->n[c];
        c = s[i ++];
    }
    r->e = true;
}

bool _fNode(Node* r, const char* s)
{
    int i = 0;
    int c = s[i ++];
    while (c)
    {
        c -= 'a';
        if (!r->n[c])
            return false;
        r = r->n[c];
        c = s[i ++];
    }
    return r->e;
}

bool fNode(Node* r, const char* s, int skip)
{
    int i = 0;
    int c = s[i ++];
    while (c)
    {
        c -= 'a';

        if (i - 1 == skip)
        {
            for (int t = 0; t < 26; t ++)
            {
                if (t == c || !r->n[t])
                    continue;

                if (_fNode(r->n[t], &s[i]))
                    return true;
            }
            return false;
        }

        if (!r->n[c])
            return false;

        r = r->n[c];
        c = s[i ++];
    }
    return r->e;
}

typedef struct {
    Node* f;
} MagicDictionary;


/** Initialize your data structure here. */
MagicDictionary* magicDictionaryCreate() {
    MagicDictionary* m = malloc(sizeof(MagicDictionary));
    m->f = cNode();
    return m;
}

/** Build a dictionary through a list of words */
void magicDictionaryBuildDict(MagicDictionary* obj, char** dict, int size) {
    for (int i = 0; i < size; i ++)
        aNode(obj->f, dict[i]);
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool magicDictionarySearch(MagicDictionary* obj, char* word) {
    int l = strlen(word);

    for (int i = 0; i < l; i ++)
        if (fNode(obj->f, word, i))
            return true;
    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {
}

/* class MagicDictionary { */
/* #define N (26) // 1 for any character */

/*     typedef struct _Node */
/*     { */
/*         bool e; */
/*         struct _Node* n[N]; */
/*     } Node; */

/*     Node* cNode() */
/*     { */
/*         Node* n = (Node*) malloc(sizeof(Node)); */
/*         n->e = false; */
/*         memset(n->n, 0, sizeof(Node*) * N); */
/*         return n; */
/*     } */

/*     void aNode(Node* r, const char* s) */
/*     { */
/*         int i = 0; */
/*         int c = s[i ++]; */
/*         while (c) */
/*         { */
/*             c -= 'a'; */
/*             if (!r->n[c]) */
/*                 r->n[c] = cNode(); */

/*             r = r->n[c]; */
/*             c = s[i ++]; */
/*         } */
/*         r->e = true; */
/*     } */

/*     bool _fNode(Node* r, const char* s) */
/*     { */
/*         int i = 0; */
/*         int c = s[i ++]; */
/*         while (c) */
/*         { */
/*             c -= 'a'; */
/*             if (!r->n[c]) */
/*                 return false; */
/*             r = r->n[c]; */
/*             c = s[i ++]; */
/*         } */
/*         return r->e; */
/*     } */

/*     bool fNode(Node* r, const char* s, int skip) */
/*     { */
/*         int i = 0; */
/*         int c = s[i ++]; */
/*         while (c) */
/*         { */
/*             c -= 'a'; */

/*             if (i - 1 == skip) */
/*             { */
/*                 for (int t = 0; t < 26; t ++) */
/*                 { */
/*                     if (t == c || !r->n[t]) */
/*                         continue; */

/*                     if (_fNode(r->n[t], &s[i])) */
/*                         return true; */
/*                 } */
/*                 return false; */
/*             } */

/*             if (!r->n[c]) */
/*                 return false; */

/*             r = r->n[c]; */
/*             c = s[i ++]; */
/*         } */
/*         return r->e; */
/*     } */

/*     Node* f; */

/*  public: */
/*     /\** Initialize your data structure here. *\/ */
/*     MagicDictionary() { */
/*         f = cNode(); */
/*     } */

/*     /\** Build a dictionary through a list of words *\/ */
/*     void buildDict(vector<string> dict) { */

/*         for (vector<string>::iterator it = dict.begin(); it != dict.end(); ++ it) */
/*             aNode(f, (*it).c_str()); */
/*     } */

/*     /\** Returns if there is any word in the trie that equals to the given word after modifying exactly one character *\/ */
/*     bool search(string word) { */
/*         const char* s = word.c_str(); */
/*         int l = strlen(s); */
/*         for (int i = 0; i < l; i ++) */
/*             if (fNode(p, s, i)) */
/*                 return true; */
/*         return false; */
/*     } */
/* }; */
