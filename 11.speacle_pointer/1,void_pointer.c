//void pointer is a pointer which has no associated dta type with it.
//it can point to any data of any data type and can be typecasted to any type

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    void *ptr = &a;

    //we can not dereference a void pointer
    // printf("%d",*ptr);//this line give we the error
    printf("%d",*(int*)ptr);

    //use of void pointer 
    //malloc and calloc function returns a void pointer , Due to this reason ,they can allocate a memory for any type of data
    //malloc and calloc are used to allocate memory at runtime
    return 0;
}
