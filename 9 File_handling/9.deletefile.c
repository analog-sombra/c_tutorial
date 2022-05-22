//syntext 
//int remove(file_name);
//0 == file has been deleted sccessully
//-1 == file does not exist
//onozexo == error while deleting the file

#include <stdio.h>

int main(int argc, char const *argv[])
{
    if(remove("delete.txt")==0){
        printf("File deleted successfully\n");
    }else{
        printf("Error deleting file\n");
    }
    return 0;
}
