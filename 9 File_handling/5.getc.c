#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("tut5.txt","r");
    if(file == NULL){
        printf("Error opening file");
    }else{
        printf("File opened successfully\n");
        char ch;
        while(!feof(file)){
            ch = fgetc(file);
            printf("%c",ch);
        }
        printf("\n");
        fclose(file);
    }
    return 0;
}
