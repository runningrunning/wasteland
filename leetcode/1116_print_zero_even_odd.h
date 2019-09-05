typedef struct {
    pthread_mutex_t zero;
    pthread_mutex_t odd;
    pthread_mutex_t even;
    int n;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    pthread_mutex_init(&obj->zero, NULL);
    pthread_mutex_init(&obj->odd, NULL);
    pthread_mutex_init(&obj->even, NULL);
    pthread_mutex_lock(&obj->odd);
    pthread_mutex_lock(&obj->even);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    for (int i = 1; i <= obj->n; i ++)
    {
        pthread_mutex_lock(&obj->zero);
        printNumber(0);
        if (i % 2)
            pthread_mutex_unlock(&obj->odd);
        else
            pthread_mutex_unlock(&obj->even);
    }
}

void even(ZeroEvenOdd* obj) {
    for (int i = 1; i <= obj->n; i ++)
    {
        if (i % 2)
            continue;
        pthread_mutex_lock(&obj->even);
        printNumber(i);
        pthread_mutex_unlock(&obj->zero);
    }
}

void odd(ZeroEvenOdd* obj)
{
    for (int i = 1; i <= obj->n; i ++)
    {
        if (!(i % 2))
            continue;
        pthread_mutex_lock(&obj->odd);
        printNumber(i);
        pthread_mutex_unlock(&obj->zero);
    }
}

void zeroEvenOddFree(ZeroEvenOdd* obj)
{
    pthread_mutex_destroy(&obj->even);
    pthread_mutex_destroy(&obj->odd);
    pthread_mutex_destroy(&obj->zero);
    free(obj);
}
