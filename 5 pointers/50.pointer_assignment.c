#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 10;
    int *p,*q;
    p = &i;
    q= p;
    // note q = p is not same as *q = *p
    printf("%d\n",*p);
    printf("%d\n",*q);
    return 0;
}
