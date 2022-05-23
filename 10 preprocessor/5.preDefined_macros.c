#include <stdio.h>

int main(int argc, char const *argv[])
{
    //return the file name
    printf("%s\n",__FILE__);

    //return the current time
    printf("%s\n",__DATE__);

    //return the current time
    printf("%s\n",__TIME__);
    
    //return the current line number
    printf("%d\n",__LINE__);

    //return the current timestamp
    printf("%s\n",__TIMESTAMP__);

    //return the current function name
    printf("%s\n",__func__);

    //is your compiler is c99 or c11
    printf("%d\n",__STDC__);
    //if 1 then it is c99
    //if 0 then it is c11

    #line 1000 "newFile.c"
    //change the current line number
    printf("%d\n",__LINE__);
    printf("%d\n",__LINE__);
    printf("%s\n",__FILE__);
    return 0;
}
