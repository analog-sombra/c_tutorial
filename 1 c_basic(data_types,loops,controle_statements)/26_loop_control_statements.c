//break used to terminate form the loop
#include <stdio.h>
int main()
{
    // int n;
    // printf("Ente a number\n");
    // scanf("%d", &n);
    // while (n != 0)
    // {//stop loop when user inter a nagative number
    //     if (n < 0)
    //     {
    //         break;
    //     }
    //     printf("Ente a number\n");
    //     scanf("%d", &n);
    // }

    //similar to break but instead of terminating from the loop , it forces to  execute the next iteration fo the loop;
    int j,k =2;
    for(j=1;j<=20;j++){
        if(j == k){
            k = k+2;
            continue;
        }
        printf("%d ",j);
    }
    return 0;
}