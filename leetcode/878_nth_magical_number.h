// similar question, maybe ?
// almost same with 880 decoded string at index.

#define MOD 1000000007
int gcd(int a, int b)
{
    return (a % b) ? gcd(b, a % b) : b;
}

int nthMagicalNumber(int N, int A, int B)
{
    long m;

    if (A > B)
        m = gcd(A, B);
    else
        m = gcd(B, A);

    m = A * B / m;

    long x = m / A + m / B - 1;

    long r = ((long) N / x * m) % MOD;

    if (N % x)
    {
        x = N % x;

        int min = A > B ? B : A;
        int max = A > B ? A : B;
        int s = 1;
        int e = m / min;

        while (s < e)
        {
            int m = (s + e) / 2;

            if (m + min * m / max < x)
                s = m + 1;
            else
                e = m;
        }

        long t = min * s;
        if (t / max + s > x)
            t = (t / max) * max;

        r += t;
    }
    return r % MOD;
}
