/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize)
{
    int* r = malloc(sizeof(int) * k);
    *returnSize = k;

    int s = 0;
    int e = arrSize - k;

    while (s < e)
    {
        int m = (s + e) / 2;

        if (x - arr[m] > arr[m + k] -  x)
            s = m + 1;
        else
            e = m;
    }

    memcpy(r, &arr[s], sizeof(int) * k);
    return r;
}

/* stupid wrong algorithm */
/* int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) */
/* { */
/*     int s = 0; */
/*     int e = arrSize - 1; */
/*     int* r = malloc(sizeof(int) * k); */
/*     *returnSize = k; */

/*     if (x <= arr[s]) */
/*     { */
/*         memcpy(r, arr, sizeof(int) * k); */
/*         return r; */
/*     } */
/*     else if (x >= arr[e]) */
/*     { */
/*         memcpy(r, &arr[arrSize - k], sizeof(int) * k); */
/*         return r; */
/*     } */
/*     while (s < e) */
/*     { */
/*         int m = s + (e - s) / 2; */
/*         if (arr[m] < x) */
/*             s = m + 1; */
/*         else */
/*             e = m; */
/*     } */

/*     if (x - arr[s - 1] == arr[s] - x) */
/*         s -= 1; */

/*     int start = s; */
/*     int pre_s = s - k + 1; */
/*     int post_s = s + k - 1; */


/*     if (k == 1) */
/*     { */
/*         r[0] = arr[s]; */
/*         return r; */
/*     } */

/*     pre_s = pre_s < 0 ? 0 : pre_s; */
/*     post_s = post_s >= arrSize ? arrSize - 1 : post_s; */

/*     int pre_d = x - arr[pre_s]; */
/*     int post_d = arr[post_s] - x; */

/*     int diff = pre_d < post_d ? post_d : pre_d; */
/*     int num = post_s - pre_s + 1; */

/*     s = 0; */
/*     e = diff; */

/*     while (s < e) */
/*     { */
/*         int m = s + (e - s) / 2; */

/*         // pre */
/*         int pr_m = x - m; */
/*         int pr_s = pre_s; */
/*         int pr_e = start; */

/*         while (pr_s < pr_e) */
/*         { */
/*             int xm = pr_s + (pr_e - pr_s) / 2; */
/*             if (arr[xm] < pr_m) */
/*                 pr_s = xm + 1; */
/*             else */
/*                 pr_e = xm; */
/*         } */

/*         // post */
/*         int po_m = x + m; */
/*         int po_s = start; */
/*         int po_e = post_s; */
/*         while (po_s < po_e) */
/*         { */
/*             int xm = po_e - (po_e - po_s) / 2; */
/*             if (arr[xm] > po_m) */
/*                 po_e = xm - 1; */
/*             else */
/*                 po_s = xm; */
/*         } */

/*         if (po_s - pr_s + 1 >= k) */
/*             e = m; */
/*         else */
/*             s = m + 1; */
/*     } */

/*     // pre */
/*     int pr_m = x - s; */
/*     int pr_s = 0; */
/*     int pr_e = start; */

/*     while (pr_s < pr_e) */
/*     { */
/*         int xm = pr_s + (pr_e - pr_s) / 2; */
/*         if (arr[xm] < pr_m) */
/*             pr_s = xm + 1; */
/*         else */
/*             pr_e = xm; */
/*     } */

/*     while ((pr_s + k < arrSize) && arr[pr_s + k] - x < x - arr[pr_s + 1]) */
/*         pr_s ++; */

/*     /\* // post *\/ */
/*     /\* int po_m = x + s; *\/ */
/*     /\* int po_s = start; *\/ */
/*     /\* int po_e = post_s; *\/ */
/*     /\* while (po_s < po_e) *\/ */
/*     /\* { *\/ */
/*     /\*     int xm = po_e - (po_e - po_s) / 2; *\/ */
/*     /\*     if (arr[xm] > po_m) *\/ */
/*     /\*         po_e = xm - 1; *\/ */
/*     /\*     else *\/ */
/*     /\*         po_s = xm; *\/ */
/*     /\* } *\/ */
/*     /\* post_s = po_s; *\/ */
/*     /\* pre_s = pr_s; *\/ */

/*     memcpy(r, &arr[pr_s], sizeof(int) * k); */
/*     return r; */

/*     /\* stupid wrong algorithm *\/ */
/*     /\* // find middle *\/ */

