// stringizing denoted using # 
// pasting denoted using ##

#include <stdio.h>
//convert argument to string
#define NAME(x) #x

#define CONCAT(x,y) x ## y

int main(int argc, char const *argv[])
{   
    int xy = 25;

    printf("%s\n",NAME(Hello World));
    printf("%d\n",CONCAT(x,y));

    //it will become something like this
    printf("%d\n",xy);
    return 0;
}
