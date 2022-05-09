// In c Function are global by default
// This means if we want to access the funtion outside from the file where it is decleared, we can access it easily
// Now if we want to restrict this access, than we make our function static by putting a keyword "static" in front of the function

#include <stdio.h>

void fun1(void);
static void fun2(void);

void main()
{
    fun1();
    fun2();    
}

// This is global function
// We can use this functin outside this c file
void fun1(void)
{
    printf("Hello World from global function\n");
}

// This is static function
// We can't use this function outside this c file
static void fun2(void)
{
    printf("Hello World from static function\n");
}