// TODO, it's very fun to represent the target string
// very smart way to represent DP
// try to solve it in exclusive search way and also the DP.
// DP way, bitmap way
// smart way to represent the original target here
// just be careful~ !!!!
// careful !!

// DP or exclusive search
// not that easy !
// big bitmap DP  !!!

// backpack problems ?
// dp + backtracing
// how to memorize the dp
// to n dimension, at most is 15 bits which is 32768 2 ^ 15
// then it's easy !
// don't understand
// no need, just have the number of sticker can represent the biggest one


// DP way, bitmap way
// smart way to represent the original target here
int minStickers(char** stickers, int stickersSize, char* target)
{
    if (!target || !target[0])
        return 0;

    int tl = strlen(target);
    int l = 1 << tl;
    int* dp = calloc(sizeof(int), l);

    int f = 0;
    int m = l - 1;

    int i = 0;
    char c = target[i ++];

    while (c)
    {
        f |= 1 << (c - 'a');
        c = target[i ++];
    }

    char n[26];
    int max = 0;

    int af = 0;

    for (int j = 0; j < stickersSize; j ++)
    {
        int i = 0;
        char* s = stickers[j];
        c = s[i ++];
        while (c)
        {
            af |= 1 << (c - 'a');
            c = s[i ++];
        }
    }

    // & is low than !=, must use ()
    if ((af & f) != f)
        return -1;

    for (int j = 0; j < stickersSize; j ++)
    {
        int i = 0;
        int tf = 0;
        char* s = stickers[j];
        memset(n, 0, sizeof(n));

        c = s[i ++];
        while (c)
        {
            n[c - 'a'] ++;
            tf |= 1 << (c - 'a');
            c = s[i ++];
        }

        if (!(tf & f))
            continue;

        for (int k = 0; k <= max; k ++)
        {
            if (!dp[k] && k)
                continue;

            int next = k;
            int sm = (~k) & m;

            char now[26] = {0};

            for (int i = 0; i < tl; i++)
            {
                if (!(sm & (1 << i)))
                    continue;

                int ni = target[i] - 'a';

                if (n[ni] - now[ni])
                {
                    now[ni] ++;
                    next |= 1 << i;
                }
            }

            if (dp[next] > dp[k] + 1 || !dp[next])
                dp[next] = dp[k] + 1;

            if (next > max)
                max = next;
        }
    }

    return dp[m] ? dp[m] : -1;
}
