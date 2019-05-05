// hash ? or for smaller number just put them all
// be careful about offset 1 error !
// BETTER SOLUTIONs ???
#define PRIME 4099
typedef struct {
    int r;
    int c;
    int a;
    int l;
    void* mem;
    long rand;
    bool hash;
} Solution;

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

Solution* solutionCreate(int n_rows, int n_cols) {
    Solution* s = malloc(sizeof(Solution));
    s->mem = malloc(sizeof(int) * PRIME);
    memset(s->mem, 0, sizeof(int) * PRIME);
    s->r = n_rows;
    s->c = n_cols;
    s->a = n_rows * n_cols;
    s->l = s->a;
    s->hash = false;
    s->rand = _random((long) s);
    if (n_rows * n_cols > PRIME * 2)
        s->hash = true;
    return s;
}

bool has(int* hash, int v, bool set)
{
    int key = v % PRIME;
    while (hash[key] && hash[key] != v + 1)
        key = (key + 1) % PRIME;

    bool b = hash[key] == v + 1;
    if (set)
        hash[key] = v + 1;
    return b;
}

int* solutionFlip(Solution* obj, int *returnSize)
{
    *returnSize = 0;
    if (!obj || (!obj->hash && !obj->l))
        return NULL;

    *returnSize = 2;
    int* r = malloc(sizeof(int) * 2);

    if (obj->hash)
    {
        int* mem = (int*) obj->mem;
        int num = obj->rand % obj->a;
        obj->rand = _random(obj->rand);

        while (has(mem, num, true))
        {
            num = obj->rand % obj->a;
            obj->rand = _random(obj->rand);
        }

        r[0] = num / obj->c;
        r[1] = num % obj->c;
    }
    else
    {
        short* mem = (short*) obj->mem;
        int index = obj->rand % obj->l;
        obj->rand = _random(obj->rand);
        int last = obj->l - 1;
        if (mem[index])
        {
            r[0] = (mem[index] - 1) / obj->c;
            r[1] = (mem[index] - 1) % obj->c;
        }
        else
        {
            r[0] = index / obj->c;
            r[1] = index % obj->c;
        }
        mem[index] = mem[last] ? mem[last] : (last + 1);
        mem[last] = (r[0] * obj->c + r[1] + 1);
        obj->l --;
    }

    return r;
}

void solutionReset(Solution* obj) {
    if (obj)
    {
        if (obj->hash)
            memset(obj->mem, 0, sizeof(int) * PRIME);
        else
            obj->l = obj->a;
    }
}

void solutionFree(Solution* obj) {
    if (obj)
    {
        free(obj->mem);
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(n_rows, n_cols);
 * int* param_1 = solutionFlip(obj);
 * solutionReset(obj);
 * solutionFree(obj);
 */


/* You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space complexity. */

/* Note: */

/*     1 <= n_rows, n_cols <= 10000 */
/*     0 <= row.id < n_rows and 0 <= col.id < n_cols */
/*     flip will not be called when the matrix has no 0 values left. */
/*     the total number of calls to flip and reset will not exceed 1000. */

