// stack is a container (or a memory segment) that is used to store variables and functions
// Data is retrieved in Last in First Out (LIFO) order
// Two operations are performed on the stack:
// 1. Push: adds a new element to the stack
// 2. Pop: removes the last element from the stack


// On calling function stack is created
// when returning from function stack is destroyed
void fun1(void);
void fun2(void);
void fun3(void);

// Stact At this point
// main()
int main(void)
{
    fun1();
}

// Stact At this point
// fun1()
// main()
void fun1()
{
    fun2();
}

// Stact At this point
// fun2()
// fun1()
// main()
void fun2()
{
    fun3();
}

// Stact At this point
// fun3()
// fun2()
// fun1()
// main()
void fun3()
{
    return;
}

// Each stack get destroyed when function encounter returns

// Activation Record is a portion of a stack which is generally composed of:
// 1. Locals of the callee
// 2. Return address to the callee
// 3. Parameter of the callee

// why scope?
// 1. To avoid name conflict
// 2. To avoid data leakage
// 3. To avoid data corruption

// What is static scoping?
// In Static scoping (or lexical scoping) defination of a variable is resolved by searching it containing blocks or function. If that fails than searching outer containing block and so on
// int a = 10, b = 20;
// int fun()
// {
//   int a = 5;
//      {
//         int c;
//          c = b/a;
//          printf("%d",c);
//      }
// }

// Here search a and b in it scope if not found than search in outer blocks and so on
// a = 5; b = 20;
// therefor c = 20/5 = 4

// What is dynamic scoping?
// In dynamic scoping, definatin of a variable is resolved by searching its containing block and if not found, then seraching its calling function and if still not found, then the function which called that function will be searched and so on
/*
#include <stdio.h>

int fun1(int);
int fun2(int);
int main()
{
    int a = 10;
    a = fun2(a);
    printf("%d",a);
}

int fun1(int b)
{
    b = b + 10;
    b = fun2(b);
    return b;
}

int fun2(int b)
{
    int c;
    c = a + b;
    return c;
}
*/

/*
    Here c is not in fun2() scope, so it will be searche where fun2() is called which is fun1() 
    it also not in fun1() so it search where fun1() is called which is main() and value of a is 10
    now b not in fun2() so search where it called is called which is fun1() and value of b is 20
    therefore c = 10 + 20 = 30
*/

// Important Takeaway
// 1. In most of the programming language, static scoping is followed instead of dynamic scoping
// 2. Language including Algol, Pascal, C, Haskell, Schema etc are statically scoped
// 3. Some languages including SNOBOL, APL, Lisp etc are dynamically scoped
