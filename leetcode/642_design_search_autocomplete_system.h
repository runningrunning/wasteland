/*#include <string>
#include <vector>
#include <cstring>
using namespace std;

class AutocompleteSystem
{
#define N 256
#define T 3
#define C 27 // 26 + ' '

    typedef struct _ACNode
    {
        int e;
        int f;
        int i;
        int s[T];
        struct _ACNode* n[C];
    } ACNode;

    ACNode* cNode()
    {
        ACNode* n = (ACNode*) malloc(sizeof(ACNode));
        n->f = 0;
        n->i = 0;
        n->e = 0;
        return n;
    }

    void aNode(ACNode* r, const char* s, int id)
    {
        int i = 0;
        int c = s[i ++];

        while (c)
        {
            if (c == ' ')
                c = 26;
            else
                c -= 'a';


            if (!(r->f & (1 << c)))
            {
                r->f |= 1 << c;
                r->n[c] = cNode();
            }

            r = r->n[c];
       
            if (r->i < T)
            {
                r->s[r->i] = id;
                r->i += 1;
            }     
            
            c = s[i ++];
        }
        r->e = id + 1;
    }

    void uNode(ACNode* r, int id)
    {
        int i = 0;
        const char* s = hs[id];
        int n = hsn[id];
        int c = s[i ++];

        while (c)
        {
            if (c == ' ')
                c = 26;
            else
                c -= 'a';

            if (!(r->f & (1 << c)))
            {
                r->f |= 1 << c;
                r->n[c] = cNode();
            }

            r = r->n[c];
            
     
            if (r->i == 0)
            {
                r->s[r->i] = id;
                r->i += 1;
            }
            else if (!(r->i == T && hsn[r->s[T - 1]] > n))
            {
                int ti = 0;
                int t[T] = {0};
                bool use = false;

                for (int j = 0; j < r->i; j ++)
                {
                    int in = r->s[j];
                    int inn = hsn[in];

                    if (inn > n || use)
                    {
                        if (in != id)
                        t[ti ++] = in;
                    }
                    else
                    {
                        if (in == id || inn < n || strcmp(s, hs[in]) < 0)
                        {
                            j -= !!(in != id);
                            t[ti ++] = id;
                            use = true;
                        }
                        else
                        {
                            t[ti ++] = in;
                        }
                    }

                    if (ti == T)
                        break;
                }

                if (ti != T && !use)
                    t[ti ++] = id;
                r->i = ti;

                for (int j = 0; j < T; j ++)
                    r->s[j] = t[j];
            }     
            c = s[i ++];
        }

        r->e = id + 1;
    }

    int size;
    const char* hs[N];
    int hsn[N];
    ACNode* r;

    int ci;
    char cs[N];
    ACNode* c;
    bool failed;
    vector<string> empty;

    void acsc_sort(int* n, const char** w, int s, int e)
    {
        if (s >= e)
            return;

        int t;
        const char* ts;
        if (n[s] < n[e] || (n[s] == n[e] && strcmp(w[s], w[e]) > 0))
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
            ts = w[s];
            w[s] = w[e];
            w[e] = ts;
        }

        if (s + 1 == e)
            return;

        int cs = s;
        int ce = e;

        for (int i = s + 1; i <= e; i ++)
        {
            while (n[i] > n[s] || (n[i] == n[s] && strcmp(w[i], w[s]) < 0)) i ++;
            while (n[e] < n[s] || (n[e] == n[s] && strcmp(w[e], w[s]) > 0)) e --;

            if (i >= e)
            {
                t = n[s];
                n[s] = n[e];
                n[e] = t;

                ts = w[s];
                w[s] = w[e];
                w[e] = ts;
            }
            else
            {
                t = n[i];
                n[i] = n[e];
                n[e] = t;

                ts = w[i];
                w[i] = w[e];
                w[e] = ts;
            }
        }
        acsc_sort(n, w, cs, e - 1);
        acsc_sort(n, w, e + 1, ce);
    }

public:
    AutocompleteSystem(vector<string> v_sentences, vector<int> v_times)
    {
        r = cNode();
        c = r;
        ci = 0;
        failed = false;
        bool sort = false;
        size = v_sentences.size();

        hs[0] = strdup(v_sentences[0].c_str());
        hsn[0] = v_times[0];

        for (int i = 1; i < size; i ++)
        {
            hs[i] = strdup(v_sentences[i].c_str());
            hsn[i] = v_times[i];

            if (hsn[i] > hsn[i - 1])
                sort = true;
            else if (hsn[i] == hsn[i - 1])
            {
                if (strcmp(hs[i],  hs[i - 1]) < 0)
                    sort = true;
            }
        }

        if (sort)
            acsc_sort(hsn, hs, 0, size - 1);

        for (int i = 0; i < size; i ++)
            aNode(r, hs[i], i);
    }

    vector<string> input(char w)
    {
        if (w == '#')
        {
            int id;
            cs[ci] = 0;

            if (c->e && !failed)
            {
                id = c->e - 1;
                hsn[id] ++;
            }
            else
            {
                id = size;
                hs[id] = strdup(cs);
                hsn[id] = 1;
                size += 1;
            }

            uNode(r, id);

            ci = 0;
            c = r;
            failed = false;
            return empty;
        }

        cs[ci ++] = w;

        if (failed)
            return empty;

        if (w == ' ')
            w = 26;
        else
            w -= 'a';

        if (!(c->f & (1 << w)))
        {
            failed = true;
            return empty;
        }

        vector<string> tmp;
        c = c->n[w];

        for (int i = 0; i < c->i; i ++)
            tmp.push_back(string(hs[c->s[i]]));
        return tmp;
    }
};
*/

