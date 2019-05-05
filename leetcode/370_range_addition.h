/* TODO insert use sort array by starting index, popup by ending index using min heap or binary tree with end index */

/*
void gma_sort(int** updates, int s, int e)
{
    if (s >= e)
        return;

    int* t;
    if (updates[s][0] > updates[e][0] ||
        (updates[s][0] == updates[e][0]) && (updates[s][1] > updates[e][1]))
    {
        t = updates[s];
        updates[s] = updates[e];
        updates[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(updates[i][0] < updates[s][0] || ((updates[i][0] == updates[s][0]) && (updates[i][1] < updates[s][1]))) i ++;
        while(updates[e][0] > updates[s][0] || ((updates[e][0] == updates[s][0]) && (updates[e][1] > updates[e][1]))) e --;

        if (i >= e)
        {
            t = updates[s];
            updates[s] = updates[e];
            updates[e] = t;
        }
        else
        {
            t = updates[i];
            updates[i] = updates[e];
            updates[e] = t;
        }
    }
    gma_sort(updates, cs, e - 1);
    gma_sort(updates, e + 1, ce);
}
*/

void gma_sort(int** updates, int s, int e)
{
    if (s >= e)
        return;

    int* t;
    if (updates[s][0] > updates[e][0])
    {
        t = updates[s];
        updates[s] = updates[e];
        updates[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(updates[i][0] < updates[s][0]) i ++;
        while(updates[e][0] > updates[s][0]) e --;

        if (i >= e)
        {
            t = updates[s];
            updates[s] = updates[e];
            updates[e] = t;
        }
        else
        {
            t = updates[i];
            updates[i] = updates[e];
            updates[e] = t;
        }
    }
    gma_sort(updates, cs, e - 1);
    gma_sort(updates, e + 1, ce);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getModifiedArray(int length, int** updates, int updatesRowSize, int updatesColSize, int* returnSize)
{
    if (!length)
        return NULL;

    *returnSize = length;
    int* ret = malloc(sizeof(int) * (length + 1));
    memset(ret, 0, sizeof(int) * (length + 1));
    if (!updates || !updatesRowSize)
        return ret;

    gma_sort(updates, 0, updatesRowSize - 1);

    int pv = 0;
    int cs = 0;
    int ce = -1;

    for (int i = 0; i < length; i ++)
    {
        for (int j = ce + 1; j < updatesRowSize; j ++)
        {
            if (updates[j][0] > i)
                break;

            ce = j;
            pv += updates[j][2];
            ret[updates[j][1] + 1] = 1;
        }

        if (ret[i])
        {
            for (int j = cs; j <= ce; j ++)
            {
                if (updates[j][1] == i - 1)
                    pv -= updates[j][2];
            }

            for (int j = cs; j <= ce; j ++)
            {
                if (updates[j][1] < i)
                {
                    cs = j;
                }
                else
                    break;
            }
        }

        ret[i] = pv;
    }
    return ret;
}
