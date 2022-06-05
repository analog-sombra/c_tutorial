#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BASE_2 "01"
#define BASE_8 "01234567"
#define BASE_10 "0123456789"
#define BASE_12 "0123456789XE"
#define BASE_16 "0123456789ABCDEF"


char * base_conversion(char* input,char* inp_base,char* out_base);
int main(int argc, char const *argv[])
{
    char input[100] = "00312345";
    char inp_base[100] = "0123456789ABCDEF";
    char out_base[100] = "0123456789";
    
   
    char *output=base_conversion(input,inp_base,out_base);
    return 0;
}
char * base_conversion(char* input,char* inp_base,char* out_base){
    int inp_base_len = strlen(inp_base);
    int out_base_len = strlen(out_base);
    int input_len = strlen(input);

    //check all input char inside input base
    for (int i = 0; i < input_len; i++)
    {
        int j;
        for (j = 0; j < inp_base_len; j++)
        {
            if (toupper(input[i]) == inp_base[j])
            {
                break;
            }
        }
        if (j == inp_base_len)
        {
            printf("input base is not valid\n");
            return NULL;
        }
    }



    



}