#include <stdio.h>

int incr_without_static();
int incr_with_static();

int main(int argc, char const *argv[])
{
    int value;
    value = incr_without_static();
    value = incr_without_static();
    value = incr_without_static();

    printf("%d\n",value);


    int value1;
    value1 = incr_with_static();
    value1 = incr_with_static();
    value1 = incr_with_static();

    printf("%d\n",value1);
    return 0;
}
int incr_without_static()
{
    int count = 0;
    count = count + 1;
    return count;
}

int incr_with_static()
{
    static int count = 0;
    count = count + 1;
    return count;

    //remember always static variable assign with constent not with variable
    // int var = 3;
    // static int data = var;
    //This will give error
}


//Static variable remains in memory even if it is declared within a block on th eother hand automatic variable is destroyed after the completion of function in which it was declared.
//Static variable if declared outside the scope of any functio will act like globa variable but only within the file in which itis declared.
// you can only assign a constant literal <or value> to a stic variable. 
