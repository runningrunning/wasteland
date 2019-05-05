// TODO BETTER SOLUTION !!!!!!!!!!!
// too much times
// take care of input and output parameters !!
// stupid corner cases !!!, input the empty array !!!
// input amount is 0 !!!

// TODO: better solution ????????????????????????????
// YES ! there is better solution !!!, not this one !! :(
// wrong DP solution !!

int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int _change(int num, int* coins, int ci, int size, int* mem)
{
    if (!num)
        return 1;
    int onum = num;

    int index = (num - 1) * size + ci;
    if (mem[index])
        return mem[index] - 1;

    if (!ci)
    {
        mem[index] = 1;
        if (num % coins[ci])
            return 0;
        mem[index] ++;
        return 1;
    }

    int all = _change(num, coins, ci - 1, size, mem);
    while (num >= coins[ci])
    {
        num -= coins[ci];

        if (num)
            all += _change(num, coins, ci - 1, size, mem);
        else
            all ++;
    }
    mem[index] = all + 1;

    return all;
}

int change(int amount, int* coins, int coinsSize)
{
    if (!coins || !coinsSize)
        return amount == 0 ? 1 : 0;
        if (!amount)
        return 1;


    // qsort (coins, coinsSize, sizeof(int), comp);
    // int* mem = calloc(sizeof(int), coinsSize * amount);

    int* num = calloc(sizeof(int), amount);
    int* num2 = calloc(sizeof(int), amount);

    int* a = num;
    int* b = num2;

    for (int i = 0; i < coinsSize; i ++)
    {
        int x = coins[i];
        while (x <= amount)
        {
            b[x - 1] += 1;
            if (i)
            {
                for (int j = 0; j < amount - x; j ++)
                    b[j + x] += a[j];
            }
            x += coins[i];
        }
        memcpy(a, b, sizeof(int) * amount);
    }
    return b[amount - 1];
    // return _change(amount, coins, coinsSize - 1, coinsSize, mem);
}

// slow again !!!!
/* // too much times */
/* // take care of input and output parameters !! */
/* // stupid corner cases !!!, input the empty array !!! */
/* // input amount is 0 !!! */

/* // TODO: better solution ???????????????????????????? */
/* // YES ! there is better solution !!!, not this one !! :( */
/* // wrong DP solution !! */

/* int comp (const void * elem1, const void * elem2) */
/* { */
/*     int f = *((int*)elem1); */
/*     int s = *((int*)elem2); */
/*     if (f > s) return  1; */
/*     if (f < s) return -1; */
/*     return 0; */
/* } */

/* int _change(int num, int* coins, int ci, int size, int* mem) */
/* { */
/*     if (!num) */
/*         return 1; */
/*     int onum = num; */

/*     int index = (num - 1) * size + ci; */
/*     if (mem[index]) */
/*         return mem[index] - 1; */

/*     if (!ci) */
/*     { */
/*         mem[index] = 1; */
/*         if (num % coins[ci]) */
/*             return 0; */
/*         mem[index] ++; */
/*         return 1; */
/*     } */

/*     int all = _change(num, coins, ci - 1, size, mem); */
/*     while (num >= coins[ci]) */
/*     { */
/*         num -= coins[ci]; */

/*         if (num) */
/*             all += _change(num, coins, ci - 1, size, mem); */
/*         else */
/*             all ++; */
/*     } */
/*     mem[index] = all + 1; */

/*     return all; */
/* } */

/* int change(int amount, int* coins, int coinsSize) */
/* { */
/*     if (!coins || !coinsSize) */
/*         return amount == 0 ? 1 : 0; */

/*     if (!amount) */
/*         return 1; */

/*     // qsort (coins, coinsSize, sizeof(int), comp); */
/*     // int* mem = calloc(sizeof(int), coinsSize * amount); */

/*     int* num = calloc(sizeof(int), amount); */
/*     int* num2 = malloc(sizeof(int) * amount); */

/*     int* a = num; */
/*     int* b = num2; */

/*     for (int i = 0; i < coinsSize; i ++) */
/*     { */
/*         int x = coins[i]; */
/*         for (int j = 0; j < amount; j ++) */
/*         { */
/*             int y = 0; */
/*             int z = j - x; */

/*             while (z >= 0) */
/*             { */
/*                 y += a[z]; */
/*                 z -= x; */
/*             } */

/*             if (!((j + 1) % x)) */
/*                 y ++; */
/*             b[j] = y + a[j]; */
/*         } */

/*         int* t = b; */
/*         b = a; */
/*         a = t; */
/*     } */

/*     return a[amount - 1]; */
/*     // return _change(amount, coins, coinsSize - 1, coinsSize, mem); */
/* } */
