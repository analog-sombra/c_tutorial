#include <stdio.h>

void *findMid(int arr[],int len);
int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(a)/sizeof(a[0]);
    int *mid = findMid(a,len);
    printf("%d\n",*mid);
    return 0;
}

void *findMid(int arr[],int len){
   return &arr[len/2];
}

//Never ever try to return the address fo an automatic variable