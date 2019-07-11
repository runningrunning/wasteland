int heightChecker(int* heights, int heightsSize)
{
    int a[101] = {0};
    for (int i = 0; i < heightsSize; i ++)
        a[heights[i]] ++;

    int ai = 0;
    int num = 0;

    for (int i = 0; i < heightsSize; i ++)
    {
        while (!a[ai])
            ai ++;
        a[ai] --;
        if (heights[i] != ai)
            num ++;
    }
    return num;
}
