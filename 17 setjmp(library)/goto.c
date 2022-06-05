#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 1;
    INC:
    printf("%d\n",x);
    x++;
    if(x<=100){
        goto INC;
    }
    return 0;
}
