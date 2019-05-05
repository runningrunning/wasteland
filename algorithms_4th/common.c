#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef u_int32_t uint32_t;
typedef int bool;
#define true 1
#define false 0

void out(int *num, int size)
{
    for (int i = 0; i < size; i ++)
        printf("%3d ", num[i]);
    printf("\n");
}

// #include "./1.1.35.h"
// #include "./1.1.36.h"
// #include "./treap.h"
#include "./treap_no_parent.h"
int main(int argn, char* argv)
{
    test();
}
