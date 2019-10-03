#include "common.h"

#if 0
#include "./1147_longest_chunked_palindrome_decomposition.h"
void test()
{
    // char* s = "ssss";
    // char* s = "anccna"; // 6
    // char* s = "merchant"; // 1
    // char* s = "aaa"; // 3
    // char* s = "antnta"; // 4
    // char* s = "ghiabcdefhelloadamhelloabcdefghi"; // 7
    // char *s = "helloadamhello"; // 3
    // char* s = "antaprezatepzapreanta"; // 11
    // char* s = "elvtoelvto"; // 2
    // char* s = "qkosrybjochsmjfvfxllbuqwmttnpeodqiiesdywtxjdssyoznntxjdssyoznqiiesdywqkosrybjochsmjfvfxllbuqwmttnpeod"; // 7
    char* s = "jmfqcmihhdesaskmjubbcjstgqmpnfmklvfevyaqqffjugvgltvwhzqkopyaruvxhfmsllndyxkhckwjwjdvqsfbmelgmxrgvnwelllrwublvdhymiemkebuihtrsltwbfuajuwdkeppjuvnuobcsqsvkagndagthkoqwdkxeetcmmmoboxpvqrcregvmugqlmvdmkhcevpmhoikcljffjprsrrbjrkgvztkbmyubwkjmxkmsxlrfkoxkdjbxrdkcygsezbrrhzwbfwwmxbuajgrbfnlchcsglsxsgytkmcfqendlnzgyktdnyownozkgekrqqfpgzebgupmpagdxwqtbwdofpqfnkqradceewqxentxnafdxevbmkbogvmmjtartxtheobfnchwhxdahpkvroygeuufrmjjkvpqjsnzgwjvlbexloeortjgxghredfbpnbquhpdeselmfxmkrivwhhcyuacskcbfilzsmpzlzeakkjjkeakcskcbfilzsmpzlzhredfbpnbquhpdeselmfxmkrivwhhcyuaentxnafdxevbmkbogvmmjtartxtheobfnchwhxdahpkvroygeuufrmjjkvpqjsnzgwjvlbexloeortjgxgmvdmkhcevpmhoikcljffjprsrrbjrkgvztkbmyubwkjmxkmsxlrfkoxkdjbxrdkcygsezbrrhzwbfwwmxbuajgrbfnlchcsglsxsgytkmcfqendlnzgyktdnyownozkgekrqqfpgzebgupmpagdxwqtbwdofpqfnkqradceewqxjmfqcmihhdesaskmjubbcjstgqmpnfmklvfevyaqqffjugvgltvwhzqkopyaruvxhfmsllndyxkhckwjwjdvqsfbmelgmxrgvnwelllrwublvdhymiemkebuihtrsltwbfuajuwdkeppjuvnuobcsqsvkagndagthkoqwdkxeetcmmmoboxpvqrcregvmugql"; // 16
    // char* s = "onlaiuwlouxpuzrxkwxwbxtlfqulquwcmdcwvqsqvpxrwhkubebnyudxhpxlkxeqtimhbfderhkcrmbdkvmuivmnbwuqjiaxjuhzzmwszguyxdhidppphciuhdfqrxrafexmzvieidmfbgdaiknhobnpghiejkqvyxsdbonewybcbhzmberxawzecunvllgrlbfrgascaaeoflxpytsfustfudtjtjklesthnobyvzynxduvpalogvdnkwvtdlhotaieadgpylkbhyosnyojdcofwwehqnmymmevegxazbaxuilpqqghytnntsewkwsxrfhvyyszzmvoeyrqedfksypgzzbsplcvyuuzdcpodgnlzyngiffaeqpgnidyyngynzznzizvvimwfesbublxqgbsevmsotynobfpcokvyylxlktygvhwxqdfhmitmdibamtavtsustkzlierhcldwosyxxutqgacvhfpwsyqklbphnlhmmrlhmmrnlbphkwsyqpgacvhfxutqsyxowdclzlierhstktavtsumdibamhmitqdfygvhwxtkylxlvyfpcokotynobmssevqgbblxesbuimwfnzizvvynzzynggnidyqpffaengignlzyoddcpuzvyubsplcpgzzfksyeyrqedzzmvoysfhvykwsxrntsewtnpqqghyuilbaxvegxazemmhqnmyfwweconyojdosbhypylkaieadgtdlhotnkwvogvdvpalxdubyvzynthnolestjktjstfuduytsfflxpaeorgascaflgrlbecunvlrxawzbemhzewybcbnsdbojkqvyxhiepgnhobngdaikbdmfvieiafexmzrfqrxciuhdidppphhyxdwszguuhzzmjiaxjmnbwuqmuivmbdkvkcrbfderhtimhqxlkxedxhpnyubebkuxrwhqsqvpvcwmdulquwcfqwbxtlxkwxxpuzriuwlouonla";
    printf("%d.\n", longestDecomposition2(s));
    printf("%d.\n", longestDecomposition(s));
}

