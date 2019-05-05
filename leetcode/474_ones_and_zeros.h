// TODO: FIND a WAY TO OPTIMIZE THIS !!!
// knapsack problem with multiple dimensions !! 2D knapsack !
// why it's faster than others ?
// Learn a lot, different way to write DP algorithms
// one is from number of bits and the other one is from every sting we want to match
// the one from number of bits is much better, rolling arrays
//
// PEEK HINT, don't use str index as cache, use m*n as
// try more DP now, how to optimize!!
// DP + heap again ???!!! it's that way ???
// greedy or DP ?
// how to sort ?
// is it mature to a standard DP SOLUTION
// should I use memory here ? it's fine to remember every m's and n's in each slot, 600 * 100 * 100, it's too much
// time limit !!!!!!
// how to optimize this kind of DP problems ???????
// save all of status ?
// just plain DP, store every status


// just simple DP, DP from strs !!!!!!
int fmf_str(int* ns, int s, int e, int num, int* max, int m, int n, int* cache, int oc, int o)
{
    if (s > e || (!m && !n))
        return 0;

    if (e - s + 1 + num < *max)
        return 0;

    if (cache[s * oc + m * o + n])
        return cache[s * oc + m * o + n] - 1;

    int nm = (ns[s] >> 8) & 0xFF;
    int nn = ns[s] & 0xFF;

    int with = 0;
    int with_out = 0;

    if (m >= nm && n >= nn)
        with = fmf_str(ns, s + 1, e, num + 1, max, m - nm, n - nn, cache, oc, o) + 1;

    with_out = fmf_str(ns, s + 1, e, num, max, m, n, cache, oc, o);

    int _max = with > with_out ? with : with_out;
    cache[s * oc + m * o + n] = _max + 1;

    if (_max + num > *max)
        *max = _max + num;

    return _max;
}

#define GET_MAX(x, y) (x) > (y) ? (x) : (y)

void fmf_nums(int* ns, int nl, int m, int n, int* cache)
{
    for (int s = 0; s < nl; s ++)
    {
        int nm = ns[s] >> 8;
        int nn = ns[s] & 0xFF;

        for (int i = m; i >= nm; i --)
            for (int j = n; j >= nn; j --)
                cache[i * (n + 1) + j] = GET_MAX(cache[i * (n + 1) + j], cache[(i - nm) * (n + 1) + j - nn] + 1);
    }
}

int findMaxForm(char** strs, int strsSize, int m, int n)
{
    int ni = 0;
    int* ns = malloc(sizeof(int) * strsSize);
    int num = 0;

    for (int i = 0; i < strsSize; i ++)
    {
        ns[ni] = 0;

        int j = 0;
        char* s = strs[i];
        char c = s[j ++];

        int n0 = 0;
        int n1 = 0;

        while (c)
        {
            if (c == '0')
                n0 ++;
            else
                n1 ++;

            c = s[j ++];
        }

        // always contain 1 byte
        if (n0 + n1 == 1)
        {
            if (m >= n0 && n >= n1)
            {
                m -= n0;
                n -= n1;
                num ++;
            }
        }
        else
            ns[ni ++] = n0 << 8 | n1;
    }

    // DP fmf_nums
    int* cache = calloc(sizeof(int), (m + 1) * (n + 1));
    fmf_nums(ns, ni, m, n, cache);
    return cache[(m + 1) * (n + 1) - 1] + num;

    // m, n start from 0
    //  DP fmf_str

    /* int* cache = calloc(sizeof(int), ni * (m + 1) * (n + 1)); */
    /* int max = 0; */
    /* fmf_str(ns, 0, ni - 1, 0, &max, m, n, cache, (m + 1) * (n + 1), n + 1); */
    /* free(cache); */
    /* free(ns); */
    /* return max + num; */

}
