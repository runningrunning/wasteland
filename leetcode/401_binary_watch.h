/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int num, int* returnSize)
{
    char bits[64] = {
        0, 1, 1, 2, 1, 2, 2, 3,
        1, 2, 2, 3, 2, 3, 3, 4,
        1, 2, 2, 3, 2, 3, 3, 4,
        2, 3, 3, 4, 3, 4, 4, 5,
        1, 2, 2, 3, 2, 3, 3, 4,
        2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5,
        3, 4, 4, 5, 4, 5, 5, 6
    };

    char** result = malloc(sizeof(char**) * 256);

    int r = 0;
    int hour = num > 4 ? 4 : num;
    char* time;

    for (int i = 0; i <= hour; i ++)
    {
        for (int h = 0; h < 12; h ++)
        {
            if (bits[h] != i)
                continue;
            int m = num - i;

            if (!m)
            {
                int n = 0;
                time = malloc(6);
                if (h >= 10)
                    time[n ++] = '1';
                time[n ++] = (h % 10) + '0';
                time[n ++] = ':';
                time[n ++] = '0';
                time[n ++] = '0';
                time[n ++] = 0;
                result[r ++] = time;
            }
            else
            {
                for (int min = 1; min < 60; min ++)
                {
                    if (bits[min] == m)
                    {
                        int n = 0;
                        time = malloc(6);
                        if (h >= 10)
                            time[n ++] = '1';
                        time[n ++] = (h % 10) + '0';
                        time[n ++] = ':';
                        time[n ++] = (min / 10) + '0';
                        time[n ++] = (min % 10) + '0';
                        time[n ++] = 0;
                        result[r ++] = time;
                    }
                }
            }
        }
    }

    *returnSize = r;
    return result;
}
