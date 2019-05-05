// [t - 3000, t]
// how to write correct code ?
#define MOD 3006

typedef struct {
    int st;
    int en;
    int* rcs;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* r = malloc(sizeof(RecentCounter));
    r->rcs = malloc(sizeof(int) * MOD);
    r->st = 0;
    r->en = -1;
    return r;
}

int recentCounterPing(RecentCounter* obj, int t) {
    if (!obj)
        return 0;
    /* if (obj->en == -1) */
    /*     obj->rcs[obj->st] = t; */

    obj->en ++;
    obj->rcs[obj->en % MOD] = t;

    int st = obj->st;
    int en = obj->en;

    while (st < en)
    {
        int m = st + (en - st) / 2;
        int im = m % MOD;

        if (obj->rcs[im] < t - 3000)
            st = m + 1;
        else
            en = m;
    }
    obj->st = st;
    return obj->en - obj->st + 1;
}

void recentCounterFree(RecentCounter* obj) {
    if (obj)
    {
        free(obj->rcs);
        free(obj);
    }
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * struct RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */
