/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* intervalIntersection(struct Interval* A, int ASize, struct Interval* B, int BSize, int* returnSize)
{
    int a = 0;
    int b = 0;

    int rs = 0;
    struct Interval* r = NULL;

    while (a < ASize && b < BSize)
    {
        if (A[a].start > B[b].end)
            b ++;
        else if (B[b].start > A[a].end)
            a ++;
        else if (A[a].start <= B[b].start && A[a].end >= B[b].end)
        {
            r = realloc(r, sizeof(struct Interval) * (rs + 1));
            r[rs].start = B[b].start;
            r[rs].end = B[b].end;
            rs ++;
            b ++;
        }
        else if (B[b].start <= A[a].start && B[b].end >= A[a].end)
        {
            r = realloc(r, sizeof(struct Interval) * (rs + 1));
            r[rs].start = A[a].start;
            r[rs].end = A[a].end;
            rs ++;
            a ++;
        }
        else
        {
            r = realloc(r, sizeof(struct Interval) * (rs + 1));
            r[rs].start = A[a].start >= B[b].start ? A[a].start : B[b].start;
            r[rs].end = A[a].end <= B[b].end ? A[a].end : B[b].end;

            if (B[b].end > r[rs].end)
            {
                a ++;
                B[b].start = r[rs].end + 1;
            }
            else
            {
                b ++;
                A[a].start = r[rs].end + 1;
            }

            rs ++;
        }
    }

    *returnSize = rs;
    return r;
}
