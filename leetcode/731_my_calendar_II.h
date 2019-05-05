/* double free or corruption (fasttop): 0x00000000026696b0 *** */
/* missing one case !!!!!!1 */
/* Forget to reset TimeSlot left and right to NULL !!!! */

struct TimeSlot{
    int start;
    int end;
    struct TimeSlot* left;
    struct TimeSlot* right;
};

typedef struct {
    struct TimeSlot* s;
    struct TimeSlot* d;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* m = malloc(sizeof(MyCalendarTwo));
    m->s = NULL;
    m->d = NULL;
    return m;
}

void _insert_d(struct TimeSlot** t, int start, int end)
{
    if (start >= end)
        return;

    struct TimeSlot* p = *t;

    while(*t)
    {
        p = *t;
        if (p->start >= end)
            t = &(*t)->left;
        else if (p->end <= start)
            t = &(*t)->right;
        /* else */
        /*     printf("error.\n"); */
    }

    p = malloc(sizeof(struct TimeSlot));
    p->start = start;
    p->end = end;
    p->left = NULL;
    p->right = NULL;
    *t = p;
}

void _insert(struct TimeSlot** t, int start, int end, struct TimeSlot** d)
{
    if (start >= end)
        return;

    struct TimeSlot* p = *t;

    while(*t)
    {
        p = *t;
        if (!(p->end <= start || p->start >= end) && (p->start != p->end))
            break;

        if (p->start >= end)
            t = &(*t)->left;
        else
            t = &(*t)->right;
    }

    p = *t;

    if (!p)
    {
        p = malloc(sizeof(struct TimeSlot));
        p->start = start;
        p->end = end;
        p->left = NULL;
        p->right = NULL;
        *t = p;
    }
    else
    {
        if (p->start >= start && p->end <= end)
        {
            int ps = p->start;
            int pe = p->end;
            p->end = p->start;

            t = &p->left;
            _insert(t, start, ps, d);
            t = &p->right;
            _insert(t, pe, end, d);
            _insert_d(d, ps, pe);
        }
        else if (start >= p->start && end <= p->end)
        {
            int pe = p->end;
            p->end = start;
            t = &p->right;
            _insert(t, end, pe, d);
            _insert_d(d, start, end);
        }
        else if (p->start < start)
        {
            int pe = p->end;
            p->end = start;

            t = &p->right;
            _insert(t, pe, end, d);
            _insert_d(d, start, pe);
        }
        else // p->end > end;
        {
            int ps = p->start;
            p->start = end;
            t = &p->left;

            _insert(t, start, ps, d);
            _insert_d(d, ps, end);
        }
    }
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end)
{
    if (!obj)
        return false;

    struct TimeSlot* p = obj->d;

    while(p)
    {
        if (!(p->end <= start || p->start >= end))
        {
            printf("coll with %d. %d \n", p->start, p->end);
            return false;
        }

        if (p->start >= end)
            p = p->left;
        else
            p = p->right;
    }

    _insert(&obj->s, start, end, &obj->d);
    return true;
}

void _free_timeslot(struct TimeSlot* t)
{
    if (t->left)
        _free_timeslot(t->left);
    if (t->right)
        _free_timeslot(t->right);
    free(t);
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    if (obj->s)
        _free_timeslot(obj->s);
    if (obj->d)
        _free_timeslot(obj->d);
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * struct MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 * myCalendarTwoFree(obj);
 */
