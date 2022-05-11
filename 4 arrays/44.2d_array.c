// The basic form of declaring two dimensional array is:
// data_type array_name[row_size][column_size];
// where row_size and column_size are the number of rows and columns respectively.

// for example
// int array[3][3];
// -------------------
// |  0  |  1  |  2  |
// -------------------
// |  3  |  4  |  5  |
// -------------------
// |  6  |  7  |  8  |
// -------------------

#include <stdio.h>

int main(void)
{
    int array[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

}