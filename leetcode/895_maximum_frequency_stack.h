// max heap with hash, hash set or mapping ?
// hash store the number of ints
// how to write a dynamic hash table ?
// heap num (16), index(16), value(32)
// hash hash_value_index
// hash_value num(32), value(32)
// just write code with careful !!!!

#define PRIME 16411

typedef struct {
    // int** hash; don't need that complicated, just int hash should be enough, keep the removed one there.
    int* hash;
    int hash_value_size;
    unsigned long* hash_value;
    int heap_size;
    int heap_index;
    unsigned long* heap;
    unsigned long st_size;
} FreqStack;

FreqStack* freqStackCreate() {
    FreqStack* fs = malloc(sizeof(FreqStack));
    fs->hash = calloc(sizeof(int), PRIME);
    fs->hash_value_size = 0;
    fs->hash_value = NULL;
    fs->heap_index = 0;
    fs->heap_size = 0;
    fs->heap = NULL;
    fs->st_size = 0;
    return fs;
}

void freqStackPush(FreqStack* obj, int x) {
    if (obj)
    {
        int k = x % PRIME;
        int* hash = obj->hash;
        unsigned long* value = obj->hash_value;

        while (hash[k] && (value[hash[k] - 1] & 0xFFFFFFFF) != x)
            k = (k + 1) % PRIME;

        unsigned long z = obj->st_size << 32 | x;

        if (hash[k])
        {
            int i = hash[k] - 1;
            value[i] += 1L << 32;
            z |= (value[i] >> 32) << 48;

        }
        else
        {
            if (!(obj->hash_value_size % 1024))
                obj->hash_value = realloc(obj->hash_value, sizeof(unsigned long) * (obj->hash_value_size + 1024));
            obj->hash_value[obj->hash_value_size] = 1L << 32 | x;
            obj->hash_value_size ++;

            hash[k] = obj->hash_value_size;
            z |= 1L << 48;
        }

        obj->st_size ++;

        // add heap
        if (obj->heap_index == obj->heap_size)
        {
            obj->heap_size += 1024;
            obj->heap = realloc(obj->heap, sizeof(unsigned long) * obj->heap_size);
        }

        int hi = obj->heap_index ++;
        unsigned long* heap = obj->heap;
        obj->heap[hi] = z;

        while (hi)
        {
            int p = (hi - 1) / 2;

            if (heap[p] > z)
                break;

            heap[hi] = heap[p];
            heap[p] = z;
            hi = p;
        }
    }
}

int freqStackPop(FreqStack* obj) {
    if (obj)
    {
        unsigned long r = obj->heap[0];
        int x = r & 0xFFFFFFFF;

        int k = x % PRIME;
        int* hash = obj->hash;
        unsigned long* value = obj->hash_value;

        while (hash[k] && (value[hash[k] - 1] & 0xFFFFFFFF) != x)
            k = (k + 1) % PRIME;

        if (hash[k])
        {
            int i = hash[k] - 1;
            value[i] -= 1L << 32;
        }

        // remove heap
        unsigned long* heap = obj->heap;
        obj->heap_index --;
        heap[0] = obj->heap[obj->heap_index];

        int hx = 0;
        int hi = obj->heap_index;
        unsigned long z = heap[0];

        while (hx * 2 + 1 < hi)
        {
            unsigned long l = heap[hx * 2 + 1];
            unsigned long r = l;

            if (hx * 2 + 2 < hi)
                r = heap[hx * 2 + 2];

            if (l >= r)
            {
                if (l < z)
                    break;

                heap[hx] = l;
                heap[hx * 2 + 1] = z;
                hx = hx * 2 + 1;
            }
            else
            {
                if (r < z)
                    break;

                heap[hx] = r;
                heap[hx * 2 + 2] = z;
                hx = hx * 2 + 2;
            }
        }

        return x;
    }

    return 0;
}

void freqStackFree(FreqStack* obj) {

    if (obj)
    {
        free(obj->hash);
        free(obj->hash_value);
        free(obj->heap);
        free(obj);
    }
}

/**
 * Your FreqStack struct will be instantiated and called as such:
 * struct FreqStack* obj = freqStackCreate();
 * freqStackPush(obj, x);
 * int param_2 = freqStackPop(obj);
 * freqStackFree(obj);
 */
