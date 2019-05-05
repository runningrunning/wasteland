// out of mind
// https://en.wikipedia.org/wiki/De_Bruijn_sequence#Example_using_inverse_Burrows%E2%80%94Wheeler_transform
// math Hamiltonian, De Bruijn Sequences
// Thanks for providing the solution.
// Intuitively I agree that reusing last k-1 digits to build next password will eventually get to the result. But how do we prove that? How do you prove that given any n, k, this recursive algorithm to this problem will guarantee visited.size == goal? I will be sad if Google really asks this question without additional intro to a new grad or new junior.
// @kenteng I think it is pretty much self-proved. At every move, you just append one more digit to cover a combination. It is impossible to do less than that to cover a new combination. The only part which is not very clear is that if such method can always generate a solution (In other words, is it possible that all the search in this method would fail).
// know the result then to get the result
// it's math problems !!
// run out of ideas ~!!
// DFS or BFS
// DFS + MATH !!!!

// MATH, know the result to get the answer !!!!
// try to reuse the last n - 1 digits, then get the answer

bool _cs(char* r, int c, int n, int a, int k, int m, char* b)
{
    if (n == a)
        return true;
    for (int i = 0; i < k; i ++)
    {
        int new = (c % m) * 10 + i;
        if (!b[new])
        {
            b[new] = 1;
            r[0] = '0' + i;
            if (_cs(r + 1, new, n + 1, a, k, m, b))
                return true;
            b[new] = 0;
        }
    }
    return false;
}

char* crackSafe(int n, int k)
{
    if (n == 1)
    {
        char* r = malloc(k + 1);
        for (int i = 0; i < k; i ++)
            r[i] = '0' + i;
        r[k] = 0;
        return r;
    }

    int num = 1;
    int mod = 1;
    int s = n;
    while (s --)
    {
        mod *= 10;
        num *= k;
    }

    mod /= 10;

    char* bits = calloc(sizeof(char), 10000);
    char* r = malloc(sizeof(char) * (n + num));

    bits[0] = 1;
    for (int i = 0; i < n; i ++)
        r[i] = '0';
    _cs(r + n, 0, 1, num, k, mod, bits);
    r[n + num] = 0;
    return r;
}

// char* crackSafe(int n, int k)
// {
//     char f[_MAX] = {0};

//     int st = 0;
//     int si = 0;
//     int stack[_MAX];
//     stack[si ++] = st;

//     int msi = 0;
//     bool found = false;
//     // for (int i = 0; i < 10000; i ++)
//     while (si != _MAX)
//     {
//         int p = stack[si - 1];

//         p %= (_MAX / 10);

//         found = false;
//         for (int j = p * 10; j <= p * 10 + 9; j ++)
//         {
//             if (!f[j])
//             {
//                 f[j] = 1;
//                 p = j;
//                 stack[si ++] = j;
//                 found = true;
//                 break;
//             }
//         }

//         /* if (!found) */
//         /*     printf("here is %d %d.\n", si, stack[si - 1]); */

//         while (!found && si)
//         {
//             si --;
//             p = stack[si];
//             f[p] = 0;

//             // printf("p is %d.\n", p);

//             for (int j = p + 1; j <= p / 10 + 9; j ++)
//             {
//                 if (!f[j])
//                 {
//                     f[j] = 1;
//                     p = j;
//                     stack[si ++] = j;
//                     found = true;
//                     break;
//                 }
//             }
//         }

//         // out(stack, si);

//         if (si > msi)
//             msi = si;


//         if (!found)
//         {
//             if (st == _MAX)
//                 break;

//             si = 0;
//             stack[si ++] = ++ st;
//             printf("st is %d %d\n", st, msi);
//         }

//         // printf("%04d - > ", p);
//     }
//     printf("found is %d msi %d.\n", found, msi);
//     out(stack, si);
// }
