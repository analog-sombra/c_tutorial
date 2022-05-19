//Structure packing
//Because of stucutre padding ,size of the structure becomes more then the size of the actual structure ,bue to this some memory will get wasted.

// we can avoid the wastage of memory by simply writing #pragma pack(1)

#include <stdio.h>


// #pragma is a preprocessor directive. used to turn on or off certain features of the compiler.

#pragma pack(1)

struct abc{
 char a;
 int b;
 char c;
}var;

int main(){
    printf("%ld\n", sizeof(var));
}

