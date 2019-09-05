// code optimize

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
    *returnSize = barcodesSize;
    if (barcodesSize < 3)
        return barcodes;

    int* t = calloc(sizeof(int), 10001);
    int max = 0;
    int max_i = 0;

    for (int i = 0; i < barcodesSize; i ++)
        t[barcodes[i]] ++;

    int ti = 0;

    for (int i = 0; i < 10001; i ++)
    {
        if (t[i] > max)
        {
            max = t[i];
            max_i = i;
        }
        t[ti ++] = t[i] << 16 | i;
    }

    int in = 0;

    for (int i = 0; i < max; i ++)
    {
        barcodes[in] = max_i;
        in += 2;
    }

    for (int i = 0; i < ti; i ++)
    {
        int tx = t[i] & 0xFFFF;
        int tn = t[i] >> 16;

        if (tx != max_i)
        {
            while(tn)
            {
                if (in >= barcodesSize)
                    in = 1;
                barcodes[in] = tx;
                in += 2;
                tn --;
            }
        }
    }

    return barcodes;
}

