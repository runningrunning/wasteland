typedef struct _CacheNode {
    struct _CacheNode* pre;
    struct _CacheNode* post;
    int key;
    int val;
} CacheNode;

typedef struct _HashNode {
    int i;
    int s;
    CacheNode** c;
} HashNode;

typedef struct {
    int primer;
    HashNode** hash;

    int num;
    int cap;

    CacheNode* last;
    CacheNode* head;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 3 > capacity)
            break;
    }

    LRUCache* l = malloc(sizeof(LRUCache));
    l->primer = dp;
    l->num = 0;
    l->cap = capacity;
    l->hash = calloc(sizeof(HashNode*), l->primer);
    l->last = NULL;
    l->head = NULL;
    return l;
}

void access(LRUCache* obj, CacheNode* n)
{
    if (!obj->head)
    {
        obj->head = n;
        obj->last = n;
        return;
    }

    if (obj->head == n)
        return;

    if (obj->last == n)
        obj->last = n->pre;

    if (n->pre)
        n->pre->post = n->post;

    if (n->post)
        n->post->pre = n->pre;

    n->post = obj->head;
    obj->head->pre = n;
    n->pre = NULL;

    obj->head = n;

    if (obj->cap == 1)
        obj->last = n;

    obj->last->post = NULL;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    if (obj && obj->cap)
    {
        int x = key % obj->primer;
        if (obj->hash[x])
        {
            HashNode* h = obj->hash[x];
            for (int i = 0; i < h->i; i ++)
            {
                if (h->c[i]->key == key)
                {
                    access(obj, h->c[i]);
                    return h->c[i]->val;
                }
            }
        }
    }
    return - 1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj)
    {
        if (!obj->cap)
            return;

        int x = key % obj->primer;
        HashNode* h = NULL;

        if (obj->hash[x])
        {
            h = obj->hash[x];

            for (int i = 0; i < h->i; i ++)
            {
                if (h->c[i]->key == key)
                {
                    h->c[i]->val = value;
                    access(obj, h->c[i]);
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
            c->pre = c->post = NULL;
        }
        else
        {
            c = obj->last;
            int ox = c->key % obj->primer;
            HashNode* oh = obj->hash[ox];

            for (int i = 0; i < oh->i; i ++)
            {
                if (oh->c[i] == c)
                {
                    oh->i --;
                    oh->c[i] = oh->c[oh->i];
                    break;
                }
            }
        }

        h->c[h->i] = c;
        h->i ++;
        c->key = key;
        c->val = value;
        access(obj, c);
    }
}

void lRUCacheFree(LRUCache* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj);
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
