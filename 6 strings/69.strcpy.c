#include <stdio.h>
#include <string.h>

//prototype: char* strcpy(char* destination,const char* source)
//here const because the source will not modify

int main(int argc, char const *argv[])
{
    char str1[10] = "Hello";
    char str2[10];
    //Strcpy returns the pointer to the first character of the string which is copied in the destination. Hence if we use %s then whole string will be whole string will be printed on the screen.
    //str2 = destination
    //str1 = source


    printf("%s\n",strcpy(str2,str1));
    printf("%s\n",str2);


    //in the call to strcpy(str1,str2) there is no way the strcpy will check whether the string pointed by str2 will fit in str1
    //if the length of the string pointed by str2 is greater then the lenght of the character arrayh str1 then it will be an undefined begaviour.

    //to avoid this we can call strncpy function
    //strncpy(destination, source,sizeof(destination));
    char st1[6] = "hello";
    char st2[4];
    strncpy(st2,st1,sizeof(st2));
    st2[sizeof(st2)-1] = '\0';
    printf("%s",st2);

    //strncpy will leave thestring in str2 (destination) without a termination NULL character, if the size of str1(source) is equal to or greater then the size of str2(destination)
    
    return 0;
}
