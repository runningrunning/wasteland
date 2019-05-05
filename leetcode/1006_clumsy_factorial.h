// 8 => 9
// be more careful
// corner case
// + - * / is 0 except the first 5 - 4 * 3 / 2 is -1
int clumsy(int N)
{
    int x[] = {0, 1, 2, 6, 7};
    if (N <= 4)
        return x[N];
    int l = (N - 3) % 4;
    l = l ? l : 4;
    int e[] = {0, 1, 1, 1, -2};
    return N + 1 + e[l] - ((N % 4) ? 0 : 1);
}
