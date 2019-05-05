// FAILED PASS !!!!!!!!!!!!!!!!!!!!
int mg_sort(int* n, int s, int e, int* m)
{
    if (s >= e)
        return 0;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return *m > (n[s] - n[e]) ? *m : (n[s] - n[e]);

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    int _mi = ;
    int _ma = max;
    for (int i = cs; s <= ce; i ++)
    {
        if (n[i] < n[e])
        {
            if (n[i] > _mi)
                _mi = n[i];
        }
        else if (n[i] > n[e])
        {
            if (n[i] < _ma)
                _ma = n[i];
        }
    }
}

/* int mg(int* n, int s, int l) */
/* { */
/*     int ns = 0; */
/*     int slot[256] = {0}; */
/*     int shift = (3 - l) << 3; */

/*     for (int i = 0; i < s; i ++) */
/*     { */
/*         int x = (n[i] >> shift) & 0xFF; */
/*         if (!slot[x]) */
/*             ns ++; */
/*         slot[x] ++; */
/*     } */

/*     if (ns == 1) */
/*         return l == 3 ? 0 : mg(n, s, l + 1); */
/*     else */
/*     { */
/*         int pre; */
/*         for (int i = 0; i < 256; i ++) */
/*             if (slot[x] ) */
/*     } */
/* } */


// STUPID ALGO !!!!!
// use slot !
int maximumGap(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;
}


/* typedef struct _Node */
/* { */
/*     int l; */
/*     int r; */
/*     int lm; */
/*     int rm; */
/*     struct _Node* n[2]; */
/* } Node; */

/* Node* cNode() */
/* { */
/*     Node* n = malloc(sizeof(Node)); */
/*     n->l = n->r = -1; */
/*     n->lm = n->rm = -1; */
/*     n->n[0] = n->n[1] = NULL; */
/*     return n; */
/* } */

/* int aNode(Node* o, int n, int t) */
/* { */
/*     if (!t) */
/*         return 0; */

/*     int m = 0; */
/*     int b = !!(n & t); */
/*     if (!o->n[b]) */
/*         o->n[b] = cNode(); */
/*     Node* no = o->n[b]; */

/*     if (b) */
/*     { */
/*         o->rm = aNode(no, n, t >> 1); */

/*         if (o->r == -1) */
/*             o->r = n; */
/*         else if (o->r > n) */
/*             o->r = n; */
/*     } */
/*     else */
/*     { */
/*         o->lm = aNode(no, n, t >> 1); */
/*         if (o->l == -1) */
/*             o->l = n; */
/*         else if (o->l < n) */
/*             o->l = n; */
/*     } */

/*     if (o->r != -1 && o->l != -1) */
/*         m = o->r - o->l; */
/*     if (o->rm > o->lm) */
/*         return m > o->rm ? m : o->rm; */
/*     return m > o->lm ? m : o->lm; */
/* } */
/* // use tree or trie to finish this ! */
/* int maximumGap(int* nums, int numsSize) */
/* { */
/*     if (numsSize < 2) */
/*         return 0; */
/*     int m = 0; */
/*     Node* r = cNode(); */
/*     for (int i = 0; i < numsSize; i ++) */
/*         m = aNode(r, nums[i], 1 << 30); */
/*     return m; */
/* } */

