//i want to store all the information about the cars which are avaiable in my garage.
//a strcture is  a user defined data type that can be used to group elements of different types into a single type.

//declaring structure variables

#include <stdio.h>

 struct car{
        char *engine;
        char *fuel_type;
        int fuel_tank_cap;
        int seating_car;
        float city_mileage;
    }car1,car2;
int main(int argc, char const *argv[])
{
   car1.engine = "engine1";
   car2.engine = "engine2";

   printf("%s\n",car1.engine);
    printf("%s\n",car2.engine);
    return 0;
}
