#include <stdio.h>


#define ONE 1
#define AND &&
#define OR ||
#define SHOW printf("Hello world");
#define TWO ONE+1
#define MSG "Hello world\
good \nmorning\
    whar are you doing"

//passing one argument in macro
#define SQUARE(a) ((a)*(a))

//passing multiple arguments in macro
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(int argc, char const *argv[])
{
    if(ONE AND ONE){
        SHOW
    }
    printf("%d\n",TWO);
    printf("%s\n",MSG);
    printf("%d\n",MAX(ONE,TWO));
    printf("%d\n",MIN(ONE,TWO));
    printf("%d\n",SQUARE(TWO));
    return 0;

    //when to use macro or function
    //when you need speed you can use macro
    //when you need your file size to be small you can use function
}
