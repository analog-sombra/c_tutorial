#include <stdio.h>
int x = 16; //global variable

void fun();
int main(int argc, char const *argv[])
{
    int k = 12;//local variable
    //you can't define same variable name in same scope 
    // int k = 43;
    printf("%d\n",k);
    {
        int k = 43;//local variable
        printf("%d\n",k);
        printf("%d\n",x);
    }
    printf("%d\n",k);
    printf("%d\n",x);
    fun();
    
    return 0;
}

void fun(){
    int j = 53;//local variable
    printf("%d\n",j);
    printf("%d\n",x);
}
