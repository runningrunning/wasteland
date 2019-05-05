typedef struct {
    int start;
    int end;
    int size;
    int* n;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* m = malloc(sizeof(MyCircularQueue));
    m->n = malloc(sizeof(int) * (k + 1));
    m->start = 0;
    m->end = 0;
    m->size = k + 1;
    return m;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->start == obj->end;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->end + 1) % obj->size) == obj->start;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!obj || myCircularQueueIsFull(obj))
        return false;

    obj->n[obj->end] = value;
    obj->end = (obj->end + 1) % obj->size;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj || myCircularQueueIsEmpty(obj))
        return false;

    obj->start = (obj->start + 1) % obj->size;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (!obj || myCircularQueueIsEmpty(obj))
        return -1;
    return obj->n[obj->start];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (!obj || myCircularQueueIsEmpty(obj))
        return -1;
    int e = (obj->end - 1 + obj->size) % obj->size;
    return obj->n[e];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj)
        free(obj->n);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */
