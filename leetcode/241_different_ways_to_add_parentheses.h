int* dwtc(int* nums, int s, int e, int* op, int* size)
{
    if (s + 1 == e)
    {
        int* r = malloc(sizeof(int));
        *size = 1;
        if (!op[s])
            r[0] = nums[s] * nums[e];
        else
            r[0] = nums[s] + nums[e] * op[s];
        return r;
    }

    int rs = 0;
    int* r = dwtc(nums, s + 1, e, op, &rs);

    for (int i = 0; i < rs; i ++)
    {
        if (!op[s])
            r[i] = nums[s] * r[i];
        else
            r[i] = nums[s] + r[i] * op[s];
    }

    int ls = 0;
    int* lr = dwtc(nums, s, e - 1, op, &ls);
    r = realloc(r, sizeof(int) * (rs + ls));

    for (int i = 0; i < ls; i ++)
    {
        if (!op[e - 1])
            r[rs + i] = nums[e] * lr[i];
        else
            r[rs + i] = lr[i] + nums[e] * op[e - 1];
    }
    rs += ls;
    for (int i = s + 1; i <= e - 2; i++)
    {
        int f1;
        int* rf1 = dwtc(nums, s, i, op, &f1);
        int f2;
        int* rf2 = dwtc(nums, i + 1, e, op, &f2);

        r = realloc(r, sizeof(int) * (rs + f2 * f1));

        for (int j = 0; j < f1 * f2; j ++)
        {
            int fc1 = rf1[j / f2];
            int fc2 = rf2[j % f2];

            if (!op[i])
                r[rs + j] = fc1 * fc2;
            else
                r[rs + j] = fc1 + fc2 * op[i];
        }
        rs += f1 * f2;
    }
    *size = rs;
    return r;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char* input, int* returnSize)
{
    if (!input)
    {
        *returnSize = 0;
        return NULL;
    }

    int i = 0;
    char c = input[i];

    int si = 0;
    int* st = malloc(sizeof(int) * 1024);
    int* ot = malloc(sizeof(int) * 1024);

    bool negative = false;
    int num = 0;

    while(c)
    {
        if (c <= '9' && c >= '0')
            num = num * 10 + c - '0';
        else
        {
            if (si && (!(si % 1024)))
            {
                st = realloc(st, sizeof(int) * (1024 + si));
                ot = realloc(ot, sizeof(int) * (1024 + si));
            }

            if (!i)
                negative = true;
            else
            {
                st[si] = negative ? - num : num;

                ot[si] = c == '*' ? 0 : (c == '+' ? 1 : - 1);

                if (input[i + 1] == '-')
                {
                    i ++;
                    negative = true;
                }
                else
                    negative = false;


                si ++;
                num = 0;
            }
        }
        c = input[++ i];
    }
    st[si ++] = negative ? - num : num;

    if (si == 1)
    {
        int* r = malloc(sizeof(int));
        *returnSize = 1;
        r[0] = st[0];
        return r;
    }
    return dwtc(st, 0, si - 1, ot, returnSize);
}
