#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,23,43,23};
    int *ptr;
    ptr = &a[0];
    printf("%d\n",*ptr);

    printf("\n\nAddition\n\n\n");
    //additon 
    ptr = ptr+7;
    printf("%d\n",*ptr);

   printf("\n\nsubtration\n\n\n");
    //subtrationc
    ptr = ptr - 4;
    printf("%d\n",*ptr);


   printf("\n\nIncrement\n\n\n");
    //increment
    ptr++;
    printf("%d\n",*ptr);
    printf("%d\n",*(ptr++));
    printf("%d\n",*(++ptr));



    printf("\n\ndecrement\n\n\n");
    // decrement
    ptr--;
    printf("%d\n",*(ptr--));
    printf("%d\n",*(--ptr));

    //pointer comparing
    //use relational operators(<,>,<=,>=) and equality operators(==,!=) to compare pointers.
    //only possible when both  pointers point to same array.
    // output depends upon the relative position of both the pointers.
    printf("\n\nPointer comparing\n\n\n");  
    int *p = &a[4];
    int *q = &a[5];
    printf("%d\n",*p);  
    printf("%d\n",*q);  
    printf("%d\n",p==q);
    printf("%d\n",p!=q);
    printf("%d\n",p<q);
    printf("%d\n",p>q);
    printf("%d\n",p<=q);
    printf("%d\n",p>=q);
    
    



    return 0;
}
