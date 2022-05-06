//comma operator can be used as a "separator"
//comma operator can be used as an "operator"

//comma operator returns the rightmost operand in the expression and it simply evaluates the rest of the operand and finally reject them.
//comma operator is habing least precedence among all the operators availablle in c language.

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a=10,b=20,c=30,d,e,f;
    printf("a = %d, b = %d, c = %d",a,b,c);
    d = (1,2,3,4);
    printf("\nd = %d",d);


    //it's not directly reject first it's eveluate then reject
    e = (printf("\n%s","Hello"),10);

    printf("\ne = %d",e);


    f = 3,4,5;//same as (f = 3),4,5
    printf("\nf = %d",f);

    // int x = 4,5,6; //same as int x = 4,int 5 , int 6//so this is an error


    int var;
    int num;
    num = (var = 10,var+1);
    printf("\nnum = %d",num);
     

    return 0;
}
