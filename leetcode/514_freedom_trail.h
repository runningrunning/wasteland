// simple DP, but how to represent them
// it's just simple, but how to prove it's correct !!!
// how to prove it's correct and how to make sure that the previous status has nothing to do
// the later status ?


// just every point to every point minimal
// when it stop at some points, it should have the minimum value
// how to represent the DP is the most important thing
int findRotateSteps(char* ring, char* key)
{
    int* cs[26] = {0};

    int i = 0;
    int c = ring[i ++];


    while (c)
    {
        c -= 'a';

        if (cs[c])
        {
            int n = cs[c][0] + 1;
            cs[c] = realloc(cs[c], sizeof(int) * (n + 1));
            cs[c][n] = i;
            cs[c][0] += 1;
        }
        else
        {
            cs[c] = malloc(sizeof(int) * 2);
            cs[c][0] = 1;
            cs[c][1] = i;
        }

        c = ring[i ++];
    }

    int l = i - 1;

    int si = 0;
    int* stacks = malloc(sizeof(int) * i);
    int bsi = 0;
    int* bstacks = malloc(sizeof(int) * i);
    stacks[si ++] = 1 << 16;


    i = 0;
    int a = key[i ++];

    while (a)
    {
        a -= 'a';
        int* ra = cs[a] + 1;

        for (int j = 0; j < cs[a][0]; j ++)
        {
            int cj = ra[j];
            int min = INT_MAX;

            for (int k = 0; k < si; k ++)
            {
                int num = stacks[k] & 0xFFFF;
                int ck = stacks[k] >> 16;
                int d = 0;

                if (cj >= ck)
                {
                    d = (cj - ck) > (l + ck - cj) ? (l + ck - cj) : (cj - ck);
                    d += 1;
                }
                else
                {
                    d = (ck - cj) > (l + cj - ck) ? (l + cj - ck) : (ck - cj);
                    d += 1;
                }

                if (min > num + d)
                   min = num + d;
            }
            bstacks[j] = cj << 16 | min;
        }

        si = cs[a][0];
        int* t = stacks;

        stacks = bstacks;
        bstacks = t;

        a = key[i ++];
    }

    int min = INT_MAX;
    for (i = 0; i < si; i ++)
        if (min > (stacks[i] & 0xFFFF))
            min = (stacks[i]) & 0xFFFF;
    return min;
}
