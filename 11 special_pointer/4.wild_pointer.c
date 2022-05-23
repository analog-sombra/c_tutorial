//wild pointer are also knows as uninitialiezed pointers.
//These pointers usually point to some arbitrary memory location and may cause a program to crash or misbehave.

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *p;//right now this is a wild pointer
    *p = 20;//no more wild pointer
    return 0;

    //always avoid wild pointers
    //initialize them with the address of a known variable.
    //Explicity allocate the memory and put the values in the allocated memory. like this
    int *ptr = (int*)malloc(sizeof(int));
}
