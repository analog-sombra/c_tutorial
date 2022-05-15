//Either one dimensional or multi-dimensional arrrays can be made constant be starting the declarationwith the keyword const.

//Advantage
//It assures us that the programe will not modify the array which may contain some valuable information.
//It also helps the compiler to catch errors by informing that is no intention to modify tthid array.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int a[10] = {1,2,3,4,5,6,7,8,9,10};
// a[2]=20;//This is give an error 


    return 0;
}
