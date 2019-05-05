/* TODO How to generate total random int */
/* TODO Try Heap code to get MIN, MAX Heap */
/* TODO know how to generate total full permutation */
/* There is no easy way to do so? */

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef u_int32_t uint32_t;
typedef int bool;
#define true 1
#define false 0

#define LEN_M(m) sizeof(m)/sizeof(m[0])

struct Interval {
    int start;
    int end;
};

struct Point {
    int x;
    int y;
};


/* generate full permutation
   void full_permutation(int* n, int s, int e)
   {
   if (s == e)
   out(n, e + 1);
   else
   {
   int cur = n[s];

   for (int i = s; i <= e; i ++)
   {
   int t = n[i];
   n[i] = n[s];
   n[s] = t;
   full_permutation(n, s + 1, e);
   n[i] = n[s];
   n[s] = cur;
   }
   }
   }

   void test()
   {
   int m[] = {1, 2, 3, 4, 5, 6, 7, 8};
   // int l = sizeof(m)/sizeof(m[0]);
   int l = 4;
   int* t = malloc(sizeof(int) * l);
   memcpy(t, m, sizeof(int) * l);
   full_permutation(m, 0, l - 1);
   }
*/

int* dup_a(int* m, int l)
{
    int* r = malloc(sizeof(int) * l);
    memcpy(r, m, sizeof(int) * l);
    return r;
}

char** dup_s(char** m, int l)
{
    char** r = malloc(sizeof(char*) * l);
    for (int i = 0; i < l; i ++)
        r[i] = strdup(m[i]);
    return r;
}

int** gen_aa(int* m, int l, int l1)
{
    int l2 = l / l1;
    int** r = malloc(sizeof(int*) * l2);
    for (int i = 0; i < l2; i ++)
    {
        r[i] = malloc(sizeof(int) * l1);
        for (int j = 0; j < l1; j ++)
            r[i][j] = m[i * l1 + j];
    }
    return r;
}

char* g_randomstr(int l)
{
    char* s = malloc(l + 1);
    s[l] = 0;
    for (int i = 0; i < l; i ++)
        s[i] = (rand() % 26) + 'a';
    return s;
}

/* generate random 1 - n form 1 - m, no duplicates */
int* g_randomlist(int m, int n)
{
    int *mu = malloc(sizeof(int) * (m + 1));
    memset(mu, 0, sizeof(int) * (m + 1));
    int *t = malloc(sizeof(int) * n);
    int rn = m - n + 1;
    for (int i = 0; i < n; i ++)
    {
        int x = (rand() % rn) + 1;
        if (mu[x])
            x = rn;
        mu[x] = 1;
        t[i] = x;
        rn ++;
    }
    free(mu);
    return t;
}

int* g_rand(int m, int n)
{
    int* r = malloc(sizeof(int) * m);

    for (int i = 0; i < m; i ++)
        r[i] = (rand() % n) + 1;
    return r;
}

int* g_randomlist_dup(int m, int n)
{
    int *t = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
        t[i] = rand() % m;
    return t;
}

void test_g_randomlist()
{
    int m = 10;
    int n = 5;

    for (int i = 0; i < 20; i ++)
    {
        int* t = g_randomlist(m, n);
        // out(t, n);
    }
}

