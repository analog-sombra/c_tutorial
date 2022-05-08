#include <stdio.h>

int main(int argc, char const *argv[])
{
    //do while run at least one 
    int i = 0;
    do{
        printf("%d\n",i);
        i++;
    }while(i<5);

    printf("Enter 0 to exit\n");
    int j;
    do{
        printf("Enter an integer\n");
        scanf("%d",&j);
    }while (j != 0);
    printf("You are out of the loop");
    
    return 0;
}
