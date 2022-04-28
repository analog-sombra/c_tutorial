#include <stdio.h>
//on the other hand , globa variable by default initialized to 0
int j = 34;
int k;
int main(int argc, char const *argv[])
{
    //Auto means Automatic
    //variables declared inside a scope by default are automatic variables.
    // auto int k == int k
    //If you won't initalized auto variable, by default it will be initlized with some garbage(random) value

    auto int var;//declaration and definetion
    extern int i; //only declaration
    //this is only declaratio that's why you can declaration multiple time
    //Note nultiple declaration allowed but multipla definetion not awlloed because definetion resirve space in computer ram 
    extern int i; 
    extern int i; 
    
    printf("%d \n",var);//it will be random and depend on your system
    printf("%d \n",k);
    // printf("%d \n",i); //not defination that's why error

    extern int j;
    printf("%d\n",j);

    //extern variable says to compiler go outside from my scope and you will find the definition of the variable that i declared
    //compiler believes that whatever the extern varibale said is true and produce no error. Linker throws an error when he finds no such variable exist
    //when on extern variables in initalized, then memory for this variable is allocated and it will be considere defined


    
    return 0;
}
