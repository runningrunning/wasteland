// FUN, need to figure out why
// read the qs
// it's mathematics
// brilliant solution

// | ai - aj | + | bi - bj | + | i - j |

// =>

// ai - aj + bi - bj + i - j
// (ai + bi + i) - (aj + bj + j)

// ai - aj + bj - bi + i - j
// (ai - bi + i) - (aj - bj + j)

// aj - ai + bi - bj + i - j
// (- ai + bi + i) - (- aj + bj + j)

// aj - ai + bj - bi + i - j
// (- ai - bi + i) - (- aj - bj + j)

#define MAX(a, b) (a) < (b) ? (b) : (a)
#define MIN(a, b) (a) < (b) ? (a) : (b)

int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
    int max = INT_MIN;
    int max_1 = INT_MIN;
    int min_1 = INT_MAX;
    int max_2 = INT_MIN;
    int min_2 = INT_MAX;
    int max_3 = INT_MIN;
    int min_3 = INT_MAX;
    int max_4 = INT_MIN;
    int min_4 = INT_MAX;

    for (int i = 0; i < arr1Size; i ++)
    {
        int a = arr1[i] + arr2[i] + i;
        max_1 = MAX(max_1, a);
        min_1 = MIN(min_1, a);

        a = arr1[i] - arr2[i] + i;
        max_2 = MAX(max_2, a);
        min_2 = MIN(min_2, a);

        a = arr2[i] - arr1[i] + i;
        max_3 = MAX(max_3, a);
        min_3 = MIN(min_3, a);

        a = - arr1[i] - arr2[i] + i;
        max_4 = MAX(max_4, a);
        min_4 = MIN(min_4, a);
    }

    max = max_1 - min_1;
    max = MAX(max, (max_2 - min_2));
    max = MAX(max, (max_3 - min_3));
    max = MAX(max, (max_4 - min_4));
    return max;
}
/*
int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
    int max = 0;
    for (int i = 0; i < arr1Size; i ++)
        for (int j = i + 1; j < arr1Size; j ++)
        {
            int t = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j);
            if (t > max)
                max = t;
        }
    return max;
}
*/
