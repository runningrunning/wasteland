/* class WordFilter { */
/*     // try my trier */
/* #define N 26 */
/*     typedef struct _Node{ */
/*         struct _Node* n[N]; */
/*         int idn; */
/*         int* ids; */
/*     } Node; */

/*     Node* cNode(int id) */
/*     { */
/*         Node* n = (Node*) malloc(sizeof(Node)); */
/*         memset(n->n, 0, sizeof(Node*) * N); */
/*         n->ids = NULL; */
/*         n->idn = 0; */

/*         if (id != -1) */
/*         { */
/*             n->ids = (int*) malloc(sizeof(int)); */
/*             n->idn = 1; */
/*             n->ids[0] = id; */
/*         } */
/*         return n; */
/*     } */

/*     void aNode(Node* n, int id) */
/*     { */
/*         n->ids = (int*) realloc(n->ids, sizeof(int) * (n->idn + 1)); */
/*         n->ids[n->idn] = id; */
/*         n->idn ++; */
/*     } */

/*     void fNode(Node* n) */
/*     { */
/*         for (int i = 0; i < N; i ++) */
/*             if (n->n[i]) */
/*                 fNode(n->n[i]); */
/*         free(n); */
/*     } */

/*     Node* pre; */
/*     Node* suf; */
/*     int last_empty; */
/*     int size; */

/*  public: */
/*     WordFilter(vector<string> words) */
/*     { */
/*         pre = cNode(-1); */
/*         suf = cNode(-1); */

/*         last_empty = -1; */
/*         size = words.size(); */

/*         for (int j = 0; j < size; j ++) */
/*         { */
/*             const char* a = words[j].c_str(); */

/*             if (!a[0]) */
/*             { */
/*                 last_empty = j; */
/*                 continue; */
/*             } */

/*             int i = 0; */
/*             int c = a[i ++]; */

/*             Node* r = pre; */
/*             while (c) */
/*             { */
/*                 c -= 'a'; */
/*                 if (!r->n[c]) */
/*                     r->n[c] = cNode(j); */
/*                 else */
/*                     aNode(r->n[c], j); */
/*                 r = r->n[c]; */
/*                 c = a[i ++]; */
/*             } */
/*             i -= 2; */

/*             r = suf; */
/*             while (i >= 0) */
/*             { */
/*                 c = a[i] - 'a'; */
/*                 if (!r->n[c]) */
/*                     r->n[c] = cNode(j); */
/*                 else */
/*                     aNode(r->n[c], j); */
/*                 r = r->n[c]; */
/*                 i --; */
/*             } */
/*         } */
/*         size -= 1; */
/*     } */

/*     int find(int* p, int pn, int* s, int sn) */
/*     { */
/*         int ps = 0; */
/*         int pe = pn - 1; */
/*         int ss = 0; */
/*         int se = sn - 1; */

/*         while (pe >= 0 && se >= 0 && p[pe] != s[se]) */
/*         { */
/*             if (p[pe] > s[se]) */
/*             { */
/*                 int _s = 0; */
/*                 int _e = pe; */

/*                 while (_s < _e) */
/*                 { */
/*                     int m = _s + (_e - _s) / 2; */
/*                     if (p[m] < s[se]) */
/*                         _s = m + 1; */
/*                     else */
/*                         _e = m; */
/*                 } */
/*                 pe = _s; */
/*                 if (p[pe] != s[se]) */
/*                     pe --; */
/*             } */
/*             else */
/*             { */
/*                 int _s = 0; */
/*                 int _e = se; */

/*                 while (_s < _e) */
/*                 { */
/*                     int m = _s + (_e - _s) / 2; */
/*                     if (s[m] < p[pe]) */
/*                         _s = m + 1; */
/*                     else */
/*                         _e = m; */
/*                 } */
/*                 se = _s; */

/*                 if (p[pe] != s[se]) */
/*                     se --; */
/*             } */
/*         } */

/*         if (pe < 0 || se < 0 || p[pe] != s[se]) */
/*             return -1; */
/*         return p[pe]; */
/*     } */

/*     int f(string _prefix, string _suffix) */
/*     { */
/*         const char* prefix = _prefix.c_str(); */
/*         const char* suffix = _suffix.c_str(); */
/*         // return last one */
/*         if (!prefix[0] && !suffix[0]) */
/*             return size; */

/*         Node* p = pre; */
/*         Node* s = suf; */

/*         char* a = prefix; */
/*         int i = 0; */
/*         int c = a[i ++]; */
/*         while (c) */
/*         { */
/*             c -= 'a'; */
/*             if (!p->n[c]) */
/*                 return -1; */
/*             p = p->n[c]; */
/*             c = a[i ++]; */
/*         } */

/*         a = suffix; */
/*         i = strlen(a) - 1; */
/*         while (i >= 0) */
/*         { */
/*             c = a[i] - 'a'; */
/*             if (!s->n[c]) */
/*                 return -1; */
/*             s = s->n[c]; */
/*             i --; */
/*         } */

/*         if (p == pre) */
/*             return s->ids[s->idn - 1]; */
/*         else if (s == suf) */
/*             return p->ids[p->idn - 1]; */
/*         return find(p->ids, p->idn, s->ids, s->idn); */
/*     } */
/* }; */



/**
 * Your WordFilter struct will be instantiated and called as such:
 * struct WordFilter* obj = wordFilterCreate(words);
 * int param_1 = wordFilterF(obj, prefix, suffix);
 * wordFilterFree(obj);
 */

// try my trier
#define N 26
typedef struct _Node{
    struct _Node* n[N];
    int idn;
    int* ids;
} Node;

Node* cNode(int id)
{
    Node* n = malloc(sizeof(Node));
    memset(n->n, 0, sizeof(Node*) * N);
    n->ids = NULL;
    n->idn = 0;

    if (id != -1)
    {
        n->ids = malloc(sizeof(int));
        n->idn = 1;
        n->ids[0] = id;
    }
    return n;
}

void aNode(Node* n, int id)
{
    n->ids = realloc(n->ids, sizeof(int) * (n->idn + 1));
    n->ids[n->idn] = id;
    n->idn ++;
}

void fNode(Node* n)
{
    for (int i = 0; i < N; i ++)
        if (n->n[i])
            fNode(n->n[i]);
    free(n);
}

typedef struct {
    Node* pre;
    Node* suf;
    int last_empty;
    int size;
} WordFilter;

WordFilter* wordFilterCreate(char** words, int size) {
    WordFilter* w = malloc(sizeof(WordFilter));

    Node* pre = cNode(-1);
    Node* suf = cNode(-1);

    w->pre = pre;
    w->suf = suf;
    w->last_empty = -1;
    w->size = size - 1;

    for (int j = 0; j < size; j ++)
    {
        const char* a = words[j];

        if (!a[0])
        {
            w->last_empty = j;
            continue;
        }

        int i = 0;
        int c = a[i ++];

        Node* r = pre;
        while (c)
        {
            c -= 'a';
            if (!r->n[c])
                r->n[c] = cNode(j);
            else
                aNode(r->n[c], j);
            r = r->n[c];
            c = a[i ++];
        }
        i -= 2;

        r = suf;
        while (i >= 0)
        {
            c = a[i] - 'a';
            if (!r->n[c])
                r->n[c] = cNode(j);
            else
                aNode(r->n[c], j);
            r = r->n[c];
            i --;
        }
    }
    return w;
}

int find(int* p, int pn, int* s, int sn)
{
    int ps = 0;
    int pe = pn - 1;
    int ss = 0;
    int se = sn - 1;

    while (pe >= 0 && se >= 0 && p[pe] != s[se])
    {
        if (p[pe] > s[se])
        {
            int _s = 0;
            int _e = pe;

            while (_s < _e)
            {
                int m = _s + (_e - _s) / 2;
                if (p[m] < s[se])
                    _s = m + 1;
                else
                    _e = m;
            }
            pe = _s;
            if (p[pe] != s[se])
                pe --;
        }
        else
        {
            int _s = 0;
            int _e = se;

            while (_s < _e)
            {
                int m = _s + (_e - _s) / 2;
                if (s[m] < p[pe])
                    _s = m + 1;
                else
                    _e = m;
            }
            se = _s;

            if (p[pe] != s[se])
                se --;
        }
    }

    if (pe < 0 || se < 0 || p[pe] != s[se])
        return -1;
    return p[pe];
}

int wordFilterF(WordFilter* obj, char* prefix, char* suffix) {
    if (!obj)
        return -1;

    // return last one
    if (!prefix[0] && !suffix[0])
        return obj->size;

    Node* p = obj->pre;
    Node* s = obj->suf;

    char* a = prefix;
    int i = 0;
    int c = a[i ++];
    while (c)
    {
        c -= 'a';
        if (!p->n[c])
            return -1;
        p = p->n[c];
        c = a[i ++];
    }

    a = suffix;
    i = strlen(a) - 1;
    while (i >= 0)
    {
        c = a[i] - 'a';
        if (!s->n[c])
            return -1;
        s = s->n[c];
        i --;
    }

    if (p == obj->pre)
        return s->ids[s->idn - 1];
    else if (s == obj->suf)
        return p->ids[p->idn - 1];
    return find(p->ids, p->idn, s->ids, s->idn);
}

void wordFilterFree(WordFilter* obj) {
    if (obj)
    {
        fNode(obj->pre);
        fNode(obj->suf);
        free(obj);
    }
}

/**
 * Your WordFilter struct will be instantiated and called as such:
 * struct WordFilter* obj = wordFilterCreate(words);
 * int param_1 = wordFilterF(obj, prefix, suffix);
 * wordFilterFree(obj);
 */
