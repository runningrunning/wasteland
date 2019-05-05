typedef struct {
    int all;
    long rand;
    int* w;
    int s;
} Solution;

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

Solution* solutionCreate(int* w, int wSize) {
    Solution * s = malloc(sizeof(Solution));
    for (int i = 1; i < wSize; i ++)
        w[i] += w[i - 1];

    s->w = w;
    s->s = wSize;
    s->rand = _random((long) s);

    if (wSize)
        s->all = w[wSize - 1];
    return s;
}

int solutionPickIndex(Solution* obj) {
    if (obj && obj->s > 1)
    {
        obj->rand = _random(obj->rand);

        int r = (obj->rand % obj->all) + 1;


        int s = 0;
        int e = obj->s - 1;
        int* w = obj->w;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (w[m] < r)
                s = m + 1;
            else
                e = m;
        }
        return s;
    }
    return 0;
}

void solutionFree(Solution* obj) {
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 * solutionFree(obj);
 */
