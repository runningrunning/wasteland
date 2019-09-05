// TODO find better solution
// find better and simple solution
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MIN_S(a, b) ((a) < ((b) / 2) ? (a) : ((b) / 2))

int* addNegabinary(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int* s = arr1;
    int sz = arr1Size;

    int* o = arr2;
    int oz = arr2Size;

    if (arr1Size < arr2Size)
    {
        s = arr2;
        sz = arr2Size;
        o = arr1;
        oz = arr1Size;
    }

    if (sz < 2)
    {
        int* t = malloc(sizeof(int) * 2);
        t[1] = s[0];
        t[0] = 0;
        sz = 2;
        s = t;
    }

    for (int i = 0; i < oz; i ++)
    {
        int is = sz - 1 - i;
        int io = oz - 1 - i;
        s[is] += o[io];
    }

    int min_s;

    for (int i = 0; i < sz - 2; i ++)
    {
        int is = sz - 1 - i;

        if (s[is] > 1)
        {
            if (s[is - 1])
            {
                min_s = MIN_S(s[is - 1], s[is]);
                s[is] -= min_s * 2;
                s[is - 1] -= min_s;
            }

            if (s[is] > 1)
            {
                s[is - 1] += s[is] / 2;
                s[is - 2] += s[is] / 2;
                s[is] %= 2;
            }
        }
    }

    int ri = 0;
    int* r = NULL;
    int n[2] = {0};

    min_s = MIN_S(s[0], s[1]);
    s[0] -= min_s;
    s[1] -= min_s * 2;

    if (s[0] > 1 || s[1] > 1)
    {
        if (s[1] > 1)
        {
            s[0] += s[1] / 2;
            n[0] += s[1] / 2;
            s[1] %= 2;
            ri = 1;
        }

        if (s[0] > 1)
        {
            n[0] += s[0] / 2;
            n[1] += s[0] / 2;
            s[0] %= 2;
            ri = 2;
        }
        ri = 2;

        min_s = MIN_S(n[1], s[0]);
        n[1] -= min_s;
        n[0] -= min_s * 2;
    }

    r = malloc(sizeof(int) * (ri + sz));
    bool start = false;

    if (ri)
    {
        ri = 0;
        for (int i = 1; i >= 0; i --)
        {
            if (n[i] || start)
            {
                start = true;
                r[ri ++] = n[i];
            }
        }
    }

    for (int i = 0; i < sz; i ++)
    {
        if (s[i] || start)
        {
            start = true;
            r[ri ++] = s[i];
        }
    }

    if (ri == 0)
    {
        ri = 1;
        r[0] = 0;
    }

    *returnSize = ri;
    return r;
}
