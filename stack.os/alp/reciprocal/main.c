#include "reciprocal.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int i = atoi(argv[1]);
    printf("The reciprocal of %d is %.2f.\n", i, Reciprocal(i));
    return 0;
}
