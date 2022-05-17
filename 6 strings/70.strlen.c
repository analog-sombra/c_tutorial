//prototype: size_t strlen(const char* str);
//size_t is an unsigned inteafer type of at least 16 bit
//strlen function is used to detemine the length of the given string.
//To the strlen() function, we should pass the pointer tothe first character of the stringwhose length we want to determine
//and as a result, it returns the length of the string
//Note it doesn't count Null character

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *str = "Hello world";
    char str1[] = "Hello world";
    char str2[100] = "Hello world";
    printf("%ld\n",strlen(str));
    printf("%ld\n",strlen(str1));
    //it calculates the length of the string and not the length of array
    printf("%ld\n",strlen(str2));
    return 0;
}
