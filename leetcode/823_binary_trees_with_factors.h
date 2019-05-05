// no hash, two pinter be careful about overflow int temporary, use
// long
#define MOD 1000000007

void nfbt_sort(int* n, int s, int e)
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

    if (s + 1 >= e)
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

    nfbt_sort(n, cs, e - 1);
    nfbt_sort(n, e + 1, ce);
}

int numFactoredBinaryTrees(int* A, int ASize)
{
    nfbt_sort(A, 0, ASize - 1);
    long* size = malloc(sizeof(long) * ASize);
    long num = 0;

    for (int i = 0; i < ASize; i ++)
    {
        long t = 0;
        t ++;

        int a = A[i];
        int sq = sqrt(a);
        int end = i - 1;

        for (int j = 0; j < i; j ++)
        {
            if (A[j] > sq)
                break;

            if (!(a % A[j]))
            {
                int n = a / A[j];

                if (n == A[j])
                {
                    t += size[j] * size[j];
                    break;
                }
                else
                {
                    while (end && A[end] > n)
                        end --;

                    if (A[end] == n)
                        t += size[end] * size[j] * 2;
                }
            }
        }

        size[i] = t;
        num += t;
        num %= MOD;
    }
    return num;
}

// use hash to find next
/*
int numFactoredBinaryTrees_hash(int* A, int ASize)
{
    nfbt_sort(A, 0, ASize - 1);
    long* size = malloc(sizeof(long) * ASize);

    int hb[68] = {0};
    int primer = 2053; // 2053 should use 65 bytes
    int* hash = malloc(sizeof(int) * primer);

    int x, y;
    long num = 0;

    for (int i = 0; i < ASize; i ++)
    {
        long t = 0;
        t ++;

        int a = A[i];

        int h = a % primer;
        x = h / 32;
        y = h % 32;
        while ((hb[x] & (1 << y)) && A[hash[h]] != a)
        {
            h = (h + 1) % primer;
            x = h / 32;
            y = h % 32;
        }
        hash[h] = i;
        hb[x] |= 1 << y;

        int end = sqrt(a);

        for (int j = 0; j < i; j ++)
        {
            if (A[j] > end)
                break;

            if (!(a % A[j]))
            {
                int n = a / A[j];

                if (n == A[j])
                    t += size[j] * size[j];
                else
                {
                    h = n % primer;
                    x = h / 32;
                    y = h % 32;

                    while ((hb[x] & (1 << y)) && A[hash[h]] != n)
                    {
                        h = (h + 1) % primer;
                        x = h / 32;
                        y = h % 32;
                    }

                    if (hb[x] & (1 << y))
                    {
                        t += size[j] * size[hash[h]] * 2;
                    }
                }
            }
        }
        size[i] = t;

        num += t;
        num %= MOD;
    }
    return num;
}
*/
