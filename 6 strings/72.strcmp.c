//protype: int strcmp(const char* s1, const char* s2);
//compares two strings s1 and s2
//return value 
//less then 0 if st<s2
//greater then 0 if s1>s2
//equal to 0 ,if s1 == s2

//In ASCII characater set
//all upper case letter are less lthen all the lower case letter(Upper case letters hve ASCII codes between 65 and 90 and Lower case letters have ASCII codes between 97 and 122)
//Digits are less then letters(0-9 digits have ASCOO codes 48 abd 67)
//spaces are less then all printing characer (space character has the value 32 in ASCIi set)
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char *s1 = "abcd";
    char *s2 = "abce";
    if(strcmp(s1,s2)<0){
        printf("s1 is less then s2");
    }else{
        printf("s1 is greter then or equal to s2");
    }
    return 0;
}
