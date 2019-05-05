// just cached the results ??
// better solutions ??
// permutations here
int nsp(int* a, int s, int p, int l, int n, int** store, int** fg)
{
    if (store[p][l])
        return store[p][l] - 1;

    if (n == 1)
    {
        for (int i = 0; i < s; i ++)
            if (a[i] >= 0)
            {
                store[p][l] = fg[p][i] + 1;
                return fg[p][i];
            }
        store[p][l] = 1;
        return 0;
    }

    int pre = -1;
    int ret = 0;
    for (int i = 0; i < s; i ++)
    {
        if (a[i] >= 0 && fg[p][i] && a[i] != pre)
        {
            pre = a[i];
            a[i] = - a[i] - 1;
            ret += nsp(a, s, i, l & (~(1 << i)), n - 1, store, fg);
            a[i] = - (a[i] + 1);
        }
    }

    store[p][l] = ret + 1;
    return ret;
}

int numSquarefulPerms(int* A, int ASize)
{
    if (!ASize)
        return 0;

    if (ASize == 1)
    {
        int x = sqrt(A[0]);
        return (x * x) == A[0] ? 1 : 0;
    }

    // sort
    for (int i = 0; i < ASize; i ++)
        for (int j = i + 1; j < ASize; j ++)
        {
            if (A[j] < A[i])
            {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }

    int num = (1 << ASize) - 1;
    // how many possible permutations start with [i][bits], cached result
    int** store = calloc(sizeof(int*), ASize);
    int* fn = calloc(sizeof(int), ASize);
    int** fg = malloc(sizeof(int*) * ASize);
    for (int i = 0; i < ASize; i ++)
        fg[i] = calloc(sizeof(int), ASize);
    for (int i = 0; i < ASize; i ++)
    {
        int n = 0;
        for (int j = i + 1; j < ASize; j ++)
        {
            int x = sqrt(A[i] + A[j]);
            if (x * x == A[i] + A[j])
            {
                fg[i][j] = fg[j][i] = 1;
                fn[i] ++;
                fn[j] ++;
                n ++;
            }
        }
        store[i] = calloc(sizeof(int), num);
        if (!fn[i])
            return 0;
    }

    int ret = 0;
    int pre = A[0] - 1;
    for (int i = 0; i < ASize; i ++)
    {
        if (pre != A[i])
        {
            A[i] = - A[i] - 1;
            ret += nsp(A, ASize, i, num & (~(1 << i)), ASize - 1, store, fg);
            A[i] =  - (A[i] + 1);
            pre = A[i];
        }
    }
    return ret;
}
