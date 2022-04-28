// float ,Double and long double for representing fraction numbers
// Float 4 bytes = 32 bits
// Double  8 bytes = 64
// longDoubel = 12 bytes = 96 bits

// Size of these data types totally depends from system to system

#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long double));

    // Fixed and floating point
    // floating point use in morden computer

    // flote precise for 6
    float x = 3.36324762874628364824634;
    // double is precise for 16 digit
    double y = 3.87435897394579347593745983754;
    // long double is precise for 19 digit
    long double z = 3.7923742836487253645234984;
    printf("%.16f\n", x);
    printf("%.16f\n", y);
    printf("%.21Lf\n", z);

    int l = 4 / 9;
    printf("%d\n", l);

    float k = 4 / 9;
    printf("%.2f\n",k);

    float j = 4.0/9.0;
    printf("%.2f\n", j);
    return 0;
}