#include "./1054_distant_barcodes.h"
void test()
{
    int m[] = {1, 2, 1, 2, 1, 3, 5, 1, 1, 3, 2};
    // int m[] = {1, 2, 1, 2, 3};
    // int m[] = {1};
    // int m[] = {1, 1, 1, 2, 2, 2};
    // int m[] = {1, 1, 1, 1, 2, 2, 3, 3};
    int l = LEN_M(m);
    int ri = 0;
    int* r = rearrangeBarcodes(m, l, &ri);
    out(r, ri);
}

#include "./1067_digit_count_in_range.h"
void test()
{
    printf("%d.\n", digitsCount(1, 1, 13));
    printf("%d.\n", digitsCount(0, 1, 70010));
    // printf("%d.\n", digitsCount(3, 100, 250));
    printf("%d %d.\n", digitsCount(2, 1000, 2533), digitsCount_test(2, 1000, 2533));
    for (int i = 1; i < 1000; i ++)
        for (int j = i; j < 3000; j ++)
            for (int d = 0; d < 10; d ++)
                if (digitsCount(d, i, j) != digitsCount_test(d, i, j))
                {
                    printf("%d %d %d %d %d.\n", i, j, d, digitsCount(d, i, j), digitsCount_test(d, i, j));
                    exit(1);
                }
}

#include "./1095_find_in_mountain_array.h"
void test()
{
}


#include "./1185_day_of_the_week.h"
void test()
{
    printf("%s.\n", dayOfTheWeek(31, 8, 2019));
    printf("%s.\n", dayOfTheWeek(1, 1, 1971));
    printf("%s.\n", dayOfTheWeek(18, 7, 1999));
    printf("%s.\n", dayOfTheWeek(15, 8, 1993));
}

#include "./1175_prime_arrangements.h"
void test()
{
    printf("%d\n", numPrimeArrangements(3));
    printf("%d\n", numPrimeArrangements(5));
    printf("%d\n", numPrimeArrangements(100));
}

#include "./1154_day_of_the_year.h"
void test()
{
    // char* s = "2019-01-09";
    // char* s = "2003-03-01";
    char* s = "2019-02-10";
    printf("%s is %d.\n", s, dayOfYear(s));
}
#endif

#include "./1198_find_smallest_common_element_in_all_rows.h"
void test()
{
    int m[] = {1, 2, 3, 4, 5, 5, 2, 4, 5, 8, 9, 10, 3, 4, 5, 7, 9, 11, 1, 3, 4, 5, 7, 9};
    int n = LEN_M(m);
    int c = 6;
    int** a = gen_aa(m, n, c);
    outaaa(a, c, n / c);
    printf("%d.\n", smallestCommonElement(a, n/c, &c));
}


int main(int argn, char** argv){
    // printf("INT_MIN %d, INT_MAX %d.\n", INT_MIN, INT_MAX);
    srand(time(NULL));
    int i = 0;
    // while(i++ < 100000)
    {
       // printf("=========\n");
        test();
        //  printf("=========\n\n");
    }
}
