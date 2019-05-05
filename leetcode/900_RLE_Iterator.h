/* class RLEIterator */
/* { */
/*     int ci; */
/*     int cn; */
/*     int as; */
/*     vector<int> a; */

/*  public: */

/*     RLEIterator(vector<int> A) { */
/*         ci = -1; */
/*         cn = 0; */
/*         a = A; */
/*         as = A.size(); */
/*     } */

/*     int next(int n) { */
/*         if (!as) */
/*             return -1; */

/*         if (ci == -1) */
/*         { */
/*             if (cn == -1) */
/*                 return -1; */
/*             ci = 0; */
/*         } */

/*         while (ci < as && n + cn > a[ci]) */
/*         { */
/*             n -= a[ci] - cn; */
/*             ci += 2; */
/*         } */

/*         cn += n; */

/*         if (ci >= as) */
/*         { */
/*             ci = cn = -1; */
/*             return -1; */
/*         } */

/*         return a[ci + 1]; */
/*     } */
/* }; */

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */


/* typedef struct { */
/* } RLEIterator; */

/* RLEIterator* rLEIteratorCreate(int* A) { */
/* } */

/* int rLEIteratorNext(RLEIterator* obj, int n) { */
/* } */

/* void rLEIteratorFree(RLEIterator* obj) { */
/* } */

/* /\** */
/*  * Your RLEIterator struct will be instantiated and called as such: */
/*  * struct RLEIterator* obj = rLEIteratorCreate(A); */
/*  * int param_1 = rLEIteratorNext(obj, n); */
/*  * rLEIteratorFree(obj); */
/*  *\/ */
