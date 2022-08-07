#include <stdio.h>
#include <setjmp.h>

// setjump(jmp_buf buf) : uses buf to store current position and returns 0.
// longjump(jmp_buf buf, i) : Go back to place pointed by buf and return i.


jmp_buf buf;
int main(int argc, char const *argv[])
{
    int x = 1;
    setjmp(buf);
    printf("%d\n",x);
    x++;
    if(x<=100){
        longjmp(buf,1);
    }
    return 0;
}
