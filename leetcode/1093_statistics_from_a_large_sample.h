// Answers within 10^-5 of the true value will be accepted as correct.
// if it's 10^-5, it should use double !!!!!!!

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* sampleStats(int* count, int countSize, int* returnSize)
{
    long sum = 0;
    int num = 0;
    int min_value = 0;
    int max_value = 0;
    int max_num = 0;
    int max_num_value = 0;

    double* r = malloc(sizeof(double) * 5);

    for (int i = 0; i < 256; i ++)
    {
        sum += i * count[i];
        num += count[i];

        if (count[i])
        {
            if (!min_value)
                min_value = i + 1;
            max_value = i + 1;
            if (max_num < count[i])
            {
                max_num = count[i];
                max_num_value = i;
            }
        }
    }

    int median = 0;
    int need = (num % 2) ? (num + 1) / 2 : (num / 2);

    int i = 0;
    for (i = 0; i < 256; i ++)
    {
        if (need <= count[i])
        {
            median = i;
            break;
        }
        need -= count[i];
    }

    r[3] = median;

    if (!(num % 2))
    {
        need += 1;

        for (; i < 256; i ++)
        {
            if (need <= count[i])
            {
                median += i;
                break;
            }
            need -= count[i];
        }

        r[3] = median / 2.0;
    }

    r[0] = min_value - 1;
    r[1] = max_value - 1;
    r[2] = sum / ((double) num);
    r[4] = max_num_value;
    *returnSize = 5;
    return r;
}

