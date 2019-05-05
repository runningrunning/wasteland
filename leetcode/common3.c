#include "common.h"

/*
#include "./424_longest_repeating_character_replacement.h"
void test()
{

    // char* s = "ABAB";
    // int k = 2;

    // char* s = "AABABBBA";
    char* s = "AAAAAABBBBBBBBBCCCCCCCCCCDCC";
    int k = 2;
    printf("%d.\n", characterReplacement(s, k));
}

#include "./340_longest_substring_with_at_most_k_distinct_characters.h"
void test()
{
    // char* s = "ecebabbbacnifeninfanobie";
    // int k = 4;

    char* s = "ecebbba";
    int k = 1;
    printf("%d.\n", lengthOfLongestSubstringKDistinct(s, k));
}

#include "./830_positions_of_large_groups.h"
void test()
{
    // char* s = "abbxxxxxzzy";
    // char* s = "abc";

    // char* s = "abcdddeeeeaabbbcdddd";
    char* s = "a";
    int ri;
    int* c;
    int** r = largeGroupPositions(s, &c, &ri);
    outaa(r, c, ri);
}

#include "./831_masking_personal_information.h"
void test()
{
    // char* s = "LeetCode@LeetCode.com";
    // char* s = "AB@qq.com";

    // char* s = "1(234)567-890)";
    // char* s = "86-(10)13345678";
    char* s = "+111 111 111 111 1";
    printf("%s.\n", maskPII(s));
}

#include "./829_consecutive_numbers_sum.h"
void test()
{
    int x = 911111335;
    // int x = 1;
    printf("%d.\n", consecutiveNumbersSum(x));
}

#include "./828_unique_letter_string.h"
void test()
{
    char* s = "LETTER";
    // char* s = "ABC";
    // char* s = "ABAB";
    printf("%d.\n", uniqueLetterString(s));
}

#include "./239_sliding_window_maximum.h"
void test()
{
    // int m[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int m[] = {7, 2, 4};
    int l = LEN_M(m);

    int ri;
    int* r = maxSlidingWindow(m, l, 2, &ri);
    out(r, ri);
}

#include "./768_max_chunks_to_make_sorted_II.h"
void test()
{
    // int m[] = {5,4,3,2,1};
    // int m[] = {2, 1, 3, 4, 4};
    int m[] = {2, 1, 3, 5, 4, 3};
    int l = LEN_M(m);
    printf("%d.\n", maxChunksToSorted(m, l));
}

#include "./128_longest_consecutive_sequence.h"
void full_permutation(int* n, int s, int e)
{
    if (s == e)
    {
        if (longestConsecutive(n, e + 1) != 30)
            out(n, e + 1);
    }
    else
    {
        int cur = n[s];

        for (int i = s; i <= e; i ++)
        {
            int t = n[i];
            n[i] = n[s];
            n[s] = t;
            full_permutation(n, s + 1, e);
            n[i] = n[s];
            n[s] = cur;
        }
    }
}
void test()
{
    int n[] = {-3, -4, -6, -7, -8, 100, 4, 15, 200, 1, 2, 17, 3, 0, -1, -2, 5, 6, 7, 8, 9, 19, 18, -10, 14, 11, 9, 13, 16, -8, -4, 10, -5, 12, -9};
    int l = LEN_M(n);

    int* r = dup_a(n, l);
    full_permutation(r, 0, l - 1);
    printf("%d.\n", longestConsecutive(n, l));
}

#include "./115_distinct_subsequences.h"
void test()
{

    // char* s = "rabbbit";
    // char* t = "rabbit";

    // char* s = "babgbag";
    // char* t = "bag";a

    // char* s = "ddd";
    // char* t = "dd";

    char* s = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
    char* t = "bcddceeeebecbc";

    printf("%d.\n", numDistinct(s, t));
}

#include "./149_max_points_on_a_line.h"
void test()
{
}

#include "./140_word_break_II.h"
void test()
{

    // char* s = "catsanddog";
    // char* d[] = {"cat", "cats", "and", "sand", "dog"};

    // char* s = "pineapplepenapple";
    // char* d[] = {"apple", "pen", "applepen", "pine", "pineapple"};

    // char* s = "catsandog";
    // char* d[] = {"cats", "dog", "sand", "and", "cat"};

    char* s = "aaaaaaaa";
    char* d[] = {"aaaa", "aa", "a"};

    int l = LEN_M(d);

    int ri;
    char** r = wordBreak(s, d, l, &ri);
    outstr(r, ri);
    // printf("%d.\n", ri);
}

#include "./472_concatenated_words.h"
void test()
{
    char* w[] = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    // char* w[] = {"a", "aa", "aaa", "aaaaa"};
    int l = LEN_M(w);

    char** d = malloc(sizeof(char*) * l);
    memcpy(d, w, sizeof(char*) * l);

    int ri = 0;
    char** r = findAllConcatenatedWordsInADict(d, l, &ri);
    outstr(r, ri);
    free(d);
    free(r);
}

#include "./282_expression_add_operators.h"
void test()
{
    // char* s = "123"; int t = 6;
    // char* s = "232"; int t = 8;
    // char* s = "105"; int t = 5;
    char* s = "105551024"; int t = 12524;
    // char* s = "00"; int t = 0;
    // char* s = "3456237490"; int t = 9191;

    // char* s = "123456789"; int t = 45;
    int ri = 0;
    char** r = addOperators(s, t, &ri);
    outstr(r, ri);
}

#include "./527_word_abbreviation.h"
void test()
{
    char* d[] = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion", "intrusxon", "ixtrusxox"};
    int l = LEN_M(d);

    char** r = malloc(sizeof(char*) * l);
    memcpy(r, d, sizeof(char*) * l);
    int ri = 0;
    char** t = wordsAbbreviation(r, l, &ri);
    outstr(r, l);
    outstr(t, l);
}

// FAILED PASS!!!
#include "./164_maximum_gap.h"
void test()
{
    // int m[] = {3, 6, 9, 1, 1, 20, 21, 16, 17, 18, 16, 15, 11, 26};
    // int m[] = {1, 1, 1, 1};
    int m[] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    int l = LEN_M(m);

    printf("%d.\n", maximumGap(m, l));
}

#include "./652_find_duplicate_subtrees.h"
void test()
{
    // int m[] = {1, 2, 3, 4, 0, 2, 4, 0, 0, 0, 0, 4};
    int m[] = {1, 2, 2, 4, 4, 4, 4};
    struct TreeNode *r = gen_tree(m, sizeof(m)/sizeof(m[0]));
    int rs;
    int* cs;
    int** ret = levelOrderBottom(r, &cs, &rs);

    outTree(r);
    for(int i = 0; i < rs; i++)
        out(ret[i], cs[i]);
    int rs = 0;
    struct TreeNode** t = findDuplicateSubtrees(r, &rs);
    for (int i = 0; i < rs; i ++)
        outTree(t[i]);
}

#include "./483_smallest_good_base.h"
void test()
{
    char* s = "1000000000000000000";
    printf("%ld.\n", smallestGoodBase(s));
}

#include "./716_max_stack.h"
void test()
{
    MaxStack* s = maxStackCreate(20);
    maxStackPush(s, -63);
    printf("%d.\n", maxStackTop(s));
    maxStackPush(s, -57);
    printf("%d.\n", maxStackPopMax(s));
    maxStackPush(s, -48);
    maxStackPush(s, 46);
    printf("%d.\n", maxStackTop(s));
    printf("%d.\n", maxStackPeekMax(s));
    printf("%d.\n", maxStackPopMax(s));
    printf("%d.\n", maxStackTop(s));
    printf("%d.\n", maxStackPop(s));
    printf("%d.\n", maxStackPopMax(s));
    maxStackPush(s, 18);
    maxStackPush(s, 84);
    maxStackPush(s, -4);
    maxStackPush(s, 71);
    maxStackPush(s, -89);
    maxStackPush(s, 12);
    printf("%d.\n", maxStackPeekMax(s));
    maxStackPush(s, 38);
}

// #include "./380_insert_delete_getrandom_O1.h"
#include "./381_insert_delete_get_random_O1_duplicates_allowed.h"
void test()
{
    RandomizedSet* obj = randomizedSetCreate();
    printf("%d. \n", randomizedSetInsert(obj, 3));
    printf("%d. \n", randomizedSetInsert(obj, -2));
    printf("%d. \n", randomizedSetRemove(obj, 2));
    printf("%d. \n", randomizedSetInsert(obj, 1));
    printf("%d. \n", randomizedSetInsert(obj, -3));
    printf("%d. \n", randomizedSetInsert(obj, -2));
    printf("%d. \n", randomizedSetRemove(obj, -2));
    printf("%d. \n", randomizedSetRemove(obj, 3));
    printf("%d. \n", randomizedSetInsert(obj, -1));
    printf("%d. \n", randomizedSetRemove(obj, -3));
    printf("%d. \n", randomizedSetInsert(obj, 1));
    printf("%d. \n", randomizedSetInsert(obj, -2));
    printf("%d. \n", randomizedSetInsert(obj, -2));
    printf("%d. \n", randomizedSetInsert(obj, -2));
    printf("%d. \n", randomizedSetInsert(obj, 1));
    printf("%d. \n", randomizedSetGetRandom(obj));
}

#include "./295_find_median_from_data_stream.h"
void test()
{
    MedianFinder* m = medianFinderCreate();
    medianFinderAddNum(m, 1);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 2);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 3);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 4);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 5);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 6);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 7);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderAddNum(m, 8);
    printf("%lf.\n", medianFinderFindMedian(m));
    medianFinderFree(m);
}

#include "./833_find_and_replace_in_string.h"
void test()
{
    char* s = "abcd";
    int i[] = {0, 2, 2};
    int l = LEN_M(i);
    char* sr[] = {"a", "cx", "cd"};
    char* tg[] = {"eee", "fff", "x"};

    printf("%s.\n", findReplaceString(s, i, l, sr, l, tg, l));
}

#include "./835_image_overlap.h"
void test()
{
    int m1[] = {1, 1, 0, 0, 1, 0, 0, 1, 0};
    int m2[] = {0, 0, 0, 0, 1, 1, 0, 0, 1};

    int l = LEN_M(m1);

    int c = 3;
    int** i1 = gen_aa(m1, l, c);
    int** i2 = gen_aa(m2, l, c);
    printf("%d \n", largestOverlap(i1, 3, 0, i2, 3, 0));
}

#include "./480_sliding_window_median.h"
void test()
{
    // int m[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int m[] = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    int l = LEN_M(m);
    int k = 3;

    int rs = 0;
    double* r = medianSlidingWindow(m, l, k, &rs);()
    outd(r, rs);
}

#include "./432_all_O_one_data_structure.h"
void test()
{
     AllOne* o = allOneCreate();
     allOneInc(o, "hello");
     allOneInc(o, "goodbye");
     allOneInc(o, "hello");
     allOneInc(o, "hello");
     printf("%s.\n", allOneGetMaxKey(o));
     allOneInc(o, "leet");
     allOneInc(o, "code");
     allOneInc(o, "leet");
     allOneDec(o, "hello");
     allOneInc(o, "leet");
     allOneInc(o, "code");
     allOneInc(o, "code");
     printf("%s.\n", allOneGetMaxKey(o));
     allOneInc(o, "1");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "1");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
}

#include "./354_russian_doll_envelopes.h"
void test()
{
    int m[] = {5, 4, 6, 4, 6, 7, 2, 3};
    // int m[] = {6, 4, 6, 7};
    // int m[] = {30, 50, 12, 2, 3, 4, 12, 15};
    // int m[] = {};
    // int m[] = {2, 100, 3, 200, 4, 300, 5, 500, 5, 400, 5, 250, 6, 370, 6, 360, 7, 380};
    int l = LEN_M(m);
    int** r = gen_aa(m, l, 2);
    printf("%d.\n", maxEnvelopes(r, l / 2, 2));
}

#include "./146_lru_cache.h"
void test()
{
    LRUCache* l = lRUCacheCreate(2);
    lRUCachePut(l, 1, 1);
    lRUCachePut(l, 2, 2);
    printf("%d.\n", lRUCacheGet(l, 1));
    lRUCachePut(l, 3, 3);
    printf("%d.\n", lRUCacheGet(l, 2));
    lRUCachePut(l, 4, 4);
    printf("%d.\n", lRUCacheGet(l, 1));
    printf("%d.\n", lRUCacheGet(l, 3));
    printf("%d.\n", lRUCacheGet(l, 4));
    lRUCachePut(l, 5, 5);
    printf("%d.\n", lRUCacheGet(l, 3));
    printf("%d.\n", lRUCacheGet(l, 4));
}

#include "./460_lfu_cache.h"
void test()
{

    // LFUCache* l = lFUCacheCreate(2);
    // lFUCachePut(l, 1, 1);
    // lFUCachePut(l, 2, 2);
    // printf("%d.\n", lFUCacheGet(l, 1));
    // lFUCachePut(l, 3, 3);
    // printf("%d.\n", lFUCacheGet(l, 2));
    // printf("%d.\n", lFUCacheGet(l, 3));
    // lFUCachePut(l, 4, 4);
    // printf("%d.\n", lFUCacheGet(l, 1));
    // printf("%d.\n", lFUCacheGet(l, 3));
    // printf("%d.\n", lFUCacheGet(l, 4));
    // lFUCachePut(l, 5, 5);
    // printf("%d.\n", lFUCacheGet(l, 1));
    // printf("%d.\n", lFUCacheGet(l, 2));
    // printf("%d.\n", lFUCacheGet(l, 3));
    // printf("%d.\n", lFUCacheGet(l, 4));
    // printf("%d.\n", lFUCacheGet(l, 5));
    // lFUCachePut(l, 6, 6);
    // printf("%d.\n", lFUCacheGet(l, 3));
    // printf("%d.\n", lFUCacheGet(l, 4));
    // printf("%d.\n", lFUCacheGet(l, 5));

    // LFUCache* l = lFUCacheCreate(3);
    // lFUCachePut(l, 7, 28);
    // lFUCachePut(l, 7, 1);
    // lFUCachePut(l, 8, 15);
    // printf("%d.\n", lFUCacheGet(l, 6));
    // lFUCachePut(l, 10, 27);
    // lFUCachePut(l, 8, 10);
    // printf("%d.\n", lFUCacheGet(l, 8));
    // lFUCachePut(l, 6, 29);
    // lFUCachePut(l, 1, 9);
    // printf("%d.\n", lFUCacheGet(l, 6));
    // lFUCachePut(l, 10, 7);
    // printf("%d.\n", lFUCacheGet(l, 1));
    // printf("%d.\n", lFUCacheGet(l, 2));
    // printf("%d.\n", lFUCacheGet(l, 13));
    // lFUCachePut(l, 8, 30);
    // lFUCachePut(l, 1, 5);
    // printf("%d.\n", lFUCacheGet(l, 1));
    // lFUCachePut(l, 13, 2);
    // printf("%d.\n", lFUCacheGet(l, 12));

    LFUCache* l = lFUCacheCreate(10);
    lFUCachePut(l, 10, 13);
    lFUCachePut(l, 3, 17);
    lFUCachePut(l, 6, 11);
    lFUCachePut(l, 10, 5);
    lFUCachePut(l, 9, 10);
    printf("%d.\n", lFUCacheGet(l, 13));
    lFUCachePut(l, 2, 19);
    printf("%d.\n", lFUCacheGet(l, 2));
    printf("%d.\n", lFUCacheGet(l, 3));
    lFUCachePut(l, 5, 25);
    printf("%d.\n", lFUCacheGet(l, 8));
    lFUCachePut(l, 9, 22);
    lFUCachePut(l, 5, 5);
    lFUCachePut(l, 1, 30);
    printf("%d.\n", lFUCacheGet(l, 11));
    lFUCachePut(l, 9, 12);
    printf("%d.\n", lFUCacheGet(l, 7));
    printf("%d.\n", lFUCacheGet(l, 5));
    printf("%d.\n", lFUCacheGet(l, 8));
    printf("%d.\n", lFUCacheGet(l, 9));
    lFUCachePut(l, 4, 30);
    lFUCachePut(l, 9, 3);
    printf("%d.\n", lFUCacheGet(l, 9));
    printf("%d.\n", lFUCacheGet(l, 10));
    printf("%d.\n", lFUCacheGet(l, 10));
    lFUCachePut(l, 6, 14);
    lFUCachePut(l, 3, 1);
    printf("%d.\n", lFUCacheGet(l, 3));
    lFUCachePut(l, 10, 11);
    printf("%d.\n", lFUCacheGet(l, 8));
    lFUCachePut(l, 2, 14);
    printf("%d.\n", lFUCacheGet(l, 1));
    printf("%d.\n", lFUCacheGet(l, 5));
    printf("%d.\n", lFUCacheGet(l, 4));
    lFUCachePut(l, 11, 4);
    lFUCachePut(l, 12, 24);
    lFUCachePut(l, 5, 18);
    printf("%d.\n", lFUCacheGet(l, 13));
    lFUCachePut(l, 7, 23);
    printf("%d.\n", lFUCacheGet(l, 8));
    printf("%d.\n", lFUCacheGet(l, 12));
    lFUCachePut(l, 3, 27);
    lFUCachePut(l, 2, 12);
    printf("%d.\n", lFUCacheGet(l, 5));
    lFUCachePut(l, 2, 9);
    lFUCachePut(l, 13, 4);
    lFUCachePut(l, 8, 18);
    lFUCachePut(l, 1, 7);
    printf("%d.\n", lFUCacheGet(l, 6));
    lFUCachePut(l, 9, 29);
    lFUCachePut(l, 8, 21);
    printf("%d.\n", lFUCacheGet(l, 5));
    lFUCachePut(l, 6, 30);
    lFUCachePut(l, 1, 12);
    printf("%d.\n", lFUCacheGet(l, 10));
    lFUCachePut(l, 4, 15);
    lFUCachePut(l, 7, 22);
    lFUCachePut(l, 11, 26);
    lFUCachePut(l, 8, 17);
    lFUCachePut(l, 9, 29);
    printf("%d.\n", lFUCacheGet(l, 5));
    lFUCachePut(l, 3, 4);
    lFUCachePut(l, 11, 30);
    printf("%d.\n", lFUCacheGet(l, 12));
    lFUCachePut(l, 4, 29);
    printf("%d.\n", lFUCacheGet(l, 3));
    printf("%d.\n", lFUCacheGet(l, 9));
    printf("%d.\n", lFUCacheGet(l, 6));
    lFUCachePut(l, 3, 4);
    printf("%d.\n", lFUCacheGet(l, 1));
    printf("%d.\n", lFUCacheGet(l, 10));
    lFUCachePut(l, 3, 29);
    lFUCachePut(l, 10, 28);
    lFUCachePut(l, 1, 20);
    lFUCachePut(l, 11, 13);
    printf("%d.\n", lFUCacheGet(l, 3));
    lFUCachePut(l, 3, 12);
    lFUCachePut(l, 3, 8);
    lFUCachePut(l, 10, 9);
    lFUCachePut(l, 3, 26);
    printf("%d.\n", lFUCacheGet(l, 8));
    printf("%d.\n", lFUCacheGet(l, 7));
    printf("%d.\n", lFUCacheGet(l, 5));
    lFUCachePut(l, 13, 17);
    lFUCachePut(l, 2, 27);
    lFUCachePut(l, 11, 15);
    printf("%d.\n", lFUCacheGet(l, 12));
    lFUCachePut(l, 9, 19);
    lFUCachePut(l, 2, 15);
    lFUCachePut(l, 3, 16);
    printf("%d.\n", lFUCacheGet(l, 1));
    lFUCachePut(l, 12, 17);
    lFUCachePut(l, 9, 1);
    lFUCachePut(l, 6, 19);
    printf("%d.\n", lFUCacheGet(l, 4));
    printf("%d.\n", lFUCacheGet(l, 5));
    printf("%d.\n", lFUCacheGet(l, 5));
    lFUCachePut(l, 8, 1);
    lFUCachePut(l, 11, 7);
    lFUCachePut(l, 5, 2);
    lFUCachePut(l, 9, 28);
    printf("%d.\n", lFUCacheGet(l, 1));
    lFUCachePut(l, 2, 2);
    lFUCachePut(l, 7, 4);
    lFUCachePut(l, 4, 22);
    lFUCachePut(l, 7, 24);
    lFUCachePut(l, 9, 26);
    lFUCachePut(l, 13, 28);
    lFUCachePut(l, 11, 26);
}

#include "./778_swim_in_rising_water.h"
void test()
{
    // int m[] = {0,1,2,3,4,24,23,22,21,5,12,13,14,15,16,11,17,18,19,20,10,9,8,7,6}; int c = 5;
    // int m[] = {7, 23, 21, 9, 5, 3, 20, 8, 18, 15, 14, 13, 1, 0, 22, 2, 10, 24, 17, 12, 6, 16, 19, 4, 11}; int c = 5;
    int m[] = {26,99,80,1,89,86,54,90,47,87 ,9,59,61,49,14,55,77,3,83,79,42,22,15,5,95,38,74,12,92,71,58,40,64,62,24,85,30,6,96,52,10,70,57,19,44,27,98,16,25,65,13,0,76,32,29,45,28,69,53,41,18,8,21,67,46,36,56,50,51,72,39,78,48,63,68,91,34,4,11,31,97,23,60,17,66,37,43,33,84,35,75,88,82,20,7,73,2,94,93,81};  int c = 10;

    int l = LEN_M(m);

    int** r = gen_aa(m, l, c);
    printf("%d.\n", swimInWater(r, c, NULL));

    outaaa(r, c, c);
}

#include "./632_smallest_range.h"
void test()
{
    int m1[] = {4, 10, 15, 24, 25};
    int m2[] = {0, 9, 12, 20, 25};
    int m3[] = {5, 18, 22, 25, 30};
    int m4[] = {25};
    int* m[] = {m1, m2, m3, m4};
    int l[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4)};

    int rs = 0;
    int* r = smallestRange(m, LEN_M(m), l, &rs);
    out(r, rs);
}

#include "./277_find_the_celebrity.h"
void test()
{
}

#include "./533_lonely_pixel_II.h"
void test()
{
    char* m[] = {
        "WBWBBW",
        "WBWBBW",
        "WBWBBW",
        "WWBWBW",
    };

    int r = LEN_M(m);
    int c = strlen(m[0]);
    int n = 3;

    printf("%d.\n", findBlackPixel(m, r, c, n));
}

#include "./792_number_of_matching_subsequences.h"
void test()
{
    // char* m[] = {"a", "bb", "aa", "ace", "acd", "bc", "cx"};
    char* m[] = {"vn", "vm", "vm", "vn", "vn", "vn", "vn"};
    int l = LEN_M(m);
    // printf("%d.\n", numMatchingSubseq("abbcdex", m, l));
    printf("%d.\n", numMatchingSubseq("vvvvvvvn", m, l));
    // outstr(m, l);
}

#include "./782_transform_to_chessboard.h"
void test()
{
    // int m[] = {0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1}; int c = 4;
    // int m[] = {0, 1, 1, 0}; int c = 2;
    // int m[] = {1, 0, 0, 1}; int c = 2;
    // int m[] = {1, 0, 1, 0}; int c = 2;
    // int m[] = {1, 0, 1, 0, 1, 0, 1, 0, 1}; int c = 3;
    int m[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}; int c = 4;
    int l = LEN_M(m);

    int cs[1] = {c};
    int** i = gen_aa(m, l, c);

    printf("%d.\n", movesToChessboard(i, l / c, cs));
}

#include "./838_push_dominoes.h"
void test()
{
    char* s = ".L.R....LR..L..RRLR..LRRL..L..RLLR....R..";
    // char* s = "R.L.L...RR";
    // char* s = "RR.L";
    // char* s = ".L.R...L";
    printf("%s.\n", pushDominoes(strdup(s)));
}

#include "./839_similar_string_groups.h"
void test()
{
    // char* s[] = {"tars", "rats", "arts", "star", "atrs", "srat", "sart"};
    // char* s[] = {"rt", "tr", "tr"};
    // char* s[] = {"xsfiqspnyg","sfgixnqysp","ngpssyfixq","snyixgfqsp","sqpnyixgsf","fxgispnsyq","yipqxfngss","gssqpynixf","nsgfxyipqs","sxsnyqfgip","sfxpysingq","sgypfxnqsi","xpsfsiygnq","fsspxqgyni","xssiqnfypg","yinsxfsqpg","gyisxqsfpn","sfnpxiqsyg","signfqypxs","sxfqgsynip","nsgyqsxifp","nqyisgfsxp","sqypfxngsi","psqigsyfnx","fxgpqsisny","ifnxpgqssy","fsgsxqyinp","fyigsqxnps","spsxqfingy","pfgsixsyqn","qyxsfigpns","figsxnspyq","syignsxfpq","nsqsfiypxg","gssfpxiynq","syqgxsipnf","yqnspixfsg","fnspqyixgs","nsiyxsqpfg","gsxsfypnqi","qsfngipxsy","psxfyisnqg","sxnypsqfgi","fsipxngyqs","xgfsypqsin","qfigsxsynp","ifpgnsyxsq","gsxsiypnqf","gxssyiqfnp","qisfnxpgsy","ssxyqfinpg","yixpsqsfgn","piyfsxgqsn","ixqsgfnyps","gsinysxqfp","sysgqixfnp","fsqxnyigsp","sgxiqspnfy","fpqyxsigns","sqgyixpfsn","ygqnsispxf","ixyssgqfnp","yinspxsfqg","sysqifnxgp","ygsqsxnifp","gsxsifpnqy","nqsiypgfxs","yfssigxpqn","xspsqfnyig","sqnypsxigf","qsipsxngfy","qsisxpgnyf","sxfpsnyqig","synsifgpxq","qnsygfpxsi","ysigpnqsfx","fpgiqnxssy","sqyixngpfs","fspiqxsyng","xgfqssipyn","sgxnsyipfq","sfnpgyqisx","niqfsspyxg","sygfpxnqsi","ginsqspxfy","yipsnxsfqg","qinsxpyfsg","gpfysqnsix","sqgfpixsyn","pnisqgfxsy","npgiyqsxsf","sgyipsfxnq","fsqnisyxpg","xsypgqinsf","pqifnyxssg","fsigyqspnx","qginxssfyp","nspxfsgqiy","siqfpgnyxs","syxqginpfs","xpnygfqssi","fgispnxysq","pyixnfsgsq","gsixnspyqf","sgqfyxspni","qspyfigxns","sgqsnfxipy","siqspgnyfx","sxpgniqyfs","fgxyspsqin","ssynxfgqip","xngissypfq","snqxfpsyig","siqfspgynx","gysqspfixn","sixpsqfnyg","nspxqsgfiy","sfqiypngxs","fqxyspsnig","nsisqpxgfy","gxnpysfsqi","ysgqpxinfs","fqssxgpiyn","ifygsqpsnx","xsygiqnfps","sfisxgnqyp","syfxgispnq","fgsipyxsqn","qnpssxgfyi","sgxfsyipnq","spgfisxqyn","nixssypgqf","ygisqxfsnp","gpifqxssny","npfqxisysg","fissxqpnyg","fysgnpixqs","xsnispqygf","sygfqispxn","gxispnfysq","figpxnssyq","ygixsfsnqp","qssyipfgnx","xqngypfsis","fsxnpgyqsi","gfnqxsyspi","synfsxqgpi","inqpgssxfy","npqxsfgsyi","syigsxqfnp","sfnixpqsyg","pgxisyfqsn","nspygsfqxi","spqifygsnx","gsinypfsxq","pngfssyqix","yxsisnpfgq","nxsyfipgqs","iypqsngxfs","piqsnfxsgy","nfxsqyspgi","sqyfigpxns","siyfsxpgqn","sqpfynisxg","finspgqxys","ysfipxgqsn","sxipqfgsny","sfqixypsng","xnypgqissf","xypifqsgns","xsyngifpsq","snfispxygq","pnsfixgqsy","snygpfxqis","sqsnypfgix","sgipnfxysq","ynisxfqspg","ypgsixqfsn","siqpgsnfxy","nygqisxpfs","fnqyxpigss","qsxyfigpns","fsxypgqsni","syqfgsnpix","ipnsxyqfsg","qfynsgspxi","ixnqfsyspg","gpyxsqifns","yspnqxsgif","qsfnysxpgi","ygqnxispsf","fpyxgqnsis","fnyspsxgiq","fsxpngsqyi","yfxisspgnq","gqsxfpysni","qysxpfgnis","fnixspygqs","xnpsiqyfgs","sfqiysngxp","qxisgfnyps","xipsfsyqgn","qsxpisngfy","syxqispgfn","siynxgqfps","fqpgssyxin","ysinxqfspg","ifnspgqsxy","ysfnqgpsxi","ysfnqgpsix","nfgqisypxs","sfyqpgsnxi","sfxiyspngq","iysspnxfgq","ygfxpinssq","sgifyqpxns","fsqpnsgxyi","nsgxisfpqy","sgyxfnipqs","pnxgssyqif","sxpsgqfyin","yfxgispqns","yfqixsnpsg","ysgsixpfqn","yfxgisqpsn","qsgpnfixys","qsfpxnygsi","psyxsqfgin","fypxgsqisn","qssingpxyf","fyisngpxqs","snsqixgfpy","nifyqspxsg","pnssixfqyg","gyfnsxspqi","inqssypgfx","ifpyxsnsqg","qsfngxpisy","gsyfnxispq","gsynqsxifp","qxisgfynps","sqnixygpfs","yissxqpnfg","yqsxgsnfip","qxnifgypss","ngqisspyxf","ygqsspxnif","qpsgiyxsfn","pyqgfsinsx","sifpsnyqxg","pxgnsyfqis","gssqinpxfy","ypqfisxgsn","qpysgsinxf","sfqnispyxg","nyixsspqfg","fyqpsgsnxi","gsfxspnyiq","qngypxsifs","ixfpqsngys","fpyqsxisng","ysxginsfpq","nxqsiyfpgs","fqsyipsxgn","xnqisgsfyp","qnpxifyssg","iqnsgysxfp","sqxnifgpsy","gnfpxyiqss","sixsgyfqpn","fsqpxsgnyi","yqsipsgnxf","pfissngqxy","sgpqynifxs","nqsyfgsxpi","syfgsqpinx","fsqsngyxip","fsnqpxiygs","xsisqnfypg","sngyfspxiq","fixgsypqsn","spsynqixfg","snypisgxfq","pnysqgisfx","qnpisyfgsx","nspxisyqfg","yqsgnifpxs","ngsypsxqfi","fspinxysqg","sixgfypqsn","iysnxpqfsg","psxynsfgiq","fqgpsixnsy","nsgypsfiqx","sqxnspiygf","sgsnypxqif","yssfxgpinq","ifpssnyxgq","fnpsxqsyig","gqypnxfsis","sqgfpxnysi","qigfsxypsn","spnygfsqix","sisnxfgpyq","yfsgniqpxs","sxynqfgpis","pxssigqnfy","siyfsxgqpn","sipgqyxfsn","nqsixpgfsy","gqyxssnpif","qgsnfpysxi","sqysfnpxgi","ngqsyxsfip","fpsxsngyqi","spfxqisnyg","fpxsgiyqns","gsxnqfiyps","pqixnfssgy","spxysfqgin","xnyssgiqpf","qspnyifsgx","yxspnisfgq","xqgsypsinf","sipgnsyxfq","inspsqfxgy","pgixsfqnsy","fxqipgssny","yxfspgsinq","fgiqysxpns","npgxqissfy","nipfxsqysg","ipsxfgqnys","fxsipsqyng","yspxsqfgin","iynqpfgssx","xisqsfpnyg","ynqxfsgips","sgyiqspnfx","pfsiqysxng","nqsgypsifx","ynspqfgsix","nqsixpgfys","spxsfyignq","qfpnsxigys","snsfigxyqp","sfsqpynxgi","spxynfqgis","inxypfsqsg","pgqsnsxyfi","ygixqsfsnp","qnpsyifsgx","pqsyfgixns","qixnpfsgys","qxpinfyssg","yxngpfqiss","spgsfnxyqi","sqxygipfsn","sgixpnsqyf","snqipxgysf","xsqpygsnfi","ysfnsgpixq","sysgxiqfnp","psyxgnqsfi","nfqssyigxp","nspsfiyqxg","qfpysgnsix","nyixsfpgsq","qynspixfsg","synpixgfqs","sxpfgiyqns","pgyqnssifx","xisyqfnspg","ifnqgspxys","fxsqysgpni","psqsfygxni","fiypxqgnss","fsispnqxyg","ygnxpsfsiq","fpsqgxynis","qigynxspfs","ssyfipqngx","xiypsqgsnf","snsygfxqip","yqgsnifsxp","xyfqsispgn","xgfnypqsis","nypssgqfix","fpiqsxysng","ysxgpnqsfi","ixsgsfpnyq","iqysnfxpsg","sygspnfiqx","gypsisxnfq","ynfsisgxpq","pyiqfgxnss","xpsifgqnys","gsxqyfnsip","fpnsigqsyx","yqsgnfispx","isfyxnqsgp","gqsifxypsn","nfqyxspgis","fipgnsyxsq","pnyfiqsxsg","qiyfnxsgsp","sqsxingfpy","yfsgpnqxsi","qsxgpnyfis","gsyfnxsipq","siyfqnsxpg","pqsxgynsfi","qsisnpgxyf","sxpsigqnfy","ifsxygpsnq","qgnsxisfyp","fqxispsnyg","syqsfgpnxi","spixqfsnyg","xsnifsgpyq","ygisnqpxfs","yspsqxnfig","qxisyngfsp","gsnyqsxifp","yixssnpgqf","psqfxsgyni","sisngpxqyf","qygsisnfpx","sfqsypxnig","sfxniyqpsg","fyispnqxsg","qxfspgisyn","igyssfpqnx","fxgisnpsyq","igspnfxysq","qnysfspigx","ysfinpgqxs","pgyqissnfx","xfgsqpnisy","gxnqysfspi","ysifxqpgns","qnysgspxfi","sgfspixynq","ssnyqpigfx","pgxsiyfnqs","nqxisfsgpy","sqpxfiygns","pxgsisqnfy","pyqssnfixg","pfsisygqxn","npyxsfgqsi","syqgsxipnf","inqyfssgxp","xsgnqfsiyp","qifnsxsgpy","nisqgxysfp","fsyxsnpgiq","xsfnypqgis","siqpngsxyf","xnpfsysiqg","xyngqpfsis","xspqgsfyin","ysxiqfpnsg","fpgsyqxisn","pqgxisfnsy","sqixnfpsgy","gsfiqspnyx","nsyxgpqsfi","xisgsqpfny","yngqxfsips","qsgfpsyxin","qfgnsxspiy","fsqxipnsyg","gxfsqsipyn","sfnqipyxgs","gifqxypssn","nisgsqxfpy","xnpisqsfgy","gxnspifysq","fiqsgsnxpy","xyfissnpgq","syqfgsnxip","pgsiyfxqsn","iqnfyxgssp","ifspsyxgnq","psnfgsyqxi","gxsspiqnyf","ygipsfsnqx","gxsqspyifn","gqsifxypns","ifgspxsyqn","ypgsixqnsf","gxpsisqnfy","nssxfiqgpy","sysfixgqpn","sgfnxsyqip","psxsfygqni","psyqxifgsn","qxnfspyisg","qsspixngfy","gxpsqsifyn","xfisqpngsy","yxsfingpqs","gsqfpxnsiy","xigsnpqsyf","gnisqxyfsp","fxgpinssyq","gyssxiqfnp","ygfispsqxn","fsgxnqsiyp","sqsfxgnyip","npiyqssfgx","iyxqgpsnsf","sxpyqfigsn","gqixynssfp","isxnsygpqf","qinpxsyfsg","ifpsgqyxns","sngfyspxiq","pqyigsxnsf","gxfpqissny","nqigxsspyf","synfpxiqgs","infpqxssgy","gipnfsxyqs","nsiyfsqpxg","niyxspqfgs","iqgsynfpsx","xfspsiygnq","gqinyxssfp","pngxssyqif","yssnxiqpgf","isfgnqpyxs","sspqyfnigx","syxigqnpfs","gnqssypifx","xifpygnssq","snipysgxfq","qsgispnfxy","xfnqypgssi","fpsxgiyqns","gqyxssfpin","nsygpxfsqi","fsqxpniygs","nsyiqsgxpf","sfnyspqigx","yssfqxignp","ixfpgsnqys","yfsixpgqsn","sinfsxpgqy","fxigspnsyq","psxsfyiqng","nsygxqspif","gssqypixnf","ifspgyxsnq","xsysiqfpng","sqgyixfspn","pysfqsxign","fnyssxpgqi","nysgpxfsqi","xfnqyigssp","ypixnfsgsq","sqyfsxpign","fsxqnyigsp","fnyxisqspg","ypnxgfqssi","qspnfixgys","qgspiyxsfn","fsqyxpigns","ypixnsfqgs","sqsginxfpy","pynfsisxqg","pgqfxssyni","snsgixqfpy","qysgnfispx","qispsxgnfy","nsgpxisqfy","sngixpsyfq","gyfqxispns","isxnpgqsyf","sxnypsqigf","sixnsyqpgf","snqxfygips","fsqsnpyxig","qxfnsisgpy","sgxsiyfnqp","snfiqyxpgs","iqsfyxgsnp","inpsxfqgsy","yiqspxgnsf","pqsyifsxgn","yixfsqsgnp","nypsixgfqs","psxyfsngiq","fxqingypss","sgfqsixynp","ixpqnssgfy","iyxssfgqnp","pxsnqgsiyf","ifnssyqgxp","nxgfsyipqs","fngixpsysq","gyqxssnpif","ifnsxgspqy","gnspxyiqsf","fsxipnysgq","yfiqxsnpsg","ipfyssqxng","ypqfinxgss","pssqfyingx","sfxpsqiygn","fpssnixgyq","npssxgfqyi","xsnfysiqpg","gsiqpynsxf","qxfsgpisyn","nsgsixpfqy","nixpsfyqgs","gysnxispqf","fiqssgnxpy","qisnygpfxs","qigspfsxyn","fxqsngysip","xsqgfiynps","sfyqsgpnxi","fspqignxsy","qfngsxsyip","psqnfyxgsi","xnissgyqpf","ifgnypsqxs","nsgspxqiyf","sinfsxqgpy","nxifsypqsg","iyngpxsqsf","sfqipyxsng","xpingyfqss","fipsxqsnyg","nsgpxisqyf","sgnspxqiyf","qsxgpnsfiy","snypqsgixf","gniyqxsfsp","igxnsfpqsy","gqnfsyxisp","isxnygpfsq","xygsisnfpq","pxnisfgsyq","fspixyqgns","xynfsispqg","spqsnfxiyg","fsyipxgqsn","iqgfnspxys","qinfxypgss","iqgsyfpnxs","fsxqynigsp","insysfpqxg","fygipxqssn","nsigsqfyxp","fpsynixgqs","gifqxypnss","nixpysfsgq","qnissgpxyf","gyspnsxfiq","pfyxgqnsis","sfypxnsiqg","pqfxgynssi","fgisnypxqs","issfpxgynq","ysfsqgxipn","xfqngsisyp","sfnqipyxsg","syxfgnpiqs","pnsfixgysq","fiynsqgpsx","siqxygfpsn","gfxisqypns","nfqxipssyg","iqpnygxsfs","xspsqynfig","gyxqsinpfs","igqnyfspxs","nsxysfgqip","sngsqpyixf","gssnxiqpyf","qgnixssfyp","qxpnsfigys","qissngpxyf","xfinypssgq","pqfisyngsx","qnpsxsgfyi","fiyssxpgqn","gfpsqixysn","iynsgqfxsp","fxginsspyq","issgqfnpxy","ysipfqngxs","xysgnfispq","siqxpgnyfs","gsyfxnsipq","xnfpysgsiq","ssyqnipxgf","ysxqpginfs","sgsnypfqix","qpfsgyxisn","inqfsxpsyg","ssfxnqgiyp","nsiqxsgfyp","fsxpnsgqyi","fgxspiyqns","sfxpqinsyg","npsxqfygsi","gyixsspqfn","nsfpxgqsyi","sxsginqfpy","ixssqngypf","ixpgssqynf","gixqfsypns","sixnsyqpfg","ypgsfxnsqi","isqxypsfng","xqisyfgnps","pngfiyqsxs","sixypsqfng","sfypxiqsgn","ifnpygqsxs","fsspxngyqi","qxgspfsiyn","gfnisyqspx","npgxifsyqs","ixsqnygfsp","qxinfyspsg","nxpiqysfsg","ifxsqgysnp","xnqisgspyf","sqigfsyxpn","nsxypsfiqg","isxgnqfyps","fpsxsnygqi","pyiqsxgnfs","fgsnypxqis","qnysfspxgi","nxpgqysfsi","xsqyipsfgn","nixpsyfqgs","fpsixsqyng","gypsfsxniq","spnxqyisgf","sxfqisyngp","sixsynpgqf","pqsgsfiynx","sqigsxfnyp","xqypsgsfin","syfiqnxspg","qiysgxfpsn","pisfnqsgxy","fsxpqinsyg","yfsxnsgipq","fxqgnpiyss","pqyfsnisgx","yisgnfqspx","nxyqfpgiss","qfgnpsxiys","fpgqnxsiys","iysnfqgpsx","pgnsiyfxqs","gnqyssipxf","spfiqyxngs","siygfxqnps","sgxiqsnpfy","ngqsyxsfpi","yssxqgipfn","fiqsnygsxp","sypnfxisqg","qigfsxspyn","synfisxqpg","gfqpysxsni","fpginsqxys","pssfxqygin","sfqipxysng","fqissxygnp","sfqxipnsyg","fsnyixgqsp","nqyissfxpg","qnisgspxfy","isxysfgqnp","pqgfxyssni","piyfqnsxsg","syiqnfpxgs","sfnpsyqigx","xsspgfniyq","nqspxfsyig","ipqssyngfx","sqigfysxpn","nigyfqpsxs","nifyqpsxsg","iqnfgspxys","gfnpsiqyxs","psxysqfngi","sygxpfnqsi","ixnqfgysps","ifnspyqgxs","nqpifsgyxs","fgisspynqx","gyxpissqfn","xqsnifgpsy","fnyqxgisps","fpiqsgynxs","fgsqxypisn","nyixfspgsq","gfqpysxnis","nspysigfxq","ysgpqnxsfi","ipsxsfnqgy","gxsnqpsiyf","nyxfsispqg","pnysiqsxfg","gssfqxiynp","sqfsxgpiyn","pfigsnsqxy","qxispgsyfn","sysfinxqpg","siyxfngpqs","iqpgnsyxsf","spixqsfnyg","fsnqixgysp","sgiqnfpxys","yfspigxsqn","yfgixpsnsq","sxqnpgsyif","pgsfyixqsn","sgynisqfpx","xfinqsgspy","fiqxpgssny","gypqsifnsx","iqyssfpgnx","fqypgsnxsi","ngiqpssyfx","xisqsfpgyn","fxqsngypis","fypxgsqnsi","npyxqissfg","sipgfsyqxn","nqssypgifx","ipssxyqfng","xpfgysnqsi","xspfgiysnq","ixqyfnsspg","qsxipnyfgs","ssyxngfiqp","spsynqfxig","fqgyssnixp","fgyipssxnq","qsfipnyxgs","siqpfgsxyn","fpqsgyxisn","fgqsspynix","ifpqsnyxgs","gyxpfssqin","nspqyfsigx","qgsxfpysni","yspnqgsxif","pnsqfgxyis","yfsnxiqpgs","pgxyssfqni","xfsgpnsyqi","yxfgpnqiss","ixngpysfsq","sgpnfisqxy","xspigsfyqn","gipxfsnyqs","xpqngsisyf","fnigxpsysq","fsqxiynspg","pixnsfqsgy","gfysqipxsn","xgsyinqfps","gsnqxyipsf","pgyissqfnx","ixssnfgyqp","sqsynfpgix","sqixsyfnpg","xfqisgspyn","snsfigxpqy","sngspxqiyf","gnfispxysq","nsyigqspxf","qnipgssxfy","inspqyfxgs","xssfpqygin","fsynqxisgp","fsxgnspqyi","iqssfxgnpy","gfsqpynxsi","nfpgqxiyss","nqgxisfpsy","iqypsnfgsx","syqsgfnpix","pxissygfnq","xyfisgqpns","xniyqgsfsp","nfpsgqyxis","sfnisyqgxp","fiqssgnypx","qnssypgifx","sxnfpqygis","fpgyinssxq","sqsipygnxf","pgxsysnqfi","gnfpxyissq","isxpqfsngy","ygsnifxqps","qsfnygpsxi","ixqgsfpnys","ngiqpyxssf","gxpssifnqy","snyfipqsgx","xsigqnfyps","yfqisgpsnx","sgpnifxsqy","pxgnysfqis","ysqinpsxgf","pinxsqfsyg","pyqxifssgn","nxfgspsiqy","nxpsyqfgis","nyqgfipxss","gxfspsiqyn","sqiyxgnspf","qnfpysgisx","spsynqigfx","sngysfxqip","fyisnqpxgs","nxssqyigfp","ngifsypqsx","xifpysgsnq","signfxypqs","gxfpsisqny","sygnisqfpx","qnysfgpisx","yfqxnsgips","yxfpgnqiss","yfxisspngq","xgynsifpsq","fnyxisgpqs","fpixsqysng","fsxqpniygs","nfqxypssig","psqxfsgyni","npgxsfsyqi","iysxnpfqgs","qsxiynpfsg","fsxipnyqgs","fqsxnyigsp","sqisypxfgn","fsqipnysgx","gifxspnysq","pgxysnqsfi","xnyfgsqsip","xpnysfqsig","fyqnsxpigs","fqyigsnxsp","sqysnfpxgi","fiysxspgnq","sfigsxqynp","gnqxfysips","xyipqnfssg","qspnyifsxg","nxpgissfqy","fnispsgqxy","sypxsqfgin","ynsiqpsgfx","qsygpnxfsi","ysfsnigpxq","qsinspgxyf","xinpgssyqf","ygnispsqxf","xypisqgfsn","gfnyspxisq","sxqfpgsyin","snxyipfsqg","pqfngyissx","ygxfnipssq","syxsifgpnq","sfisxgqnyp","gxpnsyfqis","gssqfixynp","npyfsxgqsi","fgxyspsniq","nqxisfpgsy","ssngiqxpfy","xgqpysfisn","nspsfyigxq","gnxyifspsq","npfqxssyig","qspxyfgisn","ispnfqxgys","sqsypnigfx","qxssypifgn","ifsynsqpxg","qxgnyfspsi","isfpgxnqys","pqyfsnsigx","psynsigxqf","ixsspngyqf","qpnisyfgsx","sqyfnpgsxi","sgnxpyqfis","qyxsifgpns","sysfixnqpg","ypsfxqigns","nisxgqysfp","ssniqpygfx","gsqxsynpif","yssxpgiqfn","siqpngyxsf","psqgfyxnsi","gsifyqspnx","qyssfxgnip","sqpnxfgyis","iqxynsspgf","spfxqinsyg","sipxfsyqgn","nqigpssxyf","fxspgiyqns","qspifygxsn","nxissgqpfy","pxsiygqnfs","nspixfsqgy","xgfiyqpsns","pssfnqigxy","ygsqifxnps","ssgpxinqfy","spgsfxnyqi","ypifngsqsx","qpyigsxnsf","snpqyfsigx","sfixqpgyns","pxsinfyqsg","fgipsnyxsq","qxngyfspsi","fsipxqgnys","yfsixpgnsq","pnyfqssigx","sigxpqnyfs","pqsifgyxns","gxyssiqfnp","psxgiyqnsf","sxynfqgpis","gxfssypnqi","fqgssxpnyi","siyfqsnxpg","gnsxqpsiyf","syqnsxipgf","qspxyfgins","gpxsyiqfns","iqssgxfnpy","yspixfsqgn","qnxisyfgsp","ixnpgssyqf","sfysnqpxgi","sgfpqsxiny","npsxsfygqi","qnfpyigssx","ssigpnqyfx","pqfsgynsxi","xqgypnfiss","ixqyfpssng","siynqsfxpg","xisgnyqpsf","xissgqpnfy","nyfssxgipq","qsygsnxfpi","gipsfsnyqx","fpssqixgyn","fiyxspqsgn","pgxyssfqin","fgsspyxiqn","gpxyisqnsf","pysigxsfnq","fsqpixgsyn","nfpxyissgq","iqnfgysxsp","pnygssqifx","pisgsyxqfn","ifxspgysnq","gfspysxiqn","pxsifgqnys","iyfqsxspgn","spsfiyxngq","piyxqsfsng","iqpnsfxsgy","xissgqpfny","ifnsgqpxys","qispsxgfny","iqnfgyspsx","psyigsqfnx","spiyxgnsqf","xnyigfqsps","snyfpgxqis","sspgfixnqy","qpgynxsifs","gqspinxsyf","snqfispyxg","ispnyqsgxf","qpysgsxnif","xiygnsqfps","iqnsgspxyf","spsqgxifny","snyqgxfspi","iqgfnyspsx","snifqypxgs","gssnxiypqf","sgnpsqyifx","xqynpsfsgi","pqxyissngf","yxgsinfpsq","ixgsyfpnqs","fpginqxssy","ispsngfxqy","spfnigqxsy","qiyfnxgssp","spgfiyxqsn","npqxsfgysi","syfxgnpiqs","fpiqsnysxg","syifgqxspn","fsxnpgqsyi","ygixpsfsnq","xqypssgfin","fxsynipgqs","ysfxnqgisp","gqsifnypxs","nsgypfxqis","nfiyqpsxsg","sqyfpnisxg","fyqgnpixss","gsnpxyiqsf","syiqpgxsnf","xsfspiqngy","sysgiqxfnp","gpifyqssnx","sfiyspqngx","fsqpxngysi","yxsignpfsq","figqxnspys","fsspxqgyin","pgfnqyissx","gnysqpisfx","nxssfyigqp","spsfqxginy","spsyfqnxig","xssyqnfipg","sngyqsfixp","pisqnfxsgy","syqfgsnixp","pfqsygnisx","yqgsinfpsx","gxpqssifyn","nxsfqpgiys","nqyissgxpf","xqfnpigyss","ssifxngyqp","qnyfgpssix","ngpssqfixy","snfpysgxiq","sgxiqsypfn","fiynqssxpg","gfxsqipysn","xiysqgfpsn","ssypqgxinf","snfxqipsyg","xngsqpfisy","isqyngfpsx","fsgnqxsiyp","fnysqxpgsi","sfnxipyqsg","pgxyssnqfi","qnfygpssix","sgqpfxsnyi","fqginpxssy","yfgpqnxiss","fqginsxspy","ygfnqsxpsi","xfpyisnsqg","spigfnsxyq","ynpqixfssg","yfqpgnxiss","giqxfpnyss","pinxqsfsyg","gpxsysnqfi","fpixsqnsyg","ngqifsyxps","psxygnqsfi","spgqifxnsy","qsfnygpsix","pqsisxgnyf","fpqynsisxg","xnyqfpgiss","nfpqyisgsx","pfsixygqsn","pifxygnssq","nyfsixgpqs","pqsisygnxf","fqgxispnsy","fpyqsnisxg","ypxnifsgqs","sgfqpixyns","pynsfqsxig","igxssfpqny","fgqisnspxy","npisqysfgx","iyfgsqpsnx","sgpnfiqsxy","ifpxgqynss","xssfgpyniq","fnyxisqpgs","isxgnqpyfs","iyxsnsqfpg","pxsgsyiqfn","xnipqsgysf","sspnyqigxf","igpsnsqfxy","isfypnqsgx","gspsnifxqy","yngsxfqips","pyngisqxsf","pnyixgfqss","ysfsngipxq","syifnqpxgs","sfxpqyisgn","sgnfpyqxis","pqyfsnisxg","pnysfqsxig","fsspgqxyni","fqyinsgxsp","spngqfyisx","pgyfqxinss","giynpqssxf","yfqissgpxn","nspsgiyfxq","sxpinfyqsg","sxnfpyqgis","qsxiyfpnsg","gnsipysfxq","siqnxgyfps","yfgpxnqssi","xisgsqnfpy","fnsixqpgsy","fqypgssxni","qsgyfixnps","pngfqsysix","sisnqxypfg","siqnsgyfpx","psxgfyqnsi","sgpinyqsxf","ysngfixsqp","fxqspgysin","yssfngpixq","xspyiqsfgn","fqgsixpnsy","xiypfsgsnq","ipyxgsfsqn","yfipxqsgns","yxfspgisnq","pqxyisgnsf","sisfqxgpny","nspxisgqfy","qsinypfsxg","isyxfqsngp","snsqyxgfpi","xnigsfypsq","ssgnxpqyif","ginqsfspxy","xqpnsfgyis","nqygxsspif","ipysnfxqsg","nsxpisqgfy","xyigsqfnps","ixgnyfspsq","fsyqsgixnp","xgifspqsyn","psqnfixgys","isnsgqpxyf","nygssxfipq","gqinysxsfp","nfqsxyspgi","fsysqgxipn","fgxisypqsn","fspyixnqsg","fpsinyqgxs","fysqinspxg","piqynsfsgx","iqsxgsnfyp","pssxyignfq","pyqssnifxg","fsqpignxsy","nqsxgsyfpi","gfnqysxspi","nqsixfpgsy","fsinqsyxpg","ifgpxynssq","pxngsyiqfs","gfyssiqxnp","snsyipfxqg","ysgnsxifpq","psqynigxfs","ygfxpnssiq","inspsyfxgq","nsfgpxqsyi","yfsnigxpqs","yqgfnispsx","fpssnxygiq","xsignqfyps","nssfigxpqy","pynxifssgq","fiypsqgnsx","qisfsxgpny","xgpysnqsfi","fgsqpyxisn","spiysgnxqf","fsgsiqyxnp","sgxqyfnsip","syixgfspnq","pnsfsqigxy","gifyqspxsn","xnypgsisqf","qspfynxgsi","nxpsgqfyis","ipsnxyqfsg","sxpfgiynqs","xiysgqfpsn","xfsngsiqyp","sxqsnfgipy","gfxpyisnsq","pnxgssqyif","nisqxsgfyp","ypsgfnqxsi","qpysnsgxif","piqxnfssgy","snqxfgsyip","ypsgxqfsin","sipgsyxqfn","nsxfyispqg","gqixfpnyss","npsifqygxs","isgnqypfxs","ssyxnfgipq","pysqfgxnis","qpisgsxyfn","psqynsfigx","igyqnssxfp","qnsygfpisx","gysqspxifn","xspyinsfgq","pnyfssqigx","ixspqgfnys","fqysxspgni","qnypisfgxs","pqgyissnxf","qpifsxgnsy","xfisqgnpsy","iqpnfsxgys","xinpgsysqf","spxgqfiysn","qsgfxsypin","psnygsfqxi","qiynsgspxf","fpsinyxgqs","qxsnysfgip","psfnqsigxy","pxsqgiynfs","nfxsgyspqi","ypsgniqfxs","ifsgqsnpxy","yfpgixqssn","sspxyfginq","pxsqginyfs","iynqgfpssx","fsxiqypnsg","pgqiysxnfs","fxgpsnisyq","sxypqfigns","xqygpnfiss","sqgyixpsfn","nigfxsypsq","giysqfpsxn","qspgynxfsi","pqsfnisgxy","qngisxspyf","qnyssgpixf","sfgpxnqysi","isxgqfsnpy","pgyinsfxqs","ygnxpfssiq","gifxqpnyss","ynfsxiqspg","gyisnsxfpq","gxqnfysips","psyxsnfgiq","fpsqignsyx","ixsfqgpnys","gpyxisfnqs","gxpyfsnsqi","piysfxgqsn","ixfssngpyq","sigqnfpxys","ipxngyfqss","nifgxspqys","sgxnyfspqi","sinygfpsqx","qiyfnxpgss","yqpixfngss","ynxsigqpsf","fxipqsgsny","ifspngxysq","fxyingspsq","pgnyisqxsf","syqfgnpixs","yfgissqpxn","xqysfpigns","fiynxsgqsp","xqsniyspgf","fpgynsqsxi","spyxisfnqg","nspsgyifxq","xyfissngpq","ysngifxsqp","gfypqsxsni","npssygfqxi","xypfqssign","nypsifgxqs","xsyginsfpq","yqsxpisfgn","qfpngxissy","sfygxpniqs","fiyqxpgnss","npsxsfgyqi","xpfnisgsqy","ixyqnssgfp","xynssgiqpf","qxfpsisgny","fsqipxysng","sqnspixyfg","pysiqfsxng","spignfsxyq","fxsynpigqs","gsnspxqiyf","snfisyxpgq","pyxqnfsigs","pfxnsygiqs","ysqinpfxgs","xnpsiqsfgy","fsyqsgxinp","gsiyxqsfpn","snqspfxiyg","gqisynspfx","gsspqinyxf","yfisxqpgns","qssgipfynx","sfipqxgyns","sfxnsqyigp","pxqnfgissy","yssgixqpnf","snqsxfgipy","isxyqfsnpg","nqspfigysx","ygnispfqxs","pnyqisfgxs","pngsiyqfxs","xpqsgnisyf","xipgqysfsn","fqysnsgxip","gysnpsxfiq","qgisnypxfs","fxgpnssiyq","yginpssqxf","gqsifpyxns","xspsgqfyin","gfiqxypssn","gnysqxisfp","qsinxsgfyp","sgfqxsynip","igxsyfqspn","xiygfsqnps","sxfpqigsny","nqsixfgpsy","gsfxsynpiq","ypxqgfsins","fnypgixsqs","psxnfiqgys","npfysqgsix","ypgqxsfins","fpsnigqsyx","nsgypfxsiq","xsgsifpnqy","qigfpssxyn","xyqgnfisps","pssiyxgnfq","ygsqixnsfp","pixnsyqsgf","iqsnygpfxs","pxynfgissq","yxsqpginfs","sfxiqypsgn","spxfiysngq","ifxspgqsny","spsxqyingf","nigfsxypsq","yxfnsgpsiq","gsyqspixnf","ysxginqsfp","sfxnsgyiqp","xyigsfnpsq","ixsqgsnfyp","sqxisypgnf","nyixpfsqsg","sxpfgiysnq","qsfpxngysi","sgpqifxnsy","pnyxsifqsg","nfpxqsgsiy","iqfgpnyxss","fpgxnqsiys","fgyssipxnq","fgqsnxypis","sqyfpxngsi","pyqnifsxgs","ipsnfyqgxs","infspsgqxy","sqfgniypxs","gqyinsspxf","ixspfgqnys","ixsgpynfsq","npxssyfiqg","pqgnfixyss","fqigssyxpn","sqgpixyfsn","fxnyqgspsi","yisqgxnpfs","qigfxsspyn","yfgnisxpqs","sfnpxiqsgy","fxyiqgpnss","iyxsnsfqpg","gissfxynqp","fxsiqgpnys","syqpfnixsg","gfxypisnsq","iqgsynspfx","fyqpsnsgxi","fnyxisqgps","siyxqgfpsn","npfxigsyqs","pynxifsgsq","gqxyispnsf","fixqpsnygs","qixsfgysnp","gqssinpxfy","insqxsgfyp","gsspfinyxq","npissyfxqg","pfyqissngx","iqpnyfxsgs","gqxniyspsf","xsyifqpgsn","nigsspqfxy","ygqxspfsin","xqgniyspsf","xpqnfsyisg","ipxssfgqny","fsinqsgxpy","ngqissxpfy","ssgypnfiqx","pqgfnsixys","yfqixsgpsn","sgixpnfqsy","spiysxngqf","yxispfnsgq","yngsixfpsq","xgsyiqnfps","ifxnsygpqs","ipsxgfnyqs","gyfxsispnq","sgpnfixsqy","pgqsysxnfi","ysxpqfisgn","nxgqisypfs","sfqipsngxy","xiysqfnspg","nqfigxssyp","ysxgisqpnf","gyxspiqfns","nqfpxssyig","gxqpysfsni","nisyfqpgxs","issypnxfgq","inxysfpqsg","qpsfyisnxg","xsiypngfqs","syqipxgnsf","pqfnsyigsx","sfpxnqygsi","ygfinpsqxs","fxginsqspy","pgiysfqnsx","sgnpfyqisx","pxssyignfq","nyixsspgfq","fnisxpsyqg","xgnyisqpsf","psqynifsgx","pgiqsxynfs","sfxisypgnq","iyngpxsfsq","syfqxispgn","fgysxpnqis","fiygsxqnps","yqgfnissxp","pqnisyfgsx","qnssxpgify","ysngfxispq","iqnsxpfsgy","qpgfiyxssn","sqgnfixyps","xssfqnyipg","fsqgyispnx","qsgfxsipyn","qnyxpgfssi","synfqxpsig","sypnixgfqs","nqysfixspg","synpgxsiqf","sxpiygqnfs","ngqxyssfpi","gissfxypqn","ifsnygpsxq","igsfysqnpx","qsisngpxyf","sqfgyipxns","infyssqxpg","inysgfpsqx","gqyfnxisps","pfynsgsqxi","sipnfxysqg","ygsxpinfsq","ypqfgnxiss","ssqifygpnx","siygnxqfps","sisnyfgxpq","xsqiyfnpsg","pgixsfsnqy","qnypisxgfs","issqxpfnyg","gnsxpysfiq","yqfnsgpsix","finssyqgxp","nisfqgpsyx","ypgqxfsins","gfyssipxnq","yfsipxgqsn","gynsxiqsfp","xsgyiqnfps","xnypgsqsif","pisfgynqsx","gfxsypisqn","nsgpxiqsyf","fsyipxngsq","fxynisqpgs","gsqyfsnpix","gssnypfixq","spxfqsginy","sqfspixyng","ifgpxysnsq","gsyqsfixnp","ngyssipfqx","npsqxsfgiy","gpyxisfsqn","gsipysxqfn","issnygpfxq","qigsspnfxy","sgsqfixynp","fpgxqinsys","ynxgisqpsf","ysgsfxnpqi","sngyqsxifp","inxpsqfsgy","sgsqxfnypi","sgqnyfspxi","fpsigxynqs","pyxgisqnsf","iqsxgfnyps","qsgnfixyps","xyfpiqssng","sqysnfxpig","fnsxipsqyg","fpyxsqnsig","pgqysfinsx","fsxipygqns","insgyqfsxp","sixgpqnyfs","fsynxsgqip","fspiqxysng","xnisqgfpsy","siqfpgnysx","sxfspgiqyn","psigqsxfny","nqyisspxfg","synsgqfxip","xssfqnypig","xyqpsgsnfi","xnpfsqsiyg","fqsgxypisn","ssgxnqfiyp","xypisqsfgn","fspxiynqsg","pnxgsyiqfs","qpxnifsgys","fxyinsspgq","fsynqisxpg","sqypxsgfin","yxsgpinfsq","yixfsqspgn","fsqpxignys","niqfxspysg","ssxnqfiypg","gsyinqspxf","qpfysgnsix","sngypfxqis","pnxyfssgiq","ixsqgynfsp","iyxsfpnqgs","gxnsfipysq","sxpgqfiysn","nisyfxpgqs","fypsxqsnig","gnpssifxqy","sqxsypifgn","yginpsfqxs","ngsqpyxisf","xspsnfyqig","fpsixyqgns","iqsfyngsxp","igsqnpxfsy","nfpxyisgsq","sxypqfigsn","fssxiynqpg","pyqsifsxgn","siyxspqfgn","gqipsnxsyf","sfxnsqiygp","pxsqyignfs","xsnispqgyf","psnyigqxsf","ygfxnipssq","qgxsnisfyp","ssiqpgxynf","isfsngpxqy","qxfingypss","pxigqssfny","xisqnfpsgy","fiqspgnysx","sfynsgpqxi","psnysqfxgi","infpqxsygs","qxnifsypsg","sgxsypifqn","igyqnsxsfp","pqsgifsynx","fnyxispgqs","fiqynsgsxp","xqsnifspgy","nyqsfipxsg","fisnpgqxys","fqgsyxpnsi","pisgsqxfny","xngsqfsiyp","gpifxqssny","qxfgyipnss","nigqsxysfp","pfysixgqsn","pnyxsgfqsi","fpgsqyxisn","psyfqnsigx","iyxsnpfqgs","fsnisyqgxp","sngxipsyfq","nsigsqfpxy","qxinysgfsp","pxsisnyfgq","gyspfsxniq","spxfsyignq","ynisfgsqpx","pgyisqsfnx","ixsqnfgysp","pnysfxsgqi","ysfsqgxinp","qfysnsgxip","yxfpgnsisq","gqsyfnsxpi","nsqxypsfig","ssyxngfipq","spnsqfyigx","fgsqysxpni","spqfisxgyn","xsgsinpfqy","sfxysqipgn","ixsgyqfsnp","spnsygfqxi","qiynpgssxf","nspsfiygxq","xiqsgpfsyn","psqyfigxns","ginypqssxf","qfpnsgixys","sspxnfgiyq","qixfnypgss","fpsqnixgys","fpsyxqigns","gxssfypnqi","fgispnyxsq","yfspxqgisn","fpssgxyniq","gqsxfpyins","sqsynpfgix","isfgpxqsyn","gysspxfniq","qsypgsxifn","ngqfsspyxi","ifsgnsqpxy","sgpxsqfyin","ygixpnsqsf","sqysnfxpgi","npsfxyqgis","fgqiysxnps","gfspysxnqi","isfpqxsngy","gspsqinyxf","iqsgynfsxp","fqnspixysg","qspgfyixsn","syixpfnqsg","psqyngfisx","sfxpyisngq","qpysgsxifn","nsspxgyqif","iqnpyxgssf","xgsinpfsyq","gysipxsfnq","npxyssfiqg","npsifyqgxs","qnysifgspx","insyfqsgxp","sfxypgsqin","fqypgsxsni","gfnyspxqsi","pgyqxfisns","nygiqpsxfs","pfysgxiqsn","pysfixgqsn","xiqsnpgsyf","gsypnxfqis","pisnxfqsgy","ysngqxpfis","xyqsnfispg","nfixypssgq","nsqgpxfsyi","fsxynspgiq","gqypnxisfs","isynpqxgsf","xyfisgqnps","fsyipxqgsn","pnyqigfsxs","gxfssipnqy","sgpqifxsny","fpsgqnsyix","iypgnsqxsf","nyfsigxpqs","yqssfxgnpi","ygfpisxqsn","yginssfqxp","spgiyqnxsf","pfqsyingsx","ysnqxgipsf","sngsxpqyif","sigpnxqyfs","ysniqsxfgp","gsinpyqsxf","nigfsxysqp","nfyigqxssp","qngfsxspyi","gnqsiypsfx","fsngiyqxsp","xqspigfnys","igynsfpqsx","pisfqyngsx","pxisgysfnq","xspfsiygnq","psyixqfgsn","sfxnqgyisp","ysxpnsgifq","gpxsyiqsnf","sipgnxqyfs","spginxsyfq","yspgqxnfis","xgqsfypisn","ngqissfpxy","ygpsnsqfxi","spxnsfgqiy","gyqnxispsf","fxisqnsgyp","gqssfxypin","psnfyigqxs","qxgfyipnss","ysfnqsxpgi","fgqsspxniy","ygpfisxqsn","fsgyixnqsp","qspgyfixsn","gxpfnysisq","fnyqxpgiss","pqisgysfnx","qyifsxgnsp","psnfgiyqxs","ypfgxqssin","iqxsfgysnp","fpgsnsqxyi","sisnpfgxyq","xspsnfqyig","qssyipfngx","pqfgyisnsx","gysifqpsxn","gnxsqpsiyf","qnssixfpyg","sqfnxgysip","yfspsixgnq","qsinsgpxyf","ynfqisgxps","nsisxpqgfy","gxfpnysisq","fsynqxsigp","fgxsypisqn","yixfsqgsnp","qsxfpnsyig","fiqsgsnpxy","gssqypfixn","xssfpnqiyg","qygfpssxin","snpgfisqxy","ssfpqgxiny","gfxysipnsq","sngpqsyixf","sigpnxsyfq","spsxyinfqg"};
    int l = LEN_M(s);

    printf("%d.\n", numSimilarGroups(s, l));
}

#include "./837_new_21_game.h"
void test()
{

    // printf("%lf.\n", new21Game(0, 0, 10));
    // printf("%lf.\n", new21Game(0, 0, 2));
    // printf("%lf.\n", new21Game(1, 0, 2));
    // printf("%lf.\n", new21Game(10, 1, 10));
    // printf("%lf.\n", new21Game(6, 1, 10));
    // printf("%lf.\n", new21Game(21, 17, 10));
    // printf("%lf %lf %lf.\n", new21Game(21, 17, 10), new21Game_1(21, 17, 10), new21Game_2(21, 17, 10));
    // printf("%lf %lf %lf.\n", new21Game(9632, 6575, 5602), new21Game_1(9632, 6575, 5602), new21Game_2(9632, 6575, 5602));
    // printf("%lf.\n", new21Game(9301, 9224, 7771));
    // printf("%lf %lf.\n", new21Game(9301, 9224, 8881), new21Game(9301, 9224, 8881));

    printf("%lf.\n", new21Game_2(9301, 9224, 8881));
}

#include "./689_maximum_sum_of_3_non-overlapping_subarrays.h"
void test()
{
    int m[] = {2, 1, 2, 1, 2, 6, 7, 5, 9, 10, 1}; int k = 3;
    int l = LEN_M(m);

    int rs = 0;
    int* r = maxSumOfThreeSubarrays(m, l, k, &rs);
    out(r, rs);
}

#include "./803_bricks_falling_when_hit.h"
void test()
{

    int m[] = {1, 0, 0, 0, 1, 1, 0, 0}; int c = 4;
    int h[] = {1, 1, 1, 0};

    int m[] = {1, 1, 1, 1, 1}; int c = 1;
    int h[] = {3, 0, 4, 0, 1, 0, 2, 0, 0, 0};

    int m[] = {1, 0, 1, 1, 1, 1}; int c = 3;
    int h[] = {0, 0, 0, 2, 1, 1};

    int m[] = {0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; int c = 5;
    int h[] = {6, 0, 1, 0, 4, 3, 1, 2, 7, 1, 6, 3, 5, 2, 5, 1, 2, 4, 4, 4, 7, 3};

    int m[] = {1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}; int c = 8;
    int h[] = {4,6,3,0,2,3,2,6,4,1,5,2,2,1};

    int l = LEN_M(m);
    int* cs = malloc(sizeof(int) * l / c);
    for (int i = 0; i < l / c; i ++)
        cs[i] = c;

    int** r = gen_aa(m, l, c);
    int hl = LEN_M(h);
    int hc = 2;

    int* hcs = malloc(sizeof(int) * hl / hc);
    for (int i = 0; i < hl / hc; i ++)
        hcs[i] = hc;
    int** hs = gen_aa(h, hl, hc);

    int ri;
    int* rs = hitBricks(r, l / c, cs, hs, hl / hc, hcs, &ri);
    out(rs, ri);
}

#include "./218_the_skyline_problem.h"
void test()
{
    // int m[] = {2, 9, 10, 3, 7, 15, 5, 12, 12, 15, 20, 10, 19, 24, 8};
    // int m[] = {2, 9, 10, 3, 7, 15, 5, 12, 12, 12, 16, 11, 15, 20, 10, 19, 24, 8};
    // int m[] = {2, 9, 10, 10, 12, 10};
    // int m[] = {0,2147483647,2147483647};
    int m[] = {1,3000,1,2,2999,2,3,2998,3,4,2997,4,5,2996,5,6,2995,6,7,2994,7,8,2993,8,9,2992,9,10,2991,10,11,2990,11,12,2989,12,13,2988,13,14,2987,14,15,2986,15,16,2985,16,17,2984,17,18,2983,18,19,2982,19,20,2981,20,21,2980,21,22,2979,22,23,2978,23,24,2977,24,25,2976,25,26,2975,26,27,2974,27,28,2973,28,29,2972,29,30,2971,30,31,2970,31,32,2969,32,33,2968,33,34,2967,34,35,2966,35,36,2965,36,37,2964,37,38,2963,38,39,2962,39,40,2961,40,41,2960,41,42,2959,42,43,2958,43,44,2957,44,45,2956,45,46,2955,46,47,2954,47,48,2953,48,49,2952,49,50,2951,50,51,2950,51,52,2949,52,53,2948,53,54,2947,54,55,2946,55,56,2945,56,57,2944,57,58,2943,58,59,2942,59,60,2941,60,61,2940,61,62,2939,62,63,2938,63,64,2937,64,65,2936,65,66,2935,66,67,2934,67,68,2933,68,69,2932,69,70,2931,70,71,2930,71,72,2929,72,73,2928,73,74,2927,74,75,2926,75,76,2925,76,77,2924,77,78,2923,78,79,2922,79,80,2921,80,81,2920,81,82,2919,82,83,2918,83,84,2917,84,85,2916,85,86,2915,86,87,2914,87,88,2913,88,89,2912,89,90,2911,90,91,2910,91,92,2909,92,93,2908,93,94,2907,94,95,2906,95,96,2905,96,97,2904,97,98,2903,98,99,2902,99,100,2901,100,101,2900,101,102,2899,102,103,2898,103,104,2897,104,105,2896,105,106,2895,106,107,2894,107,108,2893,108,109,2892,109,110,2891,110,111,2890,111,112,2889,112,113,2888,113,114,2887,114,115,2886,115,116,2885,116,117,2884,117,118,2883,118,119,2882,119,120,2881,120,121,2880,121,122,2879,122,123,2878,123,124,2877,124,125,2876,125,126,2875,126,127,2874,127,128,2873,128,129,2872,129,130,2871,130,131,2870,131,132,2869,132,133,2868,133,134,2867,134,135,2866,135,136,2865,136,137,2864,137,138,2863,138,139,2862,139,140,2861,140,141,2860,141,142,2859,142,143,2858,143,144,2857,144,145,2856,145,146,2855,146,147,2854,147,148,2853,148,149,2852,149,150,2851,150,151,2850,151,152,2849,152,153,2848,153,154,2847,154,155,2846,155,156,2845,156,157,2844,157,158,2843,158,159,2842,159,160,2841,160,161,2840,161,162,2839,162,163,2838,163,164,2837,164,165,2836,165,166,2835,166,167,2834,167,168,2833,168,169,2832,169,170,2831,170,171,2830,171,172,2829,172,173,2828,173,174,2827,174,175,2826,175,176,2825,176,177,2824,177,178,2823,178,179,2822,179,180,2821,180,181,2820,181,182,2819,182,183,2818,183,184,2817,184,185,2816,185,186,2815,186,187,2814,187,188,2813,188,189,2812,189,190,2811,190,191,2810,191,192,2809,192,193,2808,193,194,2807,194,195,2806,195,196,2805,196,197,2804,197,198,2803,198,199,2802,199,200,2801,200,201,2800,201,202,2799,202,203,2798,203,204,2797,204,205,2796,205,206,2795,206,207,2794,207,208,2793,208,209,2792,209,210,2791,210,211,2790,211,212,2789,212,213,2788,213,214,2787,214,215,2786,215,216,2785,216,217,2784,217,218,2783,218,219,2782,219,220,2781,220,221,2780,221,222,2779,222,223,2778,223,224,2777,224,225,2776,225,226,2775,226,227,2774,227,228,2773,228,229,2772,229,230,2771,230,231,2770,231,232,2769,232,233,2768,233,234,2767,234,235,2766,235,236,2765,236,237,2764,237,238,2763,238,239,2762,239,240,2761,240,241,2760,241,242,2759,242,243,2758,243,244,2757,244,245,2756,245,246,2755,246,247,2754,247,248,2753,248,249,2752,249,250,2751,250,251,2750,251,252,2749,252,253,2748,253,254,2747,254,255,2746,255,256,2745,256,257,2744,257,258,2743,258,259,2742,259,260,2741,260,261,2740,261,262,2739,262,263,2738,263,264,2737,264,265,2736,265,266,2735,266,267,2734,267,268,2733,268,269,2732,269,270,2731,270,271,2730,271,272,2729,272,273,2728,273,274,2727,274,275,2726,275,276,2725,276,277,2724,277,278,2723,278,279,2722,279,280,2721,280,281,2720,281,282,2719,282,283,2718,283,284,2717,284,285,2716,285,286,2715,286,287,2714,287,288,2713,288,289,2712,289,290,2711,290,291,2710,291,292,2709,292,293,2708,293,294,2707,294,295,2706,295,296,2705,296,297,2704,297,298,2703,298,299,2702,299,300,2701,300,301,2700,301,302,2699,302,303,2698,303,304,2697,304,305,2696,305,306,2695,306,307,2694,307,308,2693,308,309,2692,309,310,2691,310,311,2690,311,312,2689,312,313,2688,313,314,2687,314,315,2686,315,316,2685,316,317,2684,317,318,2683,318,319,2682,319,320,2681,320,321,2680,321,322,2679,322,323,2678,323,324,2677,324,325,2676,325,326,2675,326,327,2674,327,328,2673,328,329,2672,329,330,2671,330,331,2670,331,332,2669,332,333,2668,333,334,2667,334,335,2666,335,336,2665,336,337,2664,337,338,2663,338,339,2662,339,340,2661,340,341,2660,341,342,2659,342,343,2658,343,344,2657,344,345,2656,345,346,2655,346,347,2654,347,348,2653,348,349,2652,349,350,2651,350,351,2650,351,352,2649,352,353,2648,353,354,2647,354,355,2646,355,356,2645,356,357,2644,357,358,2643,358,359,2642,359,360,2641,360,361,2640,361,362,2639,362,363,2638,363,364,2637,364,365,2636,365,366,2635,366,367,2634,367,368,2633,368,369,2632,369,370,2631,370,371,2630,371,372,2629,372,373,2628,373,374,2627,374,375,2626,375,376,2625,376,377,2624,377,378,2623,378,379,2622,379,380,2621,380,381,2620,381,382,2619,382,383,2618,383,384,2617,384,385,2616,385,386,2615,386,387,2614,387,388,2613,388,389,2612,389,390,2611,390,391,2610,391,392,2609,392,393,2608,393,394,2607,394,395,2606,395,396,2605,396,397,2604,397,398,2603,398,399,2602,399,400,2601,400,401,2600,401,402,2599,402,403,2598,403,404,2597,404,405,2596,405,406,2595,406,407,2594,407,408,2593,408,409,2592,409,410,2591,410,411,2590,411,412,2589,412,413,2588,413,414,2587,414,415,2586,415,416,2585,416,417,2584,417,418,2583,418,419,2582,419,420,2581,420,421,2580,421,422,2579,422,423,2578,423,424,2577,424,425,2576,425,426,2575,426,427,2574,427,428,2573,428,429,2572,429,430,2571,430,431,2570,431,432,2569,432,433,2568,433,434,2567,434,435,2566,435,436,2565,436,437,2564,437,438,2563,438,439,2562,439,440,2561,440,441,2560,441,442,2559,442,443,2558,443,444,2557,444,445,2556,445,446,2555,446,447,2554,447,448,2553,448,449,2552,449,450,2551,450,451,2550,451,452,2549,452,453,2548,453,454,2547,454,455,2546,455,456,2545,456,457,2544,457,458,2543,458,459,2542,459,460,2541,460,461,2540,461,462,2539,462,463,2538,463,464,2537,464,465,2536,465,466,2535,466,467,2534,467,468,2533,468,469,2532,469,470,2531,470,471,2530,471,472,2529,472,473,2528,473,474,2527,474,475,2526,475,476,2525,476,477,2524,477,478,2523,478,479,2522,479,480,2521,480,481,2520,481,482,2519,482,483,2518,483,484,2517,484,485,2516,485,486,2515,486,487,2514,487,488,2513,488,489,2512,489,490,2511,490,491,2510,491,492,2509,492,493,2508,493,494,2507,494,495,2506,495,496,2505,496,497,2504,497,498,2503,498,499,2502,499,500,2501,500,501,2500,501,502,2499,502,503,2498,503,504,2497,504,505,2496,505,506,2495,506,507,2494,507,508,2493,508,509,2492,509,510,2491,510,511,2490,511,512,2489,512,513,2488,513,514,2487,514,515,2486,515,516,2485,516,517,2484,517,518,2483,518,519,2482,519,520,2481,520,521,2480,521,522,2479,522,523,2478,523,524,2477,524,525,2476,525,526,2475,526,527,2474,527,528,2473,528,529,2472,529,530,2471,530,531,2470,531,532,2469,532,533,2468,533,534,2467,534,535,2466,535,536,2465,536,537,2464,537,538,2463,538,539,2462,539,540,2461,540,541,2460,541,542,2459,542,543,2458,543,544,2457,544,545,2456,545,546,2455,546,547,2454,547,548,2453,548,549,2452,549,550,2451,550,551,2450,551,552,2449,552,553,2448,553,554,2447,554,555,2446,555,556,2445,556,557,2444,557,558,2443,558,559,2442,559,560,2441,560,561,2440,561,562,2439,562,563,2438,563,564,2437,564,565,2436,565,566,2435,566,567,2434,567,568,2433,568,569,2432,569,570,2431,570,571,2430,571,572,2429,572,573,2428,573,574,2427,574,575,2426,575,576,2425,576,577,2424,577,578,2423,578,579,2422,579,580,2421,580,581,2420,581,582,2419,582,583,2418,583,584,2417,584,585,2416,585,586,2415,586,587,2414,587,588,2413,588,589,2412,589,590,2411,590,591,2410,591,592,2409,592,593,2408,593,594,2407,594,595,2406,595,596,2405,596,597,2404,597,598,2403,598,599,2402,599,600,2401,600,601,2400,601,602,2399,602,603,2398,603,604,2397,604,605,2396,605,606,2395,606,607,2394,607,608,2393,608,609,2392,609,610,2391,610,611,2390,611,612,2389,612,613,2388,613,614,2387,614,615,2386,615,616,2385,616,617,2384,617,618,2383,618,619,2382,619,620,2381,620,621,2380,621,622,2379,622,623,2378,623,624,2377,624,625,2376,625,626,2375,626,627,2374,627,628,2373,628,629,2372,629,630,2371,630,631,2370,631,632,2369,632,633,2368,633,634,2367,634,635,2366,635,636,2365,636,637,2364,637,638,2363,638,639,2362,639,640,2361,640,641,2360,641,642,2359,642,643,2358,643,644,2357,644,645,2356,645,646,2355,646,647,2354,647,648,2353,648,649,2352,649,650,2351,650,651,2350,651,652,2349,652,653,2348,653,654,2347,654,655,2346,655,656,2345,656,657,2344,657,658,2343,658,659,2342,659,660,2341,660,661,2340,661,662,2339,662,663,2338,663,664,2337,664,665,2336,665,666,2335,666,667,2334,667,668,2333,668,669,2332,669,670,2331,670,671,2330,671,672,2329,672,673,2328,673,674,2327,674,675,2326,675,676,2325,676,677,2324,677,678,2323,678,679,2322,679,680,2321,680,681,2320,681,682,2319,682,683,2318,683,684,2317,684,685,2316,685,686,2315,686,687,2314,687,688,2313,688,689,2312,689,690,2311,690,691,2310,691,692,2309,692,693,2308,693,694,2307,694,695,2306,695,696,2305,696,697,2304,697,698,2303,698,699,2302,699,700,2301,700,701,2300,701,702,2299,702,703,2298,703,704,2297,704,705,2296,705,706,2295,706,707,2294,707,708,2293,708,709,2292,709,710,2291,710,711,2290,711,712,2289,712,713,2288,713,714,2287,714,715,2286,715,716,2285,716,717,2284,717,718,2283,718,719,2282,719,720,2281,720,721,2280,721,722,2279,722,723,2278,723,724,2277,724,725,2276,725,726,2275,726,727,2274,727,728,2273,728,729,2272,729,730,2271,730,731,2270,731,732,2269,732,733,2268,733,734,2267,734,735,2266,735,736,2265,736,737,2264,737,738,2263,738,739,2262,739,740,2261,740,741,2260,741,742,2259,742,743,2258,743,744,2257,744,745,2256,745,746,2255,746,747,2254,747,748,2253,748,749,2252,749,750,2251,750,751,2250,751,752,2249,752,753,2248,753,754,2247,754,755,2246,755,756,2245,756,757,2244,757,758,2243,758,759,2242,759,760,2241,760,761,2240,761,762,2239,762,763,2238,763,764,2237,764,765,2236,765,766,2235,766,767,2234,767,768,2233,768,769,2232,769,770,2231,770,771,2230,771,772,2229,772,773,2228,773,774,2227,774,775,2226,775,776,2225,776,777,2224,777,778,2223,778,779,2222,779,780,2221,780,781,2220,781,782,2219,782,783,2218,783,784,2217,784,785,2216,785,786,2215,786,787,2214,787,788,2213,788,789,2212,789,790,2211,790,791,2210,791,792,2209,792,793,2208,793,794,2207,794,795,2206,795,796,2205,796,797,2204,797,798,2203,798,799,2202,799,800,2201,800,801,2200,801,802,2199,802,803,2198,803,804,2197,804,805,2196,805,806,2195,806,807,2194,807,808,2193,808,809,2192,809,810,2191,810,811,2190,811,812,2189,812,813,2188,813,814,2187,814,815,2186,815,816,2185,816,817,2184,817,818,2183,818,819,2182,819,820,2181,820,821,2180,821,822,2179,822,823,2178,823,824,2177,824,825,2176,825,826,2175,826,827,2174,827,828,2173,828,829,2172,829,830,2171,830,831,2170,831,832,2169,832,833,2168,833,834,2167,834,835,2166,835,836,2165,836,837,2164,837,838,2163,838,839,2162,839,840,2161,840,841,2160,841,842,2159,842,843,2158,843,844,2157,844,845,2156,845,846,2155,846,847,2154,847,848,2153,848,849,2152,849,850,2151,850,851,2150,851,852,2149,852,853,2148,853,854,2147,854,855,2146,855,856,2145,856,857,2144,857,858,2143,858,859,2142,859,860,2141,860,861,2140,861,862,2139,862,863,2138,863,864,2137,864,865,2136,865,866,2135,866,867,2134,867,868,2133,868,869,2132,869,870,2131,870,871,2130,871,872,2129,872,873,2128,873,874,2127,874,875,2126,875,876,2125,876,877,2124,877,878,2123,878,879,2122,879,880,2121,880,881,2120,881,882,2119,882,883,2118,883,884,2117,884,885,2116,885,886,2115,886,887,2114,887,888,2113,888,889,2112,889,890,2111,890,891,2110,891,892,2109,892,893,2108,893,894,2107,894,895,2106,895,896,2105,896,897,2104,897,898,2103,898,899,2102,899,900,2101,900,901,2100,901,902,2099,902,903,2098,903,904,2097,904,905,2096,905,906,2095,906,907,2094,907,908,2093,908,909,2092,909,910,2091,910,911,2090,911,912,2089,912,913,2088,913,914,2087,914,915,2086,915,916,2085,916,917,2084,917,918,2083,918,919,2082,919,920,2081,920,921,2080,921,922,2079,922,923,2078,923,924,2077,924,925,2076,925,926,2075,926,927,2074,927,928,2073,928,929,2072,929,930,2071,930,931,2070,931,932,2069,932,933,2068,933,934,2067,934,935,2066,935,936,2065,936,937,2064,937,938,2063,938,939,2062,939,940,2061,940,941,2060,941,942,2059,942,943,2058,943,944,2057,944,945,2056,945,946,2055,946,947,2054,947,948,2053,948,949,2052,949,950,2051,950,951,2050,951,952,2049,952,953,2048,953,954,2047,954,955,2046,955,956,2045,956,957,2044,957,958,2043,958,959,2042,959,960,2041,960,961,2040,961,962,2039,962,963,2038,963,964,2037,964,965,2036,965,966,2035,966,967,2034,967,968,2033,968,969,2032,969,970,2031,970,971,2030,971,972,2029,972,973,2028,973,974,2027,974,975,2026,975,976,2025,976,977,2024,977,978,2023,978,979,2022,979,980,2021,980,981,2020,981,982,2019,982,983,2018,983,984,2017,984,985,2016,985,986,2015,986,987,2014,987,988,2013,988,989,2012,989,990,2011,990,991,2010,991,992,2009,992,993,2008,993,994,2007,994,995,2006,995,996,2005,996,997,2004,997,998,2003,998,999,2002,999,1000,2001,1000,1001,2000,1001,1002,1999,1002,1003,1998,1003,1004,1997,1004,1005,1996,1005,1006,1995,1006,1007,1994,1007,1008,1993,1008,1009,1992,1009,1010,1991,1010,1011,1990,1011,1012,1989,1012,1013,1988,1013,1014,1987,1014,1015,1986,1015,1016,1985,1016,1017,1984,1017,1018,1983,1018,1019,1982,1019,1020,1981,1020,1021,1980,1021,1022,1979,1022,1023,1978,1023,1024,1977,1024,1025,1976,1025,1026,1975,1026,1027,1974,1027,1028,1973,1028,1029,1972,1029,1030,1971,1030,1031,1970,1031,1032,1969,1032,1033,1968,1033,1034,1967,1034,1035,1966,1035,1036,1965,1036,1037,1964,1037,1038,1963,1038,1039,1962,1039,1040,1961,1040,1041,1960,1041,1042,1959,1042,1043,1958,1043,1044,1957,1044,1045,1956,1045,1046,1955,1046,1047,1954,1047,1048,1953,1048,1049,1952,1049,1050,1951,1050,1051,1950,1051,1052,1949,1052,1053,1948,1053,1054,1947,1054,1055,1946,1055,1056,1945,1056,1057,1944,1057,1058,1943,1058,1059,1942,1059,1060,1941,1060,1061,1940,1061,1062,1939,1062,1063,1938,1063,1064,1937,1064,1065,1936,1065,1066,1935,1066,1067,1934,1067,1068,1933,1068,1069,1932,1069,1070,1931,1070,1071,1930,1071,1072,1929,1072,1073,1928,1073,1074,1927,1074,1075,1926,1075,1076,1925,1076,1077,1924,1077,1078,1923,1078,1079,1922,1079,1080,1921,1080,1081,1920,1081,1082,1919,1082,1083,1918,1083,1084,1917,1084,1085,1916,1085,1086,1915,1086,1087,1914,1087,1088,1913,1088,1089,1912,1089,1090,1911,1090,1091,1910,1091,1092,1909,1092,1093,1908,1093,1094,1907,1094,1095,1906,1095,1096,1905,1096,1097,1904,1097,1098,1903,1098,1099,1902,1099,1100,1901,1100,1101,1900,1101,1102,1899,1102,1103,1898,1103,1104,1897,1104,1105,1896,1105,1106,1895,1106,1107,1894,1107,1108,1893,1108,1109,1892,1109,1110,1891,1110,1111,1890,1111,1112,1889,1112,1113,1888,1113,1114,1887,1114,1115,1886,1115,1116,1885,1116,1117,1884,1117,1118,1883,1118,1119,1882,1119,1120,1881,1120,1121,1880,1121,1122,1879,1122,1123,1878,1123,1124,1877,1124,1125,1876,1125,1126,1875,1126,1127,1874,1127,1128,1873,1128,1129,1872,1129,1130,1871,1130,1131,1870,1131,1132,1869,1132,1133,1868,1133,1134,1867,1134,1135,1866,1135,1136,1865,1136,1137,1864,1137,1138,1863,1138,1139,1862,1139,1140,1861,1140,1141,1860,1141,1142,1859,1142,1143,1858,1143,1144,1857,1144,1145,1856,1145,1146,1855,1146,1147,1854,1147,1148,1853,1148,1149,1852,1149,1150,1851,1150,1151,1850,1151,1152,1849,1152,1153,1848,1153,1154,1847,1154,1155,1846,1155,1156,1845,1156,1157,1844,1157,1158,1843,1158,1159,1842,1159,1160,1841,1160,1161,1840,1161,1162,1839,1162,1163,1838,1163,1164,1837,1164,1165,1836,1165,1166,1835,1166,1167,1834,1167,1168,1833,1168,1169,1832,1169,1170,1831,1170,1171,1830,1171,1172,1829,1172,1173,1828,1173,1174,1827,1174,1175,1826,1175,1176,1825,1176,1177,1824,1177,1178,1823,1178,1179,1822,1179,1180,1821,1180,1181,1820,1181,1182,1819,1182,1183,1818,1183,1184,1817,1184,1185,1816,1185,1186,1815,1186,1187,1814,1187,1188,1813,1188,1189,1812,1189,1190,1811,1190,1191,1810,1191,1192,1809,1192,1193,1808,1193,1194,1807,1194,1195,1806,1195,1196,1805,1196,1197,1804,1197,1198,1803,1198,1199,1802,1199,1200,1801,1200,1201,1800,1201,1202,1799,1202,1203,1798,1203,1204,1797,1204,1205,1796,1205,1206,1795,1206,1207,1794,1207,1208,1793,1208,1209,1792,1209,1210,1791,1210,1211,1790,1211,1212,1789,1212,1213,1788,1213,1214,1787,1214,1215,1786,1215,1216,1785,1216,1217,1784,1217,1218,1783,1218,1219,1782,1219,1220,1781,1220,1221,1780,1221,1222,1779,1222,1223,1778,1223,1224,1777,1224,1225,1776,1225,1226,1775,1226,1227,1774,1227,1228,1773,1228,1229,1772,1229,1230,1771,1230,1231,1770,1231,1232,1769,1232,1233,1768,1233,1234,1767,1234,1235,1766,1235,1236,1765,1236,1237,1764,1237,1238,1763,1238,1239,1762,1239,1240,1761,1240,1241,1760,1241,1242,1759,1242,1243,1758,1243,1244,1757,1244,1245,1756,1245,1246,1755,1246,1247,1754,1247,1248,1753,1248,1249,1752,1249,1250,1751,1250,1251,1750,1251,1252,1749,1252,1253,1748,1253,1254,1747,1254,1255,1746,1255,1256,1745,1256,1257,1744,1257,1258,1743,1258,1259,1742,1259,1260,1741,1260,1261,1740,1261,1262,1739,1262,1263,1738,1263,1264,1737,1264,1265,1736,1265,1266,1735,1266,1267,1734,1267,1268,1733,1268,1269,1732,1269,1270,1731,1270,1271,1730,1271,1272,1729,1272,1273,1728,1273,1274,1727,1274,1275,1726,1275,1276,1725,1276,1277,1724,1277,1278,1723,1278,1279,1722,1279,1280,1721,1280,1281,1720,1281,1282,1719,1282,1283,1718,1283,1284,1717,1284,1285,1716,1285,1286,1715,1286,1287,1714,1287,1288,1713,1288,1289,1712,1289,1290,1711,1290,1291,1710,1291,1292,1709,1292,1293,1708,1293,1294,1707,1294,1295,1706,1295,1296,1705,1296,1297,1704,1297,1298,1703,1298,1299,1702,1299,1300,1701,1300,1301,1700,1301,1302,1699,1302,1303,1698,1303,1304,1697,1304,1305,1696,1305,1306,1695,1306,1307,1694,1307,1308,1693,1308,1309,1692,1309,1310,1691,1310,1311,1690,1311,1312,1689,1312,1313,1688,1313,1314,1687,1314,1315,1686,1315,1316,1685,1316,1317,1684,1317,1318,1683,1318,1319,1682,1319,1320,1681,1320,1321,1680,1321,1322,1679,1322,1323,1678,1323,1324,1677,1324,1325,1676,1325,1326,1675,1326,1327,1674,1327,1328,1673,1328,1329,1672,1329,1330,1671,1330,1331,1670,1331,1332,1669,1332,1333,1668,1333,1334,1667,1334,1335,1666,1335,1336,1665,1336,1337,1664,1337,1338,1663,1338,1339,1662,1339,1340,1661,1340,1341,1660,1341,1342,1659,1342,1343,1658,1343,1344,1657,1344,1345,1656,1345,1346,1655,1346,1347,1654,1347,1348,1653,1348,1349,1652,1349,1350,1651,1350,1351,1650,1351,1352,1649,1352,1353,1648,1353,1354,1647,1354,1355,1646,1355,1356,1645,1356,1357,1644,1357,1358,1643,1358,1359,1642,1359,1360,1641,1360,1361,1640,1361,1362,1639,1362,1363,1638,1363,1364,1637,1364,1365,1636,1365,1366,1635,1366,1367,1634,1367,1368,1633,1368,1369,1632,1369,1370,1631,1370,1371,1630,1371,1372,1629,1372,1373,1628,1373,1374,1627,1374,1375,1626,1375,1376,1625,1376,1377,1624,1377,1378,1623,1378,1379,1622,1379,1380,1621,1380,1381,1620,1381,1382,1619,1382,1383,1618,1383,1384,1617,1384,1385,1616,1385,1386,1615,1386,1387,1614,1387,1388,1613,1388,1389,1612,1389,1390,1611,1390,1391,1610,1391,1392,1609,1392,1393,1608,1393,1394,1607,1394,1395,1606,1395,1396,1605,1396,1397,1604,1397,1398,1603,1398,1399,1602,1399,1400,1601,1400,1401,1600,1401,1402,1599,1402,1403,1598,1403,1404,1597,1404,1405,1596,1405,1406,1595,1406,1407,1594,1407,1408,1593,1408,1409,1592,1409,1410,1591,1410,1411,1590,1411,1412,1589,1412,1413,1588,1413,1414,1587,1414,1415,1586,1415,1416,1585,1416,1417,1584,1417,1418,1583,1418,1419,1582,1419,1420,1581,1420,1421,1580,1421,1422,1579,1422,1423,1578,1423,1424,1577,1424,1425,1576,1425,1426,1575,1426,1427,1574,1427,1428,1573,1428,1429,1572,1429,1430,1571,1430,1431,1570,1431,1432,1569,1432,1433,1568,1433,1434,1567,1434,1435,1566,1435,1436,1565,1436,1437,1564,1437,1438,1563,1438,1439,1562,1439,1440,1561,1440,1441,1560,1441,1442,1559,1442,1443,1558,1443,1444,1557,1444,1445,1556,1445,1446,1555,1446,1447,1554,1447,1448,1553,1448,1449,1552,1449,1450,1551,1450,1451,1550,1451,1452,1549,1452,1453,1548,1453,1454,1547,1454,1455,1546,1455,1456,1545,1456,1457,1544,1457,1458,1543,1458,1459,1542,1459,1460,1541,1460,1461,1540,1461,1462,1539,1462,1463,1538,1463,1464,1537,1464,1465,1536,1465,1466,1535,1466,1467,1534,1467,1468,1533,1468,1469,1532,1469,1470,1531,1470,1471,1530,1471,1472,1529,1472,1473,1528,1473,1474,1527,1474,1475,1526,1475,1476,1525,1476,1477,1524,1477,1478,1523,1478,1479,1522,1479,1480,1521,1480,1481,1520,1481,1482,1519,1482,1483,1518,1483,1484,1517,1484,1485,1516,1485,1486,1515,1486,1487,1514,1487,1488,1513,1488,1489,1512,1489,1490,1511,1490,1491,1510,1491,1492,1509,1492,1493,1508,1493,1494,1507,1494,1495,1506,1495,1496,1505,1496,1497,1504,1497,1498,1503,1498,1499,1502,1499,1500,1501,1500};

    // int m[] = {1, 2, 4, 1, 3, 5, 1, 1, 3};
    int l = LEN_M(m);
    int c = 3;

    int r = l / 3;

    int** b = gen_aa(m, l, c);

    int rs = 0;
    int** ret = getSkyline(b, r, c, &rs);
    outaaa(ret, 2, rs);
}

#include "./699_falling_squares.h"
void test()
{
}

#include "./273_integer_to_english_words.h"
void test()
{
    // 1000000 error
    printf("%s.\n", numberToWords(1234567811));
    printf("%s.\n", numberToWords(1000));
}

#include "./639_decode_ways_II.h"
void test()
{
    char* s = "*";
    printf("%s is %d.\n", s, numDecodings(s));
    s = "**"; // should be 96
    printf("%s is %d.\n", s, numDecodings(s));
    s = "1*";
    printf("%s is %d.\n", s, numDecodings(s));
    s = "*1";
    printf("%s is %d.\n", s, numDecodings(s));
    s = "204";
    printf("%s is %d.\n", s, numDecodings(s));
    s = "**********1111111111";
    printf("%s is %d.\n", s, numDecodings(s));
    s = "1*1*22*19";
    printf("%s is %d.\n", s, numDecodings(s));
}

#include "./564_find_the_closest_palindrome.h"
void test()
{
    char* s = "123";
    printf("%s.\n", nearestPalindromic(s));

    s = "99";
    printf("%s.\n", nearestPalindromic(s));

    s = "100";
    printf("%s.\n", nearestPalindromic(s));

    s = "102";
    printf("%s.\n", nearestPalindromic(s));

    s = "989";
    printf("%s.\n", nearestPalindromic(s));

    s = "1000";
    printf("%s.\n", nearestPalindromic(s));
    s = "1002";
    printf("%s.\n", nearestPalindromic(s));

    s = "2002";
    printf("%s.\n", nearestPalindromic(s));
    s = "1";
    printf("%s.\n", nearestPalindromic(s));

    s = "10";
    printf("%s.\n", nearestPalindromic(s));
    s = "998989898128912819";
    printf("%s.\n", nearestPalindromic(s));
    s = "999999999999999999";
    printf("%s.\n", nearestPalindromic(s));

    s = "987";
    printf("%s.\n", nearestPalindromic(s));

    s = "1837722381";
    printf("%s.\n", nearestPalindromic(s));
    s = "807045053224792883";
    printf("%s.\n", nearestPalindromic(s));
}

#include "./233_number_of_digit_one.h"
void test()
{
    int n = 13;
    printf("%d %d.\n", countDigitOne(n), countDigitOne_1(n));

    n = 1;
    printf("%d %d.\n", countDigitOne(n), countDigitOne_1(n));

    n = 18;
    printf("%d %d.\n", countDigitOne(n), countDigitOne_1(n));

    n = 100;
    printf("%d %d.\n", countDigitOne(n), countDigitOne_1(n));

    n = 11111;
    printf("%d %d.\n", countDigitOne(n), countDigitOne_1(n));

    for (int i = 100000; i >= 0; i --)
        if (countDigitOne(i) != countDigitOne_1(i))
            printf("%d is %d and %d.\n", i, countDigitOne(i), countDigitOne_1(i));
}

#include "./286_walls_and_gates.h"
void test()
{
#define INF 2147483647
    // int m[] = {INF, -1, 0, INF, INF, INF, INF, -1, INF, -1, INF, -1, 0, -1, INF, INF};
    // int m[] = {INF, -1, 0, INF, INF, INF, INF, -1, -1, -1, -1, -1, 0, -1, INF, INF};
    int l = LEN_M(m);
    int c = 4;
    int r = l /c;
    int** i = gen_aa(m, l, c);
    wallsAndGates(i, r, c);
    outaaa(i, r, c);
#undef INF
}

#include "./600_non-negative_integers_without_consecutive_ones.h"
void test()
{
    int n = 8;
    printf("%d : %d.\n", n, findIntegers(n));

    n = INT_MIN;
    printf("%d : %d.\n", n, findIntegers(n));

    n = INT_MAX;
    printf("%d : %d.\n", n, findIntegers(n));
    // n = 6;
    // printf("%d : %d.\n", n, findIntegers(n));
    // n = 100;
    // printf("%d : %d.\n", n, findIntegers(n));
    // printf("%d : %d.\n", n, findIntegers_2(n));
    // printf("%d : %d.\n", n, findIntegers(n));
    // printf("%d : %d.\n", n, findIntegers_2(n));

    int pt = 0;
    for (int i = 0; i < 999999839; i ++)
    {
        pt = findIntegers_2(i, pt);
        if (findIntegers(i) != pt)
            printf("i is %d %x %d %d.\n", i, i, findIntegers(i), findIntegers_2(i, pt));
    }

}

#include "./351_android_unlock_patterns.h"
void test()
{
    // int m = 1; int n = 1;
    printf("%d.\n", numberOfPatterns(1, 1));
    printf("%d.\n", numberOfPatterns(2, 2));
    printf("%d.\n", numberOfPatterns(1, 2));
    // printf("%d.\n", numberOfPatterns(1, 2));
    // printf("%d.\n", numberOfPatterns(3, 3));

}

#include "./840_magic_squares_in_grid.h"

#include "./841_keys_and_rooms.h"
void test()
{

    // int m1[] = {1};
    // int m2[] = {2};
    // int m3[] = {3};
    // int m4[] = {};

    // int m1[] = {1, 3};
    // int m2[] = {3, 0, 1};
    // int m3[] = {2};
    // int m4[] = {0);

    int m1[] = {1, 3};
    int m2[] = {1, 4};
    int m3[] = {2, 3, 2, 4, 1};
    int m4[] = {};
    int m5[] = {4, 3, 2};


    int* m[] = {m1, m2, m3, m4, m5};
    int l[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4), LEN_M(m5)};
    printf("%d.\n", canVisitAllRooms(m, LEN_M(m), l));
}

#include "./842_split_array_into_fibonacci_sequence.h"
void test()
{
    // char* s = "123456579";
    // char* s = "1101111";
    // char* s = "011235813213455";
    // char* s = "11235813";
    // char* s = "0123";
    char* s = "1011";
    int rs;
    int* r = splitIntoFibonacci(s, &rs);
    out(r, rs);
}

typedef struct {
    char* a[100];
    char* s;
    int max;
} Master;

bool _has_str(Master* a, char* x, int l)
{
    for (int i = 0; i < l; i ++)
    {
        if (!strcmp(a->a[i], x))
            return true;
    }
    return false;
}

int guess(Master* m, char* x)
{
    char* a = x;
    char* b = m->s;
    int t = !!(a[0] == b[0]);
    t += !!(a[1] == b[1]);
    t += !!(a[2] == b[2]);
    t += !!(a[3] == b[3]);
    t += !!(a[4] == b[4]);
    t += !!(a[5] == b[5]);

    if (t > m->max)
        m->max = t;
    return t;
}

#include "./843_guess_the_word.h"
void test()
{
    Master* m = malloc(sizeof(Master));
    for (int i = 0; i < 100; i ++)
    {
        char* x = g_randomstr(6);
        while (_has_str(m, x, i))
            x = g_randomstr(6);
        m->a[i] = x;
    }
    m->s = m->a[rand() % 100];
    findSecretWord(m->a, 100, m);

    if (m->max != 6)
        printf("failed.\n");
}

#include "./305_number_of_islands_II.h"
void test()
{

    // int m[] = {0, 0, 0, 1, 1, 2, 2, 1, 2, 2, 0, 2, 2, 2};
    // int x = 3;
    // int y = 3;

    int m[] = {32,7,28,0,28,18,6,11,31,22,36,21,6,8,29,18,39,10,55,22,51,1,14,12,14,3,37,9,20,13,51,19,1,22,19,11,44,22,24,8,42,16,8,12,52,0,12,1,48,18,6,19,58,20,7,8,38,19,47,5,7,21,22,4,37,3,0,12,53,10,50,12,1,23,24,18,22,17,19,10,24,16,46,16,57,18,37,21,18,5,30,6,25,23,45,5,41,18,32,12,6,10,8,1,32,11,1,1,48,6,17,6,0,22,36,9,59,12,50,9,59,4,53,13,49,16,24,7,33,11,2,7,1,16,8,2,37,19,32,9,34,4,41,9,26,7,10,15,18,3,16,4,12,16,16,5,21,19,16,14,19,3,58,23,10,17,5,15,43,5,27,9,34,18,9,6,2,19,46,11,39,16,10,21,46,1,9,18,10,14,27,23,23,0,24,4,48,10,55,0,34,0,30,20,58,18,54,21,18,15,27,5,42,19,35,19,27,7,49,23,21,2,31,16,12,18,9,11,28,10,50,19,18,1,59,18,27,11,44,15,2,15,37,17,53,7,12,21,56,11,42,3,37,16,23,15,0,17,13,4,44,6,17,13,9,21,49,14,50,17,27,3,3,2,41,12,16,10,3,23,14,8,52,2,28,1,58,7,28,22,4,18,28,15,13,2,56,0,34,11,17,11,55,11,20,12,46,12,0,1,2,2,57,22,2,22,56,14,9,19,29,19,19,7,49,6,0,10,42,5,51,22,36,13,36,12,22,23,14,21,42,4,46,21,25,17,33,22,46,19,3,22,26,11,26,4,32,23,58,19,5,11,10,6,56,4,31,23,38,17,49,5,6,12,18,0,34,21,0,5,41,7,27,22,42,2,46,15,29,20,36,0,35,18,13,20,34,16,20,6,32,5,34,22,48,4,59,21,25,13,4,13,41,14,32,17,45,13,14,14,30,12,25,2,3,20,14,19,41,8,39,5,24,3,26,5,33,10,30,21,35,15,25,5,24,2,55,9,10,8,13,5,16,3,8,20,59,2,33,0,27,15,24,17,37,4,34,15,12,12,45,4,16,18,48,14,15,0,47,8,59,11,22,22,54,5,47,14,4,22,18,7,57,6,53,15,48,22,32,22,58,11,27,0,57,1,28,5,20,19,30,9,18,4,12,2,47,16,48,5,56,1,38,18,2,11,49,0,30,19,1,0,29,1,1,21,9,0,43,7,3,16,3,7,37,6,12,7,9,4,15,5,41,23,1,4,39,0,49,3,13,22,57,23,56,5,21,16,47,18,45,15,38,16,28,9,1,13,47,12,8,18,40,2,53,20,12,22,23,13,38,12,58,17,20,15,58,5,52,9,58,15,44,9,44,23,18,13,50,15,59,17,11,1,32,16,58,8,23,5,14,11,44,16,30,4,34,17,20,18,14,9,27,10,2,12,4,6,26,2,54,8,11,17,25,20,52,10,43,23,53,0,3,11,7,19,38,0,1,12,4,2,31,19,27,12,59,6,17,21,49,21,44,20,2,21,26,20,29,2,50,5,53,2,2,8,44,3,49,18,11,6,19,5,17,12,38,2,20,23,35,20,56,7,36,22,54,1,32,1,15,4,46,23,41,4,22,18,46,7,27,16,49,22,12,4,57,4,43,21,4,0,29,9,24,19,43,6,8,6,9,7,21,18,35,16,44,8,31,8,23,14,36,5,5,2,52,12,55,18,13,23,9,20,17,4,30,16,55,19,34,19,46,9,35,5,55,13,5,13,36,19,26,9,8,15,8,11,42,6,34,13,47,15,59,22,35,1,17,18,58,13,46,2,27,17,33,5,6,2,50,23,50,16,25,22,53,22,5,7,22,10,39,22,9,17,18,21,23,2,40,5,39,17,2,16,35,21,37,18,7,14,40,4,56,8,42,20,36,20,8,14,18,18,35,22,37,1,32,2,32,14,35,14,15,10,12,17,54,18,56,13,51,2,22,3,16,9,1,18,28,17,22,2,55,10,14,7,8,19,31,9,8,9,14,0,16,6,32,0,23,9,49,19,42,0,44,14,54,12,10,7,43,19,49,11,44,10,45,12,3,12,29,4,49,15,37,23,11,7,43,4 };
    int x = 60;
    int y = 24;

    int l = LEN_M(m);

    int c = 2;
    int** r = gen_aa(m, l, c);

    int rs = 0;
    int* rt = numIslands2(x, y, r, l / 2, 2, &rs);
    out(rt, rs);
}

#include "./765_couples_holding_hands.h"
void test()
{
    // int m[] = {0, 2, 1, 3};
    // int m[] = {3, 2, 0, 1};
    // int m[] = {1, 2, 3, 4, 5, 0};
    // int m[] = {5, 3, 4, 2, 1, 0};

    int m[] = {28,4,37,54,35,41,43,42,45,38,19,51,49,17,47,25,12,53,57,20,2,1,9,27,31,55,32,48,59,15,14,8,3,7,58,23,10,52,22,30,6,21,24,16,46,5,33,56,18,50,39,34,29,36,26,40,44,0,11,13};

    int l = LEN_M(m);
    printf("%d.\n",  minSwapsCouples(m, l));
}

#include "./743_network_delay_time.h"
void test()
{

    // int m[] = {1, 2, 30, 2, 3, 40, 4, 1, 10, 1, 4, 100, 2, 4, 30, 4, 3, 5};
    // int n = 4;
    // int k = 1;

    int m[] = {2,13,18,15,10,92,6,15,80,2,14,68,13,14,65,14,3,63,10,13,59,9,7,42,1,14,70,15,14,34,11,1,48,6,7,2,8,13,48,15,6,92,8,7,19,9,14,53,3,5,48,3,10,70,3,8,57,5,15,5,10,14,8,9,3,8,15,8,52,10,5,96,4,7,52,14,13,87,14,10,91,5,2,17,3,15,5,5,1,39,13,3,39,7,13,71,13,2,41,4,13,20,11,12,61,8,4,4,9,8,80,9,2,45,7,9,88,8,15,96,1,12,92,2,7,0,7,2,43,3,9,21,4,2,95,2,12,35,2,5,32,1,9,97,4,9,95,15,4,81,5,13,30,1,6,43,1,7,22,10,3,60,11,4,9,4,11,55,14,5,5,7,4,13,15,13,72,11,3,55,11,8,50,3,7,25,12,11,29,7,10,71,7,5,24,12,14,18,9,13,89,7,3,25,2,9,2,5,11,83,6,4,48,14,1,27,14,11,21,8,14,12,10,1,74,4,1,97,4,10,46,14,8,16,13,5,39,9,4,6,11,7,98,1,13,10,8,11,22,9,11,96,1,8,56,3,14,81,6,11,45,5,4,48,4,6,71,11,15,64,3,12,74,2,6,71,7,8,35,11,2,20,7,12,12,6,14,8,2,15,42,8,2,24,6,12,67,5,8,90,2,10,36,15,7,0,15,1,68,12,4,43,1,5,78,13,9,97,2,4,51,13,15,39,9,12,93,5,3,79,7,1,34,8,12,37,12,15,36,8,5,92,7,11,96,14,9,94,8,1,31,14,2,18,2,8,62,15,3,84,6,1,3,10,4,91,1,3,75,1,4,9,11,10,69,7,15,88,6,9,25,9,6,44,6,8,68,6,2,96,1,15,16,6,3,61,12,9,50,13,11,27,8,6,40,13,12,45,14,7,61,4,15,8,12,2,87,14,4,94,11,6,37,12,8,10,13,6,0,9,15,70,1,10,26,14,6,30,15,2,58,3,1,12,10,7,96,2,3,4,5,14,99,8,3,85,12,10,38,14,15,34,4,8,31,10,8,13,4,12,57,12,7,4,3,2,65,15,5,85,12,5,42,3,6,53,4,3,3,10,15,29,9,5,47,4,5,43,9,1,98,13,4,72,3,4,88,5,9,21,10,12,41,13,10,3,3,11,77,13,7,21,5,7,88,6,5,22,12,6,72,15,12,37,9,10,94,11,14,0,1,11,51,5,10,44,14,12,34,15,9,85,11,13,74,6,10,54,8,10,9,13,8,68,2,11,13,2,1,91,12,3,31,12,13,99,1,2,84,12,1,89,4,14,9,5,12,34,7,14,53,7,6,87,11,9,20,3,13,6,6,13,40,13,1,94,10,11,20,10,6,67,5,6,27,8,9,97,11,5,66,10,2,73,10,9,17,15,11,48};
    int n = 15;
    int k = 2;

    // int m[]  = {1, 2, 1}; int n = 2; int k = 2;

    int l = LEN_M(m);
    int c = 3;

    int** r = gen_aa(m, l, c);
    for (int i = 0; i < l / c; i ++)
        if (r[i][2] < 23)
            printf("%d,%d,%d,\n", r[i][0], r[i][1], r[i][2]);
    printf("%d.\n", networkDelayTime(r, l / 3, c, n, k));
}

#include "./323_number_of_connected_components_in_an_undirected_graph.h"
void test()
{
    // int m[] = {0, 1, 1, 2, 3, 4};
    // int m[] = {0, 1, 1, 2, 2, 3, 3, 4};
    // int m[] = {0, 1};
    int m[] = {0, 1, 1, 2, 0, 2, 3, 4};
    int n = 5;

    int l = LEN_M(m);
    int c = 2;

    int** r = gen_aa(m, l, c);

    printf("%d.\n", countComponents(n, r, l / c, c));
}

#include "./547_friend_circles.h"
void test()
{
    // int m[] = {1, 1, 0, 1, 1, 0, 0, 0, 1};
    // int m[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int m[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int l = LEN_M(m);
    int c = 3;

    int** r = gen_aa(m, l, c);

    printf("%d\n", findCircleNum(r, c, c));
}

#include "./737_sentence_similarity_II.h"
void test()
{
    char* w1[] = {"great", "acting", "skills"};
    int l1 = LEN_M(w1);
    char* w2[] = {"fine", "painting", "talent"};
    int l2 = LEN_M(w2);

    char* p1[] = {"great", "good"};
    char* p2[] = {"fine", "good"};
    char* p3[] = {"acting", "drama"};
    char* p4[] = {"skills", "talent"};
    char** p[] = {p1, p2, p3, p4};
    int lp = LEN_M(p);

    printf("%d.\n", areSentencesSimilarTwo(w1, l1, w2, l2, p, lp, 2));
}

#include "./721_accounts_merge.h"
void test()
{

    // char* m1[] = {"John", "johnsmith@mail.com", "john00@mail.com"};
    // char* m2[] = {"John", "johnnybravo@mail.com"};
    // char* m3[] = {"John", "johnsmith@mail.com", "john_newyork@mail.com"};
    // char* m4[] = {"Mary", "mary@mail.com"};
    // char* m5[] = {"Mary", "johnnybravo@mail.com", "mary@mail.com", "john_newyork@mail.com"};
    // char* m6[] = {"Mary", "mary1@mail.com"};

    char* m1[] = {"Hanzo","Hanzo2@m.co","Hanzo3@m.co"};
    char* m2[] = {"Hanzo","Hanzo4@m.co","Hanzo5@m.co"};
    char* m3[] = {"Hanzo","Hanzo0@m.co","Hanzo1@m.co"};
    char* m4[] = {"Hanzo","Hanzo3@m.co","Hanzo4@m.co"};
    char* m5[] = {"Hanzo","Hanzo7@m.co","Hanzo8@m.co"};
    char* m6[] = {"Hanzo","Hanzo1@m.co","Hanzo2@m.co"};
    char* m7[] = {"Hanzo","Hanzo6@m.co","Hanzo7@m.co"};
    char* m8[] = {"Hanzo","Hanzo5@m.co","Hanzo6@m.co"};

    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m8);
    int l8 = LEN_M(m7);

    char** m[] = {m1, m2, m3, m4, m5, m6, m7, m8};
    int l = sizeof(m)/sizeof(m[0]);
    int ls[] = {l1, l2, l3, l4, l5, l6, l7, l8};

    int* cs;
    int rs;
    char*** r =accountsMerge(m, l, ls, &cs, &rs);

    for (int i = 0; i < rs; i ++)
        outstr(r[i], cs[i]);
}

#include "./684_redundant_connection.h"
void test()
{
    int m[] = {1, 2, 1, 3, 2, 3};
    // int m[] = {1, 2, 2, 3, 3, 4, 1, 4, 1, 5};
    // int m[] = {1, 2, 2, 1};
    // int m[] = {3,7,1,4,2,8,1,6,7,9,6,10,1,7,2,3,8,9,5,9};
    // int m[] = {21,22,4,7,12,13,13,25,12,15,17,23,15,16,8,21,23,24,3,9,19,21,13,21,4,10,5,6,1,20,10,16,1,4,10,14,5,20,1,2,3,24,2,11,11,24,24,25,17,18};

    int l = LEN_M(m);
    int c = 2;

    int** r = gen_aa(m, l, c);

    int rs;
    int* ret = findRedundantConnection(r, l / c, c, &rs);
    out(ret, rs);
}

#include "./685_redundant_connection_II.h"
void test()
{
    int m[] = {1, 2, 1, 3, 2, 3};
    // int m[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 5};
    // int m[] = {1, 2, 2, 1};
    // int m[] = {3,7,1,4,2,8,1,6,7,9,6,10,1,7,2,3,8,9,5,9};
    // int m[] = {21,22,4,7,12,13,13,25,12,15,17,23,15,16,8,21,23,24,3,9,19,21,13,21,4,10,5,6,1,20,10,16,1,4,10,14,5,20,1,2,3,24,2,11,11,24,24,25,17,18};

    // int m[] = {2, 1, 3, 1, 4, 2, 1, 4};

    int l = LEN_M(m);
    int c = 2;

    int** r = gen_aa(m, l, c);

    int rs;
    int* ret = findRedundantDirectedConnection(r, l / c, c, &rs);
    out(ret, rs);
}

// #include "./207_course_schedule.h"
#include "./210_course_schedule_II.h"
void test()
    int m[] = {1, 0}; int n = 2;
    // int m[] = {1, 0, 0, 1}; int n = 2;
    // int m[] = {1, 0, 2, 0, 3, 1, 3, 2}; int n = 4;

    int l = LEN_M(m);
    int c = 2;
    int** r = gen_aa(m, l, c);

    // printf("%d.\n", canFinish(n, r, l / c, NULL));
    int rs = 0;
    int* rt = findOrder(n, r, l / c, NULL, &rs);
    out(rt, rs);
}

// failed too much times !!!
#include "./269_alien_dictionary.h"
void test()
{
    // char* m[] = {"wrt", "wrf", "er", "ett", "rftt"};
    // char* m[] = {"z", "x"};
    // char* m[] = {"z", "x", "z"};
    // char* m[] = {"z", "z"};
    // char* m[] = {"ab", "adc"};
    char* m[] = {"abce"};
    int l = LEN_M(m);

    printf("%s.\n", alienOrder(m, l));
}

#include "./444_sequence_reconstruction.h"
void test()
{

    // int m1[] = {1, 2};
    // int m2[] = {1, 3};
    // int* m[] = {m1, m2};
    // int ms[] = {LEN_M(m1), LEN_M(m2)};

    // int m1[] = {1, 2};
    // int* m[] = {m1};
    // int ms[] = {LEN_M(m1)};

    // int m1[] = {1, 2};
    // int m2[] = {1, 3};
    // int m3[] = {2, 3};
    // int* m[] = {m1, m2, m3};
    // int ms[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3)};
    // int n[] = {1, 2, 3};

    // int m1[] = {5, 2, 6, 3, 100};
    // int m2[] = {4, 1, 5 ,2};
    // int* m[] = {m1, m2};
    // int ms[] = {LEN_M(m1), LEN_M(m2)};
    // int n[] = {4, 1, 5, 2, 6, 3};

    int* m[] = {};
    int ms[] = {};
    int n[] = {1};

    int ml = LEN_M(m);
    int nl = LEN_M(n);

    printf("%d.\n", sequenceReconstruction(n, nl, m, ml, ms));
}

#include "./133_clone_graph.h"

#include "./261_graph_valid_tree.h"
void test()
{
    // int m[] = {0, 1, 0, 2, 0, 3, 1, 4}; int n = 5;
    int m[] = {0, 1, 1, 2, 2, 3, 1, 3, 1, 4}; int n = 5;
    int l = LEN_M(m);
    int c = 2;
    int** r = gen_aa(m, l, c);

    printf("%d.\n", validTree(n, r, l / c, c));
}

#include "./399_evaluate_division.h"
void test()
{

    // char* m1[] = {"a", "b"};
    // char* m2[] = {"e", "f"};
    // char* m3[] = {"b", "e"};
    // char** m[] = {m1, m2, m3};
    // double vs[] = {3.4, 1.4, 2.3};

    // char* q1[] = {"b", "a"};
    // char* q2[] = {"a", "f"};
    // char* q3[] = {"f", "f"};
    // char* q4[] = {"e", "e"};
    // char* q5[] = {"c", "c"};
    // char* q6[] = {"a", "c"};
    // char* q7[] = {"f", "e"};
    // char** q[] = {q1, q2, q3, q4, q5, q6, q7};

    char* m1[] = {"x1", "x2"};
    char* m2[] = {"x2", "x3"};
    char* m3[] = {"x3", "x4"};
    char* m4[] = {"x4", "x5"};
    char** m[] = {m1, m2, m3, m4};
    double vs[] = {3.0, 4.0, 5.0, 6.0};

    char* q1[] = {"x1", "x5"};
    char* q2[] = {"x5", "x2"};
    char* q3[] = {"x2", "x4"};
    char* q4[] = {"x2", "x2"};
    char* q5[] = {"x2", "x9"};
    char* q6[] = {"x9", "x9"};
    char** q[] = {q1, q2, q3, q4, q5, q6};

    int l = LEN_M(m);
    int ql = LEN_M(q);
    int rs;
    double* r = calcEquation(m, l, 2, vs, l, q, ql, 2, &rs);
    outd(r, rs);
}

#include "./844_backspace_string_compare.h"
void test()
{
    // char* s = "ab#c"; char* t = "ad#c";
    char* s = "ab##c"; char* t = "c#d###c";
    printf("%d.\n", backspaceCompare(strdup(s), strdup(t)));
}

#include "./845_longest_mountain_in_array.h"
void test()
{
    // int m[] = {2, 1, 4, 7, 3, 2, 5};
    //int m[] = {2, 2, 2};
    // int m[] = {0,1,2,3,4,5,4,3,2,1,0};
    int m[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l = LEN_M(m);
    printf("%d.\n", longestMountain(m, l));
}

#include "./846_hand_of_straights.h"
void test()
{
    // int m[] = {1, 2, 3, 6, 2, 3, 7, 8, 4}; int w = 3;
    // int m[] = {2, 2, 2, 3, 3, 3, 4, 4, 6}; int w = 3;
    // int m[] = {1, 2, 3, 5, 6, 7, 7, 8, 9}; int w = 3;
    int m[] = {1, 2, 3, 4, 5, 6}; int w = 2;
    int l = LEN_M(m);

    printf("%d.\n", isNStraightHand(m, l, w));
}

#include "./785_is_graph_biparitite.h"
void test()
{
    int m1[] = {1, 2, 3};
    int m2[] = {0, 2};
    int m3[] = {1, 3, 0};
    int m4[] = {0, 2};
    int* m[] = {m1, m2, m3, m4};
    int lm = LEN_M(m);
    int l[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4)};
    printf("%d.\n", isBipartite(m, lm, l));
}

#include "./752_open_the_lock.h"
void test()
{

    // char* m[] = {"0201", "0101", "0102", "1212", "2002"};
    // char* t = "0202";

    // char* m[] = {"8888"};
    // char* t = "0009";

    char* m[] = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    char* t = "8888";

    int l = LEN_M(m);
    printf("%d\n", openLock(m, l, t));
}

#include "./802_find_eventual_safe_states.h"
void test()
{

    // int m1[] = {4,9};
    // int m2[] = {3,5,7};
    // int m3[] = {0,3,4,5,6,8};
    // int m4[] = {7,8,9};
    // int m5[] = {5,6,7,8};
    // int m6[] = {6,7,8,9};
    // int m7[] = {7,9};
    // int m8[] = {8,9};
    // int m9[] = {9};
    // int m10[] = {};
    // int* m[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10};
    // int ls[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4), LEN_M(m5), LEN_M(m6), LEN_M(m7), LEN_M(m8), LEN_M(m9), LEN_M(m10)};

    // int m1[] = {};
    // int m2[] = {0, 2, 3, 4};
    // int m3[] = {3};
    // int m4[] = {4};
    // int m5[] = {};
    // int* m[] = {m1, m2, m3, m4, m5};
    // int ls[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4), LEN_M(m5)};


    int m1[] = {1, 2};
    int m2[] = {2, 3};
    int m3[] = {5,};
    int m4[] = {0};
    int m5[] = {};
    int* m[] = {m1, m2, m3, m4, m3, m5, m5};
    int ls[] = {LEN_M(m1), LEN_M(m2), LEN_M(m3), LEN_M(m4), LEN_M(m3), LEN_M(m5), LEN_M(m5)};

    int l = LEN_M(m);
    int rs;
    int* r = eventualSafeNodes(m, l, ls, &rs);
    out(r, rs);
}

// #include "./310_minimum_height_trees.h"
#include "./834_sum_of_distances_in_tree.h"
void test()
{
    // int m[] = {1, 0, 1, 2, 1, 3};
    // int m[] = {0, 1};
    // int m[] = {0, 3, 1, 3, 2, 3, 4, 3, 5, 4};
    // int m[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8};
    // int m[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7};
    int m[] = {0, 1, 0, 2, 0, 3, 3, 4};
    // int m[] = {0, 1, 0, 2, 2, 3, 2, 4, 2, 5};

    int l = LEN_M(m);
    int c = 2;
    int n = (l / c) + 1;

    int** r = gen_aa(m, l, c);

    int rs;
    // int* ret = findMinHeightTrees(n, r, l / c, c, &rs);
    int* ret = sumOfDistancesInTree(n, r, l / c, NULL, &rs);
    out(ret, rs);
}

#include "./631_design_excel_sum_formula.h"
void test()
{

    Excel* e = excelCreate(3, 'C');
    _out(e);
    excelSet(e, 1, 'A', 2);
    _out(e);
    char* s[] = {"A1", "A1:B2", "A1"};
    int l = LEN_M(s);
    excelSum(e, 3, 'C', s, l);
    _out(e);
    excelSet(e, 2, 'B', 3);
    _out(e);

    Excel* e = excelCreate(5, 'E');
    _out(e);
    excelSet(e, 1, 'A', 1);
    char* s1[] = {"A1", "A1"};
    int l1 = LEN_M(s1);
    excelSum(e, 2, 'B', s1, l1);
    excelSet(e, 1, 'A', 2);
    _out(e);
    Excel* e = excelCreate(5, 'E');
    _out(e);
    excelSet(e, 1, 'A', 5);
    excelSet(e, 1, 'B', 3);
    excelSet(e, 1, 'C', 2);
    char* s1[] = {"A1", "A1:B1"};
    int l1 = LEN_M(s1);
    excelSum(e, 1, 'C', s1, l1);
    excelSet(e, 1, 'B', 5);
    _out(e);
    char* s2[] = {"A1:A5"};
    int l2 = LEN_M(s2);
    excelSum(e, 1, 'B', s2, l2);
    excelSet(e, 5, 'A', 10);
    char* s3[] = {"A1:C1", "A1:A5"};
    int l3 = LEN_M(s3);
    excelSum(e, 3, 'C', s1, l1);
    _out(e);
    excelSum(e, 3, 'C', s3, l3);
    _out(e);
    excelSet(e, 3, 'A', 3);
    _out(e);

}

// #include "./694_number_of_distinct_islands.h"
#include "./711_number_of_distinct_islands_II.h"
void test()
{
    // int m[] = {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1};
    // int m[] = {1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1};
    // int m[] = {1, 1, 1, 0, 1};
    // int m[] = {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1};

    // int m[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0};
    // int c = 5;

    // int m[] = {0, 0, 1, 1, 1, 1};

    // int m[] = {1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0};
    // int c = 3;

    // int m[] = {1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,0}; // 26
    // int c = 25;

    // int m[] = {0,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0}; // 16
    // int c = 50;


    // int m[] = {1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1}; // 9
    // int c = 15;

    // int m[] = {1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,0,0,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,1,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,0}; // 61
    // int c = 50;

    // int m[] = {1,0,1,0,1,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,0,1,1,0,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,0,1,0,0,0,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,1,1,1,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1}; // 65
    // int c = 50;

    // int m[] = {1,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,>1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,1,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,0,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,1,0,1,0,1,1,1,0}; // 65
    // int c = 50;

    int m[] = {1,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,0,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,0,1,1,0,1,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0}; // 65
    int c = 50;


    int l = LEN_M(m);

    int** r = gen_aa(m,l, c);
    // outaaa(r, c, l / c);
    printf("%d.\n", numDistinctIslands2(r, l / c, c));
    // printf("%d.\n", numDistinctIslands(r, l / c, c));
}

#include "./403_frog_jump.h"
void test()
{

    // int m[] = {0, 1, 2};
    // int m[] = {0, 1, 2, 3, 4, 8, 9, 11};
    // int m[] = {0, 1, 3, 5, 6, 8, 12, 18};
    // int m[] = {0, 2};

    int m[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,717,718,719,720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736,737,738,739,740,741,742,743,744,745,746,747,748,749,750,751,752,753,754,755,756,757,758,759,760,761,762,763,764,765,766,767,768,769,770,771,772,773,774,775,776,777,778,779,780,781,782,783,784,785,786,787,788,789,790,791,792,793,794,795,796,797,798,799,800,801,802,803,804,805,806,807,808,809,810,811,812,813,814,815,816,817,818,819,820,821,822,823,824,825,826,827,828,829,830,831,832,833,834,835,836,837,838,839,840,841,842,843,844,845,846,847,848,849,850,851,852,853,854,855,856,857,858,859,860,861,862,863,864,865,866,867,868,869,870,871,872,873,874,875,876,877,878,879,880,881,882,883,884,885,886,887,888,889,890,891,892,893,894,895,896,897,898,899,900,901,902,903,904,905,906,907,908,909,910,911,912,913,914,915,916,917,918,919,920,921,922,923,924,925,926,927,928,929,930,931,932,933,934,935,936,937,938,939,940,941,942,943,944,945,946,947,948,949,950,951,952,953,954,955,956,957,958,959,960,961,962,963,964,965,966,967,968,969,970,971,972,973,974,975,976,977,978,979,980,981,982,983,984,985,986,987,988,989,990,991,992,993,994,995,996,997,998,1035};

    int l = LEN_M(m);
    printf("%d.\n", canCross(m, l));
}

// PEEK HINT !!
#include "./659_split_array_into_consecutive_subsequences.h"
void test()
{

    // int m[] = {-3, -2, -1, 0, 1, 1, 2, 3}; // 1
    // int m[] = {INT_MIN, INT_MIN + 1, INT_MIN + 2, INT_MIN + 3, INT_MIN + 3, INT_MIN + 4, INT_MIN + 5}; // 1

    // int m[] = {INT_MIN, INT_MIN + 1, INT_MIN + 2, INT_MIN + 3, INT_MIN + 5, INT_MIN + 6, INT_MIN + 6}; // 0
    // int m[] = {1, 2, 3, 3, 4, 5}; // 1
    // int m[] = {INT_MAX - 6, INT_MAX - 5, INT_MAX - 4, INT_MAX -4, INT_MAX -3, INT_MAX -2, INT_MAX - 1, INT_MAX}; // 1
    // int m[] = {1, 2, 3, 3, 4, 4, 5, 5}; // 1
    // int m[] = {1, 2, 3, 4, 4, 5};

    int l = LEN_M(m);
    printf("%d.\n", isPossible(m, l));
}

#include "./311_sparse_matrix_multiplication.h"
void test()
{


    int a1[] = {1, 0, 1};
    int a2[] = {-1, 0, 3};
    int* a[] = {a1, a2};
    int b1[] = {7, 0, -3};
    int b2[] = {0, 0, 0};
    int b3[] = {1, 0, 1};
    int* b[] = {b1, b2, b3};

    int a1[] = {1};
    int* a[] = {a1};
    int b1[] = {-1};
    int* b[] = {b1};

    int al = LEN_M(a1);
    int als = LEN_M(a);
    int bl = LEN_M(b1);
    int bls = LEN_M(b);

    int** r = multiply(a, als, al, b, bls, bl);
    outaaa(r, bl, als);
}

// #include "./224_basic_calculator.h"
#include "./772_basic_calculator_III.h"
void test()
{
    char* s = "1 + 1";
    printf("s %s r %d.\n", s, calculate(s));

    s = "2-1 + 2 ";
    printf("s %s r %d.\n", s, calculate(s));

    s = "(1+(4+5+2)-3)+(6+8)";
    printf("s %s r %d.\n", s, calculate(s));

    s = "(2)";
    printf("s %s r %d.\n", s, calculate(s));

    s = "1000";
    printf("s %s r %d.\n", s, calculate(s));

    s = "(1-(3-4))";
    printf("s %s r %d.\n", s, calculate(s));

    s = " 6-4/2";
    printf("s %s r %d.\n", s, calculate(s));

    s = "2*(5+5*2)/3+(6/2+8)";
    printf("s %s r %d.\n", s, calculate(s));
    s = "(2+6* 3+5- (3*14/7+2)*5)+3";
    printf("s %s r %d.\n", s, calculate(s));

    s = " (3 - 4/1) * (15 - (2 + 4 / 2))";
    printf("s %s r %d.\n", s, calculate(s));
}

#include "./849_maximize_distance_to_closest_person.h"
void test()
{
    // int m[] = {0,1};
    // int m[] = {1, 0, 0};
    // oint m[] = {0, 0, 1};

    int m[] = {1, 0, 0, 0, 0, 0, 1, 0, 1};
    // int m[] = {1, 0, 0, 1, 0, 1};

    int l = LEN_M(m);

    printf("%d.\n", maxDistToClosest(m, l));
}

#include "./848_shifting_letters.h"
void test()
{
    int m[] = {26, 9, 17};
    int l = LEN_M(m);
    char* s = "ruu";
    printf("%s.\n", shiftingLetters(s, m, l));
}

#include "./851_loud_and_rich.h"
void test()
{
    int m[] = {1, 0, 2, 1, 3, 1, 3, 7, 4, 3, 5, 3, 6, 3};

    int l = LEN_M(m);
    int c = 2;

    int** r = gen_aa(m, l, c);

    int q[] = {3, 2, 5, 4, 6, 1, 7, 0};
    int ql = LEN_M(q);

    int rs = 0;
    int* ret = loudAndRich(r, l / c, 0, q, ql, &rs);
    out(ret, rs);
}

#include "./529_minesweeper.h"
void test()
{

    char* m[] = {
        "EEEEE",
        "EEMEE",
        "EEEEE",
        "EEEEE",
    };
    int cl[] = {3, 0};


    // char* m[] = {
    //     "EEEEEEEE",
    //     "EEEEEEEM",
    //     "EEMEEEEE",
    //     "MEEEEEEE",
    //     "EEEEEEEE",
    //     "EEEEEEEE",
    //     "EEEEEEEE",
    //     "EEMMEEEE",
    // };
    // int cl[] = {0, 0};

    // char* m[] = {
    //     "EEEEE",
    //     "EEMEE",
    //     "EEEEE",
    //     "EEEEE",
    // };
    // int cl[] = {0, 2};

    int l = sizeof(m)/sizeof(m[0]);

    char** r = malloc(sizeof(char*) * l);
    for (int i = 0; i < l; i ++)
        r[i] = strdup(m[i]);

    int c = strlen(r[0]);

    int* cs;
    int rs;
    char** ret = updateBoard(r, l, c, cl, 2, &cs, &rs);

    if (ret)
        for (int i = 0; i < rs; i ++)
            printf("%s.\n", ret[i]);

}

#include "./435_non-overlapping_intervals.h"
void test()
{
    // 9int m[] = {1, 2, 2, 3, 3, 4, 1, 3};
    // int m[] = {1, 2, 2, 3};

    // int m[] = {1, 2, 1, 2, 1, 2, 1, 2};

    // int m[] = {1, 100, 11, 22, 1, 11, 2, 12}; // 2
    // int m[] = {0, 2, 1, 3, 1, 3, 2, 4, 3, 5, 3, 5, 4, 6}; // 4
    int m[] = {0, 2, 1, 3, 2, 4, 3, 5, 4, 6}; // 2
    // int m[] = {-100,-87,-99,-44,-98,-19,-97,-33,-96,-60,-95,-17,-94,-44,-93,-9,-92,-63,-91,-76,-90,-44,-89,-18,-88,10,-87,-39,-86,7,-85,-76,-84,-51,-83,-48,-82,-36,-81,-63,-80,-71,-79,-4,-78,-63,-77,-14,-76,-10,-75,-36,-74,31,-73,11,-72,-50,-71,-30,-70,33,-69,-37,-68,-50,-67,6,-66,-50,-65,-26,-64,21,-63,-8,-62,23,-61,-34,-60,13,-59,19,-58,41,-57,-15,-56,35,-55,-4,-54,-20,-53,44,-52,48,-51,12,-50,-43,-49,10,-48,-34,-47,3,-46,28,-45,51,-44,-14,-43,59,-42,-6,-41,-32,-40,-12,-39,33,-38,17,-37,-7,-36,-29,-35,24,-34,49,-33,-19,-32,2,-31,8,-30,74,-29,58,-28,13,-27,-8,-26,45,-25,-5,-24,45,-23,19,-22,9,-21,54,-20,1,-19,81,-18,17,-17,-10,-16,7,-15,86,-14,-3,-13,-3,-12,45,-11,93,-10,84,-9,20,-8,3,-7,81,-6,52,-5,67,-4,18,-3,40,-2,42,-1,49,0,7,1,104,2,79,3,37,4,47,5,69,6,89,7,110,8,108,9,19,10,25,11,48,12,63,13,94,14,55,15,119,16,64,17,122,18,92,19,37,20,86,21,84,22,122,23,37,24,125,25,99,26,45,27,63,28,40,29,97,30,78,31,102,32,120,33,91,34,107,35,62,36,137,37,55,38,115,39,46,40,136,41,78,42,86,43,106,44,66,45,141,46,92,47,132,48,89,49,61,50,128,51,155,52,153,53,78,54,114,55,84,56,151,57,123,58,69,59,91,60,89,61,73,62,81,63,139,64,108,65,165,66,92,67,117,68,140,69,109,70,102,71,171,72,141,73,117,74,124,75,171,76,132,77,142,78,107,79,132,80,171,81,104,82,160,83,128,84,137,85,176,86,188,87,178,88,117,89,115,90,140,91,165,92,133,93,114,94,125,95,135,96,144,97,114,98,183,99,157};

    int l = LEN_M(m);
    struct Interval* r = gen_interval(m, l);
    printf("%d.\n", eraseOverlapIntervals(r, l / 2));
}

#include "./307_range_sum_query_mutable.h"
void test()
{
    // int m[] = {1, 3, 5, 7, 9};
    // int m[] = {100, 10};
    int m[] = {1, 3, 5};
    int l = LEN_M(m);
    NumArray* n = numArrayCreate(m, l);
    printf("%d.\n", numArraySumRange(n, 0, 2));
    numArrayUpdate(n, 1, 2);
    printf("%d.\n", numArraySumRange(n, 0, 2));
}

#include "./308_range_sum_query_2D_mutable.h"
void test()
{

    // int m[] = {
    //     3, 0, 1, 4, 2,
    //     5, 6, 3, 2, 1,
    //     1, 2, 0, 1, 5,
    //     4, 1, 0, 1, 7,
    //     1, 0, 3, 0, 5
    // };
    // int l = LEN_M(m);
    // int c = 5;
    // int** r = gen_aa(m, l, c);
    // NumMatrix* n = numMatrixCreate(r, l / c, c);
    // printf("%d.\n", numMatrixSumRegion(n, 0, 0, 0, 0));
    // printf("%d.\n", numMatrixSumRegion(n, 0, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 3, 3));
    // numMatrixUpdate(n, 4, 4, 10);
    // printf("%d.\n", numMatrixSumRegion(n, 0, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 3, 3));
    // numMatrixUpdate(n, 3, 3, 10);
    // printf("%d.\n", numMatrixSumRegion(n, 0, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 4, 4));
    // printf("%d.\n", numMatrixSumRegion(n, 3, 0, 3, 3));
    // outaaa(r, c, l / c);

    // int m[] = {0, -5, 9, 1, -8, 5, 8, 1, 1, 5};
    int m[] = {1, 2};
    int l = LEN_M(m);
    int c = l;
    int** r = gen_aa(m, l, c);
    NumMatrix* n = numMatrixCreate(r, l / c, c);
    printf("%d.\n", numMatrixSumRegion(n, 0, 5, 0, 9));
    printf("%d.\n", numMatrixSumRegion(n, 0, 5, 0, 9));
    numMatrixUpdate(n, 0, 3, -1);
    printf("%d.\n", numMatrixSumRegion(n, 0, 3, 0, 6));
    printf("%d.\n", numMatrixSumRegion(n, 0, 0, 0, 0));
    printf("%d.\n", numMatrixSumRegion(n, 0, 0, 0, 1));
    numMatrixUpdate(n, 0, 0, 3);
    numMatrixUpdate(n, 0, 1, 5);
    printf("%d.\n", numMatrixSumRegion(n, 0, 0, 0, 1));

}

// Find better solution !!
#include "./315_count_of_smaller_numbers_after_self.h"
void test()
{
    // int m[] = {5, 2, 6, 1};
    // int m[] = {1, 2, 3, 1, 2, 4, 3, 1, 9};
    // int m[] = {1, 2, 3, 4, 5};
    // int m[] = {0, 2 ,1};
    int m[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    int rs;
    int l = sizeof(m)/sizeof(m[0]);

    int* r = countSmaller(m, l, &rs);
    out(r, rs);
}

// DO IT AGAIN !!!
#include "./327_count_of_range_sum.h"
void test()
{
    // int m[] = {-2, 5, -1}; int low = -2; int up = 2; // 3
    int m[] = {0, -3, -3, 1, 1, 2}; int low = 3; int up = 5; // 2
    // int m[] = {INT_MIN, 0, INT_MIN, INT_MAX}; int low = -564; int up = 3864; // 3
    int l = LEN_M(m);
    printf("%d.\n", countRangeSum(m, l, low, up));
}

#include "./493_reverse_pairs.h"
void test()
{

    // int m[] = {1, 3, 2, 3, 1}; // 2
    // int m[] = {2, 4, 3, 5, 1}; // 3
    // int m[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}; // 0
    // int m[] = {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004}; // 40

    int l = LEN_M(m);
    printf("%d.\n", reversePairs(m, l));
}

#include "./699_falling_squares.h"
void test()
{

    int m[] = {1, 2, 2, 3, 4, 1, 6, 1};
    // int m[] = {100, 100, 200, 100};
    // int m[] = {1, 2, 1, 3};

    int c = 2;
    int l = LEN_M(m);

    int** r = gen_aa(m, l, c);

    int rs;
    int* rt = fallingSquares(r, l / c, c, &rs);
    out(rt, rs);
}

// DO IT AGAIN !!! TODO STUPID
#include "./850_rectangle_area_II.h"
void test()
{

    // int m[] = {0, 0, 4, 4, 2, 0, 4, 6, 2, 0, 6, 2};
    // int m[] = {0, 0, 4, 4, 2, 0, 6, 2};
    // int m[] = {0, 0, 4, 4};
    // int m[] = {0, 0, 1000000000, 1000000000, 1000000002, 1000000002, 1000000004, 1000000004};
    // int m[] = {0, 0, 1000000000, 1000000000};
    // int m[] = {41, 59, 61, 89, 49, 83, 95, 98, 32, 9, 43, 66}; // 1831

    // int m[] = {40, 20, 51, 30, 26, 88, 51, 89, 24, 69, 74, 73}; // 335
    int m[] = {2,30,36,61,35,31,74,65,43,11,92,15,22,55,76,81}; // 3482


    int c = 4;
    int l = LEN_M(m);

    int ** r = gen_aa(m, l, c);
    printf("%d\n", rectangleArea(r, l / c, NULL));
}

#include "./852_peak_index_in_a_mountain_array.h"
void test()
{

    // int m[] = {0, 1, 0};
    // int m[] = {0, 2, 1, 0};
    // int m[] = {1, 2, 3, 4, 5, 3, 1, 0};

    printf("%d.\n", peakIndexInMountainArray(m, LEN_M(m)));
}

#include "./853_car_fleet.h"
void test()
{

    // int p[] = {10, 8, 0, 5, 3}; int s[] = {2, 4, 1, 1, 3};

    int p[] = {10, 11, 9, 7}; int s[] = {2, 1, 3, 4};

    int t = 12;
    int l = LEN_M(p);
    printf("%d.\n", carFleet(t, p, l, s, l));
}

#include "./855_exam_room.h"
void test()
{

    // int n = 10;
    // ExamRoom* obj = examRoomCreate(n);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 0);
    // examRoomLeave(obj, 4);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 0);
    // examRoomLeave(obj, 4);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 7);
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 3);
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 3);
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 9);
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 0);
    // examRoomLeave(obj, 8);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 0);
    // examRoomLeave(obj, 8);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 2);


    // int n = 4;
    // ExamRoom* obj = examRoomCreate(n);
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 1);
    // examRoomLeave(obj, 3);
    // printf("%d.\n", examRoomSeat(obj));

    int n = 9;
    ExamRoom* obj = examRoomCreate(n);
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 4);
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 3);
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 8);
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 0);
    examRoomLeave(obj, 7);
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 1);
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 5);
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 0);
    examRoomLeave(obj, 8);
    printf("%d.\n", examRoomSeat(obj));
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 7);
    printf("%d.\n", examRoomSeat(obj));
    examRoomLeave(obj, 7);
    printf("%d.\n", examRoomSeat(obj));

    // examRoomLeave(obj, 4);
    // printf("%d.\n", examRoomSeat(obj));
    // examRoomLeave(obj, 9);
    // printf("%d.\n", examRoomSeat(obj));

}

#include "./854_k_similar_strings.h"
void test()
{

    printf("%d.\n", kSimilarity("ab", "ba"));  // 1
    printf("%d.\n", kSimilarity("abc", "bca")); // 2
    printf("%d.\n", kSimilarity("abac", "baca")); // 2
    printf("%d.\n", kSimilarity("aabc", "abca")); // 2
    printf("%d.\n", kSimilarity("abcdef", "bcdefa")); // 5
    printf("%d.\n", kSimilarity("abcdefaaa", "bcdefaaaa")); // 5
    printf("%d.\n", kSimilarity("abbacde", "baabced")); // 3
    printf("%d.\n", kSimilarity("cba", "abc")); // 1
    printf("%d.\n", kSimilarity("decba", "edabc")); // 2
    printf("%d.\n", kSimilarity("abbacdecba", "baabcedabc")); // 4
    printf("%d.\n", kSimilarity("a", "a")); // 0
    printf("%d.\n", kSimilarity("fffeaacbdbdafcfbbafb", "abcbdfafffefabdbbafc")); // 10
    printf("%d.\n", kSimilarity("feacbd", "cbdafe")); // 5

    printf("%d.\n", kSimilarity("abcdefabcdefabcdef", "edcfbebceafcfdabad")); // 10
    printf("%d.\n", kSimilarity("eabcdfabc", "bbceacfda")); // 6

    printf("%d.\n", kSimilarity("bfddfbcdeadbfdbadecd","deddacfdbedbbfabdfdc")); // 9
    printf("%d.\n", kSimilarity("abbcdeff","ecdffbab")); // 6

}

#include "./732_my_calendar_III.h"
void test()
{
    MyCalendarThree* o = myCalendarThreeCreate();

    // int m[] = {10, 20, 50, 60, 10, 40, 5, 15, 5, 10, 25, 55};
    // int m[] = {24, 40, 43, 50, 27, 43, 5, 21, 30, 40, 14, 29, 3, 19, 3, 14, 25, 39, 6, 19};

    int m[] = {24, 40, 43, 50, 27, 43, 5, 21, 30, 40, 14, 29, 3, 19, 3, 14, 25, 39, 6, 19};

    for (int i = 0; i < LEN_M(m); i += 2 )
        printf("%d.\n", myCalendarThreeBook(o, m[i], m[i + 1]));

}

#include "./352_data_stream_as_disjoint_intervals.h"
void test()
{
    int rs = 0;
    struct Interval* r = NULL;
    SummaryRanges* s = summaryRangesCreate();
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);
    summaryRangesAddNum(s, 1);
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);

    summaryRangesAddNum(s, 10);
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);

    summaryRangesAddNum(s, 3);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 7);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 2);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 6);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 5);
    summaryRangesGetIntervals(s, &rs);

    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);


    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);
    summaryRangesAddNum(s, 4);
    summaryRangesGetIntervals(s, &rs);

    summaryRangesAddNum(s, 9);
    out_interval(summaryRangesGetIntervals(s, &rs), rs);
    summaryRangesAddNum(s, 10);
    out_interval(summaryRangesGetIntervals(s, &rs), rs);
    summaryRangesAddNum(s, 8);
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);

    summaryRangesAddNum(s, 8);
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);

    summaryRangesAddNum(s, 1000);
    r = summaryRangesGetIntervals(s, &rs);
    out_interval(r, rs);

}

#include "./715_range_module.h"
void test()
{
    int qs, qe;
    RangeModule* r = rangeModuleCreate();

    rangeModuleAddRange(r, 10, 20);
    rangeModuleRemoveRange(r, 14, 16);
    qs = 10; qe = 14; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    qs = 13; qe = 15; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    qs = 16; qe = 17; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    qs = 9; qe = 14; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    qs = 11; qe = 14; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    qs = 15; qe = 17; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));


    // rangeModuleAddRange(r, 10, 180);
    // rangeModuleAddRange(r, 150, 200);
    // rangeModuleAddRange(r, 250, 500);
    // qs = 50; qe = 100; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    // qs = 180; qe = 300; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    // qs = 600; qe = 1000; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));
    // rangeModuleRemoveRange(r, 50, 150);
    // qs = 50; qe = 100; printf("%d - %d is %d.\n", qs, qe, rangeModuleQueryRange(r, qs, qe));

}

#include "./385_mini_parser.h"
#include "./341_flatten_nested_list_iterator.h"
void test()
{
    // char* s = "324";

    // char* s = "[123,[456,[-789],0]]";
    // char* s = "[1,2,[3,4,[[5,6],7,9],[-12]]]";

    // char* s = "[[1,2],[3,4],[[[5],6,[[7,8,-1]],[[1],2],11],-12,[11],-9],1000]";
    // char* s = "[-1]";
    // char* s = "[[]]";
    // char* s = "[]";

    char* s = "[1,[2],3]";
    struct NestedInteger* x = deserialize(s);
}

#include "./856_score_of_parentheses.h"
void test()
{
    printf("%d.\n", scoreOfParentheses("()"));
    printf("%d.\n", scoreOfParentheses("()()()()"));
    printf("%d.\n", scoreOfParentheses("()(())((()))"));
    printf("%d.\n", scoreOfParentheses("((())(()))"));
    printf("%d.\n", scoreOfParentheses("(()())"));
    printf("%d.\n", scoreOfParentheses("(())"));
    printf("%d.\n", scoreOfParentheses("(()(()))"));
}

#include "./859_buddy_strings.h"
void test()
{
    printf("%d.\n", buddyStrings("a", "b"));
    printf("%d.\n", buddyStrings("a", "a"));
    printf("%d.\n", buddyStrings("aa", "aa"));
    printf("%d.\n", buddyStrings("ba", "ab"));
    printf("%d.\n", buddyStrings("ab", "ab"));
    printf("%d.\n", buddyStrings("aaaaaaaab", "aaaaabaaa"));
    printf("%d.\n", buddyStrings("aaaaaaaab", "aaaaabaaac"));
}

#include "./858_mirror_reflection.h"
void test()
{
    printf("%d.\n", mirrorReflection(2, 1));
    printf("%d.\n", mirrorReflection(30, 20));
}

#include "./857_minimum_cost_to_hire_k_workers.h"
void test()
{

    int q[] = {10, 20, 5};
    int w[] = {70, 50, 30};
    int k = 2;

    // int q[] = {3, 1, 10, 10, 1};
    // int w[] = {4, 8, 2, 2, 7};
    // int k = 5;

    // int q[] = {14, 56, 59, 89, 39, 26, 86, 76, 3, 36};
    // int w[] = {90, 217, 301, 202, 294, 445, 473, 245, 415, 487};
    // int k = 2;

    int l = LEN_M(q);
    printf("%lf.\n", mincostToHireWorkers(q, l, w, l, k));

}

#include "./435_non-overlapping_intervals.h"
void test()
{
    // int m[] = {1, 2, 2, 3, 3, 4, 1, 3};
    int m[] = {1, 2, 2, 3};

    // int m[] = {1, 2, 1, 2, 1, 2, 1, 2};

    // int m[] = {1, 100, 11, 22, 1, 11, 2, 12}; // 2
    // int m[] = {0, 2, 1, 3, 1, 3, 2, 4, 3, 5, 3, 5, 4, 6}; // 4
    // int m[] = {0, 2, 1, 3, 2, 4, 3, 5, 4, 6}; // 2
    // int m[] = {-100,-87,-99,-44,-98,-19,-97,-33,-96,-60,-95,-17,-94,-44,-93,-9,-92,-63,-91,-76,-90,-44,-89,-18,-88,10,-87,-39,-86,7,-85,-76,-84,-51,-83,-48,-82,-36,-81,-63,-80,-71,-79,-4,-78,-63,-77,-14,-76,-10,-75,-36,-74,31,-73,11,-72,-50,-71,-30,-70,33,-69,-37,-68,-50,-67,6,-66,-50,-65,-26,-64,21,-63,-8,-62,23,-61,-34,-60,13,-59,19,-58,41,-57,-15,-56,35,-55,-4,-54,-20,-53,44,-52,48,-51,12,-50,-43,-49,10,-48,-34,-47,3,-46,28,-45,51,-44,-14,-43,59,-42,-6,-41,-32,-40,-12,-39,33,-38,17,-37,-7,-36,-29,-35,24,-34,49,-33,-19,-32,2,-31,8,-30,74,-29,58,-28,13,-27,-8,-26,45,-25,-5,-24,45,-23,19,-22,9,-21,54,-20,1,-19,81,-18,17,-17,-10,-16,7,-15,86,-14,-3,-13,-3,-12,45,-11,93,-10,84,-9,20,-8,3,-7,81,-6,52,-5,67,-4,18,-3,40,-2,42,-1,49,0,7,1,104,2,79,3,37,4,47,5,69,6,89,7,110,8,108,9,19,10,25,11,48,12,63,13,94,14,55,15,119,16,64,17,122,18,92,19,37,20,86,21,84,22,122,23,37,24,125,25,99,26,45,27,63,28,40,29,97,30,78,31,102,32,120,33,91,34,107,35,62,36,137,37,55,38,115,39,46,40,136,41,78,42,86,43,106,44,66,45,141,46,92,47,132,48,89,49,61,50,128,51,155,52,153,53,78,54,114,55,84,56,151,57,123,58,69,59,91,60,89,61,73,62,81,63,139,64,108,65,165,66,92,67,117,68,140,69,109,70,102,71,171,72,141,73,117,74,124,75,171,76,132,77,142,78,107,79,132,80,171,81,104,82,160,83,128,84,137,85,176,86,188,87,178,88,117,89,115,90,140,91,165,92,133,93,114,94,125,95,135,96,144,97,114,98,183,99,157};

    int l = LEN_M(m);
    struct Interval* r = gen_interval(m, l);
    printf("%d.\n", eraseOverlapIntervals(r, l / 2));
}

#include "./452_minimum_number_of_arrows_to_burst_balloons.h"
void test()
{

    // int m[] = {10, 16, 2, 8, 1, 6, 7, 12};
    int m[] = {10, 16, 1, 11, 1, 15};

    int l = LEN_M(m);
    int c = 2;
    int** r = gen_aa(m, l, c);
    printf("%d.\n", findMinArrowShots(r, l / c, c));
}

#include "./253_meeting_rooms_II.h"
void test()
{

    // int m[] = {7, 10, 2, 4};
    // int m[] = {0, 30, 35, 40, 45, 60}; // 1
    // int m[] = {8, 14, 12, 13, 6, 13, 1, 9}; // 3
    // int m[] = {0, 30, 5, 10, 15, 20}; // 2
    // int m[] = {2, 15, 36, 45, 9, 29, 16, 23, 4, 9}; // 2

    int l = LEN_M(m);
    struct Interval* r = gen_interval(m, l);
    printf("%d.\n", minMeetingRooms(r, l / 2));
}

#include "./634_find_the_derangement_of_an_array.h"
// be careful about permutation !
void _premu(int* n, int s, int e, int* num)
{
    if (s == e)
    {
        // out(n, e + 1);
        for (int i = 0; i <= e; i ++)
            if (n[i] == i)
                return;
        (*num) ++;
        return;
    }

    int t = n[s];
    // start from s
    for (int i = s; i <= e; i ++)
    {
        n[s] = n[i];
        n[i] = t;
        _premu(n, s + 1, e, num);
        n[i] = n[s];
        n[s] = t;
    }
}
void test()
{

    for (int n = 1; n < 12; n ++)
    {
        int* x = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i ++)
            x[i] = i;

        int num = 0;
        _premu(x, 0, n - 1, &num);
        printf("%d %d.\n", findDerangement(n), num);
    }
}

#include "./432_all_O_one_data_structure.h"
void test()
{
     AllOne* o = allOneCreate();

     allOneInc(o, "hello");
     allOneInc(o, "goodbye");
     allOneInc(o, "hello");
     allOneInc(o, "hello");
     printf("%s.\n", allOneGetMaxKey(o));
     allOneInc(o, "leet");
     allOneInc(o, "code");
     allOneInc(o, "leet");
     allOneDec(o, "hello");
     allOneInc(o, "leet");
     allOneInc(o, "code");
     allOneInc(o, "code");
     printf("%s.\n", allOneGetMaxKey(o));
     allOneInc(o, "1");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "1");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "3");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneDec(o, "2");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));


     for (int i = 0; i < 1001000; i ++)
         allOneInc(o, "a");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     for (int i = 0; i < 1001000; i ++)
         allOneInc(o, "b");
     printf("%s.\n", allOneGetMaxKey(o));
     printf("%s.\n", allOneGetMinKey(o));
     allOneInc(o, "b");
     printf("%s.\n", allOneGetMaxKey(o));
     allOneInc(o, "a");
     allOneInc(o, "a");
     printf("%s.\n", allOneGetMaxKey(o));

     for (int i = 0; i < 10010; i ++)
     {
         allOneInc(o, "a");
         printf("%s.\n", allOneGetMaxKey(o));
         allOneInc(o, "b");
         printf("%s.\n", allOneGetMaxKey(o));
         allOneDec(o, "b");
     }
}

#include "./644_maximum_average_subarray_II.h"
void test()
{

    // int m[] = {1,12,-5,-6,50,3, 50, -20, 10, 10, 10, 1000, -300, 20, 500}; int k = 7;
    // int m[] = {7,4,5,8,8,3,9,8,7,6}; int k = 7;

    // int m[] = {1, 12, -5, -6, 50, 3}; int k = 4;
    // int m[] = {0, 1, 2, 3, 4, 5, -6, 10, 8}; int k = 3;

    // int m[] = {8, 9, 3, 1, 8, 3, 0, 6, 9, 2}; int k = 8;

    // int m[] = {-1}; int k =1;

    int m[] = {0, 1, 1, 3, 3}; int k = 4;

    // int m[] = {64,514,188,145,614,214,888,344,380,781,346,668,165,687,236,551,338,609,401,118,662,911,907,792,83,942,213,427,442,979,700,507,493,888,4,107,454,893,803,834,26,150,502,191,189,738,742,528,699,496,998,361,407,257,154,842,551,719,270,994,699,970,853,544,210,209,652,665,102,807,499,480,957,354,672,499,92,766,27,792,614,377,505,373,986,11,216,889,731,838,883,782,160,88,326,370,298,330,35,752,138,887,233,447,241,257,946,685,23,325,829,638,54,335,11,392,346,579,282,429,417,165,211,577,606,890,300,904,572,335,656,710,222,889,510,815,498,808,501,522,486,330,512,540,665,875,933,364,455,567,793,224,732,357,154,690,599,454,594,171,141,603,234,716,844,744,531,343,904,32,865,390,715,729,931,380,604,216,96,411,783,890,636,867,599,790,558,198,596,504,369,737,107,603,805,952,699,337,295,604,721,512,994,436,241,277,169,197,845,265,609,628,507,245,848,106,387,758,656,335,262,26,72,370,981,230,674,681,567,969,637,640,833,983,429,426,261,598,623,106,215,232,87,723,829,935,181,568,693,838,903,307,216,328,677,197,558,703,230,477,24,219,469,857,203,898,283,464,848,259,922,64,843,9,139,673,296,320,593,341,510,849,649,726,177,678,276,87,382,858,916,758,78,385,616,281,284,251,97,132,862,371,548,706,733,687,379,29,360,324,723,870,173,372,949,702,402,225,141,136,83,57,895,513,443,863,794,79,466,243,211,329,615,112,35,700,799,766,729,159,90,452,382,616,176,331,318,579,908,812,67,343,869,962,857,664,825,3,743,292,247,307,621,214,419,656,914,570,422,995,82,864,800,464,480,328,147,151,259,407,315,327,750,184,641,607,201,467,611,944,111,210,603,84,776,374,92,42,945,866,389,379,730,541,195,563,870,694,66,481,101,381,808,851,917,450,811,118,269,774,415,732,336,370,816,112,745,908,506,42,126,247,773,208,789,968,771,11,662,189,492,763,922,301,966,840,103,777,310,372,551,77,104,887,448,272,351,545,532,209,939,658,457,712,866,246,32,990,257,694,531,749,809,454,402,127,646,505,905,956,229,808,386,685,696,834,957,399,731,841,609,670,499,66,734,718,664,766,60,273,812,591,22,621,45,425,100,691,282,5,0,512,814,386,197,862,572,507,613,303,348,574,325,200,992,59,918,656,825,978,929,637,921,304,610,967,81,710,10,363,68,362,227,234,748,777,448,672,284,61,975,984,636,300,184,628,711,102,637,536,432,918,525,354,222,135,673,303,198,35,19,618,398,598,852,498,375,300,171,11,713,498,996,701,151,180,682,862,635,671,751,419,589,276,125,812,764,150,467,962,186,838,580,936,437,784,434,164,84,957,176,149,456,172,203,959,704,885,821,691,556,572,111,145,201,588,309,965,739,129,279,925,967,859,213,756,995,999,921,79,957,97,580,765,621,783,724,325,668,897,17,576,822,480,74,23,68,383,988,807,512,267,84,832,478,297,588,473,297,509,904,606,958,484,723,579,620,799,905,640,48,274,217,870,754,643,893,174,26,233,982,891,852,418,75,330,716,663,155,365,525,59,323,483,896,46,63,868,845,320,508,245,594,77,116,700,720,361,874,99,947,208,990,799,627,65,482,695,80,637,60,605,49,735,89,297,781,152,165,978,824,25,223,770,103,691,470,823,53,696,922,352,905,264,151,884,681,985,579,762,975,991,367,376,726,808,673,859,960,190,837,136,215,412,906,318,456,728,494,861,425,416,213,682,681,364,566,362,702,145,476,677,136,844,53,214,652,78,73,965,268,262,101,835,674,360,154,130,88,0,991,865,416,556,547,449,273,465,164,975,962,640,652,450,484,57,664,489,135,737,806,755,999,259,590,26,619,96,508,60,96,852,925,865,408,825,314,681,290,478,656,605,471,660,55,307,717,72,796,204,161,954,311,161,566,254,539,185,702,47,597,799,251,523,16,660,700,682,693,990,513,702,947,984,362,3,291,432,75,440,988,236,394,300,749,312,554,640,850,256,40,447,407,291,322,775,303,22,458,997,365,971,699,312,307,413,315,598,197,742,390,186,331,137,838,432,449,744,73,299,352,113,747,112,404,69,887,60,444,697,57,809,668,108,121,975,873,789,926,71,883,316,609,214,453,799,999,903,895,72,202,247,537,301,711,293,723,599,353,167,648,410,976,669,870,449,996,744,238,922,167,122,591,776,688,44,927,687,299,822,111,854,69,648,155,133,294,230,732,647};  int k = 398;

    int l = sizeof(m) / sizeof(m[0]);

    printf("%d average is %f.\n", k, findMaxAverage(m, l, k));
    // k = 7;
    // printf("%d average is %f.\n", k, findMaxAverage(m, l, k));
}

#include "./726_number_of_atoms.h"
void test()
{
    printf("%s\n", countOfAtoms("H2O"));
    printf("%s.\n", countOfAtoms("Mg(OH)2"));
    printf("%s.\n", countOfAtoms("K4(ON(SO3)2O2Ossss2)O2((OA)2)2OOsDOb3X"));
    printf("%s.\n", countOfAtoms("XXXXYYY3"));
    printf("%s.\n", countOfAtoms("XaaaaB3"));
    printf("%s.\n", countOfAtoms("(XaaaaB3)2O4"));
}

#include "./355_design_twitter.h"
void test()
{
    Twitter* obj = twitterCreate();
    twitterPostTweet(obj, 1, 5);

    twitterPostTweet(obj, 1, 5);
    int rs;
    int* r = twitterGetNewsFeed(obj, 1, &rs);
    out(r, rs);
    twitterPostTweet(obj, 1, 6);
    twitterPostTweet(obj, 1, 7);
    twitterPostTweet(obj, 1, 8);
    r = twitterGetNewsFeed(obj, 1, &rs);
    out(r, rs);
    twitterFollow(obj, 2, 1);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    twitterUnfollow(obj, 2, 1);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    twitterPostTweet(obj, 2, 9);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    twitterFollow(obj, 2, 1);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    twitterUnfollow(obj, 2, 1);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    r = twitterGetNewsFeed(obj, 1, &rs);
    out(r, rs);
    twitterUnfollow(obj, 1, 2);
    r = twitterGetNewsFeed(obj, 1, &rs);
    out(r, rs);
    twitterFollow(obj, 1, 2);
    twitterFollow(obj, 2, 1);
    r = twitterGetNewsFeed(obj, 1, &rs);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    twitterPostTweet(obj, 1, 8);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);
    twitterFollow(obj, 1, 2);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    twitterPostTweet(obj, 2, 9);
    r = twitterGetNewsFeed(obj, 2, &rs);
    out(r, rs);

}

#include "./588_design_in-memory_file_system.h"
void test()
{
    FileSystem* obj = fileSystemCreate();
    int rs;
    char** r = fileSystemLs(obj, "/", &rs);
    outstr(r, rs);
    fileSystemMkdir(obj, strdup("/a/b/c/"));
    r = fileSystemLs(obj, "/", &rs);
    outstr(r, rs);
    r = fileSystemLs(obj, "/a", &rs);
    outstr(r, rs);
    r = fileSystemLs(obj, "/a/b", &rs);
    outstr(r, rs);
    fileSystemAddContentToFile(obj, strdup("/a/b/c/e/d"), "Hello");
    r = fileSystemLs(obj, "/a/b/c", &rs);
    outstr(r, rs);
    r = fileSystemLs(obj, "/a/b/c/e", &rs);
    outstr(r, rs);
    printf("%s.\n", fileSystemReadContentFromFile(obj, "/a/b/c/e/d"));
    fileSystemAddContentToFile(obj, strdup("/f"), "Hello F");
    printf("%s.\n", fileSystemReadContentFromFile(obj, "/f"));
    r = fileSystemLs(obj, "/", &rs);
    outstr(r, rs);
    fileSystemAddContentToFile(obj, strdup("/c"), "Hello C");
    printf("%s.\n", fileSystemReadContentFromFile(obj, "/c"));
    r = fileSystemLs(obj, "/", &rs);
    outstr(r, rs);
    fileSystemAddContentToFile(obj, strdup("/0"), "Hello 0");
    printf("%s.\n", fileSystemReadContentFromFile(obj, "/0"));
    r = fileSystemLs(obj, "/", &rs);
    outstr(r, rs);
    fileSystemAddContentToFile(obj, strdup("/a/a"), "Hello X");
    printf("%s.\n", fileSystemReadContentFromFile(obj, "/a/a"));
    r = fileSystemLs(obj, "/a", &rs);
    outstr(r, rs);
    r = fileSystemLs(obj, "/c", &rs);
    outstr(r, rs);
}

#include "./630_course_schedule_III.h"
void test()
{

    int m[] = {100, 200, 200, 1300, 1000, 1250, 2000, 3300}; // 4
    // int m[] = {5, 5, 4, 6, 2, 6}; // 2
    // int m[] = {100, 200, 200, 1300, 1000, 1250, 2000, 3200}; // 3
    // int m[] = {7, 17, 3, 12, 10, 20, 9, 10, 5, 20, 10, 19, 4, 18}; // 4
    // int m[] = {10, 20}; // 1
    // int m[] = {}; // 0
    // int m[] = {1, 2, 2, 3}; // 2
    // int m[] = {9, 14, 7, 12, 1, 11, 4, 7}; // 3
    // int m[] = {860,4825, 13,1389, 746,8823, 455,2778, 233,2069, 106,5648, 802,2969, 958,2636, 567,2439, 623,1360, 700,4206, 9,3725, 241,7381}; // 12
    // int m[] = {100, 2, 32, 50}; // 1
    // int m[] = {671,4420,481,6286,248,1026,590,4427,480,843,208,5326,1000,9443,87,7434,683,7547,435,8617,376,9563,900,5643,798,8797,750,8705,393,7240,849,8602,743,7803,721,7094,556,2574};

    int l = LEN_M(m);
    int c = 2;
    int** r = gen_aa(m, l, c);
    printf("%d.\n", scheduleCourse(r, l / c, 0));
}

#include "./698_partition_to_k_equal_sum_subsets.h"
void test()
{
    // int m[] = {1, 2, 3, 4, 5, 95, 90, 91, 92, 93, 94}; int k = 3;
    // int m[] = {1, 2, 2, 5, 94, 96, 100}; int k = 3;
    // int m[] = {4, 4, 2, 3, 5, 2, 1}; int k = 3;
    // int m[] = {4, 5, 3, 2, 5 ,5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5}; int k = 14;
    // int m[] = {7628,3147,7137,2578,7742,2746,4264,7704,9532,9679,8963,3223,2133,7792,5911,3979}; int k = 6;

    // int m[] = {4, 3, 2, 3, 5, 2, 1}; int k = 4;

    int m[] = {129,17,74,57,1421,99,92,285,1276,218,1588,215,369,117,153,22}; int k = 3;
    int l = sizeof(m)/sizeof(m[0]);
    printf("%d.\n", canPartitionKSubsets(m, l, k));
}

#include "./416_partition_equal_subset_sum.h"
void test()
{

    // int m[] = {1, 2, 1, 6};
    // int m[] = {1, 2, 3, 5};
    // int m[] = {1, 5, 11, 5};
    // int m[] = {4, 3, 2, 3, 5, 2, 1}; int k = 4;
    // int m[] = {4, 5, 3, 2, 5 ,5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5}; int k = 14;
    int m[] = {7628,3147,7137,2578,7742,2746,4264,7704,9532,9679,8963,3223,2133,7792,5911,3979}; int k = 6;
    int l = LEN_M(m);
    printf("%d.\n", canPartition(m, l));
}

#include "./621_task_scheduler.h"
// TODO DO IT AGAIN
void test()
{
    char* s = "AAC"; int n = 1;
    // char* s = "AAABBC"; int n = 1;
    // char* s = "ZZAAAXBBBCCCCC"; int n = 2;
    // char* s = "ZACDEFGZ"; int n = 5;
    // char* s = "GCAHAGGFGJHCAGEAHEFDBDHHEGFBCGFHJFACGDIJAGDFBFHIGJGHFEHJCEHFCEFHHIGAGDCBIDBCJIBGCHDIABAJCEBFBJJDDHIIBAEHJJAJEHGBFCHCBJBAHBDIFAEJHCEGFGBGCGAHEFHFCGBIEBJDBBGCAJBJJFJCAGJEGJCDDAIAJFHJDDDCEDDFBAJDIHBAFEBJAHDEIBHCCCGCBEAGHHAIABADAIECCDABHDECAHBIABEHCBADHEJBJABGJJFFHIAHFCHDHCCEIGJHDEIJCCHJCGIEDEHJAHDABFIFJJHDICGJCCDBEBEBGBACFEHBDCHFAIAEJFAEBIGHDBFDBIBEDIDFAEHBIGFDEBECCCJJCHIBHFHFDJDDHHCDAJDFDGBIFJJCCIFGFCEGEFDAIIHGHHAJDJGFGEEAHBGAJJEIHAGECDIBEAGACEBJCBADJEJIFFCBIHCFBCGDAABFCDBIIHHJAFJFJFHGFDJGIEBCGIFFJHHGAAJCGFBAAEEAEIGFDBIFABJFFJBFJFJFIEJHDGGDFGBJFJAJEGHIEGDIBDJAAGAIIAAIIHECAGIFFCDJJIAAFCJGCCHEAHFBJGIAAHGBEGDICGJCCIHBDJHBJHBFJEJAGHBEHBFFHEBEGHJGJBHCHAABEIHBIDJJCDGIJGJDFJEFDEBDBCBBCCIFDEIGGIBHGJAAHIIHAIFCDACGEGEEHDCGDIAGGDAHHIFEIADHBBGICGBIIDFFCCAIEAEJAHCDACBGHGJGIHBACHIDDCFGBHEBBHCBGGCFBEJBBIDHDIIAAHGFBJFDEGFAGGDABBBJAFHHDCJIAHGCJIFJCAECHJHHFGEACFJHDGGDDCBHBCEFBDJHJJJAFFDEFCIBHHDEAIABFGFFIEEGAIDFCHECGHFFHJHGAEHBGGDDDFIAFFDEHJEDDAJFEEEFIDAFFJEIJDDGACGGIEGEHEDEJBGIJCHCCAABCGBDIDEHJJBFEJHHIGBD"; int n = 1;
    printf("%d\n", leastInterval(s, strlen(s), n));
}

#include "./358_rearrange_string_k_distance_apart.h"
void test()
{
    printf("%s.\n", rearrangeString("abcdabcdabdeac",4));
    printf("%s.\n", rearrangeString("aabbcc", 3));
    printf("%s.\n", rearrangeString("aaabc", 3));
    printf("%s.\n", rearrangeString("aaadbbcc", 2));
    printf("%s.\n", rearrangeString("abb", 2));
    printf("%s.\n", rearrangeString("aabbc", 2));
    printf("%s.\n", rearrangeString("aabbcc",2));
    printf("%s.\n", rearrangeString("aa",2));
}

// #include "./714_best_time_to_buy_and_sell_stock_with_transaction_fee.h"
#include "./309_best_time_to_buy_and_sell_stock_with_cooldown.h"
void test()
{

    // int m[] = {6, 1, 3, 2, 4, 7};
    // int m[] = {2, 1, 2, 0, 1};
    int m[] = {70,4,83,56,94,72,78,43,2,86,65,100,94,56,41,66,3,33,10,3,45,94,15,12,78,60,58,0,58,15,21,7,11,41,12,96,83,77,47,62,27,19,40,63,30,4,77,52,17,57,21,66,63,29,51,40,37,6,44,42,92,16,64,33,31,51,36,0,29,95,92,35,66,91,19,21,100,95,40,61,15,83,31,55,59,84,21,99,45,64,90,25,40,6,41,5,25,52,59,61,51,37,92,90,20,20,96,66,79,28,83,60,91,30,52,55,1,99,8,68,14,84,59,5,34,93,25,10,93,21,35,66,88,20,97,25,63,80,20,86,33,53,43,86,53,55,61,77,9,2,56,78,43,19,68,69,49,1,6,5,82,46,24,33,85,24,56,51,45,100,94,26,15,33,35,59,25,65,32,26,93,73,0,40,92,56,76,18,2,45,64,66,64,39,77,1,55,90,10,27,85,40,95,78,39,40,62,30,12,57,84,95,86,57,41,52,77,17,9,15,33,17,68,63,59,40,5,63,30,86,57,5,55,47,0,92,95,100,25,79,84,93,83,93,18,20,32,63,65,56,68,7,31,100,88,93,11,43,20,13,54,34,29,90,50,24,13,44,89,57,65,95,58,32,67,38,2,41,4,63,56,88,39,57,10,1,97,98,25,45,96,35,22,0,37,74,98,14,37,77,54,40,17,9,28,83,13,92,3,8,60,52,64,8,87,77,96,70,61,3,96,83,56,5,99,81,94,3,38,91,55,83,15,30,39,54,79,55,86,85,32,27,20,74,91,99,100,46,69,77,34,97,0,50,51,21,12,3,84,84,48,69,94,28,64,36,70,34,70,11,89,58,6,90,86,4,97,63,10,37,48,68,30,29,53,4,91,7,56,63,22,93,69,93,1,85,11,20,41,36,66,67,57,76,85,37,80,99,63,23,71,11,73,41,48,54,61,49,91,97,60,38,99,8,17,2,5,56,3,69,90,62,75,76,55,71,83,34,2,36,56,40,15,62,39,78,7,37,58,22,64,59,80,16,2,34,83,43,40,39,38,35,89,72,56,77,78,14,45,0,57,32,82,93,96,3,51,27,36,38,1,19,66,98,93,91,18,95,93,39,12,40,73,100,17,72,93,25,35,45,91,78,13,97,56,40,69,86,69,99,4,36,36,82,35,52,12,46,74,57,65,91,51,41,42,17,78,49,75,9,23,65,44,47,93,84,70,19,22,57,27,84,57,85,2,61,17,90,34,49,74,64,46,61,0,28,57,78,75,31,27,24,10,93,34,19,75,53,17,26,2,41,89,79,37,14,93,55,74,11,77,60,61,2,68,0,15,12,47,12,48,57,73,17,18,11,83,38,5,36,53,94,40,48,81,53,32,53,12,21,90,100,32,29,94,92,83,80,36,73,59,61,43,100,36,71,89,9,24,56,7,48,34,58,0,43,34,18,1,29,97,70,92,88,0,48,51,53,0,50,21,91,23,34,49,19,17,9,23,43,87,72,39,17,17,97,14,29,4,10,84,10,33,100,86,43,20,22,58,90,70,48,23,75,4,66,97,95,1,80,24,43,97,15,38,53,55,86,63,40,7,26,60,95,12,98,15,95,71,86,46,33,68,32,86,89,18,88,97,32,42,5,57,13,1,23,34,37,13,65,13,47,55,85,37,57,14,89,94,57,13,6,98,47,52,51,19,99,42,1,19,74,60,8,48,28,65,6,12,57,49,27,95,1,2,10,25,49,68,57,32,99,24,19,25,32,89,88,73,96,57,14,65,34,8,82,9,94,91,19,53,61,70,54,4,66,26,8,63,62,9,20,42,17,52,97,51,53,19,48,76,40,80,6,1,89,52,70,38,95,62,24,88,64,42,61,6,50,91,87,69,13,58,43,98,19,94,65,56,72,20,72,92,85,58,46,67,2,23,88,58,25,88,18,92,46,15,18,37,9,90,2,38,0,16,86,44,69,71,70,30,38,17,69,69,80,73,79,56,17,95,12,37,43,5,5,6,42,16,44,22,62,37,86,8,51,73,46,44,15,98,54,22,47,28,11,75,52,49,38,84,55,3,69,100,54,66,6,23,98,22,99,21,74,75,33,67,8,80,90,23,46,93,69,85,46,87,76,93,38,77,37,72,35,3,82,11,67,46,53,29,60,33,12,62,23,27,72,35,63,68,14,35,27,98,94,65,3,13,48,83,27,84,86,49,31,63,40,12,34,79,61,47,29,33,52,100,85,38,24,1,16,62,89,36,74,9,49,62,89};

    // int m [] = {1, 2, 3, 4, 4, 5, 6, 7,3,8,2,1,9,100,10,11,9,13,12,15, 16, 11, 9, 10, 9};
    // int m[] = {1, 3, 2, 8, 4, 9};
    // int m[] = {7, 1, 5, 3, 6, 4};
    // int m[] = {1, 2, 3, 4, 5};
    // int m[] = {7, 6, 4, 3, 1};

    int l = LEN_M(m);
    printf("%d.\n", maxProfit(m, l));
}

#include "./861_score_after_flipping_matrix.h"
void test()
{
    int m[] = {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0};
    int l = LEN_M(m);
    int c = 4;

    int** r = gen_aa(m, l, c);
    int* cs = malloc(sizeof(int));
    cs[0] = c;

    printf("%d.\n", matrixScore(r, l / c, cs));
}

#include "./863_all_nodes_distance_k_in_binary_tree.h"
void test()
{
    int m[] = {3, 5, 1, 6, 2, 1, 8, 19, 0, 7, 4, 10, 9, 11, 13, 20};
    struct TreeNode* r = gen_tree(m, LEN_M(m));
    int rs;

    struct TreeNode* t = find_node(r, 5);
    int** ret = distanceK(r, t, 4, &rs);
    out(ret, rs);
}

#include "./862_shortest_subarray_with_sum_at_least_k.h"
void test()
{
    // int m[] = {1}; int k = 1;
    // int m[] = {1, 2}; int k = 4;
    // int m[] = {2, -1, 2, 3}; int k = 3;
    int m[] = {48, 99, 37, 4, -31}; int k = 140; // should be 2

    int l = LEN_M(m);

    printf("%d.\n", shortestSubarray(m, l, k));
}

void test_once_sort()
{
    int i = 0;
    int size = 10;
    int* m = malloc(sizeof(int) * size);

    while (i < size)
        m[i++] = rand( );
    out(m, size);
    // _quicksort(m, size, sizeof(int), cmpfunc, 0);
    _my_qsort(m, 0, size - 1);
    if (!verify(m, size))
        out(m, size);
    out(m, size);
    free(m);
}

// #include "./280_wiggle_sort.h"
#include "./324_wiggle_sort_II.h"
void test()
{
    // int m[] = {1, 5, 1, 1, 6, 4};
    // int m[] = {1, 3, 2, 2, 3, 1};
    // int m[] = {4,5,5,5,5,6,6,6};
    int m[] = {4, 5, 5, 6};
    int l = sizeof(m)/sizeof(m[0]);
    int* r = malloc(sizeof(int) * l);
    memcpy(r, m, sizeof(int) * l);

    // int l = 10000;
    // int* r = malloc(sizeof(int) * l);
    // int i = 0;
    // while (i < l)
    //     r[i++] = rand( ) % 100;

    wiggleSort(r, l);
    out(r, l);

    // for (int i = 1; i < l - 1; i += 2)
    // {
    //     if (r[i] < r[i - 1] || r[i] < r[i + 1])
    //     {
    //         printf("error %d %d %d %d.\n", i, r[i - 1], r[i], r[i + 1]);
    //         // out(r, l);
    //     }
    // }
}

#include "./864_random_pick_with_blacklist.h"
void test()
{
    // int m[] = {0, 1, 3, 4, 9};  int N = 10;
    // int m[] = {}; int N = 1;
    // int m[] = {}; int N = 2;
    int m[] = {1}; int N = 3;
    // int m[] = {2}; int N = 4;
    // int m[] = {0, 2}; int N = 4;
    int l = LEN_M(m);

    Solution* s = solutionCreate(N, dup_a(m, l), l);
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
    printf("%d.\n", solutionPick(s));
}

#include "./755_pour_water.h"
void test()
{

    // int m[] = {2, 1, 1, 2, 1, 2, 2}; int V = 4; int K = 3;

    // int m[] = {1, 2, 3 ,4}; int V = 2; int K = 2;

    // int m[] = {4, 0, 3, 0, 3}; int V = 7; int K = 1;

    // int m[] = {3, 0, 3, 3}; int V = 2; int K = 3;

    // int m[] = {1, 2, 3, 4, 3, 2, 1, 2, 3, 4, 3, 2, 1}; int V = 2; int K = 2;
    // int m[] = {1, 2, 3, 4, 3, 2, 1, 2, 3, 4, 3, 2, 1}; int V = 10; int K = 5;
    // int m[] = {6,11,7,14,15,1,3,11,1,11}; int V = 4; int K = 7;

    // int m[] = {1,2,3,4,3,2,1,2,3,4,3,2,1}; int V = 10; int K =2 ;
    int l = sizeof(m)/sizeof(m[0]);
    int rs;
    int* t = pourWater(dup_a(m, l), l, V, K, &rs);
    out(t, rs);
}

#include "./668_kth_smallest_number_in_multiplication_table.h"
void test()
{
    int m, n, k;
    m = 2;
    n = 3;
    k = 6;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 1;
    n = 9;
    k = 6;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 3;
    n = 3;
    k = 5;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 30000;
    n = 30000;
    k = 5000;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 9;
    n = 9;
    k = 81;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 3;
    n = 3;
    k = 9;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 2;
    n = 2;
    k = 4;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    // m = 9895;
    // n = 28405;
    // k = 100787757;
    // printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
    m = 99;
    n = 99;
    k = 7283;
    printf("m %d n %d k %d is %d.\n", m, n, k, findKthNumber(m, n, k));
}

#include "./638_shopping_offers.h"
void test()
{

    // int p[] = {2, 5};
    // int n[] = {3, 2};
    // int m[] = {3, 0, 5, 1, 2, 10};

    int p[] = {2, 3, 4};
    int n[] = {1, 2, 1};
    int m[] = {1, 1, 0, 4, 2, 2, 1, 9};



    int l = LEN_M(p);
    int ml = LEN_M(m);

    int ss = ml / (l + 1);
    int** r = gen_aa(m, ml, l + 1);

    printf("%d.\n", shoppingOffers(p, l, r, ss, 0, n, l));
}

#include "./312_burst_balloons.h"
void test()
{
    int m[] = {3, 1, 5, 8};
    int l = LEN_M(m);
    printf("%d.\n", maxCoins(dup_a(m, l), l));
}

#include "./407_trapping_rain_water_II.h"
void test()
{
}

#include "./329_longest_increasing_path_in_a_matrix.h"
void test()
{
    // int m[] = {9, 9, 4, 6, 6, 8, 2, 1, 1};
    int m[] = {3, 4, 5, 8, 7, 6, 9, 10, 11};
    int l = LEN_M(m);
    int c = 3;
    int** r = gen_aa(m, l, c);
    printf("%d.\n", longestIncreasingPath(r, l / c, c));
}

#include "./375_guess_number_higher_or_lower_II.h"
void test()
{
    printf("%d.\n", getMoneyAmount(100));
    printf("%d.\n", getMoneyAmount(68));
    printf("%d.\n", getMoneyAmount(84));
    printf("%d.\n", getMoneyAmount(84));
    printf("%d.\n", getMoneyAmount(100));
    printf("%d.\n", getMoneyAmount(5));
    printf("%d.\n", getMoneyAmount(7));
    printf("%d.\n", getMoneyAmount(100));
    printf("%d.\n", getMoneyAmount(34));
    for (int i = 1; i < 20; i ++)
        printf("%d : %d.\n", i, getMoneyAmount(i));
}

#include "./407_trapping_rain_water_II.h"
void test()
{
    // int m[] = {1, 4, 3, 1, 3, 2, 3, 2, 1, 3, 2, 4, 2, 3, 3, 2, 3, 1}; int c = 6;
    // int m[] = {14,17,18,16,14,16,17,3,10,2,3,8,11,10,4,7,1,7,13,7,2,9,8,10,13,1,3,4,8,6,20,3,3,9,10,8}; int c = 6;
    // int m[] = {5, 5, 5, 5, 1, 5, 5, 5, 5}; int c = 3;

    int m[] = {1103,1106,1107,1105,1103,1105,1106,1102,1109,1101,1102,1107,1100,1109,1103,1106,1100,1106,1102,1106,1101,1108,1107,1109,1102,1100,1102,1103,1107,1105,1109,1102,1102,1108,1109,1107,1103,1106,1101,1102,1109,1103,1101,1109,1104,1107,1108,1104,1105,1100,1103,536,101,990,966,883,872,180,1006,291,315,935,94,337,346,515,856,739,323,867,134,905,592,555,824,377,444,374,53,760,97,818,286,188,798,594,413,661,764,409,942,70,686,378,749,22,236,596,104,549,1105,580,444,388,477,611,107,912,327,502,662,766,311,290,296,451,875,699,454,629,450,739,41,127,107,781,491,685,719,937,577,866,507,363,596,975,316,693,229,634,538,881,742,839,513,29,280,378,718,725,1100,159,806,733,628,255,856,461,931,565,389,498,774,238,851,360,203,510,44,774,134,924,997,866,753,501,237,375,869,946,442,561,447,238,285,417,484,131,868,405,39,247,245,803,828,438,153,21,938,539,1106,414,453,773,623,548,616,850,914,828,138,698,379,927,927,1006,334,753,480,193,500,509,782,735,654,600,515,149,964,796,679,92,552,474,207,517,365,814,358,621,632,838,309,353,756,578,350,432,321,820,1105,811,671,740,888,315,330,746,454,636,532,475,718,426,292,268,934,647,72,634,610,46,462,909,389,560,478,81,983,141,891,940,943,904,670,173,209,991,909,1006,969,783,823,678,200,105,936,476,94,350,1100,694,386,552,946,117,455,766,189,428,897,422,358,182,669,19,346,220,352,597,216,311,723,382,331,265,829,609,731,914,949,821,950,677,715,238,137,160,994,668,930,234,432,279,406,91,640,94,302,982,1102,860,635,395,232,309,650,52,908,723,308,200,534,600,219,591,829,346,742,165,1004,14,389,779,283,786,860,265,870,152,589,894,1003,215,631,577,514,623,971,764,336,269,954,212,212,516,794,31,852,878,1108,199,882,918,968,508,46,818,763,258,313,343,143,658,900,764,577,756,378,539,510,56,798,807,259,1000,313,43,373,507,263,902,696,135,162,1006,985,198,167,739,446,470,424,931,470,314,38,37,60,758,1106,912,804,707,709,53,49,12,438,413,510,691,657,548,169,161,545,144,349,702,225,137,514,639,59,974,295,439,353,345,187,910,248,981,959,299,377,998,302,805,753,154,839,400,692,350,551,579,836,242,1101,52,370,127,33,771,91,319,200,435,1006,377,687,244,700,636,534,67,624,178,215,368,322,396,110,356,736,1004,926,562,588,539,956,300,657,980,61,90,641,603,867,637,322,896,224,365,522,100,422,489,1100,979,199,284,365,651,630,443,997,898,348,576,780,294,866,427,616,270,859,247,215,69,227,528,955,793,883,468,883,647,299,493,617,488,767,324,481,739,110,469,628,448,35,398,84,243,167,691,503,368,1100,709,427,849,579,373,632,804,183,857,441,472,692,400,302,801,67,125,531,167,584,501,957,961,241,31,547,750,64,40,108,335,91,526,526,12,241,149,806,414,348,590,228,31,980,872,822,389,987,695,1106,914,186,493,217,769,867,754,509,921,137,960,246,570,828,115,573,59,254,721,815,944,301,385,965,624,599,778,1003,928,815,892,832,992,727,40,103,584,136,603,496,263,553,84,824,723,189,387,772,785,1108,929,720,742,304,27,356,245,147,701,163,953,583,338,935,301,720,28,227,846,973,65,100,868,140,914,581,671,643,695,799,83,614,861,815,260,878,513,495,16,205,649,959,130,977,236,773,687,606,991,1105,570,46,965,780,528,221,352,542,206,389,331,280,994,182,437,244,50,293,82,408,840,73,357,960,40,583,724,69,532,57,934,92,445,242,214,964,453,908,496,650,288,169,272,272,693,51,858,733,334,1102,132,164,345,831,467,375,757,181,786,279,228,711,713,663,943,917,969,738,816,807,730,94,318,344,708,1001,386,908,725,62,181,199,569,516,20,26,234,119,549,10,388,119,63,91,124,348,999,436,77,1107,233,797,241,542,132,291,885,860,189,600,264,360,141,823,867,504,191,91,613,730,443,992,191,497,425,306,835,414,732,902,561,307,42,144,191,516,425,67,718,605,1009,972,307,493,786,164,987,319,597,1102,392,31,276,573,870,692,221,695,96,295,940,1000,593,324,486,126,830,902,535,538,849,535,500,146,370,628,653,347,938,592,631,320,965,898,235,825,580,447,863,18,732,793,360,667,107,837,136,279,81,1101,159,920,538,649,408,898,620,403,587,900,986,209,562,941,97,787,109,667,576,962,27,651,745,378,308,194,205,786,815,276,438,964,538,318,603,288,207,565,682,784,455,10,335,1007,293,422,137,392,431,1103,344,449,344,431,169,995,967,364,771,772,982,551,726,862,860,672,492,409,227,164,183,25,516,861,374,800,273,501,182,47,547,869,838,881,290,997,866,600,351,980,362,675,521,79,527,371,93,361,122,1100,516,648,677,374,499,42,164,114,885,689,151,422,548,979,646,180,966,854,770,659,824,475,324,336,896,193,49,979,545,162,631,403,800,299,119,641,683,274,745,558,305,887,323,843,208,959,365,165,803,1108,166,970,943,833,296,181,368,687,150,255,191,771,1000,333,60,110,964,85,374,52,634,669,929,299,854,479,248,561,986,393,29,143,353,314,966,991,485,676,21,977,922,202,739,912,878,141,12,184,217,1108,226,193,387,497,482,583,967,72,135,943,807,506,428,151,163,736,484,990,403,495,958,315,40,39,569,908,170,572,434,729,290,651,912,20,490,736,593,799,150,718,733,948,567,503,441,720,230,915,700,1103,401,648,280,431,677,839,681,190,753,105,909,34,98,164,396,579,242,979,720,383,40,443,673,597,289,104,659,509,361,349,474,752,340,96,525,359,925,196,891,21,644,143,397,732,297,783,653,529,752,1104,254,134,149,269,73,428,363,722,279,715,414,743,809,744,829,325,445,97,863,679,460,497,812,847,572,99,620,215,970,714,921,567,839,413,826,902,831,532,615,453,589,371,538,388,457,710,55,892,797,1109,561,599,396,363,436,958,804,46,516,117,102,427,674,931,830,490,176,1004,364,133,447,943,494,327,322,941,27,719,175,166,618,79,755,1005,432,181,305,579,569,811,686,662,581,350,935,753,182,101,99,1107,576,888,822,60,206,134,343,223,196,509,380,804,578,125,151,352,649,447,273,208,600,949,212,523,641,138,267,814,581,356,693,148,235,505,550,431,982,236,644,168,735,366,962,655,482,456,349,121,893,1103,671,835,552,226,349,184,354,606,340,277,304,23,767,529,870,660,302,842,886,289,1000,963,645,305,608,117,751,947,580,986,550,594,811,93,810,502,619,506,450,949,773,745,314,883,616,174,533,261,359,1101,540,349,714,175,996,312,635,89,601,557,417,494,141,571,929,941,63,538,437,504,829,553,591,133,778,197,649,653,448,998,404,330,690,108,496,28,762,473,108,705,20,515,189,152,76,108,435,482,988,1103,976,807,758,557,282,526,96,922,169,887,910,563,207,942,13,45,961,117,508,59,164,871,916,344,13,335,794,438,807,773,643,125,570,391,24,195,907,110,107,418,339,359,323,889,644,326,924,595,785,1105,996,940,636,902,626,639,579,762,419,376,525,405,843,438,786,857,623,36,310,72,796,639,773,110,518,407,426,785,992,554,550,330,836,528,575,804,509,144,556,918,863,72,313,696,852,442,544,817,820,1104,879,606,825,994,706,334,392,475,461,726,371,353,47,197,871,612,991,370,98,889,630,951,303,934,638,145,718,172,952,880,1006,173,476,821,510,525,497,244,342,300,960,703,643,349,890,504,303,223,864,1102,454,485,333,748,761,961,883,821,475,178,691,823,693,509,987,545,24,474,779,356,117,82,401,750,421,633,597,67,846,803,449,291,630,124,381,381,428,606,544,893,774,577,707,810,77,684,345,443,500,1107,142,959,539,533,700,302,157,639,359,345,432,150,978,53,265,349,776,35,946,663,270,62,230,967,214,297,993,550,731,836,1007,215,137,888,738,179,180,237,808,530,573,231,670,893,626,277,233,392,302,1101,45,563,573,618,872,778,905,208,670,978,386,19,183,513,897,264,683,67,491,833,939,406,54,952,290,22,219,865,757,864,376,144,769,291,752,983,411,648,181,423,968,909,432,494,765,671,100,790,81,1103,613,10,330,10,952,962,22,514,817,769,368,535,904,127,168,646,100,570,636,624,983,947,875,758,431,630,419,873,410,842,796,14,843,468,366,137,420,378,641,579,138,351,456,384,468,615,20,911,175,1109,877,500,936,742,248,709,715,10,572,467,842,358,471,27,817,179,507,579,548,138,149,28,480,595,402,290,552,764,543,717,753,410,560,31,495,798,730,200,150,644,657,335,993,471,704,152,640,201,73,1100,330,564,548,152,502,940,432,44,695,318,104,790,718,654,812,555,794,532,97,935,167,745,612,502,558,306,996,540,850,59,61,522,966,599,664,458,882,438,492,567,98,586,347,807,230,149,704,15,24,1102,292,533,879,246,25,427,894,363,309,734,764,360,246,720,302,252,168,174,33,651,731,121,579,420,270,800,912,965,157,926,99,791,449,968,27,816,385,911,521,684,988,275,387,576,986,679,171,144,843,1106,137,916,1009,707,326,270,849,580,577,996,496,18,777,287,976,146,445,703,47,956,729,377,222,106,944,550,127,105,684,960,641,812,218,640,861,535,252,700,457,171,686,944,179,805,573,145,941,361,190,1100,307,910,698,871,1006,984,411,124,79,438,426,62,592,635,692,443,512,287,133,959,800,161,245,970,956,809,457,239,512,638,559,809,538,599,23,886,573,776,1000,994,204,769,46,786,394,81,219,248,710,1104,549,500,845,785,460,791,936,260,372,438,888,274,589,768,863,954,644,779,721,987,115,267,746,152,44,482,575,605,720,275,642,259,117,477,386,568,611,312,170,973,92,48,237,24,806,443,968,440,564,1109,417,669,937,505,811,323,977,728,270,39,345,902,641,453,722,17,363,323,672,523,638,106,561,866,120,709,651,79,491,205,100,899,864,379,746,18,692,714,736,305,743,424,197,374,867,261,734,220,574,1108,733,203,844,636,411,955,335,404,376,816,599,466,57,805,836,794,813,870,850,892,165,583,658,705,300,515,956,376,77,873,114,800,418,300,778,171,245,103,565,611,261,154,420,661,301,598,445,457,458,1105,691,966,210,339,661,852,844,959,570,911,174,674,53,582,965,821,743,552,266,650,506,869,146,268,520,438,856,307,885,304,934,566,260,135,895,263,329,81,565,890,334,729,906,377,654,213,540,739,756,1106,380,604,655,868,862,518,296,708,815,523,354,740,431,957,217,668,210,888,739,117,768,63,189,17,782,185,220,312,914,318,450,636,912,96,495,116,956,133,814,761,647,511,843,420,458,402,79,10,281,1100,118,391,566,297,398,338,472,961,993,728,269,433,355,524,871,192,982,817,667,139,921,304,640,754,67,88,147,136,88,770,638,196,151,194,835,892,875,649,843,858,368,454,633,65,320,495,599,293,654,1106,422,565,903,52,310,960,130,799,438,560,559,66,747,52,251,924,934,468,564,119,668,274,564,291,329,226,128,270,509,773,516,273,328,409,315,980,711,787,121,139,338,22,196,427,65,789,693,989,599,1107,99,257,863,1005,890,534,221,1009,794,721,124,653,336,794,52,642,117,106,771,228,235,451,241,773,220,296,904,904,627,845,493,68,92,347,63,325,223,627,324,1008,690,790,651,16,574,45,648,33,141}; int c = 50; // 353397

    // int m[] = {19383,10886,12777,16915,17793,18335,15386,10492,16649,11421,12362,27,8690,59,7763,3926,540,3426,9172,5736,15211,5368,2567,6429,5782,1530,2862,5123,4067,3135,13929,9802,4022,3058,3069,8167,1393,8456,5011,8042,16229,7373,4421,4919,3784,8537,5198,4324,8315,4370,16413,3526,6091,8980,9956,1873,6862,9170,6996,7281,12305,925,7084,6327,336,6505,846,1729,1313,5857,16124,3895,9582,545,8814,3367,5434,364,4043,3750,11087,6808,7276,7178,5788,3584,5403,2651,2754,2399,19932,5060,9676,3368,7739,12,6226,8586,8094,7539}; int c = 10; // 79058

    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);
    printf("l %d %d.\n", l,trapRainWater(r, l / c, c));
}

#include "./745_prefix_and_suffix_search.h"
void test()
{
    // char* m[] = {"apple", "bal", "pla", "xla", "xxala", "xxxxx", "xx", "xxa", "xxb", "xxc", "xxd", "ddd", "yyd", "ddx", "yyb", "ycb"};
    char* m[] = {"apple"};
    WordFilter* w = wordFilterCreate(m, LEN_M(m));
    printf("%d.\n", wordFilterF(w, "a", "e"));
    printf("%d.\n", wordFilterF(w, "", "a"));
    printf("%d.\n", wordFilterF(w, "b", ""));
    printf("%d.\n", wordFilterF(w, "", ""));
    printf("%d.\n", wordFilterF(w, "", "l"));
    printf("%d.\n", wordFilterF(w, "", "ple"));
    printf("%d.\n", wordFilterF(w, "", "pla"));
    printf("%d.\n", wordFilterF(w, "", "apla"));
    printf("%d.\n", wordFilterF(w, "", "pla"));
    printf("%d.\n", wordFilterF(w, "xx", "la"));
    printf("%d.\n", wordFilterF(w, "", "l"));
    printf("%d.\n", wordFilterF(w, "", "l"));
    printf("%d.\n", wordFilterF(w, "", "l"));
    printf("%d.\n", wordFilterF(w, "", "l"));
    printf("%d.\n", wordFilterF(w, "xxala", "xxala"));
    printf("%d.\n", wordFilterF(w, "xxx", "xxx"));
    printf("%d.\n", wordFilterF(w, "x", "b"));
    printf("%d.\n", wordFilterF(w, "y", "ydd"));
    printf("%d.\n", wordFilterF(w, "ddx", "dx"));

}
*/

