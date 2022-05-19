#include <stdio.h>
// insted of declaring multipla variables, we can also declare an array of structure in which each element of the array will represent a structure variable.

struct car
{
    int fule_tank_cap;
    int seating_car;
    float city_mileage;
};

int main(int argc, char const *argv[])
{
    struct car c[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the car %d fule tank capacity\n", i + 1);
        scanf("%d", &c[i].fule_tank_cap);
        printf("Enter the car %d seating car\n", i + 1);
        scanf("%d", &c[i].seating_car);
        printf("Enter the car %d city mileage\n", i + 1);
        scanf("%f", &c[i].city_mileage);
    }
    printf("\n");
    for(int i = 0; i < 2; i++)
    {
        printf("Car %d fule tank capacity is %d\n", i + 1, c[i].fule_tank_cap);
        printf("Car %d seating car is %d\n", i + 1, c[i].seating_car);
        printf("Car %d city mileage is %f\n", i + 1, c[i].city_mileage);
    }


    return 0;
}
