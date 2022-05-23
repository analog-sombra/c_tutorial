//calloc() fuction is used to dynamically allocate multiple blocks of memory.

//it is different from malloc in two ways;
//1. calloc() need two arguments instead of one.

//syntex: void *calloc(size_t nmemb, size_t size);
//nmemb is the number of blocks of memory to be allocated.
//size is the size of each block of memory.

//ex
// int *ptr = (int*)calloc(5,sizeof(int));

//an equivalent mallco() call is
// int *ptr = (int*)malloc(5*sizeof(int));

//memory allocated by callloc is initalized to zero
//it is not the case with malloc memory allocated by malloc is initialized with some garbage value

// note
// malloc and calloc both return NULL when sufficient memory is not avalibale int he heap.

//calloc stands for clear allocation
//malloc stands for memory allocation


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i,n;
    printf("Enter the number of integers:\n");
    scanf("%d",&n);
    int *ptr = (int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element:\n",i+1);
        scanf("%d",&ptr[i]);
        //you can also use 
        // scanf("%d",ptr + i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",ptr[i]);
        //you can also use
        // printf("%d\n",*(ptr + i));
    }
    return 0;
}
