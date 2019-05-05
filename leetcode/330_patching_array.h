// MOST GENIUS !
// STUPID ME !!!!!!!!
// GREEDY, start from the LAST
// why greedy ?????
// from the last, fine the missing ones
// as we only add one number per each new integer needed to be represented
// so it's more wise to divide the already added into 2 integer's
// but how to prove it works ?
// SIMPLE GREEDY ?
//
// 757. set intersection size at least two
// STUPID WRONG ALGORITHM, how to solve as greedy?
// greedy ?????
// how to do it ?
//
//
//
// 1, 2, 2
// is that simple ????
// peek hint !!
// greedy ?
// hash ??????
int minPatches(int* nums, int numsSize, int n)
{
    long m = 1;
    long a = 0;
    long s = 0;
    long ni = 0;

    /* while (m <= n) */
    /* { */
    /*     if (ni < numsSize && (s + 1) >= nums[ni]) */
    /*         s += nums[ni ++]; */

    /*     if (s < m) */
    /*     { */
    /*         s += s + 1; */
    /*         a ++; */
    /*     } */
    /*     m = s; */
    /*     m ++; */
    /* } */

    while (m <= n)
    {
        if (ni < numsSize && m >= nums[ni])
            m += nums[ni ++];
        else
        {
            m += m;
            a ++;
        }
    }
    return a;
}

/* int minPatches(int* nums, int numsSize, int need) */
/* { */
/*     int ri = 0; */
/*     int* r = NULL; */

/*     if (!nums || !numsSize) */
/*     { */
/*         if (!need) */
/*             return 0; */

/*         r = malloc(sizeof(int) * need); */
/*         ri = need; */
/*         for (int i = 0; i < need; i ++) */
/*             r[i - 1] = i + 1; */
/*     } */
/*     else */
/*     { */
/*         int x = nums[0]; */
/*         int low, high; */

/*         if (x == 1) */
/*         { */
/*             low = 1; */
/*             high = 1; */
/*         } */
/*         else */
/*         { */
/*             r = malloc(sizeof(int) * (x - 1)); */
/*             ri = x - 1; */

/*             for (int i = 0; i < x - 1; i ++) */
/*                 r[i] = i + 1; */

/*             low = 1; */
/*             high = x; */
/*         } */

/*         int cur = high + 1; */

/*         for (int i = 1; i <= numsSize; i ++) */
/*         { */
/*             if (i == numsSize) */
/*             { */
/*                 printf("cur %d high %d.\n", cur, high); */
/*                 x = 0; */
/*                 cur = need; */
/*             } */
/*             else */
/*                 x = nums[i]; */

/*             if (high + x < cur) */
/*             { */
/*                 int y = cur - high - x; */

/*                 r = realloc(r, sizeof(int) * (ri + 1)); */
/*                 r[ri ++] = y; */

/*                 for (int j = high + 1; j < low + y; j ++) */
/*                 { */
/*                     r = realloc(r, sizeof(int) * (ri + 1)); */
/*                     r[ri ++] = j - low; */
/*                 } */
/*             } */
/*             else if (x > cur) */
/*             { */
/*                 for (int j = x - 1; j > high; j --) */
/*                 { */
/*                     r = realloc(r, sizeof(int) * (ri + 1)); */
/*                     r[ri ++] = j - high; */
/*                 } */
/*             } */

/*             cur = high + x; */
/*             high = cur; */

/*             if (cur >= need) */
/*                 break; */

/*             cur ++; */
/*         } */
/*     } */
/*     out(r, ri); */
/* } */
