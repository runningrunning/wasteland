/* FAILED TOO MUCH TIMES */
/* the minimize heap ? */
/* no need, stack should be enough ! */
/* STUPID WRONG answer */
/* Forget to remove last time stamp  */
/* KISS */
/* rotate array is about how to setup END */
/* VIP !!!!!!!!! STOP FLAG !!! */

#define MAX_TS 300
#define STACK_SIZE  301
typedef struct {
    int si;
    int end;
    int last_time;
    int last_hit;
    int all_hit;
    int stacks[STACK_SIZE];
    int counts[STACK_SIZE];
} HitCounter;

/** Initialize your data structure here. */
HitCounter* hitCounterCreate() {
    HitCounter* hc = malloc(sizeof(HitCounter));
    hc->si = 0;
    hc->end = 0;
    hc->last_time = 0;
    hc->last_hit = 0;
    hc->all_hit = 0;
    hc->stacks[0] = 0;
    hc->counts[0] = 0;
    return hc;
}

void insert_last(HitCounter* obj, int timestamp)
{
    if (!obj || !obj->last_time || obj->last_time == timestamp)
        return;

    int end = obj->end % STACK_SIZE;
    obj->stacks[end] = obj->last_time;
    obj->counts[end] = obj->last_hit;
    obj->end ++;
    obj->last_time = 0;
    obj->last_hit = 0;
}


/** Return the number of hits in the past 5 minutes.
    @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) {
    if (!obj)
        return 0;

    insert_last(obj, timestamp);

    int t = timestamp - MAX_TS;
    if (t > 0)
    {
        for (int i = obj->si; i < obj->end; i ++)
        {
            int si = i % STACK_SIZE;
            if (obj->stacks[si] > t)
                break;
            obj->all_hit -= obj->counts[si];
            obj->si ++;
        }
    }
    return obj->all_hit;
}

/** Record a hit.
    @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
    if (!obj)
        return;

    obj->all_hit ++;
    if (!obj->last_time || obj->last_time == timestamp)
        obj->last_hit ++;
    else
    {
        hitCounterGetHits(obj, timestamp);
        obj->last_hit = 1;
    }
    obj->last_time = timestamp;
}

void hitCounterFree(HitCounter* obj) {
    if (obj)
        free(obj);
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * struct HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 * int param_2 = hitCounterGetHits(obj, timestamp);
 * hitCounterFree(obj);
 */
