//A NULL pointer is a pointe that does not point to any memory location, it represent an invalid memory location.
//when a NULL value is assigned to a pointer, then the pointer is considered as NULL pointer.


//use of NULL pointer
//it is used to initalize a pointer when that pointer isn't assigned any valid memory address yet.

//useful for handling errors when using malloc function
//the value of NULL is 0 we acan either use NULL or 0 but this 0 is written in context of pointers and is not equivalent to the intege 0

#include <stdio.h>
int maind(){
    int *ptr = NULL;
    // printf("%d",*ptr);
    printf("%ld",sizeof(NULL));
    return 0;

    //best practice
    //it is a good practice to initialize a pointer as NULL
    //it is a good practive to perform NULLcheck before dereferencing any pointer to avoid surprises.
}