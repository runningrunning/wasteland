#include "common.h"

/*
// TODO WHY QSORT ERROR
#include "./473_matchsticks_to_square.h"
void test()
{
    // int m[] = {1, 1, 2, 2, 2};
    // int m[] = {1, 1, 2, 3, 2, 4, 1, 1, 1, 0};
    // int m[] = {100, 20, 99, 1, 80, 75, 25};
    // int m[] = {7, 16, 28, 3, 41, 5, 36, 41, 7, 16, 16, 15, 4, 43, 22, 49, 42, 9};
    // int m[] = {16, 45, 39, 47, 25, 28, 36, 18, 40, 6, 48, 38, 14};
    int m[] = {36, 19, 30, 1, 14, 35, 41, 17, 7, 34, 11, 28, 27, 36, 34, 30};
    int m[] = {6, 33, 30, 31, 42, 47, 11, 45, 45, 10, 22, 43, 35};
    int l = LEN_M(m);

    int x = 100;
    int l = 0;
    int* m = NULL;
    for (int i = 0; i < 4; i ++)
    {
        int z = x;
        while (z)
        {
            m = realloc(m, sizeof(int) * (1 + l));
            int t = rand() % 50;
            m[l] = z > t ? t : z;
            z -= m[l];
            l ++;
        }
    }
    out(m, l);
    if (!makesquare(m, l))
    {
        out(m, l);
    }
    free(m);
    // printf("%d.\n", makesquare(m, l));
}

#include "./915_partition_array_into_disjoint_intervals.h"
void test()
{
    // int m[] = {5, 0, 3, 8, 6};
    int m[] = {1, 1, 1, 0, 6, 12};

    int l = LEN_M(m);
    printf("%d.\n", partitionDisjoint(m, l));
}

#include "./916_word_subsets.h"
void test()
{
    char* a[] = {"amazon", "apple", "facebook", "google", "leetcode", "ceorr"};

    // char* b[] = {"e", "o"};
    // char* b[] = {"e", "l"};
    // char* b[] = {"e", "oo"};
    // char* b[] = {"lo", "eo"};
    // char* b[] = {"ec", "oc", "ceo"};
    char* b[] = {"rr", "oc", "ceo"};

    int al = LEN_M(a);
    int bl = LEN_M(b);

    int ri = 0;
    char** r = wordSubsets(a, al, b, bl, &ri);
    outstr(r, ri);
}

#include "./887_super_egg_drop.h"
void test()
{
    // printf("%d.\n", superEggDrop(1, 2));
    // printf("%d.\n", superEggDrop(2, 6));
    // printf("%d.\n", superEggDrop(3, 14));
    // printf("%d.\n", superEggDrop(100, 10000));
    // printf("%d.\n", superEggDrop(10, 10000));
}

// TODO STUPID WRONG ALGORITHM
#include "./321_create_maximum_number.h"
void test()
{

    // int k = 5;
    // int m1[] = {3, 4, 6, 5};
    // int m2[] = {9, 1, 2, 5, 8, 3};

    // int k = 5;
    // int m1[] = {6, 7, 8, 8};
    // int m2[] = {6, 0,4, 9};

    // int k = 4;
    // int m1[] = {3, 9};
    // int m2[] = {8, 9};

    // int k = 15;
    // int m1[] = {2, 5, 6, 4, 4, 0};
    // int m2[] = {7, 3, 8, 0, 6, 5, 7, 6, 2};

    // int k = 80;
    // int m1[] = {1,5,8,1,4,0,8,5,0,7,0,5,7,6,0,5,5,2,4,3,6,4,6,6,3,8,1,1,3,1,3,5,4,3,9,5,0,3,8,1,4,9,8,8,3,4,6,2,5,4,1,1,4,6,5,2,3,6,3,5,4,3,0,7,2,5,1,5,3,3,8,2,2,7,6,7,5,9,1,2};
    // int m2[] = {7,8,5,8,0,1,1,6,1,7,6,9,6,6,0,8,5,8,6,3,4,0,4,6,7,8,7,7,7,5,7,2,5,2,1,9,5,9,3,7,3,9,9,3,1,4,3,3,9,7,1,4,4,1,4,0,2,3,1,3,2,0,2,4,0,9,2,0,1,3,9,1,2,2,6,6,9,3,6,0};

    // int k = 80;
    // int m1[] = {1,5,8,1,4,0,8,5,0,7,0,5,7,6,0,5,5,2,4,3,6,4,6,6,3,8,1,1,3,1,3,5,4,3,9,5,0,3,8,1,4,9,8,8,3,4,6,2,5,4,1,1,4,6,5,2,3,6,3,5,4,3,0,7,2,5,1,5,3,3,8,2,2,7,6,7,5,9,1,2,1,9,8,9,1,0,5,5,9,7,7,8,8,3,3,8,9,3,7,5,3,6,1,0,1,0,9,3,7,8,4,0,3,5,8,1,0,5,7,2,8,4,9,5,6,8,1,1,8,7,3,2,3,4,8,7,9,9,7,8,5,2};
    // int m2[] = {7,8,5,8,0,1,1,6,1,7,6,9,6,6,0,8,5,8,6,3,4,0,4,6,7,8,7,7,7,5,7,2,5,2,1,9,5,9,3,7,3,9,9,3,1,4,3,3,9,7,1,4,4,1,4,0,2,3,1,3,2,0,2,4,0,9,2,0,1,3,9,1,2,2,6,6,9,3,6,0,9,8,9,1,0,5,5,9,7,7,8,8,3,3,8,9,3,7,5,3,6,1,0,1,0,9,3,7,8,4,0,3,5,8,1,0,5,7,2,8,4,9,5,6,8,1,1,8,7,3,2,3,4,8,7,9,9,7,8,5};

    // int k = 500;
    // int m1[] = {8,9,7,3,5,9,1,0,8,5,3,0,9,2,7,4,8,9,8,1,0,2,0,2,7,2,3,5,4,7,4,1,4,0,1,4,2,1,3,1,5,3,9,3,9,0,1,7,0,6,1,8,5,6,6,5,0,4,7,2,9,2,2,7,6,2,9,2,3,5,7,4,7,0,1,8,3,6,6,3,0,8,5,3,0,3,7,3,0,9,8,5,1,9,5,0,7,9,6,8,5,1,9,6,5,8,2,3,7,1,0,1,4,3,4,4,2,4,0,8,4,6,5,5,7,6,9,0,8,4,6,1,6,7,2,0,1,1,8,2,6,4,0,5,5,2,6,1,6,4,7,1,7,2,2,9,8,9,1,0,5,5,9,7,7,8,8,3,3,8,9,3,7,5,3,6,1,0,1,0,9,3,7,8,4,0,3,5,8,1,0,5,7,2,8,4,9,5,6,8,1,1,8,7,3,2,3,4,8,7,9,9,7,8,5,2,2,7,1,9,1,5,5,1,3,5,9,0,5,2,9,4,2,8,7,3,9,4,7,4,8,7,5,0,9,9,7,9,3,8,0,9,5,3,0,0,3,0,4,9,0,9,1,6,0,2,0,5,2,2,6,0,0,9,6,3,4,1,2,0,8,3,6,6,9,0,2,1,6,9,2,4,9,0,8,3,9,0,5,4,5,4,6,1,2,5,2,2,1,7,3,8,1,1,6,8,8,1,8,5,6,1,3,0,1,3,5,6,5,0,6,4,2,8,6,0,3,7,9,5,5,9,8,0,4,8,6,0,8,6,6,1,6,2,7,1,0,2,2,4,0,0,0,4,6,5,5,4,0,1,5,8,3,2,0,9,7,6,2,6,9,9,9,7,1,4,6,2,8,2,5,3,4,5,2,4,4,4,7,2,2,5,3,2,8,2,2,4,9,8,0,9,8,7,6,2,6,7,5,4,7,5,1,0,5,7,8,7,7,8,9,7,0,3,7,7,4,7,2,0,4,1,1,9,1,7,5,0,5,6,6,1,0,6,9,4,2,8,0,5,1,9,8,4,0,3,1,2,4,2,1,8,9,5,9,6,5,3,1,8,9,0,9,8,3,0,9,4,1,1,6,0,5,9,0,8,3,7,8,5};
    // int m2[] = {7,8,4,1,9,4,2,6,5,2,1,2,8,9,3,9,9,5,4,4,2,9,2,0,5,9,4,2,1,7,2,5,1,2,0,0,5,3,1,1,7,2,3,3,2,8,2,0,1,4,5,1,0,0,7,7,9,6,3,8,0,1,5,8,3,2,3,6,4,2,6,3,6,7,6,6,9,5,4,3,2,7,6,3,1,8,7,5,7,8,1,6,0,7,3,0,4,4,4,9,6,3,1,0,3,7,3,6,1,0,0,2,5,7,2,9,6,6,2,6,8,1,9,7,8,8,9,5,1,1,4,2,0,1,3,6,7,8,7,0,5,6,0,1,7,9,6,4,8,6,7,0,2,3,2,7,6,0,5,0,9,0,3,3,8,5,0,9,3,8,0,1,3,1,8,1,8,1,1,7,5,7,4,1,0,0,0,8,9,5,7,8,9,2,8,3,0,3,4,9,8,1,7,2,3,8,3,5,3,1,4,7,7,5,4,9,2,6,2,6,4,0,0,2,8,3,3,0,9,1,6,8,3,1,7,0,7,1,5,8,3,2,5,1,1,0,3,1,4,6,3,6,2,8,6,7,2,9,5,9,1,6,0,5,4,8,6,6,9,4,0,5,8,7,0,8,9,7,3,9,0,1,0,6,2,7,3,3,2,3,3,6,3,0,8,0,0,5,2,1,0,7,5,0,3,2,6,0,5,4,9,6,7,1,0,4,0,9,6,8,3,1,2,5,0,1,0,6,8,6,6,8,8,2,4,5,0,0,8,0,5,6,2,2,5,6,3,7,7,8,4,8,4,8,9,1,6,8,9,9,0,4,0,5,5,4,9,6,7,7,9,0,5,0,9,2,5,2,9,8,9,7,6,8,6,9,2,9,1,6,0,2,7,4,4,5,3,4,5,5,5,0,8,1,3,8,3,0,8,5,7,6,8,7,8,9,7,0,8,4,0,7,0,9,5,8,2,0,8,7,0,3,1,8,1,7,1,6,9,7,9,7,2,6,3,0,5,3,6,0,5,9,3,9,1,1,0,0,8,1,4,3,0,4,3,7,7,7,4,6,4,0,0,5,7,3,2,8,5,1,4,5,8,5,6,7,5,7,3,3,9,6,8,1,5,1,1,1,0,3};

    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);

    int ri = 0;
    int* r = maxNumber(m1, l1, m2, l2, k, &ri);
    out(r, ri);
    r = maxNumber2(m1, l1, m2, l2, k, &ri);
    out(r, ri);
}

#include "./499_the_maze_III.h"
void test()
{

    // int m[] = {
    //            0, 0, 0, 0, 0,
    //            1, 1, 0, 0, 1,
    //            0, 0, 0, 0, 0,
    //            0, 1, 0, 0, 1,
    //            0, 1, 0, 0, 0,
    // };
    // int c = 5;
    // int b[] = {4, 3};
    // // int h[] = {0, 1};
    // int h[] = {3, 0};


    int m[] = {0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0};
    int c = 10;
    int b[] = {2, 4};
    int h[] = {7, 6};

    int l = LEN_M(m);

    int** r = gen_aa(m, l, c);
    printf("%s.\n", findShortestWay(r, l / c, &c, b, 2, h, 2));
}

#include "./330_patching_array.h"
void test()
{

    int m[] = {1, 3}; int n = 6;

    // int m[] = {1, 5, 10}; int n = 20;

    // int m[] = {1, 2, 2}; int n = 5;
    // int m[] = {1, 2, 3}; int n = 10;

    int l = LEN_M(m);
    minPatches(m, l, n);
}

#include "./483_smallest_good_base.h"
void test()
{
    // printf("%s", smallestGoodBase("1000000000000"));
    // printf("%s\n", smallestGoodBase("1000000000000000000"));
    printf("%s", smallestGoodBase("916365355264637559")); // 971306

    // printf("%s", smallestGoodBase("13"));
    // printf("%s", smallestGoodBase("4681"));
    // printf("%s", smallestGoodBase("14919921443713777"));

    for (long x = 100000; x >= 16; x --)
    {
        long y = smallestGoodBase2(x);
        if (x != y + 1)
            printf("x %ld, %ld\n", x, y);
    }

}

#include "./411_minimum_unique_word_abbreviation.h"
void test()
{

    char* t = "apple";
    char* m[] = {"blade"};

    // char* t = "apple";
    // char* m[] = {"plain", "amber", "blade"};

    // char* t = "oooo";
    // char* m[] = {"looo", "lloo", "lolo", "olll", "oool"};

    // char* t = "aaaaaxaaaaa";
    // char* m[] = {"bbbbbxbbbbb"};

    // char* t = "onetwothre";
    // char* m[] = {"rkaromrcbl","cgdqnbwoom","icqwawtgux","egrsqhqmdg","mpeqhehtfz","fntpyxdoev","bpysavnyvp","rztggzislg","ndhsychnkx","tmvgcwsqxl","ghtavqzdku","duxqlvvxer","jvsuzwihvz","pwedmdanxi","hkrjexfwki","jeomlkizat","swpmnxaifk","jlecvorgvm","ukcddxpdvj","eaijhjzexy","zyzlgrnjdg","qiwkjffays","cepthmkpiw","wyxcveickl","euuwvrqtte","rqodvucfrx","ftwidrlvcr","yulrlrjeaz","nsmsyqlbip","cversuexrs","sxoxjsjiql","lvltjbbibe","jntrxysnth","vgjpovdigm","wadvlanmab","njnyudpakg","yaoaexeffb","ljcvvizzat","onovwwafjd","mibcnmgdch","pcdalztmug","lhnrkihtsj","hmrgddbgxz","ykerkcirnt","bgsvmqlhle","fjfopyhuxm","likhegxmry","tnybravwig","ayccnuiiar","xnslfgdwff","leivjyejzs","ggcvkzrkfh","ycninyoqme","viaeyugryr","avwmkgvolr","rztqnynkaq","wfblaildla","pcibbcnkvv","bqmnorzfty","alxbxfdflo","mmbjxetggn","tshbgnwujr","bqqkhgfbsh","vjwirxojpg","oprjyasewn","lmkwrcuewh","jmtznciylt","znioetuyrp","avmgbtoabp","hqcgdwezws","vbsxcnjiyc","dbpyoqssdg","lmllmyztnz","qjoxpylmou","tfotxdjqwq","zwgnwmkkkl","ykypesaksg","karblvxqwj","hfabvikusr","xzrgqlretn","sekpoaxpqw","ojocklcynn","uwgwyskqix","rewsfjqxiv","hfszylbzoa","tszvsoxffc","jetuoinngo","iwldqqqtgq","ugzvwndttq","tqgmczwsds","zlmbrftzwt","ilfsfgprsu","izxuftidre","czampnjeki","vtmtwljddl","bkwhbpoqzc","irykbeqeae","wpbjuosruf","dbecaxjyfc","vappsjvxds","eszeynzxgk","vyryylckvd","dxgrsrqtzs","grklncpqno","hdgkizpstv","kuelsplstn","jioihzdsjv","lkvpximomy","zgbazdwerq","mzdnunitps","crdwyctvmx","vkcxtvrolp","ewvyugbnxt","iptugjopof","uvsbhslgsz","efaazcmgqn","odhwoyubqz","tkiphyvhzm","dlfompwbcn","uthdbqnqhd","hrymmxhkyz","gqwnjhrzrv","rgmbkkrsij","eckhliblev","ukbsuficxy","wxsbudpayi","efkiscsapg","rthxnxxdqr","vwqhmbmoew","uhaxwxxlvv","flmcdceers","gudnihidnq","uglwjqfvnl","jpvqtyuwou","jgpcxtdfzc","qruarlfctn","lyqenkusvv","bxlwxddwok","ycpqxwyrpn","vaoatwogqz","hlyzjaszyv","kkfaqqlxqt","gnxoaynrsx","umgohdcjtu","fbogoqpzic","gmgkbmycfg","hmtcwvlcak","bbioreajzt","hsywmtrzwx","wkxiaugaru","eoffbgnync","eqwcuqfrvv","jshvxcsjta","uoilmsdphn","mmlefkhjlx","wzrqmywkre","qknpbnplhy","jqajvorqzk","wxaaihkmgc","ofipipoaeb","ivvtcwuwpu","qlaphulysp","vdlvmgogun","kckgpqrgde","upzwzebpot","uhmwprqujt","qsqrwnwbmm","xyfrnzgpbf","yeuydievju","sadhocohse","pgtlzezzqi","qxmjjjodol","mzpitgkhqk","cqesfbgyeq","igkzzompsv","eelpodtvkw","xspozoxitm","xcatlxravb","bahvvdejdr","jwsnephxil","wubbiwjxok","sjfeprnxmg","impdvqccmg","sywdrujoim","ahhyqokgkw","llivqxfomd","izgljwaosi","lwejzmfmum","kvdgepwjiv","wokufytuog","leyrhwlode","qwujqyhdtq","augomiegzc","dawdmfiyfi","clltonasyw","uwmyftdzlc","hpbuccisxv","dqvbeiolpi","qcoelfgekj","vuhljsyptt","tnsyzjkepq","nojrlyocpv","jkmurokagd","ktsczgdvxg","tuwuamhqcs","pywkgsfrzn","pqdcqkayrx","wfcafldbdw","nzzmqjjwnt","pouzrvsfmd","anhitvoqsg","zgjxlhvxal","mmkkoxllpx","tlaibfblba","jseepbrzqn","escpqfplbh","xcuqdlpohe","dinlfopmak","quhtycfztb","jabhzctkem","kvujljlxlr","ieermvpola","lnvjsbwtyw","tuvpedtgrt","ovndpydtea","dqgjcfvwxo","mklxjejzal","ttrczgappv","umchzdzslf","pqmqsrxvle","aovakofbqi","xugswhauhl","kcavggbgdn","fnfyvugera","mjnzmsnwjz","tvkbjhacit","ytjtsxqgta","ogokbhswpc","lwahoewpbk","jsanvhhaxr","vbsvoqobpf","wcrftfiapu","alzcaypbto","jbpttunqpz","idtykgeqwj","igluzaaxzh","mfrmalgoia","puuromirde","evtrvgwgiy","fjxerafngh","kpbxuuyjzs","bqsitqnpge","segagpipmk","fhewkrwplc","irdzhdbyjf","oixcddxfcn","zdjvpbkfvu","uxnkrmjegj","axwxqzdfkf","wdmjibssgi","hongmgsbah","qjsyehxrta","pfcuuhjloj","jvwaziwnab","yrbvaahjbd","fyndtzmibj","uiymzzdyau","logicyjcta","ksjsrlegnh","zegnghadux","ertotwgjly","ljpumdhjbs","wbathmuxyc","gwypioivhb","gixjjncnwu","mjghnftald","suhuakvnqe","obzbiskgnl","mesfhxqljd","rtcjwyehqd","xwltmxwzct","yqniboesdh","gntuznwfpn","aydtyvatiw","djxxksfdqg","iksgynlrdm","bzrxivhpsz","pdkkzirtfd","tkuqcbkenr","gkbdlrbcdh","owkzgyagnj","qtmoxotxiy","ffzqbmqjin","abppepmpve","evkabwwspq","krlzskvqwu","vduzjsbbad","elexmftoyw","herjtdxbyp","oyjmlggphc","babpsjzohe","msjtgjjucx","uuryitndpd","wqmbgfugib","suoleojzmq","pugzyazgxh","xzmeyzocec","sysyhioxgb","fouzdaioge","qtaanuabjw","mlpftkoyaq","vepkrzewot","ctpsagubff","mjatcvmmxq","tedjnxpciu","cyjgyujqln","ubbyjaxvyb","mspzftzowj","vwrzouuxfc","apbnjvfodg","owlcxtmrth","cpydpratev","nqaogjqvng","plvogrcqux","zsxtjrscyv","hukvkgsykv","vycweckuda","iarmqiylpa","bkfdhoobbk","uwqztqvfgp","audiizdwrd","fpmxlrudsb","mdlcojdrwi","nzdtulpqlr","spswxxbtup","ifklvrtude","gmrqaodzzx","bsjtcrlqhe","hofpmpygsp","lrsrusvnpc","pqjsoiffqz","wszfxozeyb","ckehyzmjbf","pupadvmozw","yutvysgcqe","kkigqkxtun","oebmzvcfsj","rjshkqobov","ncezdpfmzc","vdiiqowixs","ysvthrllwi","hggcviftsd","gtlpdgiogj","kehvffaips","azzcejappt","qmqvzyhxxo","uqbzkyprgw","cecznqjzzz","agsanizkbf","lgbaolcaoo","qwpljtrsxf","shfkvmehfq","ejkwnjqmkm","psbtexhpsp","udcmjlswqi","cdzybavecf","qrrcvobzim","pyvtlmhezp","ojhkmbwbig","vcqmxayuoj","tahxzdzath","xwosdwaxmp","xydruzkofs","xpbdfgoljc","pfapltzqiy","yzjlcbkdci","jevjtsbzym","oerbhzgfvp","filwanhqgy","lkgetjjnob","lecbgepxfp","gjdgvdptre","cubogrhiox","mbykbhxrsk","cgndmdtftu","oqnasbumze","lanqdsrgnn","rxlvhwbjkd","uyikygxhde","dvusokvpkr","njgtwcjyxq","webvpgduhe","jooxtqepko","ewntsinmfr","fgslnktytv","cwewkdsjlv","jmcrwdvyvs","rcjfaontaz","rsmshzldhd","khtqwgbftj","flsazxaoye","psielzdtpo","pzyhbqtowc","fbzarwvlnx","uzdjxohgcb","nuorwwvjhs","mxzhfvdokq","cucqwqkkfv","kmhqqdaory","hoyldihsio","mogjomdtno","ylhryaemow","vtbzrctzes","ygukxqfygb","tyysmdnamn","uxnegiiqbw","mzoymgtkiu","kahtfqbjoo","jnuzljrdjq","xekobsrrex","rxuuyymcuq","excfnzzlfb","hwshqvplck","esyrsgubpx","dovvkqcodn","gpnuqhvxax","mkwxxdclrj","rhtcqckgjb","crcigwavmv","bgxncjdepo","qyhrzlgvhh","ovmkptayle","yqsnqzuhbb","meqnotlfgv","ehayslvfuh","dfiuslnbxx","qjnmogwzxh","joavqnclpl","cfpolcbebu","asaykbtrkl","ulurlfborn","bujrqboxht","rybjznkwhk","krhdfjnyvm","itqshtdgtg","rokgrfgqxz","dcccmdcxpe","puqjfmifiz","tgweqfqmmx","mkvrkvydca","vizbpqkjhf","zlroochyzw","krhxtnxplz","zwprzgyfwj","cswngmrxwd","wknaaplxvw","uhqzqprvmv","ebqkgzwnvn","karblpzvpl","orcbziqwfa","jxnxftbkns","uawdhzawcx","blgardomfd","setsynkucs","vygzfqncpq","mabnuxpoqo","hzkcqnohfw","fmenyiloni","aynxdvhcgh","uvenozbufc","oyufphgnck","chpvoaphdr","nacybsmood","wdkowlsnnk","tnndfpmxgm","iqxwziqopl","vjndylkfyf","huytmldevq","bfepsmzack","lypmgcghzq","vptjwhqwvs","pntjuxlvph","nvdgeclbmm","rqnorxfpon","rzpewlwtel","ooshukzuvj","imvrwgzimm","glysoltzku","mrhipjkptt","wdsxxyxstv","tbgzgwbweg","jngczisbth","ytgadierdi","emupezpzgo","zoxhfhjche","jbrtypitgc","nhlywdyrkl","ylvvuxnbla","lykverisbj","hwjnelonec","gioxpxxgpi","jygvkbbegt","vdroxspahq","qmccvxeurn","knpycthhaq","tdouqmouzo","ckqqlghgur","laplacxfgb","cbhtzwriiw","njgmousyky","qjiutmefey","qvxfcfpuie","nzhksaaqnc","ulgtrnzmnn","svcxfhbcvp","seqwyekxbp","dhtutxsgjj","ybonqyzuiw","dcnrqgtqub","klvukpseel","unuybutscm","vltdcylylv","elnaqgclhw","xnfrbpabgt","ehpqviebwp","biqkxbwyju","ltwmerrqmj","ixczhninbz","byemsryyxh","kyxqmpeyun","kosfnzsipm","gjwckqvgpa","nioevqzklr","llixglamff","uowucdoxtm","gmziwaqijq","wpahffpfba","ozcepkzkuk","hjwfonfhii","kqpvseducn","izqqtwlusy","zwaaugmmjt","dfxitqdhvm","jexsxvyvql","coqyiwagvc","hsswztfqlz","dtdbmyxnuz","sujbwhzaaa","usoojybqhl","vturgkplxi","imektsgofv","hdbchklaot","snzvwerkzh","apdxsfjuhb","japucmcwwa","omajpxifto","yrnjvjkoan","vgtkwsohsj","uwwftgvzek","bixzrhudrh","zmkvlxorqc","dshikdwbzr","opovhdfjkq","jhaiiktzro","zkwyodutsz","nvosfngpns","orbkxdwjkx","napykdiriu","fhkyrpeeru","nlshczrrne","jixnmqfqjx","klnthfgqbq","hvzozhfhrh","bjjssxofhm","nwuoglclmz","cnzbvhjkjs","qlgbbbhzeb","cjnekqhepm","dvmjxyvqty","smqtsokate","psrziqcrfq","gcbelqerwv","kijvtufiqn","zqqpkyocxj","siswmjmpgc","mmyjhomxgz","seqaauoost","vaqtvcfxst","eewwqfcuum","myuzcjxazc","mazuiyacbq","qgmcwoejyu","exfsobtvll","toyjbniqke","tdokycpwry","bdpyjscdsa","lwlrjwskds","ubswlncnzb","gsmanpioft","hfumimelre","muxattjsvh","vfrltokoiz","zrnbtppgbv","nimdtkdnnt","likbznzcod","wyanqgypjn","idehxrshne","wnfngkexox","hqdshcztkl","cnvaulbfnx","xnitliqxju","ypmwodatah","zjgzkwvpki","vaiitbalti","hanhhecibk","eekknqqpyf","cwcebhcowy","wlodfidqps","imbwmxocmn","mkqdarumdp","ogztxktnel","aymyrisavj","zcgmsmvrvp","wkvgctblut","vvdffjzevo","nhnivcxsxr","potjpikdpw","lwbofagifd","gdpugqmcmd","hywghbbofe","gmpbavzewc","vquezoxpcc","qqknwllhot","xvlnapisvk","nqjgbbbdsc","zbyvtsgxrx","afdscdtuig","jyxxrknizw","tyrwhfdqpb","rrsaxmuvcr","ljmwjeplbb","gkewrecgkp","dhouzordas","acjpzkmgjp","mqaceydfqx","nhtzcaesnq","ousmcebttf","eztcdtlryf","fgpebkrpst","ukeatvruux","phrjvpmjme","mlgmidhqlg","bniqmkzvhj","jxbpevetde","jnjxlvegak","aglacbsozc","qezotaizij","oebucsszbw","mwtovusrtm","didlkdgbrm","yfxuwfdzqb","wgmhqmxfzs","lkdqfpgvih","aftnhojohf","zqjkqxylhx","weokjmxgyf","rqbidpwxun","ebnwlwdkkh","yicdgrlfht","exadvjqzhm","mihrnsianx","pavwqcedqj","vznfjxndph","nrzyoliqin","seousvpnwv","nrbkyxknfh","qhkzpqqqux","ppjrlhfzhu","lntztijwmp","mskzuecwda","inlqiuezhx","fzdixbsntf","izqwlumkku","qmkaiccwdm","ykbawvjykl","zfwumgzulx","mshemudgid","ftfukzyjfh","dtrtmzlber","vfztqetnvh","kqbbudzctq","sbofalvjiz","eqswuygmpq","feqfqbvgeq","jatlzcojyf","fjotwkrowr","igfevujeuz","essfkyvpjt","qbuqtwzigz","ogyacvsxrk","jflgfguqfj","tpwcdxbbpq","qabtvzzndx","momvgzaqlq","ckhxerxncz","oucryibndu","ltlfckaeyq","fekladjiwz","lejinimira","orrnojpjvd","tmajyvacfy","waoxnqzljk","mxmouagoxg","tsviocdyvr","ykmhdedosd","plxjtoecil","pgzbsdflal","vnzbxtvocz","qbdidfxrbi","grpcnxfzrx","spkbqquncx","yphvluihsa","djsgegvgav","vrgumtfaru","evexrtqawo","moixxsnsxc","bsjcmpwcuy","wubpdalppo","caznrihobl","auiemgkhue","gzuxqfhodf","mjafhwxjfj","krorwsntgo","fgpdpnzljm","hpziembxjj","tspdcrwbrd","xokormczev","jcuwcrxdio","ijmqziicpg","ouxjsveqca","wqfyybukcp","sybnjkcrqy","scltfoddtf","qztxxahpal","apjxtlqury","lidtztpkar","cjdnyvxpel","niwthedcyf","plrvkwywpu","mchpslzwfm","vyldmddehq","qglufmnfry","uortqssinf","xrwaitnpys","foidmwuzdc","ooojztxwqn","cwnqenssut","qeeepaepse","guffblbunz","bacecevatf","itezkmthgy","hbcpylnuit","kghholjkip","ijakxrsuvz","mhzivtfmki","etjpvacrca","cmvrnkusjc","immsstdxah","qpylmdnwfj","xxysqcjrcs","ldsvvjodsj","cwlkqgshso","gnchrjvzzc","qedekzeedt","fzrzmpqwig","usorrzqjqe","eyqlcudmuv","amgqimiiuq","hmhffadqwa","bpxyddkhfr","pgzqyuibun","utqfrcqbtq","mkyklkdrfr","xwgjteuxzo","fcqyebmlqv","tpegzxnfzj","dkwvbhbcmr","rremdoghwj","aanlmpfehe","dkbglbejof","afmlvayqqd","sdcgcoewyc","jzhksjztxv","mkiirbsdil","hdodicrwvu","coxxambtmt","qohuoodthm","rxgmjckqbv","jfxrieoupd","fdwlbkcvrx","unfqgabdkf","heuazwfntq","nmdcmdidjs","pniamtjaxo","sdnvkxvooc","zclnshudjo","yubntouycs","qfylorgiru","ldguvwzpuu","bdchhjjrkm","nzbyaqyfzu","qzatfjwdni","sqjvtgdzpd","rbszsxjhxb","tzisfirwyh","ymfjqhpzdk","xoobvegggb","ruytuztznz","ieusknjkoa","chbttdgxoi","xfejvbnqib","bjhpwkvpyc","qfmisqkagu","qpxsdfftzb","zcgsjkcser","gslstcwewm","tmoukfxvly","dbgztefvwc","yserwcecfv","waikpktisk","yjcltebphr","mccghwvqac","xxzzxahign","mvillotxud","zfyauvfqbh","zvcteadqvh","dyoryffkuk","nxgptovyci","meyzjxwtnz","wrlhbkttwt","ubhvkmhima","fecksiguko","udnicxrkcv","bjnktficie","vimrcdhlny","luzmrkbuod","uckacspojy","tjulukluyk","bhmslgpeod","buihnyxiwm","xhhkrxtkav","frfhfoelfu","edljlpwcvc","fmjkgulyky","visqasusix","xpkcnxwwbj","bxqyseatub","bsmknvzupf","teqnlnqbfn","kbnwsjbltd","xeswkdeffq","cqmyyaypum","ukxcvbmpii","uozytzegjj","waqrlxtcub","njhlhaqviv","ktdrflrcqd","cbpnhtisuj","tswxgbqlff","glmygpvhun","nbhixjvzfj","divzzzleal","zqqggeleru","hjholwrjeb","vhxmagdfjc","fbrkcuzbhx","dfkolsknmq","dqunofgoai","aghwoekwoq","pjxszbkgmn","fvdoufggal","bigherqoev","nvpcvxmgyz","jjbhrhbypd","ybnqboocnw","ibealdrrev","lpuqyxcbun","qdandzyrlh","ulcmhvraxj","auxtsfahpk","ugnqonsurv","okdlcadvkr","pbzlkpdpql","mykqizxhxb","pkqcukrafd","rzyzurgvec","dbbjitryuy","tqlyfubjpy","ybmlymtzyz","fsoyqtyvll","bjzzkdfgzr","ywepvbllxo","xdxjhqppoi","brxxxyepzr","mjydksqmyw","npebewmbyy","xyfbzzmdof","wvklbqtyvn","whegjxeqtk","bkztjpzmrq","ewsthtbjrt","ardseurdzh","qnfdkabmjs","ytywartowq","fjatvetenq","wnlszaoxpa","vhhgicqxnd","gprhypmpiw","jgjkmpzzfm","wdowzmolct","finthotcit","upmceqjepq","gbrsdomlhb","mdtbsweejz","uwvgfytvgw","wcgwuovtfy","khzuaowtrn","edngubpiyj","eyinqbwtyq","denfcldgtw","svulbfdsei","gvzvthylko","hfbhlaxqoi","hjlmivcfxt","zvciwfovlc","fiiuhdpcar","mozqsoimwr","gruxkjvjue","cczeboorha","hrhmoxuvyq","cgtipwrrpn","pxtpqonuek","rrbyhollma","zlqfvuxfjk","ijwjyqxufd","zfsghopygq","evlvdkjqqg","bztnmktukx","duzyyedjvd","kriljupqls","ghnbbvwxzr","oqdiqzebno","ylmxvfjnef","lymxwcgmvg","fippvlvbeb","jhsuiwqhto","sdexilkvnz","ybgmbjthof","gnfwydxgct","sezydyhdkj","uyrelqzkdz","qqpolljsuv","azajretvon","qtskjtlhit","xwbcasyori","cmddyydphx","qhadrrqtoh","cbiebcjlsl","nolpsequkx","udcryrapth","zmoukbfnpd","xgsixdxdfx","zjvxyctdcx","dmgeicrgpz","cfzaeqhasd","mgswfhrsod","lcegawkmtv","casgahrvyr","iqtlyqiikj","sahcszkhyg","gngidasvae","xywwylkmfc","yymygkkinw","yjycfnxbwc","vucvdickiz","sljswongwi","efbwphdzel","byoymaisrh","ffvdkezyuj","gshrnnkati","wactaxdeqf","myyglkecsw","fkuefpwati","vtstuqbued","yeivgrgept","mpoudpbddi","fgihmzsbrg","akxlgbnaqe","offjwjipvo","rtmwjhkikt"};


    int l = LEN_M(m);
    printf("%s.\n", minAbbreviation(t, m, l));
}

#include "./917_reverse_only_letters.h"
void test()
{
    // char* s = "ab-cde";
    // char* s = "ab-cd";
    char* s = "Test1ng-Leet=code-Q!";
    printf("%s.\n", reverseOnlyLetters(s));
}

#include "./919_complete_binary_tree_inserter.h"
void test()
{
    // int m[] = {1, 2, 3, 4, 5, 6};
    int m[] = {1};
    int l = LEN_M(m);

    struct TreeNode* r = gen_tree(m, l);
    outTree(r);
    CBTInserter* c = cBTInserterCreate(r);
    printf("%d.\n", cBTInserterInsert(c, 2));
    outTree(cBTInserterGet_root(c));
}

#include "./918_maximum_sum_circular_subarray.h"
void test()
{

    // int m[] = {-2, -3, -1};
    // int m[] = {1, -2, 3, 2};
    // int m[] = {1, -2, 3, 32};
    // int m[] = {3, -2, 2, -3};
    // int m[] = {3, -3, 2, -3};
    // int m[] = {5, -3, 5};

    // int m[] = {6, 9, -3};
    int m[] = {-5, 4, -6};

    int l = LEN_M(m);
    printf("%d.\n", maxSubarraySumCircular(m, l));
}

#include "./920_number_of_music_playlists.h"
void test()
{
    // printf("%d.\n", numMusicPlaylists(3, 3, 1));
    // printf("%d.\n", numMusicPlaylists(2, 3, 0));
    // printf("%d.\n", numMusicPlaylists(2, 3, 1));
    // printf("%d.\n", numMusicPlaylists(2, 4, 0));
    printf("%d.\n", numMusicPlaylists(16, 16, 4));// 789741546
    // printf("%d.\n", numMusicPlaylists(16, 19, 5)); // 64612811
}

#include "./903_valid_permutations_for_DI_sequence.h"
void test()
{
    // printf("%d.\n", numPermsDISequence("DID"));
    printf("%d.\n", numPermsDISequence("DI"));
    printf("%d.\n", numPermsDISequence("ID"));
}

#include "./879_profitable_schemes.h"
void test()
{

    int g[] = {2, 2};
    int p[] = {2, 3};
    int G = 5;
    int P = 3;

    // int g[] = {2, 3, 5};
    // int p[] = {6, 7, 8};
    // int G = 10;
    // int P = 5;

    int l = LEN_M(g);

    printf("%d.\n", profitableSchemes(G, P, g, l, p, l));
}

#include "./798_smallest_rotation_with_highest_score.h"
void test()
{
    int m[] = {2, 3, 1, 4, 0};
    // int m[] = {1, 3, 0, 2, 4};
    // int m[] = {2, 4, 1, 3, 0};
    int l = LEN_M(m);

    printf("%d.\n", bestRotation(m, l));
}

#include "./679_24_game.h"
void test()
{

    // int m[] = {4, 1, 8, 7};
    // int m[] = {2, 9, 3, 6};
    // int m[] = {2, 2, 0, 0};
    int m[] = {1, 2, 1, 2};

    int l = LEN_M(m);
    printf("%d.\n", judgePoint24(m, l));
}

#include "./188_best_time_to_buy_and_sell_stock_IV.h"
void test()
{

    // int m[] = {2, 4, 1}; int k = 2;
    // int m[] = {3, 2, 6, 5, 0, 3}; int k = 30; // 7
    // int m[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; int k = 100;
    // int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; int k = 100;
    // int m[] = {5, 3, 9, 7, 2, 12, 3, 19}; int k = 1000000000;
    // int m[] = {5, 3, 9, 7, 2, 12, 3, 19}; int k = 1;
    // int m[] = {5, 3, 9, 7, 2, 12, 3, 19}; int k = 2;
    // int m[] = {5, 3, 9, 7, 2, 12, 3, 19}; int k = 3; // 32
    // int m[] = {6, 1, 3, 2, 4, 7}; int k = 2; // 7
    // int m[] = {1,2,4,2,5,7,2,4,9,0}; int k = 4;

    int l = LEN_M(m);
    printf("%d.\n", maxProfit(k, m, l));
}

#include "./921_minimum_add_to_make_parentheses_valid.h"
void test()
{
    printf("%d.\n", minAddToMakeValid("())"));
    printf("%d.\n", minAddToMakeValid("((("));
    printf("%d.\n", minAddToMakeValid("()"));
    printf("%d.\n", minAddToMakeValid("()))(("));
    printf("%d.\n", minAddToMakeValid(""));
}

#include "./922_sort_array_by_parity_II.h"
void test()
{
    int m[] = {2, 4, 5, 7};
    int l = LEN_M(m);
    int n = 0;
    out(sortArrayByParityII(dup_a(m, l), l, &n), l);
}

#include "./924_minimize_malware_spread.h"
void test()
{

    int m[] = {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1};
    int c = 10;
    int n[] = {9, 0, 2};

    int m[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int c = 3;
    int n[] = {1, 2};

    int m[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1};
    int c = 4;
    int n[] = {3, 1};

    int ln = LEN_M(n);
    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);
    int* i = dup_a(n, ln);

    printf("%d.\n", minMalwareSpread(r, c, 0, i, ln));
}

#include "./923_3sum_with_multiplicity.h"
void test()
{

    // int m[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5}; int t = 8;
    // int m[] = {1, 1, 2, 2, 2, 2}; int t = 5;

    int m[] = {16, 51, 36, 29, 84, 80, 46, 97, 84, 16}; int t = 171;

    int l = LEN_M(m);
    printf("%d.\n", threeSumMulti(m, l, t));
}

#include "./913_cat_and_mouse.h"
void test()
{

    int m1[] = {2};
    int m2[] = {2};
    int m3[] = {0, 1};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int* m[] = {m1, m2, m3};
    int ls[] = {l1, l2, l3};

    // 0
    int m1[] = {2, 5};
    int m2[] = {3};
    int m3[] = {0, 4, 5};
    int m4[] = {1, 4, 5};
    int m5[] = {2, 3};
    int m6[] = {0, 2, 3};

    // 2
    int m1[] = {2, 5};
    int m2[] = {5};
    int m3[] = {0, 4, 5};
    int m4[] = {4, 5};
    int m5[] = {2, 3, 1};
    int m6[] = {0, 2, 3};

    // 2
    int m1[] = {2, 5};
    int m2[] = {2};
    int m3[] = {0, 4, 5, 1};
    int m4[] = {4, 5};
    int m5[] = {2, 3};
    int m6[] = {0, 2, 3};

    // 2
    int m1[] = {4, 5};
    int m2[] = {5};
    int m3[] = {4, 5};
    int m4[] = {4, 5};
    int m5[] = {2, 3, 1};
    int m6[] = {0, 2, 3};

    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int* m[] = {m1, m2, m3, m4, m5, m6};
    int ls[] = {l1, l2, l3, l4, l5, l6};

    // 0
    int m1[] = {3, 4};
    int m2[] = {3, 5};
    int m3[] = {3, 6};
    int m4[] = {0, 1, 2};
    int m5[] = {0, 5, 6};
    int m6[] = {1, 4};
    int m7[] = {2, 4};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m7);
    int* m[] = {m1, m2, m3, m4, m5, m6, m7};
    int ls[] = {l1, l2, l3, l4, l5, l6, l7};

    // 1
    int m1[] = {2, 3};
    int m2[] = {3, 4};
    int m3[] = {0, 4};
    int m4[] = {0, 1};
    int m5[] = {1, 2};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int* m[] = {m1, m2, m3, m4, m5};
    int ls[] = {l1, l2, l3, l4, l5};

    // 1, why it always 0
    int m1[] = {3,4,6,7,9,15,16,18};
    int m2[] = {4,5,8,19};
    int m3[] = {4,5,6,7,9,18};
    int m4[] = {0,10,11,15};
    int m5[] = {0,1,2,6,10,12,14,16};
    int m6[] = {1,2,7,9,15,17,18};
    int m7[] = {0,2,4,7,9,10,11,12,13,14,15,17,19};
    int m8[] = {0,2,5,6,9,16,17};
    int m9[] = {1,9,14,15,16,19};
    int m10[] = {0,2,5,6,7,8,10,11,13,15,16,17,18};
    int m11[] = {3,4,6,9,17,18};
    int m12[] = {3,6,9,12,19};
    int m13[] = {4,6,11,15,17,19};
    int m14[] = {6,9,15,17,18,19};
    int m15[] = {4,6,8,15,19};
    int m16[] = {0,3,5,6,8,9,12,13,14,16,19};
    int m17[] = {0,4,7,8,9,15,17,18,19};
    int m18[] = {5,6,7,9,10,12,13,16};
    int m19[] = {0,2,5,9,10,13,16};
    int m20[] = {1,6,8,11,12,13,14,15,16};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m7);
    int l8 = LEN_M(m8);
    int l9 = LEN_M(m9);
    int l10 = LEN_M(m10);
    int l11 = LEN_M(m11);
    int l12 = LEN_M(m12);
    int l13 = LEN_M(m13);
    int l14 = LEN_M(m14);
    int l15 = LEN_M(m15);
    int l16 = LEN_M(m16);
    int l17 = LEN_M(m17);
    int l18 = LEN_M(m18);
    int l19 = LEN_M(m19);
    int l20 = LEN_M(m20);
    int* m[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};
    int ls[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20};

    // 1
    int m1[] = {6};
    int m2[] = {4};
    int m3[] = {9};
    int m4[] = {5};
    int m5[] = {1, 5};
    int m6[] = {3, 4, 6};
    int m7[] = {0, 5, 10};
    int m8[] = {8, 9, 10};
    int m9[] = {7};
    int m10[] = {2, 7};
    int m11[] = {6, 7};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m7);
    int l8 = LEN_M(m8);
    int l9 = LEN_M(m9);
    int l10 = LEN_M(m10);
    int l11 = LEN_M(m11);
    int* m[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11};
    int ls[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11};

    // 0
    int m1[] = {2,9,14};
    int m2[] = {2,5,7};
    int m3[] = {0,1,3,8,9,11,14};
    int m4[] = {2,12};
    int m5[] = {5,11,18};
    int m6[] = {1,4,18};
    int m7[] = {9,17,19};
    int m8[] = {1,11,12,13,14,17,19};
    int m9[] = {2,16,17};
    int m10[] = {0,2,6,12,14,18};
    int m11[] = {14};
    int m12[] = {2,4,7};
    int m13[] = {3,7,9,13};
    int m14[] = {7,12,14};
    int m15[] = {0,2,7,9,10,13,17};
    int m16[] = {18};
    int m17[] = {8,19};
    int m18[] = {6,7,8,14,19};
    int m19[] = {4,5,9,15};
    int m20[] = {6,7,16,17};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m7);
    int l8 = LEN_M(m8);
    int l9 = LEN_M(m9);
    int l10 = LEN_M(m10);
    int l11 = LEN_M(m11);
    int l12 = LEN_M(m12);
    int l13 = LEN_M(m13);
    int l14 = LEN_M(m14);
    int l15 = LEN_M(m15);
    int l16 = LEN_M(m16);
    int l17 = LEN_M(m17);
    int l18 = LEN_M(m18);
    int l19 = LEN_M(m19);
    int l20 = LEN_M(m20);
    int* m[] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20};
    int ls[] = {l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20};

    // 2
    int m1[] = {5};
    int m2[] = {4};
    int m3[] = {3};
    int m4[] = {2, 6};
    int m5[] = {1, 5};
    int m6[] = {0, 3, 4};
    int m7[] = {3, 5};
    int l1 = LEN_M(m1);
    int l2 = LEN_M(m2);
    int l3 = LEN_M(m3);
    int l4 = LEN_M(m4);
    int l5 = LEN_M(m5);
    int l6 = LEN_M(m6);
    int l7 = LEN_M(m7);
    int* m[] = {m1, m2, m3, m4, m5, m6, m7};
    int ls[] = {l1, l2, l3, l4, l5, l6, l7};

    int l = LEN_M(m);
    printf("%d.\n", catMouseGame(m, l, ls));
}

#include "./925_long_pressed_name.h"
void test()
{

    // char* s = "laiden";
    // char* t = "laiden";

    // char* s = "alex";
    // char* t = "aalleex"

    // char* s = "saeed";
    // char* t = "ssaaedd";

    char* s = "leelee";
    char* t = "lleeeelee";
    printf("%d.\n", isLongPressedName(s, t));
}

#include "./926_flip_string_to_monotone_increasing.h"
void test()
{
    printf("%d.\n", minFlipsMonoIncr("0"));
    printf("%d.\n", minFlipsMonoIncr("11"));
    printf("%d.\n", minFlipsMonoIncr("00110"));
    printf("%d.\n", minFlipsMonoIncr("010110"));
    printf("%d.\n", minFlipsMonoIncr("000110000"));
    printf("%d.\n", minFlipsMonoIncr("00011100"));
}

#include "./927_three_equal_parts.h"
void test()
{

    // int m[] = {1, 1, 1};
    // int m[] = {1, 0, 1, 0, 1};
    // int m[] = {0, 0, 0};
    int m[] = {1, 1, 0, 1, 1};

    int l = LEN_M(m);
    int* t = dup_a(m, l);

    int rs;
    int* r = threeEqualParts(t, l, &rs);
    out(r, rs);
}

#include "./928_minimize_malware_spread_II.h"
void test()
{

    int m[] = {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1};
    int c = 10;
    int n[] = {9, 0, 2};

    int m[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int c = 3;
    int n[] = {1, 2};

    int m[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1};
    int c = 4;
    int n[] = {3, 1};

    int m[] = {1, 1, 0, 1, 1, 0, 0, 0, 1};
    int c = 3;
    int n[] = {0, 1};

    int m[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int c = 3;
    int n[] = {0, 1};

    int m[] = {1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1};
    int c = 4;
    int n[] = {1, 0};

    int m[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    int c = 40;
    int n[] = {1, 6, 35, 5, 37, 32};


    int ln = LEN_M(n);
    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);
    int* i = dup_a(n, ln);
    //outaaa(r, c, c);

    printf("%d.\n", minMalwareSpread(r, c, 0, i, ln));
}

#include "./691_stickers_to_spell_word.h"
void test()
{

    // char* m[] = {"with", "example", "science"};char* t = "thehat";
    char* m[] = {"notice", "possible"}; char* t = "basicbasic";
    int l = LEN_M(m);
    printf("%d.\n", minStickers(m, l, t));
}

#include "./727_minimum_window_subsequence.h"
void test()
{
    // char* s = "abcdebdde"; char* t = "bdde";
    // char* s = "abcdebdde"; char* t = "bbde";
    // char* s = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl"; char* t = "k";
    printf("%s\n", minWindow(s, t));
}

#include "./882_reachable_nodes_in_subdivided_graph.h"
void test()
{

    // int m[] = {0, 1, 10, 0, 2, 1, 1, 2, 2}; int M = 6; int N = 3;
    // int m[] = {0, 1, 4, 1, 2, 6, 0, 2, 8, 1, 3, 1}; int M = 10; int N = 4;
    // int m[] = {0, 1, 4, 1, 2, 6, 0, 2, 8, 1, 3, 1}; int M = 2; int N = 4;
    int m[] = {1, 2, 4, 1, 4, 5, 1, 3, 1, 2, 3, 4, 3, 4, 5}; int M = 17; int N = 5;

    int l = LEN_M(m);
    int** r = gen_aa(m, l, 3);
    printf("%d.\n", reachableNodes(r, l / 3, 0, M, N));
}

#include "./465_optimal_account_balancing.h"
void test()
{

    int m[] = {0, 1, 10, 2, 0, 5};
    // int m[] = {0, 1, 10, 1, 0, 1, 1, 2, 5, 2, 0, 5};
    // int m[] = {0, 1, 1, 0, 2, 2, 0, 3, 3, 0, 4, 3, 0, 5, 3}; // 5

    int l = LEN_M(m);
    int** r = gen_aa(m, l, 3);

    printf("%d.\n", minTransfers(r, l / 3, 0));
}

#include "./446_arithmetic_slices_II_subsequence.h"
void test()
{

    // int* nums = calloc(sizeof(int), (1000));
    // nums[3] = 2;
    // nums[0] = nums[1] = nums[2] = 1;
    // printf("%d.\n", get_nums(nums, 1000));
    // int m[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    // int m[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // int m[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // int m[] = {7, 7, 7, 7};
    // int m[] = {7, 7, 7, 7, 7};
    // int m[] = {7, 7, 7, 7, 7, 7};
    // int m[] = {2, 4, 6, 8, 10};
    // int m[] = {1, 2, 3, 4, 5};
    // int m[] = {0, 1, 2, 2, 2};
    // int m[] = {0,2000000000,-294967296};
    // int m[] = {79,20,64,28,67,81,60,58,97,85,92,96,82,89,46,50,15,2,36,44,54,2,90,37,7,79,26,40,34,67,64,28,60,89,46,31,9,95,43,19,47,64,48,95,80,31,47,19,72,99,28,46,13,9,64,4,68,74,50,28,69,94,93,3,80,78,23,80,43,49,77,18,68,28,13,61,34,44,80,70,55,85,0,37,93,40,47,47,45,23,26,74,45,67,34,20,33,71,48,96};
    // int m[] = {1, 3, 5, 7, 7, 9};
    // int m[] = {1, 3, 5, 7, 9};
    // int m[] = {1, 3, 5, 7, 7, 9, 11};
    // int m[] = {1, 2, 3, 4, 5, 6, 7};

    int l = LEN_M(m);

    printf("%d.\n", numberOfArithmeticSlices(m, l));

}

#include "./929_unique_email_addresses.h"
void test()
{
    char* m[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@leetcode.com"};
    int l = LEN_M(m);

    printf("%d.\n", numUniqueEmails(m, l));
}

#include "./930_binary_subarrays_with_sum.h"
void test()
{
    // int m[] = {1, 0, 1, 0, 1, 0}; int s = 2;


    // int m[] = {0, 0, 0, 0, 1, 1, 1, 0}; int s = 0;
    // int m[] = {0, 0, 0, 0, 1, 1, 1, 0}; int s = 2;
    int m[] = {0, 0, 0, 0, 1}; int s = 2;
    int l = LEN_M(m);
    printf("%d.\n", numSubarraysWithSum(m, l, s));
}

#include "./931_minimum_falling_path_sum.h"
void test()
{

    // int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; int c = 3;
    int m[] = {51, 24, -50, 82}; int c = 2;

    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);

    printf("%d.\n", minFallingPathSum(r, l / c, &c));

}

#include "./932_beautiful_array.h"
void test()
{
    int r;
    out(beautifulArray(3, &r), 3);
    out(beautifulArray(4, &r), 4);
    out(beautifulArray(5, &r), 5);
    out(beautifulArray(6, &r), 6);
    out(beautifulArray(7, &r), 7);
}

#include "./932_beautiful_array.h"
void test()
{
    int n = 10;
    // beautifulArray(1000, &r);
    int* r = beautifulArray(n, &n);
    // beautifulArray(5, &r);
    out(r, n);

    for (int i = 0; i < n - 1; i ++)
        for (int j = i + 1; j < n; j ++)
        {
            for (int k = i + 1; k < j - 1; k ++)
                if (r[k] * 2 == r[i] + r[j])
                    printf("error\n");
        }
}

#include "./514_freedom_trail.h"
void test()
{
    // printf("%d.\n", findRotateSteps("godding", "gd"));
    printf("%d.\n", findRotateSteps("godding", "gg"));
}

#include "./502_ipo.h"
void test()
{

    int c[] = {0, 1, 5};
    int p[] = {1, 2, 3};
    int k = 2;
    int w = 0;

    int k = 11;
    int w = 0;
    int p[] = {319,178,37,756,152,763,481,1055,594,825,759,494,1087,696,717,358,1091,1145,1043,245,779,957,3,1060,1141,926,226,657,869,740,1170,746,889,416,634,209,1189,1076,819,1144,40,807,561,400,283,133,186,839,1043,491,936,559,70,9,854,1172,9,739,871,436,1087,1029,66,561,798,1141,701,1020,1072,92,636,509,392,77,84,202,843,563,329,906,101,997,1162,105,876,460,285,446,753,516,60,932,323,659,9,639,1041,861,1199,343,792,1114,536,405,542,805,929,589,538,410,143,114,24,1064,682,536,1016,1141,843,472,817,196,673,189,915,196,755,203,956,283,833,836,22,899,232,655,572,207,819,639,1024,887,407,385,251,896,165,290,193,357,870,678,411,697,998,344,628,866,1004,894,547,574,36,847,691,601,896,363,21,1133,115,658,855,1042,2,189,230,215,747,971,581,809,832,311,35,639,1127,701,167,672,763,997,1061,1170,289,806,91,198,720,67,273,863,437,152,671,635,968,107,58,453,392,236,875,719,44,850,176,580,937,227,125,851,1188,915,747,1175,69,743,250,275,290,787,780,516,775,279,256,649,83,1180,372,655,813,750,381,807,988,977,430,282,1067,551,726,756,372,17,1016,550,1128,223,174,85,1039,1,27,178,822,243,440,79,772,211,640,454,1141,654,351,54,794,711,157,492,307,1156,937,212,461,417,741,1104,642,1147,833,1194,1066,1070,876,1045,341,854,1014,787,518,404,1068,385,756,998,298,439,917,183,71,363,38,828,372,1071,195,481,1153,871,712,803,849,145,1144,410,420,561,678,241,498,548,436,871,810,180,635,119,665,551,1132,807,408,685,489,274,459,28,987,935,310,284,1163,924,812,267,1123,782,1065,1075,1199,1047,289,280,1044,931,1056,625,672,150,41,1084,998,151,483,226,548,277,1187,1010,262,1048,493,1084,845,1127,1009,773,129,547,798,118,559,463,972,666,1155,519,381,405,819,201,790,729,1100,614,691,3,386,206,514,387,612,1073,158,67,1116,164,496,1056,1159,348,530,28,1177,774,1139,559,563,310,916,897,36,1060,173,952,123,635,911,711,304,611,481,645,532,1033,385,402,797,117,307,969,1147,1127,434,1099,1043,104,74,257,778,934,901,106,84,525,138,698,877,1009,487,450,649,736,802,1032,456,757,10,2,720,1155,234,844,880,1053,1134,821,1094,970,1095,976,101,1163,104,38,198,350,896,345,867,1129,1064,403,228,1103,416,561,722,915,1161,252,45,632,1163,232,174,964,876,1126,479,432,984,815,544,1005,620,497,1021,763,169,1028,706,1112,150,368,483,251,721,492,686,1105,38,1140,1085,153,366,428,296,28,648,873,21,236,393,581,1043,1086,747,402,201,1196,416,788,318,257,815,735,1023,1143,1100,922,1033,884,824,963,159,904,21,1168,511,723,400,239,338,89,1099,572,674,54,891,426,277,91,504,302,616,468,506,917,491,744,1091,1051,594,465,850,338,417,320,1160,364,480,855,86,305,225,833,637,760,1147,613,236,460,664,1183,38,806,100,654,852,975,816,506,1092,275,6,229,972,53,554,370,63,651,701,304,1011,672,353,118,1111,448,549,151,1087,909,420,1095,663,1119,1124,729,578,733,861,1154,1195,387,1182,850,189,463,1129,1185,541,546,1159,314,137,479,59,841,514,548,496,642,341,151,999,1036,1186,704,550,1039,723,779,584,382,371,712,176,665,180,440,697,1102,408,728,157,1050,558,692,336,384,107,839,477,204,862,345,429,1144,1069,207,449,594,963,988,843,334,200,865,281,296,1040,914,995,743,1134,1050,484,602,1001,570,1052,1106,922,77,1099,681,360,955,1184,669,411,760,46,599,815,231,86,694,469,1079,1161,1105,519,1010,681,603,376,534,145,361,448,1006,91,397,671,597,238,119,467,587,723,162,804,638,568,195,460,610,868,806,995,1178,490,406,933,232,17,37,2,114,1004,871,531,209,267,37,750,1196,940,89,725,377,898,6,685,210,1127,1160,432,391,931,681,937,275,1190,137,743,652,430,566,180,1192,718,253,133,998,1067,764,747,1159,827,143,506,641,327,468,731,50,15,569,80,310,1086,1092,989,245,520,711,788,1144,938,1152,1169,563,1053,1182,331,838,112,361,1049,717,979,956,434,534,1083,117,280,1104,293,1137,592,1019,606,526,216,924,197,137,1041,2,910,274,1178,267,521,626,764,691,124,446,337,676,325,288,1120,924,512,777,1063,979,86,677,1183,777,418,41,852,929,712,1132,1030,339,943,475,851,340,894,1091,230,654,229,945,69,182,110,255,895,645,1061,793,1016,807,440,330,519,73,108,660,209,1077,1191,938,415,1162,579,258,14,273,561,834,371,134,1118,1139,1163,667,979,483,436,42,593,139,846,875,571,808,76,713,1198,352,299,156,793,509,245,697,1106,236,287,236,644,683};
    int c[] =  {275,430,1008,802,1067,152,913,662,1026,1173,799,478,1029,392,550,418,630,1184,1083,709,732,85,983,1175,762,783,857,652,867,11,279,915,349,1096,351,1070,237,434,647,590,669,874,14,613,1080,695,719,193,939,813,580,292,1058,1008,502,954,710,124,272,562,615,1019,1010,431,1150,433,1039,1036,161,1074,1106,1014,206,1173,121,294,554,628,1180,723,238,1121,1007,613,1061,948,324,267,814,425,95,1078,323,642,284,50,386,1134,555,1061,275,1101,643,616,173,411,531,1013,913,317,1003,402,873,231,817,374,378,132,18,619,1013,587,37,314,656,218,316,621,784,970,802,186,778,769,580,913,794,160,1176,125,969,577,701,863,78,698,838,1155,942,541,632,976,100,782,65,52,527,1191,336,1081,516,599,527,347,1174,909,707,743,280,448,172,207,999,344,99,520,207,370,280,455,1181,90,862,1056,1162,920,704,477,1036,99,458,170,684,1,187,298,43,326,172,1156,976,1087,947,67,825,1102,1148,758,45,563,973,924,170,330,754,520,693,1134,369,12,1092,183,1145,839,604,804,110,695,440,44,250,726,61,596,873,204,320,447,1085,518,311,100,1070,990,457,593,374,976,828,904,528,822,78,622,497,907,248,502,793,848,811,1122,973,1044,744,1086,841,299,635,397,1099,905,1033,980,997,551,56,352,455,653,294,179,661,248,1018,333,1,241,259,77,689,1011,818,669,636,427,730,641,62,1138,1155,520,499,307,46,240,1068,380,87,1117,171,287,1100,45,1071,467,1150,118,1106,718,1191,753,324,275,1169,587,346,1157,1094,245,243,220,996,631,41,311,759,1170,344,201,496,338,913,58,671,824,918,180,344,262,1038,623,854,785,713,367,1101,514,179,616,722,612,390,561,148,739,32,397,905,688,160,1021,117,22,547,1035,1022,893,597,430,872,101,106,421,928,200,992,812,41,1171,412,737,910,412,398,379,356,119,828,1138,1006,548,1182,718,558,956,598,751,381,502,943,823,858,842,211,786,592,1064,764,722,734,1014,628,722,613,1054,39,251,282,690,1168,338,119,237,1177,71,432,63,1010,354,427,773,661,581,320,656,673,352,265,724,548,1021,834,636,420,867,868,709,1012,95,585,167,649,660,179,984,632,611,1109,26,550,1085,61,218,819,263,217,1067,1043,1187,306,1193,611,983,973,61,433,220,722,953,364,1070,79,853,127,1137,199,35,245,1140,318,1119,144,459,1156,650,913,660,841,639,853,882,257,162,864,387,1168,1185,876,797,621,900,41,56,744,1024,539,433,148,582,619,508,1123,184,1199,1014,584,469,1120,175,945,494,269,724,74,58,627,209,424,1114,966,162,134,426,162,507,266,57,1055,522,140,1083,151,501,441,567,25,294,601,147,714,955,605,632,643,698,649,362,553,268,1101,939,697,762,848,731,150,138,544,1013,1063,751,1014,829,361,933,415,173,1118,716,1133,764,662,958,107,270,739,792,478,519,236,267,707,829,532,347,126,190,637,985,604,759,952,572,1150,1199,472,33,69,797,195,332,101,987,66,1089,901,1030,1188,1142,1130,1044,24,1048,901,1124,589,75,50,136,797,1122,1145,1025,964,25,411,432,940,72,17,1183,871,990,101,1035,250,1176,564,632,494,389,64,10,754,71,914,10,296,524,374,894,1187,585,504,175,858,1083,1077,7,103,390,885,1120,1181,1159,752,670,1148,23,152,1136,173,1043,657,267,358,792,1144,612,477,1042,1058,846,560,1189,695,548,250,900,340,1092,1162,225,576,618,1136,485,591,305,513,65,221,1062,880,303,196,1167,415,148,1140,1067,511,26,63,515,232,1001,456,394,418,999,181,1042,428,1041,829,839,29,478,12,766,75,178,994,606,1089,681,870,423,664,1004,357,184,988,75,963,740,775,427,123,1039,476,815,799,739,737,138,824,228,197,291,1121,805,645,229,1172,68,1011,612,925,1056,719,593,735,688,1180,684,1085,220,63,176,198,257,969,496,1087,55,664,823,280,6,655,756,814,516,445,220,707,186,641,779,729,712,136,982,33,594,1043,888,429,750,840,512,484,77,223,577,664,8,448,326,518,514,771,681,280,351,149,894,106,563,966,529,123,799,532,804,837,261,973,427,515,645,906,927,51,856,528,260,324,757,542,918,636,1060,1064,1,1128,165,65,948,518,222,521,791,983,699,402,927,41,543,1194,474,309,777,398,1058,800,97,1009,1040,245,180,676,980,653,659,997,1143,978,6,315,475,218,1075,909,291,20,19,941,945,437,168,972,16,1147,1008,969,232,1114,267,832,208,920,910,717,1101,899,744,809,47,767,482,825,193,577,1007,31,478,382,407,905,830,843,336,103,904,763,91,14,283,692,330,924,583,1106,1065,572,786,808,350,177,386,936,503,1125,788,176,669,836,1014,1023,28,798,296,423,464,190,554};

    int k = 111;
    int w = 12;
    int p[] = {319,178,37,756,152,763,481,1055,594,825,759,494,1087,696,717,358,1091,1145,1043,245,779,957,3,1060,1141,926,226,657,869,740,1170,746,889,416,634,209,1189,1076,819,1144,40,807,561,400,283,133,186,839,1043,491,936,559,70,9,854,1172,9,739,871,436,1087,1029,66,561,798,1141,701,1020,1072,92,636,509,392,77,84,202,843,563,329,906,101,997,1162,105,876,460,285,446,753,516,60,932,323,659,9,639,1041,861,1199,343,792,1114,536,405,542,805,929,589,538,410,143,114,24,1064,682,536,1016,1141,843,472,817,196,673,189,915,196,755,203,956,283,833,836,22,899,232,655,572,207,819,639,1024,887,407,385,251,896,165,290,193,357,870,678,411,697,998,344,628,866,1004,894,547,574,36,847,691,601,896,363,21,1133,115,658,855,1042,2,189,230,215,747,971,581,809,832,311,35,639,1127,701,167,672,763,997,1061,1170,289,806,91,198,720,67,273,863,437,152,671,635,968,107,58,453,392,236,875,719,44,850,176,580,937,227,125,851,1188,915,747,1175,69,743,250,275,290,787,780,516,775,279,256,649,83,1180,372,655,813,750,381,807,988,977,430,282,1067,551,726,756,372,17,1016,550,1128,223,174,85,1039,1,27,178,822,243,440,79,772,211,640,454,1141,654,351,54,794,711,157,492,307,1156,937,212,461,417,741,1104,642,1147,833,1194,1066,1070,876,1045,341,854,1014,787,518,404,1068,385,756,998,298,439,917,183,71,363,38,828,372,1071,195,481,1153,871,712,803,849,145,1144,410,420,561,678,241,498,548,436,871,810,180,635,119,665,551,1132,807,408,685,489,274,459,28,987,935,310,284,1163,924,812,267,1123,782,1065,1075,1199,1047,289,280,1044,931,1056,625,672,150,41,1084,998,151,483,226,548,277,1187,1010,262,1048,493,1084,845,1127,1009,773,129,547,798,118,559,463,972,666,1155,519,381,405,819,201,790,729,1100,614,691,3,386,206,514,387,612,1073,158,67,1116,164,496,1056,1159,348,530,28,1177,774,1139,559,563,310,916,897,36,1060,173,952,123,635,911,711,304,611,481,645,532,1033,385,402,797,117,307,969,1147,1127,434,1099,1043,104,74,257,778,934,901,106,84,525,138,698,877,1009,487,450,649,736,802,1032,456,757,10,2,720,1155,234,844,880,1053,1134,821,1094,970,1095,976,101,1163,104,38,198,350,896,345,867,1129,1064,403,228,1103,416,561,722,915,1161,252,45,632,1163,232,174,964,876,1126,479,432,984,815,544,1005,620,497,1021,763,169,1028,706,1112,150,368,483,251,721,492,686,1105,38,1140,1085,153,366,428,296,28,648,873,21,236,393,581,1043,1086,747,402,201,1196,416,788,318,257,815,735,1023,1143,1100,922,1033,884,824,963,159,904,21,1168,511,723,400,239,338,89,1099,572,674,54,891,426,277,91,504,302,616,468,506,917,491,744,1091,1051,594,465,850,338,417,320,1160,364,480,855,86,305,225,833,637,760,1147,613,236,460,664,1183,38,806,100,654,852,975,816,506,1092,275,6,229,972,53,554,370,63,651,701,304,1011,672,353,118,1111,448,549,151,1087,909,420,1095,663,1119,1124,729,578,733,861,1154,1195,387,1182,850,189,463,1129,1185,541,546,1159,314,137,479,59,841,514,548,496,642,341,151,999,1036,1186,704,550,1039,723,779,584,382,371,712,176,665,180,440,697,1102,408,728,157,1050,558,692,336,384,107,839,477,204,862,345,429,1144,1069,207,449,594,963,988,843,334,200,865,281,296,1040,914,995,743,1134,1050,484,602,1001,570,1052,1106,922,77,1099,681,360,955,1184,669,411,760,46,599,815,231,86,694,469,1079,1161,1105,519,1010,681,603,376,534,145,361,448,1006,91,397,671,597,238,119,467,587,723,162,804,638,568,195,460,610,868,806,995,1178,490,406,933,232,17,37,2,114,1004,871,531,209,267,37,750,1196,940,89,725,377,898,6,685,210,1127,1160,432,391,931,681,937,275,1190,137,743,652,430,566,180,1192,718,253,133,998,1067,764,747,1159,827,143,506,641,327,468,731,50,15,569,80,310,1086,1092,989,245,520,711,788,1144,938,1152,1169,563,1053,1182,331,838,112,361,1049,717,979,956,434,534,1083,117,280,1104,293,1137,592,1019,606,526,216,924,197,137,1041,2,910,274,1178,267,521,626,764,691,124,446,337,676,325,288,1120,924,512,777,1063,979,86,677,1183,777,418,41,852,929,712,1132,1030,339,943,475,851,340,894,1091,230,654,229,945,69,182,110,255,895,645,1061,793,1016,807,440,330,519,73,108,660,209,1077,1191,938,415,1162,579,258,14,273,561,834,371,134,1118,1139,1163,667,979,483,436,42,593,139,846,875,571,808,76,713,1198,352,299,156,793,509,245,697,1106,236,287,236,644,683};
    int c[] = {487,13,943,31,661,656,690,175,1147,760,96,290,755,504,1111,219,187,641,380,886,781,214,714,594,41,1154,908,977,1183,28,464,524,895,1177,28,225,1180,206,387,25,166,207,394,418,771,719,153,836,970,589,114,67,1180,1136,863,1144,21,9,957,861,981,849,1031,361,541,649,220,718,263,390,24,830,103,955,233,1174,521,580,83,869,321,712,1011,130,297,835,406,543,849,681,337,355,867,863,552,883,155,762,982,129,605,125,1111,442,89,1139,1084,870,183,1142,78,12,893,677,817,348,1036,482,76,619,563,435,529,311,1148,629,786,288,112,995,854,844,1002,948,570,736,1088,354,618,876,926,150,1108,412,707,233,137,775,751,1137,481,349,150,518,1165,191,223,754,419,1025,817,1001,278,692,403,1023,106,78,124,679,598,727,1026,966,564,726,1148,643,806,1182,645,300,867,613,458,844,679,907,437,1012,902,18,843,190,43,705,818,957,146,1175,130,744,941,975,692,1066,541,335,20,311,606,377,558,113,545,1115,228,29,2,1180,331,1072,151,692,1156,347,293,1135,959,865,1031,40,425,1191,1178,87,989,92,1186,1072,105,1058,369,401,1117,220,484,181,901,321,923,263,72,685,820,1123,736,942,37,419,631,545,761,227,230,25,636,1048,834,736,899,530,217,669,278,653,657,857,724,782,146,780,615,1156,751,463,625,707,355,92,718,855,624,504,359,744,793,868,462,985,1087,517,886,83,221,383,601,709,683,1097,544,411,28,1129,781,13,752,347,1150,1030,269,701,658,658,1188,222,1160,480,953,203,132,17,723,927,911,448,977,1126,219,118,1033,919,1041,712,930,963,772,264,523,479,735,919,72,1019,131,15,628,331,408,578,37,1123,125,527,887,54,1043,259,654,557,872,505,700,1077,202,368,628,29,66,199,611,730,1108,682,705,628,1001,705,21,266,428,1093,800,742,701,715,845,1151,300,460,1134,708,443,706,819,296,199,671,452,626,386,569,999,326,1081,202,384,783,541,811,1058,684,146,288,1149,480,0,658,547,773,588,758,189,489,257,436,362,417,180,671,141,657,864,808,1026,504,827,1125,977,1161,699,360,689,520,796,147,746,978,833,82,102,254,736,88,525,1037,659,1061,333,663,520,6,439,823,1151,395,188,32,513,34,805,1017,1193,157,942,87,630,915,807,215,482,1132,23,1008,1175,724,1070,339,1139,22,455,306,369,151,1031,1119,846,1195,49,1169,773,706,45,747,875,944,1161,1025,258,765,1039,459,641,1169,211,894,556,253,831,1115,458,351,1138,58,1169,1190,743,611,392,1015,54,831,330,1138,681,1012,750,967,1179,398,564,5,2,143,787,197,590,144,589,588,493,524,748,1123,707,585,641,293,871,331,1173,280,218,931,11,663,1005,1118,555,1000,699,720,81,527,71,458,462,1056,447,491,1068,1078,842,455,497,959,745,654,1011,939,787,430,535,594,940,1176,656,207,815,1133,610,1113,596,1018,961,840,555,582,1187,828,161,983,686,870,800,525,34,1013,385,870,953,59,518,521,151,633,561,848,310,712,108,1148,446,480,983,110,442,182,119,463,909,690,48,1040,631,17,1027,158,353,108,524,335,1046,514,1027,746,917,378,437,606,829,743,462,1013,525,290,477,749,896,12,351,13,42,819,334,912,30,1041,815,307,1138,168,209,1134,100,276,292,283,1074,123,561,857,92,879,58,706,532,75,49,385,342,887,646,301,54,483,589,1084,1092,178,845,243,873,611,340,712,115,157,63,773,800,844,167,384,522,877,183,368,709,501,905,512,756,246,197,463,47,232,256,37,883,1048,774,431,943,868,111,163,336,648,313,858,536,416,680,951,320,499,199,234,482,529,676,26,1180,721,877,586,628,1152,835,1145,447,763,750,188,1169,596,1125,310,519,1165,488,1063,59,292,701,1078,1088,663,512,172,477,187,215,1192,22,827,279,607,286,179,744,569,500,510,1038,570,1159,520,1070,759,831,906,644,753,574,257,983,1023,227,460,710,169,595,249,111,73,991,933,448,655,559,183,244,44,644,935,466,97,605,460,800,229,977,675,236,946,73,456,623,499,423,162,342,914,386,1082,407,954,1081,1099,142,539,416,791,1195,1099,885,965,971,796,1198,449,768,792,541,18,476,303,137,319,1008,343,733,128,641,709,175,691,227,307,1177,1198,1075,747,944,1038,933,643,613,1166,1153,120,288,1167,246,1103,185,85,1008,1060,1051,421,150,601,376,183,1028,146,297,515,688,886,1090,552,969,903,1086,931,946,1099,546,17,851,908,1170,418,94,61,233,1069,510,783,302,701,564,1195,57,1007,994,205,1019,694,1020,137,1041,803,673,1162,14,904,418,1076,514,79,944,242,491,867,934,40,1059,776,817,468,516,550,906,790,459,273,924,185,1183,337,435,699,316,768};

    int l = LEN_M(c);
    printf("%d.\n", findMaximizedCapital(k, w, p, l, c, l));
}

#include "./793_preimage_size_of_factorial_zeros_function.h"
void test()
{
    // printf("%d.\n", preimageSizeFZF(107374179));
    printf("%d.\n", preimageSizeFZF(0));
}

#include "./774_minimize_max_distance_to_gas_station.h"
void test()
{

    int m[] = {23,24,36,39,46,56,57,65,84,98};
    int k = 1;

    int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;

    int m[] = {10,19,25,27,56,63,70,87,96,97};
    int k = 3;

    int m[] = {8,14,27,53,59,61,75,76,82,93};
    int k = 13;

    int m[] = {45996,86069,130401,220615,304522,331400,378378,483984,511702,561985,629826,680384,682617,751273,874965,884597,969620,1013498,1026350,1037717,1050250,1113187,1139177,1149410,1203396,1209426,1283540,1292984,1310715,1403723,1412404,1463294,1465000,1490829,1522033,1553019,1600099,1600381,1601543,1648452,1650109,1682968,1809776,1811855,1860779,1937920,1941644,1981149,2125028,2126542,2141662,2155062,2173018,2184766,2231253,2255707,2294047,2326084,2336342,2362770,2384517,2393895,2484377,2557073,2560859,2661820,2679555,2711417,2804767,2885212,2887991,2965800,3112242,3178374,3215948,3228171,3313702,3346781,3368632,3372228,3391039,3403743,3423747,3426783,3429037,3569221,3610745,3741529,3751257,3787739,3822544,3869222,4006449,4040047,4044717,4143267,4186021,4218259,4269210,4309798,4315158,4385381,4431459,4448145,4492437,4523366,4676829,4719364,4893516,4986661,5027563,5059355,5091527,5223492,5532849,5539873,5609988,5620534,5671573,5679593,5683405,5693560,5728755,5799613,5807118,5911855,5934971,5953853,5975864,6160136,6172870,6216269,6253966,6340971,6343927,6376030,6378796,6412078,6452339,6558482,6585092,6646854,6650075,6684334,6686062,6696485,6737236,6757496,6890757,6893305,7007904,7014599,7099006,7155723,7217681,7424636,7444203,7531194,7555824,7651982,7679296,7707326,7775100,7778831,7989444,8028353,8098682,8163926,8209875,8402323,8404439,8500055,8570220,8607976,8698965,8700642,8795712,8834775,8896246,9039463,9377025,9383934,9388515,9441418,9526213,9566629,9598137,9621037,9633849,9683133,9691983,9714458,9784412,9802834,9876831,9890676,9911313,9915364,9941144,9979400,10057688,10130685,10173381,10245831,10328063,10349102,10396505,10408175,10440292,10446602,10575921,10614913,10655148,10914732,10936934,11002226,11021901,11057443,11127727,11202957,11263532,11286021,11326066,11345755,11389515,11480081,11500852,11603475,11647569,11672675,11720563,11729308,11810211,11821819,11826023,11844353,11934043,11937582,12076094,12178479,12201834,12205018,12233984,12289485,12326656,12331962,12370500,12387231,12413759,12417936,12613175,12621121,12770025,12816722,12848156,12863241,12864789,12943406,13191644,13217724,13237947,13330088,13359637,13399942,13451442,13599610,13638900,13648583,13653179,13665177,13727975,13818930,13898867,13909857,13958468,13971959,14035904,14114738,14137831,14138013,14140032,14170357,14176937,14205916,14206805,14276665,14326420,14593120,14598133,14617963,14632772,14731151,14773126,14777509,14822321,14862385,14908567,14956916,14968919,14989952,15034992,15321734,15366488,15424652,15450480,15520636,15559216,15743651,15744449,15746148,15792658,15856570,15956126,16006981,16064049,16351556,16371873,16392594,16397412,16440264,16445630,16449621,16528824,16562782,16583157,16694459,16700989,16799787,16851845,16893631,16908687,16958453,16966944,17132977,17210921,17379086,17398602,17403566,17421827,17493929,17506644,17525020,17562451,17573388,17641499,17682543,17706578,17717546,17788523,17822979,17867906,17869971,17964907,18010641,18014305,18037121,18090908,18102490,18102948,18148626,18154852,18188137,18232360,18240064,18315987,18347674,18360207,18389363,18405260,18409935,18436896,18444713,18448440,18453119,18462185,18484696,18509157,18510472,18564329,18616455,18620375,18651687,18677982,18692885,18738263,18746277,18782560,18821965,18846989,18913744,19060289,19081880,19124859,19181834,19184907,19185776,19208448,19212107,19225164,19245515,19257218,19272855,19273796,19330666,19334074,19334874,19392208,19406641,19678459,19680616,19869225,20018552,20161214,20273645,20352083,20419403,20482787,20555310,20585175,20656393,20758340,20816678,20961900,20994415,21018620,21039863,21047864,21094264,21108677,21146858,21157589,21174906,21180575,21202102,21241848,21255322,21283756,21422140,21539662,21592268,21652350,21671215,21681718,21769653,21780062,21821344,21846099,21860487,21953821,22044115,22073759,22078186,22109150,22228565,22275491,22304549,22315056,22419722,22571562,22571912,22658131,22757737,22812930,22846301,22847110,22861908,22930805,22959876,22970898,22973202,22988653,23011530,23084405,23193591,23195292,23319816,23354867,23372329,23514850,23552244,23567938,23604800,23684126,23717886,23732834,23869004,23880473,23892529,23945820,23978860,23990451,24048817,24130184,24134411,24162321,24226574,24231291,24231668,24235732,24249386,24289721,24314199,24327590,24348583,24353140,24374676,24414197,24514360,24522662,24618691,24648045,24719890,24739619,24993307,25025434,25049106,25150871,25219509,25227638,25228695,25235211,25237246,25249602,25250553,25312630,25385052,25431540,25551366,25571349,25597143,25601124,25619385,25678183,25738816,25812296,25885949,25988105,26026697,26029194,26039138,26043602,26056793,26096435,26097410,26097656,26168096,26189190,26190974,26202083,26298812,26381350,26528553,26554873,26588829,26741228,26769975,26842808,26863660,26916142,26918929,26973766,27018866,27074401,27082947,27211201,27259599,27291051,27308756,27327187,27356505,27375428,27410167,27517586,27519102,27613827,27617843,27627311,27715582,27754884,27764293,27788833,27796906,27887764,27920164,27985924,28025933,28061527,28142196,28161791,28194930,28235058,28355394,28411564,28486118,28521467,28617888,28626118,28698813,28720690,28791475,28847534,28940077,28994860,29049170,29073151,29152625,29236513,29238413,29298557,29322235,29334000,29533375,29537589,29537609,29549196,29556111,29593931,29605789,29620754,29621303,29624296,29634662,29639216,29660738,29662112,29768869,29890519,29895781,29991211,30136856,30147863,30284885,30407225,30446697,30480367,30514156,30514890,30519263,30542740,30545802,30546236,30587715,30701874,30702768,30703997,30722158,30734193,30774808,30826450,30936132,31037249,31058659,31083022,31083061,31110356,31124591,31147245,31186463,31234437,31355121,31384291,31386810,31441470,31544424,31708472,31713864,31724589,31737876,31831806,31950088,32085058,32100786,32121706,32161298,32175157,32186947,32250964,32290963,32321100,32328885,32398431,32424226,32490862,32492765,32518929,32588242,32592986,32743379,32764837,32808663,32859666,32959111,32972458,32987212,33016662,33050063,33145943,33182255,33184531,33198055,33210782,33214022,33302285,33384875,33443739,33449403,33459696,33600949,33616773,33628788,33652350,33686726,33733559,33776777,33915809,34102946,34175029,34246360,34249279,34262527,34384948,34385028,34400879,34429574,34446374,34461064,34549641,34578165,34614201,34689528,34700609,34744595,34766170,34810291,34864535,35021543,35113740,35133748,35184936,35216826,35260164,35281928,35549156,35550611,35559140,35610952,35720700,35738599,35840794,35866140,35954194,36058169,36176583,36222422,36265179,36271983,36281109,36281140,36298404,36347986,36375085,36405339,36444246,36540213,36593004,36635854,36724225,36815264,36880812,36885140,36941357,37005881,37058189,37063825,37074232,37142597,37306282,37352907,37371948,37463881,37470944,37543712,37551676,37632030,37632561,37652540,37665452,37754283,37820018,37849858,37892355,37912494,37981349,38015833,38034006,38034937,38035407,38055973,38058811,38101080,38105582,38175458,38296815,38366258,38422152,38425445,38432505,38469985,38493806,38543375,38550866,38587949,38624524,38629152,38629901,38645988,38681465,38713282,38723796,38743472,38917178,39078033,39201170,39221573,39261362,39289087,39311041,39318882,39352653,39535770,39580831,39614593,39660707,39695277,39713767,39740736,39769907,39771664,39790788,39904019,39944264,39965771,40001024,40035600,40154690,40155540,40179590,40193099,40205118,40360111,40420624,40438776,40451441,40478231,40501212,40536582,40548294,40572119,40624929,40650730,40765247,40791464,40802336,40803476,40817230,40933832,40938856,40942886,40949468,41006258,41026164,41066016,41128606,41206279,41322280,41340130,41366380,41481952,41488859,41535956,41537751,41568683,41585568,41615653,41668092,41685649,41694914,42021254,42023504,42114897,42203403,42243225,42277640,42316974,42324281,42388500,42463794,42468129,42469342,42500308,42508095,42514724,42520288,42525024,42552215,42646147,42693736,42705512,42798361,42829041,42894505,43016938,43029497,43069804,43116233,43168231,43344903,43448841,43473170,43609131,43650247,43684657,43706461,43722230,43731923,43758218,43764523,43832215,43857272,43865793,43922067,44020056,44056009,44084788,44143942,44190863,44233547,44237898,44256001,44261347,44262234,44349399,44378615,44529694,44593851,44610338,44663927,44664787,44689096,44768074,44789592,44796022,44820670,44838761,44847105,44873345,44878284,45153298,45200647,45301664,45395541,45491960,45507585,45560707,45566662,45572866,45785303,45845034,45857385,45893418,45935080,45953568,45957345,46097713,46127018,46181228,46183913,46205426,46214624,46218504,46263668,46283306,46294427,46343702,46513858,46527310,46536037,46545352,46563250,46570355,46599873,46609989,46651604,47180238,47223410,47266978,47349505,47356334,47363131,47471027,47601483,47712401,47828536,47850182,47909119,48135389,48161516,48163080,48180977,48192906,48213853,48245462,48264520,48374886,48420484,48500566,48546949,48597133,48607067,48626725,48648009,48651799,48670345,48704146,48767027,48826962,48850749,48915523,48978796,49007849,49163672,49196374,49362349,49436447,49480719,49484102,49496651,49499974,49527874,49560441,49561597,49649657,49882163,49895671,49908922,49913549,49968897,50039870,50097636,50190959,50196231,50288708,50317589,50392603,50416270,50421670,50516131,50551577,50556317,50581367,50606547,50659217,50698192,50770603,50816206,50851583,50896402,50925757,50953486,50985052,51051126,51056706,51068102,51106160,51156933,51224144,51284251,51312787,51375516,51399714,51436356,51544125,51625782,51739457,51757541,51950651,51951997,52041774,52091975,52145578,52263208,52275400,52315481,52352710,52382723,52418703,52493223,52564004,52666330,52667991,52674915,52708905,52714039,52767265,52789927,52840671,52906269,52957990,53089443,53108001,53236545,53386606,53425869,53438405,53465389,53485597,53501007,53507561,53512197,53587674,53629910,53632459,53668826,53684664,53711881,53719985,53751051,53756227,53761355,54030860,54052372,54165472,54173938,54192985,54237561,54261721,54275878,54363522,54373959,54391842,54413405,54413564,54452492,54571111,54642693,54681666,54728958,54792867,54804641,54817144,54946776,54976002,55067761,55095749,55139934,55148026,55151752,55156119,55190456,55201704,55221307,55293502,55339483,55391179,55392338,55531031,55562667,55587905,55686811,55701844,55840872,55991737,55999215,56030488,56035603,56037950,56142508,56362672,56418896,56496644,56528366,56544625,56590360,56638462,56734290,56767415,56789465,56790819,56822357,56861749,56876976,56916605,56926286,57057930,57104763,57105239,57194203,57279497,57449806,57451006,57660020,57760321,57770342,57796981,57806113,57934856,58063391,58066164,58106436,58236878,58261335,58436676,58563450,58594957,58652529,58674361,58698732,58762768,58785714,58806255,59022579,59045788,59114472,59114561,59160860,59274118,59355832,59410872,59417979,59428286,59436316,59507007,59529871,59623686,59736780,59746406,59763645,59795374,59828035,59852107,60011223,60046237,60092254,60198026,60276778,60299092,60299945,60352655,60413500,60508347,60555011,60849910,60935384,60954851,61021239,61089054,61095896,61113067,61118139,61141005,61160675,61240248,61243746,61283864,61289514,61308890,61313269,61366187,61385789,61447967,61573685,61592922,61634078,61681890,61685454,61718989,61762549,61862610,61875920,62037037,62048556,62241070,62431273,62437767,62474391,62474640,62483866,62509031,62566349,62580631,62585281,62617698,62735202,62736308,62759600,62811082,62834771,62895264,62930865,63026833,63031106,63113281,63133275,63157990,63158273,63196561,63207530,63234552,63289197,63299545,63361100,63409196,63531532,63542650,63714609,63723578,63758766,63888963,63989000,64017487,64020289,64062719,64255668,64268422,64304189,64305203,64307908,64309688,64332789,64559178,64577141,64675713,64757504,64787619,64872829,64918179,64966330,65041843,65150429,65157808,65172338,65282605,65283502,65346866,65361143,65517378,65550020,65572104,65612712,65675539,65686205,65705207,65729231,65791118,65794370,65803847,65910306,66038939,66072928,66141856,66158929,66261947,66408355,66416217,66633055,66768861,66827842,66997148,67011452,67205660,67299386,67307719,67373052,67394189,67402474,67402673,67414997,67436485,67436637,67497349,67563709,67572994,67583568,67595307,67708964,67726212,67756575,67999058,68025728,68189794,68232246,68362260,68430155,68445102,68458228,68543819,68597212,68733252,68769716,68777209,68788185,68802854,68804086,69135015,69220069,69228992,69306093,69336275,69339271,69412586,69430314,69489153,69532185,69611869,69697169,69754083,69775952,69788263,69798630,69892303,69932220,70031671,70100390,70112645,70298215,70353680,70388132,70460414,70461455,70546899,70560298,70581108,70598945,70614521,70902756,70924663,70925820,70969990,71062852,71198492,71335073,71374296,71390526,71488134,71578313,71580020,71649109,71738594,71765573,71819582,71820541,71837827,71881949,71981243,71997435,72036003,72220006,72224612,72272908,72294572,72302196,72337684,72354721,72377023,72493617,72551116,72552739,72560083,72601473,72636778,72734882,72741733,72751471,72780808,72802392,72828730,72866613,72875949,72975002,73127542,73148173,73256521,73260755,73273467,73297641,73496801,73637603,73652050,73660672,73688697,73772525,73833156,73875695,73942357,74106265,74148868,74170474,74213897,74216812,74265275,74372806,74396913,74669135,74678391,74724871,74783679,74806662,75004686,75012195,75028592,75034357,75054610,75089316,75093329,75131150,75330496,75370182,75403880,75410095,75418365,75515728,75518021,75519073,75533226,75750382,75794416,75802008,76022593,76031513,76079261,76118831,76188093,76223288,76229524,76269769,76273868,76314700,76440594,76526728,76659058,76674948,76702289,76736725,76770162,76872203,77037164,77119514,77155596,77239926,77250411,77323336,77324934,77329112,77377436,77586751,77649288,77659622,77734913,77768072,77835400,77842200,78109386,78121539,78167393,78201218,78210288,78282421,78288486,78365340,78416530,78487449,78532345,78575918,78592297,78643320,78660136,78738832,78787659,78871763,78987873,79115854,79151527,79189469,79265622,79399056,79511504,79535825,79635501,79650145,79721104,79767563,79782047,79792695,79901244,79922127,79929730,79943994,79994048,80199739,80277969,80289295,80376086,80414148,80496328,80516393,80531676,80577092,80607490,80609504,80689429,80690937,80775174,80788696,80804400,80806194,80879637,80928147,80945797,80962615,81021897,81051549,81094784,81137555,81216938,81291605,81320479,81326705,81335347,81346089,81396622,81442317,81519908,81522436,81614309,81645668,81659390,81685150,81688235,81722285,81764247,81793164,81843828,81847930,81848963,81866715,81877551,81908775,81967776,82021012,82059196,82091171,82098899,82102227,82128317,82186419,82193034,82200512,82232437,82234756,82277457,82290224,82293479,82321769,82323580,82344595,82475333,82498520,82667368,82671405,82694938,82697287,82720776,82754876,82770682,82909138,82912513,82944639,83000561,83005490,83049146,83067294,83138566,83178929,83198187,83224610,83240785,83249253,83266958,83272691,83431973,83466560,83469574,83473427,83514996,83548362,83569689,83726809,83852362,83980528,83992616,84033304,84093400,84135198,84211510,84220279,84340049,84411129,84446940,84457324,84495164,84641564,84652105,84813977,84861837,84946370,84947772,84971659,84980318,84992212,85154194,85228620,85302442,85319183,85351125,85514906,85589916,85649160,85665992,85690260,85695381,85697440,85745178,85811025,85994584,86003770,86029041,86049215,86101781,86175904,86201501,86307665,86436439,86526845,86549929,86551934,86591156,86676152,86740758,86774429,86798837,86807125,86812324,86838205,86847213,86892132,86898433,86930045,86997517,87039293,87072898,87156960,87186946,87188987,87199622,87204146,87324217,87432903,87466604,87468876,87505729,87600943,87626109,87678691,87686994,87773581,87809257,87829679,87854470,87931347,87959346,87987914,88052119,88108136,88116995,88254818,88258459,88322318,88369872,88428792,88474116,88496748,88599432,88615453,88654402,88681749,88718910,88754075,88760623,88773629,88835156,88922610,88970049,88987480,89065216,89065939,89088944,89105114,89266712,89277690,89380728,89406314,89618976,89818384,89890200,89916537,89941925,89945046,89956989,89968695,90013679,90031159,90076694,90091663,90096589,90155412,90269541,90303833,90381368,90461984,90589290,90602710,90771753,90781172,90923098,91022298,91045752,91123019,91241337,91266991,91279631,91306181,91335139,91448686,91547272,91606740,91685403,91705425,91706175,91726538,91789921,91789945,91808313,91809904,91937517,91979364,91986369,92020786,92106031,92156580,92287193,92322644,92409063,92425674,92612496,92642604,92660499,92691202,92698055,93110419,93203987,93230200,93244639,93308525,93377085,93416224,93441718,93507925,93519454,93560497,93580697,93626446,93778427,93780851,93843046,93867529,93885452,93912318,94049005,94073697,94122076,94191925,94300070,94337606,94401731,94414941,94466564,94564342,94591580,94662897,94702854,94716466,94741920,94918605,94988275,95021528,95076430,95094383,95127720,95134371,95146423,95209532,95214134,95267772,95344523,95348100,95417116,95511003,95770754,95783851,95807850,95813755,95830831,95916244,95952204,96180954,96214653,96237432,96312303,96317638,96333728,96550341,96766201,96778331,96928533,96930466,96969915,96996838,97073728,97230990,97315004,97375916,97376329,97381303,97409050,97437185,97481321,97535289,97549981,97665174,97672229,97689008,97703330,97759465,97954058,98065825,98078860,98149689,98189629,98201239,98221369,98248127,98287275,98332342,98345768,98450026,98465352,98470362,98477956,98483935,98484043,98492933,98527364,98554396,98578660,98581216,98620798,98654460,98667052,98810790,98813146,98993094,98993627,99008450,99022564,99071006,99081154,99146489,99155702,99222686,99229993,99283535,99289005,99298363,99330992,99545370,99739322,99792045,99831574,99843461,99991081};
    int k = 972559;

    int l = LEN_M(m);

    printf("%f.\n", minmaxGasDist(m, l, k));
}

#include "./629_K_inverse_pairs_array.h"
void test()
{
    // printf("%d.\n", kInversePairs(3, 1));
    // printf("%d.\n", kInversePairs(3, 2));
    // printf("%d.\n", kInversePairs(10, 3));
    // printf("%d.\n", kInversePairs(10, 7));
    // printf("%d.\n", kInversePairs(3, 1));
    printf("%d.\n", kInversePairs(1000, 1000));
}

#include "./757_set_intersection_size_at_least_two.h"
void test()
{
    // int m[] = {51, 24, -50, 82};
    int m[] = {2,10,3,7,3,15,4,11,6,12,6,16,7,8,7,11,7,15,11,12};
    int c = 2;

    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);

    printf("%d.\n", intersectionSizeTwo(r, l / c, c));
}

#include "./933_number_of_recent_calls.h"
void test()
{
    RecentCounter* obj = recentCounterCreate();
    printf("%d\n", recentCounterPing(obj, 1));
    printf("%d\n", recentCounterPing(obj, 2));
    printf("%d\n", recentCounterPing(obj, 100));
    printf("%d\n", recentCounterPing(obj, 1000));
    printf("%d\n", recentCounterPing(obj, 3000));
    printf("%d\n", recentCounterPing(obj, 3001));
    printf("%d\n", recentCounterPing(obj, 3002));
    printf("%d\n", recentCounterPing(obj, 3200));
}

#include "./934_shortest_bridge.h"
void test()
{
    // int m[] = {0, 1, 1, 0}; int c = 2;
    // int m[] = {0, 1, 0, 0, 0, 0, 0, 0, 1}; int c = 3;

    int m[] = {
               1, 1, 1, 1, 1,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 0, 0, 0, 1,
               0, 0, 1, 1, 1,
    }; int c = 5;

    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);

    printf("%d.\n", shortestBridge(r, l / c, &c));
}

#include "./935_knight_dialer.h"
void test()
{
    printf("%d.\n", knightDialer(1));
    printf("%d.\n", knightDialer(2));
    printf("%d.\n", knightDialer(3));
    printf("%d.\n", knightDialer(3));
    printf("%d.\n", knightDialer(3));
    printf("%d.\n", knightDialer(5000));
}

#include "./664_strange_printer.h"
void test()
{
    // printf("%d.\n", strangePrinter("s"));
    // printf("%d.\n", strangePrinter("aabaa"));
    // printf("%d.\n", strangePrinter("fneinfeinfienofeni983fenifneoifneofneifnoenfioenf9enfen8f3en3f98n39n3nfienifneinabaaaababbbbbbc"));
    // printf("%d.\n", strangePrinter("baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa"));
    // printf("%d.\n", strangePrinter("cdadacbdb"));
    printf("%d.\n", strangePrinter("abaca"));
   // printf("%d.\n", strangePrinter("ababa"));
    // printf("%d.\n", strangePrinter("dcddbaccadbccddabbcdcdbddbaabcbbdaccacbddcdabdb"));
    // printf("%d.\n", strangePrinter("cababacababac"));
}

#include "./546_remove_boxes.h"
void test()
{
    // int m[] = {1, 3, 2, 2, 2, 3, 4, 3, 1, 2, 2};
    // int m[] = {0, 0, 0, 0, 1, 1, 1, 0, 1, 0};
    int m[] = {1,3,2,2,2,3,4,3,1};
    int l = LEN_M(m);

    printf("%d.\n", removeBoxes(m, l));
}

#include "./730_count_different_palindromic_subsequences.h"
void test()
{
    char* s = "bccb";
    // char* s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    // char* s ="bcbacbabdcbcbdcbddcaaccdcbbcdbcabbcdddadaadddbdbbbdacbabaabdddcaccccdccdbabcddbdcccabccbbcdbcdbdaada";
    printf("%d.\n", countPalindromicSubsequences(s));
}

#include "./656_coin_path.h"
void test()
{

    // int m[] = {1, 2, 4, -1, 2}; int b = 2;
    int m[] = {1, 2, 4, -1, 0, 2}; int b = 6;
    // int m[] = {1, 0, 0, 2, 4, 1, 0, 0, -1, 3}; int b = 3;
    // int m[] = {0,0,0,0,0,0}; int b = 3;

    int l = LEN_M(m);
    int rs = 0;
    int* r = cheapestJump(m, l, b, &rs);
    out(r, rs);
}

#include "./317_shortest_distance_from_all_buildings.h"
void test()
{

    // int m[] = {
    //            1, 0, 2, 0, 1,
    //            0, 0, 0, 0, 0,
    //            0, 0, 1, 0, 0,
    // }; int c = 5;

    // int m[] = {
    //            1, 0, 0, 0, 1,
    //            1, 0, 2, 0, 0,
    //            0, 0, 1, 0, 1,
    // }; int c = 5;

    int m[] = {1, 0, 0, 0, 1}; int c = 1;

    int l = LEN_M(m);
    int** r = gen_aa(m, l, c);
    printf("%d.\n", shortestDistance(r, l / c, c));
}

#include "./517_super_washing_machines.h"
void test()
{

    // int m[] = {2, 2, 2, 2}; // 0
    // int m[] = {1, 0, 5}; // 3
    // int m[] = {0, 3, 0}; // 2
    int m[] = {3, 0, 3}; // 1
    // int m[] = {1, 3, 2, 5, 1, 0}; // 3
    // int m[] = {5, 0, 1}; // 3
    // int m[] = {6, 0, 0, 0, 0, 12}; // 9

    // int m[] = {0, 3, 0}; // it's 2, not 1

    int l = LEN_M(m);
    printf("%d.\n", findMinMoves(m, l));
}
*/

