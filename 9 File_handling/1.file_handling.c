#include <stdio.h>
int main(int argc, char const *argv[])
{
    //fopen(filename,mode)
    //fopen return the address of the structure the file

    FILE *file;
    //r will give you error if you try to open a file that doesn't exist 
    //w will create the file if it doesn't exist
    //a will create the file if it doesn't exist and append to the end of the file
    file = fopen("tut1.txt","w");

    if(file == NULL){
        printf("Error opening file");
        return 1;
    }else{
        printf("File opened successfully\n");
        fclose(file);
    }


    //w = write
    //r = read
    //a = append
    //r+ = read and write
    //w+ = write and read
    //a+ = append and read
    //rb = read binary
    //wb = write binary
    //ab = append binary

    //r+b = read and write binary
    //w+b = write and read binary
    //a+b = append and read binary
    //r+t = read and write text
    //w+t = write and read text
    //a+t = append and read text
    
    fopen("file_name.txt","w");
    return 0;
}
