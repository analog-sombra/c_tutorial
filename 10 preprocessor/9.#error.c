#include <stdio.h>
int main(int argc, char const *argv[])
{
#ifdef PI
    printf("PI is defined\n");
#else
    #error PI is not defined
#endif
    return 0;
}