#include "./568_maximum_vacation_days.h"
void test()
{

    // int f[] = {0, 1, 1, 1, 0, 1, 1, 1, 0}; int fc = 3;
    // int d[] = {1, 3, 1, 6, 0, 3, 3, 3, 3}; int dc = 3;

    // int f[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; int fc = 3;
    // int d[] = {1, 1, 1, 7, 7, 7, 7, 7, 7}; int dc = 3;

    // int f[] = {0, 1, 1, 1, 0, 1, 1, 1, 0}; int fc = 3;
    // int d[] = {7, 0, 0, 0, 7, 0, 0, 0, 7}; int dc = 3;

    /* int f[] = {0, 1, 1, 1, 0, 1, 1, 1, 0}; int fc = 3; */
    /* int d[] = {7, 0, 0, 0, 7, 0, 0, 0, 7}; int dc = 3; */

    int f[] = {0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,1,1,1,0,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,1,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,0,1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,0,1,1,0,1,0,0,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,1,0,0,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,1,1,0,1,1,0,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,1,0,1,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,0,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,0,0,1,1,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,0,0 }; int fc = 100;
    int d[] = {0,0,2,1,0,1,0,2,2,0,1,1,0,0,2,2,2,2,1,1,1,2,1,1,1,1,1,1,0,2,1,1,1,0,2,2,2,1,2,2,0,2,1,2,1,0,1,0,2,1,2,0,0,0,1,0,2,1,0,2,0,0,1,0,2,0,0,1,1,0,2,2,1,0,1,2,0,1,0,0,2,2,2,2,1,1,0,0,0,2,2,0,0,0,2,2,0,1,1,1,1,2,2,1,2,1,2,0,2,0,0,1,0,0,1,2,2,1,0,2,0,1,1,2,1,2,0,0,2,2,0,1,0,2,0,2,0,1,1,2,0,2,2,1,2,2,1,2,0,0,1,1,1,2,1,0,0,0,2,0,0,2,0,2,2,2,2,2,1,1,1,0,0,1,2,0,0,1,1,0,2,1,2,2,1,1,1,2,0,2,1,2,1,0,0,1,0,0,1,0,1,0,1,2,1,0,0,1,2,1,0,0,2,2,1,1,2,0,2,0,0,0,0,2,1,2,2,1,2,2,1,1,1,2,2,1,2,0,2,1,1,2,1,1,1,2,2,1,2,0,1,0,0,1,1,2,1,2,2,2,1,1,1,0,2,2,2,1,0,1,2,1,1,2,2,0,1,0,2,2,2,2,0,0,1,1,2,0,2,1,1,2,1,1,2,1,1,2,2,1,2,0,1,2,0,0,2,2,2,2,2,0,0,0,1,0,2,1,0,0,0,1,1,1,2,1,0,2,0,0,0,0,0,0,0,1,0,0,0,1,0,1,2,2,0,1,2,1,0,1,0,1,1,2,0,0,0,0,2,2,0,1,1,0,2,1,0,1,2,1,2,1,1,0,2,1,2,1,1,0,1,0,0,1,2,0,0,0,0,1,1,0,2,2,1,1,2,1,0,2,1,0,0,0,2,1,2,1,2,2,1,2,0,2,0,0,2,2,2,1,0,0,2,2,1,2,1,2,0,2,1,2,0,0,2,0,2,2,1,0,2,1,0,1,0,1,2,0,2,1,2,0,2,0,1,2,1,2,1,0,2,2,0,2,0,0,0,2,0,0,1,0,1,0,1,0,1,1,2,1,0,1,0,2,0,0,2,2,0,1,2,2,1,1,1,1,0,1,1,2,0,1,1,0,0,2,0,0,0,0,1,0,0,0,1,1,2,1,2,1,1,1,1,1,0,0,0,2,2,2,1,1,0,2,1,0,0,2,1,1,0,0,0,2,1,1,0,1,2,1,0,0,0,1,2,0,2,1,1,1,1,1,0,1,2,1,1,2,0,2,2,0,1,2,2,2,0,2,2,0,0,0,0,1,2,1,1,2,1,0,0,1,2,2,1,2,0,2,0,1,0,0,0,2,0,2,1,1,1,2,1,1,1,1,1,1,2,0,2,0,1,2,0,1,0,0,0,0,0,0,2,1,2,0,0,0,1,0,0,0,0,0,1,2,1,1,0,2,2,0,1,1,0,0,1,2,1,0,2,0,0,1,1,1,1,2,2,2,2,1,2,2,1,0,1,2,2,2,0,2,0,2,2,2,0,1,1,0,0,0,2,1,2,1,0,1,1,2,0,0,2,1,2,1,1,1,2,1,0,0,1,2,1,2,1,1,1,2,1,1,1,2,0,0,1,2,2,2,1,0,1,2,1,2,1,2,1,2,0,2,0,0,2,0,1,2,1,0,0,2,1,2,0,1,2,2,2,2,2,1,0,1,1,1,2,0,2,2,1,2,0,1,1,0,0,1,1,0,2,2,0,2,0,0,0,0,0,0,1,2,1,2,2,2,0,0,2,0,0,0,0,0,1,2,2,0,0,1,2,0,2,1,1,0,0,2,2,0,2,1,0,0,1,1,0,0,1,0,0,0,2,1,2,0,2,2,1,0,2,2,2,0,2,1,1,1,0,1,2,0,1,2,2,1,1,0,0,0,2,0,0,1,1,1,2,1,1,0,1,0,0,1,2,2,2,1,2,2,2,0,0,1,2,1,1,1,1,1,2,1,0,0,1,0,0,1,2,2,0,2,2,2,0,1,2,2,0,0,2,2,0,0,2,1,2,2,1,1,2,1,0,1,0,0,1,2,0,0,0,0,1,2,0,0,1,1,1,0,1,1,2,2,2,2,1,1,0,0,2,2,0,0,1,2,1,0,2,0,1,1,2,2,2,1,1,0,1,0,2,2,1,2,2,1,2,0,2,0,0,2,0,0,2,0,0,1,0,2,1,0,0,2,1,1,1,2,2,0,2,2,2,1,2,1,1,0,2,1,1,1,0,2,1,0,0,2,1,1,0,2,2,1,2,2,2,1,2,2,1,2,2,2,2,1,2,1,1,2,2,1,2,0,0,1,0,0,1,2,1,2,0,1,2,2,1,2,1,1,0,2,0,0,0,2,0,1,0,2,2,2,2,1,2,0,1,2,2,1,0,1,2,2,2,1,0,2,2,2,2,2,2,0,1,2,1,0,2,1,2,0,2,2,2,2,2,0,1,0,2,0,1,1,0,2,1,0,0,0,2,2,2,2,0,1,1,1,1,2,0,2,1,0,0,2,2,0,0,0,1,2,0,1,0,1,2,0,1,0,0,1,1,1,0,1,0,0,1,2,2,2,2,0,0,1,1,1,2,0,2,0,0,2,2,0,1,0,0,2,2,1,2,2,0,2,2,0,2,0,0,0,1,0,1,0,0,1,1,1,2,2,2,2,2,1,2,2,1,1,2,1,2,0,2,0,0,1,1,0,2,1,1,1,2,1,1,0,1,1,1,0,2,0,2,1,0,1,1,0,2,2,1,0,2,2,1,0,0,1,2,2,1,0,0,1,2,0,1,1,1,1,1,2,1,1,0,1,0,0,1,2,2,1,1,1,2,2,1,1,0,0,0,2,0,0,1,2,1,1,2,2,1,0,0,0,1,1,2,1,0,2,0,0,2,1,1,1,2,0,1,2,1,1,1,2,2,1,0,1,1,1,2,1,2,1,1,0,2,1,1,0,2,2,0,1,1,0,1,1,0,1,2,0,2,2,2,2,2,1,1,2,1,2,0,0,1,0,0,1,0,0,2,0,0,1,1,0,2,0,0,0,0,1,0,1,0,1,1,2,1,0,2,2,1,2,2,1,2,0,1,0,1,2,0,1,0,1,0,0,2,1,1,2,2,0,2,0,2,0,1,1,0,1,1,1,0,2,0,1,2,1,1,2,0,1,0,2,0,1,0,2,2,0,1,2,1,0,1,0,2,1,1,2,1,1,2,0,1,1,1,2,0,2,1,2,2,0,2,0,0,1,1,2,1,1,2,1,1,1,2,0,1,0,1,2,0,2,1,0,1,2,2,2,1,2,1,1,2,1,2,0,1,2,1,0,2,1,1,2,2,2,1,1,0,1,2,2,0,2,1,1,0,2,2,0,0,1,0,2,2,0,1,1,0,1,2,0,1,1,2,2,0,0,2,2,0,0,1,0,0,2,0,0,1,0,2,0,1,1,0,0,2,1,2,2,2,0,1,0,0,2,1,2,1,2,1,0,1,2,1,2,0,0,2,0,2,0,1,1,0,0,2,0,1,1,1,0,1,1,0,2,1,0,1,2,0,1,1,2,1,0,2,0,2,0,1,0,1,2,0,2,0,1,1,1,0,0,1,0,2,0,2,2,1,0,2,2,0,2,0,1,0,1,1,1,1,0,0,2,1,0,0,1,1,2,1,0,1,1,2,1,2,2,2,2,0,2,2,2,0,0,0,1,1,1,0,1,1,0,1,2,2,2,2,2,0,2,1,2,0,1,2,1,0,1,2,0,2,1,0,0,1,1,1,2,1,1,1,2,0,0,1,1,2,2,0,2,2,0,0,2,1,1,0,0,1,1,2,2,2,0,1,0,1,2,1,0,0,0,2,2,2,2,2,0,1,1,0,1,0,1,0,2,1,2,2,1,1,1,2,2,1,1,1,1,0,2,0,1,0,1,2,2,2,0,1,1,2,2,1,1,1,1,1,2,2,2,0,1,1,0,0,0,1,1,2,1,0,1,1,1,1,1,1,1,1,2,0,2,0,2,1,2,0,1,2,2,0,1,2,2,2,0,2,1,2,2,1,1,0,2,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,2,0,2,1,1,0,0,1,2,0,0,2,0,2,1,2,0,1,0,2,2,2,1,2,1,0,0,2,2,0,0,0,1,1,0,1,0,2,0,1,0,0,1,1,2,1,2,0,1,0,2,2,0,2,2,1,0,1,0,1,1,2,0,2,0,1,0,2,0,1,2,2,1,2,2,1,1,2,2,1,1,1,2,2,0,2,1,1,1,2,1,0,1,1,1,2,1,1,0,0,2,2,1,0,1,1,2,2,0,0,2,1,0,2,1,0,2,2,1,1,1,2,1,1,0,1,1,1,2,1,1,2,0,0,1,1,1,0,1,2,0,0,0,2,0,0,0,0,1,2,1,1,2,0,2,2,2,1,2,1,1,1,1,2,2,0,1,0,0,1,0,1,1,0,1,2,0,2,2,1,1,1,1,1,2,2,2,0,1,0,0,2,2,0,0,0,2,2,2,0,2,1,0,0,1,0,1,1,2,1,2,2,0,1,2,2,0,2,2,0,0,2,2,1,0,2,0,1,2,2,2,1,1,1,2,0,2,1,1,0,1,2,0,2,2,2,2,1,2,0,2,0,1,1,1,0,2,2,1,2,2,2,2,1,1,0,0,2,1,0,2,2,1,0,0,2,1,1,0,0,0,0,1,0,2,2,2,0,2,0,0,0,2,2,1,0,0,0,2,0,2,2,0,1,1,2,1,2,0,0,2,1,1,1,0,1,0,2,0,1,2,0,2,2,2,1,1,0,0,2,1,1,2,1,2,0,1,1,2,0,1,0,1,0,1,0,2,0,1,1,0,1,0,1,0,1,0,0,1,2,0,0,1,0,2,0,0,0,0,0,2,0,2,2,0,2,1,0,1,1,0,2,1,0,2,2,1,0,1,0,1,2,0,1,2,0,2,0,0,0,1,0,1,0,1,2,0,1,0,2,0,0,1,0,0,0,2,1,0,2,0,1,2,2,2,2,2,0,1,1,2,1,1,0,1,0,2,2,2,0,2,1,1,2,2,2,1,1,0,1,2,1,0,2,2,1,0,2,0,2,1,0,0,2,0,0,1,2,1,0,0,1,2,0,1,0,2,0,1,0,0,0,0,2,1,1,0,0,0,1,0,0,1,1,0,1,0,2,1,2,2,0,2,2,0,2,2,2,1,2,0,0,0,2,1,0,0,1,2,0,0,1,2,0,2,1,0,2,2,2,0,0,0,1,1,2,0,2,1,1,0,0,0,2,2,2,1,1,1,2,2,0,0,0,1,1,2,0,1,1,0,2,1,0,2,1,1,2,1,1,0,2,0,0,2,1,0,0,1,1,2,0,0,1,0,0,2,2,0,2,2,2,0,2,1,0,2,0,2,1,2,0,1,0,1,0,0,1,1,0,2,2,1,2,0,1,2,1,1,1,0,1,0,0,0,2,2,0,1,1,1,2,1,0,2,2,1,2,1,2,0,0,2,1,1,2,1,2,1,2,0,0,0,0,0,2,0,0,2,1,2,2,0,0,1,2,2,1,1,2,2,2,2,2,2,1,0,2,1,0,2,0,0,2,1,0,0,1,2,1,2,0,2,2,0,2,1,1,2,1,2,1,2,0,1,2,2,0,1,2,1,2,1,1,1,1,2,2,1,1,0,2,2,0,0,1,0,1,2,0,2,2,2,2,1,2,1,2,0,1,0,0,2,2,0,1,0,2,2,2,0,1,2,2,0,0,2,1,2,0,1,2,1,0,1,0,2,1,2,1,0,1,0,2,0,0,2,2,2,0,0,0,2,0,1,0,0,1,0,2,0,1,2,0,1,2,0,1,0,2,0,2,1,0,0,2,0,2,1,0,0,1,1,1,0,0,2,1,0,2,1,0,1,1,1,0,2,1,0,0,2,0,2,2,0,2,1,0,2,0,0,1,2,2,0,1,1,1,0,2,1,0,1,1,0,2,2,2,1,2,0,2,1,0,1,1,0,2,0,2,2,1,0,2,1,0,2,1,1,2,1,0,2,0,1,0,2,0,0,2,0,1,2,2,1,0,1,2,1,2,0,1,2,1,1,2,1,2,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,2,1,0,0,2,0,2,0,1,0,1,1,2,1,0,1,1,0,2,0,0,2,1,2,0,2,2,0,0,2,2,0,2,2,2,0,2,1,0,0,0,0,2,0,0,1,2,0,2,1,2,2,2,2,0,1,0,0,0,0,0,1,0,2,1,0,2,0,2,1,2,1,1,2,0,2,2,1,1,2,1,2,1,2,0,0,1,0,1,1,0,1,2,2,1,2,0,1,1,1,1,2,2,1,2,0,1,0,2,2,1,1,2,0,1,1,0,0,1,2,0,2,2,0,1,0,1,2,2,2,2,1,0,0,1,1,1,0,1,2,2,0,1,0,1,1,1,1,1,2,1,2,0,1,1,2,0,2,2,2,2,2,0,0,1,0,0,0,0,1,2,1,1,1,2,1,2,0,2,2,0,0,0,0,1,2,2,1,1,1,1,0,0,1,1,2,2,2,2,2,0,1,0,1,1,2,0,0,2,0,1,0,1,2,0,0,1,2,1,0,2,1,1,1,1,1,1,0,2,0,2,2,0,1,0,0,0,1,0,0,2,1,0,0,1,1,1,2,2,0,0,1,0,0,0,2,2,1,2,0,2,2,1,0,1,0,1,1,0,1,2,2,0,2,2,0,0,1,2,2,1,1,1,1,1,2,2,0,0,1,1,0,2,1,0,1,2,1,1,2,1,1,0,1,2,0,1,2,0,2,1,1,2,0,2,0,2,1,2,1,0,0,2,0,1,1,1,2,0,2,2,2,0,0,2,0,0,2,2,2,1,1,0,0,2,2,0,2,0,0,1,2,1,0,2,2,1,1,1,0,2,0,1,2,2,1,1,2,1,2,1,0,0,0,2,2,0,1,1,0,0,2,0,1,0,1,2,0,2,2,2,2,1,0,1,1,2,0,0,2,2,1,1,1,1,1,2,0,1,2,2,2,0,0,1,0,0,1,2,0,0,2,0,2,2,0,2,1,1,1,2,1,0,0,0,1,0,0,0,2,2,1,0,2,2,1,2,1,1,1,2,1,2,0,2,2,2,2,1,1,1,2,1,0,1,2,0,1,1,2,0,0,2,1,0,1,0,1,1,2,0,1,0,0,0,1,2,2,1,2,2,2,1,0,0,2,1,1,2,2,0,2,0,2,1,2,2,1,1,2,2,2,0,0,1,0,0,2,0,0,2,1,1,0,0,2,1,2,2,1,0,2,0,2,2,2,0,0,0,2,1,0,2,2,1,1,0,2,0,0,2,0,0,2,2,2,1,0,2,1,2,1,2,2,0,2,1,2,1,1,2,1,1,2,2,0,0,1,0,2,2,1,0,1,0,0,2,2,0,2,1,0,2,2,0,1,1,2,2,1,0,1,0,0,0,0,0,1,1,1,0,2,1,2,0,1,1,0,1,2,1,2,2,2,1,1,2,2,2,0,0,1,0,0,1,1,2,1,0,0,0,2,0,0,1,0,0,2,0,2,1,0,2,1,2,0,1,1,1,1,1,0,0,1,0,2,0,0,1,1,1,1,2,1,0,0,1,2,1,1,0,0,1,0,1,0,2,2,0,2,0,2,0,1,0,2,1,0,2,2,2,1,2,1,1,1,0,0,2,1,0,1,2,0,0,2,0,2,2,2,1,2,1,1,1,1,1,2,0,2,1,2,1,2,2,1,0,2,1,2,0,2,0,0,2,2,1,0,0,2,2,1,1,0,2,1,1,1,1,0,2,0,0,0,1,2,2,2,1,2,0,0,2,1,2,1,0,0,2,0,1,1,2,0,1,2,2,2,0,1,2,0,2,0,0,1,2,1,0,1,0,0,1,2,0,1,0,1,2,0,0,1,2,1,0,0,0,1,1,0,0,2,2,0,1,0,2,0,1,0,1,1,1,2,1,2,2,2,1,2,0,2,2,1,2,2,1,1,2,2,0,2,0,2,0,1,2,2,2,2,0,0,2,2,2,0,2,0,1,0,0,0,2,2,0,1,1,2,0,1,2,2,1,0,1,0,1,2,2,2,1,2,1,1,2,0,1,0,2,2,1,1,2,1,1,1,1,1,2,0,1,0,2,0,0,2,2,2,1,1,1,2,1,1,2,1,1,0,1,1,1,2,0,2,0,2,1,0,1,2,2,2,2,2,1,1,2,2,2,1,1,1,1,0,2,2,1,2,1,1,0,0,1,0,2,1,1,2,2,0,1,2,2,2,1,1,1,2,2,0,0,1,0,0,1,0,0,0,1,1,2,0,2,2,0,0,0,0,0,0,0,0,0,2,1,1,2,1,2,0,0,0,1,2,0,0,1,1,0,2,2,2,0,0,2,1,0,1,1,0,2,2,2,1,2,1,2,1,1,1,2,2,1,1,2,1,1,2,2,2,1,0,0,1,2,0,1,1,1,0,0,0,0,0,1,0,0,1,0,2,2,1,0,1,1,2,2,1,2,2,2,1,1,2,0,0,0,2,0,2,2,0,0,0,2,2,1,1,0,0,2,2,0,1,0,0,1,2,2,1,2,2,1,2,2,2,0,0,0,2,2,1,1,0,0,1,2,2,1,0,1,1,0,0,0,0,1,2,0,1,1,2,2,2,0,2,0,0,2,0,1,2,2,1,2,0,1,1,2,2,2,1,1,1,0,1,0,1,0,2,1,2,2,1,2,0,2,0,2,1,0,1,2,0,1,1,0,1,0,2,1,2,0,1,0,2,0,1,2,2,1,1,0,0,0,1,2,0,2,0,2,1,1,0,1,0,2,0,2,0,2,2,1,2,2,0,2,2,0,0,0,2,2,2,1,1,0,0,1,2,2,0,2,1,0,2,1,1,0,2,0,0,0,0,0,0,2,0,1,0,1,1,0,1,0,0,1,1,2,2,0,2,1,1,2,1,0,2,1,2,2,0,1,1,0,2,2,0,1,0,2,2,0,0,2,1,2,0,0,0,0,1,0,0,2,1,1,0,0,2,0,2,0,1,1,2,1,2,1,2,1,0,1,2,0,2,2,1,0,1,1,0,0,0,2,2,2,1,2,2,0,1,2,0,1,2,0,2,0,0,1,0,1,0,1,0,2,1,1,2,1,1,0,0,0,2,2,1,0,0,0,1,0,1,1,1,2,2,2,2,2,0,0,1,0,1,1,2,0,0,0,0,2,0,2,2,1,1,2,0,1,1,1,2,2,0,2,0,2,0,2,0,2,1,1,1,0,2,0,2,1,2,1,2,2,2,2,0,1,0,2,2,2,0,0,2,2,2,0,0,0,1,0,2,2,2,1,1,0,2,1,2,2,2,2,1,1,0,1,1,1,2,1,1,2,0,2,1,2,2,0,0,2,1,2,1,0,2,0,2,0,0,2,2,2,2,2,0,2,2,1,2,2,2,0,2,2,2,2,2,2,0,0,2,2,2,2,0,2,2,1,0,0,0,1,1,1,1,0,0,0,0,2,0,1,1,0,2,0,0,1,2,2,1,1,2,1,1,0,1,1,0,0,1,0,2,0,1,0,0,0,0,2,2,1,0,0,2,1,0,0,2,0,2,1,0,0,0,0,0,1,1,1,0,2,2,0,2,2,1,0,0,1,0,2,1,0,2,0,0,2,0,1,0,2,1,2,1,0,0,0,2,1,0,0,2,2,0,0,1,2,1,1,2,0,0,2,1,1,0,2,0,0,2,2,0,2,1,2,2,0,0,1,1,1,1,2,0,2,0,1,1,2,1,2,2,0,0,0,0,2,2,1,2,0,0,1,2,0,0,1,1,2,2,1,2,0,1,0,2,2,0,0,2,0,2,0,1,0,2,0,2,1,1,0,2,0,1,1,0,1,2,0,2,0,2,0,1,1,1,2,2,2,1,0,1,0,2,2,0,0,2,2,1,0,1,2,2,1,0,2,0,1,0,1,0,1,1,2,1,0,2,0,1,0,1,2,1,2,2,1,1,0,2,1,1,0,2,1,1,0,0,0,2,0,1,0,2,0,1,1,1,2,2,0,1,2,0,0,0,1,1,0,0,1,0,1,1,2,2,1,2,2,1,2,1,1,1,2,0,1,1,0,0,1,1,0,1,2,1,2,1,1,0,1,1,2,2,0,2,2,0,0,1,2,1,1,1,0,1,0,2,1,2,2,0,0,2,0,0,2,2,2,1,2,2,2,0,0,0,1,2,0,1,1,1,2,0,1,0,0,0,0,2,1,0,0,2,2,1,1,2,0,1,2,2,2,0,1,2,1,0,0,0,2,2,2,2,2,1,1,1,2,2,1,1,0,0,1,0,0,2,0,0,1,0,1,2,2,0,0,2,1,1,2,2,0,0,0,1,1,1,0,0,1,0,0,1,1,1,2,1,0,2,0,2,2,2,1,1,0,2,2,0,1,1,2,0,2,2,1,0,0,2,1,2,2,2,1,1,0,0,2,0,2,2,0,2,0,1,1,1,2,2,2,2,1,0,1,0,1,1,0,1,1,1,1,2,1,0,0,2,1,1,1,1,2,1,0,1,1,2,0,2,2,0,1,2,0,1,2,0,2,1,1,2,2,2,1,1,1,0,0,1,2,0,0,1,0,0,0,2,1,1,0,2,2,2,2,1,1,2,1,1,0,1,0,0,0,1,1,1,1,0,2,0,0,0,1,1,0,2,2,2,2,2,0,0,1,1,0,1,1,2,2,0,2,1,1,1,0,0,1,0,2,1,0,2,0,2,1,0,0,2,0,2,0,0,2,0,1,0,1,1,1,1,2,1,1,0,1,0,2,1,1,2,1,2,1,0,2,0,0,2,0,1,0,1,0,0,0,0,1,0,0,2,1,2,0,1,2,2,2,1,2,2,1,0,2,2,1,0,2,1,2,0,0,0,0,1,0,0,0,0,2,1,1,0,1,2,0,1,2,1,2,2,2,0,2,1,2,2,0,0,0,1,2,0,1,2,2,1,1,0,0,0,2,0,1,2,0,2,1,0,2,0,2,1,1,0,2,2,1,2,0,0,0,2,2,1,2,1,2,0,2,0,1,1,1,0,1,1,2,2,1,1,1,0,2,2,0,1,0,2,2,2,1,0,1,2,1,0,0,0,1,0,1,0,1,0,2,2,0,0,1,0,2,2,2,0,0,1,1,0,0,0,0,1,0,2,2,2,0,0,1,2,1,0,1,2,2,1,0,0,2,0,1,0,0,2,0,2,0,0,1,2,0,0,1,2,1,0,1,2,2,2,0,1,1,2,0,2,0,1,1,2,1,2,0,1,1,2,2,1,1,2,0,0,2,2,1,1,2,2,2,0,2,2,2,2,2,1,0,1,2,2,0,1,1,2,2,0,0,0,2,0,1,0,0,0,2,0,0,2,2,0,1,0,0,0,1,2,2,1,0,0,0,2,1,2,1,0,1,0,2,1,0,0,0,1,0,2,2,2,0,0,2,1,0,2,1,1,1,2,0,0,2,1,2,2,2,2,0,1,0,2,0,2,1,1,0,2,0,1,0,1,0,2,2,2,2,0,0,2,2,1,2,0}; int dc = 52;

    int fl = LEN_M(f);
    int dl = LEN_M(d);
    int** _f = gen_aa(f, fl, fc);
    int** _d = gen_aa(d, dl, dc);

    int* _fs = malloc(sizeof(int) * fl / fc);
    int* _ds = malloc(sizeof(int) * dl / dc);

    for (int i = 0; i < fl / fc; i ++)
        _fs[i] = fc;

    for (int i = 0; i < dl / dc; i ++)
        _ds[i] = dc;

    printf("%d.\n", maxVacationDays(_f, fl / fc, _fs, _d, dl / dc, _ds));
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
