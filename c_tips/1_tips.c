#include<stdio.h>
int main(int argc, char const *argv[])
{
    //printf fucntion return the lenth of charactor
    int len = printf("Hello kk\n");
    printf("%d\n",len);

    //create space and place string inside this
    printf("%s","Hello\n");
    printf("%10s","Hello\n");
    
    //if is length greater then number then it will be ignore
    printf("%5s","Hello darksider\n");

    //char number store in 256 if it's cross then it will be start from begning
    char c = 255;
    c = c +10;
    printf("%d\n",c);


    //signed int i  == signed i
    //unsigned i == int 1 == unsigned int i
    //long i == long int i
    //long long i == long long int i



    unsigned i = 1;
    int j = -5;
    printf("%u\n",i+j);
    printf("%d\n",i+j);
    return 0;

    
}
