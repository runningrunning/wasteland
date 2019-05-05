int reachNumber(int target)
{
    target = target < 0 ? - target : target;

    int x = sqrt(target * 2);
    while (x * x + x < target * 2)
        x ++;

    int last = (x * x + x) / 2;

    if (!((last - target) & 1))
        return x;

    /* int pre = ((x - 1) * (x - 1) + x - 1) / 2; */

    /* if (target - pre == 1 || last - target == 1) */
    /*     return x + 1; */

    return x + 1 + (x & 1);
    /* if (target & 1) */
    /* else */
    /* { */
    /*     return  */
    /* } */
}
