// Declearing a string variable 
// A string variable is a one dimensional array of character that is capable of holding a string at a time
// for example: char s[6]

// Note: Always make the array one character longer than the string. if length of the string is 5 charcter long than don't forget to make extra room for Null character

#include <stdio.h>

int main(void)
{
// initializing a string variable
    // this look like string literal but it not
    // we can change the value because it behave like array
    char s[6] = "Hello";

    // This can also do the work done
    // omitting the length
    char s2[] = "Hello";
    // Automatically the compiler set aside 6 character for s2 which enough to store the given string with null cahracter
    
}