#include <stdio.h>
//matrix multiplaction
int main(int argc, char const *argv[])
{
   //write a programe for matrix multiplaction
   int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, mat3[3][3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("\nMatrix 1:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix 2:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix 3:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }
    
   
    return 0;
}
