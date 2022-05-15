#include <stdio.h>
void minmax(int arr[],int len, int *min,int *max);
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int min,max;
    minmax(arr,len,&min,&max);
    printf("%d\n",min);
    printf("%d\n",max);
    
    
    return 0;
}

void minmax(int arr[],int len, int *min,int *max){
    int i;
    *min = *max = arr[0];
    for(i=1;i<len;i++){
        if(arr[i]<*min){
            *min = arr[i];
        }
        if(arr[i]>*max){
            *max = arr[i];
        }
    }
}
