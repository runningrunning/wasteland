// without mutex and signal
// no way but cheating !!!
/*
typedef struct {
    // User defined data may be declared here.
    bool first_called;
    bool second_called;
    bool first_run;
    bool second_run;
} Foo;


Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    // Initialize user defined data here.
    obj->first_called = false;
    obj->second_called = false;
    obj->first_run = false;
    obj->second_run = false;
    return obj;
}

void first(Foo* obj) {
    // printFirst() outputs "first". Do not change or remove this line.
    obj->first_called = true;
    printFirst();
    obj->first_run = true;
}

void second(Foo* obj) {
    // printSecond() outputs "second". Do not change or remove this line.
    while (!obj->first_run);
    obj->second_called = true;
    printSecond();
    obj->second_run = true;
}

void third(Foo* obj) {
    // printThird() outputs "third". Do not change or remove this line.
    while (!obj->second_run);
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}
*/


// with mutex and signal
/*
typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t lock;
    pthread_cond_t first;
    pthread_cond_t second;
    bool is_first;
    bool is_second;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    // Initialize user defined data here.
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->first, NULL);
    pthread_cond_init(&obj->second, NULL);
    obj->is_first = false;
    obj->is_second = false;
    return obj;
}

void first(Foo* obj) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_lock(&obj->lock);
    obj->is_first = true;
    pthread_cond_signal(&obj->first);
    pthread_mutex_unlock(&obj->lock);
}

void second(Foo* obj) {
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while (!obj->is_first)
        pthread_cond_wait(&obj->first, &obj->lock);
    printSecond();
    obj->is_second = true;
    pthread_cond_signal(&obj->second);
    pthread_mutex_unlock(&obj->lock);
}

void third(Foo* obj) {
    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while (!obj->is_second)
        pthread_cond_wait(&obj->second, &obj->lock);
    printThird();
    pthread_mutex_unlock(&obj->lock);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_cond_destroy(&obj->first);
    pthread_cond_destroy(&obj->second);
    pthread_mutex_destroy(&obj->lock);
    free(obj);
}
*/

// with mutex
typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t second;
    pthread_mutex_t third;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    // Initialize user defined data here.
    pthread_mutex_init(&obj->second, NULL);
    pthread_mutex_init(&obj->third, NULL);
    pthread_mutex_lock(&obj->second);
    pthread_mutex_lock(&obj->third);
    return obj;
}

void first(Foo* obj) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_unlock(&obj->second);
}

void second(Foo* obj) {
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->second);
    printSecond();
    pthread_mutex_unlock(&obj->second);
    pthread_mutex_unlock(&obj->third);
}

void third(Foo* obj) {
    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&obj->third);
    printThird();
    pthread_mutex_unlock(&obj->third);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->second);
    pthread_mutex_destroy(&obj->third);
    free(obj);
}

