// be more careful !!!
struct _FreNode;
typedef struct _CacheNode {
    struct _CacheNode* pre;
    struct _CacheNode* post;

    struct _FreNode* fre;

    int num;
    int key;
    int val;
} CacheNode;

typedef struct {
    int i;
    int s;
    CacheNode** c;
} HashNode;

typedef struct _FreNode
{
    struct _FreNode* pre;
    struct _FreNode* post;

    CacheNode* head;
    CacheNode* last;

    int fre;
} FreNode;

typedef struct {
    int primer;
    HashNode** hash;

    int num;
    int cap;

    FreNode* head;
    FreNode* last;
    FreNode* free;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 3 > capacity)
            break;
    }

    LFUCache* l = malloc(sizeof(LFUCache));
    l->primer = dp;
    l->hash = calloc(sizeof(HashNode*), l->primer);
    l->num = 0;
    l->cap = capacity;
    l->free = l->head = l->last = NULL;
    return l;
}

/* void _access(LFUCache* obj, CacheNode* n) */
/* { */
/*     n->num ++; */

/*     FreNode* l = NULL; */

/*     if (n->fre) */
/*     { */
/*         l = n->fre; */

/*         if (l->head == l->last && (!l->pre || l->pre->fre > (l->fre + 1))) */
/*         { */
/*             l->fre ++; */
/*             return; */
/*         } */
/*         else if (!l->pre) */
/*         { */
/*             FreNode* nl = NULL; */

/*             if (obj->free) */
/*             { */
/*                 nl = obj->free; */
/*                 obj->free = nl->post; */
/*             } */
/*             else */
/*             { */
/*                 nl = malloc(sizeof(FreNode)); */
/*                 nl->pre = nl->post = NULL; */
/*                 nl->head = nl->last = NULL; */
/*             } */

/*             if (n->pre) */
/*                 n->pre->post = n->post; */
/*             else */
/*                 n->fre->head = n->post; */

/*             if (n->post) */
/*                 n->post->pre = n->pre; */
/*             else */
/*                 n->fre->last = n->pre; */

/*             n->pre = n->post = NULL; */
/*             n->fre = NULL; */

/*             l->pre = nl; */
/*             nl->post = l; */
/*             nl->pre = NULL; */
/*             obj->head = nl; */

/*             l = nl; */
/*         } */
/*         else */
/*         { */
/*             FreNode* ol = l->pre; */

/*             if (l->head == l->last) */
/*             { */
/*                 l->head = l->last = NULL; */
/*                 l->pre->post = l->post; */

/*                 if (l->post) */
/*                     l->post->pre = l->pre; */
/*                 else */
/*                     obj->last = l->pre; */

/*                 l->post = obj->free; */
/*                 l->pre = NULL; */
/*                 l->head = l->last = NULL; */
/*                 obj->free = l; */

/*                 l = ol; */
/*             } */
/*             else */
/*             { */
/*                 if (l->pre->fre == n->num) */
/*                 { */
/*                     if (n->pre) */
/*                         n->pre->post = n->post; */
/*                     else */
/*                         n->fre->head = n->post; */

/*                     if (n->post) */
/*                         n->post->pre = n->pre; */
/*                     else */
/*                         n->fre->last = n->pre; */

/*                     n->pre = n->post = NULL; */
/*                     n->fre = NULL; */
/*                     l = ol; */
/*                 } */
/*                 else */
/*                 { */
/*                     FreNode* nl = NULL; */

/*                     if (obj->free) */
/*                     { */
/*                         nl = obj->free; */
/*                         obj->free = nl->post; */
/*                     } */
/*                     else */
/*                     { */
/*                         nl = malloc(sizeof(FreNode)); */
/*                         nl->pre = nl->post = NULL; */
/*                         nl->head = nl->last = NULL; */
/*                     } */

/*                     nl->post = l->post; */
/*                     nl->pre = l->pre; */

/*                     if (l->post) */
/*                         l->post->pre = nl; */
/*                     else */
/*                         obj->last = nl; */

/*                     if (l->pre) */
/*                         l->pre->post = nl; */
/*                     else */
/*                         obj->head = nl; */

/*                     l = nl; */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     else */
/*     { */
/*         if (obj->last && obj->last->fre == n->num) */
/*             l = obj->last; */
/*         else */
/*         { */
/*             if (obj->free) */
/*             { */
/*                 l = obj->free; */
/*                 obj->free = l->post; */
/*             } */
/*             else */
/*                 l = malloc(sizeof(FreNode)); */

/*             l->pre = l->post = NULL; */
/*             l->head = l->last = NULL; */

/*             if (!obj->head) */
/*             { */
/*                 obj->head = l; */
/*                 obj->last = l; */
/*             } */
/*             else */
/*             { */
/*                 obj->last->post = l; */
/*                 l->pre = obj->last; */
/*                 obj->last = l; */
/*             } */

/*             l->fre = n->num; */
/*         } */

/*         n->fre = l; */
/*     } */

/*     if (l) */
/*     { */
/*         l->fre = n->num; */

/*         if (!l->head) */
/*         { */
/*             l->head = n; */
/*             l->last = n; */
/*         } */
/*         else */
/*         { */
/*             l->head->pre = n; */
/*             n->post = l->head; */
/*             n->pre = NULL; */
/*             l->head = n; */
/*         } */
/*     } */
/* } */

/* CacheNode* _evict(LFUCache* obj) */
/* { */
/*     FreNode* l = obj->last; */

/*     CacheNode* c = l->last; */

/*     if (l->head == l->last) */
/*     { */
/*         l->head = l->last = NULL; */

/*         if (l->pre) */
/*             l->pre->post = l->post; */
/*         else */
/*             obj->head = l->post; */

