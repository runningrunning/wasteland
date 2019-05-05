void wiggleSort(int* nums, int numsSize)
{
    if (numsSize < 2)
        return;

    for (int i = 0; i < numsSize - 1; i += 2)
    {
        if (nums[i] > nums[i + 1])
        {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];
        }
    }

    if (numsSize < 3)
        return;

    for (int i = 1; i < numsSize - 1; i += 2)
    {
        if (nums[i] < nums[i + 1])
        {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];
        }
    }

    return;
}

/* void ws_sort(int* n, int s, int e, int a) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int t; */
/*     if (n[s] > n[e]) */
/*     { */
/*         t = n[s]; */
/*         n[s] = n[e]; */
/*         n[e] = t; */
/*     } */

/*     if (s + 1 == e) */
/*         return; */

/*     int cs = s; */
/*     int ce = e; */
/*     for (int i = s + 1; i <= e; i ++) */
/*     { */
/*         while(n[i] < n[s]) i++; */
/*         while(n[e] > n[s]) e--; */

/*         if (i >= e) */
/*         { */
/*             t = n[s]; */
/*             n[s] = n[e]; */
/*             n[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = n[i]; */
/*             n[i] = n[e]; */
/*             n[e] = t; */
/*         } */
/*     } */

/*     if (e == a) */
/*         return; */

/*     if (a < e) */
/*         ws_sort(n, cs, e - 1, a); */
/*     else */
/*         ws_sort(n, e + 1, ce, a); */
/* } */

/* void wiggleSort(int* nums, int numsSize) */
/* { */
/*     ws_sort(nums, 0, numsSize - 1, (numsSize - 1) / 2); */
/*     if (numsSize < 3) */
/*         return; */

/*     out(nums, numsSize); */
/*     int i = 1; */
/*     int e = numsSize - 2; */
/*     if (numsSize & 1) */
/*         e += 1; */

/*     int t; */
/*     while (i < e) */
/*     { */
/*         t = nums[i]; */
/*         nums[i] = nums[e]; */
/*         nums[e] = t; */
/*         i += 2; */
/*         e -= 2; */
/*     } */
/* } */