#include "./719_find_K-th_smallest_pair_distance.h"
void test()
{
    // int m[] = {1, 3, 4, 1, 10}; int k = 1;
    int m[] = {197180,567032,701885,294688,49821,319144,793670,35956,30654,462823,954237,828852,85004,156833,193021,362217,197278,327502,82298,521188,951833,265111,760577,510602,668226,3307,908042,352949,860824,129537,908611,25249,417829,291862,465673,534186,369397,683232,173430,18207,82787,876718,391394,475845,722608,190000,969787,233166,662525,607653,200810,935100,640383,693229,625474,122557,533527,260952,707482,765465,845266,157430,435025,90838,620046,538885,587099,596938,443819,627769,682479,56604,286713,267635,810558,457445,369187,956105,591738,68417,48665,381853,999042,500394,630032,323115,736066,650057,579736,492572,594889,681727,648476,489128,546548,374299,783065,38284,13220,596704,598511,384239,638410,55052,936220,399790,922645,771376,626086,623725,130425,34870,312207,925749,660887,584385,191057,200707,583676,297674,117068,113528,42937,94302,896727,371017,964230,600323,856003,671048,276365,771512,3835,306347,525872,295193,529473,963721,601928,136931,129565,459260,140827,904512,987024,436624,489672,82935,960898,859620,843811,32944,828990,201443,937507,585595,70375,448112,933974,569408,236339,971838,379143,498500,546479,56608,610197,117083,470717,78277,439988,425379,615416,514394,296548,271413,76011,978081,603937,393688,273149,81525,880102,364966,364381,272250,317743,552991,195896,918495,869437,638686,466379,537575,803871,890732,747277,626373,201056,341977,189149,259704,36461,434740,613412,21800,978801,762134,307758,814170,195211,658684,989269,93562,580701,407882,140920,599676,551519,772480,922489,783429,577383,876213,150333,95805,943354,1815,773057,936455,557840,573860,696063,240428,132502,906863,110557,970566,262927,322797,238051,775953,691630,221805,679158,229601,387288,549635,147070,165593,742521,723065,476921,22860,137692,621763,110984,818869,9460,636648,117176,631137,664359,279407,12375,260199,462089,862555,828749,902128,560565,458550,118747,197335,535240,360820,679017,643935,374215,714356,896603,61759,7125,691590,22273,774046,392237,90279,659709,891104,484757,281464,886138,17869,47516,121401,136681,531063,301053,95468,645767,154683,861940,981055,772378,458822,510786,667702,897655,93896,154311,979714,242923,321638,896685,282348,606268,905787,418330,126778,150270,326502,680627,394,622114,979631,974401,387808,236432,143990,551797,979906,477188,703793,129928,670854,426538,318678,228140,971328,998219,650386,508009,64167,727696,885179,730394,401257,159439,927117,281326,632924,414042,563269,35018,532472,97627,155052,888771,604117,390350,971798,849885,829612,17184,838357,860317,975320,494257,482182,175805,265029,732863,81541,475487,345034,591676,788846,788335,434100,512869,142266,276883,159383,543296,645572,844360,544748,530566,441608,626208,595451,788244,38129,965907,6475,559988,278906,903361,411616,606767,298266,280090,331740,543601,4289,990479,131651,510330,298111,445022,692353,538452,678540,276344,416483,771474,242780,135645,796355,409593,870923,109422,632455,872740,512578,325021,684730,572102,90258,580077,179525,298448,333323,917066,578630,701530,568637,193656,863330,899504,265380,536558,59592,728252,605281,885512,984888,558937,873510,586455,896449,547050,845741,913377,290062,2595,771493,446140,423256,910729,366719,559481,725190,13466,557895,21697,302767,984904,734345,284393,8670,740881,351858,989249,130194,944115,696781,162129,771026,601439,163705,950662,859846,27005,899816,435139,247523,343790,97381,401373,914843,426395,952446,318514,429013,706227,448630,236511,201989,162606,898963,412648,932782,431170,903346,43288,317790,692510,763717,270754,478441,883868,287135,940846,97256,330719,752417,370197,264251,603678,516620,193141,136381,788313,675601,573069,891293,822852,159055,461520,82631,507049,661084,567251,268684,720805,668686,529552,372260,249306,957404,643578,923664,635606,899776,917487,41512,392265,291646,887338,23163,153985,202402,152565,363200,928030,164426,487735,962176,560435,221493,889385,980431,846174,843827,431929,797050,4130,208076,728367,793299,797987,575597,86975,318983,524654,945873,635639,593132,345910,910226,805703,938781,575958,606967,315567,722457,856262,620516,548556,421284,32866,477522,356809,737976,585153,695598,388779,857475,26292,605658,295266,778950,611057,321321,228628,526179,927480,865843,765893,233688,315017,694910,257967,964064,544128,606643,135407,717710,515726,641216,953480,571063,657188,65344,814170,347945,819442,287626,633939,299528,705240,495224,281339,555593,911630,765400,451430,62960,971989,620830,250028,415037,348769,738027,750184,362865,396049,893686,782157,161747,172721,138915,521915,504092,405586,662543,471933,362044,548218,274433,587072,543147,672696,993553,936389,237981,605162,556298,799299,473530,678492,560934,583177,763173,714624,278096,816224,494356,798547,258655,842530,619873,862897,245485,243523,260043,797014,990717,707342,944342,566721,197076,736850,36777,336616,961796,366950,537168,422914,434049,1442,520290,138071,583219,484161,722352,402343,972482,687957,570516,177653,195761,939239,963537,521486,357704,106892,438854,532776,368633,360796,494022,102371,671304,17947,238659,416667,168943,280214,53180,709044,44094,959832,129038,771431,942598,49135,562780,734285,126809,514109,217519,158822,96225,795261,659474,869970,122026,557963,29702,568768,993741,255043,402084,9948,910982,552521,266726,503273,487330,109913,697890,819901,410910,556547,705826,169242,754342,643277,291015,402205,14542,124687,708094,174311,944730,540390,74269,442421,992878,466858,767999,368801,520964,622857,877932,454307,59819,769142,94812,351694,194701,617641,611086,435933,438039,379440,216080,302644,565559,276803,247497,624969,25134,569641,645354,246817,882209,492821,567117,373456,326874,804688,747092,827878,365412,518317,255460,784764,18319,761054,536202,814815,787045,241070,185778,737519,770870,177149,572205,990096,938570,141722,87562,916611,212228,419607,196269,810309,137899,260418,599992,168151,790397,938582,32951,822993,730875,785237,762741,972643,574948,666462,654687,316075,499059,185381,40791,657698,993842,876982,629090,888648,115628,505570,547939,754928,856966,171158,243635,297309,444684,915873,506139,65457,182836,910261,285579,541492,720362,90168,906013,240911,984588,339175,274630,830227,540225,773311,678958,833766,739114,138863,643530,346066,936330,30325,912691,246626,961428,245578,255104,979704,248171,653069,42054,493713,73880,989630,26066,360072,217194,471208,530511,294235,979067,77774,876554,531491,531929,861336,253883,868970,245116,993151,518046,997241,595451,411888,371395,368434,208904,463918,640801,412051,246548,121914,845571,729834,96644,292060,922913,440516,855199,763623,2834,337755,296897,914276,841187,464834,801906,804831,442523,232495,699364,912716,206965,834329,439203,447070,560044,303228,728308,58709,189382,547193,815611,707779,233235,583605,761298,122313,633709,392716,84716,30564,844372,806994,330500,155800,177840,707376,901555,813587,605694,524233,406760,7613,447052,105177,816752,948700,564277,408249,464174,514329,739975,589676,152165,708938,769700,988758,144764,938811,429143,964066,802117,514990,142507,655498,660259,79727,43326,787556,293121,880253,323632,665689,579346,747669,923670,439130,24495,195570,486810,454711,559970,658784,330733,851052,394267,296669,830328,448248,958380,475200,976363,617718,561004,978699,977703,884150,747266,413622,41599,47052,500278,529384,916731,516235,381877,363127,494730,492683,813876,268904,158255,636861,186156,361660,21557,498565,298022,770405,834343,99885,184194,807717,45427,777067,427623,438643,932434,804568,324789,726992,423130,771540,260512,612068,627285,837393,58997,342724,976482,575930,8867,301046,851918,75024,964463,82488,431774,533362,150838,309271,79014,481765,881159,645353,939537,271051,834105,66965,288483,961641,701880,761472,250899,906914,762772,764645,415599,922715,440830,866787,586557,989973,542631,949276,214171,666047,560663,217817,851017,958413,965335,800209,873515,572566,356241,150921,791920,139845,569774,32065,78047,860517,196276,187443,128562,133682,151674,207978,489975,151454,808127,113620,955288,657820,545580,805746,486414,423127,137311,691099,757170,563178,549713,444979,27099,543962,899319,94763,716154,397716,294219,27748,231604,585419,707587,215600,813601,855956,610743,383755,25112,800671,223594,809757,982545,731585,104923,380043,90668,691949,935321,185917,471685,268957,815173,925878,731903,171280,622105,582672,428100,363410,529336,207875,499781,360509,49498,499774,311021,945282,483201,994527,606152,602501,486726,407084,488849,176121,699060,779425,543589,864540,38408,396423,549453,944094,573443,365420,706941,372792,115072,825835,424338,86166,276640,755658,437577,699030,987017,372965,820541,696245,125464,975310,722544,148149,627441,142933,537474,876461,707447,244048,791845,904507,558954,333536,365468,530203,796905,55498,258553,102893,422976,432190,227076,392889,679800,319156,393406,479004,768337,765995,843998,54491,179250,839033,572420,94613,718463,417703,45467,126304,936693,391578,693297,437036,391905,802332,756145,529841,943609,756258,914098,506736,125337,807596,109416,492293,563341,770274,989862,145705,365524,309275,997021,333032,705714,8954,25138,227866,944696,665664,772860,812837,474026,731129,875920,898776,103210,256965,169501,653111,192266,567681,40311,974575,573241,432818,809247,24321,107816,778615,531109,536285,82416,359723,656922,913249,57304,558529,908219,60390,402343,982695,32981,946606,966295,844320,704478,639714,251699,467431,140366,190446,971551,35940,29988,568025,388157,593820,856662,240874,239601,137385,939713,468473,412571,929177,851960,17084,681517,350622,941710,154127,240923,593910,491547,829259,506098,838780,179240,542284,196754,493190,980305,611074,799220,268779,209118,366446,925055,347413,640269,861330,535487,868203,574357,287504,854196,57515,889212,897774,172859,510005,80366,593042,703196,259776,413961,289446,185127,508919,694452,902407,373037,325073,61352,323584,440512,910215,26904,691804,665458,364913,664904,950599,577159,825577,519443,113249,407742,371124,634982,882451,654245,619070,635692,46239,869116,670389,1178,739047,116167,601107,539492,985452,364151,351134,794692,440037,214915,1008,441540,360834,208547,195723,663975,930361,814908,429207,365901,166420,16347,22444,504243,543754,473508,112128,745908,701947,940495,975090,611724,716273,841772,467480,478866,12502,612038,323016,456645,866878,440364,884525,527988,499317,740370,352037,470443,487362,369199,92179,317273,254299,354914,115031,635139,706136,116984,438009,674234,391688,705838,365495,702295,335848,257630,437409,165324,316903,716769,834429,738506,230127,506257,819441,713117,115614,334009,65575,561109,984858,54674,236133,763868,478983,452755,179204,69600,104731,81161,332687,3372,851334,416088,307383,466042,593339,811825,238319,323662,715685,133692,895037,540699,977545,177135,188844,119812,37389,589374,281603,917,224623,712432,118722,746748,264988,825257,634379,771020,357686,380583,315795,943412,400260,592507,494387,579488,448088,181941,949371,909421,8612,486808,931308,913636,495934,603,558165,47515,720721,620780,936662,803130,160556,868039,72573,3867,669452,115972,978387,307995,704740,361456,925026,965123,297222,966715,241999,552202,672857,303851,942098,16325,492994,598936,353336,459357,723540,783227,956263,411650,934775,203175,994379,13551,140654,342221,372036,195501,317154,647446,791153,980800,273155,839642,418881,965073,762273,547051,785092,190000,131861,743947,401364,763628,305518,923697,465951,631582,328784,665284,151487,679969,41349,852916,749702,80142,518247,991487,993676,52519,878154,529954,2349,213444,19676,860405,331753,455367,185432,595363,440451,727791,124949,89259,306262,276698,229646,220673,942485,161640,742937,924960,310775,249847,954443,473570,70204,194252,228286,672606,296969,562994,588384,821765,579077,364393,56025,692814,819218,164959,962813,8351,949375,917609,508695,213765,61566,291726,490425,568155,368856,36342,418992,8653,567270,310612,307726,484530,397339,313111,413243,540835,581352,47534,622988,467552,546798,16053,780240,477922,128823,886634,530119,556236,244693,221555,621597,692058,810802,554585,986761,125677,952795,680852,278153,164596,519072,259485,8804,69837,865984,877882,878137,116717,928987,885740,745956,54868,86922,190338,735914,209441,442294,644449,150431,975710,524794,41073,326949,117506,325312,464414,326643,357374,474892,481412,238754,949206,123977,573472,592813,152273,169779,305259,427149,676521,368013,124312,997304,997827,378218,522239,505109,662680,515729,737769,831515,112856,215620,208078,167428,977313,782128,909695,7082,108416,185576,155533,171202,864991,131768,944446,821672,510622,979791,953772,333412,900565,352841,847747,837781,39001,164900,299419,881986,127894,178796,777157,333262,585220,313656,273073,96706,616344,271251,815390,273887,431689,758389,1769,619253,248649,981165,606416,181888,880655,200350,965013,270487,305814,27178,124969,452599,512991,305460,835077,83372,755787,485919,42276,527611,544853,489394,573799,48484,492550,960760,214242,451423,987915,463234,773220,145810,638649,540532,441259,382719,698005,317977,976626,592199,788830,987770,291623,739529,660345,938667,67594,25460,439829,196445,192961,404486,703532,957522,864329,488212,104980,478587,269007,88741,416617,955007,202587,874526,360666,863798,368014,268746,945029,927135,333984,502225,529971,337973,152269,74447,985853,425638,191581,415499,268373,739055,762391,71525,245774,134864,51242,280010,588893,341402,226874,701916,778215,266157,437762,543835,914133,533844,740050,874357,242473,385010,706940,556090,128518,739448,792895,895569,976074,897992,600164,654374,197781,283770,814498,648582,100034,591767,579438,843759,60640,256990,646960,40462,160059,183756,281191,932120,903371,73298,414671,763831,4713,77833,437042,834233,870451,325289,204468,885564,548923,309040,404198,410419,388402,274697,143017,351474,71755,966297,257641,66442,2630,977980,442474,847244,500339,798800,854673,535288,98062,272948,934722,475362,895652,937253,673301,936654,403495,644050,748806,138989,848843,650352,730081,53707,291546,872326,889821,599917,871995,88756,969786,862807,80883,364533,111670,310534,271167,536529,598944,692888,525646,99803,488145,17013,762177,34358,283391,659994,33071,369860,512381,647203,391695,921982,889580,38283,295605,968947,239866,82741,826458,205194,273055,780039,253968,499349,532470,199402,5825,211114,530513,109825,901070,462030,407741,255242,78669,108340,337679,960804,356226,701677,332062,902243,485516,220568,104886,895089,719513,931161,95887,98592,702289,717281,416464,182518,155812,890227,157096,499833,866887,701155,757119,23522,300827,768752,443560,616101,385845,306332,957064,832948,610586,858154,448586,157021,97414,842834,352967,316046,764931,44685,991278,846098,72829,864474,545917,519479,847624,964604,936514,142804,249078,29914,494591,120209,473143,694904,887767,315377,910788,622688,181443,899656,297422,262186,504640,813323,552631,280292,506617,738345,133984,249257,648504,542019,385922,616068,373741,226613,890606,869983,483492,859105,47998,550111,500819,92154,659468,360847,694965,822391,603091,463675,538000,762227,472477,734103,527216,156169,399648,631991,83781,395642,587395,307752,70495,761355,834751,497051,424449,106535,615874,158979,666047,429743,2209,619175,659602,740768,889559,680516,823146,638694,515470,79024,102759,176084,720381,450342,770893,622234,25283,506103,975958,717071,749893,390081,911194,172219,999338,637643,928348,207881,68196,772819,942140,744056,616318,683358,517188,525373,878671,973586,732532,893521,255025,68169,764453,748405,48303,360784,451874,994001,759875,396761,356730,564398,903411,42965,358941,637343,537633,241137,194807,70408,670985,662013,845816,105390,657202,545005,895523,63973,959933,701549,530947,61626,157857,786259,206568,534641,776564,143916,466844,778727,618490,431340,791300,739399,569880,360808,994730,41591,947986,133142,505978,136408,499730,964568,819852,115609,769678,612624,455661,406322,455160,819683,386511,693523,489411,994884,949986,600856,639650,440754,100545,764923,898797,851607,562669,449219,658057,696734,892438,302277,729194,784936,268843,770878,682823,327371,230771,821880,75821,132518,718494,765710,394926,692127,973865,979682,112981,491766,49275,918115,481580,932591,877940,996231,661541,441301,937251,115050,641195,942038,662056,922349,627868,794458,778082,361731,18358,404603,2727,969412,339685,894690,793717,706702,667045,508135,410742,21537,438235,414094,694580,360678,489843,658522,453121,529485,784009,29377,102280,851573,476831,702553,41743,880047,735385,551456,152528,585954,895331,984138,962059,405225,724580,142714,690646,20115,140989,743974,278050,647388,833949,684397,758971,509038,736987,420011,557962,33137,243121,170820,188702,568675,54575,105544,689132,560486,567574,597581,564874,942583,748941,802382,819886,777585,833901,293490,900820,901869,228547,963740,629782,985992,620677,659612,439414,45229,741885,887782,331136,761217,241826,739564,526878,312079,226230,821074,341684,765224,655355,999840,975567,322683,667089,712679,499176,34697,357264,721758,151288,278809,829840,432941,375315,914121,794842,460921,890478,965935,585823,500812,993535,155139,509996,506062,359360,817254,102471,529888,970569,576046,39787,10492,594685,53714,970688,102564,83315,186638,101817,567768,849518,76383,311520,290414,908524,656338,770561,555909,611049,371890,570454,217717,329081,178228,879618,989074,231432,869270,689799,360433,116990,896363,625208,215443,68743,363203,653474,877974,222737,625581,875969,966998,130464,824042,33405,727716,525627,648883,261367,725282,745218,864457,880251,530646,903051,344774,728926,271763,290178,720782,505154,539993,322317,169586,750221,720249,653702,50862,179595,92833,426010,995395,163610,9545,80517,511453,76585,594693,369616,445401,433151,202147,879875,605038,911648,315265,284449,70590,564182,753395,133099,92640,472766,802533,94066,93050,862433,128375,12447,24942,199250,421960,625440,610620,197443,419031,722414,100456,485703,419838,956023,958882,841686,435205,947425,989969,958384,296656,597648,678992,178851,320241,866796,966262,715427,247065,494294,769285,318264,780857,456222,82945,125743,953875,708311,941798,211162,413713,653838,574669,813174,896404,777940,358445,710338,442031,583926,994642,382324,241767,429278,161804,553441,680428,915472,354428,330251,949116,92777,993738,411401,393817,842710,264605,423510,469547,634759,160464,197302,421605,698439,771471,365743,147610,911013,893992,670597,795217,607441,396327,65531,145770,70388,720735,328846,508932,11917,218722,248336,175998,831299,169520,814346,429929,881782,704112,954799,784527,552015,585158,309869,416881,580984,734248,428180,641300,740628,871659,584917,731646,828436,15341,408594,915765,147299,235082,754033,687468,378845,655030,3197,747155,106008,963554,974050,492958,141620,693268,369145,500573,164350,813422,304084,839721,841855,813789,472028,462608,348137,210911,383089,249182,773567,699676,864279,580267,943127,491580,192492,591124,699066,745894,141624,626763,960822,699830,262481,266514,514589,547672,387757,806089,536772,755456,461998,254781,966995,889482,441408,58601,343863,655552,99128,337901,502691,634500,869585,684080,53631,6494,338840,364471,511628,793599,694384,932576,881832,913903,543806,628236,318960,162877,360994,613790,459879,404837,64086,596718,207921,401911,577727,284023,301199,210114,392689,185386,876410,350485,964635,129439,867344,38116,473870,559844,804337,636086,164590,960115,912611,739793,958775,617625,498114,492435,652878,216338,765990,694300,254125,68333,653280,517202,769915,264350,502147,866068,28675,867017,284367,558690,659976,845331,583732,922928,409984,309747,596235,209669,32624,823718,33609,655005,194539,322190,127227,870465,857175,71981,64877,401795,580331,83207,15634,449198,440613,67212,517272,234554,557048,200047,879032,190391,974461,807875,583097,916161,772973,981084,254366,292824,40234,975222,79395,753932,488312,635928,969227,80192,813473,738146,301231,557195,592631,650168,17654,316838,231043,86123,770035,211861,548854,29055,49905,671686,41669,478540,227105,489269,289710,729206,350150,684714,613407,568079,772239,339691,375291,140816,770015,863814,831058,539884,683849,735618,357141,260841,476666,462405,135976,197329,572429,207492,780725,872489,910913,759883,998898,248617,176033,77763,960802,639218,279853,711911,910976,184430,104797,51668,704211,920218,319843,198211,123155,927162,705850,165488,783481,145239,604960,789154,821463,460744,302425,546945,574733,825258,675498,299087,491760,17516,951541,568357,847324,466517,92965,646288,548719,277919,972766,333740,426672,565738,433342,526954,474964,83653,378746,625790,231935,912042,532701,777327,812418,984876,761427,412136,725218,205012,296526,473856,469459,693274,566779,853271,492891,347936,644844,349377,53257,489546,970921,526209,421526,693935,190034,92751,741119,672472,891141,22906,926358,246287,442006,960860,543731,794029,278717,490341,313167,211296,420765,731555,649349,272001,474267,864068,134620,804108,421480,752149,204457,423846,876667,355124,681355,434661,190882,170404,731523,950652,248313,161776,644453,143199,687938,534562,292719,920336,554015,100684,23561,30292,467053,852980,668315,513154,837850,422834,31376,449041,540434,30111,144208,278880,66789,429976,642615,575006,769267,661195,326880,736413,57596,587625,771893,706469,30099,30894,80080,789435,257607,104603,123931,389487,448707,13099,184366,522267,661196,766677,876735,880754,729099,689526,719673,233251,916577,312044,815605,449225,637688,404224,227994,542073,672489,149339,779875,875986,972216,48476,63318,625908,6781,631315,152944,530793,128822,129884,880758,999026,691738,111052,514156,312053,619631,653785,124565,990524,140669,891940,972514,20456,769893,151193,21783,271957,185960,660754,133102,627864,486706,997852,931576,811717,281165,368216,284850,817109,343739,519690,211908,762134,283284,34303,14669,709768,476503,563840,633291,775066,285948,48740,335812,697514,926515,683612,948882,739450,861873,738068,490500,805713,175478,814469,611575,229974,857246,405504,454612,418426,728706,817780,506990,66151,321225,572760,736029,488456,934647,567719,613749,105745,71929,419599,375843,995973,789495,356552,840803,170538,39842,687533,168225,652048,662808,166452,368104,687375,580004,28936,580674,5030,799481,118611,39388,84149,605525,694576,80625,837527,91042,889315,662305,129487,650736,252199,590621,473979,327338,675669,464852,135961,892665,99167,578986,849985,437682,335173,904863,292186,659833,134974,827439,635822,874227,963173,246008,99250,536554,63714,697125,272604,835119,311172,550901,491821,603356,885486,547271,5976,778971,514250,115486,295303,626278,283710,106902,824650,95833,350331,157770,761140,951472,291484,741454,189975,283874,616936,362548,575798,10598,625387,8022,929958,464412,296086,770588,757731,735175,318260,820840,258206,539640,678029,216539,649040,223408,146186,647245,366085,389450,367644,25624,483017,190243,700253,173849,248034,376505,88650,480191,437802,931335,710190,779460,79385,22258,894556,291784,9384,240645,514378,653757,296415,762668,140031,523401,480292,45370,53074,455224,685902,392276,321849,969391,396847,415776,432924,99565,1067,306575,788359,386868,742135,605738,629717,869831,456494,197510,163948,143105,864328,533525,569884,201072,308501,887904,524433,631264,339080,31990,876216,261141,108964,333231,628486,67925,673433,863402,616118,868873,826654,424879,412975,374914,81873,575859,413831,334938,304553,668311,834740,717742,594535,754411,985526,293230,650058,421458,67199,489514,356387,705479,524119,472268,734040,761380,819611,858814,255069,258732,631447,369255,58924,81534,591379,882347,75896,376127,630406,71493,44708,558748,831029,749732,666999,171649,767493,928841,341284,132730,929647,748264,75704,223687,498946,398326,494919,25668,293974,529133,743125,740363,20302,886801,652544,30118,877332,551882,802802,321657,220608,46212,57106,12867,948452,969661,603856,771125,651852,724523,197079,777191,333082,35126,400453,571727,295607,410951,896547,187675,893977,955646,297360,230964,562186,113312,117006,120426,327565,192942,627375,620506,88894,647450,327271,617859,827359,165875,411067,977909,215720,344231,561124,776708,799338,784430,539833,632298,936895,197692,78037,617429,966514,846093,506156,359903,203269,955200,788016,802153,353206,843617,64839,291541,810198,569806,760662,612852,688836,638868,409017,71334,739250,376779,202849,96956,203179,113599,414476,351188,764328,579095,384914,904187,446776,271550,776248,877449,199117,289797,948650,763831,993806,466523,903292,868428,72219,363838,404908,669968,629366,961604,307825,32715,193918,47280,93907,625564,200858,416765,436398,283257,81139,103547,214468,169462,421561,494855,611131,304118,106444,685922,353341,925466,64152,604597,787724,515871,51670,898687,420375,976782,968869,987577,855187,698910,601465,201997,277593,929625,509297,155762,724684,970196,369368,64808,579689,252384,222794,748204,654552,338607,938353,270852,810925,110149,927191,746662,573740,753291,389093,58099,29864,297770,58741,689432,106329,997359,211542,403186,798689,483703,347815,55716,618359,124240,33810,263778,598937,381545,252751,334145,749681,888129,378383,874100,923620,145587,438575,487525,41264,148162,600237,629332,981962,276819,257507,720619,913665,649448,515473,558956,784229,169365,223584,194797,947491,124961,220163,916964,393251,383018,188015,615394,797844,284891,389194,203979,911068,742517,719358,798374,88936,287962,208206,384885,660624,879897,311384,664079,321925,557023,933845,9990,38647,278587,598319,316227,449019,610943,723982,903705,860536,552770,317262,495107,689575,941128,735453,941460,994204,787920,771952,359576,425764,161188,567396,575243,171670,788403,199099,526476,144349,903825,330695,475139,446603,19032,651661,406149,832096,208281,69189,46480,462039,233906,227350,300204,972414,975359,685919,433389,926157,559308,607028,767618,545019,934982,612905,219656,805505,525155,692771,814105,806654,602367,268892,136378,594877,230625,383446,663590,780157,630048,59025,61882,387501,925854,36774,89119,982371,303001,454462,315756,562449,804154,562,572091,282784,247977,67688,53683,800845,814515,451220,907021,27220,247127,716874,446717,84332,491653,423487,322746,967512,418215,209205,524889,822946,165373,583159,904993,582353,656205,386157,280130,261595,90250,751428,359903,552906,174493,745535,594429,750994,995475,657949,963775,459765,413027,391379,270084,723176,876096,922967,513565,629600,378615,134056,141141,321535,161143,418985,87472,88207,949288,193004,935502,749486,925024,866845,446749,331761,39600,275966,326044,212038,287374,189133,812765,59534,61533,308152,926520,794754,565068,888070,57395,439106,441491,605528,428760,486510,507471,44439,970435,84873,166688,751180,272525,720232,496453,18155,259270,33370,834515,581906,695459,851093,559316,326870,600131,743992,233561,568894,140700,408667,512908,590768,405559,561459,502950,551529,320911,827800,922229,858732,961393,374412,584409,795602,398644,262192,199897,689298,231826,510698,995321,774379,236596,655353,430128,127784,599533,45637,953783,738038,911365,500048,608884,660624,41586,731644,9964,168627,586509,357346,922171,291689,890528,618577,770961,801648,351380,155468,713984,832322,117923,691214,775954,976454,223045,3939,738727,425638,519941,252362,327786,928840,140277,263156,812633,890739,896010,757853,33008,699500,715476,129185,433389,892541,787359,712567,195911,247307,492584,5535,950618,489210,664614,674523,384041,264121,603957,208815,804780,320268,75439,422667,830717,751704,220366,606412,251427,751235,446455,559728,555778,769432,608646,147738,315795,26824,763639,421,586864,532523,150472,570228,134634,892774,967488,366547,261152,170024,652240,200280,427586,322907,623030,623365,19562,745548,299900,244506,636221,747110,756714,232727,347565,601280,137287,940865,79781,851361,751001,138869,910766,971975,908106,952322,519391,602317,235079,119936,253732,923246,187503,292707,126507,509598,163907,431424,456566,613354,179356,423282,512071,37760,80819,975330,77189,57176,791470,303015,418088,615446,705623,320471,308802,848711,421389,782941,198137,632732,883874,262408,996569,38860,975650,482477,17237,245632,132259,119247,199790,50736,269881,762137,562554,724421,820534,630902,298326,868009,440661,624269,242030,219705,616440,101065,251620,463887,668701,881721,728925,146726,683497,648453,987687,302014,2524,790124,453819,868198,459907,995106,99888,849162,819871,178713,417930,502295,800020,705759,852743,730262,527439,96994,230732,929354,562121,898907,586873,349719,42435,579497,829467,693991,737507,829031,280998,553326,559145,166037,823771,557511,901995,976061,328321,582876,914140,532563,556032,10995,628024,509793,994123,121587,330895,315069,426514,462329,401612,886308,333628,565003,744693,791239,183792,815049,78580,584996,336341,115692,356326,336379,690213,58987,966817,328098,731193,790663,688531,427728,350387,401669,418891,82577,100523,856424,838244,612054,880977,633611,270349,861311,141682,88009,78692,43188,943899,889452,743680,361823,988119,163216,754037,391341,339034,577905,900703,441293,534254,747933,343469,214207,115571,743407,959568,548052,78411,892510,541475,988180,660037,929713,825487,327637,611942,44810,333392,50752,97973,591736,682042,346578,909589,353835,479438,407882,533615,427132,632313,445545,959797,654862,967937,608242,238321,598143,145669,143366,769108,638510,778024,491538,256260,19991,485525,280168,660341,432264,871988,466841,495567,152573,364131,907467,411605,958852,158104,932464,312539,257522,506852,178785,627650,902492,914099,952909,326682,24614,750562,475438,840668,670304,338083,877550,827475,90268,469786,131409,578489,302199,602044,690584,687577,616523,260809,25831,671175,494631,778756,669941,424502,183133,903206,764242,794876,460481,569902,334728,337347,24199,310702,239633,4190,961424,67700,938794,743908,51982,870008,343325,511568,556860,585471,229958,284120,423824,44229,502453,348299,979521,626701,141296,767656,621652,186995,407874,653391,388854,789669,132462,639924,714569,320878,893546,323543,509524,382302,100276,258159,372402,883213,4277,991812,304651,514288,337759,716379,225792,291157,534071,308094,299330,184845,30122,382554,723368,87507,127843,416999,617211,727539,865990,969276,776839,721611,2282,882138,694780,882856,505921,696531,205349,626529,191053,920922,747334,32608,883725,624198,8903,873060,671819,19183,474177,264009,737628,180959,729430,579122,68727,487968,107723,222399,206815,790567,522184,235260,969962,280530,280301,321937,769600,288196,203760,57815,106577,232241,776581,239245,52844,255283,788531,871855,875442,930083,552366,180383,778167,584958,990455,653894,536698,988591,323567,418600,135527,222130,485670,393056,181783,672786,930563,168141,336431,164404,169513,327538,948011,976904,304367,995332,265661,496117,726733,135237,925495,211983,346249,881377,670420,499242,703245,333005,321122,149793,538979,228663,461492,675223,262110,555646,1434,944398,9421,236601,628425,296632,750670,445904,835777,405562,358709,145838,265599,160556,109192,877751,471258,987641,45417,517294,233869,745798,830520,249460,964708,375588,131349,225865,802891,633491,360487,134036,602035,158644,705457,305050,388487,913936,712448,754309,374808,386655,567580,621715,965267,512449,605666,449737,190577,475988,452323,535201,45148,945693,543758,650785,35267,686763,886313,411378,562070,342543,234378,504870,979776,68150,114189,105161,3574,740037,44188,688468,1302,604288,658357,781513,979610,506470,764354,346910,59078,858029,849518,924790,831632,522375,369825,56887,104862,586231,50059,274540,615746,48155,495673,2214,425438,42973,339224,57782,983238,159499,606618,935557,819305,649881,714035,874102,930195,194624,717232,346191,916383,313176,418389,96757,914701,316975,262815,515698,442350,345649,82835,67737,365540,370088,588578,946211,612084,559225,724478,485769,92062,288789,605292,813312,622341,706005,339617,749369,653663,351501,350279,468019,834880,610745,248123,404150,799670,663652,279156,632045,104469,930006,925464,739495,849041,369865,191927,755145,205875,408808,877704,543450,358692,622355,219060,212010,707992,172084,496648,335087,744217,754843,643159,595521,229994,393561,715216,192458,123991,54768,584229,524542,481834,874896,282444,149118,750606,397747,379004,867698,317087,60707,339913,365468,748672,805960,20114,788301,203946,508697,420883,187291,421379,222404,871160,539730,215136,272435,312896,52813,482963,571743,610963,93968,991784,795733,570803,956418,363593,358116,311981,506427,305387,259641,822583,337560,186279,628776,987383,267182,626224,514872,542776,644036,90580,477623,593741,96602,190086,838513,594983,161840,205045,293721,84028,760943,381814,661593,24832,921867,961857,894035,77936,929527,741941,998069,97810,870892,951418,833754,513990,179110,783113,810942,692256,368735,248368,868438,874629,358842,804141,152056,534927,811956,498152,92132,393956,981401,979192,878989,254824,452106,537647,326031,510513,410375,404274,281760,904284,789150,896858,485347,287987,567686,274533,92169,324330,967702,620548,778758,333963,473152,234472,49107,130232,169422,670872,58158,850784,895324,905214,4151,563420,626608,378587,117141,765634,517418,919335,617360,161855,190828,598054,776160,958526,854454,683773,849670,881878,168848,635034,807239,168722,902693,658384,63244,338212,709657,778215,533396,113799,891074,704076,64078,67924,730086,961861,787038,502940,749506,866796,965136,161806,346822,607052,409492,23404,753626,104232,859036,36216,400179,267378,697958,435186,898822,293807,928210,972687,764350,747743,621975,895932,216459,150379,855694,960960,39846,797192,106160,8902,213117,623391,157002,670233,386363,981991,627528,980198,415135,617757,620720,60625,627867,834487,16891,853225,195904,427842,42979,579604,591449,116645,482503,104517,57414,122551,5070,618584,762662,749084,213619,110723,52409,520215,697087,936427,33824,271914,613581,214276,79788,903778,739798,411910,200346,113366,842788,969547,666651,697526,985200,917132,544229,648357,111819,437344,175196,391479,922457,16952,232860,341285,414332,232553,134335,208160,193333,731430,892615,678698,215062,396483,41806,213174,158094,705649,561158,250123,556425,452517,276491,838292,257922,886287,861983,484517,667928,175972,877333,858255,240681,668902,111304,802680,1137,410127,266926,241887,983706,75024,429650,936087,15980,225716,440442,260753,500075,146501,464676,43037,249401,504185,157270,134326,20467,56823,430030,945361,620886,235920,482981,483244,248136,336668,983058,59722,468389,303831,278271,727098,94744,141632,424416,585531,571965,791254,45821,925532,487792,780940,904442,753487,471469,193398,94108,90045,546773,42872,3280,294088,317871,534388,926314,199383,771069,369277,901461,871107,398811,348109,325929,517701,147240,255855,848274,106700,847580,896953,682431,799231,556634,752301,43930,677257,211139,519298,910623,60705,7062,833920,510246,257157,278021,190586,968836,497319,294127,864524,333961,147121,773479,528271,886397,932299,408664,915116,339700,366400,203241,484148,3694,602681,66182,394993,578627,509322,635981,962551,660560,182794,435333,163391,860142,715326,988060,209197,320985,624135,405134,441837,224225,329735,768997,977110,916207,588124,554084,537684,8678,474130,30108,317540,206012,295104,95818,985268,580652,502515,329499,970925,121576,962548,801999,395315,126158,115886,576841,344471,172753,92428,749650,540759,324784,9705,309507,323789,486816,568251,704137,699486,322537,271710,283686,991527,3562,974651,279507,37247,898282,947281,689631,720719,347250,620262,737922,409755,341796,226106,4063,88922,754806,234215,724510,710539,285556,431197,687964,954378,157701,27263,741131,807450,160117,990586,264182,499659,738112,451940,605336,726214,409759,788552,94480,35871,309802,472596,911716,902442,353205,56188,882450,535094,254681,49185,389878,454002,464202,326828,863080,977456,629460,650041,995884,818106,164568,242638,267570,106255,622171,745253,753186,537874,678053,407225,5265,270833,865975,833162,555859,18385,506145,470653,376322,949499,820969,298086,231308,52802,2777,908186,315263,674914,398180,930064,498937,580896,517750,126815,875690,491915,12680,121503,390994,747063,966241,153827,154862,850203,136726,64978,934183,338180,739629,193870,62510,683276,403680,41731,511520,873899,325040,408644,972831,214722,572613,83281,95415,691927,393565,188122,806322,685907,773168,851200,455690,405266,582206,49291,76198,78622,561357,268023,150928,989679,448175,977437,939514,387217,322469,203920,630175,248253,671885,449683,16954,560725,958444,320632,119608,547506,317191,826879,92620,958392,590483,275058,367926,854902,487816,155929,690180,372485,307463,670182,782019,942601,546200,71996,650400,319976,256843,971159,918992,827456,336922,973881,124603,199973,689903,91135,478143,447673,455912,950230,496654,692726,505002,517341,559466,90077,114398,988872,138369,250721,647611,661647,337743,231212,585842,532472,51084,232362,945823,637842,531421,380717,27453,542261,545919,398074,99012,181016,351475,800855,946418,925212,840155,217755,736977,118308,652003,647915,553161,767984,385038,11255,735922,858518,667008,475788,900594,415110,698226,373742,521803,715473,342666,283859,894453,913421,697979,720569,336742,289837,139012,294227,793443,952270,629354,54438,143504,342279,437846,205815,732083,7367,690854,230338,584780,645404,584500,413213,967228,604977,711068,261696,454040,427191,248311,292915,274630,727819,925435,700266,848661,894097,215630,1287,963364,883797,387437,716331,234039,426311,412049,950312,183449,317349,954201,133009,527709,38628,421654,50535,92850,793995,228292,474295,204357,981680,696426,628260,926183,4123,584011,339078,763622,931809,754844,379248,741633,976360,286823,691316,996952,964406,558305,976819,642913,670532,909063,626030,321872,262603,851823,571898,556971,276585,730130,632926,115132,997919,525290,487080,550791,970129,906328,309838,3059,539325,15263,684113,508854,882644,567154,189332,93140,350600,569698,134997,333913,25137,36171,641550,230857,712753,481445,457466,973441,511102,291626,21998,173705,540506,506981,912176,927307,95751,17876,278006,855251,265451,562229,208760,8582,294965,507770,641979,404042,838246,184180,605377,928426,82486,918734,938340,192032,936229,93117,989597,638671,395544,99328,408098,169602,894373,519304,705480,736600,261712,641753,343511,795979,430137,199842,917141,910929,420965,902976,901427,407457,422269,739968,457913,925844,313722,229223,366051,934395,391875,392385,354664,325740,278450,276132,576915,388656,855638,620666,969106,410901,865421,658185,440584,901876,788618,418004,120936,740934,143937,398088,836364,32518,494576,878500,647258,973157,376635,893761,213106,69008,553643,433469,157969,491992,995129,321380,611490,638591,477663,980777,380470,988734,719044,335309,21983,833449,529809,751521,910619,852713,582393,420611,792183,906758,659540,118840,737101,385987,282001,42594,441198,290066,734093,650766,662083,639502,53694,853260,54243,119713,889017,232016,185481,240205,374646,786262,926688,807576,895931,336108,878867,676564,676006,182278,586154,961710,308416,807021,707663,895273,484534,140718,382476,131711,840301,455585,324144,369222,265332,513883,197177,798832,391207,145356,143048,965040,395358,551007,687146,401090,10277,950710,974657,764043,505815,223605,565689,149856,895305,883766,102498,109505,932649,621423,968301,402919,321660,567196,752500,66861,279291,990405,179463,815058,551786,48959,811810,881482,917820,257155,401923,406866,424188,14551,807945,680902,513016,752973,10278,702964,823794,431145,64460,916240,953530,354046,821459,842480,72697,480158,574447,204674,782252,700022,756622,119327,131610,375760,425636,615192,600018,492036,459305,428497,217277,876271,843061,244282,661150,989988,749297,986554,591502,396875,121495,194143,395989,597593,675733,145385,587671,623034,196867,266940,360933,486051,586628,677402,70578,322974,767102,123498,807979,623968,92528,917481,423405,432114,116858,517511,176269,98259,629482,945027,437091,260249,153601,199042,446001,810401,773100,273221,885328,61021,115848,440569,522251,202777,374264,832347,206340,839919,951768,906940,577983,700228,147106,538388,367427,317313,632324,740844,270532,215966,965672,703960,716157,412425,387474,552599,714028,532980,914547,410322,997253,937714,15020,607973,797123,161870,559545,885882,735159,799354,330695,483380,911460,389203,412553,228762,716794,962931,166606,272820,335882,995239,618792,702010,571507,180735,496327,14941,434628,857604,93412,530134,318556,233938,179692,332138,120551,253805,977053,120868,763795,365177,793927,372998,277407,170369,667669,223637,350068,529894,852150,998449,629099,463039,266484,889973,742375,560380,441324,475812,801332,133652,103694,529692,154502,681373,427020,658169,30971,102928,668159,242020,421010,970060,698587,736126,227118,358562,463595,643318,852296,622424,859413,417161,516956,493971,347342,867503,379660,264345,664518,923804,343230,824772,77327,592275,831708,56556,324890,273228,607173,78056,662324,245757,718236,724396,940804,939093,486800,913858,301602,894940,749635,330459,513148,466518,537385,35532,181158,6368,127278,246004,467539,25850,735305,703053,871374,293503,504483,527248,838858,648494,817525,498086,7953,275389,372628,870246,103670,449353,599452,495469,951625,277684,554132,867070,203681,288089,984972,137307,945954,432428,613779,612793,674842,309513,573603,626859,286762,60890,764253,494459,105263,70483,627169,20502,67562,203600,711589,495252,757792,474236,502235,632384,779590,463986,564901,283435,934876,859227,11664,528803,32379,177336,863779,809396,718218,593337,604758,600022,252403,469204,988329,172616,931814,379176,115242,347886,584903,229240,325001,535495,841550,475187,513997,679718,628227,644049,79779,629801,625916,963851,447872,783453,731424,289769,508708,308735,915187,238232,695660,212973,633380,221897,167048,808904,946041,305538,574681,946316,63072,647883,688453,877199,804910,705277,440658,555339,712144,471037,755711,721023,505952,83834,298013,77200,967484,230406,451278,173239,874511,380484,200668,789769,400162,398465,259720,539161,202177,959951,466621,13370,793109,541695,416148,121981,351263,626454,598787,838363,951788,250578,29454,718070,66180,122064,393931,374881,655994,504761,911521,872366,408284,79729,98697,783872,668485,635100,352262,383853,277600,869345,606967,467589,59066,720490,728822,654946,232281,240804,235110,632501,833348,760838,747357,559717,975025,825748,719095,16872,293834,39582,203708,946374,947029,731545,483274,56466,478793,184143,197004,580381,798980,549304,931030,167553,511926,424828,624015,206446,428618,74504,574504,859723,498681,793582,52151,226727,81664,765850,431874,158962,345419,177399,382048,895650,444591,68679,76503,429381,540114,509212,712595,592540,185351,578397,923809,114523,99651,64925,228426,363811,212508,930820,310497,986516,663669,977761,986402,411728,709263,472914,67455,720091,619892,986818,20603,679749,902297,116886,493557,48704,277686,149795,339944,432165,740280,408783,244269,148066,954696,553422,445816,315268,252988,158342,164449,776118,624113,833004,876766,67465,361017,756947,207307,792463,487313,14689,175274,898978,408039,319462,687305,798852,516769,976811,518706,898116,107704,245825,613931,711403,797638,109724,155540,180914,247555,483423,184464,533238,923442,90565,543852,207759,678312,763323,336896,971315,32324,490846,178872,326152,592340,683246,865792,134369,812579,347100,344538,13976,992048,786429,164258,583126,226263,403655,796675,631705,949369,645728,950274,833237,854713,22577,928473,386347,7532,700521,379443,996190,652778,596458,850747,600195,110572,343543,347504,781106,309223,379320,613127,740634,725364,815233,818960,445983,784036,763308,675342,359079,812025,680623,999865,813067,760298,913784,763970,580089,174248,363238,208233,430124,859714,723703,403408,461518,216457,264439,844105,361709,495351,150067,605957,607536,529435,314732,942607,205450,794844,35874,362228,963989,652800,996134,6451,554602,806733,16710,550856,526198,605043,158574,125090,4537,925616,700018,787033,943748,750262,952251,476256,535539,740139,563295,258278,356297,356877,639012,626528,193505,55381,826739,453306,323753,388245,603642,964663,950514,226955,121659,226927,890823,112516,579226,440481,151861,598724,691686,26594,184205,782936,896193,912877,103070,110187,166371,273177,426293,178345,194186,825057,504668,641778,964802,745100,797742,39382,203437,273324,894058,136988,215089,21941,279558,184932,718778,298688,263985,370953,191771,214968,39577,335637,890770,931615,480459,494765,107383,244521,258933,190026,723985,998426,796682,587532,49097,253696,852568,452986,115793,713345,469378,251189,11500,227079,914556,388518,50878,836406,934579,8257,143669,360264,226179,475224,709379,40148,19357,47963,385221,939983,26345,765802,75379,108940,248874,162858,676508,898627,527238,86615,643109,114633,607736,454840,116557,231906,515852,108871,566520,74260,514388,134495,672977,261151,760707,894912,392846,501003,869312,257532,124137,457760,605447,575468,338222,433460,29423,682723,270134,319551,795694,619910,195054,618513,230325,53507,769999,509660,84961,30211,986222,710941,698550,320847,576459,28061,439164,399333,413992,505337,924597,639212,853388,503899,152198,569860,553079,343253,821440,85265,370285,500653,856147,101663,682241,442323,17497,474388,73294,114739,17325,669465,835932,410458,439817,875322,593539,368255,102192,294331,849620,261126,333709,757862,64730,670654,144467,77563,799062,457409,284724,61700,823619,580567,100592,391579,580536,563416,770942,560572,334600,478785,70251,478127,791685,752061,992762,776898,199253,196861,201225,264879,45284,91344,978920,347944,941817,844584,67263,963238,373520,853256,990787,176144,783581,41317,387699,866497,970953,600219,634371,573614,257294,977887,8962,532797,76994,447431,441347,480077,335907,427398,808596,634838,532080,218356,683636,773826,20743,145851,831929,783479,896585,588654,67214,453174,768964,755200,223162,540140,876490,470964,608,900466,414991,52934,156524,391832,333866,552417,34071,855813,606891,817832,887712,171791,658085,887287,769990,716260,38344,986018,144698,127331,687217,596543,476133,465883,4130,129908,301423,643805,31725,658579,451285,267626,6096,505677,558139,525748,644899,584563,764028,168938,898153,916807,320716,355030,593858,476690,936957,635907,519977,94981,771963,461713,650628,653728,995836,866234,928578,496705,982232,971519,421917,592594,683804,592668,753496,66434,238045,69186,56186,827166,204185,195025,989795,616010,617170,523555,66334,583455,273507,248766,948895,426633,38007,239491,1753,912102,713531,187901,210907,956736,359162,486738,958180,278959,669549,868734,91963,930223,43386,97271,175874,319239,478653,45972,643508,211096,408911,591389,856085,61740,648751,742528,686994,553119,209264,770113,867949,403218,542909,806048,101882,176929,971047,675686,205475,897770,643599,928675,271208,945288,813038,20068,774874,685171,719465,815101,447415,499453,335116,839737,959258,286180,168058,223231,272827,983564,250515,425320,769948,54453,536134,454799,374007,712047,495909,21769,933051,182542,261477,199616,875674,378211,329316,862117,631793,566810,279742,783353,276797,749668,839777,998148,677228,794597,809246,415736,204081,480185,440799,290789,272578,929621,676876,549551,623539,283684,936752,139830,215662,920757,357675,336768,41657,39692,892596,857260,585827,655124,7512,103693,539762,650377,338866,375203,655450,367816,947935,203757,279214,710830,47039,836648,880598,71770,600213,511852,333679,229330,576566,448035,732261,406334,838218,903181,209159,30241,482248,671599,113831,225311,411881,771378,891680,177931,555182,819107,169831,203624,952110,224012,627508,514722,608744,41858,667974,261568,881736,203663,609962,676470,599417,580949,118485,635313,607066,61348,532020,159595,675407,815116,713103,702629,305028,735230,404418,522525,246096,55772,523703,50416,995345,493187,794205,767888,395641,849918,738964,302009,432476,258899,968824,995215,127332,713602,946097,610797,162419,985212,550508,698438,134370,211559,624349,560155,406269,808301,946215,474436,421684,659174,227571,96998,874959,434829,318150,751537,364548,145591,668648,717643,120659,774465,661288,180805,204597,644954,856333,844535,387975,182271,87579,31843,69739,65078,129065,631808,83330,265936,272307,388794,429977,431513,834170,765023,91909,660368,482659,705484,124987,422402,723330,197740,299043,790621,865287,798030,621402,7299,377040,946946,951911,126241,317249,537977,467495,207919,297849,113323,940525,966699,288419,458761,255640,665369,589653,852191,332753,675009,777930,927666,446251,42973,561828,929800,911254,94550,695383,648167,638,374036,393409,397019,436568,973361,775091,621473,690924,739378,206807,478511,36643,838595,702742,728659,927897,370859,174409,644665,545345,602634,923977,994316,332524,743486,347301,147426,868578,610487,461261,307721,613431,156629,976306,322921,690688,618801,337815,863730,982885,700842,191565,819541,773950,9583,13142,828175,73929,652626,924754,657159,105941,544865,40410,880756,528270,742419,637491,673650,732297,74979,886703,664390,295929,493770,945412,286166,202537,245808,890801,483614,888092,927536,597274,172942,314160,617013,127564,626598,611352,771755,61276,318159,929673,363707,411295,684168,300178,477811,68590,299273,755173,385881,185162,252421,743165,680455,455431,98404,370171,559076,869770,758091,682443,551246,544188,427301,414786,54084,259695,782109,570993,37227,589847,56449,344808,821556,451505,526178,153234,133754,889339,429779,526474,947051,227493,696658,119629,163447,676395,616640,294600,409324,766614,476642,163338,945747,768078,290915,74859,379024,810171,667562,771842,77805,531159,663400,68185,501907,458545,823746,945637,850803,752258,340770,554333,334768,727558,456367,896708,338702,574065,856398,257706,918245,71679,154017,24774,24103,394754,114907,427140,346612,983587,758747,251664,350596,843359,329167,485196,866949,332726,622892,610291,360979,652277,608640,151251,41963,393741,860120,558177,985458,532781,171137,279674,250807,368932,815833,304487,312176,520518,978259,269677,248419,420488,70097,366393,364363,635532,360141,219131,754345,787961,905448,459411,941510,107968,918402,824838,583041,506884,536860,681808,957205,53240,235906,164744,79990,119182,529661,200963,300481,262258,213897,29381,485437,773519,301191,716385,655125,497541,228552,205545,671269,516288,436722,331644,794522,834916,929470,778420,829070,394455,154652,104823,671370,555033,835929,71680,784737,436250,329657,268192,273645,444558,975697,652202,660518,498138,250095,150407,448533,160375,187115,25321,503049,848938,922756,420260,490301,803302,618656,363649,27078,483558,153505,298545,290132,182698,971080,448774,324275,187755,219455,697801,231472,662058,82101,129432,867102,572425,608636,315421,963669,670196,632463,110522,38125,937098,522863,320468,78993,499204,618799,281266,610573,286927,852725,306973,822611,757599,718021,974198,99884,151328,534233,719905,609027,365109,537223,279634,269075,974601,325113,557345,274531,118134,133065,737436,256863,656348,306229,750768,105333,179423,354831,282741,406308,496387,801824,92647,655436,188821,64531,525708,94021,792303,869984,281104,365558,279912,189110,628762,600080,354682,225190,965685,310872,324810,487158,622692,986892,780750,181865,335240,532483,665528,955217,836264,601872,308543,117754,575032,920286,946135,500314,213399,26685,590161,900727,199012,82516,9850,26654,485577,691126,506428,824513,464597,290456,767155,975375,638802,721874,884570,447910,92970,894446,810051,412905,133191,466710,313996,55771,594295,3414,892096,423914,869395,705780,646611,62528,774281,877622,366637,436721,437943,623927,313796,751757,406118,864025,375501,343742,348352,652268,70335,625476,266917,560331,20851,976676,8866,704411,124741,553627,527342,635216,866720,6079,664183,888522,999977,551775,278294,924101,549934,976223,591115,405503,323561,968296,844724,524361,301320,242528,754945,502856,924448,476041,441232,985688,318893,662712,218550,373331,791513,139822,606627,265660,222082,666080,329012,410386,422000,174317,987454,399143,327272,179726,964311,293869,418352,328111,339917,505837,398206,39023,667611,202933,131370,921166,10008,59223,3406,760300,691917,68890,119247,32943,196828,591783,670706,935836,42811,795938,100037,649330,238074,514840,640880,844774,367280,513665,635068,137065,916111,400312,277773,813664,285474,633318,476585,643650,752941,17484,591257,807802,890006,740142,425185,946389,893176,145462,136096,326768,684342,917564,730104,235911,311269,454743,339056,316199,754687,194187,955168,170259,637577,862131,508722,442417,20483,495405,992341,752365,683567,985213,457235,682848,614538,290527,742817,649523,773544,422673,568243,550422,431167,499366,441704,313940,2768,360035,7624,466276,932013,388191,188509,111829,392231,805052,330190,625731,358509,222423,213455,955618,635756,737021,474737,416279,462834,130146,188839,474325,749233,881579,351302,569305,910211,548560,630937,266405,236934,459926,156726,723426,150852,544118,231395,136511,897514,912788,589402,968745,152302,653470,99079,955011,306632,115612,233896,913853,31781,445660,633671,382933,32744,432170,277486,579925,636137,277736,265320,959685,861924,338506,16079,472822,382474,373144,802387,661798,82857,596069,463839,30303,569005,972620,144902,439517,38024,971359,459469,719424,502504,469350,63874,747930,955671,256892,612937,348379,684582,408867,121241,839832,488042,320222,374885,937290,713531,545815,56520,273207,422949,470586,707661,421076,286379,658012,825462,504221,521032,862377,388946,715634,413875,634634,830168,545467,129410,516950,361699,109834,508888,569769,759873,80878,959676,898377,85888,944092,366444,377719,708393,20226,409764,646760,863475,84135,60224,337322,70353,900458,944783,489504,636077,821106,291207,402656,414004,79599,330274,537692,793147,739508,430228,757309,231416,636654,425704,867360,174789,408991,897327,624937,418423,962832,521562,808926,61626,676463,981755,480655,976647,373564,421577,243862,747056,205148,545213,652819,604794,590663,398929,762234,682669,845529,669153,286933,529879,152797,499098,846342,443818,449213,240158,758195,220485,537456,401203,795327,424120,426989,458764,387116,699689,781385,531549,959642,178349,189353,194953,307214,126744,457196,958385,575962,812445,829516,330117,58837,467570,852054,449378,534986,413777,247042,598365,825241,817213,621006,620714,348472,553083,850446,696347,42817,95134,380357,175749,336043,728159,978317,739723,776935,402499,504655,796948,716516,427916,189046,549152,622782,423128,278862,916883,928044,582573,547444,391435,812005,571930,614170,752632,539850,375182,768488,426864,913485,128391,325337,682989,215899,993461,465458,293547,383074,321823,342962,269172,93434,285764,691908,340515,826727,663919,283915,624075,844011,633709,639563,356353,78781,665009,116969,183907,688772,49456,795614,506873,379576,288469,642326,430175,678525,348829,828955,164841,696785,270913,655630,314057,687574,96843,356423,839027,954970,446321,521112,694495,941654,190303,173211,440738,621782,564801,35510,601822,786698,902399,319519,912969,610964,851437,531197,379746,284047,767544,113483,136550,511074,858447,854949,875624,152828,831762,523000,534281,372637,717913,215032,410876,92760,19002,201224,103047,823061,583877,92048,955971,859459,785197,215397,699197,748457,520747,739014,264083,368119,601034,256175,916871,658528,676841,477189,135992,157594,457436,788312,221778,232201,876662,637173,628357,179291,912713,592379,122314,435229,314508,733150,414183,718788,281967,625650,842990,222716,789129,52672,108887,913102,347902,784162,194109,53137,952063,484569,41588,398019,82141,36930,441162,144497,471897,551403,263688,361332,950352,606137,138501,218920,664253,991640,526403,315813,571982,767279,870600,742975,23112,592445,848187,806746,674042,452086,851804,64304,757675,676466,334461,102280,100101,557025,193550,343956,398453,855828,564179,340210,560951,219887,397781,558813,73871,340273,260891,52991,864326,493288,321147,3715,733835,710202,635566,766183,443903,174467,708716,511585,767605,262635,927238,664770,434243,28306,902182,637669,254304,550127,169120,279362,232586,739181,790764,555424,408898,959236,800784,630566,564134,469288,464313,403118,130768,494872,718635,217615,518541,407031,814721,462566,224210,582450,494152,645057,307847,307393,643587,729865,69696,705448,203427,690925,99477,717388,994476,689741,166775,945951,258434,884258,533806,925280,623042,628933,46265,903690,677895,774644,179265,826526,66474,819432,784728,680912,808394,310816,359524,354121,435174,115146,556813,738182,909281,797300,584565,584262,561041,858152,23989,35025,798573,308063,831534,196821,829867,939104,82999,348167,307372,178808,134116,985010,966507,478467,224465,903026,347496,164670,554171,607751,90342,839801,897830,873695,250833,457587,332541,240183,920742,826711,915126,811771,732776,534524,375784,761388,213463,44846,107072,401175,330323,279384,407145,257661,921060,473727,316020,717199,425743,597180,320813,478709,111351,457570,435220,71036,151792,181205,643631,821193,340798,51748,902170,854364,764294,843483,249082,922834,86058,842957,817471,112732,458766,302375,636556,182095,17685,702612,988046,296179,104954,612307,908102,562247,310789,69294,728703,79718,691138,536410,750560,552458,599375,55268,972916,657658,698463,966600,921310,102545,570610,313832,386295,729245,84323,106512,434739,597622,89192,445926,385768,16156,103342,89778,713501,179153,710049,874125,805848,196892,518495,207976,964825,521506,352324,861493,699838,836722,674637,659576,746627,448993,669292,23324,630576,517906,871653,674153,462770,215439,212973,8829,603343,532961,375858,87283,313388,328217,847988,798746,551527,776620,286391,157606,849718,719948,80887,353731,717595,172752,671225,284218,285842,562654,758658,885965,28092,495064,957830,817310,805542,483835,651155,915668,418728,345046,935689,258873,150432,948592,332781,469848,874477,78354,215552,138758,411923,946996,364404,371554,500507,353603,926937,542959,443077,650120,158213,940350,587966,217069,376345,639740,476531,104643,458288,506918,979708,334895,518967,327536,418396,4454,692964,388656,689160,162529,722198,958248,247863,544987,760086,789586,851770,566270,168696,52511,538800,459490,365046,763266,539253,801586,404325,848979,817976,55571,19393,129040,872484,506096,957616,783539,295438,248536,105813,269798,172673,5812,625104,825213,34970,209244,431246,90943,617060,235017,782156,500036,802103,261016,591862,125486,403191,221396,89019,23554,845031,415860,368478,41596,363802,635004,457783,756272,257816,300411,828660,266558,205833,756248,805300,770033,639565,703263,957921,409866,891715,806478,442438,827425,863647,512327,284115,840881,284466,98174,908111,968862,695277,793098,191747,406303,582266,579719,795909,757037,971491,343829,480125,194430,650062,346577,386053,804026,173437,898432,635397,758129,380764,950360,558895,524211,91261,673161,159881,22335,57644,322350,642135,671841,147291,409144,72182,126232,751572,608617,669781,65709,27491,111397,64146,479601,275569,636139,122852,896625,826521,468139,942925,473773,686315,431413,208968,66605,747804,67557,410587,777954,820757,97567,304271,978212,444526,70208,321403,987094,376158,803392,371825,771674,942464,348867,809450,464232,238803,155739,640088,500114,607480,243823,381624,199580,31543,952475,645524,936759,456237,555941,539018,591362,784599,205281,564353,304103,911800,14379,103541,268223,201288,223634,897312,473758,808976,631077,198368,769606,871598,291803,189929,933955,371574,808637,962549,834215,720103,240531,721401,306488,905111,570253,629427,978236,17836,432588,795612,549605,823970,926892,260893,945413,798898,745004,519643,516373,572399,219059,660536,562504,485381,251210,128740,318431,94649,714422,909326,410842,816915,181586,969990,110322,62986,22556,902764,198471,365330,593209,588286,108197,422609,849571,670043,729397,796469,489517,940744,17635,155201,853020,813964,246587,914715,811323,740059,183915,546084,663166,378422,744806,700376,468030,883271,155835,649171,80052,786152,899322,682703,422353,165132,379514,352078,42599,632263,278621,826083,937617,6166,205431,166378,46042,414058,652480,902245,20020,788703,380505,922208,531265,991698,639020,945093,68636,343073,601321,493491,356991,530262,62939,235121,705728,1546,624508,407058,545526,87302,424984,788323,12673,831050,791392,302842,26785,382536,750381,107865,275103,351338,207957,719278,747464,675173,392074,541228,892028,602826,154428,501041,406351,713118,298086,655407,326690,561698,805439,415218,474971,909470,605333,862014,249218,108790,955575,72761,91300,54095,645791,329112,953448,929015,320499,815456,193571,313871,412894,401811,312024,194864,586134,736655,510475,75562,732257,769024,158856,433349,485527,399289,420208,505469,184613,25112,706785,185782,447987,391285,384118,433809,755927,836568,917535,369849,880566,717073,827549,67409,384137,196978,709279,114915,967803,637040,843745,154744,238211,411814,577567,763365,437306,167924,288316,264832,396326,725898,693120,318501,855808,560418,910749,853761,386756,285524,292342,831484,391753,727256,818474,566232,284399,170385,440634,888638,965014,899145,609563,598566,789338,856958,407503,117639,482168,165695,447903,639292,307357,371676,270300,461465,594982,895040,448533,349218,709184,902326,813133,368908,690132,33188,243537,206332,503919,350269,535985,230061,712436,365930,923812,734110,914338,256933,852377,767033,582216,666071,20480,159065,639456,600987,852562,735136,215408,638588,382150,932597,629856,160066,77216,512954,84181,151660,199809,942244,678014,696538,444088,44926,271289,212273,675975,225578,449264,683257,73467,312201,469325,661982,71632,220028,601855,982401,357747,117622,907071,663497,786748,922462,294102,352463,313023,602019,815965,640263,916056,582339,242224,971903,512787,749190,179451,903379,848994,916966,56456,672695,562805,146559,269372,558417,285613,548323,421977,837201,804054,79191,233379,136949,940655,647622,234754,105080,898559,657017,577917,534901,541736,122750,590121,815464,997697,458812,651651,345436,660601,302620,895067,261647,949436,45734,589531,281288,750334,61308,202832,686250,579045,741101,93184,730471,744503,990779,21570,877676,457823,733905,867607,329138,305829,81383,720358,556636,23023,782004,362246,10466,618972,368285,367651,202231,532221,167216,904944,65046,653247,808615,371229,987717,556747,777728,421897,473145,739559,141486,162078,721616,61030,425370,764079,718100,257968,44718,91388,726180,764778,950182,576569,84786,851331,870751,447017,363608,35983,832388,345986,474672,642737,589049,658096,830858,830888,422586,405467,895020,448390,72397,326306,534204,994323,760431,824255,682040,166579,456033,182836,20096,408134,233611,628424,949124,974349,803003,219266,960769,617752,38400,400669,852688,218819,771767,454988,991400,953161,601677,522764,548917,184345,946714,544494,173142,152139,299637,587182,752247,922146,7874,516714,137544,576829,170858,959892,142605,335351,812694,829675,347968,756170,500064,838339,552778,655769,974321,770053,409285,424835,158410,916945,764047,897660,905450,278577,607137,223197,141772,729719,969119,766310,508786,411302,346625,190333,9803,733169,23938,674291,262804,411565,933688,789625,102342,789484,93591,529385,118668,95741,622456,542768,490591,818566,658289,569156,299279,89926,115430,366098,88972,366721,467143,514676,768373,340434,348701,379556,720810,998616,500239,751770,961767,387360,228234,702794,938884,795656,558370,757675,655779,611399,21940,520463,135218,813714,292796,681197,124355,938025,258933,939964,84458,649542,588420,332204,679518,100385,914282,34369,823610,349299,842590,492722,199824,813208,829553,868225,47732,19858,640522,426789,80472,886560,604914,973310,328378,733757,375246,503426,802413,67283,302847,372181,609333,316702,300474,23712,993040,225316,487568,335965,876579,599948,326092,957354,485737,207190,434860,767128,547460,836959,248344,268302,869425,692754,74719,460079,28580,599305,807778,441976,278912,558144,499165,337287,780875,757923,848360,862028,748330,396456,759199,750050,647043,408224,462354,358875,639622,178621,821413,815549,968292,825319,860528,488688,960740,139451,840160,300899,715985,638012,585892,378434,365401,210046,782114,21634,431518,842295,774385,446613,615367,701773,817888,393179,239771,902782,225502,344768,742372,879121,709939,235049,504892,208493,525930,661339,32699,613745,87462,969620,79155,639278,400022,836865,400002,1082,901309,522147,158551,304121,429808,627902,235493,44466,736541,401971,14579,825774,130919,386974,159506,200132,714277,43766,221265,414289,817648,990292,195853,410964,977386,958879,267601,732797,540274,55719,277452,973104,332909,318372,938821,653069,124714,383792,485641,107227,202311,676326,220913,120962,94893,506750,291845,339031,823384,442511,885502,853427,83503,405202,7721,494838,341714,498591,279969,734776,425889,358056,543725,603788,466765,53525,275931,777023,887093,569767,492892,638549,309807,864796,517424,745352,371875,384108,886378,763284,112261,77334,353345,73648,268003,528277,536833,502893,721750,278716,506147,69028,453572,788613,388026,573767,263308,839284,58211,856684,245646,162300,343604,782200,611547,757262,325120,425614,408558,991186,914154,483506,97089,481775,923355,276954,851239,85088,538443,503136,453350,594942,415515,418141,97260,326786,839124,420208,755955,102164,246899,215873,16945,773932,711558,356253,393258,534114,590227,646500,871223,409977,504313,212772,387096,981921,802771,952464,62725,736839,704237,121794,974158,308820,963871,188247,532960,524685,668645,433792,826010,245600,638375,211060,102338,386566,116648,934248,188395,439294,568117,248482,350668,452233,365610,145126,532589,997126,170592,701231,781210,703912,789952,475314,853001,797322,546244,949052,537927,139042,9955,323568,302201,458948,411444,540761,692584,136009,610095,443761,688261,4483,555278,594477,335885,430021,14370,445618,487976,336215,556545,948949,607668,178240,692103,72131,810027,641793,597120,881598,274182,827462,476676,671513,806808,84511,746600,881443,612701,960743,88992,585116,444615,902621,686968,614713,346615,114119,841380,898122,856540,550162,350828,523021,786645,649779,728343,194849,571190,332378,367394,13143,258144,978583,446007,834702,539138,764971,643142,838262,21579,484070,146331,702118,869967,385885,546446,726708,997962,600342,454934,75150,683502,921019,914954,172164,474056,372082,191963,421167,177708,816520,325813,957432,211448,182005,911316,180905,560332,811871,286923,640612,982891,273979,269397,373820,70292,252064,917218,678557,114038,282969,62803,723336,84560,319149,596114,503048,169304,818986,729291,439334,541669,483151,457896,900678,167616,963773,188151,131917,162339,27996,939212,906560,813717,406199,149780,305484,903753,239375,563428,136292,639358,464990,108451,715816,666367,814610,946236,883588,733864,485421,910943,328816,821809,644893,817467,796246,707763,322017,120479,700098,932913,672081,717850,468130,842473,948808,440264,51450,269685,170580,495655,110574,79911,542538,595553,142518,101195,388625,612920,298826,954895,96976,649951,592359,330134,431383,310366,85123,737777,976381,884845,511016,257201,305417,939081,965641,773207,943968,809740,463768,116118,655989,115893,788588,918231,890839,538863,101980,569229,146018,216845,118433,162547,647884,574259,820983,465636,821568,59412,461758,758993,548799,124604,887367,73540,294921,385611,237643,266789,38119,65383,476282,91463,914387,642746,167051,210762,25007,95217,313820,426980,852153,158663,68524,635516,640372,69140,556010,425614,19737,244557,91895,935288,405372,725397,717482,802799,627419,584433,208948,800291,176846,465984,6927,418985,437159,295786,583612,994804,670769,588409,191089,59045,306471,738189,191002,160987,988888,471522,110974,985230,505630,579552,96269,644920,638346,70318,526487,350842,637981,683975,47394,982510,422089,837330,420665,490341,756551,604239,888795,529168,165656,798275,166980,742306,978607,461446,923121,846362,282423,789836,334467,427937,734826,544249,262708,909832,517903,368261,287994,77680,545911,371297,483976,407920,36886,466334,697307,318637,593659,977179,54461,457263,287652,441938,659643,160968,156089,355639,496394,215737,882573,267390,310547,317914,921132,863453,656893,858302,337110,497815,228937,692806,803529,876663,599079,848408,203886,850813,596601,624895,643384,865162,259609,159086,810064,627510,815693,815436,747613,559247,595960,715048,900412,396208,682582,103662,502325,92550,801478,39558,481483,39153,616830,87473,854107,666555,416796,382442,756119,325335,45674,222481,66464,770722,95059,255526,170038,154410,587186,323979,990960,938789,719761,747441,517925,787198,148360,170062,157236,778282,808772,446618,413123,331942,803917,583478,11757,148562,667222,193973,772529,858403,770962,134637,204967,190967,930856,786568,769149,677766,266933,571789,236453,351468,213504,803284,365470,247537,551334,725513,573273,544334,852824,426046,552360,130462,841667,582601,700233,906249,929252,152772,995953,979986,238889,326224,342239,374962,115224,804671,649080,644116,405040,569021,599009,882340,789652,392734,328450,639773,222086,65237,814555,162530,744442,897212,939559,309541,613328,396916,606483,835662,900249,911050,842113,862268,780996,995972,496929,88221,516246,619711,314996,725500,754071,367112,249277,967438,264036,72791,288600,569123,88540,742326,111759,250038,590565,479965,787016,146444,636497,245910,346583,587116,112567,957318,830622,35170,676661,72749,669044,858807,99569,42907,170294,797814,794128,728067,682993,389828,993468,297354,256432,991000,153739,920084,119499,6007,227425,864892,725237,769890,842754,155999,271529,673598,238038,499056,302316,285765,295304,892807,891457,789214,490291,492908,34846,653224,598122,729723,956436,639495,591013,187869,210159,139755,885491,634215,234470,732707,24154,608226,547460,481404,457012,278613,353345,976114,965206,452435,833972,659095,715782,238793,506488,903661,672156,741740,228148,661439,759483,636433,965678,437407,158071,764205,670458,46547,650799,168982,646530,260164,177800,98006,701591,609167,86284,801120,570982,494511,341384,746522,513011,450983,917848,352586,458711,259069,55534,814829,870060,881544};  int k = 25000000;
    int l = LEN_M(m);

    printf("l %d k %d s %d.\n", l, k, l * (l - 1) / 2);
    // int m[] = {1, 2, 10}; int k = 3;
    printf("%d.\n", smallestDistancePair(m, LEN_M(m), k));
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