void q_swap(int* a, int* b)
{
    if (*a == *b)
        return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void q_sort(int*nums, int s, int e)
{
    if (s >= e)
        return;

    if (nums[s] > nums[e])
    {
        q_swap(&nums[s], &nums[e]);
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;
    int i = 0;
    for(i = s + 1; i <= e; i ++)
    {
        while(nums[i] < nums[s]) i ++;
        while(nums[e] > nums[s]) e --;
        if (i >=  e)
            q_swap(&nums[s], &nums[e]);
        else
            q_swap(&nums[i], &nums[e]);
    }

    q_sort(nums, cs, e - 1);
    q_sort(nums, e + 1, ce);
}


#define THRESHOLD 4

void _my_stupid_qsort(int* n, int s, int e)
{
    if (s >= e)
        return;

    // for insert sort
    if (e - s + 1 <= THRESHOLD)
        return;

    int t;
    int m = s + (e - s + 1) / 2;

    if (n[m] < n[s])
    {
        t = n[m];
        n[m] = n[s];
        n[s] = t;
    }

    if (n[e] < n[m])
    {
        t = n[m];
        n[m] = n[e];
        n[e] = t;

        if (n[m] < n[s])
        {
            t = n[m];
            n[m] = n[s];
            n[s] = t;
        }
    }

    int cs = s;
    int ce = e;

    while (s < e)
    {
        while (n[s] < n[m])
            s ++;
        while (n[e] > n[m])
            e --;

        if (s == e)
            break;

        t = n[s];
        n[s] = n[e];
        n[e] = t;

        if (s == m)
            m = e;
        else if (e == m)
            m = s;
        s ++;
        e --;
    }

    _my_stupid_qsort(n, cs, m - 1);
    _my_stupid_qsort(n, m + 1, ce);
}

void _my_stupid_qsort_stack(int* n, int _s, int _e)
{
    if (_s >= _e)
        return;

    // for insert sort
    if (_e - _s + 1 <= THRESHOLD)
        return;

    int si = 0;
    int stack[64];
    // printf("%d %d.\n", CHAR_BIT, sizeof(size_t));

    int s = _s;
    int e = _e;

    int max = 0;
    while (true)
    {
        // printf("= si is %d.\n", si);

        int t;
        int m = s + (e - s + 1) / 2;

        if (n[m] < n[s])
        {
            t = n[m];
            n[m] = n[s];
            n[s] = t;
        }

        if (n[e] < n[m])
        {
            t = n[m];
            n[m] = n[e];
            n[e] = t;

            if (n[m] < n[s])
            {
                t = n[m];
                n[m] = n[s];
                n[s] = t;
            }
        }

        int cs = s;
        int ce = e;

        while (s < e)
        {
            while (n[s] < n[m])
                s ++;
            while (n[e] > n[m])
                e --;

            if (s == e)
                break;

            t = n[s];
            n[s] = n[e];
            n[e] = t;

            if (s == m)
                m = e;
            else if (e == m)
                m = s;
            s ++;
            e --;
        }

        // brilliant part to save stack size, always put the largest part in the stack !!
        if (m - cs <= THRESHOLD)
        {
            if (ce - m <= THRESHOLD)
            {
                if (!si)
                    break;

                e = stack[-- si];
                s = stack[-- si];
            }
            else
            {
                s = m + 1;
                e = ce;
            }
        }
        else if (ce - m <= THRESHOLD)
        {
            s = cs;
            e = m - 1;
        }
        else if (m - cs < ce - m)
        {
            stack[si ++] = m + 1;
            stack[si ++] = ce;

            s = cs;
            e = m - 1;
        }
        else
        {
            stack[si ++] = cs;
            stack[si ++] = m - 1;

            s = m + 1;
            e = ce;
        }
    }
}

void _my_qsort(int* n, int s, int e)
{
    _my_stupid_qsort(n, s, e);
    _my_stupid_qsort_stack(n, s, e);

    int th = e < (THRESHOLD - 1) ? e : (THRESHOLD - 1);
    int min_i = 0;
    for (int i = 1; i <= th; i ++)
        if (n[i] < n[min_i])
            min_i = i;

    int t;
    if (min_i)
    {
        t = n[0];
        n[0] = n[min_i];
        n[min_i] = t;
    }

    int i = 1;
    while (i <= e)
    {
        int t = i - 1;
        while (n[i] < n[t])
            t --;

        if (t != i - 1)
        {
            int tr = i - 1;
            int c = n[i];

            while (tr != t)
            {
                n[tr + 1] = n[tr];
                tr --;
            }
            n[t + 1] = c;
        }
        i ++;
    }

    /* for (int i = 2; i <= e; i ++) */
    /* { */
    /*     if (n[i] >= n[i - 1]) */
    /*         continue; */

    /*     int t = n[i]; */
    /*     int x = i - 1; */

    /*     while (n[x] > t) */
    /*     { */
    /*         n[x + 1] = n[x]; */
    /*         x --; */
    /*     } */
    /*     n[x + 1] = t; */
    /* } */
}

int b_search(int* nums, int s, int e, int target)
{
    if (s > e)
        return -1;

    if (s == e)
        return nums[s] == target ? s : -1;
    int i = (((e - s) + 1) / 2) + s;
    if (nums[i] == target)
        return i;

    return (nums[i] > target) ?
        b_search(nums, s, i - 1, target) : b_search(nums, i + 1, e, target);
}

int b_search_2(int* nums, int size, int target)
{
    int s = 0;
    int e = size - 1;

    while(s <= e)
    {
        int m = s + (e - s) / 2;

        if (nums[m] == target)
            return m;
        if (nums[m] > target)
            e = m - 1;
        else
            s = m + 1;
    }
    return -1;
}

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

struct TreeNode* gen_tree(int* ns, int size)
{
    struct TreeNode **a = malloc(sizeof(struct TreeNode*) * size);
    for(int i = 0; i < size; i++)
    {
        if (ns[i])
        {
            a[i] = malloc(sizeof(struct TreeNode));
            a[i]->val = ns[i];
            a[i]->left = NULL;
            a[i]->right = NULL;

            if (i > 0)
            {
                if (i & 1)
                    a[(i - 1)/2]->left = a[i];
                else
                    a[(i - 1)/2]->right = a[i];
            }
        }
    }
    struct TreeNode* r = a[0];
    free(a);
    return r;
}

struct TreeNode*  find_node(struct TreeNode* r, int v)
{
    if (!r)
        return NULL;
    if (r->val == v)
        return r;

    struct TreeNode* t = find_node(r->left, v);
    if (t)
        return t;
    return find_node(r->right, v);
}

struct Interval* gen_interval(int* ns, int size)
{
    struct Interval* all = malloc(sizeof(struct Interval) * (size / 2));
    int j = 0;
    for (int i = 0; i < size / 2; i ++)
    {
        all[i].start = ns[j ++];
        all[i].end = ns[j ++];
    }
    return all;
}

void out_interval(struct Interval* n, int s)
{
    for (int i = 0; i < s; i ++)
        printf("%d: %d - %d |", i, n[i].start, n[i].end);
    printf("\n");
}


void gtn(struct TreeNode* r, int v, struct TreeNode** n)
{
    if (*n)
        return;

    if (r->val == v)
    {
        *n = r;
        return;
    }

    if (r->left)
        gtn(r->left, v, n);

    if (r->right)
        gtn(r->right, v, n);
}

struct TreeNode* get_treenode(struct TreeNode* r, int v)
{
    struct TreeNode* node = NULL;
    gtn(r, v, &node);
    return node;
}

void tree_pre(struct TreeNode* r)
{
    if (r)
        printf("%d ", r->val);

    if (r->left)
        tree_pre(r->left);

    if (r->right)
        tree_pre(r->right);
}

void tree_in(struct TreeNode* r)
{
    if (r->left)
        tree_in(r->left);

    if (r)
        printf("%d ", r->val);

    if (r->right)
        tree_in(r->right);
}

void tree_post(struct TreeNode* r)
{
    if (r->left)
        tree_post(r->left);

    if (r->right)
        tree_post(r->right);

    if (r)
        printf("%d ", r->val);
}

struct ListNode* genList(int* nums, int numsSize)
{
    struct ListNode* header;
    struct ListNode** cur = &header;

    for(int i = 0; i < numsSize; i ++)
    {
        struct ListNode* c = malloc(sizeof(struct ListNode));
        c->val = nums[i];
        c->next = NULL;
        *cur = c;
        cur = &c->next;
    }

    return header;
}

void outList(struct ListNode* list)
{
    while(list)
    {
        printf(" -> %d ", list->val);
        list = list->next;
    }
    printf("\n");
}

void outTree(struct TreeNode* root)
{
    if (root)
    {
        if (!root->left && !root->right)
            printf("V: %d, L: NULL, R: NULL.\n", root->val);
        else if (root->left && !root->right)
            printf("V: %d, R: NULL.\n", root->val);
        else if (!root->left && root->right)
            printf("V: %d, L: NULL.\n", root->val);
        else
            printf("V: %d.\n", root->val);

        outTree(root->left);
        outTree(root->right);
    }
}

void outl(long *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%ld ", num[i]);
    printf("\n");
}

void out(int *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%4d ", num[i]);
    printf("\n");
}

void outsh(short *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%d ", num[i]);
    printf("\n");
}

void outa(char *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%d ", num[i]);
    printf("\n");
}

void outaa(int** num, int* cs, int size)
{
    for (int i = 0; i < size; i ++)
        out(num[i], cs[i]);
    printf("\n");
}

void outaaa(int** num, int cs, int size)
{
    for (int i = 0; i < size; i ++)
        out(num[i], cs);
    printf("\n");
}


void outd(double *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%lf ", num[i]);
    printf("\n");
}

void outstr(char** r, int rs)
{
    for (int i = 0; i < rs; i ++)
        printf("%s\n", r[i] ? r[i] : "NULL");
    printf("\n");
}

bool verify(int *num, int size)
{
    for (int i = 1; i < size; i ++)
    {
        if (num[i] < num[i - 1])
        {
            printf("verify failed, [%d] %d is less than [%d] %d.\n",
                   i, num[i], i - 1, num[i - 1]);
            return false;
        }
    }
    return true;
}

#define NEIGHBORS_MAX_SIZE 100
struct UndirectedGraphNode {
    int label;
    struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
    int neighborsCount;
};

/* struct NestedInteger { */
/* }; */
/* struct NestedInteger *NestedIntegerInit() */
/* { */
/*     return NULL; */
/* } */

/* void NestedIntegerAdd(struct NestedInteger* ni, struct NestedInteger* el) */
/* { */
/*     printf("ADD LIST L%d -> L%d.\n", el->id, ni->id); */
/* } */

/* void NestedIntegerSetInteger(struct NestedInteger* ni, int i) */
/* { */
/*     printf("ADD VALUE %d -> L%d.\n", i, ni->id); */
/* } */

/* bool NestedIntegerIsInteger(struct NestedInteger * i) */
/* { */
/*     return false; */
/* } */



// FASTEST QSORT IN C !!
// MUST FIGURE OUT WHY !!!

typedef int (*__compar_d_fn_t) (const void *, const void *, void *);
/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)                                                      \
  do                                                                              \
    {                                                                              \
      size_t __size = (size);                                                      \
      char *__a = (a), *__b = (b);                                              \
      do                                                                      \
        {                                                                      \
          char __tmp = *__a;                                                      \
          *__a++ = *__b;                                                      \
          *__b++ = __tmp;                                                      \
        } while (--__size > 0);                                                      \
    } while (0)
/* Discontinue quicksort algorithm when partition gets below this size.
   This particular magic number was chosen to work best on a Sun 4/260. */
#define MAX_THRESH 4
/* Stack node declarations used to store unfulfilled partition obligations. */
typedef struct
  {
    char *lo;
    char *hi;
  } stack_node;
/* The next 4 #defines implement a very fast in-line stack abstraction. */
/* The stack needs log (total_elements) entries (we could even subtract
   log(MAX_THRESH)).  Since total_elements has type size_t, we get as
   upper bound for log (total_elements):
   bits per byte (CHAR_BIT) * sizeof(size_t).  */
#define STACK_SIZE        (CHAR_BIT * sizeof(size_t))
#define PUSH(low, high)        ((void) ((top->lo = (low)), (top->hi = (high)), ++top))
#define        POP(low, high)        ((void) (--top, (low = top->lo), (high = top->hi)))
#define        STACK_NOT_EMPTY        (stack < top)
/* Order size using quicksort.  This implementation incorporates
   four optimizations discussed in Sedgewick:
   1. Non-recursive, using an explicit stack of pointer that store the
      next array partition to sort.  To save time, this maximum amount
      of space required to store an array of SIZE_MAX is allocated on the
      stack.  Assuming a 32-bit (64 bit) integer for size_t, this needs
      only 32 * sizeof(stack_node) == 256 bytes (for 64 bit: 1024 bytes).
      Pretty cheap, actually.
   2. Chose the pivot element using a median-of-three decision tree.
      This reduces the probability of selecting a bad pivot value and
      eliminates certain extraneous comparisons.
   3. Only quicksorts TOTAL_ELEMS / MAX_THRESH partitions, leaving
      insertion sort to order the MAX_THRESH items within each partition.
      This is a big win, since insertion sort is faster for small, mostly
      sorted array segments.
   4. The larger of the two sub-partitions is always pushed onto the
      stack first, with the algorithm then concentrating on the
      smaller partition.  This *guarantees* no more than log (total_elems)
      stack size is needed (actually O(1) in this case)!  */
void
_quicksort (void *const pbase, size_t total_elems, size_t size,
            __compar_d_fn_t cmp, void *arg)
{
  char *base_ptr = (char *) pbase;
  const size_t max_thresh = MAX_THRESH * size;
  if (total_elems == 0)
    /* Avoid lossage with unsigned arithmetic below.  */
    return;
  if (total_elems > MAX_THRESH)
    {
      char *lo = base_ptr;
      char *hi = &lo[size * (total_elems - 1)];
      stack_node stack[STACK_SIZE];
      stack_node *top = stack;
      PUSH (NULL, NULL);
      while (STACK_NOT_EMPTY)
        {
          char *left_ptr;
          char *right_ptr;
          /* Select median value from among LO, MID, and HI. Rearrange
             LO and HI so the three values are sorted. This lowers the
             probability of picking a pathological pivot value and
             skips a comparison for both the LEFT_PTR and RIGHT_PTR in
             the while loops. */
          char *mid = lo + size * ((hi - lo) / size >> 1);
          if ((*cmp) ((void *) mid, (void *) lo, arg) < 0)
            SWAP (mid, lo, size);
          if ((*cmp) ((void *) hi, (void *) mid, arg) < 0)
            SWAP (mid, hi, size);
          else
            goto jump_over;
          if ((*cmp) ((void *) mid, (void *) lo, arg) < 0)
            SWAP (mid, lo, size);
        jump_over:;
          left_ptr  = lo + size;
          right_ptr = hi - size;
          /* Here's the famous ``collapse the walls'' section of quicksort.
             Gotta like those tight inner loops!  They are the main reason
             that this algorithm runs much faster than others. */
          do
            {
              while ((*cmp) ((void *) left_ptr, (void *) mid, arg) < 0)
                left_ptr += size;
              while ((*cmp) ((void *) mid, (void *) right_ptr, arg) < 0)
                right_ptr -= size;
              if (left_ptr < right_ptr)
                {
                  SWAP (left_ptr, right_ptr, size);
                  if (mid == left_ptr)
                    mid = right_ptr;
                  else if (mid == right_ptr)
                    mid = left_ptr;
                  left_ptr += size;
                  right_ptr -= size;
                }
              else if (left_ptr == right_ptr)
                {
                  left_ptr += size;
                  right_ptr -= size;
                  break;
                }
            }
          while (left_ptr <= right_ptr);
          /* Set up pointers for next iteration.  First determine whether
             left and right partitions are below the threshold size.  If so,
             ignore one or both.  Otherwise, push the larger partition's
             bounds on the stack and continue sorting the smaller one. */
          if ((size_t) (right_ptr - lo) <= max_thresh)
            {
              if ((size_t) (hi - left_ptr) <= max_thresh)
                /* Ignore both small partitions. */
                POP (lo, hi);
              else
                /* Ignore small left partition. */
                lo = left_ptr;
            }
          else if ((size_t) (hi - left_ptr) <= max_thresh)
            /* Ignore small right partition. */
            hi = right_ptr;
          else if ((right_ptr - lo) > (hi - left_ptr))
            {
              /* Push larger left partition indices. */
              PUSH (lo, right_ptr);
              lo = left_ptr;
            }
          else
            {
              /* Push larger right partition indices. */
              PUSH (left_ptr, hi);
              hi = right_ptr;
            }
        }
    }
  /* Once the BASE_PTR array is partially sorted by quicksort the rest
     is completely sorted using insertion sort, since this is efficient
     for partitions below MAX_THRESH size. BASE_PTR points to the beginning
     of the array to sort, and END_PTR points at the very last element in
     the array (*not* one beyond it!). */
#define min(x, y) ((x) < (y) ? (x) : (y))
  {
    char *const end_ptr = &base_ptr[size * (total_elems - 1)];
    char *tmp_ptr = base_ptr;
    char *thresh = min(end_ptr, base_ptr + max_thresh);
    char *run_ptr;
    /* Find smallest element in first threshold and place it at the
       array's beginning.  This is the smallest array element,
       and the operation speeds up insertion sort's inner loop. */
    for (run_ptr = tmp_ptr + size; run_ptr <= thresh; run_ptr += size)
      if ((*cmp) ((void *) run_ptr, (void *) tmp_ptr, arg) < 0)
        tmp_ptr = run_ptr;
    if (tmp_ptr != base_ptr)
      SWAP (tmp_ptr, base_ptr, size);
    /* Insertion sort, running from left-hand-side up to right-hand-side.  */
    run_ptr = base_ptr + size;

    while ((run_ptr += size) <= end_ptr)
    {
        tmp_ptr = run_ptr - size;
        while ((*cmp) ((void *) run_ptr, (void *) tmp_ptr, arg) < 0)
            tmp_ptr -= size;
        tmp_ptr += size;
        if (tmp_ptr != run_ptr)
        {
            char *trav;
            trav = run_ptr + size;
            while (--trav >= run_ptr)
            {
                char c = *trav;
                char *hi, *lo;
                for (hi = lo = trav; (lo -= size) >= tmp_ptr; hi = lo)
                    *hi = *lo;
                *hi = c;
            }
        }
    }
  }
}

int cmpfunc(const void *a, const void *b, void* x) {
    return (*(int *)a - *(int *)b);
}

struct Point* cpoints(int* m, int l)
{
    struct Point* ps = malloc(sizeof(struct Point) * l / 2);
    for (int i = 0; i < l; i += 2)
    {
        ps[i / 2].x = m[i];
        ps[i / 2].y = m[i + 1];
    }

    return ps;
}

bool _is_prime(int x, int* r, int ri)
{
    int sq = sqrt(x);
    for (int i = 0; i < ri; i ++)
    {
        if (r[i] > sq)
            return true;

        if (!(x % r[i]))
            return false;
    }
    return true;
}

int* gen_prime(int n, int* rs)
{
    int ri = 0;
    int* r = NULL;

    for (int i = 2; i <= n; i ++)
    {
        if (_is_prime(i, r, ri))
        {
            r = realloc(r, sizeof(int) * (ri + 1));
            r[ri ++] = i;
        }
    }

    *rs = ri;
    return r;
}
