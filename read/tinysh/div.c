#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float a, b;
    a = atoi(argv[1]);
    scanf("%f", &b);
    printf("%f\n", b / a);
}

