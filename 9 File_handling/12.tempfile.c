//syntex of tempfile function
//FILE *tempfile(char *template);
// creates a temporaray binary file and opens in w+b mode
//when your program ends, the file is deleted

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *data = "Hello World";
    int len = strlen(data);
    FILE *temp;
    temp = tmpfile();
    if(temp == NULL){
        printf("Error creating temp file\n");
    }
    else{
        char *filedata;
        while(len--){
            fputc(*data++, temp);
        }
        rewind(temp);
        while(!feof(temp)){
            putchar(fgetc(temp));
        }
        
       
        
        printf("\nTemp file created\n");
    }
    return 0;
}
