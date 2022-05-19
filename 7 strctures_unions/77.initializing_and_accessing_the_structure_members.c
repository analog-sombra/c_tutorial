#include <stdio.h>
struct car{
    char *engine;
    char *fuel_type;
    int fuel_tank_cap;
    int seating_car;
    float city_mileage;
};

int main(int argc, char const *argv[])
{
    struct car c1 = {"engine1","fuel_type1",100,5,10.5};
    struct car c2 = {"engine2","fuel_type2",200,10,20.5};
    printf("%s\n",c1.engine);
    printf("%s\n",c2.engine);
    
    return 0;
}
