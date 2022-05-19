// When an object of some structure type is declared then some cantifuous block of memory will be allocated to structure members.

#include <stdio.h>
struct abc
{
    char a;
    char b;
    int c;
};
struct ijk
{
    char a;
    int c;
    char b;
};
struct xyz
{
    int c;
    char a;
    char b;
};
// structure padding
// processor doesn't read 1 byte at a time from memory. it reads 1 word at a time.

// if we have a 32 bit processor then it means it can access 4 bytes at a time which means word size is 4 bytes.

// if we have a 64 bit processor then it means it can access 8 bytes at a time which means word size is 8 bytes.

// we can save the number of cycles by using the concept called padding

int main(int argc, char const *argv[])
{
    struct abc var;
    printf("%ld\n", sizeof(var));
    struct  ijk var1;
    printf("%ld\n", sizeof(var1));
    struct xyz var2;
    printf("%ld\n", sizeof(var2));    
    return 0;
}
