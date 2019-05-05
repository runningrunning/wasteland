// corner case it's ==
// code optimize
int minDeletionSize(char** A, int ASize)
{
    if (!A || !ASize || !strlen(A[0]))
        return 0;

    int dn = 0;
    int ls = strlen(A[0]);

    // compare with which index
    // int cs[101] = {0};
    char ds[101] = {0};

    while (true)
    {
        bool new = false;
        for (int i = 1; i < ASize; i ++)
        {
            char* a = A[i - 1];
            char* b = A[i];

            for (int j = 0; j < ls; j ++)
            {
                if (ds[j] || a[j] == b[j])
                    continue;

                if (a[j] < b[j])
                    break;

                dn ++;
                ds[j] = 1;
                new = true;
            }
        }

        if (!new || dn == ls)
            break;
    }
    return dn;
}
