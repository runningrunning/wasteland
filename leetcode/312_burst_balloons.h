// MY FAV DP !!!
// dp like check every time
// CHEATING READ THE SOLUTION !!!!!
// change the view of the code, which one is the last to remove, then divide it into 2 field
// To solve this problem, it will be helpful to think about how to divide the original problem to a smaller scale problem. Suppose the last balloon bursting is balloon index i, it is natually divide the original problem into two parts. The part before balloon i and the part after balloon i. This two parts are independent because of balloon i, they will never be adjacent parts of each other.

// 375 guess number higher or lower II ?
// how to use DP to represent this?
// up to down and down to up algorithm

// simple DP? how to prove the answer it correct?, not it's not correct and it can not get the best answer
// e.g. {2, 8, 2}, it's 40, not 38, 1 * 2 * 8 + 1 * 2 * 8 + 8;
// wrong algorithm !!!!!!, browser all of them ?
// a little bit wrong representation ???, by removing same contents but higher score

// which one to burst at the first ?? !!! NOT !!!
// which one to burst at the LAST !!!!!!

#define _MAX(a, b) (a) > (b) ? (a) : (b)

int maxCoins(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int** d = malloc(sizeof(int*) * (numsSize + 1));
    for (int i = 0; i <= numsSize; i ++)
        d[i] = calloc(sizeof(int), (numsSize + 1));

    for (int i = 0; i < numsSize; i ++)
    {
        for (int j = 0; j + i < numsSize; j ++)
        {
            int pj = j == 0 ? 1 : nums[j - 1];
            int fj = (j + i == numsSize - 1) ? 1 : nums[j + i + 1];
            int mj = pj * fj;

            if (i == 0)
                d[j][j] = nums[j] * mj;
            else
            {
                for (int k = j; k <= j + i; k ++)
                {
                    if (k == j)
                        d[j][j + i] = mj * nums[k] + d[k + 1][j + i];
                    else if (k == j + i)
                        d[j][j + i] = _MAX(d[j][j + i], mj * nums[k] + d[j][k - 1]);
                    else
                        d[j][j + i] = _MAX(d[j][j + i], pj * nums[k] * fj + d[j][k - 1] + d[k + 1][j + i]);
                }
            }
        }
    }

    return d[0][numsSize - 1];

}

// STUPID WRONG ALGORITHMS !!!
/* int maxCoins(int* nums, int numsSize) */
/* { */
/*     if (!numsSize) */
/*         return 0; */

/*     char** cur; */
/*     char** next; */

/*     int** all = malloc(sizeof(int*) * numsSize); */
/*     cur = malloc(sizeof(char*) * numsSize); */
/*     next = malloc(sizeof(char*) * numsSize); */

/*     for (int i = 0; i < numsSize; i ++) */
/*         all[i] = calloc(sizeof(int), numsSize); */

/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         cur[i] = calloc(sizeof(char), numsSize); */
/*         next[i] = calloc(sizeof(char), numsSize); */

/*         cur[i][i] = 1; */
/*         all[0][i] = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 == numsSize ? 1 : nums[i + 1]); */
/*     } */

/*     int* pre = malloc(sizeof(int) * numsSize); */
/*     char** _pre = cur; */
/*     char** _cur = next; */

/*     // out(all[0], numsSize); */

/*     for (int i = 1; i < numsSize; i ++) */
/*     { */
/*         for (int c = 0; c < numsSize; c ++) */
/*         { */
/*             int pmax = 0; */
/*             int pin = 0; */
/*             int cn = nums[c]; */
/*             bool got = false; */

/*             for (int p = 0; p < numsSize; p ++) */
/*             { */
/*                 if (_pre[p][c] || !all[i - 1][p]) */
/*                     continue; */

/*                 got = true; */

/*                 int px = all[i - 1][p]; */
/*                 int pp, po; */

/*                 int pi = c - 1; */
/*                 while (pi >= 0 && _pre[p][pi]) */
/*                     pi --; */

/*                 pp = pi == -1 ? 1 : nums[pi]; */
/*                 int pn = c + 1; */
/*                 while (pn < numsSize && _pre[p][pn]) */
/*                     pn ++; */
/*                 po = pn == numsSize ? 1 : nums[pn]; */


/*                 // not only choose the bigger one, but also choose the one with smallest remover */
/*                 if (px + cn * pp * po > pmax) */
/*                 { */
/*                     pmax = px + cn * pp * po; */
/*                     pin = p; */
/*                 } */
/*                 else if (px + cn * pp * po == pmax && nums[pin] > nums[p]) */
/*                 { */
/*                     pin = p; */
/*                 } */
/*             } */

/*             if (got) */
/*             { */
/*                 for (int j = 0; j < numsSize; j ++) */
/*                     _cur[c][j] = _pre[pin][j]; */
/*                 _cur[c][c] = 1; */
/*                 // outa(_cur[c], numsSize); */
/*                 // printf("for c %d, it's %d.\n", c, pin); */
/*                 all[i][c] = pmax; */
/*             } */
/*             else */
/*             { */
/*                 all[i][c] = 0; */
/*             } */
/*         } */

/*         // out(all[i], numsSize); */
/*         _pre = _pre == cur ? next : cur; */
/*         _cur = _cur == cur ? next : cur; */
/*     } */

/*     int max = 0; */
/*     for (int i = 0; i < numsSize; i ++) */
/*         if (all[numsSize - 1][i] > max) */
/*             max = all[numsSize - 1][i]; */
/*     return max; */
/* } */

/*
void _mc_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }
    _mc_sort(n, cs, e - 1);
    _mc_sort(n, e + 1, ce);
}

int maxCoins(int* nums, int numsSize)
{
    int* m = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        m[i] = (nums[i] << 16) | i;
        nums[i] = (i << 16) | ((i + 2) << 8) | nums[i];
    }
    _mc_sort(m, 0, numsSize - 1);

    int x = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int c = m[i] & 0xFFFF;
        int mid = m[i] >> 16;
        int left = ((nums[c] >> 16) & 0xFF)- 1;
        int right = ((nums[c] >> 8) & 0xFF) - 1;

        if (left == -1 && right == numsSize)
            x += mid;
        else if (left == -1)
        {
            x += mid * (nums[right] & 0xFF);
            nums[right] &= 0xFFFF;
        }
        else if (right == numsSize)
        {
            x += mid * (nums[left] & 0xFF);
            nums[left] = (nums[left] & 0xFFFF00FF) | ((numsSize + 1) << 8);
        }
        else
        {
            x += mid * (nums[left] & 0xFF) * (nums[right] & 0xFF);
            nums[right] = (nums[right] & 0xFFFF) | (left + 1) << 16;
            nums[left] = (nums[left] & 0xFFFF00FF) | ((right + 1) << 8);
        }
    }
    return x;
}
*/
