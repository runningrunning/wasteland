// trie !!!
// do we need trie for this problem? YES
// i don't think so (for stack, we don't need)
// brilliant idea, do back tracing, not store the previous result

// if store string in the original order, we need to use stack to trace all of result
// store string in reverse order, then each time, we just do reverse checking trie


// simple is the fastest !!!!!!
// remove the recursive part
// add the string in reverse order

/* class TrieNode */
/* { */
/*     bool end; */
/*     TrieNode* n[26]; */
/* public: */
/*     TrieNode() */
/*     { */
/*         end = false; */
/*         memset(n, 0, sizeof(n)); */
/*     } */
/* }; */

/* class StreamChecker { */
/* public: */
/*     StreamChecker(vector<string>& words) { */
/*     } */
/*     bool query(char letter) { */
/*     } */
/* }; */

// trie ?
// do we need trie for this problem?
// i don't think so
// simple is the fastest !!


class StreamChecker {
    struct _TNode
    {
        int eof;
        struct _TNode* n[26];
    };

    typedef struct _TNode TNode;

    TNode* _ntrie()
    {
        TNode* r = (TNode*) malloc(sizeof(TNode));
        memset(r, 0, sizeof(TNode));
        return r;
    }

    /* void _atrie(TNode* r, const char* s, int sl) */
    /* { */
    /*     if (!s[sl]) */
    /*     { */
    /*         r->eof = true; */
    /*         return; */
    /*     } */

    /*     int c = s[sl] - 'a'; */

    /*     if (!r->n[c]) */
    /*     { */
    /*         r->num ++; */
    /*         r->n[c] = _ntrie(); */
    /*     } */
    /*     _atrie(r->n[c], s, sl + 1); */
    /* } */

    int sn;
    int ss;
    char* str;
    TNode* root;

    /* int _ts; */
    /* TNode** _temp; */
    /* int _ms; */
    /* int _mn; */
    /* TNode** _matched; */
public:

    StreamChecker(vector<string>& words) {
        /* _ts = _ms = _mn = 0; */
        /* _temp = _matched = 0; */
        root = _ntrie();
        for (int i = 0; i < words.size(); i ++)
        {
            const char* s = words[i].c_str();
            int l = strlen(s);
            TNode* t = root;
            for (int j = l - 1; j >= 0; j --)
            {
                int c = s[j] - 'a';
                if (!t->n[c])
                    t->n[c] = _ntrie();
                t = t->n[c];
            }
            t->eof = true;
        }

        sn = 0;
        ss = 1024;
        str = (char*) malloc(sizeof(char) * ss);
    }

