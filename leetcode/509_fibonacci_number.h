// how to calculate the fib number
// it have lots of optimization ways
// with matrix multiply etc ~!!!
// try tail recursion here.

/* int _fib(int n, int* t) */
/* { */
/*     if (!t[n]) */
/*         t[n] = _fib(n - 1, t) + _fib(n - 2, t) + 1; */
/*     return t[n] - 1; */
/* } */
/* int fib(int N) */
/* { */
/*     int* t = calloc(sizeof(int), (N + 1)); */
/*     t[0] = 1; */
/*     t[1] = 2; */
/*     return _fib(N, t); */
/* } */

int _fib(int n, int c, int p1, int p2)
{
    int x = p1 + p2;
    if (c == x)
        return x;
    return _fib(n, c + 1, p2, x);
}

int fib(int N)
{
    if (N <= 1)
        return N;
    return _fib(N, 2, 0, 1);
}
