char** letterCombinations(char* digits, int* returnSize)
{
    int ds[] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};
    char* da[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char dx[] = {'b', 'c', 'a', 'e', 'f', 'd', 'h', 'i', 'g', 'k', 'l', 'j', 'n', 'o', 'm', 'q', 'r', 's', 'p', 'u', 'v', 't', 'x', 'y', 'z', 'w'};
    int di[] = {  0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   0,   1,   0,   0,   1,   0,   0,   0,   1};

    int l = strlen(digits);

    if (!l)
    {
        *returnSize = 0;
        return 0;
    }
    int len = 0;
    int max = 1;
    char* init = malloc(sizeof(char) * (l + 1));
    init[l] = 0;
    for (int i = 0; i < l; i ++)
    {
        int c = digits[i] - '0';
        max *= ds[c];
        if (c != 1)
        {
            init[len] = da[c][0];
            len ++;
        }
    }
    init[len] = 0;

    int pos = 0;
    char** ret = malloc(sizeof(char*) * max);
    *returnSize = max;
    ret[0] = init;
    char* pre = init;
    for(int i = 1; i < max; i++)
    {
        char* str = strdup(pre);
        int j = 0;
        while(str[j] && (str[j] == ' ' || di[str[j] - 'a']))
        {
            if (str[j] != ' ')
                str[j] = dx[str[j] - 'a'];
            j++;
        }
        if (!str[j])
            return ret;
        str[j] += 1;
        ret[i] = str;
        pre = str;
    }
    return ret;
}
