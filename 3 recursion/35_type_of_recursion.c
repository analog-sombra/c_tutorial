// There are four type of recursion

// 1. Direct Recursion
// 2. Indirect Recursion
// 3. Tail Recursion
// 4. Non-tail Recursion

// Direct Recursion
// A Function is called direct recursive if it call the same function again and again

// Structure of Directd recursion
/*
fun()
{
    // some COde
    fun();
    // some COde
}
*/

// Indirect Recursion
// A function (let say fun()) is called indirect recursive if it calls another function (let say fun2()) which calls fun() again

// Structure of indirect recursion
/*
fun()
{
    // some COde
    fun2();
    // some COde
}

fun2()
{
    // some COde
    fun();
    // some COde
}
*/

// Write a program to print number 1 to 10 using in such a way that when number is odd, add 1 and when number is even, subtract 1
// Expected Output: 2 1 4 3 6 5 8 7 10 9
/*
#include <stdio.h>

void odd();
void even();
int n = 1;
int main(void)
{
    odd();
    return;
}

void odd()
{
    if(n <= 10)
    {
        printf("%d",n+1);
        n++;
        even();
    }
    return;
}

void even()
{
    if(n <= 10)
    {
        printf("%d",n-1);
        n++;
        odd();
    }
    return;
}
// Output: 2 1 4 3 6 5 8 7 10 9
*/

// Tail Recursion
// A recursive function is said to be tail recursive if the recursivec call is the last thing done by the funciton. There is no need to keep record of the previous state.
/*
void fun(int n)
{
    if(n == 1)
        return;
    else
        printf("%d",n);
    return fun(n-1);
}

int main()
{
   fun(3);
    return 0;
}
*/

// Non-tail recursive
// A recursive function is said to be non-tail recursive if the recursive call is not the last thing done by the function. After returning back, there is something left to evaluate
/*
void fun(int n)
{
    if(n==0)
        return;
    fun(n-1);
    printf("%d",n);
}

int main()
{
    fun(3);
    return 0;
}
*/