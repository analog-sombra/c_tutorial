//increment operator is used to increment the value of a variable by one 
//decrement operator is used to decrement the value of variable by one
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // a++ is same as a = a+1
    // a-- is same as a = a-1
    //both are unary operators.
    //becaseue they are applied on single operand
    // pre_incremetn operator ++a;
    //post-increment operator a++;
    //Pre-decrement operator --a;
    //Post-decrement operator a--;
    //you cannot use rvalue before or after increment/decrement operator
    //ex (a+b)++error
    //ex ++(a+b)error


    //lvalue(left value) simply means an object that has an identifiable location in memory(i.e. haveing an address).
    //- in any assignment statement "lvalue" must have the capability to hold the data
    //-lvalue must be a variable because they have the capability to store the data.
    //- lvalue cannot be a function,expression(like a+b) or a constant (like ,3,4 etc.)

    //rvalue(right value) simply means an object that has no identifiable location in memory.
    //=anything which is capable of returing a constant expression or value.
    //-Expression like a+b like return some constant value.

    int a=1,b=1,c=1,d=1;
    printf("First increment then use %d\n",++a);
    printf("First use then increment %d\n",b++);
    printf("First decrement then use %d\n",--c);
    printf("First use then decrement %d\n",d--);
       return 0;
}
