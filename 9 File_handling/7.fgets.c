#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *file;
    char data[100];
    file = fopen("tut7.txt","r");
    if(file ==NULL){
        printf("Error opening file");
    }else{
        while (!feof(file))
        {
            fgets(data,100,file);
            printf("%s",data);
        }
        
    }
    return 0;
}
