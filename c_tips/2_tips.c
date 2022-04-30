#include <stdio.h>
int main(){
    //due to adding 0 in front of a decimel value now it's a octal value not a decimal value
    int var = 052;
    printf("%d\n", var);
    printf("%o\n", var);
    //%o is for printing octal value
    //octal value use base 8 system so 052 = 5*8^1 + 2*8^0 =5*8 +2*1 =42

//you can use macro like this
    #define STRING "%s\n"
    #define WEL "Welcome to my World"
    printf(STRING, WEL);
    return 0;
}