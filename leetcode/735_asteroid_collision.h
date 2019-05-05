/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    *returnSize = 0;
    if (!asteroids || !asteroidsSize)
        return NULL;

    int ai = 0;
    int* a = asteroids;
    for (int i = 1; i < asteroidsSize; i ++)
    {
        if (!a[i])
            continue;

        if (a[i] > 0 || ai < 0 || a[ai] < 0)
            a[++ ai] = a[i];
        else
        {
            int x;
            int j = ai;
            for (; j >= 0; j --)
            {
                x = a[j] + a[i];
                if (x >= 0 || a[j] < 0)
                {
                    if (!x)
                        j --;
                    break;
                }
            }
            ai = j;
            if (x < 0)
                a[++ ai] = a[i];
        }
    }

    *returnSize = ai + 1;
    return asteroids;
}
