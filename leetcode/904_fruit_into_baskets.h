int totalFruit(int* tree, int treeSize)
{
    if (!tree || !treeSize)
        return 0;

    if (treeSize < 3)
        return treeSize;

    int m = 0;
    int t[2] = {tree[0] + 1, 0};
    int n[2] = {1, 0};

    for (int i = 1; i < treeSize; i ++)
    {
        int x = tree[i] + 1;
        if (t[0] == x)
            n[0] ++;
        else if (t[1] == x)
            n[1] ++;
        else
        {
            if (n[0] + n[1] > m)
                m = n[0] + n[1];

            if (n[1])
            {
                t[0] = tree[i - 1] + 1;
                int num = i - 1;
                while (num && tree[num] == (t[0] - 1))
                    num --;
                n[0] = i - 1 - num;
            }

            t[1] = x;
            n[1] = 1;
        }
    }

    if (n[0] + n[1] > m)
        m = n[0] + n[1];
    return m;
}
