// the 5400 is learn form do calcuation
// learn a lot
// it's kind of dp, and use memory to store internal values
// TODO rework!!
double ss(int A, int B, int s, double* mem)
{
    if (A && B <= 0)
        return 0;

    if (A <= 0)
        return 1;

    int xa = A / 25;
    int xb = B / 25;
    int ne = xa * s + xb;

    if (mem[ne] != 0.0)
        return mem[ne];

    double r;

    if (A > 75 && A <= 100)
        r = 0.25 * (1 + ss(A - 75, B - 25, s, mem) + ss(A - 50, B - 50, s, mem) + ss(A - 25, B - 75, s, mem));
    else if (A > 50 && A <= 75)
        r = 0.25 * (1 + (B <= 25 ? 0.5 : 1) + ss(A - 50, B - 50, s, mem) + ss(A - 25, B - 75, s, mem));
    else if (A > 25 && A <= 50)
        r =  0.25 * (1 + (B <= 25 ? 0.5 : 1) + (B <= 50 ? 0.5 : 1) + ss(A - 25, B - 75, s, mem));
    else if (A >= 0 && A <= 25)
        r = 0.25 * (1 + (B <= 25 ? 0.5 : 1) + (B <= 50 ? 0.5 : 1) + (B <= 75 ? 0.5 : 1));
    else
        r = 0.25 * (ss(A - 100, B, s, mem) + ss(A - 75, B - 25, s, mem) + ss(A - 50, B - 50, s, mem) + ss(A - 25, B - 75, s, mem));

    mem[ne] = r;

    return r;
}

double soupServings(int N)
{
    if (N >= 5400)
        return 1.0;

    int s = (N + 25) / 25;
    double* mem = malloc(sizeof(double) * s * s);
    for (int i = 0; i < s * s; i ++)
        mem[i] = 0.0;
    return ss(N, N, s, mem);
}
