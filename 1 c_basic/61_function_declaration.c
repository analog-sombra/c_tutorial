// What is function declaration?
// As we know, a function is a block of code which is used to perform a specific task.
// Function declaration is a statement which tells the compiler about the existence of a function.

// for example
// int areaOfRect(int length, int breadth);
// 1. Name of function:     areaOfRect
// 2. Return type:          int
// 3. Number of parameters: 2
// 4. Type of parameter 1:  int
// 5. Type of parameter 2:  int

// it is not necessary to put the name of the parameter in function prototype

#include <stdio.h>

char fun();
int main()
{
    char c = fun();
    printf("character is: %c", c);
    return 0;
}

char fun()
{
    return 'a';
}