// what is function defination?
// function defination is a block of code which is used to define a function.

#include <stdio.h>

int add(int, int);

int main()
{
    int m = 20, n = 30, sum;
    sum = add(m, n);
    printf("sum is: %d", sum);
}

int add(int a, int b)
{
    return a + b;
}

// Difference between argument and parameter
// parameter is a variable in the declaration and defination of the function
// argument is the actual value passed to the function

// Note: Parameter is also called as formal parameter and argument is also called as actual parameter.  The formal parameter is the variable that is used to store the value of the actual parameter.
// Note: The actual parameter is the value that is passed to the function.
