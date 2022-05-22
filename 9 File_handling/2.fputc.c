#include <stdio.h>


int main(int argc, char const *argv[])
{
    //fputc(char,file)
    char *data = "Hello World";
    int len = strlen(data);
    int counter;
    FILE * file;
    file = fopen("tut2.txt","w");
    if(file == NULL){
        printf("Error opening file");
    }else{
        printf("File opened successfully\n");
        
        for(counter = 0; counter < len; counter++){
            printf("Writing the charecte %c\n",data[counter]);
            fputc(data[counter],file);
        }
        printf("writing done\n");
        fclose(file);
    }


    return 0;
}
