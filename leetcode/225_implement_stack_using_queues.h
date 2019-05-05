typedef struct {
    int used;
    int size;
    int q_start;
    int q_end;
    int last;
    int* qa;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    if (!maxSize)
        return NULL;

    MyStack* m = malloc(sizeof(MyStack));
    m->used = 0;
    m->size = maxSize;
    m->q_start = 0;
    m->q_end = 0;
    m->qa = malloc(sizeof(int) * maxSize);
    return m;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return !obj || !obj->used;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!obj || obj->size <= obj->used)
        return;
    obj->used ++;
    obj->last = x;
    obj->qa[obj->q_end ++] = x;
    obj->q_end %= obj->size;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj))
        return 0;

    for (int i = 0; i < obj->used - 1; i ++)
    {
        obj->last = obj->qa[obj->q_start ++];
        obj->qa[obj->q_end ++] = obj->last;
        obj->q_start %= obj->size;
        obj->q_end %= obj->size;
    }

    obj->used --;
    int v = obj->qa[obj->q_start ++];
    obj->q_start %= obj->size;
    return v;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (myStackEmpty(obj))
        return 0;
    return obj->last;
}

void myStackFree(MyStack* obj) {
    if (obj)
    {
        free(obj->qa);
        free(obj);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