#define N 101
#define T 3
#define C 27 // 26 + ' '

typedef struct _ACNode
{
    int e;
    int f;
    int i;
    int s[T];
    struct _ACNode* n[C];
} ACNode;

ACNode* cNode()
{
    ACNode* n = malloc(sizeof(ACNode));
    n->f = 0;
    n->i = 0;
    n->e = 0;
    return n;
}

void aNode(ACNode* r, char* s, int id)
{
    int i = 0;
    int c = s[i ++];

    while (c)
    {
        if (c == ' ')
            c = 26;
        else
            c -= 'a';

        if (!(r->f & (1 << c)))
        {
            r->f |= 1 << c;
            r->n[c] = cNode();
        }

        r = r->n[c];

        if (r->i < T)
        {
            r->s[r->i] = id;
            r->i += 1;
        }

        c = s[i ++];
    }
    r->e = id + 1;
}

void uNode(ACNode* r, int id, char** hs, int* hsn)
{
    int i = 0;
    char* s = hs[id];
    int n = hsn[id];
    int c = s[i ++];

    while (c)
    {
        if (c == ' ')
            c = 26;
        else
            c -= 'a';

        if (!(r->f & (1 << c)))
        {
            r->f |= 1 << c;
            r->n[c] = cNode();
        }
        r = r->n[c];

        if (r->i == 0)
        {
            r->s[r->i] = id;
            r->i += 1;
        }
        else if (!(r->i == T && hsn[r->s[T - 1]] > n))
        {
            int ti = 0;
            int t[T] = {0};
            bool use = false;

            bool found = -1;
            for (int j = 0; j < r->i; j ++)
                if (id == r->s[j])
                    found = j;

            for (int j = 0; j < r->i; j ++)
            {
                int in = r->s[j];
                int inn = hsn[in];

                if (inn > n || use)
                {
                    if (id != in)
                        t[ti ++] = in;
                }
                else
                {
                    if (in == id || inn < n || strcmp(s, hs[in]) < 0)
                    {
                        j -= !!(in != id);
                        t[ti ++] = id;
                        use = true;
                    }
                    else
                    {
                        t[ti ++] = in;
                    }
                }
                printf("== %d  %d %d %s\n", r->i, use, j, hs[id]);
            out(r->s, T);
            out(t, T);


                if (ti == T)
                    break;
            }

            if (ti != T && !use)
                t[ti ++] = id;

            r->i = ti;
            for (int j = 0; j < T; j ++)
                r->s[j] = t[j];
        }

        c = s[i ++];
    }

    r->e = id + 1;
}

