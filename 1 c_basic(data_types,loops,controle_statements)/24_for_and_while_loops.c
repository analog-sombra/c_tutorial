#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("While loop\n");
    int i = 3;
    while(i>0){
        printf("%d\n",i);
        i--;
    }
printf("For Loop\n");
    for(int i = 0;i<5;i++){
        printf("%d\n",i);
    }
    return 0;
}
