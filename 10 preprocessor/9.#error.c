#include <stdio.h>
int main()
{
#ifdef PI
    printf("PI is defined\n");
#else
    // #error PI is not defined
    #warning PI is not defined
#endif
    return 0;
}
