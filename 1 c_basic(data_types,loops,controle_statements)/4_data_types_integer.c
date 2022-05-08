//Size of Integer
// 2 bytes = 16 bits
// 4 bytes = 32 bits
//more size more content it can hold

#include <stdio.h>

int main(int argc, char const *argv[])
{

    //size of uniry opreter not a funciton
    printf("%ld bytes\n",sizeof(int));

    //Range upper and lower limit of some set of data
    //[0,1,2,3,4,5] = Range 0 to 4 


    //Prerequisites
    // ## Decimal number system: Human understandable number system also called as bvase 10 nubmer system
    // range 0 to 9 
    // 10^2 10^1 10^0
    // 5     6    8
    //500 + 60 +  8 = 568
    // ## Binary number system : machine understanble number system. also called as base 2 number system
    //Range  0 to 1
    // 2^3 2^2 2^1 2^0
    // 1   1   0   0
    // 8   4   0   0 = 12
    // Range of 4 bit data
    // 4 bit data: min value = 0(0000), max value = 15(1111)
    // calculate max range of bit formula: 2^n-1

    //range
    //unsigned range: 0 TO 65535 (BY APPLYING : 2^N-1)
    //Sined range: -32768 to +32767 

    //represention for nagative numbers
    //Signed Magnitude
    //1's complement
    //2's complemnet

    //formula for complement range: -(2^n-1) to +(2^n-1-1)





    // ##  Modifiers (short, long ,signed, unsigned) used for integer.
    

    //long and short
    //long integer is 4 bytes short int may be 2 bytes
    //shor integer is 4 bytes long int may be 8 bytes
    int x;
    short y; //same as short int
    long z; //same as long int  


    printf("%ld normal\n",sizeof(x));
    printf("%ld short\n",sizeof(y));
    printf("%ld long\n",sizeof(z));

    //sizeof(short) <= sizeof(int) <= sizeof(long)

    //note by default variable_name is signed integer variable

    //unsigned variable name; allows only positve values.

    //writing signed int varibale name is equivalent ot writing int variable_name
    

    //%d is used to print "signed integer"
    //%u is used to rpitn "unsigned integer"
    //%ld used to print "long interger" equivalent to "signed long integer"
    //%lu is used to print "unsigned long integer"
    //%lld is used to print "long long integer"
    //%llu is used to print "unsigned long long integer"

    

    return 0;
}
