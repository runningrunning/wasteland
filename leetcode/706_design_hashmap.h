#define PRIME 16411
typedef struct {
    long** n;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* m = malloc(sizeof(MyHashMap));
    m->n = calloc(sizeof(long*), PRIME);
    return m;
}

/** value will always be positive. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int x = key % PRIME;
    if (!obj->n[x] || obj->n[x][0] == obj->n[x][1])
    {
        int s = obj->n[x] ? obj->n[x][1] * 2 : 256;
        int i = obj->n[x] ? obj->n[x][0] : 0;
        obj->n[x] = realloc(obj->n[x], sizeof(long) * (s + 2));
        obj->n[x][0] = i;
        obj->n[x][1] = s;
    }

    for (int i = 0; i < obj->n[x][0]; i ++)
    {
        long t = obj->n[x][i + 2];

        if ((t >> 32) == (long) key)
        {
            obj->n[x][i + 2] = ((long) key) << 32 | (long) value;
            return;
        }
    }

    int i = obj->n[x][0];
    obj->n[x][i + 2] =  ((long) key) << 32 | (long) value;
    obj->n[x][0] ++;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    int x = key % PRIME;
    if (!obj->n[x])
        return -1;

    for (int i = 0; i < obj->n[x][0]; i ++)
    {
        long t = obj->n[x][i + 2];
        if ((t >> 32) == (long) key)
            return t & 0xFFFFFFFF;
    }

    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int x = key % PRIME;
    if (!obj->n[x])
        return;

    for (int i = 0; i < obj->n[x][0]; i ++)
    {
        long t = obj->n[x][i + 2];
        if ((t >> 32) == (long) key)
        {
            int e = obj->n[x][0] - 1;
            obj->n[x][i + 2] = obj->n[x][e + 2];
            obj->n[x][0] --;
            break;
        }
    }
    return;
}

void myHashMapFree(MyHashMap* obj) {
    if (obj)
        free(obj->n);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * struct MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 * int param_2 = myHashMapGet(obj, key);
 * myHashMapRemove(obj, key);
 * myHashMapFree(obj);
 */
