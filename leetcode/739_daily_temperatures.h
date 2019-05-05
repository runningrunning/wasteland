/* Find better solutions and data structure */
/* it's temperature stack */
/* stack only, try to find another solution ? */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* temperature 30 ~ 100 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    *returnSize = 0;
    if (!temperatures || !temperaturesSize)
        return NULL;

    *returnSize = temperaturesSize;

    int si = 0;
    int ti[101] = {0};
    int ts[101] = {0};
    ti[0] = -1;
    ts[0] = INT_MAX;

    int* ret = malloc(sizeof(int) * temperaturesSize);
    for (int i = temperaturesSize - 1; i >= 0; i --)
    {
        int t = temperatures[i];
        if (t < ts[si])
            si ++;
        else
        {
            int s = 0;
            int e = si;

            while(s < e)
            {
                int m = s + (e - s) / 2;
                if (ts[m] > t)
                    s = m + 1;
                else
                    e = m;
            }
            si = s;
        }
        ts[si] = t;
        ti[si] = i;

        if (si == 1)
            ret[i] = 0;
        else
            ret[i] = ti[si - 1] - i;
    }
    return ret;
}
