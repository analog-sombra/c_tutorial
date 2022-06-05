//syntex: int atexit(void (*func)(void))

#include <stdio.h>
#include <stdlib.h>


void onexit(){
    printf("Called before termination");
}

int main(){
    if(atexit(onexit) != 0){
        printf("Failed to register onexit\n");
    }else{
        printf("Register completed\n");
    }
    return 0;
}