#include <stdio.h>
//syntex of rewind function
//void rewind(FILE *stream);
int main(int argc, char const *argv[])
{
     FILE *file;
        file = fopen("test.txt", "r");
        while (!feof(file))
        {
            char c = fgetc(file);
            printf("%c", c);
        }
        printf("\n");
        //resetting the file pointer to the beginning of the file
        rewind(file);
        while (!feof(file))
        {
            char c = fgetc(file);
            printf("%c", c);
        }
       
        
        
    return 0;
}
