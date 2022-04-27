#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Brief overview of character data type.
    //size of characters.
    //range of characters
    //defference between signed and unsigned characters
    char var = 'c';
    printf("%c\n",var);
    char var1 = 99;
    printf("%c\n",var1);

    //char 
    //size 1 byte = 8 bit
    //Range Unsigned 0 to 255
    //range signed -128 to +127
    printf("%d\n",sizeof(char));

    return 0;
}
