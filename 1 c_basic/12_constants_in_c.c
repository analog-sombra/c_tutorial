//const As the name suggest - someting that never changes.
//once defined cannot be modified later in the code.
//defining constants
//1. define a constant using #define
//2. define a constant using const keyword
//3. define a constant using typedef
//4. define a constant using enum
//5. define a constant using struct
//6. define a constant using union


#include <stdio.h>


int main(int argc, char const *argv[])
{
    //1. define a constant using #define

    // #define PI 3.14
    //here Pi is macro and 3.14 is value
    //job of preprocessor <not compiler> to replace macro with value
    //please don't add semicolon at the end
    //aways use uppsercase letter for for defining macro
    //whatever inside double quotes is a macro and whatever outside is a value 
    #define PI 3.14
    printf("%f\n",PI);

    //we can use macro like function

    #define MAX(a,b) ((a)>(b)?(a):(b))
    printf("%d\n", MAX(10,20));

    //some predefined macros like __DATE__ __TIME__ __FILE__ __LINE__ __STDC__ __cplusplus 
    //__func__ __STDC_VERSION__ __STDC_HOSTED__ __STDC_IEC_559__ __STDC_IEC_559_COMPLEX__
    //__STDC_ISO_10646__ 

    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%d\n", __STDC__);







    //2. define a constant using const keyword
    const int MAX_SIZE = 100;

    //MAX_SIZE is a read only variable
    printf("%d\n",MAX_SIZE);

    //3. define a constant using typedef
    typedef int my_int;
    my_int my_var = 10;
    printf("%d\n",my_var);

    //4. define a constant using enum
    enum my_enum {
        ONE,
        TWO,
        THREE
    };
    printf("%d\n",ONE);

    //5. define a constant using struct
    struct my_struct {
        int a;
        int b;
    };
    struct my_struct my_struct_var = {1,2};
    printf("%d\n",my_struct_var.a);

    //6. define a constant using union
    union my_union {
        int a;
        int b;
    };
    union my_union my_union_var = {1,2};
    printf("%d\n",my_union_var.a);

    return 0;
}