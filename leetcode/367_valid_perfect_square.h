bool ips(int num, int s, int e)
{
    if (s >= e)
        return num == s * s;

    int m = (s + e) / 2;
    int t = m * m;

    if (num == t)
        return true;

    if (num > t)
        return ips(num, m + 1, e);
    return ips(num, s, m - 1);
}

bool isPerfectSquare(int num)
{
    return ips(num, 1, 46340);
}
