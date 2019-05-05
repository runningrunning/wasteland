// too complicated, just be careful !
// try to use recursion here
// TODO practice more here.
// try to not use recursion here !!!
#define N 26

typedef struct _WordDictionary {
    int i;
    int f;
    struct _WordDictionary* n[N];
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary* w = malloc(sizeof(WordDictionary));
    w->i = 0;
    w->f = 0;
    return w;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    if (obj && word)
    {
        WordDictionary* t = obj;
        int i = 0;
        int c = word[i ++];

        while (c)
        {
            c -= 'a';
            if (!(t->f & (1 << c)))
            {
                t->f |= 1 << c;
                t->n[c] = wordDictionaryCreate();
                t->i = i;
            }
            t = t->n[c];
            c = word[i ++];
        }
        t->f |= 1 << 30;
    }
}

bool ws(WordDictionary* obj, char* w, int i)
{
    if (w[i] == 0)
        return !!(obj->f & (1 << 30));

    int c = w[i];

    if (c == '.')
    {
        for (int j = 0; j < N; j ++)
            if ((obj->f & (1 << j)) && ws(obj->n[j], w, i + 1))
                return true;
        return false;
    }

    c -= 'a';
    if (!(obj->f & (1 << c)))
        return false;
    return ws(obj->n[c], w, i + 1);
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    if (obj && word)
    {
        WordDictionary* t = obj;
        return ws(obj, word, 0);
        /* int i = 0; */
        /* int c = word[i ++]; */

        /* int ws = 0; */
        /* int wsize = 256; */
        /* int* wi = malloc(sizeof(int) * 256); */
        /* WordDictionary** wt = malloc(sizeof(WordDictionary*) * 256); */

        /* while (true) */
        /* { */
        /*     bool found = true; */

        /*     if (c == 0) */
        /*     { */
        /*         if (t->f & (1 << 30)) */
        /*             return true; */

        /*         found = false; */
        /*     } */
        /*     else if (c == '.') */
        /*     { */
        /*         if (!(t->f & 0xFFFFFFF)) */
        /*             found = false; */
        /*         else */
        /*         { */
        /*             if ((ws + 1)  == wsize) */
        /*             { */
        /*                 wsize += 256; */
        /*                 wt = realloc(wt, sizeof(WordDictionary*) * (wsize)); */
        /*                 wi = realloc(wi, sizeof(int) * (wsize)); */
        /*             } */

        /*             wt[ws] = t; */
        /*             for (int n = 0; n < N; n ++) */
        /*                 if (t->f & (1 << n)) */
        /*                 { */
        /*                     wi[ws] = n; */
        /*                     t = t->n[n]; */
        /*                     break; */
        /*                 } */
        /*             ws ++; */
        /*         } */
        /*     } */
        /*     else */
        /*     { */

        /*         c -= 'a'; */
        /*         if (!(t->f & (1 << c))) */
        /*             found = false; */
        /*         else */
        /*             t = t->n[c]; */
        /*     } */

        /*     if (!found) */
        /*     { */
        /*         while (ws && !found) */
        /*         { */
        /*             ws --; */
        /*             found = false; */
        /*             t = wt[ws]; */

        /*             for (int n = wi[ws] + 1; n < N; n ++) */
        /*             { */
        /*                 if (t->f & (1 << n)) */
        /*                 { */
        /*                     found = true; */
        /*                     i = t->i; */
        /*                     wi[ws] = n; */
        /*                     t = t->n[n]; */
        /*                     break; */
        /*                 } */
        /*             } */
        /*         } */
        /*         if (!found) */
        /*             return false; */
        /*     } */
        /*     c = word[i ++]; */
        /* } */
    }
    return false;
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj)
    {
        for (int i = 0; i < N; i ++)
            if (obj->f & (1 << i))
                wordDictionaryFree(obj->n[i]);
        free(obj);
    }
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */

// other methods
//
// typedef struct {
//     int* b;f
//     int bsize;

//     int* lf;

//     int primer;
//     int* heap;

//     char** ss;
//     int* sl;
//     int size;
//     bool has_empty;
// } WordDictionary;

// #define PRIMER 8209

// /** Initialize your data structure here. */
// WordDictionary* wordDictionaryCreate() {
//     WordDictionary* w = malloc(sizeof(WordDictionary));

//     w->primer = PRIMER;
//     w->heap = malloc(sizeof(int) * PRIMER);
//     memset(w->heap, 0, sizeof(int) * PRIMER);

