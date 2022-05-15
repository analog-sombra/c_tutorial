#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,7,34,32,2,43,234,52,34,2654,34,356,4,4,3,32,564,4,4,343,34,3,434,34,34,34,3,43,34,43,43};
    //total size of array / one element size 
    int size = sizeof(a)/sizeof(a[0]);
    printf("%d",size);
    return 0;
}
