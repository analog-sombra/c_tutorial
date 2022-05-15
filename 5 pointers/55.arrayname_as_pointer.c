#include <stdio.h>
//name of an arary can be used as a pointer to the first element of an arary.
int main(int argc, char const *argv[])
{
    int a[] = {3,54,65,34,23,54,6,34};
    *a = 10;
    printf("%d\n",*a);
    printf("%d\n",a[0]);
    printf("%d\n",*(a+3));
    printf("%d\n",*(a-1));
    // printf("%d\n",*(a--));//this will give error


    int sum=0,*p;
    for(p = a;p<=a+7;p++){
        sum+=*p;
    }
    printf("sum is %d\n",sum);
    return 0;
}
