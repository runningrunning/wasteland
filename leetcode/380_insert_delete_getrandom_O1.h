// don't use linear probing
// corner cases !!!
typedef struct {
    int** hash;
    int size;
    int si;
    int* st;
} RandomizedSet;

#define PRIMER 8209
/** Initialize your data structure here. */
RandomizedSet* randomizedSetCreate() {
    RandomizedSet* r = malloc(sizeof(RandomizedSet));
    r->hash = calloc(sizeof(int*), PRIMER);
    r->size = 256;
    r->si = 0;
    r->st = malloc(sizeof(int) * 256);
    return r;
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (obj)
    {
        int* st = obj->st;
        int** hash = obj->hash;
        int x = val % PRIMER; // hash can be negative
        if (x < 0)
            x += PRIMER;

        int y = 0;

        if (hash[x])
        {
            for (int i = 0; i < hash[x][0]; i ++)
                if (st[hash[x][i + 2]] == val)
                    return false;

            y = hash[x][0] + 2; // must add 2 !!!

            if (y == hash[x][1])
            {
                hash[x][1] += 10;
                hash[x] = realloc(hash[x], sizeof(int) * (hash[x][1] + 2));
            }

            hash[x][0] += 1;
        }
        else
        {
            hash[x] = malloc(sizeof(int) * (10 + 2));
            hash[x][0] = 1;
            hash[x][1] = 10;
            y = 2;
        }

        if (obj->si == obj->size)
        {
            obj->size *= 2;
            obj->st = realloc(obj->st, sizeof(int) * obj->size);
            st = obj->st;
        }

        st[obj->si] = val;
        hash[x][y] = obj->si;
        obj->si += 1;
        return true;
    }
    return false;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val)
{
    if (obj)
    {
        int* st = obj->st;
        int** hash = obj->hash;
        int x = val % PRIMER;
        if (x < 0)
            x += PRIMER;
        if (!hash[x])
            return false;

        for (int i = 0; i < hash[x][0]; i ++)
            if (st[hash[x][2 + i]] == val)
            {
                int t = hash[x][2 + i];
                hash[x][2 + i] = hash[x][2 + hash[x][0] - 1];
                hash[x][0] -= 1;
                obj->si --;
                st[t] = st[obj->si];

                if (t != obj->si)
                {
                    int y = st[t] % PRIMER;
                    if (y < 0)
                        y += PRIMER;

                    for (int j = 0; j < hash[y][0]; j ++)
                        if (hash[y][2 + j] == obj->si)
                        {
                            hash[y][2 + j] = t;
                            break;
                        }
                }
                return true;
            }
    }
    return false;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    if (obj)
    {
        int i = rand() % obj->si;
        return obj->st[i];
    }
    return 0;
}

void randomizedSetFree(RandomizedSet* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj->st);
        free(obj);
    }
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * struct RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 * bool param_2 = randomizedSetRemove(obj, val);
 * int param_3 = randomizedSetGetRandom(obj);
 * randomizedSetFree(obj);
 */
