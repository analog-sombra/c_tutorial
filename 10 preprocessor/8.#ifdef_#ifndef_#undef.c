#include <stdio.h>

#define INTEL


//it's on you you want to use else or not
int main(int argc, char const *argv[])
{
    #ifdef INTEL
        printf("Code for Intel\n");
    #else
        printf("Code for AMD\n");
    #endif

    #ifdef AMD
        printf("Code for AMD\n");
    #else
        printf("Code for Intel\n");
    #endif

    #ifndef AMD
        printf("Code is not for AMD\n");
    #else
        printf("Code is for AMD\n");
    #endif

    //set undefine an define mactro

    #undef INTEL
    //now INTEL is not defined
    #ifdef INTEL
        printf("Code for Intel\n");
    #else
        printf("Code for AMD\n");
    #endif
    return 0;
}
