/* TODO too much failed cases!! More Careful!!!! */
void nge_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (nums[s] < nums[e])
    {
        t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;
    for (int i = s + 1; i <= e; i ++)
    {
        while(nums[i] > nums[s]) i ++;
        while(nums[e] < nums[s]) e --;

        if (i >= e)
        {
            t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;
        }
        else
        {
            t = nums[i];
            nums[i] = nums[e];
            nums[e] = t;
        }
    }

    nge_sort(nums, cs, e - 1);
    nge_sort(nums, e + 1, ce);
}

void nge(int* n, int s, int e, int* x, int* y)
{
    if (s >= e)
        return;

    for (int i = s; i <= e; i ++)
    {
        for (int j = i + 1; j <= e; j ++)
        {
            if (n[i] > n[j])
            {
                if (*x == -1 && *y == -1)
                {
                    *x = i;
                    *y = j;
                    nge(n, i + 1, j, x, y);
                }
                else
                {
                    if (*y == j)
                    {
                        if (n[*x] >= n[i])
                            *x = i;
                        nge(n, i + 1, j, x, y);
                    }
                    else
                    {
                        *x = i;
                        *y = j;
                        nge(n, i + 1, j, x, y);
                    }
                }
                return;
            }
        }
    }
}

int nextGreaterElement(int n)
{
    if (n < 10)
        return -1;

    int j = 0;
    int a[20] = {0};

    while(n)
    {
        a[j ++] = n % 10;
        n /= 10;
    }

    int x = -1;
    int y = -1;
    nge(a, 0, j - 1, &x, &y);

    if (x == -1)
        return -1;

    int t;
    t = a[x];
    a[x] = a[y];
    a[y] = t;

    nge_sort(a, 0, y -1);

    long l = 0;
    long o = 1;
    for (int m = 0; m < j; m ++)
    {
        l += a[m] * o;
        o *= 10;
    }
    return l > INT_MAX ? -1 : l;
}
