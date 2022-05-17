// raw magor order: Element are stored row by row
// column magor order Elements are stored column by column

// c stores the elements in a row major order
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("\n\n2D Array\n\n");
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // a[0][0]
    printf("%d\n", **a);
    // a[1][0]
    printf("%d\n", **(a + 1));
    // a[0][1]
    printf("%d\n", *((*a) + 1));
    // a[2][2]
    printf("%d\n", *((*(a + 2)) + 2));

    int b[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        },
        {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19},
        },
        {
            {21, 22, 23},
            {24, 25, 26},
            {27, 28, 29},
        },
    };
    printf("\n\n3D Array\n\n");
    // b[0][0][0]
    printf("%d\n",***b);
    // b[1][0][0]
    printf("%d\n",***(b+1));
     // b[1][1][1]
    printf("%d\n",*(*(*(b+1)+1)+1));
    // b[2][1][1]
    printf("%d\n",*(*(*(b+2)+1)+1));    
    // b[3][3][3]
    printf("%d\n",*(*(*(b+2)+2)+2));




    return 0;
}
