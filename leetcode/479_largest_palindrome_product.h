int largestPalindrome(int n)
{
    if (n == 1)
        return 9;

    int x = 1;

    while (n --)
        x *= 10;
    x -= 1;

    int s = x;

    while (x)
    {
        int y = x;
        long tx = x;
        int last = 0;

        while (y)
        {
            last = y;
            tx *= 10;
            tx += y % 10;
            y /= 10;
        }

        for (int z = s; z > x;)
        {
            if (!(tx % z))
                return tx % 1337;
            if (tx / z > z)
                break;
            // if it's start from 9
            z -= (last & 1) ? 2 : 1;
        }
        x --;
    }
    return 0;
}

/*
int largestPalindrome(int n)
{
    if (n == 1)
        return 9; // 9 = 9 * 1

    int x = 1;
    while (n --)
        x *= 10;
    x -= 1;

    int s = x;

    while (x)
    {
        for (int z = s; z > x;)
        {
            int t = x;
            int y = x;
            int r = 0;

            while (y)
            {
                t *= 10;
                t += y % 10;
                y /= 10;
                r = r * 10 + t / z;
                t = t % z;
            }

            if (!t)
            {
                t = x;
                y = x;

                while (y)
                {
                    t *= 10;
                    t += y % 10;
                    y /= 10;
                    t = t % 1337;
                }
                return t;
            }

            if (r >= z)
                break;

            // can never be even, must odd
            z -= 2;
        }
        x --;
    }
    return 0;
}
*/
