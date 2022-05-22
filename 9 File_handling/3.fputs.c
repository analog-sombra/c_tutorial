#include <stdio.h>

int main(int argc, char const *argv[])
{

    //fputs(string,file)
    FILE *file;

    file = fopen("tut3.txt","w");
    if(file == NULL){
        printf("Error opening file");
    }else{
        printf("File opened successfully\n");
        fputs("Hello World",file);
        printf("writing done\n");
        fclose(file);
    }
    return 0;
}
