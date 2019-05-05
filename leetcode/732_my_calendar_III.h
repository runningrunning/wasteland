// dynamic segment tree here !!!!!!!!!!!!!!!!!!!!!!
// stupid wrong algorithm, not pure treap
// similar with 699 falling squares, but not fixed input length !!
// static data use segment tree
// variable data use interval tree with treap ?
// not interval tree, but variants treap !!!!!!!!!!!
// learn a lot !!!!
// can still use segment tree, as it's fixed in 1e9 !! learn how to do so, it's simple !!
int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct _Node{
    int s; // start
    int e; // end
    int p; // priority
    int m; // maximum below
    int mn; // meeting number
    struct _Node* _l; // left
    struct _Node* _r; // right
} Node;

typedef struct {
    int m;
    int p; // start priority
    Node* r;
} MyCalendarThree;

MyCalendarThree* myCalendarThreeCreate() {
    MyCalendarThree* m = malloc(sizeof(MyCalendarThree));
    m->r = NULL;
    m->p = _random((long) m);
    m->m = 0;
    return m;
}

void _find(Node* r, int s, int e, int* m, int* t, int* ti)
{
    if (r)
    {
        if (r->s < e && r->e > s)
        {
            if (r->s <= s && r->e >= e)
            {
                *ti = 2;

                t[0] = r->s;
                t[1] = s;
                t[2] = r->mn;

                t[4] = e;
                t[5] = r->e;
                t[6] = r->mn;

                r->s = s;
                r->e = e;
                r->mn ++;
                *m = r->mn;
                return;
            }

            if (s <= r->s && e >= r->e)
            {
                r->mn ++;

                if (!(*ti))
                {
                    *ti = 2;
                    t[0] = s;
                    t[1] = r->s;
                    t[2] = 1;
                    t[4] = r->e;
                    t[5] = e;
                    t[6] = 1;
                }
                else
                {
                    if (r->s < t[1])
                        t[1] = r->s;
                    if (r->e > t[4])
                        t[4] = r->e;
                }

                if (*m < r->mn)
                    *m = r->mn;
            }
            else if (s >= r->s && s <= r->e && e > r->e)
            {
                if (!(*ti))
                {
                    *ti = 2;
                    t[0] = s;
                    t[1] = r->e;
                    t[2] = r->mn + 1;
                    t[4] = r->e;
                    t[5] = e;
                    t[6] = 1;
                }
                else
                {
                    if (r->e < t[1])
                        t[1] = r->e;
                    t[2] = r->mn + 1;
                }
                r->e = s;
                if (*m < r->mn + 1)
                    *m = r->mn + 1;
            }
            else if (e >= r->s && e <= r->e && s < r->s)
            {
                if (!(*ti))
                {
                    *ti = 2;
                    t[0] = s;
                    t[1] = r->s;
                    t[2] = 1;
                    t[4] = r->s;
                    t[5] = e;
                    t[6] = r->mn + 1;
                }
                else
                {
                    if (r->s > t[4])
                        t[4] = r->s;
                    t[6] = r->mn + 1;
                }
                r->s = e;
                if (*m < r->mn + 1)
                    *m = r->mn + 1;
            }
        }

        if (r->e > s)
            _find(r->_l, s, e, m, t, ti);

        if (r->s < e)
            _find(r->_r, s, e, m, t, ti);
    }
}

void _add(Node** r, Node* n)
{
    if (*r)
    {
        Node* p = *r;

        if (n->s <= p->s)
        {
            _add(&(p->_l), n);
            if (p->p > p->_l->p)
            {
                Node* t = p->_l;
                p->_l = t->_r;
                t->_r = p;
                *r = t;
            }
        }
        else
        {
            _add(&(p->_r), n);

            if (p->p > p->_r->p)
            {
                Node* t = p->_r;
                p->_r = t->_l;
                t->_l = p;
                *r = t;
            }
        }

        p = *r;

        p->m = p->e;
        if (p->_l)
            p->m = p->m > p->_l->m ? p->m : p->_l->m;

        if (p->_r)
            p->m = p->m > p->_r->m ? p->m : p->_r->m;
    }
    else
        *r = n;
}

void _out(Node* r)
{
    if (r)
    {
        printf("(%d -> %d : %d, ", r->s, r->e, r->mn);
        _out(r->_l);
        _out(r->_r);
        printf(")");
    }
    else
    {
        printf(" NULL ");
    }
}

int myCalendarThreeBook(MyCalendarThree* obj, int start, int end) {
    if (obj)
    {
        int m = 0;
        int ti = 0;
        int t[16] = {0};

        _find(obj->r, start, end, &m, t, &ti);

        if (!m)
            m = 1;

        if (obj->m < m)
            obj->m = m;

        /* printf("insert s %d e %d m %d ti %d.\n", start, end, m, ti); */
        /* out(t, ti * 4); */

        if (ti)
        {
            for (int i = 0; i < ti; i ++)
            {
                int oi = i * 4;

                if (t[oi] != t[oi + 1])
                {
                    Node* n = malloc(sizeof(Node));
                    n->_l = n->_r = NULL;
                    n->s = t[oi];
                    n->e = t[oi + 1];
                    n->p = obj->p;
                    n->m = n->e;
                    n->mn = t[oi + 2];
                    obj->p = _random(obj->p);
                    _add(&obj->r, n);
                }
            }
        }
        else
        {
            Node* n = malloc(sizeof(Node));
            n->_l = n->_r = NULL;
            n->s = start;
            n->e = end;
            n->p = obj->p;
            n->m = n->e;
            n->mn = 1;
            obj->p = _random(obj->p);
            _add(&obj->r, n);
        }

        /* _out(obj->r); */
        /* printf("\n"); */
        return obj->m;
    }
    return 0;
}

void myCalendarThreeFree(MyCalendarThree* obj) {
    if (obj)
        free(obj);
}

/**
 * Your MyCalendarThree struct will be instantiated and called as such:
 * struct MyCalendarThree* obj = myCalendarThreeCreate();
 * int param_1 = myCalendarThreeBook(obj, start, end);
 * myCalendarThreeFree(obj);
 */
