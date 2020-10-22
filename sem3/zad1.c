#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float a;
    float v;
    a = atof(argv[1]);
    v = a*a;
    printf("Wartość %f do kwadratu to %f.\n", a, v);

    return 0;
}