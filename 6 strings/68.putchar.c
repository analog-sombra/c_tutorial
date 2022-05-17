//putchar accepts an integer argument (which represents  a character it wants to disply) and returns an integer representing the character written on the screen. 
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int ch;
    for(ch = 'A';ch <= 'Z';ch++){
        putchar(ch);
    }
    return 0;
}
