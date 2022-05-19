//designeated initialization allows structure members to be initialized in any order;
#include <stdio.h>
struct abc{
    int a;
    int b;
    int c;
};

int main(int argc, char const *argv[])
{
    struct abc a = {.b =20,.c=10,.a=30};
    printf("%d\n",a.a);
    printf("%d\n",a.b);
    printf("%d\n",a.c);
    return 0;
}
