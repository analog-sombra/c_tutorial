#include <stdio.h>
#include <math.h>
void show_greeting(char name[]);
void show_menu();
void length_of_number();
void length_of_words();
void reverse_the_number();
void palindrome_number();
void armstrong_number();
void strong_number();
void prime_number();
void fibonacci_series();
void floyds_tringle();
void perfect_number();

int main()
{
    int input;
    char name[50];
    printf("Enter your Name: ");
    scanf("%s", name);
    show_greeting(name);

    show_menu();

    do
    {
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\n");
            show_menu();
            break;
        case 2:
            printf("\n");
            length_of_number();

            break;
        case 3:
            printf("\n");
            length_of_words();
            break;
        case 4:
            printf("\n");
            reverse_the_number();
            break;
        case 5:
            printf("\n");
            palindrome_number();
            break;
        case 6:
            printf("\n");
            armstrong_number();
            break;
        case 7:
            printf("\n");
            strong_number();
            break;
        case 8:
            printf("\n");
            prime_number();
            break;
        case 9:
            printf("\n");
            fibonacci_series();
            break;
        case 10:
            printf("\n");
            floyds_tringle();
            break;
        case 11:
            printf("\n");
            perfect_number();
            break;
        default:
            if (input != 0)
            {
                printf("Please Enter a valid choice\n");
            }
            break;
        }
        printf("Enter your Choice: ");

    } while (input != 0);

    printf("\n\n\n");
    printf("Hope you enjoyed the program.\n");
    printf("Thank you for using it. Have a good day %s\n", name);

    return 0;
}
void show_menu()
{
    printf("0 ->  Exit the programe\n");
    printf("1 ->  Show menu\n");
    printf("2 ->  Length of number\n");
    printf("3 ->  Length of single words\n");
    printf("4 ->  Reverse the number\n");
    printf("5 ->  Palindrome Number\n");
    printf("6 ->  Armstrong Number\n");
    printf("7 ->  Strong Number\n");
    printf("8 ->  Prime Number\n");
    printf("9 ->  Fibonacci Series\n");
    printf("10 -> Floyd's tringle\n");
    printf("11 -> Perfect Number\n");
    printf("Enter Your Choice: ");
}

void show_greeting(char name[])
{

    printf("Hello %s Here is Some basic c programe what would you like to try\n", name);
    printf("Enter the coresponding number to execute\n");
}

void length_of_number()
{
    int number, len = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    while (number != 0)
    {
        len++;
        number = number / 10;
    }
    printf("Length of number is %d\n", len);
}

void length_of_words()
{
    char word[50];
    int len = 0;
    printf("Enter a word: ");
    scanf("%s", word);
    while (word[len] != '\0')
    {
        len++;
    }
    printf("Length of word is %d\n", len);
}

void reverse_the_number()
{
    int number, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    while (number != 0)
    {
        int remender = number % 10;
        reverse = reverse * 10 + remender;
        number = number / 10;
    }
    printf("Reverse of number is %d\n", reverse);
}

void palindrome_number()
{
    int number, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    while (number != 0)
    {
        int remender = number % 10;
        reverse = reverse * 10 + remender;
        number = number / 10;
    }
    if (number == reverse)
    {
        printf("Number is palindrome\n");
    }
    else
    {
        printf("Number is not palindrome\n");
    }
}

void armstrong_number()
{
    int num, count = 0, result = 0, mul = 1, cnt, rem;
    printf("Enter a number: ");
    scanf("%d", &num);
    int q = num;
    while (q != 0)
    {
        q = q / 10;
        count++;
    }
    cnt = count;
    q = num;
    while (q != 0)
    {
        rem = q % 10;
        while (cnt != 0)
        {
            mul = mul * rem;
            cnt--;
        }
        result = result + mul;
        cnt = count;
        q = q / 10;
        mul = 1;
    }
    // result
    if (num == result)
        printf("%d is an armstrong number\n", num);
    else
        printf("%d is not an armstrong number\n", num);
}

void strong_number()
{
    int num, i, result = 0, fact = 1, rem, q;
    printf("Enter a number: ");
    scanf("%d", &num);

    q = num;
    while (q != 0)
    {
        rem = q % 10;
        for (i = 1; i <= rem; i++)
        {
            fact = fact * i;
        }
        result = result + fact;
        fact = 1;
        q = q / 10;
    }
    if (num == result)
        printf("%d is a strong number\n", num);
    else
        printf("%d is not a strong number\n", num);
}
void prime_number()
{
    int num, i, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("%d is a prime number\n", num);
    }
    else
    {
        printf("%d is not a prime number\n", num);
    }
}

void fibonacci_series()
{

    int num, i, j;
    printf("Enter a number(0-45): \n");
    scanf("%d", &num);
    if (num < 46)
    {
        int a[num];
        a[0] = 0;
        a[1] = 1;
        for (i = 2; i < num; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        printf("Fibonacci series is: ");
        for (j = 0; j < num; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Enter the valid number range between 0 to 45\n");
    }
}

void floyds_tringle()
{
    int i, j, n, row;
    printf("Enter the number or row: ");
    scanf("%d", &row);
    n = 1;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", n);
            n++;
        }
        printf("\n");
    }
}

void perfect_number()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int sum = 0, i, rem;
    for (i = 1; i < number; i++)
    {
        rem = number % i;
        if (rem == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == number)
    {
        printf("%d is a perfect number\n", number);
    }
    else
    {
        printf("%d is not a perfect number\n", number);
    }
}