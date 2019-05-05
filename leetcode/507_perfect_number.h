/* 1 is NOT, as 1 is 1x1 ? */
bool checkPerfectNumber(int num)
{
    if (num < 2)
        return false;

    int all = 1;
    int x = sqrt(num);

    for (int i = 2; i <= x; i ++)
        if (!(num % i))
            all += i + num / i;

    return all == num;
}
