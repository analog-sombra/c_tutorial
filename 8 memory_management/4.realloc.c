//reclloc function is used to change the size of the memory block without losing the old data.

//syntex: void *realloc(void *ptr, size_t size);

//here ptr is pointer to the previously allocated memory.

//size is the new size of the memory block.

//on failure realloc returns NULL.

//int *ptr = (int*)malloc(5*sizeof(int));
// ptr = (int*)realloc(ptr,10*sizeof(int));
// This will allocate memory space of 10 ints and copy the 5 ints from the previous memory block to the new memory block.
//also this function movers the contents of the old block to a new block and the data of the old block is not lost.

//we may lose the data when the new size is smaller then the old size
//newly allocated bytes are unitialized.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    int *ptr = (int*)malloc(2*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    printf("Enter the two number\n");
    for(i=0;i<2;i++)
    {
        scanf("%d",ptr+i);
    }

    ptr = (int*)realloc(ptr,4*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    printf("Enter the two number\n");
    for(i=2;i<4;i++)
    {
        scanf("%d",ptr+i);
    }
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("%d\n",ptr[i]);
    }
    return 0;
}
