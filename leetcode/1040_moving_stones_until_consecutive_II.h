// be careful about sort and ^
// more understandable code !
// just one method
// for minimum step, the best way is find a slot and never move again
// so the problem is to fine the stonesSize range with most slots are already occupied
// for maximum step, the best way is to use every possible slot and move multiply times
// how to handle 3, 4, 5, 7, 10 and 3, 4, 5, 6, 10
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void _sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    if (n[s] > n[e])
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];
    }

    if (s + 1 == e)
        return;

    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            if (s != e) // s != e for ^
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];
            }
        }
        else
        {
            n[i] ^= n[e];
            n[e] ^= n[i];
            n[i] ^= n[e];
        }
    }

    _sort(n, os, e - 1);
    _sort(n, e + 1, oe);
}

int* numMovesStonesII(int* stones, int stonesSize, int* returnSize)
{
    int i = 0;
    for (i = 0; i < stonesSize - 1; i ++)
        if (stones[i] > stones[i + 1])
            break;

    if (i != stonesSize - 1)
        _sort(stones, 0, stonesSize -1);

    int* ret = malloc(sizeof(int) * 2);
    int end = 0;
    int min = INT_MAX;

    for (i = 0; i < stonesSize; i ++)
    {
        int need = stones[i] + stonesSize - 1;
        while (end < stonesSize && stones[end] <= need)
            end ++;
        int cur = stonesSize - end + i;

        // take care the 3, 4, 5, 7, 10 and 3, 4, 5, 6, 10
        if (cur == 1 && (stones[end - 1]  - stones[i]) == stonesSize - 2)
            continue;

        min = cur < min ? cur : min;
        if (end == stonesSize)
            break;
    }

    int max = (stones[stonesSize - 2] - stones[0] < stones[stonesSize - 1] - stones[1]) ?
        stones[stonesSize - 1] - stones[1] : stones[stonesSize - 2] - stones[0];
    max -= stonesSize - 2;

    ret[0] = min;
    ret[1] = max;
    *returnSize = 2;
    return ret;
}


// wrong algorithm
/*
int* numMovesStonesII(int* stones, int stonesSize, int* returnSize)
{
    int i = 0;
    for (i = 0; i < stonesSize - 1; i ++)
        if (stones[i] > stones[i + 1])
            break;

    if (i != stonesSize - 1)
        _sort(stones, 0, stonesSize - 1);


    int s = 0;
    int e = stonesSize - 1;
    int n = 0;
    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    // wrong, for minimum, it's not always in the smaller delta
    while (true)
    {
        int ds = stones[e - 1] - stones[s];
        int de = stones[e] - stones[s + 1];
        printf("%d %d.\n", ds, de);
        if (ds <= de && ds + 1 >= stonesSize)
        {
            e --;
            n ++;
            continue;
        }

        if (de + 1 >= stonesSize)
        {
            s ++;
            n ++;
            continue;
        }

        if (ds + 1 >= stonesSize)
        {
            e --;
            n ++;
            continue;
        }
        break;
    }
    ret[0] = n;

    s = 0;
    e = stonesSize - 1;
    n = 0;

    // correct, but for maximum, there is better method !
    while (true)
    {
        int ds = stones[e - 1] - stones[s];
        int de = stones[e] - stones[s + 1];

        if (ds >= de && ds + 1 >= stonesSize)
        {
            stones[e] = stones[e - 1];
            stones[e - 1] -= 1;
            n ++;
            continue;
        }

        if (de + 1 >= stonesSize)
        {
            stones[s] = stones[s + 1];
            stones[s + 1] += 1;
            n ++;
            continue;
        }

        if (ds + 1 >= stonesSize)
        {
            stones[e] = stones[e - 1];
            stones[e - 1] -= 1;
            n ++;
            continue;
        }
        break;
    }
    ret[1] = n;
    return ret;
}
*/
