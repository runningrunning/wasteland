/* what's lexicographical order if 10, 100, 1000, 10000, 100000 */
/*
  1
  10
  100
  101
  102
  103
  11
  110
  111
  112
  12
  2
  20
  200
  2000
  200000
  20001
  3
  4
  5
  6
  7
  8
  9
*/

/* int next(int c, int n) */
/* { */
/*     int t = n / 10; */

/*     if (c <= t) */
/*         c *= 10; */
/*     else */
/*     { */
/*         if (c == n) */
/*             c /= 10; */

/*         while (c % 10 == 9) */
/*             c /= 10; */

/*         c ++; */
/*     } */

/*     return c; */
/* } */

class Solution {
 public:
    vector<int> lexicalOrder(int n) {
        vector<int> x;
        x.reserve(n);
        int c = 1;
        int t = n / 10;
        for (int i = 0; i < n; i ++)
        {
            x.push_back(c);

            if (c <= t)
                c *= 10;
            else
            {
                if (c == n)
                    c /= 10;

                c ++;

                while (!(c % 10))
                    c /= 10;
                /* while (c % 10 == 9) */
                /*     c /= 10; */

                /* c ++; */
            }
        }
        return x;
    }
};