/*     /\* */
/*     while (s < e) */
/*     { */
/*         int m = s + (e - s) / 2; */
/*         if (arr[m] < x) */
/*             s = m + 1; */
/*         else */
/*             e = m; */
/*     } */

/*     int pre_s = s; */
/*     int post_s = s; */
/*     int num = post_s - pre_s + 1; */

/*     if (x - arr[s - 1] <= arr[s] - x) */
/*     { */
/*         s -= 1; */

/*         if (x - arr[s] == arr[s + 1] - x && k != 1) */
/*         { */
/*             num = 2; */
/*             pre_s = s; */
/*             post_s = s + 1; */
/*         } */
/*         else */
/*         { */
/*             pre_s = s; */
/*             post_s = s; */
/*         } */
/*     } */
/*     printf("pre_s %d %d.\n", pre_s, arr[pre_s]); */

/*     while (num < k) */
/*     { */
/*         int n = (k - num) / 2; */
/*         int post_n = post_s + n; */
/*         int pre_n = pre_s - (k - num - n); */

/*         printf("try %d %d.\n", pre_n, post_n); */

/*         if (post_n >= arrSize) */
/*         { */
/*             post_n = arrSize - 1; */
/*             pre_n = arrSize - k; */
/*         } */

/*         if (pre_n < 0) */
/*         { */
/*             pre_n = 0; */
/*             post_n = k - 1; */
/*         } */

/*         if (x - arr[pre_n] == arr[post_n] - x) */
/*         { */
/*             pre_s = pre_n; */
/*             break; */
/*         } */
/*         else */
/*         { */
/*             if (x - arr[pre_n] < arr[post_n] - x) */
/*             { */
/*                 if (pre_n == 0) */
/*                 { */
/*                     pre_s = 0; */
/*                     break; */
/*                 } */

/*                 int nx = x + x - arr[pre_n]; */
/*                 s = post_s; */
/*                 e = post_n; */

/*                 while (s < e) */
/*                 { */
/*                     int m = s + (e - s) / 2; */
/*                     if (arr[m] <= nx) */
/*                         s = m + 1; */
/*                     else */
/*                         e = m; */
/*                 } */

/*                 pre_s = pre_n; */

/*                 if (s == post_n && x - arr[pre_n - 1] > arr[post_n] - x) */
/*                     break; */

/*                 post_s = s - 1; */
/*             } */
/*             else */
/*             { */
/*                 if (post_n == arrSize - 1) */
/*                 { */
/*                     pre_s = arrSize - k; */
/*                     break; */
/*                 } */

/*                 int nx = x - (arr[post_n] - x); */
/*                 s = pre_n; */
/*                 e = pre_s; */

/*                 while (s < e) */
/*                 { */
/*                     int m = s + (e - s) / 2; */
/*                     if (arr[m] < nx) */
/*                         s = m + 1; */
/*                     else */
/*                         e = m; */
/*                 } */

/*                 pre_s = s; */
/*                 post_s = post_n; */
/*                 printf("got %d %d %d %d\n", pre_n, pre_s, post_s, nx); */
/*             } */
/*         } */
/*         num = post_s - pre_s + 1; */
/*     } */
/*     printf("pre_s %d %d.\n", pre_s, arr[pre_s]); */

/*     if (x - arr[pre_s] == arr[pre_s + k - 1] - x) */
/*     { */
/*         int nx = arr[pre_s]; */
/*         s = 0; */
/*         e = pre_s; */
/*         while (s < e) */
/*         { */
/*             int m = s + (e - s) / 2; */
/*             if (arr[m] < nx) */
/*                 s = m + 1; */
/*             else */
/*                 e = m; */
/*         } */
/*         int d_s = pre_s - s; */

/*         nx = arr[pre_s + k - 1]; */
/*         s = pre_s; */
/*         e = pre_s + k - 1; */

/*         while (s < e) */
/*         { */
/*             int m = s + (e - s) / 2; */
/*             if (arr[m] <= nx) */
/*                 s = m + 1; */
/*             else */
/*                 e = m; */
/*         } */

/*         int d_e = pre_s + k - s; */
/*         pre_s -= d_s < d_e ? d_s : d_e; */
/*     } */

/*     memcpy(r, &arr[pre_s], sizeof(int) * k); */
/*     return r; */
/*     *\/ */
/* } */
