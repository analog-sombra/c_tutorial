#include <stdio.h>
int main(int argc, char const *argv[])
{

    // if
    if (4 == 4)
    {
        printf("TRUE");
    }

    // if else
    if (4 == 5)
    {
        printf("FALSE");
    }

    else
    {
        printf("FALSE");
    }

    // nested if else
    if (4 == 5)
    {
        if (4 == 5)
        {
            printf("FALSE");
        }
        else
        {
            printf("TRUE");
        }
    }
    else
    {
        printf("FALSE");
    }

    // if you have only one statement then you can ignore curely bresses

    if (4 == 4)
        printf("TURE");
    else
        printf("FALSE");


        //switch case
        int a = 10;
        switch (a)
        {
        case 10:
            printf("10");
            break;
        case 20:
            printf("20");
            break;
        case 30:
            printf("30");
            break;
        default: // if no match found
            printf("default"); // will be executed if no match found
            break; // this is optional
        }
        //you are not allowed to add duplicate case
        //only those expression are allowed in swithc which results in an integral constant value
        //float value is not allowed as a constant value in case label. only integer constants/constant expression are allowed in case label.
        //variable expressions are not allowed in case labels. although macros are allowed
        //Default can be placed anywhere inside switch. it will still get evaluated if no match is found.

    return 0;
}
