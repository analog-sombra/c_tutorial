//Actual Parameters: The parameters passed to a funcion.
//Formal Parameters: The parameters received bya function.



// What is call by value
// Here values of actual parameters will be copied to formal parameters and these two different parameters store values in different locations

// What is call by reference
// Here actual parameters will be stored in the same location as formal parameters and these two different parameters will point to the same location
// Therefore any changes made to them will be reflected in the other parameter

// Here instead of passing values to the function, we are passing the address of the variable to the function.

#include <stdio.h>

void fun1(int *var1,int *var2);
void fun2(int var1,int var2);

int main(int argc, char const *argv[])
{
    int x = 10, y = 20;
    printf("Before -> x: %d, y: %d\n",x,y);
    fun2(x,y);
    printf("After Pass by value -> x: %d, y: %d\n",x,y);
    fun1(&x,&y);
    printf("After Pass by reference -> x: %d, y: %d",x,y);
    return 0;
}

// pass by value funcion
void fun1(int *var1, int *var2){
    *var1 = 100;
    *var2 = 200;
}

//pass by reference funcion
void fun2(int var1, int var2){
    var1 = 100;
    var2 = 200;
}