// READING STRING USING SCANF
// Using scanf(), we can read a string into a string variable (character array)
#include <stdio.h>

int main(void)
{
    char a[10];
    printf("Enter the string:\n");
    scanf("%s", a);
    printf("%s", a);
    // Like any array name, a is treated as a pointer
    // to the first element of the array. Therefore,
    // there is no need to put &
}