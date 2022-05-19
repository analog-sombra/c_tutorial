//function pointer are like normal pointer but they have the capability to point to a function.
//int *ptr[10]; this is wrong
//always rememver the precedence of operators. precedence of [] is higher then *
//so here prt is a array of pointers

// int (*ptr)[10]; in this line we cahnge the precedence of ptr and force them to point the 10 intgers

// int (*ptr)(int,int);
//to a function containing two integer arguments and it returns an integer
//asssiging the address of a function to a function pointer.

// int (*ptr)(int,int) = &add;
//or
//int (*ptr)(int,int);
//ptr = &add;


#include <stdio.h>
int add(int a,int b);
int main(int argc, char const *argv[])
{
    int result;
    int (*ptr)(int,int);
    ptr = &add;
    //or you write in a single line
    // int (*ptr)(int,int) = &add;
    //or
    //int (*ptr)(int,int) =add;
    //because the function
    result = (*ptr)(10,20);
    printf("%d\n",result);
    return 0;
}

int add(int a,int b)
{
    return a+b;
}
