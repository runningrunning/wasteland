// stupid me, in_hash should also check the value in the hash !!!!!!

// in hash should check the value !
// hash ,is that simple ? better solution or data structure
// complicated, find better one
// sparse matrix ?
// how to represent the date structure
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// idea 1
// store x, y for lamps on that x or y
// store (-1, y - (x + 1)) and (-1, y + (x + 1)) for lamps on that diagonals
// -1 for x, or y is 0
/* int comp(const void* e1, const void* e2) */
/* { */
/*     int* l1 = (int*)(*e1); */
/*     int* l2 = (int*)(*e2); */
/*     return (l1[0] == l2[0]) ? (l1[1] - l2[1]) : (l1[0] - l2[0]); */
/* } */
// idea 2
// hash, store the same thing, but hash with possible to remove thing from it
// or double hash etc ?

void rev_hash(int** hash, int num, int k, int v)
{
    k = k % num;
    if (k < 0)
        k += num;

    if (hash[k] && hash[k][0])
    {
        int n = hash[k][0];
        for (int i = 1; i <= n; i ++)
        {
            if (hash[k][i] == v)
            {
                hash[k][i] = hash[k][n];
                hash[k][0] -= 1;
                break;
            }
        }
    }
}

void set_hash(int** hash, int num, int k, int v)
{
    k = k % num;

    if (k < 0)
        k += num;

    int n = 0;
    if (hash[k])
        n = hash[k][0];

    hash[k] = realloc(hash[k], sizeof(int) * (n + 2));
    hash[k][n + 1] = v;
    hash[k][0] = n + 1;
}

// in value should check value
bool in_hash(int** hash, int num, int k, int** l, int t)
{
    int ok = k;
    k = k % num;
    if (k < 0)
        k += num;
    if (!hash[k] || !hash[k][0])
        return false;

    for (int i = 1; i <= hash[k][0]; i ++)
    {
        int v = hash[k][i];

        if (t == 0)
        {
            if (l[v][0] == ok)
                return true;
        }
        else if (t == 1)
        {
            if (l[v][1] == ok)
                return true;
        }
        else if (t == 2)
        {
            if (l[v][1] - l[v][0] - 1 == ok)
                return true;
        }
        else if (t == 3)
        {
            if (l[v][1] + l[v][0] + 1 == ok)
                return true;
        }
    }
    return false;
}

int* gridIllumination(int N, int** lamps, int lampsRowSize, int *lampsColSizes, int** queries, int queriesRowSize, int *queriesColSizes, int* returnSize)
{
    *returnSize = 0;
    if (!lamps || !lampsRowSize || !queries || !queriesRowSize)
        return NULL;
    int dp;
    int p[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
    int pn = sizeof(p)/sizeof(p[0]);

    for (int i = 0; i < pn; i ++)
    {
        dp = p[i];
        if (dp >= lampsRowSize * 4)
            break;
    }
    int** x_hash = calloc(sizeof(int*), dp);
    int** y_hash = calloc(sizeof(int*), dp);
    int** xy0_hash = calloc(sizeof(int*), dp);
    int** xy1_hash = calloc(sizeof(int*), dp);

    for (int i = 0; i < lampsRowSize; i ++)
    {
        int x = lamps[i][0];
        int y = lamps[i][1];
        set_hash(x_hash, dp, x, i);
        set_hash(y_hash, dp, y, i);
        set_hash(xy0_hash, dp, y - x - 1, i);
        set_hash(xy1_hash, dp, y + x + 1, i);
    }

    int* ret = malloc(sizeof(int) * queriesRowSize);
    for (int i = 0; i < queriesRowSize; i ++)
    {
        int x = queries[i][0];
        int y = queries[i][1];

        if (x >= N || y >= N || x < 0 || y < 0)
            ret[i] = 0;
        else
        {
            ret[i] = in_hash(x_hash, dp, x, lamps, 0) || in_hash(y_hash, dp, y, lamps, 1)
                || in_hash(xy0_hash, dp, y - x - 1, lamps, 2) || in_hash(xy1_hash, dp, y + x + 1, lamps, 3);

            if (ret[i])
            {
                for (int j = x - 1; j <= x + 1; j ++)
                    for (int k = y - 1; k <= y + 1; k ++)
                    {
                        if (j < 0 || j >= N || k < 0 || k >= N)
                            continue;
                        if (in_hash(x_hash, dp, j, lamps, 0) && in_hash(y_hash, dp, k, lamps, 1))
                        {
                            int key = j % dp;
                            for (int m = 1; m <= x_hash[key][0]; m ++)
                            {
                                int t = x_hash[key][m];
                                int lx = lamps[t][0];
                                int ly = lamps[t][1];
                                if (lx == j && ly == k)
                                {
                                    rev_hash(x_hash, dp, lx, t);
                                    rev_hash(y_hash, dp, ly, t);
                                    rev_hash(xy0_hash, dp, ly - lx - 1, t);
                                    rev_hash(xy1_hash, dp, ly + lx + 1, t);
                                    break;
                                }
                            }
                        }
                    }
            }
        }
    }
    *returnSize = queriesRowSize;
    return ret;
}
