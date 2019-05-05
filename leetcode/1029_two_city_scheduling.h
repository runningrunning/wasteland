// STUPID WRONG ALGORITHM !!!!!!!!!!!!!!!!
// MOST GENERIOUS SOLUTION !!!!!!!!!!!!!!!

class Solution {
    void my_nth(vector<vector<int>>& c, int s, int e, int n)
    {
        if (s >= e)
            return;
        int t;
        if (c[s][0] - c[s][1] > c[e][0] - c[e][1])
        {
            t = c[s][0];
            c[s][0] = c[e][0];
            c[e][0] = t;

            t = c[s][1];
            c[s][1] = c[e][1];
            c[e][1] = t;
        }

        if (s + 1 == e)
            return;

        int os = s;
        int oe = e;

        for (int i = s + 1; i <= e; i ++)
        {
            while (c[i][0] - c[i][1] < c[s][0] - c[s][1]) i ++;
            while (c[e][0] - c[e][1] > c[s][0] - c[s][1]) e --;

            if (i >= e)
            {
                t = c[s][0];
                c[s][0] = c[e][0];
                c[e][0] = t;

                t = c[s][1];
                c[s][1] = c[e][1];
                c[e][1] = t;
            }
            else
            {
                t = c[i][0];
                c[i][0] = c[e][0];
                c[e][0] = t;

                t = c[i][1];
                c[i][1] = c[e][1];
                c[e][1] = t;
            }
        }

        if (n < e)
            my_nth(c, os, e - 1, n);
        else if (n > e)
            my_nth(c, e + 1, oe, n);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int l = costs.size();
        my_nth(costs, 0, l - 1, l / 2);

        int need = 0;
        for (int i = 0; i < l / 2; i ++)
            need += costs[i][0] + costs[l - 1 - i][1];
        return need;
    }
};

/* // find better solution !!!!!
   /* class Solution { */
/* int _comp(int* e1, int* e2) */
/* { */
/*                  int max1, min1; */
/*                  int max2, min2; */

/*                  if (e1[0] > e1[1]) */
/*                  { */
/*                      max1 = e1[0]; */
/*                      min1 = e1[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max1 = e1[1]; */
/*                      min1 = e1[0]; */
/*                  } */

/*                  if (e2[0] > e2[1]) */
/*                  { */
/*                      max2 = e2[0]; */
/*                      min2 = e2[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max2 = e2[1]; */
/*                      min2 = e2[0]; */
/*                  } */

/*                  if (max1 == max2) */
/*                      return min1 - min2; */
/*                  return max1 - max2; */
/* } */

/* void _tcs(int** c, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int* t; */

/*     if (_comp(c[s], c[e]) > 0) */
/*     { */
/*         t = c[s]; */
/*         c[s] = c[e]; */
/*         c[e] = t; */
/*     } */

/*     int os = s; */
/*     int oe = e; */

/*     for (int i = 1; i <= e; i ++) */
/*     { */
/*         while (_comp(c[i], c[s]) < 0) */
/*             i ++; */
/*         while (_comp(c[e], c[s]) > 0) */
/*             e --; */

/*         if (i >= e) */
/*         { */
/*             t = c[s]; */
/*             c[s] = c[e]; */
/*             c[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = c[i]; */
/*             c[i] = c[e]; */
/*             c[e] = t; */
/*         } */
/*     } */

/*     _tcs(c, os, e - 1); */
/*     _tcs(c, e + 1, oe); */
/* } */
/* public: */
/*     int twoCitySchedCost(vector<vector<int>>& A) { */
/*         int res = 0, n = costs.size(); */
/*         int** costs = (int**) malloc(sizeof(int*) * n); */

/*         for (int i = 0; i < n; i ++) */
/*         { */
/*             costs[i] = (int*) malloc(sizeof(int) * 2); */
/*             costs[i][0] = A[i][0]; */
/*             costs[i][1] = A[i][1]; */
/*         } */
/*         int costsRowSize = n; */

/*         int all = 0; */
/*         int removed = 0; */

/*         int rn = costsRowSize / 2; */
/*         int ra = 0; */
/*         int rb = 0; */
/*         int re = 0; */

/*         for (int i = costsRowSize - 1; i >= 0; i --) */
/*         { */
/*             all += costs[i][0] + costs[i][1]; */
/*             if (costs[i][0] != costs[i][1]) */
/*             { */
/*                 if (costs[i][0] > costs[i][1]) */
/*                 { */
/*                     if (ra < rn) */
/*                     { */
/*                         removed += costs[i][0]; */
/*                         ra ++; */
/*                     } */
/*                     else */
/*                     { */
/*                         removed += costs[i][1]; */
/*                         rb ++; */
/*                     } */
/*                 } */
/*                 else */
/*                 { */
/*                     if (rb < rn) */
/*                     { */
/*                         removed += costs[i][1]; */
/*                         rb ++; */
/*                     } */
/*                     else */
/*                     { */
/*                         removed += costs[i][0]; */
/*                         ra ++; */
/*                     } */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 removed += costs[i][0]; */
/*                 re ++; */
/*             } */
/*         } */

/*         return all - removed; */
/*     } */
/* }; */


/* // find better solution !!!!! */

