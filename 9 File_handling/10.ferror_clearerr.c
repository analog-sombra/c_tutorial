// int ferror(FILE *stream);
// void clearerr(FILE *stream);

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int status;
    char *data = "Hello World";
    FILE *file;
    //here we are opning file in read mode and trying to write data in it
    file = fopen("test.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    else
    {
        fprintf(file, "%s", data);
        //reading the error status of file
        status = ferror(file);
        printf("Status: %d\n", status);
        //clearing the error
        clearerr(file);
        printf("Status: %d\n", ferror(file));
        if(status == 0){
            printf("No error\n");
        }
        else{
            printf("Read and write error has occured\n");
        }
    }

    return 0;
}
