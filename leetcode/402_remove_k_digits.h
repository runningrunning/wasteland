/* NEED TO REWORD with Data Structure */
char* removeKdigits(char* num, int k)
{
    if (!num)
        return NULL;

    if (!k)
        return strdup(num);

    int sl = strlen(num);
    int el = sl - k;

    char* zero = malloc(2);
    zero[0] = '0';
    zero[1] = 0;

    if (el <= 0 || !strcmp(num, "0"))
        return zero;

    int sI = 0;

    char* ret = malloc(el + 1);
    ret[el] = 0;

    char flag[10240] = {0};

    while(k)
    {
        int sE = sI;

        while (num[sI] <= num[sE])
            sE ++;

        int r = sE - sI;

        if (r <= k)
        {
            k -= r;
            sI = sE;

            while(num[sI] == '0')
                sI ++;

            if (!num[sI] || sl - sI <= k)
                return zero;

            if (!k)
                strcpy(ret, num + sI);

        }
        else
        {
            int sE;
            for (int i = 0; i < k; i ++)
            {
                int sT = sI;
                while(flag[sT])
                    sT ++;

                int psT = sT;
                while (flag[sT] || num[sT] >= num[psT])
                {
                    if (!flag[sT])
                        psT = sT;
                    sT ++;
                }
                flag[psT] = 1;
                sE = sT;
            }

            int in = 0;
            for (int i = sI; i < sE; i ++)
            {
                if (!flag[i])
                    ret[in ++] = num[i];
            }
            strcpy(ret + in, num + sE);
            break;
        }

    }

    return ret;
}
