// TODO
// STUPID ME ~!!!!!!!!!!!!!!!!!!!!!
// DP again ???
// brutal force ?
// find better way ?
// search tree ?
// how to divide them ???
int countTriplets(int* A, int ASize) {
    int* all = calloc(sizeof(int), 65536);

    int n0 = 0;
    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] == 0)
        {
            n0 ++;
            continue;
        }
        for (int j = 0; j < ASize; j ++)
        {
            all[A[i] & A[j]] ++;
        }
    }

    int num = 0;
    num += n0 * ASize * ASize;

    for (int i = 0; i < ASize; i ++)
    {
        for (int j = 0; j < 65536; j ++)
            if (all[j] && !(A[i] & j))
                num += all[j];
    }

    return num;
}

