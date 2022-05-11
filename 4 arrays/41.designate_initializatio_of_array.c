// int array[10] = {1, 0, 0, 0, 2, 3, 0, 0, 0, 0};
// is equivalent to:
// int array[10] = {[0] = 1, [5] = 2, [6] = 3};

// This way of initialization is called designated initialization.
// and each number in square bracket is said to be designator.


// int array[10] = {1, 7, 5 ,0, 0, 90, 6, 0, 4};
// is equivalent to:
// int array[10] = {1, 7, 5, [5] = 90, 6, [8] = 4};

#include <stdio.h>

int main(void)
{
    int array[10] = {[0] = 1, [5] = 2, [6] = 3};
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    int array2[10] = {1, 7, 5, [5] = 90, 6, [8] = 4};
        for(int i = 0; i < 10; i++)
    {
        printf("%d ", array2[i]);
    }
}