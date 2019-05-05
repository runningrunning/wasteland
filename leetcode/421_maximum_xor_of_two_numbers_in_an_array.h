// try to not use struct, only int*
typedef struct _Node
{
    struct _Node* m[2];
} Node;

int findMaximumXOR(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;
    if (numsSize <= 1)
        return 0;
    if (numsSize == 2)
        return nums[0] ^ nums[1];

    Node* r = malloc(sizeof(Node));
    r->m[0] = r->m[1] = NULL;

    int ml = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int t = 0;
        int c = nums[i];
        int f = 1 << 30;
        Node* d = r;
        Node* e = r;
        int l = 0;

        for (int j = 30; j >= 0; j --)
        {
            int n = (f & c) ? 1 : 0;

            if (d)
            {
                if (d->m[!n])
                {
                    t |= f;
                    if (t <= ml)
                        break;
                    if (!l)
                        l = f;
                }
                d = d->m[!n] ? d->m[!n] : d->m[n];
            }

            if (!e->m[n])
            {
                Node* p = malloc(sizeof(Node));
                p->m[0] = p->m[1] = NULL;
                e->m[n] = p;
            }
            e = e->m[n];
            f >>= 1;
        }

        if (max < t)
        {
            max = t;
            ml = l - 1;
        }
    }
    return max;
}
