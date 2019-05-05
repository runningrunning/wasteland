typedef struct {
    int num;
    int off;
    int size;
    int v_all;
    int* all;
} MovingAverage;

/** Initialize your data structure here. */
MovingAverage* movingAverageCreate(int size) {
    if (!size)
        return NULL;

    MovingAverage* m = malloc(sizeof(MovingAverage));
    m->num = 0;
    m->off = 0;
    m->size = size;
    m->v_all = 0;
    m->all = malloc(sizeof(int) * size);
    memset(m->all, 0, sizeof(int) * size);
    return m;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (!obj)
        return 0;

    obj->num ++;

    double size = obj->size;

    if (obj->num < obj->size)
        size = obj->num;

    obj->v_all -= obj->all[obj->off];
    obj->v_all += val;
    obj->all[obj->off] = val;
    obj->off ++;
    obj->off %= obj->size;
    return obj->v_all / size;
}

void movingAverageFree(MovingAverage* obj) {
    if (!obj)
        return;

    free(obj->all);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * struct MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 * movingAverageFree(obj);
 */
