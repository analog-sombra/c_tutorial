#include <stdio.h>
int main(){
    //arithmetic operators

    //+ addition operators
    //- subtraction operators
    //* multiplication operators
    /// division operators
    //% modulus operator
    //all are binary operators -> means twwo operands are required to perform the operation

    int a=10,b=5;
    printf("addition operator is %d\n",a+b);
    printf("subtraction operator is %d\n",a-b);
    printf("multiplication operator is %d\n",a*b);
    printf("division operator is %d\n",a/b);
    printf("modulus operator is %d\n",a%b);

    //operator precedence and associativity
    //precedence operator  associativity
    //highest (*,/,%) left to right
    //lowest (+,-) left to right

    int i =2 ,k = 3,j=5,l=5;
    printf("%d\n",i+k*j/l);
    printf("%d\n",(i+k)*(j/l));
    printf("%d\n",i+k*(j/l));
    printf("%d\n",(i+k)*j/l);
    printf("%d\n",i+k*(j/l));
    printf("%d\n",i+k*j/l);


    
   
    return 0;
}