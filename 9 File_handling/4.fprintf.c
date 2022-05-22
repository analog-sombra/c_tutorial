#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[30];
    int age;

    printf("Enter your Name: ");
    scanf("%s",name);
    printf("Enter your age: ");
    scanf("%d",&age);
    FILE *file;
    file = fopen("tut4.txt","w");
    if(file == NULL){
        printf("Unable to to open file");
    }else{
        //write something in file in formated way
        fprintf(file,"Hello %s, \t How are you\nyou are %d year old",name,age);
        printf("writnig done");
        fclose(file);
        
    }
    return 0;
}
