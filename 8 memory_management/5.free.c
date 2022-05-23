// free function is used to release the dynamiclly allocated memory in heap.

// syntex: void free(void *ptr);

// the memory allocated in heap will not be released automatically after using the memory. The space remains there and can't be used

// it is the programmer's responsibility to release the memory.

#include <stdio.h>
#include <stdlib.h>
int *input();
int main(int argc, char const *argv[])
{
   int i,sum=0;
    int *ptr = input();
    for(i=0;i<5;i++)
    {
        sum = sum + ptr[i];
    }
    printf("%d\n",sum);
    free(ptr);
    ptr = NULL;
    return 0;

}

int *input()
{
    int *ptr, i;
    ptr = (int *)malloc(5 * sizeof(int));
    printf("Enter the five number\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", ptr + i);
    }
    return ptr;
}
