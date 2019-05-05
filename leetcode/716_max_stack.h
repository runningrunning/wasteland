typedef struct {
    int id;
    int size;

    int si;
    int* st;
    int* sid;

    int hi;
    long* hp;
} MaxStack;

/** initialize your data structure here. */
MaxStack* maxStackCreate(int maxSize) {
    MaxStack* s = malloc(sizeof(MaxStack));

    s->st = malloc(sizeof(int) * (maxSize + 1));
    s->sid = malloc(sizeof(int) * (maxSize + 1));
    s->hp = malloc(sizeof(long) * (maxSize + 1));

    s->si = s->hi = s->id = 0;
    s->size = maxSize;
    return s;
}

void aHeap(long* hp, int id, int v, int si, int hi)
{
    long t = (((long) v) << 32) | id << 16 | si;
    hp[hi] = t;

    if (hi == 0)
        return;

    int x = hi;
    while (x)
    {
        int p = (x - 1) >> 1;
        if (hp[p] >= hp[x])
            return;
        hp[x] = hp[p];
        hp[p] = t;
        x = p;
    }
}

int vHeap(long* hp, int* st, int* sid, int hi)
{
    while (true)
    {
        int index = hp[0] & 0xFFFF;
        int id = (hp[0] >> 16) & 0xFFFF;
        int v = hp[0] >> 32;
        if (st[index] == v && sid[index] == id)
            break;

        int x = 0;
        hp[x] = hp[-- hi];

        long p = hp[x];
        while (x * 2 + 1 < hi)
        {
            long l = hp[x * 2 + 1];
            long r = l;

            if (x * 2 + 2 < hi)
                r = hp[x * 2 + 2];

            if (l >= r)
            {
                if (l <= p)
                    break;

                hp[x] = l;
                hp[x * 2 + 1] = p;
                x = x * 2 + 1;
            }
            else
            {
                if (r <= p)
                    break;

                hp[x] = r;
                hp[x * 2 + 2] = p;
                x = x * 2 + 2;
            }
        }
    }
    return hi;
}

void maxStackPush(MaxStack* obj, int x) {
    if (obj)
    {
        obj->st[obj->si] = x;
        obj->sid[obj->si] = obj->id;
        aHeap(obj->hp, obj->id, x, obj->si, obj->hi);

        obj->si ++;
        obj->hi ++;
        obj->id ++;
    }
}

int maxStackPop(MaxStack* obj) {
    int x = 0;
    if (obj)
    {
        while (true && obj->si)
        {
            obj->si --;
            x = obj->st[obj->si];
            if (obj->sid[obj->si] >= 0)
                break;
        }
        if (obj->si >= 0)
            obj->sid[obj->si] = -1;
    }
    return x;
}

int maxStackTop(MaxStack* obj) {
    int x = 0;
    if (obj)
    {
        while (true && obj->si)
        {
            x = obj->st[obj->si - 1];
            if (obj->sid[obj->si - 1] >= 0)
                break;
            obj->si --;
        }
    }
    return x;
}

int maxStackPeekMax(MaxStack* obj) {
    if (obj)
    {
        obj->hi = vHeap(obj->hp, obj->st, obj->sid, obj->hi);
        long x = obj->hp[0];
        return (int) (x >> 32);
    }
    return 0;
}

int maxStackPopMax(MaxStack* obj) {
    if (obj)
    {
        obj->hi = vHeap(obj->hp, obj->st, obj->sid, obj->hi);
        long x = obj->hp[0];
        int index = x & 0xFFFF;
        int v = x >> 32;
        printf("%d %d %d.\n", index, v, obj->hi);
        obj->sid[index] = -1;
        return v;
    }
    return 0;
}

void maxStackFree(MaxStack* obj) {
    if (obj)
    {
        free(obj->hp);
        free(obj->st);
        free(obj->sid);
        free(obj);
    }
}

/**
 * Your MaxStack struct will be instantiated and called as such:
 * struct MaxStack* obj = maxStackCreate(maxSize);
 * maxStackPush(obj, x);
 * int param_2 = maxStackPop(obj);
 * int param_3 = maxStackTop(obj);
 * int param_4 = maxStackPeekMax(obj);
 * int param_5 = maxStackPopMax(obj);
 * maxStackFree(obj);
 */
