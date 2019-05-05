// STUPID WRONG ALGORITHMS
// TODO DO IT AGAIN !!
// PEEK THE SOLUTION
// CHEATING !!!!!!!!!!!!!!!
// cheating peek the answers !!!!
// different ways to do so

// log n with base number representation
int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    int n = minutesToTest / minutesToDie;
    n += 1;

    int p = 0;

    int x = 1;

    while (x < buckets)
    {
        x *= n;
        p ++;
    }

    return p;
}

/* int sq(int n) */
/* { */
/*     if (n == 1) */
/*         return 0; */

/*     int i = 0; */
/*     int s = 1; */
/*     while (s < n) */
/*     { */
/*         s <<= 1; */
/*         i ++; */
/*     } */

/*     return i; */
/* } */

/* int p_num(int p, int n) */
/* { */
/*     if (n == 1) */
/*         return p; */
/* } */

/* long nums(int turn, int pig) */
/* { */
/*     if (!pig) */
/*         return 0; */

/*     if (turn == 1) */
/*     { */
/*         long num = 1; */
/*         while (pig --) */
/*             num <<= 1; */
/*         return num; */
/*     } */

/*     int cur = INT_MIN; */
/*     int target = nums(1, pig) - 1; */
/*     int max = nums(turn -1, pig - 1); */

/*     for (int i = 1; i < pig; i ++) */
/*     { */
/*         int tmp = nums(turn - 1, pig - i) * i * p_num(pig, i); */
/*         if (tmp > cur) */
/*             cur = tmp; */
/*     } */

/*     return cur + nums(turn - 1, pig); */

/*     // return nums(turn - 1, pig) + pig * (nums(turn - 1, pig - 1) - 1) + nums(1, pig) - 1; */

/*     /\* int all = nums(turn - 1, pig); *\/ */
/*     /\* for (int i = 0; i < pig; i ++) *\/ */
/*     /\* { *\/ */
/*     /\*     all += (pig - i) * (nums(turn - 1, pig - i - 1)); *\/ */
/*     /\* } *\/ */
/*     /\* return all + nums(1, pig); *\/ */
/*     // return nums(turn - 1, pig) + pig * (nums(turn - 1, pig - 1) - 1) + nums(1, pig) - 1; */
/*     // return nums(turn - 1, pig) + pig * (nums(turn - 1, pig - 1) - 1) + nums(1, pig) - 1; */
/* } */
/* int poorPigs(int buckets, int minutesToDie, int minutesToTest) */
/* { */
/*     int turns = minutesToTest / minutesToDie; */
/*     for (int t = 1; t < 6; t ++) */
/*         for (int i = 6; i >= 1; i --) */
/*             printf("t %d i %d num %d.\n", t, i, nums(t, i)); */

/*     /\* long n = 2; *\/ */
/*     /\* int ps = 1; *\/ */
/*     /\* while (buckets > n) *\/ */
/*     /\*     n = nums(turns, ++ ps); *\/ */

/*     /\* return ps; *\/ */
/*     return 0; */
/* } */
