// string literal and character constant are not same
// "h" != 'h'
// "h" represented by a pointer
// 'h' represented by an integers

#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("\n");//no error
    // printf('\n');//error
    //printf expectes a ponter to a character not the integer
    return 0;
}
