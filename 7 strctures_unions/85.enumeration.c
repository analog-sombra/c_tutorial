//An enumerated type is a suer defined type which is used to assign names to integerl constants because names are easiier to handel in program
#include <stdio.h>

//if we do not assign values to enum names then, automatically compiler will assign values to them starting from Q.
enum Bool {
    False,
    True
};

int main(){
    enum Bool var;
    var = True;
    printf("%d\n", var);

    //two are more names can have some value

    enum point {x=0,y=0,z=0};
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    // we can assign values in any order. Allunassigned names will get value as value of previous name +1
    enum point1 {i =3,j};
    printf("%d\n", i);
    printf("%d\n", j);

    //only intergra values are allowed;

    // enum point2 {k = 3.5,l};//error

    //all enum constant must be unique in their scope
    
    return 0;
}

//two important reason
//Enums can be ceclared in the local scope
//Enum names are automaticlly initialized by the compiler

//two or more names can have same value.
