// TODO MERGE SORT ??
// be careful !!!
//
// better solution !! merge sort version ?????  how to do merge sort?
// better solutions !!!
// peek hint, how to use segment tree here?
// my segment tree
// be careful !! start can large than se
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// merge sort method, it's easy !!!
// my way to do merge sort

// only update the first part, the second part should have been done.
bool _cs_merge(int* nums, int e, int x, int* id, int* ns, int* tnums, int* tid, int* tns)
{
    int n = x / 2;

    if (n >= e)
        return false;

    for (int i = 0; i < e; i += x)
    {
        if (i + n > e)
        {
            for (int j = i; j < e; j ++)
            {
                tnums[j] = nums[j];
                tid[j] = id[j];
                tns[j] = ns[j];
            }
            break;
        }

        int* f1 = nums + i;
        int f1e = n;
        int* f2 = nums + i + n;
        int f2e = i + x > e ? (e - i - n) : n;

        int j1 = 0;
        int j2 = 0;

        int t = i;

        while (j1 < f1e && j2 < f2e)
        {
            if (f1[j1] > f2[j2])
            {
                tnums[t] = f2[j2];
                tid[t] = id[n + i + j2];
                tns[t] = ns[n + i + j2];
                t ++;
                j2 ++;
            }
            else
            {
                tnums[t] = f1[j1];
                tid[t] = id[i + j1];
                tns[t] = ns[i + j1] + t - i - j1;
                t ++;
                j1 ++;
            }
        }

        while (j2 < f2e)
        {
            tnums[t] = f2[j2];
            tid[t] = id[n + i + j2];
            tns[t] = ns[n + i + j2];
            t ++;
            j2 ++;
        }

        while (j1 < f1e)
        {
            tnums[t] = f1[j1];
            tid[t] = id[i + j1];
            tns[t] = ns[i + j1] + t - i - j1;
            t ++;
            j1 ++;
        }
    }
    return true;
}

int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    int* id = malloc(sizeof(int) * numsSize);
    int* ns = malloc(sizeof(int) * numsSize);
    int* tnums = malloc(sizeof(int) * numsSize);
    int* tid = malloc(sizeof(int) * numsSize);
    int* tns = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        id[i] = i;
        ns[i] = 0;
    }

    int* _id = id;
    int* _ns = ns;
    int* _nums = nums;

    int x = 2;
    while (_cs_merge(_nums, numsSize, x, _id, _ns, _nums == nums ? tnums : nums,
                     _id == id ? tid : id, _ns == ns ? tns : ns))
    {
        x *= 2;
        _nums = _nums == nums ? tnums : nums;
        _id = _id == id ? tid : id;
        _ns = _ns == ns ? tns : ns;
    }

    *returnSize = numsSize;
    int* r = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        r[_id[i]] = _ns[i];
    return r;
}

/*
void _cs_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

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

    _cs_sort(n, cs, e - 1);
    _cs_sort(n, e + 1, ce);
}

void _cs(int* tree, int x, int start, int end, int l, int v, int* sort, int se, int* n)
{
    if (x > end)
        return;
    int t = x + 1;
    int st = (t << l) - 1 - start;

    if (st > se) // start can larger than se !!!!
        return;

    int ed = (st + (1 << l) - 1);
    ed = ed > se ? se : ed;

    int vst = sort[st];
    int ved = sort[ed];

    if (v < vst)
        return;

    if (v >= vst && v <= ved)
        tree[x] ++;

    if (v > ved)
    {
        (*n) += tree[x];
        return;
    }

    if (l)
    {
        _cs(tree, x * 2 + 1, start, end, l - 1, v, sort, se, n);
        _cs(tree, x * 2 + 2, start, end, l - 1, v, sort, se, n);
    }
}

// segment tree method
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    if (!nums || !numsSize)
        return NULL;

    int* copy = malloc(sizeof(int) * numsSize);
    memcpy(copy, nums, sizeof(int) * numsSize);
    _cs_sort(copy, 0, numsSize - 1);

    int size = 1;

    for (int i = 1; i < numsSize; i ++)
        if (copy[i] != copy[i - 1])
            copy[size ++] = copy[i];

    int lv = 0;
    int x = 1;
    while (x < size)
    {
        x <<= 1;
        lv ++;
    }

    int start = x - 1;
    int* tree = calloc(sizeof(int), start + size);
    int* r = calloc(sizeof(int), numsSize);

    for (int i = 0; i < numsSize; i ++)
        _cs(tree, 0, start, start + size - 1, lv, nums[numsSize - 1 - i], copy, size - 1, &r[numsSize - 1 - i]);

    *returnSize = numsSize;
    return r;
}
*/

/*
typedef struct _LNode
{
    int i;
    struct _LNode* next;
} LNode;

int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    if (!nums || !numsSize)
        return NULL;

    *returnSize = numsSize;

    LNode* h = NULL;
    int* r = malloc(sizeof(int) * numsSize);
    LNode** p = &h;

    for (int i = 0; i < numsSize; i ++)
    {
        p = &h;

        int y = nums[i];
        LNode* x = malloc(sizeof(LNode));
        x->next = NULL;
        x->i = i;
        r[i] = 0;

        while (*p && nums[(*p)->i] > y)
        {
            r[(*p)->i] ++;
            p = &((*p)->next);
        }
        x->next = *p;
        *p = x;
    }
    return r;
}
*/

/* int* countSmaller(int* nums, int numsSize, int* returnSize) */
/* { */
/*     *returnSize = 0; */
/*     if (!nums || !numsSize) */
/*         return NULL; */

/*     int* r = malloc(sizeof(int) * numsSize); */
/*     memset(r, 0, sizeof(int) * numsSize); */

/*     *returnSize = numsSize; */
/*     int i = 0; */
/*     for (i = 0; i < numsSize - 1; i ++) */
/*         if (nums[i] > nums[i + 1]) */
/*             break; */

/*     if (i == numsSize - 1) */
/*         return r; */

/*     for (i = numsSize - 1; i > 0; i --) */
/*     { */
/*         for (int j = i - 1; j >= 0; j --) */
/*             if (nums[i] < nums[j]) */
/*                 r[j] ++; */
/*     } */
/*     return r; */
/* } */
