//protype: char* strcat(char* str1, const char* str2);
//stract function appends the content of string str2 at the end of the string str1

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str1[100],str2[100];
    strcpy(str1,"Welcome to ");
    strcpy(str2,"our world\n");
    strcat(str1,str2);
    printf("%s",str1);

    //An undefined behaviour can be observed if size of str1 isn't long enough to accomodate the addotional characters of str2.

    //strncat is the safer version of strcat.
    //it appends the limited number of characters specified by the third argument passed to it.
    //notestrncat automatically adds NULL characte at the end of the resultant string.
    char st1[5],st2[100];
    strcpy(st1,"He");
    strcpy(st2,"llo!");
    strncat(st1,st2,sizeof(st1)-strlen(st1)-1);
    printf("%s",st1);
    return 0;
}
