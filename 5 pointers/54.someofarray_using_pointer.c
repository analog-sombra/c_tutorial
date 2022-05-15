#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[] = {3,54,65,34,23,54,6,34};
    int sum=0,*p;
    for(p = &a[0];p<=&a[7];p++){
        sum+=*p;
    }
    printf("sum is %d\n",sum);

    return 0;
}
