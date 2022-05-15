#include <stdio.h>
int add(int b[],int len);
int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(a)/sizeof(a[0]);
    printf("%d",add(a,len));
    return 0;
}
int add(int b[],int len){
    int sum = 0,i;
    for(i=0;i<len;i++){
        sum+=b[i];
    }
    return sum;
}