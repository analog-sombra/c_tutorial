//malloc is a built-in function declared in the header file <stdlib.h>
//malloc is the short name for "memory allocation " and is used to deynamically allocate a single large block of contiguous memory according to the size specified.

//syntex: (void* )malloc(size-t size)

//malloc function simply allocates a memory block according to the size specified. is the heap and on success it return a pointe pointing to the first byte of the allocated memory else retuns NULL.

//size_t is defined in <stdlib.h> as unsigned int.

//why void pointer
//malloc doesn't have an idea of what it is pointng to 
//it merely allocates memory requested by the user without knowing the type of data to be stored inside the memory.
//the void pointer can be typecasted to an appropriate type

//int *ptr = (int*)malloc(sizeof(4));
//malloc allocateds 5 bytes of memory in the heap and the address fo the first byte is stored in the pointer ptr

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i,n;
    printf("Enter the number of integers:\n");
    scanf("%d",&n);
    int *ptr = (int*)malloc(n*sizeof(int));
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
