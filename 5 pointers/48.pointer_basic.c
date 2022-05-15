//Pinter is a special variable that is capable of storing some address.
//Ti points to a memory location where the first byte is stored

// int *ptr points to intege value
// char *ptr points to character value
// float *ptr points to float value

//Address operator
//Simply declaring a pointer is not enough.
//It is important to initialize pointer before use.
//One way to initialize a pointer is to assign address of some variable.

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x =5;
    int *ptr;
    ptr = &x;
    //you can also write in one line like this
    int y = 12, *ptr2 = &y;
    printf("%d\n",*ptr);
    printf("%d\n",*ptr2);
    return 0;
}