/*         if (l->post) */
/*             l->post->pre = l->pre; */
/*         else */
/*             obj->last = l->pre; */

/*         l->post = obj->free; */
/*         l->pre = NULL; */
/*         l->head = l->last = NULL; */

/*         obj->free = l; */
/*     } */
/*     else */
/*     { */
/*         l->last = l->last->pre; */
/*         l->last->post = NULL; */
/*     } */

/*     int key = c->key; */
/*     int x = key % obj->primer; */
/*     HashNode* h = obj->hash[x]; */
/*     if (h) */
/*     { */
/*         for (int i = 0; i < h->i; i ++) */
/*         { */
/*             if (h->c[i]->key == key) */
/*             { */
/*                 h->i --; */
/*                 h->c[i] = h->c[h->i]; */
/*                 break; */
/*             } */
/*         } */
/*     } */
/*     return c; */
/* } */

bool _remove_fre(LFUCache* o, FreNode* l)
{
    if (!l->head && !l->last)
    {
        if (l->pre)
            l->pre->post = l->post;
        else
            o->head = l->post;

        if (l->post)
            l->post->pre = l->pre;
        else
            o->last = l->pre;

        l->pre = NULL;
        l->post = o->free;
        o->free = l;
        return true;
    }
    return false;
}

void _remove_cache(CacheNode* c)
{
    if (!c->fre)
        return;

    FreNode* l = c->fre;

    if (c->pre)
        c->pre->post = c->post;
    else
        l->head = c->post;

    if (c->post)
        c->post->pre = c->pre;
    else
        l->last = c->pre;

    c->fre = NULL;
    c->pre = c->post = NULL;
}

void _remove_hash(LFUCache* o, CacheNode* c)
{
    int key = c->key;
    int x = key % o->primer;
    HashNode* h = o->hash[x];

    for (int i = 0; i < h->i; i ++)
    {
        if (h->c[i]->key == key)
        {
            h->i --;
            h->c[i] = h->c[h->i];
            break;
        }
    }
}

FreNode* _new_fre(LFUCache* obj)
{
    FreNode* l = NULL;

    if (obj->free)
    {
        l = obj->free;
        obj->free = obj->free->post;
    }
    else
        l = malloc(sizeof(FreNode));

    l->pre = l->post = NULL;
    l->head = l->last = NULL;
    l->fre = 0;

    return l;
}

void _access(LFUCache* obj, CacheNode* n)
{
    n->num ++;
    FreNode* p = NULL;
    FreNode* l = n->fre;

    if (!l)
    {
        if (obj->last)
        {
            if (obj->last->fre == n->num)
                l = obj->last;
            else
            {
                p = obj->last;
                l = _new_fre(obj);

                obj->last->post = l;
                l->pre = obj->last;
                obj->last = l;
            }
        }
        else
        {
            l = _new_fre(obj);
            obj->head = l;
            obj->last = l;
        }
    }
    else
    {
        p = l->pre;

        _remove_cache(n);

        if (_remove_fre(obj, l))
            l = NULL;

        if (p)
        {
            if (p->fre == n->num)
                l = p;
            else
            {
                l = _new_fre(obj);

                if (p->post)
                    l->post = p->post;
                else
                    obj->last = l;

                l->pre = p;
                p->post = l;
            }
        }
        else
        {
            p = _new_fre(obj);

            if (!obj->head) // only update when there is no obj->head
            {
                obj->head = p;
                obj->last = p;
            }
            else
            {
                p->post = obj->head;
                obj->head->pre = p;
                obj->head = p;
            }

            l = p;
        }
    }

    l->fre = n->num;
    n->fre = l;

    if (!l->head)
    {
        l->head = n;
        l->last = n;
    }
    else
    {
        n->post = l->head;
        l->head->pre = n;
        l->head = n;
    }
}

CacheNode* _evict(LFUCache* obj)
{
    FreNode* l = obj->last;
    CacheNode* c = l->last;

    _remove_cache(c);
    _remove_fre(obj, l);
    _remove_hash(obj, c);

    c->fre = NULL;
    c->pre = c->post = NULL;
    return c;
}

int lFUCacheGet(LFUCache* obj, int key)
{
    if (obj && obj->cap)
    {
        int x = key % obj->primer;
        HashNode* h = obj->hash[x];

        if (h)
        {
            for (int i = 0; i < h->i; i ++)
            {
                if (h->c[i]->key == key)
                {
                    _access(obj, h->c[i]);
                    return h->c[i]->val;
                }
            }
        }
    }
    return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj && obj->cap)
    {
        int x = key % obj->primer;
        HashNode* h = obj->hash[x];

        if (h)
        {
            for (int i = 0; i < h->i; i++)
            {
                if (h->c[i]->key == key)
                {
                    h->c[i]->val = value;
                    _access(obj, h->c[i]);
                    return;
                }
            }

            if (h->i == h->s)
            {
                h->s *= 2;
                h->c = realloc(h->c, sizeof(CacheNode*) * h->s);
            }
        }
        else
        {
            h = malloc(sizeof(HashNode));
            h->i = 0;
            h->s = 10;
            h->c = malloc(sizeof(CacheNode*) * h->s);
            obj->hash[x] = h;
        }

        CacheNode* c = NULL;

        if (obj->num != obj->cap)
        {
            obj->num ++;
            c = malloc(sizeof(CacheNode));
        }
        else
        {
            c = _evict(obj);
        }

        h->c[h->i] = c;
        h->i ++;

        c->pre = c->post = NULL;
        c->fre = NULL;

        c->num = 0; // update in _access
        c->key = key;
        c->val = value;
        _access(obj, c);
    }
}

void lFUCacheFree(LFUCache* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj);
    }
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * struct LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 * lFUCachePut(obj, key, value);
 * lFUCacheFree(obj);
 */
