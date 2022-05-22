//a dangling pointer is a pointer which pointer to some non existent memory location.
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *ptr = (int*)malloc(sizeof(int));
    free(ptr);
    //ptr pointer to dangling memory location
    ptr = NULL;//now it's okey
    return 0;
}
