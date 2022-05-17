// Assigning string literal to a pointer
// char *ptr = "Hello";
// ptr contain the address of first character of string literal
// "Hello"[1] is equivelent to 'H'[1]
// pointer to 'H'[1] = *(pointer to 'H' + 1)

// some point to be noted
// string literal cannot be modefied. it caused undefined behaviour
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *p = "Hello";
    printf("%c\n",*p);
    printf("%c\n",*(++p));
    printf("%c\n",*(++p));
    printf("%c\n",*(++p));
    printf("%c\n",*(++p));
    printf("%c","Hello"[0]);
    printf("%c","Hello"[1]);
    printf("%c","Hello"[2]);
    printf("%c","Hello"[3]);
    printf("%c","Hello"[4]);
    return 0;
}

