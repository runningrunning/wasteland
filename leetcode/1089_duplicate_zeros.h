// be very careful ~!!!!
void duplicateZeros(int* arr, int arrSize)
{
    int i = 0;
    int e = arrSize;
    for (; i < e; i ++)
    {
        if (arr[i] == 0)
        {
            e --;
            if (i == e)
            {
                i --;
                break;
            }
        }
    }
    if (i < e)
    {
        e = arrSize - 1;
        arr[e --] = 0;
    }
    else
    {
        e = arrSize - 1;
        i --;
    }

    if (i < arrSize)
    {
        for (; i >= 0; i --)
        {
            arr[e --] = arr[i];
            if (arr[i] == 0)
                arr[e --] = 0;
        }
    }
}

