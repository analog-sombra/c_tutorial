#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5};

  //*p is a pointer of 5 element of array
  int (*p)[5] = &a;
  //address of the array
  printf("%p\n",&a);
  printf("%p\n",p);

  //go inside the array
  printf("%d\n",*a);


//printing address of a
  printf("%p\n",&(*a));
  printf("%p\n",a);

  //first array
  printf("%d\n",**p);
  printf("%d\n",*(*p+4));


  int b[][3] = {1,2,3,4,5,6};
  int (*ptr)[3] = b;
  printf("%d %d \n",(*ptr)[1], (*ptr)[2]);
  ++ptr;
  printf("%d %d \n",(*ptr)[1], (*ptr)[2]);
  return 0;
}