/* /\*class Solution { */
/* public: */
/*     int twoCitySchedCost(vector<vector<int>>& costs) { */
/*         int res = 0, n = A.size(); */
/*         sort(A.begin(), A.end(), */
/*              [](const vector<int>& e1, const vector<int>& e2){ */
/*                  int max1, min1; */
/*                  int max2, min2; */

/*                  if (e1[0] > e1[1]) */
/*                  { */
/*                      max1 = e1[0]; */
/*                      min1 = e1[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max1 = e1[1]; */
/*                      min1 = e1[0]; */
/*                  } */

/*                  if (e2[0] > e2[1]) */
/*                  { */
/*                      max2 = e2[0]; */
/*                      min2 = e2[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max2 = e2[1]; */
/*                      min2 = e1[0]; */
/*                  } */

/*                  if (max1 == max2) */
/*                      return min1 - min2; */
/*                  return max1 - max2; */
/*             }); */

/*         int costsRowSize = n; */

/*         int all = 0; */
/*         int removed = 0; */

/*         int rn = costsRowSize / 2; */
/*         int ra = 0; */
/*         int rb = 0; */
/*         int re = 0; */

/*         for (int i = costsRowSize - 1; i >= 0; i --) */
/*         { */
/*             all += costs[i][0] + costs[i][1]; */
/*             if (costs[i][0] != costs[i][1]) */
/*             { */
/*                 if (costs[i][0] > costs[i][1]) */
/*                 { */
/*                     if (ra < rn) */
/*                     { */
/*                         removed += costs[i][0]; */
/*                         ra ++; */
/*                     } */
/*                     else */
/*                     { */
/*                         removed += costs[i][1]; */
/*                         rb ++; */
/*                     } */
/*                 } */
/*                 else */
/*                 { */
/*                     if (rb < rn) */
/*                     { */
/*                         removed += costs[i][1]; */
/*                         rb ++; */
/*                     } */
/*                     else */
/*                     { */
/*                         removed += costs[i][0]; */
/*                         ra ++; */
/*                     } */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 removed += costs[i][0]; */
/*                 re ++; */
/*             } */
/*         } */

/*         return all - removed; */
/*     } */
/* }; */
/* *\/ */
/* int _comp(int* e1, int* e2) */
/* { */
/*                  int max1, min1; */
/*                  int max2, min2; */

/*                  if (e1[0] > e1[1]) */
/*                  { */
/*                      max1 = e1[0]; */
/*                      min1 = e1[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max1 = e1[1]; */
/*                      min1 = e1[0]; */
/*                  } */

/*                  if (e2[0] > e2[1]) */
/*                  { */
/*                      max2 = e2[0]; */
/*                      min2 = e2[1]; */
/*                  } */
/*                  else */
/*                  { */
/*                      max2 = e2[1]; */
/*                      min2 = e2[0]; */
/*                  } */

/*                  if (max1 == max2) */
/*                      return min1 - min2; */
/*                  return max1 - max2; */
/* } */

/* void _tcs(int** c, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int* t; */

/*     if (_comp(c[s], c[e]) > 0) */
/*     { */
/*         t = c[s]; */
/*         c[s] = c[e]; */
/*         c[e] = t; */
/*     } */

/*     int os = s; */
/*     int oe = e; */

/*     for (int i = 1; i <= e; i ++) */
/*     { */
/*         while (_comp(c[i], c[s]) < 0) */
/*             i ++; */
/*         while (_comp(c[e], c[s]) > 0) */
/*             e --; */

/*         if (i >= e) */
/*         { */
/*             t = c[s]; */
/*             c[s] = c[e]; */
/*             c[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = c[i]; */
/*             c[i] = c[e]; */
/*             c[e] = t; */
/*         } */
/*     } */

/*     _tcs(c, os, e - 1); */
/*     _tcs(c, e + 1, oe); */
/* } */

/* int twoCitySchedCost(int** costs, int costsRowSize, int costsColSize) */
/* { */
/*     _tcs(costs, 0, costsRowSize - 1); */
/*     int all = 0; */
/*     int removed = 0; */

/*     int rn = costsRowSize / 2; */
/*     int ra = 0; */
/*     int rb = 0; */
/*     int re = 0; */

/*     for (int i = costsRowSize - 1; i >= 0; i --) */
/*     { */
/*         all += costs[i][0] + costs[i][1]; */
/*         if (costs[i][0] != costs[i][1]) */
/*         { */
/*             if (costs[i][0] > costs[i][1]) */
/*             { */
/*                 if (ra < rn) */
/*                 { */
/*                     removed += costs[i][0]; */
/*                     ra ++; */
/*                 } */
/*                 else */
/*                 { */
/*                     removed += costs[i][1]; */
/*                     rb ++; */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 if (rb < rn) */
/*                 { */
/*                     removed += costs[i][1]; */
/*                     rb ++; */
/*                 } */
/*                 else */
/*                 { */
/*                     removed += costs[i][0]; */
/*                     ra ++; */
/*                 } */
/*             } */
/*         } */
/*         else */
/*         { */
/*             removed += costs[i][0]; */
/*             re ++; */
/*         } */
/*     } */

/*     return all - removed; */
/* } */
