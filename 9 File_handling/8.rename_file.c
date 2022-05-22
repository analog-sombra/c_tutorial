 #include <stdio.h>
 int main(int argc, char const *argv[])
 {
     if(rename("tut8.txt","sombra.txt")==0){
            printf("File renamed successfully\n");
     }else{
            printf("Error renaming file\n");
     }
     return 0;
 }
 