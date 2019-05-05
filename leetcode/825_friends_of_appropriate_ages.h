int numFriendRequests(int* ages, int agesSize)
{
    int a[121] = {0};

    for (int i = 0; i < agesSize; i ++)
        a[ages[i]] ++;

    int less = 0;
    int all = 0;
    int l = 15;

    int num = 0;
    for (int i = 15; i <= 120; i ++)
    {
        all += a[i];
        if (l <= (i >> 1) + 7)
            less += a[l ++];
        num += a[i] * (all - less - 1);
    }

    return num;
}
