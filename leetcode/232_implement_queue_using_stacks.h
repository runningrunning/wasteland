typedef struct
{
    bool dirt;
    int used;
    int size;
    int peek;
    int in_i;
    int out_i;
    int* in_stack;
    int* out_stack;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize)
{
    if (!maxSize)
        return NULL;

    MyQueue* m = malloc(sizeof(MyQueue));
    m->used = 0;
    m->size = maxSize;
    m->peek = 0;
    m->dirt = true;
    m->in_i = 0;
    m->out_i = 0;
    m->in_stack = malloc(sizeof(int) * maxSize);
    m->out_stack = malloc(sizeof(int) * maxSize);
    return m;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
    return !obj || !obj->used;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
    if (!obj || obj->size <= obj->used)
        return;
    obj->dirt = true;
    obj->used ++;
    if (!obj->in_i)
        obj->peek = x;
    obj->in_stack[obj->in_i ++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    if (myQueueEmpty(obj))
        return 0;

    obj->out_i = 0;
    for (int i = 0; i < obj->used - 1; i ++)
    {
        obj->peek = obj->in_stack[-- obj->in_i];
        obj->out_stack[obj->out_i ++] = obj->peek;
    }

    int v = obj->in_stack[-- obj->in_i];
    for (int i = 0; i < obj->used - 1; i ++)
        obj->in_stack[obj->in_i ++] = obj->out_stack[-- obj->out_i];

    obj->used --;
    return v;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    if (myQueueEmpty(obj))
        return 0;
    return obj->peek;
}

void myQueueFree(MyQueue* obj)
{
    if (obj)
    {
        free(obj->in_stack);
        free(obj->out_stack);
        free(obj);
    }
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
