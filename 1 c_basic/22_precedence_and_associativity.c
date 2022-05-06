//Precedence of operators caome into picture when in on expression we need to decide which operator will be evaluated first. Operator with higher precedence will be evaluated first;
//associativity of operators come into picture when precedence of operators are some and we need to decide which operator will be evaluated first;


//int var - fun();
//= operator is having less precedence as compred to () therfore, () belongs to fun and fun will be treated as a funnction.

//int var = (fun());

//associativity can only help if there are two or more operators of some precedence and not when there is just one operator.
//operators with same precedence have same associativity as well;

#include <stdio.h>
int main(){
int a =10,b=20,c=30,d=40;
if(a <= b == d > c){
    printf("TRUE");
}else{
    printf("FALSE");
}
return 0;
}
