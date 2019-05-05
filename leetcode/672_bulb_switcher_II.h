// stupid algorithm

// ALL ON : all + all even + even odd + odd 3k + 3k is null
// ALL OFF: all
// ODD ON: all + even = odd
// EVEN ON: all + odd = even
// 3k ON: all + 3k = ~ 3k
// 3k OFF + EVEN: 3k + even
// 3k OFF + ODD: 3k + odd
// 3k OFF: 3k

int flipLights(int n, int m)
{
    if (n == 0)
        return 0;

    if (m == 0)
        return 1;

    if (n == 1)
        return 2;
    if (n == 2)
        return m > 1 ? 4 : 3;

    if (m == 1)
        return 4;

    if (m == 2)
        return 7;
    return 8;
}
