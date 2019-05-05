bool isStrobogrammatic(char* num) {
    if (!num)
        return false;

    // 0 => 1, 1 => 2, 6 => 7, 8 => 9, 9 => 10
    int sg[11] = {0, 1, 2, 0, 0, 0, 0, 10, 0, 9, 7};
    int l = strlen(num);

    if (!l)
        return false;

    for (int i = 0; i < (l + 1) / 2; i ++)
    {
        int c = num[i] - '0' + 1;
        c = sg[c] - 1 + '0';

        if (c != num[l - 1 - i])
            return false;
    }
    return true;
}
