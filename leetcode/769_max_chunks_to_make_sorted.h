int maxChunksToSorted(int* arr, int arrSize)
{
    if (!arr)
        return 0;

    if (arrSize < 2)
        return arrSize;

    int chunks  = 0;
    int right = -1;
    int left =  -1;
    for (int i = 0; i < arrSize; i ++)
    {
        if (arr[i] != i)
        {
            if (right == -1)
            {
                right = i;
                left = arr[i];
            }
            else
            {
                if (arr[i] > left)
                    left = arr[i];

                if (i == left)
                {
                    chunks ++;
                    right = -1;
                    left = -1;
                }
            }
        }
        else
        {
            if (right == -1 && left == -1)
                chunks ++;
        }
    }
    return chunks;

}
