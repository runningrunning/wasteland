// hash ?
#define PRIME 4099
int lenLongestFibSubseq(int* A, int ASize)
{
    int s[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
               196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155,
               165580141, 267914296, 433494437, 701408733, 1134903170};

    int as = 0;
    int bs = 1;

    short* hash = calloc(sizeof(short), PRIME);

    for (int i = 0; i < ASize; i ++)
    {
        int k = A[i] % PRIME;
        while (hash[k])
            k = (k + 1) % PRIME;
        hash[k] = i + 1;
    }

    int max = 0;
    long last = A[ASize - 1];

    for (int i = 0; i < ASize; i ++)
        for (int j = i + 1; j < ASize; j ++)
        {
            long a = A[i];
            long b = A[j];
            long c = s[max + as] * a + s[max + bs] * b; // find the current maximum

            if (last < c)
                break;

            c = a + b;

            int cmax = 0;
            while (last >= c)
            {
                int k = c % PRIME;

                while (hash[k] && A[hash[k] - 1] != c)
                    k = (k + 1) % PRIME;

                if (!hash[k])
                    break;

                cmax ++;
                a = b;
                b = c;
                c = a + b;
            }

            if (cmax > max)
                max = cmax;
        }

    return max ? max + 2 : 0;
}
