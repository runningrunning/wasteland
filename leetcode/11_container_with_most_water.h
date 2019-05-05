void sort_range_l(long *sorted, int a, int b, long* temp)
{
    if (a >= b)
        return;
    int mid = (a + b)  / 2;
    sort_range_l(sorted, a, mid, temp);
    sort_range_l(sorted, mid + 1, b, temp);
    int i = 0;
    int m = a;
    int n = mid + 1;

    while(m <= mid && n <= b)
    {
        temp[i ++] = (sorted[m] & 0x7FFFFFFF) > (sorted[n] & 0x7FFFFFFF) ?
            sorted[n ++] : sorted[m ++];
    }

    while (m <= mid)
        temp[i ++] = sorted[m ++];
    while (n <= b)
        temp[i ++] = sorted[n ++];
    memcpy(&sorted[a], temp, (b - a + 1) * sizeof(long));
}

int maxArea(int *height, int heightSize)
{
    long* merged = malloc(sizeof(long) * heightSize);
    for (long i = 0; i < heightSize; i ++)
        merged[i] = (i << 32) | height[i];

    long* temp = malloc(sizeof(long) * heightSize);
    sort_range_l(merged, 0, heightSize - 1, temp);
    free(temp);

    int* removed_lines = malloc(sizeof(int) * heightSize);
    memset(removed_lines, 0, sizeof(int) * heightSize);

    int c_min = 0;
    int c_max = heightSize - 1;
    int a_max = 0;
    int h_max = merged[heightSize - 1] & 0x7FFFFFFF;

    int current = 0;
    for(int i = 0; i < heightSize - 1; i ++)
    {
        if (((c_max - c_min) * h_max) < a_max)
            break;

        long m = merged[i];
        int h = m & 0x7FFFFFFF;
        int index = m >> 32;
        if (index == c_min)
        {
            current = (c_max - c_min) * h;
            a_max = current > a_max ? current : a_max;
            removed_lines[index] = 1;
            while(removed_lines[++ index]);
            c_min = index;
        }
        else if (index == c_max)
        {
            current = (c_max - c_min) * h;
            a_max = current > a_max ? current : a_max;
            removed_lines[index] = 1;
            while(removed_lines[-- index]);
            c_max = index;
        }
        else
        {
            removed_lines[index] = 1;
            if (index - c_min > c_max - index)
            {
                current = (index - c_min) * h;
                a_max = current > a_max ? current : a_max;
            }
            else
            {
                current = (c_max - index) * h;
                a_max = current > a_max ? current : a_max;
            }
        }
    }
    return a_max;
}
