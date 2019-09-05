typedef struct {
    // User defined data may be declared here.
    int n;
    pthread_mutex_t h;
    pthread_mutex_t o;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    // Initialize user defined data here.
    pthread_mutex_init(&obj->h, NULL);
    pthread_mutex_init(&obj->o, NULL);
    pthread_mutex_lock(&obj->o);
    obj->n = 0;
    return obj;
}

void hydrogen(H2O* obj) {
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    pthread_mutex_lock(&obj->h);
    releaseHydrogen();
    obj->n += 1;
    if (obj->n % 2)
        pthread_mutex_unlock(&obj->h);
    else
        pthread_mutex_unlock(&obj->o);
}

void oxygen(H2O* obj) {
    // releaseOxygen() outputs "O". Do not change or remove this line.
    pthread_mutex_lock(&obj->o);
    releaseOxygen();
    pthread_mutex_unlock(&obj->h);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->o);
    pthread_mutex_destroy(&obj->h);
    free(obj);
}
