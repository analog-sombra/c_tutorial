//Stands for scan Formatted String

//Accept character, string and numeric data from the user using standard input - Keyboard
//Scanf also use format spcifers like printf. for example %d  to accept integer data %c to accept character data %s to accept string data %f to accept float data %s to accept a string ans so on

#include <stdio.h>
int var;
int main(int argc, char const *argv[])
{
   
    //don't forget to add & before variable name
    //why & is used? because scanf will store the value in the memory address of variable
    //& aslo called as reference variable and address of operator
    int a,b;
    printf("Enter the first number\n");
    scanf("%d",&a);
    printf("Enter the second number\n");
    scanf("%d",&b);
    var = a+b;
    printf("%d + %d = %d\n",a,b,var);
    return 0;
}
