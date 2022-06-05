#include <stdio.h>
#include <stdlib.h>

void onexit()
{
    printf("Called before termination");
}
int main()
{
    if (atexit(onexit) != 0)
    {
        printf("Failed to register onexit\n");
    }
    printf("Hello c");
    // abort do hard exit of programe
    abort();
}