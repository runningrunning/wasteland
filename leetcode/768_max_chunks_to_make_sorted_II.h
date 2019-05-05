void mcts_sort(int* n, int s, int e)
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
    mcts_sort(n, cs, e - 1);
    mcts_sort(n, e + 1, ce);
}

#define FMASK 0x8000
#define VMASK 0x7FFF

int maxChunksToSorted(int* a, int arrSize)
{
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209};
    int dp = 5;

    for (int i = 0; i < 12; i ++)
        if (pri[i] > (arrSize << 1))
        {
            dp = pri[i];
            break;
        }

    short* hash = calloc(sizeof(short), dp);
    int* arr = malloc(sizeof(int) * arrSize);

    for (int i = 0; i < arrSize; i ++)
        arr[i] = a[i];

    mcts_sort(arr, 0, arrSize - 1);

    for (int i = 0; i < arrSize; i ++)
    {
        int v = arr[i];
        int x = v % dp;
        while ((hash[x] & FMASK) && arr[hash[x] & VMASK] != v)
            x = (x + 1) % dp;
        if (!(hash[x] & FMASK))
            hash[x] = i | FMASK;
    }

    int chunk = 0;
    int left = -1;

    for (int i = 0; i < arrSize; i ++)
    {
        int v = a[i];
        int x = v % dp;
        while ((hash[x] & FMASK) && arr[hash[x] & VMASK] != v)
            x = (x + 1) % dp;
        int y = hash[x] & VMASK;
        if (y < arrSize)
        {
            if (arr[y + 1] == arr[y])
                hash[x] = hash[x] + 1;
        }

        if (y == i)
        {
            if (left == -1)
                chunk ++;
        }
        else
        {
            if (left == -1)
                left = y;
            else if (left < y)
                left = y;
            else if (left == i) // be careful, it's i, not y
            {
                left = -1;
                chunk ++;
            }
        }
    }
    return chunk;
}
