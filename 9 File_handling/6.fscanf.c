#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    char data[100];
    char data1[100];
    file = fopen("tut6.txt","r");
    if(file == NULL){
        printf("Error opening file");
    }else{
        printf("File opened successfully\n");
        char ch;
        //fscanf and scanf stop when it's see space tab and enter
        fscanf(file,"%s %s",data,data1); 
        printf("%s %s\n",data,data1);
        printf("\n");
        fclose(file);
    }
    return 0;
}
