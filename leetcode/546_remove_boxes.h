// TODO BOTTOM UP, 3 DP problems!
// FIND BOTTOM UP SOLUTION !
// MY FAV DP
// GENIUS !!!!!!!!!
// clear mind !!!!!!
// 312 burst balloons and remove boxes and strange printer
// simple is the fastest !!!!!!!!!
//
// why every one chose this represent ?
// Let dp(i, j, k) = the maximum value of removing boxes if we have k extra boxes of color A[i] to the left of A[i: j+1].
// redefine it as T(i, j, k) which denotes the maximum points possible by removing the boxes of subarray boxes[i, j] with k boxes attached to its left of the same color as boxes[i].
//
// I'm stupid !!!!!!!!
// FAV DP !!!!!!!!
// TODO DP !!!!!!!!
// 3 dimensions d[i][j][k], WTF  !!!!!
// not that simple DP, just write code ???
// just to verify my idea, whether it's correct or not !
// BEST idea
//
// same with 664 stranger_printer ??
// stupid wrong algorithms !
// how to find the proper way to divide this problems into small scale and do it again
// same with 664 strange_printer.h
// same with 312 burst balloons ??????
// DP method !!!!
// combined with 312 burst balloons
// just need to reconstruct a little bit about the original question
// 546 remove boxes

// wrong algorithm, it can not break down into small part of the array
/* bool _rb(int*** dp, int i, int c, int k, int n) */
/* { */
/*     if (!i) */
/*     { */
/*     } */
/*     else */
/*     { */
/*         int o = dp[0][] */
/*     } */
/* } */

// top -> down
int _rb(int*** dp, int i, int j, int k, int* b)
{
    if (j < i)
        return 0;

    if (dp[i][j][k])
        return dp[i][j][k];

    if (i == j)
    {
        dp[i][j][k] = (k + 1) * (k + 1);
        return dp[i][j][k];
    }

    int max = (k + 1) * (k + 1) + _rb(dp, i + 1, j, 0, b);

    for (int x = i + 1; x <= j; x ++)
    {
        if (b[x] == b[i])
        {
            int r = _rb(dp, i + 1, x - 1, 0, b) + _rb(dp, x, j, k + 1, b);

            if (r > max)
                max = r;
        }
    }
    dp[i][j][k] = max;
    return dp[i][j][k];
}


int removeBoxes(int* boxes, int boxesSize)
{
    if (!boxes || !boxesSize)
        return 0;

    if (boxesSize == 1)
        return 1;

    int*** dp = malloc(sizeof(int**) * boxesSize);
    for (int i = 0; i < boxesSize; i ++)
    {
        dp[i] = malloc(sizeof(int*) * boxesSize);
        for (int j = 0; j < boxesSize; j ++)
            dp[i][j] = calloc(sizeof(int), boxesSize);
    }

    // top -> down
    _rb(dp, 0, boxesSize - 1, 0, boxes);

    // bottom -> up

    return dp[0][boxesSize - 1][0];
}

/* int removeBoxes(int* boxes, int boxesSize) */
/* { */
/*     if (!boxes || !boxesSize) */
/*         return 0; */

/*     if (boxesSize == 1) */
/*         return 1; */

/*     int primer = 521; */
/*     char* hash = calloc(sizeof(char), primer); */

/*     int id = 0; */
/*     char* ids = malloc(sizeof(char) * boxesSize); */

/*     for (int i = 0; i < boxesSize; i ++) */
/*     { */
/*         int k = boxes[i] % primer; */
/*         while (hash[k] && ids[hash[k] - 1] != boxes[i]) */
/*             k = (k + 1) % primer; */

/*         if (!hash[k]) */
/*         { */
/*             hash[k] = id + 1; */
/*             ids[id ++] = boxes[i]; */
/*         } */

/*         boxes[i] = hash[k]; */
/*     } */

/*     id ++; */

/*     int*** dp = malloc(sizeof(int**) * boxesSize); */
/*     for (int i = 0; i < boxesSize; i ++) */
/*     { */
/*         dp[i] = malloc(sizeof(int*) * boxesSize); */
/*         for (int j = 0; j < boxesSize; j ++) */
/*             dp[i][j] = calloc(sizeof(int), id); */
/*     } */

/*     for (int i = 0; i < boxesSize; i ++) */
/*     { */
/*     } */

/*     return dp[0][boxesSize - 1][0]; */

/*     /\* long* nb = malloc(sizeof(long) * boxesSize); *\/ */
/*     /\* int pre_num = 1; *\/ */
/*     /\* int pre = boxes[0]; *\/ */
/*     /\* int nbi = 0; *\/ */

/*     /\* for (int i = 1; i < boxesSize; i ++) *\/ */
/*     /\* { *\/ */
/*     /\*     if (pre == boxes[i]) *\/ */
/*     /\*         pre_num ++; *\/ */
/*     /\*     else *\/ */
/*     /\*     { *\/ */
/*     /\*         nb[nbi ++] = pre << 32 | pre_num; *\/ */
/*     /\*         pre = boxes[i]; *\/ */
/*     /\*         pre_num = 1; *\/ */
/*     /\*     } *\/ */
/*     /\* } *\/ */

/*     /\* nb[nbi ++] = pre << 32 | pre_num; *\/ */

/*     /\* // 3 dimensions of dp *\/ */
/*     /\* int*** dp = malloc(sizeof(int*) * nbi); *\/ */
/* } */
