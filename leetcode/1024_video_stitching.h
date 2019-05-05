// TODO LEARN A LOT !!
// HOW TO SOLVE THIS IN GREEDY ????
// IT's [) !!!!
// segment tree ??
// or greedy ?????
// better solution ?
// not clear ??
// DP ?????? How to solve this in DP and how about 
/* class Solution { */
/*  public: */
/*     static bool comp(vector<int>& v1, vector<int>& v2) */
/*     { */
/*         if (v1[0] != v2[0]) */
/*             return v1[0] < v2[0]; */
/*         if (v1[1] != v2[1]) */
/*             return v1[1] < v2[1]; */
/*         return false; */
/*     } */

/*     int videoStitching(vector<vector<int>>& clips, int T) { */
/*         sort(clips.begin(), clips.end(), comp); */
/*         if (clips[0][0] != 0) */
/*             return -1; */
/*         int* nums = (int*) calloc(sizeof(int), T + 1); */

/*         int ps = 0; */
/*         int pe = clips[0][1]; */

/*         for (int i = ps; i <= pe && i <= T; i++) */
/*             nums[i] = 1; */

/*         for (int i = 1; i < clips.size(); i ++) */
/*         { */
/*             int cs = clips[i][0]; */
/*             int ce = clips[i][1]; */
/*             if (cs > T) */
/*                 break; */

/*             if (cs > pe) */
/*             { */
/*                 return -1; */
/*             } */

/*             ps = cs; */

/*             if (ce <= pe) */
/*                 continue; */

/*             for (int j = pe + 1; j <= ce && j <= T; j ++) */
/*                 nums[j] = (cs == 0 ? 0 : (nums[cs])) + 1; */

/*             pe = ce; */
/*         } */
/*         return nums[T] ? nums[T] : -1; */
/*     } */
/* }; */

/* class Solution { */
/*  public: */
/*     static bool comp(vector<int>& v1, vector<int>& v2) */
/*     { */
/*         if (v1[0] != v2[0]) */
/*             return v1[0] < v2[0]; */
/*         if (v1[1] != v2[1]) */
/*             return v1[1] < v2[1]; */
/*         return false; */
/*     } */

/*     int videoStitching(vector<vector<int>>& clips, int T) { */
/*         sort(clips.begin(), clips.end(), comp); */
/*         if (clips[0][0] != 0) */
/*             return -1; */
/*         int* nums = calloc(sizeof(int), T + 1); */

/*         int ps = 0; */
/*         int pe = clips[0][1]; */

/*         for (int i = ps; i <= pe && i <= T; i++) */
/*             nums[i] = 1; */

/*         for (int i = 1; i < clipsRowSize; i ++) */
/*         { */
/*             int cs = clips[i][0]; */
/*             int ce = clips[i][1]; */

/*             if (cs > pe + 1) */
/*             { */
/*                 return -1; */
/*             } */

/*             ps = cs; */

/*             if (ce <= pe) */
/*                 continue; */

/*             for (int j = pe + 1; j <= ce && j <= T; j ++) */
/*                 nums[j] = (cs == 0 ? 0 : (nums[cs - 1])) + 1; */

/*             pe = ce; */
/*         } */
/*         // out(nums, T + 1); */
/*         return nums[T] ? nums[T] : -1; */
/*     } */
/* }; */
// segment tree ??
// or greedy ?????
// better solution ?
// not clear ??
// DP ??
int comp(const void* e1, const void* e2)
{
    int** c1 = (int**) e1;
    int** c2 = (int**) e2;

    if ((*c1)[0] != (*c2)[0])
        return (*c1)[0] - (*c2)[0];
    if ((*c1)[1] != (*c2)[1])
        return (*c1)[1] - (*c2)[1];
    return 0;
}

// try greedy
int videoStitching(int** clips, int clipsRowSize, int clipsColSize, int T)
{
    if (!clips || !clipsRowSize)
        return -1;
    if (!T)
        return 0;
    qsort(clips, clipsRowSize, sizeof(int*), comp);

    if (clips[0][0] != 0)
        return -1;

    int mn = 0;
    int me = 0;
    int ne = 0;

    for (int i = 0; i < clipsRowSize; i ++)
    {
        int cs = clips[i][0];
        int ce = clips[i][1];

        if (cs > T)
            break;

        if (cs > ne)
            break;

        if (ce < ne)
            continue;

        if (cs > me)
        {
            mn ++;
            me = ne;
        }

        if (ce > ne)
            ne = ce;
    }
    if (me >= T)
        return mn;
    if (ne >= T)
        return mn + 1;
    return -1;

    // int* nums = calloc(sizeof(int), T + 1);
#if 0
    int ps = 0;
    int pe = clips[0][1];

    for (int i = ps; i <= pe && i <= T; i++)
        nums[i] = 1;

    for (int i = 1; i < clipsRowSize; i ++)
    {
        int cs = clips[i][0];
        int ce = clips[i][1];

        if (cs > T)
            break;

        if (cs > pe)
            return -1;

        ps = cs;

        if (ce < pe)
            continue;

        for (int j = pe + 1; j <= ce && j <= T; j ++)
            nums[j] = (cs == 0 ? 0 : (nums[cs])) + 1;

        pe = ce;
    }
    // out(nums, T + 1);
    return nums[T] ? nums[T] : -1;
#endif
}
