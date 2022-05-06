#include <stdio.h>
int main(int argc, char const *argv[])
{
    char result;
    int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);
    result = (marks > 33)?'p':'f';
    printf("%c\n",result);

    // (marks > 33) is a boolean expression, therefore it will result either TRUE or FALSE
    //(marks> 33)?'p' :'f' is a conditional expression  which is after all an expression , therefore it is a n r-value and result is l-value

    //conditional operator is the only ternary operator availavle in the list of operators in c language

    //as is Expression1? Expression2: Expresssion3 ,expression1 is the boolean expression. if we simply write 0 instead of some boolean expression than theat simply means False and therefore expression3 wiil get evaluated.
        return 0;
}
