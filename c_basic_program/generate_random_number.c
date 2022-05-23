#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int random_number(int min, int max);

int main()
{
    printf("%ld", random_number(20, 50));
    return 0;
}

long int random_number(int min, int max)
{
    int number;
    srand(time(NULL));
    if (min < max)
    {
        number = (rand() % (max - min + 1)) + min;
    }
    else
    {
        printf("Min value shoud be lower then max value");
        exit(-1);
    }

    return number;
}