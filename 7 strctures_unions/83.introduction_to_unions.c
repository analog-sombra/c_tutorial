// Union is a user defined data type but unlike structures, union memvers share some memory location

struct abc{
    char a;
    int b;
    char c;
};

//structures use diffrect memory location for each member
//union uses same memory location for all members

union xyz{
    char a;
    int b;
    char c;
}var;
//in union memvbers wil share same memory locatio if we make changes in one member then it will be reflected to ohter member as well
#include <stdio.h>
//size of union

// size of the union is taken according to the size of the largest member of the union.

int main(int argc, char const *argv[])
{
    
    var.a = 65;
    printf("%d\n", var.a);
    printf("%c\n", var.b);

    union xyz *ptr = &var;
    printf("%d\n", ptr->a);
    printf("%c\n", ptr->b);

    printf("%ld", sizeof(var));

    return 0;
}
