#include <stdio.h>

struct abc
{
    int a;
    int b;
    int c;
};

int main(){
    struct abc a = {1,2,3};
    struct abc *b = &a;
    printf("%d %d %d\n", b->a, b->b, b->c);
    printf("%d %d %d\n", a.a, a.b, a.c);
    return 0;
}