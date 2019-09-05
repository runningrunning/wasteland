// how about lock multiple times ?
// seems does work, can not lock multiple times
typedef struct {
    pthread_mutex_t foo;
    pthread_mutex_t bar;
    int n;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->foo, NULL);
    pthread_mutex_init(&obj->bar, NULL);
    pthread_mutex_lock(&obj->bar);
    return obj;
}

void foo(FooBar* obj) {
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->foo);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(&obj->bar);
    }
}

void bar(FooBar* obj) {
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->bar);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(&obj->foo);
    }
}

void fooBarFree(FooBar* obj)
{
    pthread_mutex_unlock(&obj->foo);
    pthread_mutex_unlock(&obj->bar);
    pthread_mutex_destroy(&obj->foo);
    pthread_mutex_destroy(&obj->bar);
    free(obj);
}
