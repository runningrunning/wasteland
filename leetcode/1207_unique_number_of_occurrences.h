bool uniqueOccurrences(int* arr, int arrSize)
{
    int values[2048] = {0};
    int numbers[1024] = {0};

    for (int i = 0; i < arrSize; i ++)
        values[arr[i] + 1024] ++;

    for (int i = 0; i < 2048; i ++)
    {
        int n = values[i];

        if (!n)
            continue;

        if (numbers[n])
            return false;
        numbers[n] = 1;
    }
    return true;
}

