// use hash could reduce the 2nd loop of append
#define N 26
typedef struct _MapSum {
    int a;
    int v;
    int f;
    struct _MapSum* m[N];
} MapSum;

/** Initialize your data structure here. */
MapSum* mapSumCreate() {
    MapSum* m = malloc(sizeof(MapSum));
    m->v = 0;
    m->f = 0;
    m->a = 0;
    return m;
}

void mapSumInsert(MapSum* obj, char* key, int val) {
    if (obj)
    {
        int i = 0;
        int c = key[i ++];
        MapSum* s = obj;
        while (c)
        {
            c -= 'a';
            if (!(s->f & (1 << c)))
            {
                s->f |= 1 << c;
                s->m[c] = mapSumCreate();
            }
            s = s->m[c];
            c = key[i ++];
        }

        int r = val - s->v;
        s->v = val;
        s->a += r;

        // use hash to reduce this loop !
        if (r)
        {
            int i = 0;
            int c = key[i ++];
            MapSum* s = obj;
            while (c)
            {
                c -= 'a';
                s->a += r;
                s = s->m[c];
                c = key[i ++];
            }
        }
    }
}

int mapSumSum(MapSum* obj, char* prefix) {
    if (obj)
    {
        int i = 0;
        int c = prefix[i ++];
        MapSum* s = obj;
        while (c)
        {
            c -= 'a';
            if (!(s->f & (1 << c)))
                return 0;
            s = s->m[c];
            c = prefix[i ++];
        }
        return s->a;
    }
    return 0;
}

void mapSumFree(MapSum* obj) {
    if (obj)
    {
        for (int i = 0; i < N; i ++)
            if (obj->f & (1 << i))
                mapSumFree(obj->m[i]);
        free(obj);
    }
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * struct MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 * int param_2 = mapSumSum(obj, prefix);
 * mapSumFree(obj);
 */
