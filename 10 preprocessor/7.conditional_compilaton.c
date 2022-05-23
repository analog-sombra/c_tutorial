#define INDIA 1
#define USA 2
#define CANADA 3

#include <stdio.h>

#define COUNTRY INDIA

int main(int argc, char const *argv[])
{
    #if COUNTRY == INDIA
        printf("India\n");
    #elif COUNTRY == USA
        printf("USA\n");
    #elif COUNTRY == CANADA
        printf("Canada\n");
    #else
        printf("Unknown\n");
    #endif
}