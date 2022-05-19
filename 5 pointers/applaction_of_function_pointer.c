//suppose,we want to call a function named func() at a certain point in time in our code.

#include <stdio.h>

#define ops 4
float add(float a,float b);
float sub(float a,float b);
float mul(float a,float b);
float dev(float a,float b);
int main(){
    float (*ptr[ops])(float,float) = {add,sub,mul,dev};
    int choice;
    float a,b;
    printf("Enter your choice :  0 for sum, 1 for sub,2 for mul and 3 for div\n");
    scanf("%d",&choice);
    printf("Enter two numbers : ");
    scanf("%f %f",&a,&b);
    printf("%f",ptr[choice](a,b));

    return 0;
}

float add(float a, float b){
    return a+b;
}
float sub(float a, float b){
    return a-b;
}
float mul(float a, float b){
    return a*b;
}
float dev(float a,float b){
    return a/b;
}