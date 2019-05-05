typedef struct {
    int start;
    int end;
    int size;
    int* n;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* m = malloc(sizeof(MyCircularDeque));
    m->n = malloc(sizeof(int) * (k + 1));
    m->start = 0;
    m->end = 0;
    m->size = k + 1;
    return m;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->start == obj->end;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {

    /* // s previous is end */
    /* if (s == obj->end) */
    /*     return true; */

    // e next is start
    int e = (obj->end + 1) % obj->size;
    if (e == obj->start)
        return true;
    return false;
}

// start is the point to the top of items
/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (!obj || myCircularDequeIsFull(obj))
        return false;

    int s = (obj->start - 1 + obj->size) % obj->size;
    obj->n[s] = value;
    obj->start = s;

    return true;
}

// end is the point to the next
/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (!obj || myCircularDequeIsFull(obj))
        return false;

    obj->n[obj->end] = value;
    obj->end = (obj->end + 1) % obj->size;

    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return false;
    obj->start = (obj->start + 1) % obj->size;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return false;
    obj->end = (obj->end - 1 + obj->size) % obj->size;
    return true;
}


/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->n[obj->start];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;
    int e = (obj->end - 1 + obj->size) % obj->size;
    return obj->n[e];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->n);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * struct MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 * bool param_3 = myCircularDequeDeleteFront(obj);
 * bool param_4 = myCircularDequeDeleteLast(obj);
 * int param_5 = myCircularDequeGetFront(obj);
 * int param_6 = myCircularDequeGetRear(obj);
 * bool param_7 = myCircularDequeIsEmpty(obj);
 * bool param_8 = myCircularDequeIsFull(obj);
 * myCircularDequeFree(obj);
 */