    bool query(char letter)
    {
        if (sn == ss)
        {
            ss += 1024;
            str = (char*) realloc(str, sizeof(char) * ss);
        }
        str[sn ++] = letter;

        TNode* t = root;
        for (int i = sn - 1; i >= 0; i --)
        {
            t = t->n[str[i] - 'a'];
            if (!t)
                return false;
            if (t->eof)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

// use left only make it worse as it may contain lots of lefts
// find better way to get rid of those leftover stings
/*
struct _TNode
{
    int eof;
    int num;
    char* left;
    struct _TNode* n[26];
};
typedef struct _TNode TNode;

typedef struct
{
    int i;
    TNode* c;
} MNode;

typedef struct {
    TNode* r;
    int ts;
    MNode** temp;
    int ms;
    int mn;
    MNode** matched;
} StreamChecker;

void sc_sort(char** w, int s, int e)
{
    if (s >= e)
        return;

    char* t;

    if (strcmp(w[s], w[e]) > 0)
    {
        t = w[s];
        w[s] = w[e];
        w[e] = t;
    }

    if (s + 1 == e)
        return;

    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (strcmp(w[i], w[s]) < 0)
            i ++;
        while (strcmp(w[e], w[s]) > 0)
            e --;

        if (i >= e)
        {
            t = w[s];
            w[s] = w[e];
            w[e] = t;
        }
        else
        {
            t = w[i];
            w[i] = w[e];
            w[e] = t;
        }
    }

    sc_sort(w, os, e - 1);
    sc_sort(w, e  + 1, oe);
}

TNode* _ntrie()
{
    TNode* r = malloc(sizeof(TNode));
    memset(r, 0, sizeof(TNode));
    return r;
}

void _atrie(TNode* r, char* s, int sl, int ss)
{
    if (!s[sl])
    {
        r->eof = true;
        return;
    }

    int c = s[sl] - 'a';

    if (r->n[c])
        _atrie(r->n[c], s, sl + 1, ss);
    else
    {
        if (sl >= ss && !r->left)
            r->left = strdup(s + sl);
        else
        {
            r->num ++;
            r->n[c] = _ntrie();
            _atrie(r->n[c], s, sl + 1, ss);
        }
    }
}

TNode* _ctrie(char** words, int wl)
{
    TNode* r = _ntrie();
    for (int i = 0; i < wl - 1; i ++)
    {
        char* a = words[i];
        char* b = words[i + 1];
        int ai = 0;
        int bi = 0;
        while (a[ai] && b[bi])
        {
            if (a[ai] != b[bi])
                break;
            ai ++;
            bi ++;
        }
        _atrie(r, a, 0, ai);
    }
    _atrie(r, words[wl - 1], 0, INT_MAX);
    return r;
}

StreamChecker* streamCheckerCreate(char** words, int wl) {
    sc_sort(words, 0, wl - 1);
    StreamChecker* s = malloc(sizeof(StreamChecker));
    s->ms = 0;
    s->mn = 0;
    s->matched = 0;
    s->ts = 0;
    s->temp = 0;
    s->r = _ctrie(words, wl);
    return s;
}

bool streamCheckerQuery(StreamChecker* obj, char letter) {
    bool ret = false;
    if (obj)
    {
        int tn = 0;
        int ts = obj->ts;
        MNode** temp = obj->temp;

        for (int i = 0; i < obj->mn; i ++)
        {
            MNode* n = obj->matched[i];
            if (n->i)
            {
                if (n->c->left[n->i] == letter)
                {
                    if (n->c->left[n->i + 1] == 0)
                        ret = true;
                    else
                    {
                        if (tn >= ts)
                        {
                            ts += 256;
                            temp = realloc(temp, sizeof(MNode*) * ts);
                        }
                        temp[tn ++] = n;
                        n->i += 1;
                    }
                }
            }
            else
            {
                TNode* t = n->c->n[letter - 'a'];
                if (t)
                {
                    if (t->eof)
                        ret = true;

                    if (t->num || t->left)
                    {
                        if (tn >= ts)
                        {
                            ts += 256;
                            temp = realloc(temp, sizeof(MNode*) * ts);
                        }
                        temp[tn ++] = n;
                        n->c = t;
                        n->i = 0;
                    }
                }
                else if (n->c->left)
                {
                    if (n->c->left[0] == letter)
                    {
                        if (n->c->left[1] == 0)
                            ret = true;
                        else
                        {

                            if (tn >= ts)
                            {
                                ts += 256;
                                temp = realloc(temp, sizeof(MNode*) * ts);
                            }

                            temp[tn ++] = n;
                            n->i = 1;
                        }
                    }
                }
            }
        }

        TNode* t = obj->r->n[letter - 'a'];
        if (t)
        {
            if (t->eof)
                ret = true;

            if (t->num || t->left)
            {
                if (tn >= ts)
                {
                    ts += 256;
                    temp = realloc(temp, sizeof(MNode*) * ts);
                }
                MNode* n = malloc(sizeof(MNode));
                n->i = 0;
                n->c = t;
                temp[tn ++] = n;
            }
        }
        else if (obj->r->left)
        {
            if (obj->r->left[0] == letter)
            {
                if (obj->r->left[1] == 0)
                    ret = true;
                else
                {

                    if (tn >= ts)
                    {
                        ts += 256;
                        temp = realloc(temp, sizeof(MNode*) * ts);
                    }

                    MNode* n = malloc(sizeof(MNode));
                    n->i = 1;
                    n->c = obj->r;
                    temp[tn ++] = n;
                }
            }
        }

        obj->temp = obj->matched;
        obj->ts = obj->ms;

        obj->matched = temp;
        obj->ms = ts;
        obj->mn = tn;
    }
    return ret;
}

void streamCheckerFree(StreamChecker* obj) {
}
*/
/**
 * Your StreamChecker struct will be instantiated and called as such:
 * struct StreamChecker* obj = streamCheckerCreate(words);
 * bool param_1 = streamCheckerQuery(obj, letter);
 * streamCheckerFree(obj);
 */

