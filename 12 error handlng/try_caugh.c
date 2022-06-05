#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf savebuf;

int exception_value = 0;
#define TRY if ((exception_value = setjmp(savebuf)) == 0)
#define CAUGHERROR else
#define CAUGH(NUM) else if (exception_value == NUM)
#define THROW(NUM) longjmp(savebuf, NUM)

double compute_avg(double *values, size_t length);

int main()
{
    int a;
    printf("Enter the number of Element: ");
    scanf("%d", &a);
    double *arr = (double *)calloc(sizeof(double), a);
    double input;
    for (int i = 0; i < a; i++)
    {
        scanf("%lf", &arr[i]);
    }
    TRY
    {
        double avg = compute_avg(arr, a);
        printf("Average = %lf", avg);
    }
    CAUGH(5)
    {
        printf("ERROR NO 5");
    }
    CAUGHERROR
    {
        printf("ERROR! invalid inputs\n");
    }

    return 0;
}

double compute_avg(double *values, size_t length)
{
    double sum = 0;
    if (length <= 0)
    {
        THROW(1);
    }

    for (int i = 0; i < length; i++)
    {
        sum += values[i];
    }
    return sum / (double)length;
}