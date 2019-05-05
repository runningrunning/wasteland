// TODO Try to use HASH to do the best !!!!
// // xor | len | sum // | bit flags
// add fast check to minimize the checking time
int s_key(char* s)
{
    /*
    int i = 0;
    int x = 0;
    int a = 0;
    char c = s[i ++];
    while (c)
    {
        x ^= c;
        a += c;
        c = s[i ++];
    }
    return x << 24 | i << 16 | a;
    */
    return s[0] << 24 | strlen(s);
}

/* try to do without hash */
/* hash */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
{
    *returnSize = 0;
    if (!list1 || !list1Size || !list2 || !list2Size)
        return NULL;

    int* l1 = malloc(sizeof(int) * list1Size);
    int* l2 = malloc(sizeof(int) * list2Size);

    int l1i = 0;
    int l2i = 0;

    l1[l1i] = s_key(list1[0]);
    l2[l2i] = s_key(list2[0]);

    int ri = 0;
    int less = list1Size < list2Size ? list1Size : list2Size;
    char** r = malloc(sizeof(char*) * less);

    for (int i = 0; i <= list1Size + list2Size - 2; i ++)
    {
        int l1s = i;
        int l2s = 0;

        int l1e = 0;
        int l2e = i;

        // list1
        if (i >= list1Size - 1)
        {
            l1s = list1Size - 1;
            l2s = i - l1s;
        }

        if (i >= list2Size - 1)
        {
            l2e = list2Size - 1;
            l1e = i - l2e;
        }

        bool found = false;
        for (int t1 = l1s, t2 = l2s; t1 >= l1e && t2 <= l2e; t1 --, t2 ++)
        {
            if (t1 > l1i)
            {
                l1i = t1;
                l1[t1] = s_key(list1[t1]);
            }

            if (t2 > l2i)
            {
                l2i = t2;
                l2[t2] = s_key(list2[t2]);
            }

            if (l1[t1] == l2[t2] && !strcmp(list1[t1], list2[t2]))
            {
                found = true;
                r[ri ++] = list1[t1];
            }
        }

        if (found)
        {
            *returnSize = ri;
            return r;
        }
    }

    *returnSize = 0;
    return NULL;
}
