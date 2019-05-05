// could use some fancy data structure
// add something to do fast checking
// not need to add any hash ?

#define SPAN 10
#define CAP 1024

typedef struct {
    int capacity;
    int st;
    int ed;
    int last_time;
    char** s_stack;
    int* si_stack;
    int* ti_stack;
} Logger;

/** Initialize your data structure here. */
Logger* loggerCreate() {
    Logger* l = malloc(sizeof(Logger));
    l->capacity = CAP;
    l->st = 0;
    l->ed = 0;
    l->last_time = 0;
    l->s_stack = malloc(sizeof(char*) * l->capacity);
    l->si_stack = malloc(sizeof(int) * l->capacity);
    l->ti_stack = malloc(sizeof(int) * l->capacity);
    return l;
}

int msg(char* message)
{
    int i = 0;
    int a = 0;
    char c = message[i ++];
    char x = 0;

    while (c)
    {
        x ^= c;
        a += c;
        c = message[i ++];
    }
    return x << 24 | (i % 256) << 16 | (a % 65536);
}

/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
bool loggerShouldPrintMessage(Logger* obj, int timestamp, char* message) {
    if (!obj)
        return false;

    int start = timestamp - SPAN + 1;

    if (start > obj->last_time)
        obj->st = obj->ed = 0;

    int ed = obj->ed;
    int cap = obj->capacity;
    // empty
    if (obj->st == ed)
    {
        obj->s_stack[ed] = message;
        obj->si_stack[ed] = msg(message);
        obj->ti_stack[ed] = timestamp;
        obj->ed = (ed + 1) % cap;
        obj->last_time = timestamp;
        return true;
    }
    else
    {
        int st = obj->st;
        while (obj->ti_stack[st] < start)
            st = (st + 1) % cap;
        obj->st = st;

        int k = msg(message);

        while (st != ed)
        {
            if (obj->si_stack[st] == k)
                if (!strcmp(obj->s_stack[st], message))
                    return false;
            st = (st + 1) % cap;
        }

        st = obj->st;
        ed = obj->ed;

        // full, need to add
        if (((ed + 1) % cap) == st)
        {
            cap += CAP;
            if (st < ed)
            {
                obj->capacity = cap;
                obj->s_stack = realloc(obj->s_stack, sizeof(char*) * cap);
                obj->si_stack = realloc(obj->si_stack, sizeof(int) * cap);
                obj->ti_stack = realloc(obj->ti_stack, sizeof(int) * cap);
            }
            else
            {
                char** s_stack = malloc(sizeof(char*) * cap);
                memcpy(s_stack, &obj->s_stack[st], (obj->capacity - st) * sizeof(char*));
                memcpy(&s_stack[obj->capacity - st], obj->s_stack, ed * sizeof(char*));
                int* si_stack = malloc(sizeof(int) * cap);
                memcpy(si_stack, &obj->si_stack[st], (obj->capacity - st) * sizeof(int));
                memcpy(&si_stack[obj->capacity - st], obj->si_stack, ed * sizeof(int));
                int* ti_stack = malloc(sizeof(int) * cap);
                memcpy(ti_stack, &obj->ti_stack[st], (obj->capacity - st) * sizeof(int));
                memcpy(&ti_stack[obj->capacity - st], obj->ti_stack, ed * sizeof(int));
                obj->s_stack = s_stack;
                obj->si_stack = si_stack;
                obj->ti_stack = ti_stack;
                obj->st = 0;
                obj->ed = obj->capacity - 1;
                obj->capacity = cap;
            }
        }

        obj->s_stack[ed] = message;
        obj->si_stack[ed] = msg(message);
        obj->ti_stack[ed] = timestamp;
        obj->ed = (ed + 1) % cap;
        obj->last_time = timestamp;
        return true;
    }
}

void loggerFree(Logger* obj) {
    if (obj)
    {
        free(obj->s_stack);
        free(obj->si_stack);
        free(obj->ti_stack);
        free(obj);
    }
}

/**
 * Your Logger struct will be instantiated and called as such:
 * struct Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 * loggerFree(obj);
 */
