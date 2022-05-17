#include <stdio.h>

int main(void)
{
    // Writing string using printf function
    char *ptr = "Hello World!";
    printf("%s\n", ptr);

    // "%.ns" is used tp print just a part of string where n is the number of character is displayed on the screen
    printf("%.5s\n", ptr);

    // "%m.ns" is used to print just a part of string where n is the number of the character to be displayed and m denotes the size of the field withinn which the string will be displayed
    printf("%6.5s\n", ptr);

    // puts() function is a function declered in <stdio.h> library and is used to write strings to the output screen
    // also it automatically add a new line character after writing the string
    puts(ptr);
    puts(ptr);
    return 0;
}