// syntex: typedef existing_data_type
// typedef gives freedom to the user by allowing them to create their own types.

#include <stdio.h>

typedef struct car//struct car is old type
{
    char *engine;
    char *fuel_type;
    int fuel_tank_cap;
    int seating_car;
    float city_mileage;
}car;//car is new type

int main(){
    car c1;
    c1.engine = "engine1";
    printf("%s\n",c1.engine);
    return 0;
}