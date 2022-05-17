#include <stdio.h>
//an array name is passed as an argument to a function
int add(int b[],int);
int main(int argc, char const *argv[])
{
    int a[] = {3,54,65,34,23,54,6,34};
    int len = sizeof(a)/sizeof(a[0]);
    printf("%d",add(a,len));
    return 0;
}

int add(int b[],int len){
    int sum =0,i;
    for(i=0;i<len;i++){
        sum += b[i];
    }
    return sum;
}