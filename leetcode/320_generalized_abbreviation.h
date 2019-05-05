/* it's easy, just representation of int's binary format, bit 1 means number, bit 0 means character */
/* STUPID FOR C is larger than 10 */
/* should return [""] for this case !! */
// SIMPLE IS FASTER !!!!!!!


/* return how many bits in the last */
int bits(int B)
{
    int bs[256] = {
        0,1,0,2,0,0,0,3,
        0,0,0,0,0,0,0,4,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,5,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,6,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,7,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,8
    };

    int b = 0;
    int n = 0;

    do
    {
        b = B & 0xFF;
        B >>= 8;
        n += bs[b];
    } while(b == 255);

    return n;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateAbbreviations(char* word, int* returnSize)
{
    *returnSize = 0;

    if (!word)
        return NULL;

    int l = strlen(word);
    // should return [""] for this case !!
    // if (!l)
    //     return NULL;
    int n = l;
    int size = 1;
    while (n --)
        size *= 2;

    char num[24] = {0};
    char** ret = malloc(sizeof(char*) * size);

    int ib = 1 << (l - 1);
    for (int i = 0; i < size; i ++)
    {
        ret[i] = malloc(l + 1);
        ret[i][l] = 0;

        int ii = 0;
        int ri = 0;
        int b = ib;
        int c = 0;
        int o = i;
        while (o)
        {
            if (b & o)
                c ++;
            else
            {
                if (c)
                {
                    int ni = 0;

                    while (c)
                    {
                        num[ni ++] = (c % 10) + '0';
                        c /= 10;
                    }

                    while (ni --)
                        ret[i][ii ++] = num[ni];
                }
                ret[i][ii ++] = word[ri];
            }
            ri ++;
            o &= ~b;
            b >>= 1;
        }

        if (c)
        {
            int ni = 0;
            while (c)
            {
                num[ni ++] = (c % 10) + '0';
                c /= 10;
            }

            while (ni --)
                ret[i][ii ++] = num[ni];
        }

        while (word[ri])
            ret[i][ii ++] = word[ri ++];

        ret[i][ii] = 0;
    }
    *returnSize = size;
    return ret;
}

char** generateAbbreviations_2(char* word, int* returnSize)
{
    *returnSize = 0;

    if (!word)
        return NULL;

    int l = strlen(word);
    // should return [""] for this case !!
    // if (!l)
    //     return NULL;
    int n = l;
    int size = 1;
    while (n --)
        size *= 2;

    char num[24] = {0};
    char** ret = malloc(sizeof(char*) * size);

    int ib = 1 << (l - 1);
    for (int i = 0; i < size; i ++)
    {
        ret[i] = malloc(l + 1);
        ret[i][l] = 0;

        int o = i;

        int c = 0;
        int ii = 0;
        int ri = 0;

        while (o)
        {
            int b;
            if (o & 1)
            {
                // how many 1s
                b = ((o + 1) | o) - o  - 1;
                b = bits(b);
                ri += b;
                c = b;

                int ni = 0;
                while (c)
                {
                    num[ni ++] = (c % 10) + '0';
                    c /= 10;
                }

                while (ni --)
                    ret[i][ii ++] = num[ni];
            }
            else
            {
                // how many 0s  0s => 1s
                b = (o - 1) - (o & (o - 1));
                b = bits(b);
                c = b;

                while (c --)
                    ret[i][ii ++] = word[ri ++];
            }
            o >>= b;
        }

        // 0 is character
        while (word[ri])
            ret[i][ii ++] = word[ri ++];
        ret[i][ii] = 0;
    }
    *returnSize = size;
    return ret;
}

//         int ii = 0;
//         int ri = 0;
//         int b = ib;
//         int c = 0;
//         int o = i;
//         while (o)
//         {
//             if (b & o)
//                 c ++;
//             else
//             {
//                 if (c)
//                 {
//                     int ni = 0;

//                     while (c)
//                     {
//                         num[ni ++] = (c % 10) + '0';
//                         c /= 10;
//                     }

//                     while (ni --)
//                         ret[i][ii ++] = num[ni];
//                 }
//                 ret[i][ii ++] = word[ri];
//             }
//             ri ++;
//             o &= ~b;
//             b >>= 1;
//         }

//         if (c)
//         {
//             int ni = 0;
//             while (c)
//             {
//                 num[ni ++] = (c % 10) + '0';
//                 c /= 10;
//             }

//             while (ni --)
//                 ret[i][ii ++] = num[ni];
//         }

//         while (word[ri])
//             ret[i][ii ++] = word[ri ++];

//         ret[i][ii] = 0;
//     }
//     *returnSize = size;
//     return ret;
// }
