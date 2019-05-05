typedef struct {
    int** hash;
    int size;
    int si;
    int* st;
} RandomizedCollection;

#define PRIMER 8209
/** Initialize your data structure here. */
RandomizedCollection* randomizedCollectionCreate() {
    RandomizedCollection* r = malloc(sizeof(RandomizedCollection));
    r->hash = calloc(sizeof(int*), PRIMER);
    r->size = 256;
    r->si = 0;
    r->st = malloc(sizeof(int) * 256);
    return r;
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {
    if (obj)
    {
        int* st = obj->st;
        int** hash = obj->hash;
        bool found = false;
        int x = val % PRIMER;
        if (x < 0)
            x += PRIMER;

        int y = 0;

        if (hash[x])
        {
            for (int i = 0; i < hash[x][0]; i ++)
                if (st[hash[x][i + 2]] == val)
                {
                    found = true;
                    break;
                }

            y = hash[x][0] + 2;

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
        return !found;
    }
    return false;
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {
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
            if (st[hash[x][i + 2]] == val)
            {
                int t = hash[x][i + 2];
                hash[x][i + 2] = hash[x][hash[x][0] - 1 + 2];
                hash[x][0] -= 1;

                obj->si --;
                st[t] = st[obj->si];

                if (t != obj->si)
                {
                    int y = st[t] % PRIMER;
                    if (y < 0)
                        y += PRIMER;

                    for (int j = 0; j < hash[y][0]; j ++)
                        if (hash[y][j + 2] == obj->si)
                        {
                            hash[y][j + 2] = t;
                            break;
                        }
                }
                return true;
            }
    }
    return false;
}

/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection* obj) {
    if (obj)
    {
        int i = random() % obj->si;
        return obj->st[i];
    }
    return 0;
}

void randomizedCollectionFree(RandomizedCollection* obj) {
    if (obj)
    {
        free(obj->st);
        free(obj->hash);
        free(obj);
    }
}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * struct RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 * bool param_2 = randomizedCollectionRemove(obj, val);
 * int param_3 = randomizedCollectionGetRandom(obj);
 * randomizedCollectionFree(obj);
 */
