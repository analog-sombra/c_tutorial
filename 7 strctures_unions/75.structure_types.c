// This structure is in the global scope. Hence. it is visible to all the functions

// #include <stdio.h>

// struct
// {
//     char *name;
//     int age;
//     int salary;
// } emp1, emp2;

// int manager()
// {
//     struct
//     {
//         char *name;
//         int age;
//         int salary;
//     } manager;

//     manager.age = 27;
//     if (manager.age > 30)
//     {
//         manager.salary = 65000;
//     }
//     else
//     {
//         manager.salary = 55000;
//     }
//     return manager.salary;
// }

// int main(int argc, char const *argv[])
// {
//     printf("Enter the salary of employee: \n");
//     scanf("%d", &emp1.salary);
//     printf("Enter the salary of employee: \n");
//     scanf("%d", &emp2.salary);
//     printf("The salary of manager is %d\n", manager());
//     printf("The salary of employee 1 is %d\n", emp1.salary);
//     printf("The salary of employee 2 is %d\n", emp2.salary);
//     return 0;
// }

//anotger way

//structure tag is used toidentify a paticular kind of structure

#include <stdio.h>

struct employee
{
    char *name;
    int age;
    int salary;
};

int manager()
{
    struct employee manager;

    manager.age = 27;
    if (manager.age > 30)
    {
        manager.salary = 65000;
    }
    else
    {
        manager.salary = 55000;
    }
    return manager.salary;
}

int main(int argc, char const *argv[])
{
    struct employee emp1, emp2;
    printf("Enter the salary of employee: \n");
    scanf("%d", &emp1.salary);
    printf("Enter the salary of employee: \n");
    scanf("%d", &emp2.salary);
    printf("The salary of manager is %d\n", manager());
    printf("The salary of employee 1 is %d\n", emp1.salary);
    printf("The salary of employee 2 is %d\n", emp2.salary);
    return 0;
}