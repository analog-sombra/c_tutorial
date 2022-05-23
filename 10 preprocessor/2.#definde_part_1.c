#include <stdio.h>
#define LIMIT 5
#define PI 3.14
//here PI is name and 3.14 value
//define just replace the name with value in your whole programe

int main(int argc, char const *argv[])
{
    int count;
    for(count = 1;count<=LIMIT;count++){
        printf("%d\n",count);
    }
    //ignore if it insoide ""
    printf("PI = %f",PI);
    return 0;
}

//use "cpp 2.#defined.c > output.c" for get pre processor output