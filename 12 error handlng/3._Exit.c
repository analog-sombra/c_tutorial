// syntex: eXit(int exit_code)

#include <stdio.h>
#include <stdlib.h>

void onexit()
{
    printf("Called before termination");
}
int main(int argc, char const *argv[])
{
    if (atexit(onexit) != 0)
    {
        printf("Failed to register onexit\n");
    }
    int count = 0;
    while (1)
    {
        printf("%d\n", count);
        count++;
        if (count == 10)
        {
            //not close the signels 
            //not close the open files
            //not call the onexit function
            //it just exit program without doing anything
            _Exit(0);
        }
    }

    return 0;
}
