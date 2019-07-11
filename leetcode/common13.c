#include "common.h"

#if 0

#include "./1099_two_sum_less_than_k.h"
void test()
{
    int m[] = {499,780,837,984,481,526,944,482,862,136,265,605,5,631,974,967,574,293,969,467,573,845,102,224,17,873,648,120,694,996,244,313,404,129,899,583,541,314,525,496,443,857,297,78,575,2,430,137,387,319};
    int k = 1000;
    // int m[] = {34, 23, 1, 24, 75, 33, 54, 8};
    int l = LEN_M(m);
    // int k = 60;
    printf("%d.\n", twoSumLessThanK(m, l , k));
}

#include "./1079_letter_tile_possibilities.h"
void test()
{
    char* t = "AABBAC";
    printf("%d.\n", numTilePossibilities(strdup(t)));
}

#include "./1052_grumpy_bookstore_owner.h"
void test()
{
    int c[] = {1, 0, 1, 2, 1, 1, 7, 5};
    int g[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int l = LEN_M(c);
    printf("%d\n", maxSatisfied(c, l, g, l, 3));
}

#include "./1051_height_checker.h"
void test()
{
    // int m[] = {1, 1, 4, 2, 1, 3, 5, 1};
    int m[] = {1, 2, 3, 4, 5, 6, 7, 1};
    int l = LEN_M(m);
    printf("%d.\n", heightChecker(m, l));
}
#endif

#include "./1089_duplicate_zeros.h"
void test()
{
    // int m[] = {1, 0, 0, 2, 3, 0, 0, 4, 5, 0};
    // int m[] = {1, 2, 3, 0};
    // int m[] = {1, 0, 0, 2, 3, 0, 4};
    int l = LEN_M(m);
    duplicateZeros(m, l);
    out(m, l);
}

int main(int argn, char** argv){
    // printf("INT_MIN %d, INT_MAX %d.\n", INT_MIN, INT_MAX);
    srand(time(NULL));
    int i = 0;
    // while(i++ < 100000)
    {
       // printf("=========\n");
        test();
        // printf("=========\n\n");
    }
}