typedef struct {
    int size;
    char* hs[N];
    int hsn[N];
    ACNode* r;

    int ci;
    char cs[N];
    ACNode* c;
    bool failed;
} AutocompleteSystem;

void acsc_sort(int* n, char** w, int s, int e)
{
    if (s >= e)
        return;

    int t;
    char* ts;
    if (n[s] < n[e] || (n[s] == n[e] && strcmp(w[s], w[e]) > 0))
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
        ts = w[s];
        w[s] = w[e];
        w[e] = ts;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] > n[s] || (n[i] == n[s] && strcmp(w[i], w[s]) < 0)) i ++;
        while (n[e] < n[s] || (n[e] == n[s] && strcmp(w[e], w[s]) > 0)) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            ts = w[s];
            w[s] = w[e];
            w[e] = ts;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            ts = w[i];
            w[i] = w[e];
            w[e] = ts;
        }
    }
    acsc_sort(n, w, cs, e - 1);
    acsc_sort(n, w, e + 1, ce);
}

AutocompleteSystem* autocompleteSystemCreate(char** sentences, int* times, int size) {
    AutocompleteSystem* a = malloc(sizeof(AutocompleteSystem));
    a->r = cNode();
    a->c = a->r;
    a->ci = 0;
    a->failed = false;

    bool sort = false;

    for (int i = 1; i < size; i ++)
    {
        if (times[i] > times[i - 1])
        {
            sort = true;
            break;
        }
        else if (times[i] == times[i - 1])
        {
            if (strcmp(sentences[i],  sentences[i - 1]) < 0)
            {
                sort = true;
                break;
            }
        }
    }

    if (sort)
        acsc_sort(times, sentences, 0, size - 1);

    for (int i = 0; i < size; i ++)
    {
        a->hs[i] = sentences[i];
        a->hsn[i] = times[i];
        aNode(a->r, sentences[i], i);
    }

    a->size = size;
}

char** autocompleteSystemInput(AutocompleteSystem* obj, char c, int *returnSize) {
    *returnSize = 0;

    if (obj)
    {
        if (c == '#')
        {
            int id;
            obj->cs[obj->ci] = 0;

            if (obj->c->e && !obj->failed)
            {
                id = obj->c->e - 1;
                obj->hsn[id] ++;
            }
            else
            {
                id = obj->size;
                obj->hs[id] = strdup(obj->cs);
                printf("dup here %s %s.\n", obj->hs[id], obj->cs);
                obj->hsn[id] = 1;
                obj->size += 1;
            }

            printf("try add %s %s.\n", obj->hs[id], obj->cs);
            uNode(obj->r, id, obj->hs, obj->hsn);

            obj->ci = 0;
            obj->c = obj->r;
            obj->failed = false;
            return NULL;
        }

        obj->cs[obj->ci] = c;
        obj->ci += 1;

        if (obj->failed)
            return NULL;

        if (c == ' ')
            c = 26;
        else
            c -= 'a';

        if (!(obj->c->f & (1 << c)))
        {
            obj->failed = true;
            return NULL;
        }

        obj->c = obj->c->n[c];
        *returnSize = obj->c->i;
        char** r = malloc(sizeof(char*) * obj->c->i);
        for (int i = 0; i < obj->c->i; i ++)
            r[i] = obj->hs[obj->c->s[i]];

        return r;
    }
    return NULL;
}

void autocompleteSystemFree(AutocompleteSystem* obj) {
}