//     w->bsize = 100;
//     w->bf = malloc(sizeof(int) * 100);
//     memset(w->bf, 0, sizeof(int) * 100);
//     w->lf = malloc(sizeof(int) * 20);
//     memset(w->lf, 0, sizeof(int) * 20);

//     w->size = 0;
//     w->ss = malloc(sizeof(char*) * 256);
//     w->sl = malloc(sizeof(int) * 256);
//     w->has_empty = false;
//     return w;
// }

// /** Adds a word into the data structure. */
// void wordDictionaryAddWord(WordDictionary* obj, char* word) {
//     if (obj && word)
//     {
//         if (!word[0])
//         {
//             obj->has_empty = true;
//             return;
//         }

//         int p = obj->primer;
//         int* heap = obj->heap;
//         int* b = obj->bf;
//         int bs = obj->bsize;
//         int* lf = obj->lf;

//         int i = 0;
//         int c = word[i ++];

//         int t = 0;

//         while (c)
//         {
//             if (i == bs)
//             {
//                 bs += 100;
//                 b = realloc(b, sizeof(int) * bs);
//                 memset(b + bs - 100, 0, sizeof(int) * 100);
//                 obj->bf = b;
//                 obj->bsize = bs;
//             }

//             b[i - 1] |= 1 << (c - 'a');
//             t = (26 * t + c - 'a') % p;

//             c = word[i ++];
//         }
//         i -= 1;

//         lf[i / 32] |= 1 << (i % 32);

//         int* sl = obj->sl;
//         char** ss = obj->ss;
//         int x = t;
//         while (heap[x] && strcmp(ss[heap[x] - 1], word))
//             x = (x + 1) % p;

//         if (heap[x])
//             return;

//         int size = obj->size;

//         if (!((size + 1) % 256))
//         {
//             ss = realloc(ss, sizeof(char*) * (size + 1 + 256));
//             sl = realloc(sl, sizeof(int) * (size + 1 + 256));
//             obj->ss = ss;
//             obj->sl = sl;
//         }

//         sl[size] = i;
//         ss[size] = word;
//         heap[x] = size + 1;
//         obj->size = size + 1;
//     }
// }

// /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
// bool wordDictionarySearch(WordDictionary* obj, char* word)
// {
//     if (obj && word)
//     {
//         if (!word[0])
//             return obj->has_empty;

//         int p = obj->primer;
//         int* heap = obj->heap;
//         int* b = obj->bf;
//         int bs = obj->bsize;
//         int* lf = obj->lf;

//         int i = 0;
//         int c = word[i ++];

//         int t = 0;
//         int ci = 0;
//         while (c)
//         {
//             if (i >= bs)
//                 return false;

//             if (c != '.')
//             {
//                 if (!(b[i - 1] & (1 << (c - 'a'))))
//                     return false;
//                 t = (26 * t + c - 'a') % p;
//             }
//             else
//             {
//                 ci ++;
//                 if (!b[i - 1])
//                     return false;
//             }
//             c = word[i ++];
//         }
//         i -= 1;

//         if (!(lf[i / 32] & (1 << (i % 32))))
//             return false;
//         else if ()

//         int* sl = obj->sl;
//         char** ss = obj->ss;

//         if (ci)
//         {
//             // try find here.
//             for (int j = 0; j < obj->size; j ++)
//             {
//                 if (sl[j] != i)
//                     continue;

//                 char* w = ss[j];

//                 int m = 0;
//                 while (w[m] && (w[m] == word[m] || word[m] == '.'))
//                     m ++;

//                 if (!w[m])
//                     return true;
//             }
//         }
//         else
//         {
//             int x = t;

//             while (heap[x] && strcmp(ss[heap[x] - 1], word))
//                 x = (x + 1) % p;

//             if (heap[x])
//                 return true;
//         }
//     }
//     return false;
// }

// void wordDictionaryFree(WordDictionary* obj) {
//     if (obj)
//     {
//         free(obj->bf);
//         free(obj->lf);
//         free(obj->heap);
//         free(obj->ss);
//         free(obj->sl);
//         free(obj);
//     }
// }

// /**
//  * Your WordDictionary struct will be instantiated and called as such:
//  * struct WordDictionary* obj = wordDictionaryCreate();
//  * wordDictionaryAddWord(obj, word);
//  * bool param_2 = wordDictionarySearch(obj, word);
//  * wordDictionaryFree(obj);
//  */
