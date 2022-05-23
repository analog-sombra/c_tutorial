//only search in the compiler directory
#include <stdio.h>

//first search in the current directory then search in the compiler directory
#include "myheader.h"

int main(int argc, char const *argv[])
{
    printf("%d\n",add(10,20));
    printf("%f\n",PI);
    return 0;
}

