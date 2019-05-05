// same as 340. Longest Substring with At Most K Distinct Characters
int lengthOfLongestSubstringTwoDistinct(char* s) {
    int k = 2;
    int i = 0;
    int c = s[i ++];
    int n[256] = {0};

    int t = 0;
    int st = 0;

    while (c && t <= k)
    {
        if (!n[c])
        {
            if (t == k)
                break;
            t ++;
        }

        n[c] ++;
        c = s[i ++];
    }

    int max = i - 1;

    if (t <= k && !c)
        return max;

    while (c)
    {
        if (!n[c])
        {
            while (true)
            {
                t = s[st ++];
                n[t] --;
                if (!n[t])
                    break;
            }
        }

        n[c] ++;

        if (max < i - st)
            max = i - st;

        c = s[i ++];
    }

    return max;
}
