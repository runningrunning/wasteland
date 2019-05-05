// not segment tree !!
// it still can be, as it's INT size !!!
// add parent to minimize double
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct _Node {
    int s;
    int e;
    // int m; // add m for interval ?
    int p;
    struct _Node* _l;
    struct _Node* _r;
} Node;

typedef struct {
    int n;
    int p;
    Node* r;
} SummaryRanges;

/** Initialize your data structure here. */
SummaryRanges* summaryRangesCreate() {
    SummaryRanges* s = malloc(sizeof(SummaryRanges));
    s->p = _random((long) s);
    s->r = NULL;
    s->n = 0;
    return s;
}

bool _find(Node* r, int v, Node** pre, Node** post)
{
    if (r)
    {
        if (v <= r->e && v >= r->s)
            return false;

        if (r->s == v + 1)
            *post = r;

        if (r->e == v - 1)
            *pre = r;

        if (r->s > v)
            return _find(r->_l, v, pre, post);
        return _find(r->_r, v, pre, post);
    }
    return true;
}

void _add(Node** r, Node* n)
{
    if (*r)
    {
        Node* p = *r;

        if (p->s > n->s)
        {
            _add(&p->_l, n);
            if (p->_l->p < p->p)
            {
                Node* t = p->_l;
                p->_l = t->_r;
                t->_r = p;
                *r = t;
            }
        }
        else
        {
            _add(&p->_r, n);
            if (p->_r->p < p->p)
            {
                Node* t = p->_r;
                p->_r = t->_l;
                t->_l = p;
                *r = t;
            }
        }
    }
    else
        *r = n;
}

void _remove(Node** r, int s)
{
    if (*r)
    {
        Node* p = *r;
        if (p->s > s)
        {
            _remove(&p->_l, s);
            if (p->_l && p->_l->p < p->p)
            {
                Node* t = p->_l;
                p->_l = t->_r;
                t->_r = p;
                *r = t;
            }
        }
        else if (p->s < s)
        {
            _remove(&p->_r, s);
            if (p->_r && p->_r->p < p->p)
            {
                Node* t = p->_r;
                p->_r = t->_l;
                t->_l = p;
                *r = t;
            }
        }
        else
        {
            if (!p->_l && !p->_r)
                *r = NULL;
            else if (p->_l && p->_r)
            {
                if (p->_l->p < p->_r->p)
                {
                    Node* t = p->_l;
                    p->_l = t->_r;
                    t->_r = p;
                    *r = t;
                    _remove(&t->_r, s);
                }
                else
                {
                    Node* t = p->_r;
                    p->_r = t->_l;
                    t->_l = p;
                    *r = t;
                    _remove(&t->_l, s);
                }
            }
            else if (p->_l)
                *r = p->_l;
            else
                *r = p->_r;
        }
    }
}

void summaryRangesAddNum(SummaryRanges* obj, int val)
{
    if (obj)
    {
        Node* pre = NULL;
        Node* post = NULL;
        bool f = _find(obj->r, val, &pre, &post);
        if (!f)
            return;

        if (!pre || !post)
        {
            if (!pre && !post)
            {
                Node* n = malloc(sizeof(Node));
                n->s = val;
                n->e = val;
                n->p = obj->p;
                n->_l = n->_r = NULL;
                obj->p = _random(obj->p);
                _add(&obj->r, n);
                obj->n ++;
            }
            else if (pre)
                pre->e += 1;
            else
                post->s -= 1;
        }
        else
        {
            pre->e = post->e;
            _remove(&obj->r, post->s);
            obj->n --;
        }
    }
}

void _out(Node* n, struct Interval* r, int* rs)
{
    if (n)
    {

        _out(n->_l, r, rs);
        r[*rs].start = n->s;
        r[*rs].end = n->e;
        (*rs) ++;
        _out(n->_r, r, rs);
    }
}

struct Interval* summaryRangesGetIntervals(SummaryRanges* obj, int *returnSize)
{
    int rs = 0;

    if (!obj->n)
        return NULL;

    struct Interval* r = malloc(sizeof(struct Interval) * obj->n);
    _out(obj->r, r, &rs);
    *returnSize = obj->n;

    return r;
}

void summaryRangesFree(SummaryRanges* obj) {
    if (obj)
        free(obj);
}

/**
 * Your SummaryRanges struct will be instantiated and called as such:
 * struct SummaryRanges* obj = summaryRangesCreate();
 * summaryRangesAddNum(obj, val);
 * struct Interval* param_2 = summaryRangesGetIntervals(obj);
 * summaryRangesFree(obj);
 */
