typedef struct {
    int* ms;
    int* ss;
    int smax;
    int top;
    int cmin;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* s = malloc(sizeof(MinStack));
    s->cmin = INT_MIN;
    s->smax = maxSize - 1;
    s->top = -1;
    s->ms = malloc(sizeof(int) * maxSize);
    s->ss = malloc(sizeof(int) * maxSize);
    return s;
}

void minStackPush(MinStack* obj, int x) {
    if (!obj || obj->top == obj->smax)
        return;

    int c = ++ obj->top;

    if (!c || obj->cmin > x)
        obj->cmin = x;

    obj->ms[c] = obj->cmin;
    obj->ss[c] = x;
}

void minStackPop(MinStack* obj) {
    if (!obj || obj->top < 0)
        return;
    obj->top --;
    /* need to reset current min number */
    obj->cmin = obj->ms[obj->top];
}

int minStackTop(MinStack* obj) {
    if (!obj || obj->top < 0)
        return INT_MIN;
    return obj->ss[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (!obj || obj->top < 0)
        return INT_MIN;
    return obj->ms[obj->top];
}

void minStackFree(MinStack* obj) {
    if (obj)
    {
        free(obj->ss);
        free(obj->ms);
        obj->ss = obj->ms = NULL;
        free(obj);
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
