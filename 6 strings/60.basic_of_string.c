//String literal(or String Constant)  is a sequence of characters enclosed within double quotes
//%s placeholder use for string
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%s","hello world\n");
    // printf("%s",'hello world');//This is wrong always use double quite for string

    //you can write multipal line using \
    as well as comment it's prisive the spaces
    printf("%s","hello how are you\
    mr dark\
    hope you are ding good\n");
     printf("%s","hello how are you"
    "mr dark"
    "hope you are ding good");


    return 0;
}
