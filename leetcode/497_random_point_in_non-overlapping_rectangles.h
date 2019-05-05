// UNIFORMILY !!!
// be careful about offset-1 error !!
typedef struct {
    int rsize;
    int** rs;
    int* add;
    int all;
    int rand;
} Solution;

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

Solution* solutionCreate(int** rects, int rectsSize) {
    Solution* s = malloc(sizeof(Solution));
    s->rsize = rectsSize;
    s->rs = rects;
    s->add = malloc(sizeof(int) * rectsSize);

    int a = 0;
    for (int i = 0; i < rectsSize; i ++)
    {
        int* r = rects[i];
        a += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        s->add[i] = a;
    }
    s->all = a;
    s->rand = _random((long) s);
    return s;
}

int* solutionPick(Solution* obj, int *returnSize) {
    int* r = malloc(sizeof(int) * 2);
    *returnSize = 2;

    int x = obj->rand % obj->all;
    obj->rand = _random(obj->rand);

    int s = 0;
    int e = obj->rsize - 1;
    x += 1;

    while (s < e)
    {
        int m = (s + e) / 2;

        if (obj->add[m] < x)
            s = m + 1;
        else
            e = m;
    }

    if (s != 0)
        x -= obj->add[s - 1];

    // be careful about corner case !!!!
    x -= 1; // for offset - 1 INDEX

    int cl = obj->rs[s][2] - obj->rs[s][0] + 1;
    r[0] = obj->rs[s][0] + x % cl;
    r[1] = obj->rs[s][1] + x / cl;
    return r;
}

void solutionFree(Solution* obj)
{
    if (obj)
        free(obj->add);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(rects, rectsSize);
 * int* param_1 = solutionPick(obj);
 * solutionFree(obj);
 */
