

bool find(int cur, const int* nums, const int** ai, const char* w, int br, char* used)
{
    if (!w[0])
        return true;

    char c = w[0];

    int x = cur >> 16;
    int y = cur & 0xFF;

    for(int i = 0; i < nums[c]; i ++)
    {
        int ni = ai[c][i];
        int nx = ni >> 16;
        int ny = ni & 0xFF;
        int used_i = nx * br + ny;

        if (x - nx > 1)
            continue;

        if (nx - x > 1)
            return false;

        if (!used[used_i] && (abs(nx - x) + abs(ny - y)) == 1)
        {
            used[used_i] = 1;
            if (find(ni, nums, ai, w + 1, br, used))
                return true;
            used[used_i] = 0;
        }
    }
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if (!strlen(word))
        return false;

    int nums[256] = {0};
    int needed[256] = {0};
    int br = boardColSize;
    int all = boardRowSize * boardColSize;
    char* a = malloc(sizeof(char) * all);
    memset(a, 0, sizeof(char) * all);

    int** ai = malloc(sizeof(int*) * 256);

    for(int i = 0; i < boardRowSize; i ++)
        for(int j = 0; j < boardColSize; j ++)
        {
            int c = board[i][j];
            int ii = (i << 16) |  j;

            if (!nums[c])
                ai[c] = malloc(sizeof(int) * all);
            ai[c][nums[c]] = ii;

            nums[c] ++;
        }

    int l = strlen(word);

    for(int i = 0; i < l; i ++)
    {
        int c = word[i];
        needed[c] ++;
        if (needed[c] > nums[c])
            return false;
    }

    char c = word[0];
    for(int i = 0; i < nums[c]; i ++)
    {
        int ni = ai[c][i];
        int x = ni >> 16;
        int y = ni & 0xFF;
        int used = x * br + y;
        a[used] = 1;
        if (find(ni, nums, ai, word + 1, br, a))
            return true;
        a[used] = 0;
    }
    return false;
}
