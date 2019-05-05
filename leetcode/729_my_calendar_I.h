struct TimeSlot{
    int start;
    int end;
    struct TimeSlot* left;
    struct TimeSlot* right;
};

typedef struct {
    struct TimeSlot* s;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar* m = malloc(sizeof(MyCalendar));
    m->s = NULL;
    return m;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    if (!obj)
        return false;

    struct TimeSlot** t = &obj->s;
    struct TimeSlot* p = *t;

    while(*t)
    {
        p = *t;
        if (!(p->end <= start || p->start >= end))
            return false;

        if (p->start >= end)
            t = &(*t)->left;
        else
            t = &(*t)->right;
    }

    p = malloc(sizeof(struct TimeSlot));
    p->start = start;
    p->end = end;
    p->left = NULL;
    p->right = NULL;
    *t = p;
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

void myCalendarFree(MyCalendar* obj) {
    if (obj->s)
        _free_timeslot(obj->s);
    free(obj);
}
