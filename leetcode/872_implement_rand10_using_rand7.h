// There is specific solution to use randN to calculate randX !!!!!!
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10() {

    int x = rand7();
    while (x == 7)
        x = rand7();

    int y = rand7();
    while (y > 5)
        y = rand7();

    return (x & 1) * 5 + y;

    /* int m[] = { */
    /*     0, 0, 0, 0, 0, 0, 1, */
    /*     9, 0, 10, 0, 0, 0, 2, */
    /*     8, 0, 0, 0, 0, 0, 3, */
    /*     0, 0, 7, 0, 0, 0, 4, */
    /*     0, 0, 0, 0, 0, 0, 5, */
    /*     0, 0, 0, 0, 0, 0, 6, */
    /*     0, 0, 0, 0, 0, 0, 0, */
    /* }; */

    /* int x = rand7(); */
    /* int y = rand7(); */

    /* while (!m[x * y - 1]) */
    /* { */
    /*     x = rand7(); */
    /*     y = rand7(); */
    /* } */
    /* return m[x * y - 1]; */
}
