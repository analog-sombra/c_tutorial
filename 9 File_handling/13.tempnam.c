//create tempram file name
//syntex of tmpnam function

//char *tmpnam(char *s);
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[L_tmpnam+1];
    tmpnam(name);
    puts(name);

    return 0;
}
