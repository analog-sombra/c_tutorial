// as scanf and gets functions are resky to use. Hence.It is advisable to design our own input function

// we want out input funcion to have following funcionalities
// 1. it must continue to read the string even after seeing white space characters.
// 2. It must stop reading the string after seeing the new line character
// 3. It must discard extra characters
// 4. and it must return the number of characters it stroes in the character array

#include <stdio.h>

int input(char str[], int n);

int main(int argc, char const *argv[])
{
    char str[100];
    int n = input(str,5);
    printf("%d %s",n,str);
    return 0;
}
int input(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}