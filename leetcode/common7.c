#include "common.h"

/*
#include "./65_valid_number.h"
void test()
{
    char* m[] = {
                 "0",
                 " 0.1 ",
                 " 0. 1 ",
                 "abc",
                 "0xabc",
                 "-0xabc",
                 "1 a",
                 "2e10",
                 "1e10",
                 "1.23e10",
                 "1e10",
                 "-1e10",
                 "-1e-10",
                 "-1e+10",
                 "-1.23e-10",
                 "-0x10",
                 "1.e10",
                 "1.e-10",
                 ".e10",
                 "-.e-10",
                 "4e+",
                 "+.8",
    };

    int l = LEN_M(m);

    for (int i = 0; i < l; i ++)
        printf("%s is %d.\n", m[i], isNumber(m[i]));
}

#include "./72_edit_distance.h"
void test()
{
    // char* s1 = "horse"; char* s2 = "ros"; // 3
    // char* s1 = "intention"; char* s2 = "execution"; // 5
    // char* s1 = "teacher"; char* s2 = "teache"; // 1
    // char* s1 = "sea"; char* s2 = "eat"; // 2
    // pchar* s1 = "teacher"; char* s2 = "tenace"; // 3
    printf("s1 %s s2 %s is %d.\n", s1, s2, minDistance(s1, s2));
}

#include "./135_candy.h"
void test()
{

    // int m[] = {1, 0, 2}; // 5
    // int m[] = {1, 2, 2}; // 4
    // int m[] = {1, 2, 2, 2, 2, 2, 2, 2}; // 9

    // int m[] = {1, 4, 5, 7, 8, 4, 3, 2, 1}; // 25
    // int m[] = {1, 4, 5, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8}; // 51
    // int m[] = {1, 4, 5, 7, 8, 8, 7, 6, 5, 4, 3, 2, 1}; // 51
    // int m[] = {1, 4, 5, 7, 8, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // 60
    // int m[] = {1, 4, 5, 6, 3, 2, 1}; // 16
    // int m[] = {1, 2, 3, 4, 3, 2, 1}; // 16;
    // int m[] = {2, 3, 4, 5, 4, 3, 2, 1}; // 20
    // int m[] = {2, 3, 4, 5, 4, 3, 2, 1, 0}; // 27
    // int m[] = {3, 4, 5, 6, 5, 4, 3, 2, 1, 0}; // 34

    // int m[] = {1, 2, 3, 4, 3, 5}; // 13
    // int m[] = {1, 2, 3, 4, 3, 5, 6}; // 16
    // int m[] = {1, 2, 3, 4, 3, 5, 1}; // 14
    int m[] = {1, 2, 3, 4, 3, 5, 1, 0}; // 17

    int l = LEN_M(m);
    printf("%d.\n", candy(m, l));
}

#include "./174_dungeon_game.h"
void test()
{

    // int m[] = {-5}; int c = 1; // 6
    // int m[] = {-2, -3, 3, -5, -10, 1, 10, 30, -5}; int c = 3; // 7
    // int m[] = {-5, 100}; int c = 1; // 6
    int m[] = {-5, 100}; int c = 2; // 6


    int l = LEN_M(m);

    int** r = gen_aa(m, l, c);

    printf("%d\n", calculateMinimumHP(r, l / c, &c));
    outaaa(r, c, l / c);
}

#include "./265_paint_house_II.h"
void test()
{
    int m[] = {1, 5 ,3, 2, 9, 4}; int c = 3; // 5
    // int m[] = {8,16,12,18,9,19,18,8,2,8,8,5,5,13,4,15,9,3,19,2,8,7,1,8,17,8,2,8,15,5,8,17,1,15,3,8,8,5,5,16,2,2,18,2,9}; int c = 5; // 28
    // int m[] = {4,16,15,5,18,17,10,12,14,10,3,10,2,11,18,14,9,1,14,13}; int c = 2; // 101
    // int m[] = {16,9,20,8,8,18,8,12,1,16,2,5,3,4,16,3,3,16,9,8,6,14,18,13,13,2,4,19,15,12,13,7,5,5,2,14,9,17,12,6,17,14,6,17,14,3,19,11,6,19,12,1,7,2,12,12,9,4,1,11}; int c = 4; // 65
    // int m[] = {20,7,7,5,12,3,19,9,4,15,2,16,8,17,15,7,3,8,11,13,3,14,19,2,17,11,19,17,6,1,4,2,11,12,6,9,2,9,15,1,5,7,3,20,14,3,20,7,8,11,1,12,2,2,2,14,17,15,10,9,10,12,9,19,20,4,6,10,3,10,7,3,10,4,12,7,2,8,6,4,3,10,5,9,10,7,12,1,12,12,20,17,19,1,10,13,2,7,20,2,13,8,18,13,2}; int c = 5; // 67

    int l = LEN_M(m);

    int** r = gen_aa(m, l, c);
    outaaa(r, c, l / c);
    printf("%d.\n", minCostII(r, l / c, c));
}

#include "./291_word_pattern_II.h"
void test()
{
    char* m[] = {
                 "ac",
                 "bcdxxxx",
                 "abab",
                 "redblueredblue",
                 "aaaaa",
                 "asdasdasdasdasd",
                 "aabb",
                 "xyzabcxyzabc",
                 "abab",
                 "xyzabcxyzabc",
                 "aaaa",
                 "asdasdasdasdasd",
                 "ab",
                 "aa",
                 "abceaa",
                 "axxxxxcea",
                 "",
                 "",
    };

    int l = LEN_M(m);

    for (int i = 0; i < l; i += 2)
        printf("%s %s is %d.\n", m[i], m[i + 1], wordPatternMatch(m[i], m[i + 1]));
}

#include "./301_remove_invalid_parentheses.h"
void test()
{
    // char* s = "()())()";

    // char* s = "()())())(";

    // char* s = "(a)())()";

    // char* s = "()";

    // char* s = ")(";

    // char* s = ")abced(";

    char* s = "xx)a(bce)d)(df))";

    int ri = 0;
    char** r = NULL;
    r = removeInvalidParentheses(s, &ri);
    outstr(r, ri);
}

#include "./149_max_points_on_a_line.h"
void test()
{

    // int m[] = {1, 1, 2, 2, 3, 3}; // 3
    // int m[] = {1, 1, 3, 2, 5, 3, 4, 1, 2, 3, 1, 4}; // 4
    // int m[] = {1, 1, 3, 3}; // 2
    // int m[] = {3, 3}; // 1

    // int m[] = {1, 10, 1, 11, 1, 14, 1, 15, 1, 18, 3, 3}; // 5
    // int m[] = {1, 1, 1, 1, 1, 1}; // 3
    // int m[] = {3, 4, 3, 4, 3, 4, 3, 4}; // 4

    // int m[] = {0, 0, 1, 1, 0, 0}; // 3

    // int m[] = {3, 1, 12, 3, 3, 1, -6, -1}; // 4

    // int m[] = {0,-1,0,3,0,-4,0,-2,0,-4,0,0,0,0,0,1,0,-2,0,4}; // 10

    // int m[] = {0, 0, 1, 1, 1, -1}; // 2
    //  int m[] = {2, 1, 10, 1, 11, 1, 14, 1, 15, 1, 18, 3}; // 5

    int m[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, -1, 1}; // 6

    // int m[] = {-230,324,-291,141,34,-2,80,22,-28,-134,40,-23,-72,-149,0,-17,32,-32,-207,288,7,32,-5,0,-161,216,-48,-122,-3,39,-40,-113,115,-216,-112,-464,-72,-149,-32,-104,12,42,-22,19,-6,-21,-48,-122,161,-288,16,11,39,23,39,30,873,-111}; // 9

    // int m[] = {40,-23,9,138,429,115,50,-17,-3,80,-10,33,5,-21,-3,80,-6,-65,-18,26,-6,-65,5,72,0,77,-9,86,10,-2,-8,85,21,130,18,-6,-18,26,-1,-15,10,-2,8,69,-4,63,0,3,-4,40,-7,84,-8,7,30,154,16,-5,6,90,18,-6,5,77,-4,77,7,-13,-1,-45,16,-5,-9,86,-16,11,-7,84,1,76,3,77,10,67,1,-37,-10,-81,4,-11,-20,13,-10,77,6,-17,-27,2,-10,-81,10,-1,-9,1,-8,43,2,2,2,-21,3,82,8,-1,10,-1,-9,1,-12,42,16,-5,-5,-61,20,-7,9,-35,10,6,12,106,5,-21,-5,82,6,71,-15,34,-10,87,-14,-12,12,106,-5,82,-46,-45,-4,63,16,-5,4,1,-3,-53,0,-17,9,98,-18,26,-9,86,2,77,-2,-49,1,76,-3,-38,-8,7,-17,-37,5,72,10,-37,-4,-57,-3,-53,3,74,-3,-11,-8,7,1,88,-12,42,1,-37,2,77,-6,77,5,72,-4,-57,-18,-33,-12,42,-9,86,2,77,-8,77,-3,77,9,-42,16,41,-29,-37,0,-41,-21,18,-27,-34,0,77,3,74,-7,-69,-21,18,27,146,-20,13,21,130,-6,-65,14,-4,0,3,9,-5,6,-29,-2,73,-1,-15,1,76,-4,77,6,-29}; // 25

    int l = LEN_M(m);
    struct Point* ps = cpoints(m, l);

    printf("%d.\n", maxPoints(ps, l / 2));
}

#include "./901_online_stock_span.h"
void test()
{

    // int m[] = {100, 80, 60, 70, 60, 75, 85, 55, 100};
    int m[] = {255, 100, 80, 60, 70, 60, 75, 85, 255, 1, 2, 3, 4, 5, 6, 100, 100, 100, 100, 101, 5600};

    int l = LEN_M(m);
    StockSpanner* s = stockSpannerCreate();
    for (int i = 0; i < l; i ++)
        printf("%d is %d.\n", m[i], stockSpannerNext(s, m[i]));
}

#include "./902_numbers_at_most_n_given_digit_set.h"

bool is_full(int f, int n)
{
    if (!n)
        return false;

    while (n)
    {
        if (!(f & (1 << (n % 10))))
            return false;
        n /= 10;
    }

    return true;
}

void test()
{

    // char* m[] = {"1", "3", "5", "7"}; int n = 100; // 20
    // char* m[] = {"1", "3", "5", "7"}; int n = 111; // 21
    // char* m[] = {"1", "3", "5", "7"}; int n = 101; // 20
    // char* m[] = {"1", "3", "5", "7"}; int n = 115; // 23
    // char* m[] = {"1", "3", "5", "7"}; int n = 120; // 24
    // char* m[] = {"1", "3", "5", "7"}; int n = 129; // 24
    // char* m[] = {"1", "3", "5", "7"}; int n = 130; // 24
    // char* m[] = {"1", "3", "5", "7"}; int n = 137; // 24
    // char* m[] = {"1", "4", "9"}; int n = 1000000001;

    // char* m[] = {"1", "4", "9"}; int n = 49;
    // char* m[] = {"1", "2", "3", "4", "5", "9"}; int n = 149;
    // char* m[] = {"1", "5", "7", "8", "9"}; int n = 149;
    // char* m[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}; int n = 149;
    // char* m[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}; int n = 149;
    char* m[] = {"6", "7", "8", "9"}; int n = 9;

    // char* m[] = {"6", "7", "8", "9"}; int n = 149;

    int l = LEN_M(m);
    printf("%d.\n", atMostNGivenDigitSet(m, l, n));

    // int f = 0;
    // for (int i = 0; i < l; i ++)
    //     f |= 1 << (m[i][0] - '0');
    // for (int t = 1; t <= 100000; t ++)
    // {
    //     int num = 0;
    //     for (int n = 1; n <= t; n ++)
    //         if (is_full(f, n))
    //             num ++;
    //     int tnum = atMostNGivenDigitSet(m, l, t);
    //     if (tnum != num)
    //         printf("t %d, num %d %d.\n", t, num, tnum);
    // }
}
*/

