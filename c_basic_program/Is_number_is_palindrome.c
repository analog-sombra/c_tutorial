#include <stdio.h>

void show_greeting(char name[]);
void show_menu();
void length_of_number();
void length_of_words();

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
        default:
            printf("Please Enter a valid choice\n");
            break;
        }
        printf("Enter your Choice");

    } while (input != 0);

    printf("\n\n\n");
    printf("Hope you enjoyed the program.\n");
    printf("Thank you for using it. Have a good day %s\n", name);

    return 0;
}
void show_menu()
{
    printf("0 -> Exit the programe\n");
    printf("1 -> show menu\n");
    printf("2 -> Length of number\n");
    printf("3 -> Length of single words\n");
    printf("4 -> Reverse the number\n");
    printf("5 -> Reverse the words\n");
    printf("6 -> Reverse the words\n");
    printf("7 -> Palindrome Number\n");
    printf("8 -> Palindrome Words\n");
    printf("Enter Your Choice\n");
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
