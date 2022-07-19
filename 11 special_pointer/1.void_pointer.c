//void pointer is a pointer which has no associated data type with it.
//it can point to any data of any data type and can be typecasted to any type

#include <stdio.h>

void sayHello(){
    printf("say Hello\n");
}

int main(int argc, char const *argv[])
{
    int a = 10;
    void *ptr = &a;




    //we can not dereference a void pointer
    // printf("%d",*ptr);//this line give we the error
    printf("%d\n",*(int*)ptr);

    //use of void pointer 
    //malloc and calloc function returns a void pointer , Due to this reason ,they can allocate a memory for any type of data
    //malloc and calloc are used to allocate memory at runtime
    int x = 0xFFFFFFFF; 
    void *p;
    int *ip = &x;
    
    p = ip;

    *ip = 0x00C0FFEE;
    // *p = 0xDEADEEEF; //no type that's why this line give a error
    *(int*)p = 0xDEADEEEF; 
    // printf("value of p pointer in hex is %x\n",*(int*)p);
    // printf("value of p pointer in hex is %x\n",*ip);
    printf("sizeof(void*) = %zu\n",sizeof(p));
    printf("sizeof(ip*) = %zu\n",sizeof(ip));

    printf("p -> %p (%x)\n",p,*(int*)p);
    printf("ip -> %p (%x)\n",ip,*ip);

    return 0;
}
