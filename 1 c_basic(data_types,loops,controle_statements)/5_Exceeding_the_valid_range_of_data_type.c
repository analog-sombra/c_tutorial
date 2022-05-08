#include <stdio.h>
int main(int argc, char const *argv[])
{
    //exceeding the unsigned range
    unsigned int var = 4294967295;
    printf("%u\n",var);

    unsigned int var1 = 4294967296;
    printf("%u\n",var1);
    // printf("\n ")
    //Exceeding the singed range

    return 0;
}
