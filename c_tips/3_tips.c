#include <stdio.h>
static int i;
static int i = 23;
static int i;
int main(){
    //ox or 0X is for hexadecimal value you can also write f and F both are same 2

    //hexaadecimal value is base 8 value so 0x52 = 5*8^1 + 2*8^0 =5*8 +2*1 =42
    int var = 0x45ff;
    int var1 = 0x45FF;
    printf("%d\n", var);
    printf("%x\n", var);
    printf("%X\n", var);
    printf("%d\n", var1);
    printf("%x\n", var1);
    printf("%X\n", var1);

    static int i;
    printf("%d\n", i);

}