#include "./899_orderly_queue.h"
void test()
{
    char* s = "cba"; int k = 1;
    // char* s = "acaba"; int k = 3;
    // char* s = "baaca"; int k = 10;
    // char* s = "djsjhocwytnpttkdganudslnhbywmboknlbwcftorhlrrvwxuihxcknmoybdgzpuuovoobinebzfoouzmccfcdxzdmtudpgzretbahszlqvtfvpbpglfdhcdzwzsocufjekgqdwyrgipwspwusemvkbcssggvuemefwazeoljyrkviiwljliwnoqokcdbhldyomhoscrzfgiqrzxounqomdvckcuxivhxrwatajgdmtuzhbahdzclzvifgqhtqepevgikhcmdmnwqbbxiqzeysirlihzzhdnsaelepstxyqkoxqystlvuwrboifdtamblyqnejxxrixxusthwehlaykpqyfsnybciyidgiidciirnmjpwvkzyscxshuaujioxnfljuacyozqcxfskwvpvtqzswuvwzqibguudgdnbehzdtuatpcopunjzsevzvmjxxwrmlvmlvvkydklkatufphyivzdzokbelsazabajgxuvcyirlid"; int k = 250;
    // char* s = "djsjhocwytnpttkdganudslnhbywmboknlbwcftorhlrrvwxuihxcknmoybdgzpuuovoobinebzfoouzmccfcdxzdmtudpgzretbahszlqvtfvpbpglfdhcdzwzsocufjekgqdwyrgipwspwusemvkbcssggvuemefwazeoljyrkviiwljliwnoqokcdbhldyomhoscrzfgiqrzxounqomdvckcuxivhxrwatajgdmtuzhbahdzclzvifgqhtqepevgikhcmdmnwqbbxiqzeysirlihzzhdnsaelepstxyqkoxqystlvuwrboifdtamblyqnejxxrixxusthwehlaykpqyfsnybciyidgiidciirnmjpwvkzyscxshuaujioxnfljuacyozqcxfskwvpvtqzswuvwzqibguudgdnbehzdtuatpcopunjzsevzvmjxxwrmlvmlvvkydklkatufphyivzdzokbelsazabajgxuvcyirlid"; int k = 1;
    // char* s = "kuh"; int k = 1;
    printf("%s\n%s.\n", s, orderlyQueue(s, k));
}


int main(int argn, char** argv)
{
    // printf("INT_MIN %d, INT_MAX %d.\n", INT_MIN, INT_MAX);
    srand(time(NULL));
    int i = 0;
    // while(i++ < 1000)
    {
       // printf("=========\n");
        test();
        // printf("=========\n\n");
    }
}
