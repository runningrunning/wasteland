int romanToInt(char* s)
{
    /* /\* 1, 5, 10, 50, 100, 500, 1000 *\/ */
    char* so = {"I", "V", "X", "L", "C", "D", "M"};

    /* int ns[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2, 1}; */
    /* char* so1[]    = {NULL, "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"}; */
    /* char* so10[]   = {NULL, "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"}; */
    /* char* so100[]  = {NULL, "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"}; */
    /* char* so1000[] = {NULL, "M", "MM", "MMM"}; */

    int i = 0;
    int num = 0;
    int pre = 0;
    while(s[i])
    {
        switch(s[i])
        {
        case 'I':
            num += 1;
            break;
        case 'V':
            if (pre == 'I')
                num -= 2;
            num += 5;
            break;
        case 'X':
            if (pre == 'I')
                num -= 2;
            num += 10;
            break;
        case 'L':
            if (pre == 'X')
                num -= 20;
            num += 50;
            break;
        case 'C':
            if (pre == 'X')
                num -= 20;
            num += 100;
            break;
        case 'D':
            if (pre == 'C')
                num -= 200;
            num += 500;
            break;
        case 'M':
            if (pre == 'C')
                num -= 200;
            num += 1000;
            break;
        }
        pre = s[i];
        i ++;
    }
    return num;
}
