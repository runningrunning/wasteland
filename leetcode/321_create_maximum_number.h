// just another dp with memory ? NOT 100%
// cheating, code optimization !!!
// find better solutions for this function
// STUPID WRONG ALGORITHM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// DIVIDE AND CONQUER
// GREEDY
// CHEATING THE SOLUTIONS
// NB DIFFERENT SOLUTIONS
// simple is easy ???

// find the top x biggest number in each array and merge them together to get the largest one ?
// how to find the biggest one in each array
// we don't need to generate all of those biggest number to do the compare
// the overall max must come from the biggest number form each array and put together

void _top(int* t, int* n, int ns, int m)
{
    if (ns == m)
        memcpy(t, n, sizeof(int) * m);
    else
    {
        int p = 0;
        int s = 0;
        int e = ns - m;

        for (int i = 0; i < m; i ++)
        {
            s = p ++;
            int max = n[s];
            while (s <= e)
            {
                if (max < n[s])
                {
                    max = n[s];
                    p = s + 1;

                    if (max == 9)
                        break;
                }
                s ++;
            }

            t[i] = max;
            e ++;
        }
    }
}

/* int k = 15;  corner case here */
/* int m1[] = {2, 5, 6, 4, 4, 0}; */
/* int m2[] = {7, 3, 8, 0, 6, 5, 7, 6, 2}; */
void _fmax(int* t, int i, int k, int* n)
{
    int s1 = 0;
    int e1 = i;
    int s2 = i;
    int e2 = k;
    int n1 = 0;
    while (s1 < e1 && s2 < e2)
    {
        if (t[s1] != t[s2])
            n[n1 ++] = t[s1] < t[s2] ? t[s2 ++] : t[s1 ++];
        else
        {
            // IMPORTANT HERE !!!!, compare which one is bigger !!!!!
            int j = 1;
            bool is_large = true;
            for (; j + s1 < e1 && j + s2 < e2; j ++)
                if (t[s1 + j] != t[s2 + j])
                {
                    is_large = t[s1 + j] > t[s2 + j];
                    break;
                }

            if (j + s1 == e1)
                is_large = false;

            n[n1 ++] = is_large ? t[s1 ++] : t[s2 ++];
        }
    }

    if (n1 < k)
    {
        while (s1 < e1)
            n[n1 ++] = t[s1 ++];

        while (s2 < e2)
            n[n1 ++] = t[s2 ++];
    }
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
{
    // find the top x biggerst number for nums1 and nums2
    // at most k + 1 if nums1Size >= k and nums2Size >= k, get k from nums1 or nums2

    *returnSize = 0;
    if (nums1Size + nums2Size < k)
        return NULL;

    *returnSize = k;

    int start = nums2Size >= k ? 0 : (k - nums2Size);
    int end = nums1Size >= k ? k : nums1Size;

    int* max = NULL;
    int* m = malloc(sizeof(int) * k);
    int* n = malloc(sizeof(int) * k);
    int* tmp = malloc(sizeof(int) * k);

    for (int i = start; i <= end; i ++)
    {
        if (i)
            _top(tmp, nums1, nums1Size, i);

        if (k - i)
            _top(tmp + i, nums2, nums2Size, k - i);

        if (!max)
        {
            _fmax(tmp, i, k, m);
            max = m;
        }
        else
        {
            int* t = max == m ? n : m;

            _fmax(tmp, i, k, t);
            bool large = false;
            for (int j = 0; j < k; j ++)
                if (max[j] != t[j])
                {
                    large = max[j] < t[j];
                    break;
                }

            if (large)
                max = t;
        }
    }
    return max;
}

// // it's not that easy to handle equal here !!!
/* /\* // we can do choose the biggest number without generate all of them *\/ */
/* /\* int max1 = nums2Size >= k ? 0 : (k - nums2Size); *\/ */
/* /\* int maxi = 0; *\/ */
/* /\* int* max = malloc(sizeof(int) * k); *\/ */
/* /\* for (int i = 1; i <= nums1Size; i ++) *\/ */
/* /\* { *\/ */
/* /\* } *\/ */

/* // stupid wrong algorithm below, it's not suitable for larger number of int, try with greedy solution ? */
/* // it's greedy + brute force !!! compare the reasult */

/* /\** */
/*  * Return an array of size *returnSize. */
/*  * Note: The returned array must be malloced, assume caller calls free(). */
/*  *\/ */
/* // why it's hard ?? dp ?? */
/* // not dp, but greedy */
/* void mn(int* ns1, int s1, int* ns2, int s2, int k, int* ret, bool comp) */
/* { */
/*     // out(ns1, s1); */
/*     // out(ns2, s2); */

/*     if (!k) */
/*         return; */

/*     int ne1 = s1 + s2 - k; */
/*     int ne2 = s1 + s2 - k; */


/*     ne1 = ne1 >= s1 ? (s1 - 1) : ne1; */
/*     ne2 = ne2 >= s2 ? (s2 - 1) : ne2; */

/*     // printf("=== %d %d %d %d %d %d\n", k, comp, ne1, ne2, s1, s2); */

/*     int max = -1; */
/*     int n1 = -1; */
/*     int n2 = -1; */

/*     for (int i = 0; i <= ne1; i ++) */
/*         if (ns1[i] > max) */
/*         { */
/*             max = ns1[i]; */
/*             n1 = i; */
/*         } */

/*     int max1 = max; */
/*     int a2 = -1; */

/*     for (int i = 0; i <= ne2; i ++) */
/*     { */
/*         if (ns2[i] == max1 && a2 == -1) */
/*             a2 = i; */

/*         if (ns2[i] > max) */
/*         { */
/*             max = ns2[i]; */
/*             n2 = i; */
/*         } */
/*     } */

/*     if (n2 != -1) */
/*     { */
/*         if (comp) */
/*         { */
/*             if (ns2[n2] < ret[0]) */
/*                 return; */

/*             comp = ns2[n2] == ret[0]; */
/*         } */

/*         ret[0] = ns2[n2]; */
/*         // printf("ret0 %d %d\n", n2, ns2[n2]); */
/*         mn(ns1, s1, ns2 + n2 + 1, s2 - n2 - 1, k - 1, ret + 1, comp); */
/*     } */
/*     else if (a2 == -1 || k == 1) */
/*     { */
/*         if (comp) */
/*         { */
/*             if (ns1[n1] < ret[0]) */
/*                 return; */

/*             comp = ns1[n1] == ret[0]; */
/*         } */

/*         ret[0] = ns1[n1]; */
/*         // printf("ret0 %d %d\n", n1, ns1[n1]); */
/*         mn(ns1 + n1 + 1, s1 - n1 - 1, ns2, s2, k - 1, ret + 1, comp); */
/*     } */
/*     // else if (s1 - n1 + s2 - a2 > k) // wrong */
/*     // it's not correct to check s1 - n1 + s2 - a2 > k as */
/*     // ...... 9 ...... (s1 - n1)  // s1 - n1 < k but s1 - n0 > k */
/*     // n0     n1 */
/*     // 9 ........ 99 (s2 - a2) */
/*     // a2 */
/*     // if we add both n1 and a2 into result, then the last 99 of s2 - a2 may not in if (s1 - n1 < k) */
/*     // but if we only add one and comp with others, it can get the right answer */
/*     else if (s1 - n1 > k &&  s2 - a2 > k) */
/*     { */
/*         if (comp) */
/*         { */
/*             if (ns1[n1] < ret[0] || ns2[a2] < ret[1]) */
/*                 return; */

/*             comp = (ns1[n1] == ret[0]) && (ns2[a2] == ret[1]); */
/*         } */

/*         ret[0] = ns1[n1]; */
/*         ret[1] = ns2[a2]; */
/*         /\* printf("ret0 %d %d\n", n1, ns1[n1]); *\/ */
/*         /\* printf("ret1 %d %d\n", a2, ns2[a2]); *\/ */
/*         mn(ns1 + n1 + 1, s1 - n1 - 1, ns2 + a2 + 1, s2 - a2 - 1, k - 2, ret + 2, comp); */
/*     } */
/*     else */
/*     { */
/*         if (comp) */
/*         { */
/*             if (ns1[n1] < ret[0]) */
/*                 return; */
/*             comp = ns1[n1] == ret[0]; */
/*         } */

/*         ret[0] = ns1[n1]; */
/*         // printf("ret0 %d %d\n", n1, ns1[n1]); */
/*         mn(ns1 + n1 + 1, s1 - n1 - 1, ns2, s2, k - 1, ret + 1, comp); */
/*         mn(ns1, s1, ns2 + a2 + 1, s2 - a2 - 1, k - 1, ret + 1, true); */
/*     } */
/* } */

/* int* maxNumber2(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) */
/* { */
/*     int* r = calloc(sizeof(int), k); */
/*     mn(nums1, nums1Size, nums2, nums2Size, k, r, false); */
/*     *returnSize = k; */
/*     return r; */
/* } */
