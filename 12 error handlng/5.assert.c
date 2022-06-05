#include <stdio.h>
#include <assert.h>


int main(){
    printf("Line 1\n");
    assert(2==2);
    printf("Line 3\n");
    //exit if condition false
    assert(2==3);
    printf("Line 4\n");
    return 0;
}