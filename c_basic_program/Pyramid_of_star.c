#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter a number between 2 to 20\n");
    scanf("%d", &n);
    if (n < 2 || n > 20)
    {
        printf("Invalid number try again\n");
    }
    else
    {

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 2 * n - 1; j++)
            {
                if (j >= n - (i - 1) && j <= n + (i - 1))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
