/* TODO Need write notes for binary search ! */
/* The secret of binary search is that S or E must change every time */
/* Clear doc about binary search ! */
/* the M should never be the next to testing ,not the one we have done testing. */

/* /\** */
/*  * Return an array of size *returnSize. */
/*  * Note: The returned array must be malloced, assume caller calls free(). */
/*  *\/ */
/* char** summaryRanges(int* nums, int numsSize, int* returnSize) */
/* { */
/*     *returnSize = 0; */
/*     if (!nums || !numsSize) */
/*         return NULL; */

/*     char** ret = malloc(sizeof(char*) * numsSize); */

/*     int rt = 0; */
/*     int st = nums[0]; */
/*     int pre = nums[0] - 1; */

/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         if (nums[i] != pre + 1) */
/*         { */
/*             rt ++; */
/*             char* t = malloc(sizeof(char) * 32); */

/*             if (pre > st) */
/*                 sprintf(t, "%d->%d", st, pre); */
/*             else */
/*                 sprintf(t, "%d", st); */

/*             ret[rt - 1] = t; */
/*             st = nums[i]; */
/*         } */

/*         pre = nums[i]; */
/*     } */

/*     rt ++; */
/*     char* t = malloc(sizeof(char) * 32); */

/*     if (pre > st) */
/*         sprintf(t, "%d->%d", st, pre); */
/*     else */
/*         sprintf(t, "%d", st); */

/*     ret[rt - 1] = t; */
/*     *returnSize = rt; */

/*     return ret; */
/* } */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
    char** ret = NULL;

    *returnSize = 0;
    if (!nums || !numsSize)
        return ret;

    int rt = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int s = i;
        int e = numsSize - 1;

        if (nums[e] == nums[s] + e - s)
            s = e;
        else
        {
            /* The secret of binary search is that it should never test any value again, so the m */
            /* should NEVER be base value again !. Either we add/reduce m 1 or base value should  */
            /* be modified once per loop */
            /*
            while(s < e)
            {
                int m = s + (e - s) / 2; // next one test
                if (nums[m] > nums[i] + m - i)
                    e = m; // next >
                else
                    s = m + 1; // next possible >
            }
            s --;
            */

            while(s < e)
            {
                int m = e - (e - s) / 2; // next one to test
                if (nums[m] > nums[i] + m - i)
                    e = m - 1; // next possible <=
                else
                    s = m; // next equal
            }

            /*
            while(s < e)
            {
                int m = s + (e - s + 1) / 2; // next one to test
                if (nums[m] > nums[i] + m - i)
                    e = m - 1; // next possible <=
                else
                    s = m; // next equal
            }
            */
        }

        rt ++;
        if (!ret)
            ret = malloc(sizeof(char*));
        else
            ret = realloc(ret, sizeof(char*) * rt);

        char* t = malloc(32);
        if (nums[i] == nums[s])
            sprintf(t, "%d", nums[i]);
        else
            sprintf(t, "%d->%d", nums[i], nums[s]);
        ret[rt - 1] = t;
        i = s;
    }
    *returnSize = rt;
    return ret;
}
