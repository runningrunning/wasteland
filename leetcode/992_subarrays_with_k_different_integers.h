// DO IT AGAIN
// think too much, use wrong method
// from hash with double linked list = simple sliding windows !!!
// stupid wrong algorithm !!!!! try sliding windows here
// sliding windows ?
// complicated do more !!!
// hash with removed + smallest heap with first out
// not heap, but double linked list ???
// try my own solution
// using sliding windows here

int subarraysWithKDistinct(int* A, int ASize, int K)
{
    int bits[20005] = {0};
    int in_k = 0;

    int num = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < ASize; i ++)
    {
        if (in_k == K && !bits[A[i]])
        {
            bits[A[end ++]] --;
            start = end;
            in_k --;
        }
        if (!bits[A[i]])
            in_k ++;
        bits[A[i]] ++;

        while (bits[A[end]] != 1)
            bits[A[end++]] --;
        if (in_k == K)
            num += end - start + 1;
    }
    return num;
}

typedef struct _LNode {
    int value;
    int index;
    struct _LNode* pre;
    struct _LNode* nxt;
} LNode;

typedef struct _HNode {
    int n;
    LNode** v;
} HNode;

LNode* in_hash(HNode** hash, int dp, int k)
{
    int ok = k;
    k %= dp;
    if (!hash[k] || !hash[k]->n)
        return false;

    HNode* h = hash[k];

    for (int i = 0; i < h->n; i ++)
    {
        LNode* x = h->v[i];
        if (x->value == ok)
            return x;
    }
    return NULL;
}

void set_hash(HNode** hash, int dp, int k, LNode* v)
{
    k %= dp;
    HNode* h = hash[k];
    if (!h)
    {
        h = malloc(sizeof(HNode));
        h->v = NULL;
        h->n = 0;
        hash[k] = h;
    }
    h->v = realloc(h->v, sizeof(LNode*) * (h->n + 1));
    h->v[h->n] = v;
    h->n += 1;
}

void rev_hash(HNode** hash, int dp, int k, LNode* v)
{
    k %= dp;
    if (hash[k] && hash[k]->n)
    {
        HNode* h = hash[k];
        for (int i = 0; i < h->n; i ++)
        {
            if (h->v[i] == v)
            {
                h->v[i] = h->v[h->n - 1];
                h->n --;
                break;
            }
        }
    }
}

int subarraysWithKDistinct1(int* A, int ASize, int K)
{
    if (!A || !ASize || !K)
        return 0;
    int num = 0;
    if (K == 1)
    {
        int n = 1;
        int p = A[0];
        for (int i = 1; i < ASize; i ++)
        {
            if (p == A[i])
                n ++;
            else
            {
                num += (n + 1) * n / 2;
                p = A[i];
                n = 1;
            }
        }
        num += (n + 1) * n / 2;
        return num;
    }

    int dp;
    int p[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
    int pn = sizeof(p)/sizeof(p[0]);

    for (int i = 0; i < pn; i ++)
    {
        dp = p[i];
        if (dp >= 4 * ASize)
            break;
    }

    HNode** hash = calloc(sizeof(HNode*), dp);

    int last_new_value = -1;
    int last_new_index = -1;
    LNode* last_seen_header = NULL;
    LNode* last_seen_end = NULL;

    int start = 0;
    int in_k = 0;
    for (int i = 0; i < ASize; i ++)
    {
        int v = A[i];
        LNode* n = in_hash(hash, dp, v);
        if (in_k == K && !n)
        {
            start = last_seen_header->index + 1;
            rev_hash(hash, dp, last_seen_header->value, last_seen_header);
            LNode* t = last_seen_header;
            last_seen_header = last_seen_header->nxt;
            last_seen_header->pre = NULL;
            free(t);
            in_k -= 1;
        }

        if (!n)
        {
            in_k ++;
            last_new_value = v;
            last_new_index = i;
            LNode* x = malloc(sizeof(LNode));
            x->value = v;
            x->index = i;
            x->pre = x->nxt = NULL;
            if (!last_seen_header)
            {
                x->pre = NULL;
                last_seen_header = x;
            }
            else
            {
                x->pre = last_seen_end;
                last_seen_end->nxt = x;
            }
            last_seen_end = x;
            x->nxt = NULL;
            set_hash(hash, dp, v, x);
        }
        else
        {
            n->index = i;
            if (last_seen_end != n)
            {
                if (last_seen_header == n)
                {
                    last_seen_header = n->nxt;
                    n->nxt->pre = NULL;
                }
                else
                {
                    n->pre->nxt = n->nxt;
                    n->nxt->pre = n->pre;
                }

                n->pre = last_seen_end;
                last_seen_end->nxt = n;
                last_seen_end = n;
                n->nxt = NULL;
            }
        }

        if (in_k == K)
        {
            // printf("%d is %d %d = %d.\n", i, last_seen_header->index, start, (last_seen_header->index - start + 1));
            num += (last_seen_header->index - start + 1);
        }
    }
    return num;
}
