#include <stdio.h>
int add(int b[],int)
int main(int argc, char const *argv[])
{
    int a[] = {3,54,65,34,23,54,6,34};
    int len = sizeof(a)/sizeof(a[0]);
    printf("%d",add(a,len));
    return 0;
}
