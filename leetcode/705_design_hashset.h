#define PRIME 16411
typedef struct {
    int** n;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* m = malloc(sizeof(MyHashSet));
    m->n = calloc(sizeof(int*), PRIME);
    return m;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int x = key % PRIME;
    if (!obj->n[x] || obj->n[x][0] == obj->n[x][1])
    {
        int s = obj->n[x] ? obj->n[x][1] * 2 : 256;
        int i = obj->n[x] ? obj->n[x][0] : 0;
        obj->n[x] = realloc(obj->n[x], sizeof(int) * (s + 2));
        obj->n[x][0] = i;
        obj->n[x][1] = s;
    }

    for (int i = 0; i < obj->n[x][0]; i ++)
        if (obj->n[x][2 + i] == key)
            return;

    int i = obj->n[x][0];
    obj->n[x][2 + i] = key;
    obj->n[x][0] ++;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int x = key % PRIME;
    if (!obj->n[x])
        return;
    for (int i = 0; i < obj->n[x][0]; i ++)
        if (obj->n[x][2 + i] == key)
        {
            int e = obj->n[x][0] - 1;
            obj->n[x][2 + i] = obj->n[x][2 + e];
            obj->n[x][0] --;
            return;
        }
}

/** Returns true if this set did not already contain the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int x = key % PRIME;
    if (!obj->n[x])
        return false;
    for (int i = 0; i < obj->n[x][0]; i ++)
        if (obj->n[x][2 + i] == key)
            return true;
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    if (obj)
        free(obj->n);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * struct MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */
